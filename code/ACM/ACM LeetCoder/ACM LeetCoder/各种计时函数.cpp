//Windows系统下time()，clock()，timeGetTime()，GetTickCount()，QueryPerformanceCounter()来计时 by MoreWindows
#include<stdio.h>
#include<Windows.h>
#include<time.h>//导入time_t clock_t clock()
#include<mmsystem.h>//timeGetTime()
#pragma comment(lib, "Winmm.lib")   //timeGetTime() 

int main() {
	//用time()计时 秒！
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);
	Sleep(1000);
	timeEnd = time(NULL);
	printf("%d\n", timeEnd - timeBegin);

	//用clock()来计时 毫秒
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

	//QueryPerformanceCounter() 微秒！
	LARGE_INTEGER large_interger;
	double dff;
	__int64 c1, c2;
	QueryPerformanceFrequency(&large_interger);//得到高精度计时器的每秒频率
	dff = large_interger.QuadPart;
	QueryPerformanceCounter(&large_interger);//得到当时计时器值
	c1 = large_interger.QuadPart;
	Sleep(800);
	QueryPerformanceCounter(&large_interger);//得到第二次计时器值
	c2 = large_interger.QuadPart;
	printf("本机高精度计时器频率%lf\n", dff);
	printf("第一次计时器值%I64d 第二次计时器值%I64d 计时器差值%I64d\n", c1, c2, c2 - c1);
	printf("计时%lf毫秒\n", (c2 - c1) * 1000 / dff);

	return 0;

}