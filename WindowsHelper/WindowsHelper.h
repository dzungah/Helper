#pragma once
#ifndef HELPER_WINDOWS_H
#define HELPER_WINDOWS_H

#ifdef WINDOWSHELPER_EXPORTS
#define WINDOWSHELPER_API __declspec(dllexport)
#else
#define WINDOWSHELPER_API __declspec(dllimport)
#endif

// C++ header
#include <string>


namespace Helper::Windows
{
/// Known folder
WINDOWSHELPER_API std::wstring getWindowsDirectoryPath();                       
}


#endif // HELPER_WINDOWS_H
