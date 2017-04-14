#ifndef __SKARDLL_H__
#define __SKARDLL_H__

#include <windows.h>



typedef int (__stdcall TSW_PROC)(int switchnb, int dir);
TSW_PROC* SW_PROC;

typedef int (__stdcall Tlog_PROC)(PCHAR ModuleName, PCHAR text);
Tlog_PROC* log_PROC;


typedef int(__stdcall Tanalog_PROC)(PCHAR ModuleName, int switchnb, int dir, int max, int min);
Tanalog_PROC* analog_PROC;




int API_SW_UP = 2;
int API_SW_DN = 1;
int API_SW_TOGGLE = 3;


//extern "C" {

	__declspec(dllexport) int __stdcall Start(PCHAR RootPath);
	__declspec(dllexport) int __stdcall Close(int pnil);
	__declspec(dllexport) int __stdcall LEDs(int LED, int State);
	__declspec(dllexport) int __stdcall TestLEDs(BOOL bln);
	__declspec(dllexport) int __stdcall GetLogProc(Tlog_PROC* proc);
	__declspec(dllexport) int __stdcall FastTimer(void);
	__declspec(dllexport) char* __stdcall License(char* key);

//}
#endif
