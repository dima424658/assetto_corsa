#include "kglwindow.h"

#include <string>
#include <iostream>

#define SHIWORD(x) (*((uint16_t*)&(x)+1))

static HCURSOR cursor;
static std::wstring classname = L"acsW";

void(*kglOnKeyDown)(unsigned int);
void(*kglOnChar)(unsigned int);
void(*kglOnClose)();
void(*kglOnResize)(unsigned int, unsigned int);
void(*kglOnMouseMove)(int, int);
void(*kglOnMouseUp)(int, int, int);
void(*kglOnMouseDown)(int, int, int);
void(*kglOnMouseWheel)(int, int, float);
void(*kglOnKeyUp)(unsigned int);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT rect;

	if (message > WM_MOUSEMOVE)
	{
		switch (message)
		{
		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
		case WM_MBUTTONDOWN:
			GetWindowRect(hWnd, &rect);
			if (kglOnMouseDown)
			{
				switch (message)
				{
				case WM_LBUTTONDOWN:
					kglOnMouseDown(LOWORD(lParam), HIWORD(lParam), 0);
					break;
				case WM_RBUTTONDOWN:
					kglOnMouseDown(LOWORD(lParam), HIWORD(lParam), 2);
					break;
				case WM_MBUTTONDOWN:
					kglOnMouseDown(LOWORD(lParam), HIWORD(lParam), 1);
					break;
				}
			}
			return 0;
		case WM_LBUTTONUP:
		case WM_RBUTTONUP:
		case WM_MBUTTONUP:
			if (kglOnMouseUp)
			{
				switch (message)
				{
				case WM_LBUTTONUP:
					kglOnMouseUp(LOWORD(lParam), HIWORD(lParam), 0);
					break;
				case WM_RBUTTONUP:
					kglOnMouseUp(LOWORD(lParam), HIWORD(lParam), 1);
					break;
				case WM_MBUTTONUP:
					kglOnMouseUp(LOWORD(lParam), HIWORD(lParam), 2);
					break;
				}
			}
			return 0;
		case WM_MOUSEWHEEL:

			rect.left = LOWORD(lParam);
			rect.top = HIWORD(lParam);
			ScreenToClient(hWnd, reinterpret_cast<LPPOINT>(&rect));
			if (kglOnMouseWheel)
				kglOnMouseWheel(rect.left, rect.top, (float)SHIWORD(wParam));
			return 0;
		default:
			return DefWindowProcW(hWnd, message, wParam, lParam);
		}
	}
	if (message == WM_MOUSEFIRST)
	{
		if (!kglOnMouseMove)
			return 0;
		kglOnMouseMove(LOWORD(lParam), HIWORD(lParam));
		return 0;
	}
	if (message <= WM_KEYDOWN)
	{
		if (message != WM_KEYDOWN)
		{
			if (message != WM_SIZE)
			{
				if (message == WM_CLOSE)
				{
					if (kglOnClose)
						kglOnClose();
				}
				else if (message == WM_SETCURSOR)
				{
					if (cursor)
						SetCursor(cursor);
				}

				return DefWindowProcW(hWnd, message, wParam, lParam);
			}

			std::cout << WM_SIZE << LOWORD(lParam) << " " << HIWORD(lParam) << "\n";

			if (kglOnResize)
				kglOnResize(LOWORD(lParam), HIWORD(lParam));
			return 0;
		}

		if (kglOnKeyDown)
			kglOnKeyDown(wParam);

		return 0;
	}
	if (message == WM_KEYUP)
	{
		if (kglOnKeyUp)
			kglOnKeyUp(wParam);

		return 0;
	}
	if (message == WM_CHAR)
	{

		if (kglOnChar)
			kglOnChar(wParam);

		return 0;
	}
	if (message != WM_SYSCOMMAND)
		return DefWindowProcW(hWnd, message, wParam, lParam);

	if (wParam & 0xFFF0 != 61760 && wParam & 0xFFF0 != 61808)
		return DefWindowProcW(hWnd, message, wParam, lParam);

	return 0;
}

HWND kglOpenWindow(const std::wstring& title, unsigned int width, unsigned int height, unsigned int window_mode)
{
	HWND result;
	HINSTANCE hInstance = GetModuleHandle(NULL);

	WNDCLASS WndClass{};
	WndClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = window_mode & 1 ? NULL : reinterpret_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	WndClass.lpszClassName = classname.c_str();

	RegisterClass(&WndClass);

	DWORD style = WS_POPUP | WS_VISIBLE;
	if (!(window_mode & 1))
	{
		if (width >= GetSystemMetrics(SM_CXVIRTUALSCREEN) - 8 || (height >= GetSystemMetrics(SM_CYVIRTUALSCREEN) - 31)) // v8 = WS_TILEDWINDOW | WS_DLGFRAME | WS_GROUP | WS_POPUPWINDOW | WS_TABSTOP | WS_VISIBLE, 
			style = WS_POPUP | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

		if ((window_mode & 2) != 0)
			style = WS_TILEDWINDOW | WS_DLGFRAME | WS_GROUP | WS_POPUPWINDOW | WS_TABSTOP | WS_VISIBLE;
	}

	RECT adjust{ 0, 0, width, height };
	AdjustWindowRect(&adjust, style, 0);

	result = CreateWindowEx(NULL, classname.c_str(), title.c_str(), style, 0, 0, adjust.right - adjust.left, adjust.bottom - adjust.top, NULL, NULL, hInstance, NULL);
	if (!(window_mode & 1) && (window_mode & 4) != 0)
	{
		RECT Rect;
		GetWindowRect(GetDesktopWindow(), &Rect);

		SetWindowPos(result, NULL,
			(Rect.right - adjust.right) / 2,
			(Rect.bottom - adjust.bottom) / 2,
			0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED);
	SetForegroundWindow(result);

	return result;
}

int kglWindowStep()
{
	int result = 1;
	MSG msg;

	while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (msg.message == 18)
		{
			result = 0;
			SetThreadExecutionState(ES_CONTINUOUS);
		}
	}

	return result;
}

void kglWindowSetOnResize(void(*onResize)(unsigned int, unsigned int))
{
	kglOnResize = onResize;
}

void kglWindowSetOnMouseDown(void(*f)(int, int, int))
{
	kglOnMouseDown = f;
}

void kglWindowSetOnMouseUp(void(*f)(int, int, int))
{
	kglOnMouseUp = f;
}

void kglWindowSetOnMouseWheel(void(*f)(int, int, float))
{
	kglOnMouseWheel = f;
}

void kglWindowSetOnMouseMove(void(*f)(int, int))
{
	kglOnMouseMove = f;
}

void kglWindowSetOnChar(void(*f)(unsigned int))
{
	kglOnChar = f;
}

void kglWindowSetOnKeyDown(void(*f)(unsigned int))
{
	kglOnKeyDown = f;
}

void kglWindowSetOnKeyUp(void(*f)(unsigned int))
{
	kglOnKeyUp = f;
}

void kglWindowSetOnClose(void(*f)())
{
	kglOnClose = f;
}

bool kglWindowHasFocus(HWND window)
{
	return GetActiveWindow() == window;
}

void kglWindowSetFocus(HWND window)
{
	if (BringWindowToTop(window) < 0)
		std::cerr << "ERROR: BringWindowToTop failed" << std::endl;
	if (SetForegroundWindow(window) < 0)
		std::cerr << "ERROR: SetForegroundWindow failed" << std::endl;
}
