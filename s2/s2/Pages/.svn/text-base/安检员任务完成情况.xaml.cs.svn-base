using System;
using System.Collections.Generic;
using System.Json;
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
    public partial class 安检员任务完成情况 : UserControl
    {
        public 安检员任务完成情况()
        {
            InitializeComponent();
            paperList.DataLoaded += paperList_DataLoaded;
        }



        void paperList_DataLoaded(object sender, System.ComponentModel.AsyncCompletedEventArgs e)
        {
            //计算合计
            var paperlist = (from p in paperList
                             select p);
            int ZONGHUSHU = paperlist.Sum(o => Convert.ToInt32(o.GetPropertyValue("ZHU") == null ? "0" : o.GetPropertyValue("ZHU").ToString()));
            int ANJIANRENSHU = paperlist.Sum(o => Convert.ToInt32(o.GetPropertyValue("ZC") == null ? "0" : o.GetPropertyValue("ZC").ToString()));
            int JUJIANRENSHU = paperlist.Sum(o => Convert.ToInt32(o.GetPropertyValue("JJ") == null ? "0" : o.GetPropertyValue("JJ").ToString()));
            int WURENRENSHU = paperlist.Sum(o => Convert.ToInt32(o.GetPropertyValue("WR") == null ? "0" : o.GetPropertyValue("WR").ToString()));
             int HEHE = paperlist.Sum(o => Convert.ToInt32(o.GetPropertyValue("hehe") == null ? "0" : o.GetPropertyValue("hehe").ToString()));

             if (paperlist.Count() == 0)
             {
                 zonghushu.Text = "0";
                 anjianhushu.Text = "0";
                 jujianhushu.Text = "0";
                 wurenhushu.Text = "0";
                 anjianlv.Text = "0";
             }
            
             if (HEHE > 0  )
            {
                zonghushu.Text = (ZONGHUSHU / HEHE).ToString();
                anjianhushu.Text = (ANJIANRENSHU / HEHE).ToString();
                jujianhushu.Text = (JUJIANRENSHU / HEHE).ToString();
                wurenhushu.Text = (WURENRENSHU / HEHE).ToString();
            }
            
            if (ZONGHUSHU > 0 && ANJIANRENSHU != 0)
            {
                double ZONGHUSHU_DOUBLE;
                double.TryParse(ZONGHUSHU.ToString(), out ZONGHUSHU_DOUBLE);
                string anjianlvStr = (ANJIANRENSHU / ZONGHUSHU_DOUBLE * 100).ToString();
                if (anjianlvStr.Length > 10)
                {
                    anjianlv.Text = anjianlvStr.Substring(0, 10);
                }
                else
                {
                    anjianlv.Text = anjianlvStr;
                }
            }
            else
            {
                anjianlv.Text = "0";
            }
            
        }















        private Boolean IsNullOrEmpty(String value)
        {
            return value == null || value.Trim().Length == 0;
        }


        /// <summary>
        /// 处理查询按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        //private void btnSearch_Click(object sender, RoutedEventArgs e)
        //{
        //    //按下时，组装条件，并加载
        //    SearchObject conditions = (criteriaPanel.DataContext as SearchObject);
        //    PagedList paperList = (paperGrid.ItemsSource as PagedList);
        //    paperList.LoadOnPathChanged = false;
        //    //assemble the conditions
        //    String criteria = " where 1=1 ";
        //    String rarea = conditions.GetPropertyValue("UNIT_NAME") as string;
        //    if (!IsNullOrEmpty(rarea))
        //        criteria += " and rarea like '%" + rarea + "%'";
        //    String building = conditions.GetPropertyValue("CUS_DOM") as string;
        //    if (!IsNullOrEmpty(building))
        //        criteria += " and building like '%" + building + "%'";
        //    String unit = conditions.GetPropertyValue("CUS_DY") as string;
        //    if (!IsNullOrEmpty(unit))
        //        criteria += " and unit like '%" + unit + "%'";
        //    String floor = conditions.GetPropertyValue("CUS_FLOOR") as string;
        //    if (!IsNullOrEmpty(floor))
        //        criteria += " and floor like '%" + floor + "%'";
        //    String room = conditions.GetPropertyValue("CUS_ROOM") as string;
        //    if (!IsNullOrEmpty(room))
        //        criteria += " and room like '%" + room + "%'";

        //    String rightJoinCriteria = "";
        //    String repairman = conditions.GetPropertyValue("REPAIRMAN") as string;
        //    if (!IsNullOrEmpty(repairman))
        //        rightJoinCriteria += " and REPAIRMAN like '%" + repairman + "%'";
        //    String SAVE_PEOPLE = conditions.GetPropertyValue("SAVE_PEOPLE") as string;
        //    if (!IsNullOrEmpty(SAVE_PEOPLE))
        //        rightJoinCriteria += " and SAVE_PEOPLE like '%" + SAVE_PEOPLE + "%'";
        //    String card_id = conditions.GetPropertyValue("CARD_ID") as string;
        //    if (!IsNullOrEmpty(card_id))
        //        rightJoinCriteria += " and card_id =" + card_id + "'";


        //    String state = (cmbState.SelectedItem as ContentControl).Content.ToString();
        //    if (!IsNullOrEmpty(state))
        //        state = " having " + (state.Equals("已检") ? "sum(flag)>0" : (state.Equals("未检") ? "sum(flag)=0" : "sum(flag)<0"));
        //    else
        //        state = "";
        //    if (duplicateInspection.IsChecked.Value)
        //    {
        //        if (state.Length == 0)
        //            state = " having sum(flag)>1 ";
        //        else
        //            state += " and sum(flag)>1 ";
        //    }

        //    //如果卡号为空，不用人员查询，全连接
        //    if (rightJoinCriteria.Length == 0)
        //    {
        //        String HQL = @"select sum(abs(flag)) mark, cast(case when sum(flag)=0 then '未检' when sum(flag)>0 then '已检' else '新增' end as varchar(10)) state,  paperid paperid, road road, rarea rarea, building building, unit unit, floor floor, room room FROM      (select isnull(pid, -1) flag, isnull(pid, paperid) paperid, isnull(proad, troad) road , isnull(punit_name, tunit_name) rarea, isnull(pcus_dom, tcus_dom) building,isnull(pcus_dy, tcus_dy) unit, isnull(pcus_floor,tcus_floor) floor, isnull(pcus_room,  tcus_room) room from                                 (select t.id tid, p.id pid, t.checkpaper_id paperid,  t.road troad, t.unit_name tunit_name, t.cus_dom tcus_dom, t.cus_dy tcus_dy, t.cus_floor tcus_floor, t.cus_room tcus_room,p.road proad, p.unit_name punit_name, p.cus_dom pcus_dom, p.cus_dy pcus_dy, p.cus_floor pcus_floor, p.cus_room pcus_room   from                                  (select * from  T_IC_SAFECHECK_PAPER where CHECKPLANID='{0}') p full join (select * from T_INSPECTION where checkplan_id='{0}') t on p.id=t.checkpaper_id))       {1}                          group by paperid, road, rarea, building, unit, floor, room  {2} order by road, rarea, len(building), building, len(unit), unit, len(floor), floor, len(room), room";
        //        paperList.HQL = String.Format(HQL, new string[] { conditions.GetPropertyValue("CHECKPLANID") as string, criteria, state });
        //    }
        //    //否则退化成右连接
        //    else
        //    {
        //        String HQL = @"select sum(abs(flag)) mark, cast(case when sum(flag)=0 then '未检' when sum(flag)>0 then '已检' else '新增' end as varchar(10)) state,  paperid paperid, road road, rarea rarea, building building, unit unit, floor floor, room room FROM                                 (select isnull(pid, -1) flag, isnull(pid, paperid) paperid, isnull( proad, troad) road , isnull(punit_name,tunit_name) rarea, isnull(pcus_dom, tcus_dom) building,isnull(pcus_dy, tcus_dy) unit, isnull(pcus_floor, tcus_floor) floor, isnull(pcus_room,  tcus_room) room from                                 (select t.id tid, p.id pid, t.checkpaper_id paperid,  t.road troad, t.unit_name tunit_name, t.cus_dom tcus_dom, t.cus_dy tcus_dy, t.cus_floor tcus_floor, t.cus_room tcus_room,p.road proad, p.unit_name punit_name, p.cus_dom pcus_dom, p.cus_dy pcus_dy, p.cus_floor pcus_floor, p.cus_room pcus_room   from                                  (select * from  T_IC_SAFECHECK_PAPER where CHECKPLANID='{0}') p right join (select * from T_INSPECTION where checkplan_id='{0}' {1} ) t on p.id=t.checkpaper_id))       {2}                          group by paperid, road, rarea, building, unit, floor, room  {3} order by road, rarea, len(building), building, len(unit), unit, len(floor), floor, len(room), room";
        //        paperList.HQL = String.Format(HQL, new string[] { conditions.GetPropertyValue("CHECKPLANID") as string, rightJoinCriteria, criteria, state });
        //    }
        //    paperList.Load();
        //}

        /// <summary>
        /// 安检统计列表选择改变
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        //private void paperGrid_SelectionChanged(object sender, SelectionChangedEventArgs e)
        //{
        //    GeneralObject go = paperGrid.SelectedItem as GeneralObject;
        //    if (go == null)
        //        return;
        //    SearchObject conditions = (criteriaPanel.DataContext as SearchObject);
        //    if (go.GetPropertyValue("state").Equals("未检"))
        //    {
        //        String HQL = "select id, checkplanid, id id1, cast('未检' as varchar(10)) condition, null deleted, null  hasnotified, null  user_name, null  card_id, road, unit_name, cus_dom, cus_dy, cus_floor, cus_room, null  old_address, null  save_people, null  repairman  from t_ic_safecheck_paper where checkplanid='{0}' and road = '{1}' and unit_name='{2}' and cus_dom='{3}' and cus_dy='{4}' and cus_floor='{5}' and cus_room='{6}' and id='{7}'";
        //        checkList.HQL = String.Format(HQL, new String[] { conditions.GetPropertyValue("CHECKPLANID") as string, go.GetPropertyValue("road").ToString(), go.GetPropertyValue("rarea").ToString(), go.GetPropertyValue("building").ToString(), go.GetPropertyValue("unit").ToString(), go.GetPropertyValue("floor").ToString(), go.GetPropertyValue("room").ToString(), go.GetPropertyValue("paperid").ToString() });
        //        checkList.Load();
        //    }
        //    else
        //    {
        //        String rightJoinCriteria = " and 1=1 ";
        //        String repairman = conditions.GetPropertyValue("REPAIRMAN") as string;
        //        if (!IsNullOrEmpty(repairman))
        //            rightJoinCriteria += " and REPAIRMAN like '%" + repairman + "%'";
        //        String SAVE_PEOPLE = conditions.GetPropertyValue("SAVE_PEOPLE") as string;
        //        if (!IsNullOrEmpty(SAVE_PEOPLE))
        //            rightJoinCriteria += " and SAVE_PEOPLE like '%" + SAVE_PEOPLE + "%'";
        //        String card_id = conditions.GetPropertyValue("CARD_ID") as string;
        //        if (!IsNullOrEmpty(card_id))
        //            rightJoinCriteria += " and card_id =" + card_id + "'";

        //        String HQL = "select id, checkplan_id, checkpaper_id, condition, deleted, hasnotified, user_name, card_id, road, unit_name, cus_dom, cus_dy, cus_floor, cus_room, old_address, save_people, repairman from t_inspection where checkplan_id='{0}' and road = '{1}' and unit_name='{2}' and cus_dom='{3}' and cus_dy='{4}' and cus_floor='{5}' and cus_room='{6}' and checkpaper_id='{7}' {8}";
        //        checkList.HQL = String.Format(HQL, new String[] { conditions.GetPropertyValue("CHECKPLANID") as string, go.GetPropertyValue("road").ToString(), go.GetPropertyValue("rarea").ToString(), go.GetPropertyValue("building").ToString(), go.GetPropertyValue("unit").ToString(), go.GetPropertyValue("floor").ToString(), go.GetPropertyValue("room").ToString(), go.GetPropertyValue("paperid").ToString(), rightJoinCriteria });
        //        checkList.Load();
        //    }
        //}



        

        

       


       

 

 

        private void CheckCheckBox(String CONTENT, Panel panel)
        {
            foreach (UIElement element in panel.Children)
            {
                if (element is CheckBox)
                {
                    CheckBox aBox = element as CheckBox;
                    if (aBox.Content.ToString().Equals(CONTENT))
                        aBox.IsChecked = true;
                }
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
 

        /// <summary>
        /// 删除标记完成
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>        
        //private void wc_DeletionCompleted(object sender, UploadStringCompletedEventArgs e)
        //{
        //    paperGrid_SelectionChanged(null, null);
        //}


        



 



        

        private bool FillPrecautionsAccordingToChoices(Panel p, GeneralObject go, ObjectList lines, bool mustSelect, bool checkContradition, string equipment)
        {
            bool selected = false;
            bool normalChecked = false;
            bool abnormalChecked = false;
            foreach (UIElement element in p.Children)
            {
                if (element is CheckBox)
                {
                    CheckBox aBox = element as CheckBox;
                    if (aBox.IsChecked.HasValue && aBox.IsChecked.Value)
                    {
                        if (aBox.Content.Equals("无") || aBox.Content.Equals("正常"))
                            normalChecked = true;
                        else
                            abnormalChecked = true;
                    }
                    if (aBox.IsChecked.HasValue)
                        selected |= aBox.IsChecked.Value;
                }
            }
            if (!selected && mustSelect)
            {
                MessageBox.Show("请选择" + equipment + "隐患选项!");
                return false;
            }
            if (normalChecked && abnormalChecked && checkContradition)
            {
                MessageBox.Show("请检查" + equipment + "隐患选项!");
                return false;
            }

            foreach (UIElement element in p.Children)
            {
                if (element is CheckBox)
                {
                    CheckBox aBox = element as CheckBox;
                    if (aBox.IsChecked.HasValue && aBox.IsChecked.Value)
                    {
                        if (aBox.Content.Equals("无") || aBox.Content.Equals("正常"))
                            continue;
                        GeneralObject line = CreateALine(go);
                        lines.Add(line);
                        line.SetPropertyValue("EQUIPMENT", equipment, true);
                        line.SetPropertyValue("CONTENT", aBox.Content, true);
                    }
                }
            }
            return true;
        }



        private GeneralObject CreateALine(GeneralObject go)
        {
            GeneralObject me = new GeneralObject();
            me.EntityType = "T_INSPECTION_LINE";
            me.SetPropertyValue("CARD_ID", go.GetPropertyValue("CARD_ID"), true);
            me.SetPropertyValue("USER_NAME", go.GetPropertyValue("USER_NAME"), true);
            me.SetPropertyValue("ROAD", go.GetPropertyValue("ROAD"), true);
            me.SetPropertyValue("UNIT_NAME", go.GetPropertyValue("UNIT_NAME"), true);
            me.SetPropertyValue("CUS_DOM", go.GetPropertyValue("CUS_DOM"), true);
            me.SetPropertyValue("CUS_DY", go.GetPropertyValue("CUS_DY"), true);
            me.SetPropertyValue("CUS_FLOOR", go.GetPropertyValue("CUS_FLOOR"), true);
            me.SetPropertyValue("CUS_ROOM", go.GetPropertyValue("CUS_ROOM"), true);
            me.SetPropertyValue("TELPHONE", go.GetPropertyValue("TELPHONE"), true);
            me.SetPropertyValue("SAVE_PEOPLE", go.GetPropertyValue("SAVE_PEOPLE"), true);
            me.SetPropertyValue("SAVE_DATE", go.GetPropertyValue("SAVE_DATE"), true);
            me.SetPropertyValue("IC_METER_NAME", go.GetPropertyValue("IC_METER_NAME"), true);
            me.SetPropertyValue("JB_METER_NAME", go.GetPropertyValue("JB_METER_NAME"), true);
            me.SetPropertyValue("JB_NUMBER", go.GetPropertyValue("JB_NUMBER"), true);
            me.SetPropertyValue("SURPLUS_GAS", go.GetPropertyValue("SURPLUS_GAS"), true);
            return me;
        }

 


 
    }


}
