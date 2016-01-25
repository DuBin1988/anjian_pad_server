using Com.Aote.ObjectTools;
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

namespace Com.Aote.Pages
{
    public partial class 用气地址副本 : UserControl
    {
        public 用气地址副本()
        {
            InitializeComponent();
        }

        private void save_Click(object sender, RoutedEventArgs e)
        {
            (apply.DataContext as Com.Aote.ObjectTools.GasADObject).Invoke();
            System.Collections.Generic.IList<Com.Aote.ObjectTools.IName> list = this.pageResource.Res;
            foreach (Com.Aote.ObjectTools.IName obj in list)
                if (obj.Name.Equals("openchild"))
                {
                    Com.Aote.ObjectTools.GeneralObject go = new ObjectTools.GeneralObject();
                    go.AddProperty("f_districtname");
                    go.AddProperty("f_road");
                    ((Com.Aote.ObjectTools.ChildWindowObj)obj).Result = go;
                }
        }

        private void applys_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            if(e.ClickCount==2)
            {
                GeneralObject go = (applys.SelectedItem as GeneralObject);
                
            }
        }


    }
}
