package com.aote.rs;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import org.codehaus.jettison.json.JSONArray;
import org.codehaus.jettison.json.JSONException;
import org.codehaus.jettison.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.orm.hibernate3.HibernateTemplate;
import org.springframework.stereotype.Component;

import com.aote.rs.DBService.JsonTransfer;

@Path("xygas")
@Component
public class CalculateService {

	@Autowired
	private HibernateTemplate hibernateTemplate;

	@GET
	@Path("/whf/{begin}/{end}")
	@Produces(MediaType.APPLICATION_JSON)
	public JSONObject query(@PathParam("begin") String begin,
			@PathParam("end") String end) {
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
		JSONObject result = new JSONObject();
		try {
			Date b = format.parse(begin);
			Date e = format.parse(end);
			double f_amountmaintenance = 0;
			if(b.after(e) || b.equals(e)){
				Map<String, Object> map = new HashMap<String, Object>();
				map.put("f_amountmaintenance", f_amountmaintenance);
				result = (JSONObject) new DBService().new JsonTransfer()
						.MapToJson(map);
				return result;
			}
			// 计算维护费
			String hql = "from t_weihufeiprice";
			List<Object> list = this.hibernateTemplate.find(hql);
			for (Object object : list) {
				Map<String, Object> map = (Map<String, Object>) object;
				int month = 0;
				if (map.get("f_begindate") != null
						&& map.get("f_enddate") == null) {
					Date begindate = format.parse(map.get("f_begindate")
							.toString());
					if (b.after(begindate) && e.after(begindate)) {
						month = (e.getYear() - b.getYear()) * 12
								+ (e.getMonth() - b.getMonth());
					}
					if ((begindate.after(b) || begindate.equals(b))
							&& e.after(begindate)) {
						month = (e.getYear() - begindate.getYear()) * 12
								+ (e.getMonth() - begindate.getMonth());
					}
				}
				// 结束日期
				if (map.get("f_enddate") != null
						&& map.get("f_begindate") == null) {
					Date enddate = format
							.parse(map.get("f_enddate").toString());
					if (b.before(enddate) && e.before(enddate)) {
						month = (e.getYear() - b.getYear()) * 12
								+ (e.getMonth() - b.getMonth());
					}
					if (b.before(enddate)
							&& (e.after(enddate) || e.equals(enddate))) {
						month = (enddate.getYear() - b.getYear()) * 12
								+ (enddate.getMonth() - b.getMonth());
					}
				}
				// 价格
				double price = Double.parseDouble(map.get("f_monthprice")
						.toString());
				f_amountmaintenance += month * price;
			}
			Map<String, Object> map = new HashMap<String, Object>();
			map.put("f_amountmaintenance", f_amountmaintenance);
			result = (JSONObject) new DBService().new JsonTransfer()
					.MapToJson(map);
		} catch (ParseException e) {
			e.printStackTrace();
		}
		return result;
	}
}
