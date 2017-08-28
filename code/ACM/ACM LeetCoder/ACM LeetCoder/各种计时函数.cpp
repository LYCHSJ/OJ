//Windowsϵͳ��time()��clock()��timeGetTime()��GetTickCount()��QueryPerformanceCounter()����ʱ by MoreWindows
#include<stdio.h>
#include<Windows.h>
#include<time.h>//����time_t clock_t clock()
#include<mmsystem.h>//timeGetTime()
#pragma comment(lib, "Winmm.lib")   //timeGetTime() 

int main() {
	//��time()��ʱ �룡
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);
	Sleep(1000);
	timeEnd = time(NULL);
	printf("%d\n", timeEnd - timeBegin);

	//��clock()����ʱ ����
	clock_t clockBegin, clockEnd;
	clockBegin = clock();
	Sleep(800);
	clockEnd = clock();
	printf("%d\n", clockEnd - clockBegin);

	//timeGetTime()
	DWORD dwBegin, dwEnd;
	dwBegin = timeGetTime();
	Sleep(800);
	dwEnd = timeGetTime();
	printf("%d\n", dwEnd - dwBegin);

	//GetTickCount()
	DWORD dwGTCBegin, dwGTCEnd;
	dwGTCBegin = GetTickCount();
	Sleep(1000);
	dwGTCEnd = GetTickCount();
	printf("%d\n", dwGTCEnd - dwGTCBegin);

	//QueryPerformanceCounter() ΢�룡
	LARGE_INTEGER large_interger;
	double dff;
	__int64 c1, c2;
	QueryPerformanceFrequency(&large_interger);//�õ��߾��ȼ�ʱ����ÿ��Ƶ��
	dff = large_interger.QuadPart;
	QueryPerformanceCounter(&large_interger);//�õ���ʱ��ʱ��ֵ
	c1 = large_interger.QuadPart;
	Sleep(800);
	QueryPerformanceCounter(&large_interger);//�õ��ڶ��μ�ʱ��ֵ
	c2 = large_interger.QuadPart;
	printf("�����߾��ȼ�ʱ��Ƶ��%lf\n", dff);
	printf("��һ�μ�ʱ��ֵ%I64d �ڶ��μ�ʱ��ֵ%I64d ��ʱ����ֵ%I64d\n", c1, c2, c2 - c1);
	printf("��ʱ%lf����\n", (c2 - c1) * 1000 / dff);

	return 0;

}