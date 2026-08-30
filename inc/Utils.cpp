#include "Utils.h"
#include "_precl.h"
#include <Windows.h>
#include <fstream>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;


std::string GetAsiPath()
{
	char			moduleName[MAX_PATH] = {'\0'};
	static char		dllPath[MAX_PATH];
	char* tempPointer = NULL;

	dllPath[0] = '\0';

	GetModuleFileName((HINSTANCE)&__ImageBase, moduleName, MAX_PATH);
	tempPointer = strrchr(moduleName, '.');
	*tempPointer = '\0';
	tempPointer = strrchr(moduleName, '\\');
	strncpy_s(dllPath, moduleName, (tempPointer - moduleName + 1));
	dllPath[tempPointer - moduleName + 1] = '\0';

	return dllPath;
}

std::string GetAsiName()
{
	char			moduleName[MAX_PATH] = {'\0'};
	GetModuleFileNameA((HINSTANCE)&__ImageBase, moduleName, MAX_PATH);
	
	const std::string moduleFileName = moduleName;
	
    return moduleFileName.substr(moduleFileName.find_last_of("/\\") + 1);
}

static void * TMP_RwEngineInstance = *(void **)ADDR_RWENGINEINSTANCE;

bool IsAsiLoaderUsed()
{
	return TMP_RwEngineInstance == NULL;
}

bool file_exists(const char *name)
{
    std::ifstream f(name);
    return f.good();
}

void PluginErrorCheck(unsigned int flags)
{
	if ( flags & PLUGINPREF_VERSION_ANY )
	{
		if ( !IsVersion_1_0() && !IsVersion_1_1() && !IsVersion_Steam() )
			FATAL("Unsupported game version.");
	}
	else
	{
		if ( flags & PLUGINPREF_VERSION_1_0 )
		{
			if ( !IsVersion_1_0() )
				FATAL("Unsupported game version.");
		}
		else if ( flags & PLUGINPREF_VERSION_1_1 )
		{
			if ( !IsVersion_1_1() )
				FATAL("Unsupported game version.");
		}
		else if ( flags & PLUGINPREF_VERSION_STEAM )
		{
			if ( !IsVersion_Steam() )
				FATAL("Unsupported game version.");
		}
	}

	if ( flags & PLUGINPREF_CHECK_ASI_LOADER )
	{
		if ( !IsAsiLoaderUsed() )
			FATAL("ASI Loader is missing.");
	}
}