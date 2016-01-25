#include "extcode.h"
#pragma pack(push)
#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

int32_t __stdcall rdcompany(int32_t icDev, char isTrue[], int32_t len);
int32_t __stdcall readCard(int32_t icDev, char cardNo[], char customeNo[], 
	char orderdate[], double *orderAmount, uint64_t *orders, double *orderTotal, 
	char fgs[], char glz[], char type[], int32_t len);
int32_t __stdcall writeOrders(int32_t icDev, char cardNo[], char customeNo[], 
	char orderDate[], uint32_t orderNum, double orderAmount, double orderTotal, 
	char keyCode[]);
int32_t __stdcall makeCard(int32_t icDev, char cardNo[], char customerNo[], 
	char orderdate[], uint32_t orderNum, double orderAmount, double orderTotal, 
	char fgs[], char glz[], char keycode[]);
int32_t __stdcall clearCard(int32_t icDev, char keyCode[]);
int32_t __stdcall PC_CheckCardType(int32_t icDev, char CardCalss[], 
	int32_t len);
int32_t __stdcall BuOrdersCard(int32_t icDev, char cardNo[], 
	char orderAmount[], char orderNum[]);

long __cdecl LVDLLStatus(char *errStr, int errStrLen, void *module);

#ifdef __cplusplus
} // extern "C"
#endif

#pragma pack(pop)

