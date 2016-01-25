using System;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using System.Windows.Data;
using Com.Aote.ObjectTools;

namespace Com.Aote.Converters
{
    public class StartConverter : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            ObjectList source = value as ObjectList;
            if (source == null)
            {
                return 0;
            }

            int count = source.Count;
            int bigCount = System.Convert.ToInt32(parameter);
            if (count >= bigCount)
            {
                return 0.08;
            }
            if (count == 1)
            {
                return 0.4;
            } if (count == 2)
            {
                return 0.24;
            } if (count == 3)
            {
                return 0.2;
            } if (count == 4)
            {
                return 0.12;
            } if (count == 5)
            {
                return 0.1;
            }
            return 0;
        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
