//Import function from HH53IC.DLL
_declspec(dllimport) int HHInitCard(int icdev,char *CardNo,long GasV,int BuyTimes,short CardT);
_declspec(dllimport) int HHSellGas(int icdev,char *CardNo,long GasV,short BuyTimes);
_declspec(dllimport) int HHReadCardInfo(int icdev,char* CardNo,long* GasV,int* Times,long* RemainGas);
_declspec(dllimport) int HHChkFac(int icdev);
_declspec(dllimport) int HHClearCard(int icdev);
_declspec(dllimport) int HHModifyPassword(int icdev,int PasswordType);
_declspec(dllimport) int HHWriteToolCard(int icdev, int CardType);
_declspec(dllimport) int HHEditUserCardSet(int icdev,char *AreaCode, int Alert, int Overdraw, int MaxFlux, int ValveTest);
_declspec(dllimport) void HHSetCardPasswordType(int PwdType);