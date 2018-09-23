// winmem.cpp : Display system memory information
//

#include "stdafx.h"
#include "Windows.h"


int main()
{
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);

	printf("MemoryLoadPercent=%ld,TotalPhys=%I64d,AvailPhys=%I64d,TotalPageFile=%I64d,AvailPageFile=%I64d\n", statex.dwMemoryLoad, statex.ullTotalPhys, statex.ullAvailPhys, statex.ullTotalPageFile, statex.ullAvailPageFile);

	return 0;
}
