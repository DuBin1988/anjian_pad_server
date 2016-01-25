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

namespace s2.Pages
{
    public partial class 用气地址查询 : UserControl
    {
        public 用气地址查询()
        {
            InitializeComponent();
        }

        private void searchbutton_Click(object sender, RoutedEventArgs e)
        {
            SearchObject conditions = (applysearch.DataContext as SearchObject);
            conditions.Search();
            WebClientInfo wci = App.Current.Resources["dbclient"] as WebClientInfo;
            String where = conditions.Condition;
            checkerList.Path = "sql";
            checkerList.Names = "f_cusDom,f_cusDy,f_cusFloor,f_apartment";
            String sql = @"select f_cusDom,f_cusDy,f_cusFloor,f_apartment from t_gasaddress where {0} order by length(f_cusDom),f_cusDom,length(f_cusDy),f_cusDy,length(f_cusFloor),f_cusFloor,length(f_apartment),f_apartment";
            checkerList.HQL = String.Format(sql,where);
            checkerList.Load();
        }
    }
}
