// C++ header
#include <iostream>

// User-defined header
#include "WindowsHelper.h"

int main()
{
	std::wcout << Helper::Windows::getWindowsDirectoryPath();
	std::wcin.get();
	return 0;
}