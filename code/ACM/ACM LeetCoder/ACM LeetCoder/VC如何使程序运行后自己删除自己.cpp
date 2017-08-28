#include<iostream>
#include<windows.h>
#include<shlobj.h>
#include<stdlib.h>
#include<shellapi.h>

int WriteTextToFile(const char * FileName, const char * inputText) {
	FILE *pfile = fopen(FileName, "+w");
	if (pfile == NULL) return -1;
	int retTextBytes = fprintf(pfile, inputText);
	fclose(pfile);
	return retTextBytes;
}
void DeleteApplicationSelf() {
	const char * szFileName = "deletefile.bat";
	const char * szDeleteBat = "@ echo off\n del %%1\"\n del %%0";

	WriteTextToFile(szFileName, szDeleteBat);

	//设置本程序进程基本为实时执行，快速退出。
	SetPriorityClass(GetCurrentProcess, REALTIME_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread, THREAD_PRIORITY_TIME_CRITICAL);

	//通知资源管理器不显示本程序，当然如果程序没有真正的删除，刷新资源管理器后仍会显示出来的。
	SHChangeNotify(SHCNE_DELETE, SHCNF_PATH, _pgmptr, NULL);

	char szFilePath[MAX_PATH];
	sprintf(szFilePath, "\"%s\"", _pgmptr,NULL);
	ShellExecute(NULL, "open", "deletefile.bat", szFilePath, NULL, SW_HIDE);
	ExitProcess(0);
}

void DeleteApplicationSelf2() {
	char szCommandline[MAX_PATH + 10];

	//设置本程序进程基本为实时执行，快速退出。
	SetPriorityClass(GetCurrentProcess, REALTIME_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread, THREAD_PRIORITY_TIME_CRITICAL);
	//通知资源管理器不显示本程序，当然如果程序没有真正的删除，刷新资源管理器后仍会显示出来的。
	SHChangeNotify(SHCNE_DELETE, SHCNF_PATH, _pgmptr, NULL);

	char szFilePath[MAX_PATH];
	sprintf(szFilePath, "\"%s\"", _pgmptr);
	sprintf(szCommandline, "/c del /q %s", szFilePath);
	ShellExecute(NULL, "open", "cmd.exe", szCommandline, NULL, SW_HIDE);
	ExitProcess(0);
}

int main() {
	DeleteApplicationSelf2();
	return 0;
}