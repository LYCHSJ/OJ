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

	//���ñ�������̻���Ϊʵʱִ�У������˳���
	SetPriorityClass(GetCurrentProcess, REALTIME_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread, THREAD_PRIORITY_TIME_CRITICAL);

	//֪ͨ��Դ����������ʾ�����򣬵�Ȼ�������û��������ɾ����ˢ����Դ���������Ի���ʾ�����ġ�
	SHChangeNotify(SHCNE_DELETE, SHCNF_PATH, _pgmptr, NULL);

	char szFilePath[MAX_PATH];
	sprintf(szFilePath, "\"%s\"", _pgmptr,NULL);
	ShellExecute(NULL, "open", "deletefile.bat", szFilePath, NULL, SW_HIDE);
	ExitProcess(0);
}

void DeleteApplicationSelf2() {
	char szCommandline[MAX_PATH + 10];

	//���ñ�������̻���Ϊʵʱִ�У������˳���
	SetPriorityClass(GetCurrentProcess, REALTIME_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread, THREAD_PRIORITY_TIME_CRITICAL);
	//֪ͨ��Դ����������ʾ�����򣬵�Ȼ�������û��������ɾ����ˢ����Դ���������Ի���ʾ�����ġ�
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