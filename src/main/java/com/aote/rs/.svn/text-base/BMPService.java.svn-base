package com.aote.rs;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URLEncoder;
import java.sql.Blob;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.WebApplicationException;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.MediaType;

import org.apache.log4j.Logger;
import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.codehaus.jettison.json.JSONArray;
import org.codehaus.jettison.json.JSONException;
import org.codehaus.jettison.json.JSONObject;
import org.hibernate.Hibernate;
import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.collection.PersistentSet;
import org.hibernate.engine.SessionFactoryImplementor;
import org.hibernate.metadata.ClassMetadata;
import org.hibernate.proxy.map.MapProxy;
import org.hibernate.type.DateType;
import org.hibernate.type.DoubleType;
import org.hibernate.type.LongType;
import org.hibernate.type.ManyToOneType;
import org.hibernate.type.SetType;
import org.hibernate.type.TimeType;
import org.hibernate.type.Type;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.HibernateTemplate;
import org.springframework.stereotype.Component;
import org.springframework.web.context.ContextLoader;
import org.springframework.web.context.WebApplicationContext;

import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import com.aote.expression.ExpressionGenerator;

@Path("BMPService")
@Component
public class BMPService {
	static Logger log = Logger.getLogger(BMPService.class);

	@Autowired
	private HibernateTemplate hibernateTemplate;

	// 保存图片
	@SuppressWarnings("finally")
	@Path("savefile")
	@POST
	public String savefile(byte[] file,
			@QueryParam("FileName") String filename,
			@QueryParam("BlobId") String blob_id,
			@QueryParam("EntityName") String EntityName) {
		String result = null;
		try { 
			WebApplicationContext webApplicationContext = ContextLoader.getCurrentWebApplicationContext();    
		    ServletContext servletContext = webApplicationContext.getServletContext(); 
			//得到上传文件的保存目录
			String[] idstr=blob_id.split("_");
			String[] namestr=filename.split("/");
			File filepath = new File(servletContext.getRealPath("/")+"upload"+File.separatorChar+"images"+File.separatorChar+"anjian"+File.separatorChar+idstr[0]+File.separatorChar+idstr[1]);
            //判断上传文件的保存目录是否存在
            if (!filepath.exists() && !filepath.isDirectory())
            	filepath.mkdirs();            
            try{
            	FileOutputStream out = new FileOutputStream(filepath + File.separator + namestr[namestr.length-1]);
                if(file.length>0){
                   out.write(file, 0, file.length);
                }
                out.close();
                filepath=null;
            }catch (Exception e) {
                e.printStackTrace();
            }			
            result = "";
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			return result;
		}
	}
	// 获得图片
	@SuppressWarnings("finally")
	@Path("file/{blobid}")
	public String getimage(@Context HttpServletResponse response,
			@PathParam("blobid") String blobid) {
		try {
			WebApplicationContext webApplicationContext = ContextLoader.getCurrentWebApplicationContext();    
		    ServletContext servletContext = webApplicationContext.getServletContext(); 
			String[] idstr=blobid.split("_");
			File filepath = new File(servletContext.getRealPath("/")+"upload"+File.separatorChar+"images"+File.separatorChar+"anjian"+File.separatorChar+idstr[0]+File.separatorChar+idstr[1]);
			// 获得文件
			String jpg=".jpg";
			String sss =filepath + File.separator + blobid;
			if(sss.indexOf("_sign")==-1){
				jpg=".jpg";
			}else{
				jpg=".png";
			}
			String filename = blobid+jpg;
			filename = URLEncoder.encode(filename, "UTF-8");
			InputStream is=new FileInputStream(sss+jpg);
			response.setHeader("Pragma","No-cache"); 
			response.setHeader("Cache-Control","no-cache"); 
			response.setDateHeader("Expires", 0); 
			response.setStatus(HttpServletResponse.SC_OK);
			response.setContentType("application/octet-stream");
			response.setHeader("Content-Disposition", "attachment;filename=\""
					+ filename + "\"");
			// 把文件的内容送入响应流中
			//InputStream is = file.getBinaryStream();
			OutputStream os = new BufferedOutputStream(response
					.getOutputStream());
			transformStream(is, os);
			is.close();
			os.close();
			filepath=null;
			return "";
		} catch (Exception e) {
			e.printStackTrace();
		}finally{
			return "";
		}
	}
	
	// 数据库的图片，转移出来
	@Path("dbtofile")
	public String dbtofile() {
		try {
			WebApplicationContext webApplicationContext = ContextLoader.getCurrentWebApplicationContext();    
		    ServletContext servletContext = webApplicationContext.getServletContext(); 
			//得到上传文件的保存目录
		    for(;;){
				List list = this.hibernateTemplate.executeFind(new HibernateCallback() { 
					public Object doInHibernate(Session session) throws HibernateException, SQLException { 
					Query q = session.createQuery("from t_blob where isto is null");
					q.setFirstResult(0); 
					q.setMaxResults(1000); 
					return q.list(); 
					} 
					});//("from t_blob where isto is null");
				if (list.size() == 0){
					System.gc();
					return "";
				}
				for(int i=0;i<list.size();i++){
					Map map = (Map)list.get(i);
					// 获得文件名
					//String id = (String) map.get("id");
					//String filename = (String) map.get("filename");
					try{
						Blob file = (Blob) map.get("blob");
						String[] idstr=((String) map.get("id")).split("_");
						String[] namestr=((String) map.get("filename")).split("/");
						File filepath = new File(servletContext.getRealPath("/")+"upload"+File.separatorChar+"images"+File.separatorChar+"anjian"+File.separatorChar+idstr[0]+File.separatorChar+idstr[1]);
			            //判断上传文件的保存目录是否存在
			            if (!filepath.exists() && !filepath.isDirectory())
			            	filepath.mkdirs(); 
						byte[] b=new byte[1024];	
						InputStream is = file.getBinaryStream();
		            	FileOutputStream out = new FileOutputStream(filepath + File.separator + namestr[namestr.length-1]);
		                while(is.read(b)!=-1){
		                	out.write(b);
		                }
		                out.close();
		                is.close();
		                filepath=null;
		                execSQL("update t_blob set isto='1' where id='"+(String) map.get("id")+"'");
		            }catch (Exception e) {
		                e.printStackTrace();
		            }
		            map.clear();
				}
				list.clear();
		    }
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.gc();
		return "";
	}
	
	public void transformStream(InputStream is, OutputStream os) {
		try {
			byte[] buffer = new byte[1024];
			// 读取的实际长度
			int length = is.read(buffer);
			while (length != -1) {
				os.write(buffer, 0, length);
				length = is.read(buffer);
			}
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}
	
	/**
	 * execute sql in hibernate
	 * @param sql
	 */
	private void execSQL(final String sql) {
        hibernateTemplate.execute(new HibernateCallback() {
            public Object doInHibernate(Session session)
                    throws HibernateException {
                session.createSQLQuery(sql).executeUpdate();
                return null;
            }
        });		
	}
	
}
