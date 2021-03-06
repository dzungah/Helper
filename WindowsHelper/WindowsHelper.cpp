// WindowsHelper.cpp : Defines the exported functions for the DLL application.
//

// C++ header
#include <cassert>

// Windows header
#include <ShlObj.h>

// User-defined header
#include "header.h"
#include "WindowsHelper.h"


namespace Helper::Windows
{

std::wstring getKnownFolderPath(
		REFKNOWNFOLDERID	rfid,
		DWORD				dwFlags,
		HANDLE				hToken)
{
	PWSTR pszPath = NULL;
	auto result = SHGetKnownFolderPath(rfid, dwFlags, hToken, &pszPath);

	if (S_OK != result)
	{
		auto ev = static_cast<int>(result);
		auto ec = std::error_code(ev, std::system_category());
		throw std::system_error(ec, "SHGetKnownFolderPath failed");
	}

	// Get result
	std::wstring path(pszPath);
	path += L'\\';

	// Clean up
	CoTaskMemFree(pszPath);
	return path;
}

std::wstring getKnownFolderPath(REFKNOWNFOLDERID rfid)
{
	return getKnownFolderPath(rfid, KF_FLAG_DEFAULT, NULL);
}

std::wstring getWindowsDirectoryPath()
{
	return getKnownFolderPath(FOLDERID_Windows);
}

}

