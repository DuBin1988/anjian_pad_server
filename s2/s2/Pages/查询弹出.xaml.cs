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
using Com.Aote.Controls;
using s2.Pages;
using System.Windows.Media.Imaging;

namespace Com.Aote.Pages
{
    public partial class 查询弹出 : CustomChildWindow
	{
		public 查询弹出()
		{
			// Required to initialize variables
			InitializeComponent();
			this.Loaded += 查询弹出_Loaded;
            
		}

		void 查询弹出_Loaded(object sender, RoutedEventArgs e)
		{
            //获取图片地址并赋给图片显示
            WebClientInfo wci = Application.Current.Resources["dbclient"] as WebClientInfo;
            //获取界面对象
            GeneralObject go = this.ParamValue as GeneralObject;

            //显示客户签名
            if (go.GetPropertyValue("USER_SIGN") != null)
            {
                image.Source = new BitmapImage(new Uri(wci.BaseAddress + "/file/" + go.GetPropertyValue("USER_SIGN"), UriKind.Absolute)); 
            }
            if (go.GetPropertyValue("PHOTO_FIRST") != null)
            {
                picture1.Source = new BitmapImage(new Uri(wci.BaseAddress + "/file/" + go.GetPropertyValue("PHOTO_FIRST"), UriKind.Absolute));
            }
            if (go.GetPropertyValue("PHOTO_SECOND") != null)
            {
                picture2.Source = new BitmapImage(new Uri(wci.BaseAddress + "/file/" + go.GetPropertyValue("PHOTO_SECOND"), UriKind.Absolute));
            }
            if (go.GetPropertyValue("PHOTO_THIRD") != null)
            {
                picture3.Source = new BitmapImage(new Uri(wci.BaseAddress + "/file/" + go.GetPropertyValue("PHOTO_THIRD"), UriKind.Absolute));
            }
            if (go.GetPropertyValue("PHOTO_FOUTH") != null)
            {
                picture4.Source = new BitmapImage(new Uri(wci.BaseAddress + "/file/" + go.GetPropertyValue("PHOTO_FOUTH"), UriKind.Absolute));
            }
            if (go.GetPropertyValue("PHOTO_FIFTH") != null)
            {
                picture5.Source = new BitmapImage(new Uri(wci.BaseAddress + "/file/" + go.GetPropertyValue("PHOTO_FIFTH"), UriKind.Absolute));
            }
            if (go.GetPropertyValue("PHOTO_SIXTH") != null)
            {
                picture6.Source = new BitmapImage(new Uri(wci.BaseAddress + "/file/" + go.GetPropertyValue("PHOTO_SIXTH"), UriKind.Absolute));
            }
            if (go.GetPropertyValue("PHOTO_SEVENTH") != null)
            {
                picture7.Source = new BitmapImage(new Uri(wci.BaseAddress + "/file/" + go.GetPropertyValue("PHOTO_SEVENTH"), UriKind.Absolute));
            }

               PostUITask(go);

                //ObjectList lines = go.GetPropertyValue("LINES") as ObjectList;
                ////不存在隐患
                //if (lines == null)
                //    return;

                //foreach (GeneralObject line in lines)
                //{
                //    String EQUIPMENT = line.GetPropertyValue("EQUIPMENT") as string;
                //    String CONTENT = line.GetPropertyValue("CONTENT") as string;
                //    if (EQUIPMENT.Equals("安全隐患"))
                //        CheckCheckBox(CONTENT, precautionCheckPane);
                //    else if (EQUIPMENT.Equals("燃气表"))
                //        CheckCheckBox(CONTENT, MeterDefectsPane);
                //    else if (EQUIPMENT.Equals("立管"))
                //        CheckPlumbingBox(CONTENT, PlumbingDefectsPane);
                //    else if (EQUIPMENT.Equals("阀门表前阀"))
                //        CheckCheckBox(CONTENT, PlumbingMeterValvePane);
                //    else if (EQUIPMENT.Equals("阀门灶前阀"))
                //        CheckCheckBox(CONTENT, PlumbingCookerValvePane);
                //    else if (EQUIPMENT.Equals("阀门自闭阀"))
                //        CheckCheckBox(CONTENT, PlumbingAutomaticValvePane);
                //    else if (EQUIPMENT.Equals("户内管"))
                //        CheckCheckBox(CONTENT, PlumbingPipePane);
                //    else if (EQUIPMENT.Equals("灶具软管"))
                //        CheckCheckBox(CONTENT, CookerPipePane);
                //    else if (EQUIPMENT.Equals("热水器软管"))
                //        CheckCheckBox(CONTENT, BoilerPipePane);
                //    else if (EQUIPMENT.Equals("热水器安全隐患"))
                //        CheckCheckBox(CONTENT, BoilerDefectsPane);
                //    else if (EQUIPMENT.Equals("壁挂锅炉安全隐患"))
                //        CheckCheckBox(CONTENT, WHEDefectsPane);
                //}

            
			this.slipPaper.DataContext = go;
        }   
        
        private void ClearChecks()
        {
            Panel[] panels = { MeterDefectsPane,  PlumbingDefectsPane, PlumbingProofPane, PlumbingPressurePane, PlumbingMeterValvePane, PlumbingCookerValvePane, PlumbingAutomaticValvePane, PlumbingPipePane, PlumbingLeakagePane, 
                                 CookerPipePane, BoilerPipePane, BoilerDefectsPane, WHEDefectsPane, precautionCheckPane };
            foreach (Panel p in panels)
            {
                foreach (UIElement element in p.Children)
                {
                    if (element is CheckBox && !(element as CheckBox).Content.ToString().Equals("正常") && !(element as CheckBox).Content.ToString().Equals("无"))
                    {
                        if (element == cbRIGIDITYLeakage || element == cbRIGIDITYNormal || element == cbPressureNormal || element == cbPressureAbnormal ||
                            element == cbLEAKAGE_COOKER || element == cbLEAKAGE_BOILER || element == cbLEAKAGE_HEATER || element == cbLEAKAGE_NOTIFIED)
                            continue;
                        (element as CheckBox).IsChecked = false;
                    }
                    if (element is RadioButton)
                        (element as RadioButton).IsChecked = false;
                }
            }
        }


        private void PostUITask(GeneralObject go)
        {
            if (go.GetPropertyValue("CONDITION").ToString().Equals("正常"))
            {
                //供暖方式
                if (go.GetPropertyValue("WARM").ToString().Equals("热力公司集中供暖") || go.GetPropertyValue("WARM").ToString  ().Equals("小区集中供暖") || go.GetPropertyValue("WARM").ToString().Equals("客户自行供暖") || go.GetPropertyValue("WARM").ToString().Equals("其他供暖"))
                   {
                       this.WARM.Text = go.GetPropertyValue("WARM").ToString();
                   }
                else
                {
                    this.WARM_OTHER.Text = go.GetPropertyValue("WARM").ToString();
                }
                
               //基表厂家型号
                if (go.GetPropertyValue("JB_METER_NAME").ToString().Equals("丹东") || go.GetPropertyValue("JB_METER_NAME").ToString  ().Equals("重检") || go.GetPropertyValue("JB_METER_NAME").ToString().Equals("赛福") || go.GetPropertyValue("JB_METER_NAME").ToString().Equals("重前") || go.GetPropertyValue("JB_METER_NAME").ToString().Equals("山城") || go.GetPropertyValue("JB_METER_NAME").ToString().Equals("天津自动化") || go.GetPropertyValue("JB_METER_NAME").ToString().Equals("其他"))
                   {
                       this.JB_METER_NAME.Text = go.GetPropertyValue("JB_METER_NAME").ToString();
                   }
                else
                {
                    this.JB_METER_NAME_OTHER.Text = go.GetPropertyValue("JB_METER_NAME").ToString();
                }
                      
                //IC卡表厂家型号
                if (go.GetPropertyValue("IC_METER_NAME").ToString().Equals("华捷") || go.GetPropertyValue("IC_METER_NAME").ToString  ().Equals("赛福") || go.GetPropertyValue("IC_METER_NAME").ToString().Equals("秦川") || go.GetPropertyValue("IC_METER_NAME").ToString().Equals("秦港") || go.GetPropertyValue("IC_METER_NAME").ToString().Equals("致力") || go.GetPropertyValue("IC_METER_NAME").ToString().Equals("其他") )
                   {
                      this.IC_METER_NAME.Text = go.GetPropertyValue("IC_METER_NAME").ToString();
                   }
                else
                {
                    this.IC_METER_NAME_OTHER.Text = go.GetPropertyValue("IC_METER_NAME").ToString();
                }
                
                ObjectList lines = go.GetPropertyValue("LINES") as ObjectList;
                //不存在隐患
                if (lines == null)
                    return;

                foreach (GeneralObject line in lines)
                {
                    String EQUIPMENT = line.GetPropertyValue("EQUIPMENT") as string;
                    String CONTENT = line.GetPropertyValue("CONTENT") as string;
                    if (EQUIPMENT.Equals("安全隐患"))
                        CheckCheckBox(CONTENT, precautionCheckPane);
                    else if (EQUIPMENT.Equals("燃气表"))
                        CheckCheckBox(CONTENT, MeterDefectsPane);
                    else if (EQUIPMENT.Equals("立管"))
                        CheckPlumbingBox(CONTENT, PlumbingDefectsPane);
                    else if (EQUIPMENT.Equals("阀门表前阀"))
                        CheckCheckBox(CONTENT, PlumbingMeterValvePane);
                    else if (EQUIPMENT.Equals("阀门灶前阀"))
                        CheckCheckBox(CONTENT, PlumbingCookerValvePane);
                    else if (EQUIPMENT.Equals("阀门自闭阀"))
                        CheckCheckBox(CONTENT, PlumbingAutomaticValvePane);
                    else if (EQUIPMENT.Equals("户内管"))
                        CheckCheckBox(CONTENT, PlumbingPipePane);
                    else if (EQUIPMENT.Equals("灶具软管"))
                        CheckCheckBox(CONTENT, CookerPipePane);
                    else if (EQUIPMENT.Equals("热水器软管"))
                        CheckCheckBox(CONTENT, BoilerPipePane);
                    else if (EQUIPMENT.Equals("热水器安全隐患"))
                        CheckCheckBox(CONTENT, BoilerDefectsPane);
                    else if (EQUIPMENT.Equals("壁挂锅炉安全隐患"))
                        CheckCheckBox(CONTENT, WHEDefectsPane);
                }

            }

        }

        private void wc_GetUserProfileCompleted(object sender, DownloadStringCompletedEventArgs e)
        {
            if (e.Error == null)
            {
                JsonObject item = JsonValue.Parse(e.Result) as JsonObject;
                String ROAD = null;
                String UNIT_NAME = null;
                String CUS_DOM = null;
                String CUS_DY = null;
                String CUS_FLOOR = null;
                String CUS_ROOM = null;
                if (item.ContainsKey("ROAD"))
                    ROAD = item["ROAD"];
                if (item.ContainsKey("UNIT_NAME"))
                    UNIT_NAME = item["UNIT_NAME"];
                if (item.ContainsKey("CUS_DOM"))
                    CUS_DOM = item["CUS_DOM"];
                if (item.ContainsKey("CUS_DY"))
                    CUS_DY = item["CUS_DY"];
                if (item.ContainsKey("CUS_FLOOR"))
                    CUS_FLOOR = item["CUS_FLOOR"];
                if (item.ContainsKey("CUS_ROOM"))
                    CUS_ROOM = item["CUS_ROOM"];
                CurrentArchiveAddress.Text = String.Format("{0}\t{1}\t{2}-{3}-{4}-{5}",
                    new String[] { ROAD, UNIT_NAME, CUS_DOM, CUS_DY, CUS_FLOOR, CUS_ROOM });
            }
        }

        private void CheckPlumbingBox(String CONTENT, Panel panel)
        {
            foreach (UIElement element in panel.Children)
            {
                if (element is CheckBox)
                {
                    CheckBox aBox = element as CheckBox;
                    if (aBox.Content.ToString().Equals(CONTENT))
                        aBox.IsChecked = true;
                }
                if (element is RadioButton)
                {
                    RadioButton aBox = element as RadioButton;
                    if (aBox.Content.ToString().Equals(CONTENT))
                    {
                        aBox.IsChecked = true;
                        cbEroded.IsChecked = true;
                    }
                }
            }
        }

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

        private Boolean IsNullOrEmpty(String value)
        {
            return value == null || value.Trim().Length == 0;
        }

       

    }
}