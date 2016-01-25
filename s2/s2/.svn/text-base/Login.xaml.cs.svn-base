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
using System.Windows.Navigation;
using Com.Aote.ObjectTools;

namespace Com.Aote.Pages
{
    public partial class Login : Page 
    {
        public Login()
        {
            InitializeComponent();
        }

        // Executes when the user navigates to this page.
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
        }

        private void okbutton_Click(object sender, RoutedEventArgs e)
        {
            GeneralObject go = loginForm.DataContext as GeneralObject;
            go.Completed += go_Completed;
            go.Load();
        }

        void go_Completed(object sender, System.ComponentModel.AsyncCompletedEventArgs e)
        {
            GeneralObject go = sender as GeneralObject;
            if (go.HasErrors)
            {
               // errorLoginTip.IsShow = true;
                go.Error = "";
            }
        }

 
     
    }
}
