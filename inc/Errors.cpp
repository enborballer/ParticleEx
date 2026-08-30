#include "Errors.h"
#include <Windows.h>
#include <stdio.h>
#include <signal.h>
#include "_config.h"

void _Assert(eAssertType as, const char *file, int line, const char *func, const char *expr, const char *msg, ...)
{
	va_list ap;

	char buff[4096];
	char msgBuff[2048];
	char boxtitle[512];
	
	sprintf_s(boxtitle, "%s(%s): Shit Happens!\n", PROJECT_NAME, __TIMESTAMP__); //PROJECT_NAME
	
	if (msg)
	{
		va_start(ap, msg);
		vsprintf_s(msgBuff, msg, ap);
	}
	
	if ( as == ASSTYPE_ASSERT )
		sprintf_s(buff, "Assertion Failed!\n\n");
	else if ( as == ASSTYPE_FATAL_ERROR )
		sprintf_s(buff, "Fatal Error!\n\n");
	
	if (msg)
		sprintf_s(buff + strlen(buff), 4096 - strlen(buff), "%s\n\n", msgBuff);

	if ( as == ASSTYPE_ASSERT )
	{
		if (expr)
			sprintf_s(buff + strlen(buff), 4096 - strlen(buff), "Expression:\n   %s\n\n", expr);
	
		if (file)
			sprintf_s(buff + strlen(buff), 4096 - strlen(buff), "File: %s\nLine: %d\n", file, line);
	
		if (func)
			sprintf_s(buff + strlen(buff), 4096 - strlen(buff), "Function: %s\n", func);
	
	}

	if (IsDebuggerPresent())
		strcat_s(buff, "\n(Press OK to debug application)");
	else
		strcat_s(buff, "\n(Press OK to exit application)");
	
	if ( as == ASSTYPE_ASSERT )
		strcat_s(buff, "\n(Press CANCEL to skip error)");

	
	HWND hActive = GetActiveWindow();
	//HWND hActive = PSGLOBAL(window);
	bool bHideMouseAgain = false;
	if (hActive)
	{
		ShowWindow(hActive, SW_HIDE);
		SetCursor(LoadCursor(NULL, IDC_ARROW));
		bHideMouseAgain = ShowCursor(true) <= 0;
		while (ShowCursor(true) < 0);
	}
	
	DWORD flags = MB_ICONERROR;

	if ( as == ASSTYPE_ASSERT )
		flags = flags | MB_OKCANCEL;
	else
		flags = flags | MB_OK;

	int msgbox = MessageBoxA(NULL, buff, boxtitle, flags);
	
	switch (msgbox)
	{
		case IDOK:
			if (IsDebuggerPresent())
				DebuggerBreak();
			else
				raise(SIGABRT);
			break;
		
		case IDCANCEL:
			if (hActive)
			{
				if (bHideMouseAgain)
					while (ShowCursor(false) >= 0);
				ShowWindow(hActive, SW_SHOW);
			}
			break;
	}
}