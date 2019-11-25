#include "Application.h"

#include <Windows.h>

extern "C" {
	bool InitDll()
	{
		return true;
	}

	bool ExitDll()
	{
		return true;
	}

	void* moduleHandle;
	std::string contentPath;
} // extern "C"

LPWSTR GetPluginPath()
{
	HMODULE hPlugin;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
		(LPWSTR)&GetPluginPath,
		&hPlugin);

	//Get full path including dll file.
	WCHAR dllPath[1024];
	GetModuleFileName(hPlugin, dllPath, sizeof(dllPath));

	//Remove the dll file name.
	WCHAR* dllFileName = wcsrchr(dllPath, L'\\');
	WCHAR pluginPath[1024];
	wcsncpy_s(pluginPath, dllPath, wcslen(dllPath) - wcslen(dllFileName));

	return pluginPath;
}

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD /*dwReason*/, LPVOID /*lpvReserved*/)
{
	moduleHandle = hInst;
	WCHAR* wContentPath = GetPluginPath();
	std::wstring wsContentPath(wContentPath);
	contentPath = std::string(wsContentPath.begin(), wsContentPath.end());
	
	return TRUE;
}