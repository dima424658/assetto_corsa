#include "kglwindow.h"

static onResize_t kglOnResize = nullptr;
static onMouseDown_t kglOnMouseDown = nullptr;
static onMouseUp_t kglOnMouseUp = nullptr;
static onMouseWheel_t kglOnMouseWheel = nullptr;
static onMouseMove_t kglOnMouseMove = nullptr;
static onChar_t kglOnChar = nullptr;
static onKeyDown_t kglOnKeyDown = nullptr;
static onKeyUp_t kglOnKeyUp = nullptr;
static onClose_t kglOnClose = nullptr;

HWND kglOpenWindow(const wchar_t* title, unsigned int width, unsigned int height, unsigned int window_mode)
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASSW WndClass{};
    LPRECT Rect;

    WndClass.hInstance = hInstance;
    WndClass.style = CS_VREDRAW | CS_HREDRAW | CS_CLASSDC;
    WndClass.lpfnWndProc = WndProc;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDI_APPLICATION);
    WndClass.lpszMenuName = NULL;
    WndClass.lpszClassName = L"acsW";

    if (!(window_mode & 1))
        WndClass.hbrBackground = 0;
    else
        WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

    RegisterClass(&WndClass);

    GetWindowRect(GetDesktopWindow(), Rect);

    DWORD dwStyle = WS_POPUPWINDOW | WS_VISIBLE;
    if (!(window_mode & 1))
    {
        if (width >= GetSystemMetrics(SM_CYVIRTUALSCREEN) - 8 || (dwStyle = WS_DLGFRAME | WS_GROUP | WS_POPUPWINDOW | WS_TABSTOP | WS_TILEDWINDOW | WS_VISIBLE, height >= GetSystemMetrics(SM_CYVIRTUALSCREEN) - 31))
            dwStyle = WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_POPUPWINDOW | WS_VISIBLE;
        if ((window_mode & 2) != 0)
            dwStyle = WS_DLGFRAME | WS_GROUP | WS_POPUPWINDOW | WS_TABSTOP | WS_TILEDWINDOW | WS_VISIBLE;
    }

    RECT a{ 0, 0, width, height };

    AdjustWindowRect(&a, dwStyle, 0);

    auto hwnd = CreateWindowEx(NULL, L"acsW", title, dwStyle, 0, 0, a.right - a.left, a.bottom - a.top, NULL, NULL, hInstance, NULL);
    if (!(window_mode & 1) && (window_mode & 4) != 0)
    {
        GetWindowRect(GetDesktopWindow(), Rect);
        SetWindowPos(hwnd, NULL, (float)(Rect->right / 2) - (float)((a.right - a.left) / 2), (float)(Rect->bottom / 2) - (float)((a.bottom - a.top) / 2), NULL, NULL, SWP_NOSIZE | SWP_NOZORDER);
    }

    SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED);
    SetForegroundWindow(hwnd);

    return hwnd;
}

int kglWindowStep()
{
    int result = 1;
    MSG msg;

    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        
        if (msg.message == WM_MOVE | WM_PAINT) // ???
        {
            result = 0;
            SetThreadExecutionState(ES_CONTINUOUS);
        }
    }

    return result;
}

void kglWindowSetOnResize(onResize_t onResize)
{
    kglOnResize = onResize;
}

void kglWindowSetOnMouseDown(onMouseDown_t onMouseDown)
{
    kglOnMouseDown = onMouseDown;
}

void kglWindowSetOnMouseUp(onMouseUp_t onMouseUp)
{
    kglOnMouseUp = onMouseUp;
}

void kglWindowSetOnMouseWheel(onMouseWheel_t onMouseWheel)
{
    kglOnMouseWheel = onMouseWheel;
}

void kglWindowSetOnMouseMove(onMouseMove_t onMouseMove)
{
    kglOnMouseMove = onMouseMove;
}

void kglWindowSetOnChar(onChar_t onChar)
{
    kglOnChar = onChar;
}

void kglWindowSetOnKeyDown(onKeyDown_t onKeyDown)
{
    kglOnKeyDown = onKeyDown;
}

void kglWindowSetOnKeyUp(onKeyUp_t onKeyUp)
{
    kglOnKeyUp = onKeyUp;
}

void kglWindowSetOnClose(onClose_t onClose)
{
    kglOnClose = onClose;
}

bool kglWindowHasFocus(HWND window)
{
    return GetActiveWindow() == window;
}

void kglWindowSetFocus(HWND window)
{
    if (BringWindowToTop(window) < 0)
        printf("ERROR: BringWindowToTop failed\n");

    if (SetForegroundWindow(window) < 0)
        printf("ERROR: SetForegroundWindow failed\n");
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
  void (__cdecl *v5)(unsigned int); // eax
  
  RECT rect; // [esp+18h] [ebp-18h] BYREF

  if ( message > WM_MOUSEFIRST )
  {
    switch ( message )
    {
      case WM_LBUTTONDOWN:
      case WM_RBUTTONDOWN:
      case WM_MBUTTONDOWN:
        GetWindowRect(hWnd, &rect);
        if ( kglOnMouseDown )
        {
          switch ( message )
          {
            case WM_LBUTTONDOWN:
              kglOnMouseDown(LOWORD(lparam), HIWORD(lParam), 0);
              break;
            case WM_RBUTTONDOWN:
              kglOnMouseDown(LOWORD(lparam), HIWORD(lParam), 2);
              break;
            case WM_MBUTTONDOWN:
              kglOnMouseDown(LOWORD(lparam), HIWORD(lParam), 1);
              break;
          }
        }
        return 0;
      case WM_LBUTTONUP:
      case WM_RBUTTONUP:
      case WM_MBUTTONUP:
        if ( kglOnMouseUp )
        {
          switch ( message )
          {
            case WM_LBUTTONUP:
              kglOnMouseUp(LOWORD(lparam), HIWORD(lParam), 0);
              break;
            case WM_RBUTTONUP:
              kglOnMouseUp(LOWORD(lparam), HIWORD(lParam), 1);
              break;
            case WM_MBUTTONUP:
              kglOnMouseUp(LOWORD(lparam), HIWORD(lParam), 2);
              break;
          }
        }
        return 0;
      case WM_MOUSEWHEEL:
        rect.left = LOWORD(lparam);
        rect.top = HIWORD(lParam);
        ScreenToClient(hWnd, (LPPOINT)&rect);
        if ( kglOnMouseWheel )
          kglOnMouseWheel(rect.left, rect.top, (float)SHIWORD(wParam));
        return 0;
      default:
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }
  }
  if ( message == WM_MOUSEMOVE )
  {
    if ( !kglOnMouseMove )
      return 0;
    kglOnMouseMove((unsigned __int16)lParam, HIWORD(lParam));
    return 0;
  }
  if ( message <= WM_KEYDOWN )
  {
    if ( message != WM_KEYDOWN )
    {
      if ( message != 5 )
      {
        if ( message == 16 )
        {
          if ( kglOnClose )
            kglOnClose();
        }
        else if ( message == 32 )
        {
          if ( cursor )
            SetCursor(cursor);
        }
        return DefWindowProcW(hWnd, message, wParam, lParam);
      }
      _printf("WM_SIZE %d %d\n", (unsigned __int16)lParam, HIWORD(lParam));
      if ( kglOnResize )
        kglOnResize((unsigned __int16)lParam, HIWORD(lParam));
      return 0;
    }
    v5 = kglOnKeyDown;
    goto LABEL_24;
  }
  if ( message == WM_KEYUP )
  {
    v5 = kglOnKeyUp;
LABEL_24:
    if ( v5 )
      v5(wParam);
    return 0;
  }
  if ( message == WM_CHAR )
  {
    v5 = kglOnChar;
    goto LABEL_24;
  }
  if ( message != WM_SYSCOMMAND )
    return DefWindowProcW(hWnd, message, wParam, lParam);
  unsigned int v6 = wParam & 0xFFF0;
  if ( v6 != 61760 && v6 != 61808 )
    return DefWindowProcW(hWnd, message, wParam, lParam);
  return 0;
}