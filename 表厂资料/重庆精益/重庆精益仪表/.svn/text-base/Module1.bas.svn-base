Attribute VB_Name = "Module1"


Public Declare Function GethCom Lib "CQJYHDDll.dll" Alias "_GethCom@0" () As Long
Public Declare Function CloseHdl Lib "CQJYHDDll.dll" Alias "_CloseHdl@4" (ByVal icdev As Long) As Integer
Public Declare Function OpenComm Lib "CQJYHDDll.dll" Alias "_OpenComm@4" (ByVal portno As Integer) As Integer


Public Declare Function rdcompany Lib "CQJYHDDll.dll" Alias "_rdcompany@8" (ByVal icdev As Long, ByRef istrue As Byte) As Integer

Public Declare Function makeCard Lib "CQJYHDDll.dll" Alias "_makeCard@60" (ByVal icdev As Long, ByVal factoryCode As String, ByVal CardNo As String, ByVal customeno As String, ByVal orderdate As String, ByVal orderNum As Long, ByVal orderamount As Long, ByVal ordertotal As Long, ByVal fgs As String, ByVal glz As String, ByVal keycode As String, ByVal alertLowLimit As Long, ByVal overDraft As Long, ByVal idleDays As Integer, ByVal upLimit As Long) As Integer

Public Declare Function writeOrders Lib "CQJYHDDll.dll" Alias "_writeOrders@32" (ByVal icdev As Long, ByVal CardNo As String, ByVal customeno As String, ByVal orderdate As String, ByVal orderNum As Long, ByVal orderamount As Long, ByVal ordertotal As Long, ByVal keycode As String) As Integer

Public Declare Function readCard Lib "CQJYHDDll.dll" Alias "_readCard@36" (ByVal icdev As Long, ByRef CardNo As Byte, ByVal customeno As String, ByVal orderdate As String, ByRef orderamount As Long, ByRef orderNum As Long, ByVal ordertotal As Long, ByVal fgs As String, ByVal glz As String) As Integer


Public Declare Function clearCard Lib "CQJYHDDll.dll" Alias "_clearCard@8" (ByVal icdev As Long, ByVal keycode As String) As Integer

