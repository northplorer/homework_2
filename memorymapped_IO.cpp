// memorymapped_IO.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdint.h>
#include <conio.h>
#include "StopWatch.h"
#include "mmio.h"
#include "FileIoHelperClass.h"

int _tmain(int argc, _TCHAR* argv[])
{
	uint32_t mgSize = 4096;

	LARGE_INTEGER Size;
	Size.QuadPart = (LONGLONG)(1024 * 1024) * (LONGLONG)mgSize;;

	_ASSERTE(create_very_big_file(L"big.txt", mgSize));

	StopWatch sw;
	sw.Start();
	_ASSERTE(file_copy_using_read_write(L"big.txt", L"big2.txt"));
	sw.Stop();
	print("info] time elapsed = %f", sw.GetDurationSecond());


	DWORD bufSize = 4096;
	PUCHAR buf = (PUCHAR)malloc(bufSize);

	LARGE_INTEGER offset;
	offset.QuadPart = (LONGLONG)0;

	StopWatch sw2;
	sw2.Start();
	
	FileIoHelper FIhelper;
	FIhelper.FIOpenForRead(L"big.txt");
	FIhelper.FIOCreateFile(L"big3.txt", Size);

	while (offset.QuadPart < Size.QuadPart)
	{
		if ((Size.QuadPart - offset.QuadPart) > (LONGLONG)bufSize)
		{
			bufSize = 4096;
		}
		else
		{
			bufSize = (DWORD)(Size.QuadPart - offset.QuadPart);
		}
		
		FIhelper.FIOReadFromFile(offset, bufSize, buf);
		FIhelper.FIOWriteToFile(offset, bufSize, buf);

		offset.QuadPart += (LONGLONG)bufSize;
	}

	sw2.Stop();
	print("info] time elapsed = %f", sw2.GetDurationSecond());

	free(buf);
	FIhelper.FIOClose();

	return 0;
}

