// winmem.cpp : Display system memory information
//

#include "stdafx.h"
#include "Windows.h"


int main()
{
	char *host, *host_lower;
	size_t len;
	errno_t err = _dupenv_s(&host, &len, "COMPUTERNAME");
	if (err) {
		host_lower = '\0';
	}
	else {
		err = _strlwr_s(host_lower = _strdup(host), strlen(host) + 1);
		if (err) {
			host_lower = '\0';
		}
	}

	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);

	printf("Host=%s,MemoryLoadPercent=%ld,TotalPhys=%I64d,AvailPhys=%I64d,TotalPageFile=%I64d,AvailPageFile=%I64d\n", host_lower, statex.dwMemoryLoad, statex.ullTotalPhys, statex.ullAvailPhys, statex.ullTotalPageFile, statex.ullAvailPageFile);
	free(host);
	free(host_lower);

	return 0;
}
