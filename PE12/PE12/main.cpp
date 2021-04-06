// 1 - Start with a new C++ project.
// 1a - If you created an empty project then add a source file with any includes and using statements you need. Add a main function.
// 1b - Add the following headers
// 1bi - iostream
// 1bii - memory
#include <iostream>
#include <memory>
#include "GameLevel.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

// 3 - In the main.cpp,
// 3a - create a new function above the main and in there create a smart pointer variable to the class.
void smartPointerWrapper()
{
	std::unique_ptr<GameLevel> smartGameLevelPtr(new GameLevel());

	// Print the level's information
	smartGameLevelPtr->PrintInfo();
}

// 3b - create a new function above the main and in there create a normal pointer variable to the class. Do not delete the pointer and see that it is leaking when you call this function from the main.
void normalPointerWrapper()
{
	GameLevel* normalGameLevelPtr = new GameLevel();

	// Print the level's information
	normalGameLevelPtr->PrintInfo();
}

int main()
{
	std::cout << "==========Smart Pointer Wrapper==========" << std::endl;
	smartPointerWrapper();

	std::cout << "\n==========Normal Pointer Wrapper==========" << std::endl;
	normalPointerWrapper();

	// 3c - Also add your checks for memory leaks to the end of the main program.
	_CrtDumpMemoryLeaks();
}

// 4 - See that the memory is not leaking when you call the Smart Pointer function but is when you call the normal pointer version.

///
///	PROGARM RUN WITH SMART POINTER
/// - NO MEMORY LEAKS
/// 
/*'PE12.exe' (Win32) : Loaded 'E:\RIT\IGME 209\PE12\Debug\PE12.exe'.Symbols loaded.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\ntdll.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\kernel32.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\KernelBase.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\msvcp140d.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\vcruntime140d.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\ucrtbased.dll'.
The thread 0x4724 has exited with code 0 (0x0).
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\kernel.appcore.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\msvcrt.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\rpcrt4.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\sspicli.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\cryptbase.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\bcryptprimitives.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\sechost.dll'.
The thread 0x41ec has exited with code 0 (0x0).
The thread 0x5158 has exited with code 0 (0x0).
The thread 0x4abc has exited with code 0 (0x0).
The program '[19552] PE12.exe' has exited with code 0 (0x0).*/

///
/// PROGRAM RUN WITH NORMAL POINTER
/// - MEMORY LEAKS
/// 
/*'PE12.exe' (Win32) : Loaded 'E:\RIT\IGME 209\PE12\Debug\PE12.exe'.Symbols loaded.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\ntdll.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\kernel32.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\KernelBase.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\msvcp140d.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\vcruntime140d.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\ucrtbased.dll'.
The thread 0x1fdc has exited with code 0 (0x0).
Detected memory leaks!
Dumping objects ->
{219} normal block at 0x00B000A8, 8 bytes long.
	Data : < ^      > 0C 5E AF 00 00 00 00 00
{218} normal block at 0x00B002D8, 8 bytes long.
	Data : < ] > F0 5D AF 00 00 00 00 00
{217} normal block at 0x00B00540, 8 bytes long.
	Data : < ] > D4 5D AF 00 00 00 00 00
{216} normal block at 0x00AF5DD0, 88 bytes long.
	Data : < @   DUST    > 03 00 00 00 40 05 B0 00 44 55 53 54 00 CE C6 00
{215} normal block at 0x00B00230, 8 bytes long.
	Data : < `      > B8 60 AF 00 00 00 00 00
{210} normal block at 0x00AF60A8, 44 bytes long.
	Data : < ] > 01 00 00 00 00 00 00 00 03 00 00 00 D4 5D AF 00
Object dump complete.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\kernel.appcore.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\msvcrt.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\rpcrt4.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\sspicli.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\cryptbase.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\bcryptprimitives.dll'.
'PE12.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\sechost.dll'.
The thread 0x5734 has exited with code 0 (0x0).
The thread 0x5104 has exited with code 0 (0x0).
The thread 0x573c has exited with code 0 (0x0).
The program '[22404] PE12.exe' has exited with code 0 (0x0).*/