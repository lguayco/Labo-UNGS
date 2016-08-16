#pragma once

#include <windows.h>
#include <winerror.h>
#include "resource.h"

class Window
{
public:
	Window(HINSTANCE hInstance, int nCmdShow );
	virtual ~Window(void);
	static LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM );
public:
	HWND g_hWnd;
	HINSTANCE g_hInst;

};

