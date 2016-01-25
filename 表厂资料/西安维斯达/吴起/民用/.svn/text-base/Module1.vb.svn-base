Option Explicit On

Module Module1

    ' 设备句柄
    Public icdev As Integer
    ' 区域号
    Public cityID As Integer

    ' 初始化设备
    Declare Function __InitNew Lib "CardMan2012.dll" Alias "Init" (ByRef icdev As Integer, ByVal port As Integer, ByVal baud As Integer) As Integer

    ' 释放设备
    Declare Function __FinishNew Lib "CardMan2012.dll" Alias "Finish" (ByRef icdev As Integer) As Integer

    ' 卡型识别
    Declare Function __TestCardKindNew Lib "CardMan2012.dll" Alias "TestCardKind" (ByVal icdev As Integer, ByVal cityID As Integer) As Integer

    ' 开户或制开户卡
    Declare Ansi Function __MakeOpenUserCardNew Lib "CardMan2012.dll" Alias "MakeOpenUserCardNew" (
        ByVal icdev As Integer,
        ByRef ID As Long, ByRef BuyedGasSum As Double, ByRef BuyedGasCount As Integer,
        ByRef CloseTapeCircle As Integer, ByRef OverCurrentProtectStartFlag As Boolean, ByVal cityID As Integer) As Integer

    ' 制购气卡
    Declare Function __MakeBuyGasCardNew Lib "CardMan2012.dll" Alias "MakeBuyGasCardNew" (
        ByVal icdev As Integer,
        ByRef ID As Long, ByRef BuyedGasSum As Double, ByRef BuyedGasCount As Integer,
        ByRef CloseTapeCircle As Integer, ByRef OverCurrentProtectStartFlag As Boolean, ByVal cityID As Integer) As Integer

    ' 购气
    Declare Function __BuyGasNew Lib "CardMan2012.dll" Alias "BuyGasNew" (
        ByVal icdev As Integer,
        ByRef ID As Long, ByRef BuyedGasSum As Double, ByRef BuyedGasCount As Integer,
        ByRef CloseTapeCircle As Integer, ByRef OverCurrentProtectStartFlag As Boolean, ByVal cityID As Integer) As Integer

    ' 制工具卡
    Declare Function __MakeToolCardNew Lib "CardMan2012.dll" Alias "MakeToolCardNew" (
       ByVal icdev As Integer, ByVal Kind As Integer, ByRef BuyedGasSum As Double,
       ByVal cityID As Integer) As Integer

    ' 读普通卡: 开户卡或购气卡
    Declare Function __ReadCardNew Lib "CardMan2012.dll" Alias "ReadCardNew" (ByVal icdev As Integer, ByVal Kind As Integer,
ByRef ID As Long, ByRef BuyedGasSum As Double, ByRef BuyedGasCount As Integer,
ByRef CloseTapeCircle As Integer, ByRef OverCurrentProtectStartFlag As Boolean,
ByRef ReturnReadFlag As Boolean,
       ByVal cityID As Integer) As Integer

    ' 读检测卡
    Declare Function __ReadDetectedCardNew Lib "CardMan2012.dll" Alias "ReadDetectedCardNew" (
          ByVal icdev As Integer,
          ByRef ID As Long, ByRef OpenUserStatus As Integer, ByRef BuyedGasSum As Double,
          ByRef BuyedGasCount As Integer, ByRef CloseTapeCircle As Integer, ByRef OverCurrentProtectValue As Integer,
          ByRef CloseTapeFlag As Boolean, ByRef UnusedGasDays As Integer,
          ByRef TotalUsedGasSum As Double, ByRef TotalBuyedGasSum As Double,
          ByRef Type As Long,
          ByVal cityID As Integer
          ) As Integer

    '写厂商代码
    Declare Function __WriteFirmTagNew Lib "CardMan2012.dll" Alias "WriteFirmTag" (ByVal icdev As Integer, ByVal cityID As Integer) As Integer

    '校验厂商代码
    Declare Function __CheckFirmTagNew Lib "CardMan2012.dll" Alias "CheckFirmTag" (ByVal icdev As Integer, ByVal cityID As Integer) As Integer

End Module
