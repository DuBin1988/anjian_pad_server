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
using System.Runtime.InteropServices;
using System.Text;
using System.IO;

namespace Com.Aote.ObjectTools
{
    //咸阳折子操作对象
    public class XYZZObj : CustomTypeHelper, IAsyncObject
    {
        //打开磁卡读写机进行读写磁卡操作
        [System.Runtime.InteropServices.DllImportAttribute("YLE300_API")]
        public static extern int YLE300_Open(int ComPort);

        //从磁卡读写机读取指定磁道的数据，读取的数据在ReadData中，ReadData缓冲区必须大于300字节。若分配缓冲过小，可能引起内存存取错误。
        [System.Runtime.InteropServices.DllImportAttribute("YLE300_API")]
        public static extern int YLE300_Read(int TrackNo, byte[] ReadData);

        //将WriteData缓冲区中数据写入到磁卡的指定磁道
        [System.Runtime.InteropServices.DllImportAttribute("YLE300_API")]
        public static extern int YLE300_Write(int TrackNo, byte[] WriteData);

        //关闭磁卡读写机
        [System.Runtime.InteropServices.DllImportAttribute("YLE300_API")]
        public static extern int YLE300_Close();

        //写折数据
        private string writedata;
        public string WriteData
        {
            set 
            {
                this.writedata = value;
                OnPropertyChanged("WriteData");
            }
            get
            {
                return this.writedata;
            }
        }

        //读折数据
        private string readdata;
        public string ReadData
        {
            set
            {
                this.readdata = value;
                OnPropertyChanged("ReadData");
            }
            get
            {
                return this.readdata;
            }
        }

        //读折子
        public void Cardread()
        {
            ReadData = null;
            State = State.Start;
            IsBusy = true;
            int iComPort;
            iComPort = 0;
            long lRes = -1;
            lRes = YLE300_Open(iComPort);
            if (lRes != 0)
            {
                /* 打开失败 */
                string errorMessage = "读卡器打开失败！" + lRes;
                MessageBox.Show(errorMessage);
            }
            /* Open Success */
            byte[] str = new byte[128];
            lRes = YLE300_Read(2, str);
            string readresult = Encoding.UTF8.GetString(str, 0, 8); 
            if (lRes == 0)
            {
                ReadData = readresult;
                iComPort = 0;
                State = State.End;
            }
            else
            {
                State = State.Error;
                /* 读取磁道3失败 */
                string errorMessage = "Message: 读卡器读卡失败！";
                MessageBox.Show(errorMessage);
            }
            YLE300_Close();
            IsBusy = false;
        }

        //写折子
        public void Cardwrite()
        {
            State = State.Start;
            int iComPort;
            iComPort = 0;
            long lRes = -1;
            lRes = YLE300_Open(iComPort);
            if (lRes != 0)
            {
                /* 打开失败 */
                string errorMessage = "读卡器打开失败！" + lRes;
                MessageBox.Show(errorMessage);
            }
            /* Open Success */
            byte[] str = Encoding.UTF8.GetBytes(WriteData);
            lRes = YLE300_Write(2, str);    
            if (lRes == 0)
            {
                iComPort = 0;
                State = State.End;
            }
            else
            {
                State = State.Error;
                /* 读取磁道3失败 */
                string errorMessage = "Message: 读卡器写折失败！";
                MessageBox.Show(errorMessage);
            }
            YLE300_Close();
            IsBusy = false;
        }

        public bool isBusy = false;
        public bool IsBusy
        {
            get { return isBusy; }
            set
            {
                isBusy = value;
                OnPropertyChanged("IsBusy");
            }
        }

        #region State 卡状态
        public static readonly DependencyProperty StateProperty =
            DependencyProperty.Register("State", typeof(State), typeof(XYZZObj), null);

        public State State
        {
            get { return (State)GetValue(StateProperty); }
            set
            {
                SetValue(StateProperty, value);
            }
        }
        #endregion

        #region Error 卡错误
        public string error = "";
        public string Error
        {
            get { return error; }
            set
            {
                error = value;
                OnPropertyChanged("Error");
            }
        }
        #endregion


        public event System.ComponentModel.AsyncCompletedEventHandler Completed;

        public void OnCompleted(System.ComponentModel.AsyncCompletedEventArgs e)
        {
            if (Completed != null)
            {
                Completed(this, e);
            }
        }

        public string Name { get; set; }
    }
}
