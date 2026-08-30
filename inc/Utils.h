#pragma once
#include <string>

extern bool IsAsiLoaderUsed();
extern std::string GetAsiPath();
extern std::string GetAsiName();

enum
{
	PLUGINPREF_VERSION_1_0      = (1<<(0)),
	PLUGINPREF_VERSION_1_1      = (1<<(1)),
	PLUGINPREF_VERSION_STEAM    = (1<<(2)),
	PLUGINPREF_VERSION_ANY      = (1<<(3)),
	PLUGINPREF_CHECK_ASI_LOADER = (1<<(4))	
};

extern void PluginErrorCheck(unsigned int flags);
extern bool file_exists(const char *name);