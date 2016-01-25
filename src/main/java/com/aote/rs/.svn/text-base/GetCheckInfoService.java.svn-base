package com.aote.rs;

import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.WebApplicationException;

import org.apache.log4j.Logger;
import org.codehaus.jettison.json.JSONArray;
import org.codehaus.jettison.json.JSONException;
import org.codehaus.jettison.json.JSONObject;
import org.hibernate.HibernateException;
import org.hibernate.SQLQuery;
import org.hibernate.Session;
import org.hibernate.collection.PersistentSet;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.HibernateTemplate;
import org.springframework.stereotype.Component;


@Path("gcis")
@Component
public class GetCheckInfoService {
	static Logger log = Logger.getLogger(GetCheckInfoService.class);
	
	@Autowired
	private HibernateTemplate hibernateTemplate;
	
	@Path("getuserinfo/{UnitName}")
	@GET
	@Produces("application/json")
	public String GetUserInfo(@PathParam("UnitName")String UnitName)
	{
		if(null == UnitName)
			return "[{\"ok\":\"nok\"},{\"ok1\":\"nok\"}]";
		UnitName = UnitName.trim();
		try {
			final String findInfoHql = "select t1.f_username, f_phone, f_address, f_cardid, f_meternumber, f_aroundmeter, f_jbfactory, f_road, f_districtname, f_cusDom, f_cusDy, f_cusFloor, f_apartment, tsum, tcount, t1.f_userid, f_userstate from (select * from t_userfiles where f_address like '%" + UnitName + "%') t1 left join (select f_userid, f_username, SUM (f_pregas) tsum, COUNT(f_pregas) tcount from t_sellinggas where f_username like '%%' group by f_userid, f_username) t2 on t1.f_userid = t2.f_userid";
			JSONArray userJson = new JSONArray();
			List list = (List) hibernateTemplate.execute(new HibernateCallback() {
				public Object doInHibernate(Session session)
						throws HibernateException {
					return session.createSQLQuery(findInfoHql).list();
				}
			});
			for (Object obj : list) {
				// 把单个map转换成JSON对象
				Object[] c = (Object[]) obj;
				JSONObject json = new JSONObject();
				for (int i = 0; i < c.length; i++) {
					try {
						json.put("col" + i, c[i]);
					} catch (JSONException e) {
						throw new WebApplicationException(400);
					}
				}
				userJson.put(json);
			}

			return userJson.toString();
		} catch (Exception e) {
			return "{\"ok\":\"nok\"}";
		}
	}
	
	@Path("getsafeinfo")
	@POST
	@Produces("application/json")
	public String GetSafeInfo(String address)
	{
		JSONArray jsons = new JSONArray();
		try {
			if(null == address || 0 == address.length())
				return "[{\"ok\":\"nok\"},{\"ok1\":\"nok\"}]";
				JSONArray jsona = new JSONArray(address);
				for(int i = 0; i < jsona.length(); i++)
				{
					JSONObject json = jsona.getJSONObject(i);
					final String findInfoHql = "select top 1 COOK_BRAND, COOK_TYPE, COOK_DATE, WATER_BRAND, WATER_TYPE, WATER_FLUE, WATER_DATE, WHE_BRAND, WHE_TYPE, WHE_DATE, IC_METER_NAME, JB_METER_NAME, METER_TYPE, gas_quantity, ROAD, UNIT_NAME, CUS_DOM, CUS_DY, CUS_FLOOR, CUS_ROOM from T_INSPECTION where ROAD = '" + json.getString("ROAD") + "' and UNIT_NAME = '" + json.getString("UNIT_NAME") + "' and CUS_DOM = '" + json.getString("CUS_DOM") + "' and CUS_DY = '" + json.getString("CUS_DY") + "' and CUS_FLOOR = '" + json.getString("CUS_FLOOR") + "' and CUS_ROOM = '" + json.getString("CUS_ROOM") + "' order by ARRIVAL_TIME desc";
					JSONArray userJson = new JSONArray();
					List list = (List) hibernateTemplate.execute(new HibernateCallback() {
						public Object doInHibernate(Session session)
								throws HibernateException {
							return session.createSQLQuery(findInfoHql).list();
						}
					});
					if(1 != list.size())
					{
						continue;
					}
					Object[] c = (Object[]) list.get(0);
					JSONObject json1 = new JSONObject();
					for (int j = 0; j < c.length; j++) {
						try {
							json1.put("col" + j, c[j]);
						} catch (JSONException e) {
							throw new WebApplicationException(400);
						}
					}
					jsons.put(json1);
				}

			return (null == jsons || 0 == jsons.length()) ? "[{\"ok\":\"nok\"},{\"ok1\":\"nok\"}]" : jsons.toString();
		} catch (Exception e) {
			return "[{\"ok\":\"nok\"},{\"ok1\":\"nok\"}]";
		}
	}

}
