VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   6315
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   3630
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   6315
   ScaleWidth      =   3630
   StartUpPosition =   2  '屏幕中心
   Begin VB.CommandButton Command2 
      Caption         =   "关闭串口"
      Height          =   495
      Left            =   1800
      TabIndex        =   18
      Top             =   4080
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "打开串口"
      Height          =   495
      Left            =   240
      TabIndex        =   17
      Top             =   4080
      Width           =   1215
   End
   Begin VB.CommandButton Command6 
      Caption         =   "退出"
      Height          =   495
      Left            =   600
      TabIndex        =   16
      Top             =   5520
      Width           =   2175
   End
   Begin VB.CommandButton Command5 
      Caption         =   "判断厂家"
      Height          =   495
      Left            =   480
      TabIndex        =   15
      Top             =   4800
      Width           =   855
   End
   Begin VB.Frame Frame4 
      Caption         =   "城市代码(4位数字)"
      Height          =   855
      Left            =   120
      TabIndex        =   12
      Top             =   1080
      Width           =   3375
      Begin VB.TextBox Text4 
         Height          =   375
         Left            =   1200
         MaxLength       =   4
         TabIndex        =   14
         Top             =   360
         Width           =   1935
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         Caption         =   "城市代码："
         Height          =   180
         Left            =   120
         TabIndex        =   13
         Top             =   360
         Width           =   900
      End
   End
   Begin VB.CommandButton Command4 
      Caption         =   "写卡"
      Height          =   495
      Left            =   2400
      TabIndex        =   11
      Top             =   4800
      Width           =   855
   End
   Begin VB.CommandButton Command3 
      Caption         =   "读卡"
      Height          =   495
      Left            =   1440
      TabIndex        =   10
      Top             =   4800
      Width           =   855
   End
   Begin VB.Frame Frame3 
      Caption         =   "卡类型"
      Height          =   855
      Left            =   120
      TabIndex        =   7
      Top             =   120
      Width           =   3375
      Begin VB.ComboBox Combo1 
         Height          =   300
         Left            =   1200
         Style           =   2  'Dropdown List
         TabIndex        =   9
         Top             =   360
         Width           =   1935
      End
      Begin VB.Label Label4 
         AutoSize        =   -1  'True
         Caption         =   "卡类型选择："
         Height          =   180
         Left            =   120
         TabIndex        =   8
         Top             =   360
         Width           =   1080
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "用户信息"
      Height          =   1815
      Left            =   120
      TabIndex        =   0
      Top             =   2040
      Width           =   3375
      Begin VB.TextBox Text3 
         Height          =   375
         Left            =   840
         TabIndex        =   6
         Top             =   1320
         Width           =   2415
      End
      Begin VB.TextBox Text2 
         Height          =   375
         Left            =   840
         TabIndex        =   5
         Top             =   840
         Width           =   2415
      End
      Begin VB.TextBox Text1 
         Height          =   375
         Left            =   840
         MaxLength       =   10
         TabIndex        =   4
         Top             =   360
         Width           =   2415
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "气量："
         Height          =   180
         Left            =   240
         TabIndex        =   3
         Top             =   1320
         Width           =   540
      End
      Begin VB.Label Label2 
         AutoSize        =   -1  'True
         Caption         =   "次数："
         Height          =   180
         Left            =   240
         TabIndex        =   2
         Top             =   840
         Width           =   540
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         Caption         =   "卡号："
         Height          =   180
         Left            =   240
         TabIndex        =   1
         Top             =   360
         Width           =   540
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Dim intRet As Integer
Dim intPort As Integer

Dim bufCardNo(20) As Byte
Dim lngGas(3) As Long
Dim lngTimes(3) As Long
Dim strCityCode As String
Dim strUserCard As String
Dim lnReadGas As Long
Dim sgRemainGas As Single
Dim lngBuyTimes As Integer
Dim blnCard As Boolean
Dim blnOpenCom As Boolean
Dim intDev As Long
Dim i As Integer
Dim lngTotal As Long


Private Sub Command1_Click()
    intRet = OpenComm(0)
    If intRet <> 7 Then
        funmsgBox (intRet)
        blnOpenCom = False
        Exit Sub
    End If
    '获取句柄
    intDev = GethCom()
    'MsgBox intDev
    blnOpenCom = True
    MsgBox "打开串口成功！"
    Command1.Enabled = False
End Sub

Private Sub Command2_Click()
    '关闭串口
    If blnOpenCom = True Then
        intRet = CloseHdl(intDev)
        Command1.Enabled = True
    End If
End Sub

Private Sub Command3_Click()
    '读卡
    If Trim(Text4.Text) = "" Then
        MsgBox "输入城市代码！", vbExclamation, "提示"
        Exit Sub
    End If
    
    strCityCode = Trim(Text4.Text)
    'MsgBox intDev
    intRet = readCard(intDev, bufCardNo(0), strCityCode, "", lngGas(0), lngTimes(0), lngTotal, "", "")
'    MsgBox intRet
    If intRet <> 1 And intRet <> 2 Then
        funmsgBox (intRet)
        Exit Sub
    End If
    
    If intRet = 1 Then
        Combo1.Text = "开户卡"
    Else
        Combo1.Text = "购气卡"
    End If
    strUserCard = ""
    For i = 0 To 9
        strUserCard = strUserCard + Format(Chr(bufCardNo(i)), "0")
    Next
'    strUserCard = Format(CStr(bufCardNo(0)), "00") + Format(CStr(bufCardNo(1)), "00") + Format(CStr(bufCardNo(2)), "00") + Format(CStr(bufCardNo(3)), "00") + Format(CStr(bufCardNo(4)), "00")
    lnReadGas = lngGas(0)
     sgRemainGas = lnReadGas / 1000
    lngBuyTimes = lngTimes(0)
    Text1.Text = strUserCard
    Text2.Text = lngBuyTimes
    Text3.Text = sgRemainGas
    
End Sub

Private Sub Command4_Click()
    Dim intBZ As Integer
    
   '写卡
   strUserCard = Format(Trim(Text1.Text), "0000000000")
   lngBuyTimes = Val(Text2.Text)
   sgRemainGas = Format(Val(Text3.Text), "##0.000")
   lnReadGas = sgRemainGas * 1000
   strCityCode = Trim(Text4.Text)
   
    Select Case Trim(Combo1.Text)
        Case "开户卡"
            intRet = makeCard(intDev, "0", strUserCard, "", "", lngBuyTimes, lnReadGas, 0, "", "", strCityCode, 0, 0, 0, 0)
            intBZ = 1
        Case "购气卡"
            intRet = writeOrders(intDev, strUserCard, "", "", lngBuyTimes, lnReadGas, lngTotal, "")
            intBZ = 1
        Case "补卡"
           intRet = makeCard(intDev, "1", strUserCard, "", "", lngBuyTimes, lnReadGas, 0, "", "", strCityCode, 0, 0, 0, 0)
            intBZ = 1
        Case "换表补气"
           intRet = makeCard(intDev, "2", strUserCard, "", "", lngBuyTimes, lnReadGas, 0, "", "", strCityCode, 0, 0, 0, 0)
            intBZ = 1
        Case "新卡"
            intRet = clearCard(intDev, "")
            intBZ = 2
    End Select
    '进行判断
'    If intBZ = 1 Then
'        If blnCard = False Then '
'            MsgBox "写卡失败"
'        Else
'            MsgBox "写卡成功"
'        End If
'    ElseIf intBZ = 2 Then
        If intRet <> 12 Then
            funmsgBox (intRet)
            MsgBox "写卡失败"
        Else
            
            MsgBox "写卡成功"
        End If
'    End If
    
    
    
End Sub

Private Sub Command5_Click()
    Dim strByte(10) As Byte
    
    intRet = rdcompany(intDev, strByte(0))
    funmsgBox (intRet)
    Exit Sub
    
End Sub

Private Sub Command6_Click()
    
    Unload Me
    
End Sub

Private Sub Form_Load()
    
    Combo1.AddItem "开户卡"
    Combo1.AddItem "购气卡"
    Combo1.AddItem "新卡"
    Combo1.AddItem "补卡"
    Combo1.AddItem "换表补气"
    
    Combo1.Text = "开户卡"
    intDev = 0
    
End Sub

' -4    //不是本厂家的卡
' -3    //操作失败
'-2     //--- 串口错误
'-1     // --- 无卡
'0    //未知卡
'1    //民用开户卡
'2    //民用用户卡
'3    //操作成功
'4    //串口正确
'5     //--- 密码错误
'6    //精益厂家
'7     //工具卡 7
'8    //新卡
'9     //精益新卡
'10    //卡坏
'11    //城市代码不正确

Private Function funmsgBox(intMsg As Integer)
    Select Case intMsg
        Case 4
            MsgBox "不是本厂家的卡", vbExclamation, "提示"
        Case 128
            MsgBox "操作失败", vbExclamation, "提示"
        Case 5
            MsgBox "串口错误", vbExclamation, "提示"
        Case 134
            MsgBox "无卡", vbExclamation, "提示"
        Case 137
            MsgBox "未知卡", vbExclamation, "提示"
        Case 1
            MsgBox "民用开户卡", vbExclamation, "提示"
        Case 2
            MsgBox "民用用户卡", vbExclamation, "提示"
        Case 12
            MsgBox "操作成功", vbExclamation, "提示"
        Case 7
            MsgBox "串口正确", vbExclamation, "提示"
        Case 131
            MsgBox "密码错误", vbExclamation, "提示"
        Case 8
            MsgBox "精益厂家", vbExclamation, "提示"
        Case 9
            MsgBox "工具卡", vbExclamation, "提示"
        Case 10
            MsgBox "新卡", vbExclamation, "提示"
        Case 3
            MsgBox "精益新卡", vbExclamation, "提示"
        Case 162
            MsgBox "卡坏", vbExclamation, "提示"
        Case 11
            MsgBox "城市代码不正确", vbExclamation, "提示"
        
    
    End Select

End Function

Private Sub Form_Unload(Cancel As Integer)
Command2_Click
End Sub
