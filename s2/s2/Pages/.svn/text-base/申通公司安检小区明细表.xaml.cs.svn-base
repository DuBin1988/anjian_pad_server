using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using Com.Aote.ObjectTools;

namespace s2.Pages
{
    public partial class 申通公司安检小区明细表 : UserControl
    {

        public 申通公司安检小区明细表()
        {
            InitializeComponent();
            pl.DataLoaded += pl_DataLoaded;
            System.DateTime currentTime = System.DateTime.Now;
            start_time.Text = currentTime.Year + "-" + currentTime.Month + "-" + currentTime.Day;
            end_time.Text = currentTime.Year + "-" + currentTime.Month + "-" + currentTime.Day;
            
        }
        

        private void sou_tj_Click(object sender, RoutedEventArgs e)
        {
            string sql = "select " +
                        " arrival_time,unit_name,road,count(T1.id) ansum,count(t2.tt) oksum,round((count(t2.tt)/count(T1.id)*100),2) rzl,sum(v_count_rg) v_count_rg,sum(v_count_lq) v_count_lq,sum(v_count_rqb) v_count_rqb,sum(v_count_qt) v_count_qt,sum(v_count_tzd) v_count_tzd,sum(v_count_gk) v_count_gk " +
                        " from (select id,condition,user_name,arrival_time,departure_time,road,unit_name,cus_dom,cus_dy,cus_floor,cus_room,old_address,room_structure,warm,save_people,v_count_rg,v_count_lq,v_count_rqb,v_count_qt,v_count_tzd,v_count_gk " +
                        " from (select id,condition,user_name,arrival_time,departure_time,road,unit_name,cus_dom,cus_dy,cus_floor,cus_room,old_address,room_structure,warm,save_people,v_count_rg,v_count_lq,v_count_rqb,v_count_qt,v_count_tzd " +
                        " from (select id,condition,user_name,arrival_time,departure_time,road,unit_name,cus_dom,cus_dy,cus_floor,cus_room,old_address,room_structure,warm,save_people,v_count_rg,v_count_lq,v_count_rqb,v_count_qt " +
                        " from (select id,condition,user_name,arrival_time,departure_time,road,unit_name,cus_dom,cus_dy,cus_floor,cus_room,old_address,room_structure,warm,save_people,v_count_rg,v_count_lq,v_count_rqb " +
                        " from (select id,condition,user_name,arrival_time,departure_time,road,unit_name,cus_dom,cus_dy,cus_floor,cus_room,old_address,room_structure,warm,save_people,v_count_rg,v_count_lq " +
                        " from (select id,condition,user_name,substr(arrival_time,0,10) arrival_time,departure_time,road,unit_name,cus_dom,cus_dy,cus_floor,cus_room,old_address,room_structure,warm,save_people,v_count_rg " +
                        " from t_inspection t1 " +
                        " left outer join " +
                        " (select count(inspection_id) as v_count_rg,inspection_id from t_inspection_line where (CONTENT not like '%老化%' and CONTENT not like '%漏气%') and (EQUIPMENT like '%软管%' or EQUIPMENT like '%安全%') GROUP BY inspection_id) t2 " +
                        " on T1.id=T2.inspection_id where (arrival_time BETWEEN '" + start_time.Text + "' and '" + end_time.Text + "') ) t1 " +
                        " left outer join " +
                        " (select count(inspection_id) as v_count_lq,inspection_id from t_inspection_line where CONTENT like '%漏气%' and EQUIPMENT not like '%立管%' GROUP BY inspection_id) t2 " +
                        " on T1.id=T2.inspection_id) t1 " +
                        " left outer join " +
                        " (select count(inspection_id) as v_count_rqb,inspection_id from t_inspection_line where (CONTENT like '%表%' or CONTENT like '%其他%') and EQUIPMENT like '%燃气表%' GROUP BY inspection_id) t2 " +
                        " on T1.id=T2.inspection_id) t1 " +
                        " left outer join " +
                        " (select count(inspection_id) as v_count_qt,inspection_id from t_inspection_line where EQUIPMENT like '%热水器%隐患%' or  EQUIPMENT like '%炉%' or  EQUIPMENT like '%燃%设施%' GROUP BY inspection_id) t2 " +
                        " on T1.id=T2.inspection_id) t1 " +
                        " left outer join " +
                        " (select count(inspection_id) as v_count_tzd,inspection_id from t_inspection_line where CONTENT like '%报告%' GROUP BY inspection_id) t2 " +
                        " on T1.id=T2.inspection_id) t1 " +
                        " left outer join " +
                        " (select count(inspection_id) as v_count_gk,inspection_id from t_inspection_line where CONTENT like '%管卡%' or EQUIPMENT  like '%管卡%' GROUP BY inspection_id) t2 " +
                        " on T1.id=T2.inspection_id) t1 " +
                        " left outer join " +
                        " (select condition,id as tt from t_inspection where condition = '正常') t2 " +
                        " on T1.id=T2.tt " +
                        " GROUP BY arrival_time,unit_name,road " + "  order by arrival_time,unit_name";


            //获取分组的数据
            pl.WebClientInfo = Application.Current.Resources["dbclient"] as WebClientInfo;
            pl.LoadOnPathChanged = false;
            pl.Path = "sql";
            pl.PageSize = 1000;
            pl.HQL = sql;
            pl.PageIndex = 0;
            pl.Load();
           
        }


       

        void pl_DataLoaded(object sender, System.ComponentModel.AsyncCompletedEventArgs e)
        {
            //计算合计
            var ol = (from p in pl 
                    select p);
            int ANSUM = ol.Sum(o => Convert.ToInt32(o.GetPropertyValue("ANSUM") == null ? "0" : o.GetPropertyValue("ANSUM").ToString()));
            int OKSUM = ol.Sum(o => Convert.ToInt32(o.GetPropertyValue("OKSUM") == null ? "0" : o.GetPropertyValue("OKSUM").ToString()));
            if (ANSUM > 0)
            {
                double oksum_double;
                double.TryParse(OKSUM.ToString(), out oksum_double);
                rzl_xj.Text = (oksum_double / ANSUM * 100).ToString();
            }
            ansum_xj.Text = ANSUM.ToString();
            oksum_xj.Text = OKSUM.ToString();
            lq_xj.Text = ol.Sum(o => Convert.ToInt32(o.GetPropertyValue("V_COUNT_LQ") == null ? "0" : o.GetPropertyValue("V_COUNT_LQ").ToString())).ToString();
            rqb_xj.Text = ol.Sum(o => Convert.ToInt32(o.GetPropertyValue("V_COUNT_RQB") == null ? "0" : o.GetPropertyValue("V_COUNT_RQB").ToString())).ToString();
            rg_xj.Text = ol.Sum(o => Convert.ToInt32(o.GetPropertyValue("V_COUNT_RG") == null ? "0" : o.GetPropertyValue("V_COUNT_RG").ToString())).ToString();
            tzd_xj.Text = ol.Sum(o => Convert.ToInt32(o.GetPropertyValue("V_COUNT_TZD") == null ? "0" : o.GetPropertyValue("V_COUNT_TZD").ToString())).ToString();
            gfx_xj.Text = ol.Sum(o => Convert.ToInt32(o.GetPropertyValue("V_COUNT_QT") == null ? "0" : o.GetPropertyValue("V_COUNT_QT").ToString())).ToString();
            gk_xj.Text = ol.Sum(o => Convert.ToInt32(o.GetPropertyValue("V_COUNT_GK") == null ? "0" : o.GetPropertyValue("V_COUNT_GK").ToString())).ToString();

        }

        
        

        
    }
    public class RowModel
    {
        public String scre_time { get; set; } //安检时间
        public String unit_name { get; set; } //小区名称
        public String road { get; set; } //行政区域
        public String old_address { get; set; }//小区地址
        public int customers { get; set; }//客户数 
        public int customers_rh { get; set; }//成功入户数 
        public String customers_rhl { get; set; }//入户率 
        public int luqs { get; set; }//漏气 
        public int luq_fix { get; set; }//漏气修复 
        public int rqb { get; set; }//燃气表 
        public int rqb_fix { get; set; }//燃气表修复 
        public int jiaog { get; set; }//胶管隐患 
        public int jiaog_fix { get; set; }//胶管修复 
        public int kag { get; set; }//管卡隐患 
        public int kag_fix { get; set; } //管卡修复
        public int zibifa { get; set; }//发现故障自闭阀（个） 
        public int zibifa_fix { get; set; }//更换自闭阀（个） 
        public int hnwz { get; set; }//户内违章（户） 
        public int gfx { get; set; }//高风险 
        public int tzd { get; set; }//发放隐患通知书（张)
        public int xczl { get; set; }//发放宣传资料（份） 
        public String tsqk { get; set; }//特殊情况说明备注

            public RowModel(String scre_time, String unit_name,
                String road, String old_address, int customers, int customers_rh, String customers_rhl, int luqs, int luq_fix,
                int rqb, int rqb_fix, int jiaog, int jiaog_fix, int kag, int kag_fix, int zibifa, int zibifa_fix,
                int hnwz, int gfx, int tzd, int xczl, String tsqk)
            {
                this.scre_time = scre_time;
                this.unit_name = unit_name;
                this.road = road;
                this.old_address = old_address;
                this.customers = customers;
                this.customers_rh = customers_rh;
                this.customers_rhl = customers_rhl;
                this.luqs = luqs;
                this.luq_fix = luq_fix;
                this.rqb = rqb;
                this.rqb_fix = rqb_fix;
                this.jiaog = jiaog;
                this.jiaog_fix = jiaog_fix;
                this.kag = kag;
                this.kag_fix = kag_fix;
                this.zibifa = zibifa;
                this.zibifa_fix = zibifa_fix;
                this.hnwz = hnwz;
                this.gfx = gfx;
                this.tzd = tzd;
                this.xczl = xczl;
                this.tsqk = tsqk;
            }
            public RowModel()
            {

            }

     }

}
