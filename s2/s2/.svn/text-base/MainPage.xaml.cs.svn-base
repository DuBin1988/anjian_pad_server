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
using Microsoft.Expression.Controls;
using System.Windows.Threading;
using Com.Aote.Utils;
using Com.Aote.ObjectTools;

namespace Com.Aote.Pages
{
	public partial class MainPage : UserControl
	{
		public MainPage()
		{
            this.Loaded += new RoutedEventHandler(MainPage_Loaded);
			// 为初始化变量所必需
			InitializeComponent();
        }

        void MainPage_Loaded(object sender, RoutedEventArgs e)
        {
            Com.Aote.ObjectTools.GeneralObject go = ObjectExtension.FindResource(this, "LoginUser") as Com.Aote.ObjectTools.GeneralObject;
            Com.Aote.ObjectTools.ObjectList ol = go.GetPropertyValue("functions") as Com.Aote.ObjectTools.ObjectList;
            //CommonList newol = new CommonList();
            foreach (Com.Aote.ObjectTools.GeneralObject item in ol)
            {
                //CommonObject co = new CommonObject();
                //co["name"] = item.GetPropertyValue("name");
                //co["icon"] = item.GetPropertyValue("icon");
                //co["childsShow"] = "Collapsed";
                item.SetPropertyValue("childsShow", "Collapsed", true);
                //CommonList newchildlist = new CommonList();
                //Com.Aote.ObjectTools.ObjectList childlist = item.GetPropertyValue("children") as Com.Aote.ObjectTools.ObjectList;
                //foreach (Com.Aote.ObjectTools.GeneralObject child in childlist)
                //{
                    //CommonObject newchild = new CommonObject();
                    //newchild["name"] = child.GetPropertyValue("name");
                    //newchild["link"] = child.GetPropertyValue("link");
                    //newchildlist.Add(newchild);
                //}
                //co["children"] = newchildlist;
                //newol.Add(co);
            }
            this.menus.ItemsSource = ol;
        }

        //隐藏功能菜单
        private GeneralObject selectObj = null;
        private void PathListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            PathListBox pathListBox = sender as PathListBox;
            if (selectObj != null)
            {
                selectObj.SetPropertyValue("childsShow", "Collapsed", false);
            }
            selectObj = pathListBox.SelectedItem as GeneralObject;
            if (selectObj != null)
            {
                selectObj.SetPropertyValue("childsShow", "Visible", false);
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            int count = (menus.ItemsSource as ObjectList).Count;
            double index = menus.StartItemIndex;
            if (count - index == 6)
            {
                return;
            }
            da.To += 0.1667;
            plblp.Start += 0.1667;
            if (index == count - 1)
            {
                menus.StartItemIndex = 0;
            }
            else
            {
                menus.StartItemIndex += 1;
            }
            Storyboard sb = this.Resources["OnLoaded1"] as Storyboard;
            DoubleAnimation da1 = sb.Children[0] as DoubleAnimation;
            da1.To -= 0.1667;
            sb.Begin();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            int count = (menus.ItemsSource as ObjectList).Count;
            double index = menus.StartItemIndex;
            if (index == 0)
            {
                return;
            }
            da.To -= 0.1667;
            plblp.Start -= 0.1667;
            if (index == 0)
            {
                menus.StartItemIndex = count - 1;
            }
            else
            {
                menus.StartItemIndex -= 1;
            }

            Storyboard sb = this.Resources["OnLoaded1"] as Storyboard;
            DoubleAnimation da1 = sb.Children[0] as DoubleAnimation;
            da1.To += 0.1667;
            sb.Begin();
        }

        DispatcherTimer timer = null;
        private void ListBox_MouseLeave(object sender, MouseEventArgs e)
        {
            timer = new DispatcherTimer();
            timer.Interval = new TimeSpan(0, 0, 0, 0, 500);
            timer.Tick -= timer_Tick;
            timer.Tick += new EventHandler(timer_Tick);
            timer.Start();
        }

         void timer_Tick(object sender, EventArgs e)
         {
             timer.Stop();
             selectObj.SetPropertyValue("childsShow", "Collapsed", false);
             timer = null;
         }

         private void menus_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
         {
             PathListBox pathListBox = sender as PathListBox;
             if (selectObj != null)
             {
                 selectObj.SetPropertyValue("childsShow", "Collapsed", false);
             }
             selectObj = pathListBox.SelectedItem as GeneralObject;
             if (selectObj != null)
             {
                 selectObj.SetPropertyValue("childsShow", "Visible", false);
             }
         }

         private void ListBox_MouseEnter(object sender, MouseEventArgs e)
         {
             if (timer != null)
             {
                 timer.Stop();
             }
         }
	}
}