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
    public class WidthConverter : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            ObjectList source = value as ObjectList;
            if (source == null)
            {
                return 0;
            }

            int count = source.Count;
            
            char[] c = { ';' };
            string[] param = parameter.ToString().Split(c);
            int bigWidth = System.Convert.ToInt32(param[0]);
            int bigCount = System.Convert.ToInt32(param[1]);
            
            if (count >= bigCount)
            {
                return bigWidth;
            }
            return bigWidth / bigCount * count;
        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
