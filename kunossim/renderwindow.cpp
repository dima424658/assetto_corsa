#include "renderwindow.h"

RenderWindow::RenderWindow(std::wstring name, VideoSettings& videoSettings)
{
    unsigned int window_mode = 0;
    disableEventsWithMouseHidden = 1;

    //rw = this;

    if (videoSettings.isFullscreen)
        window_mode = 1;

    videoSettings.hwnd = hWnd = kglOpenWindow(name, videoSettings.width, videoSettings.height, window_mode | 4);

    kglWindowSetOnResize(onResize);
    kglWindowSetOnMouseDown(onMouseDown);
    kglWindowSetOnMouseUp(onMouseUp);
    kglWindowSetOnMouseWheel(onMouseWheel);
    kglWindowSetOnKeyDown(onKeyDown);
    kglWindowSetOnChar(onChar);
    kglWindowSetOnMouseMove(onMouseMove);
    kglWindowSetOnClose(onClose);
    kglWindowSetOnKeyUp(onKeyUp);
}

void onChar(unsigned int c)
{
    RenderWindow* v1; // ebx
    std::pair<void*, std::function<void __cdecl(OnKeyCharEvent const&)> >* v2; // esi
    std::_Func_base<void, OnKeyCharEvent const&>** v3; // edi

    v1 = rw;
    v2 = rw->evOnKeyChar.handlers._Myfirst;
    if (v2 != rw->evOnKeyChar.handlers._Mylast)
    {
        v3 = &v2->second._Impl;
        do
        {
            if (!*v3)
            {
                std::_Xbad_function_call();
                JUMPOUT(0x6E4A45);
            }
            (*v3)->_Do_call(*v3, (const OnKeyCharEvent*)&c);
            ++v2;
            v3 += 8;
        } while (v2 != v1->evOnKeyChar.handlers._Mylast);
    }
}

void onClose()
{
    RenderWindow* v0; // ebx
    std::pair<void*, std::function<void __cdecl(OnWindowClosedEvent const&)> >* v1; // esi
    std::_Func_base<void, OnWindowClosedEvent const&>** v2; // edi
    RenderWindow* v3; // [esp+8h] [ebp-4h] BYREF

    v0 = rw;
    v3 = rw;
    v1 = rw->evOnWindowClosed.handlers._Myfirst;
    if (v1 != rw->evOnWindowClosed.handlers._Mylast)
    {
        v2 = &v1->second._Impl;
        do
        {
            if (!*v2)
            {
                std::_Xbad_function_call();
                JUMPOUT(0x6E4A96);
            }
            (*v2)->_Do_call(*v2, (const OnWindowClosedEvent*)&v3);
            ++v1;
            v2 += 8;
        } while (v1 != v0->evOnWindowClosed.handlers._Mylast);
    }
}

void onKeyDown(unsigned int c)
{
    RenderWindow* v1; // ebx
    std::pair<void*, std::function<void __cdecl(OnKeyEvent const&)> >* v2; // esi
    std::_Func_base<void, OnKeyEvent const&>** v3; // edi

    v1 = rw;
    v2 = rw->evOnKeyDown.handlers._Myfirst;
    if (v2 != rw->evOnKeyDown.handlers._Mylast)
    {
        v3 = &v2->second._Impl;
        do
        {
            if (!*v3)
            {
                std::_Xbad_function_call();
                JUMPOUT(0x6E4AE5);
            }
            (*v3)->_Do_call(*v3, (const OnKeyEvent*)&c);
            ++v2;
            v3 += 8;
        } while (v2 != v1->evOnKeyDown.handlers._Mylast);
    }
}

void onKeyUp(unsigned int c)
{
    RenderWindow* v1; // ebx
    std::pair<void*, std::function<void __cdecl(OnKeyEvent const&)> >* v2; // esi
    std::_Func_base<void, OnKeyEvent const&>** v3; // edi

    v1 = rw;
    v2 = rw->evOnKeyUp.handlers._Myfirst;
    if (v2 != rw->evOnKeyUp.handlers._Mylast)
    {
        v3 = &v2->second._Impl;
        do
        {
            if (!*v3)
            {
                std::_Xbad_function_call();
                JUMPOUT(0x6E4B35);
            }
            (*v3)->_Do_call(*v3, (const OnKeyEvent*)&c);
            ++v2;
            v3 += 8;
        } while (v2 != v1->evOnKeyUp.handlers._Mylast);
    }
}

void onMouseDown(int x, int y, int button)
{
    RenderWindow* v3; // ebx
    std::pair<void*, std::function<void __cdecl(OnMouseDownEvent const&)> >* v4; // esi
    std::_Func_base<void, OnMouseDownEvent const&>** v5; // edi
    int v6[3]; // [esp+4h] [ebp-20h] BYREF
    tagCURSORINFO pci; // [esp+10h] [ebp-14h] BYREF

    v3 = rw;
    pci.cbSize = 20;
    if (rw->disableEventsWithMouseHidden)
    {
        if (!GetCursorInfo(&pci) || pci.flags != 1)
            return;
        v3 = rw;
    }
    v6[0] = x;
    v6[1] = y;
    v6[2] = button;
    v4 = v3->evOnMouseDown.handlers._Myfirst;
    if (v4 != v3->evOnMouseDown.handlers._Mylast)
    {
        v5 = &v4->second._Impl;
        do
        {
            if (!*v5)
            {
                std::_Xbad_function_call();
                JUMPOUT(0x6E4BC8);
            }
            (*v5)->_Do_call(*v5, (const OnMouseDownEvent*)v6);
            ++v4;
            v5 += 8;
        } while (v4 != v3->evOnMouseDown.handlers._Mylast);
    }
}

void onMouseMove(int x, int y)
{
    RenderWindow* v2; // ebx
    std::pair<void*, std::function<void __cdecl(OnMouseMoveEvent const&)> >* v3; // esi
    std::_Func_base<void, OnMouseMoveEvent const&>** v4; // edi
    int v5[3]; // [esp+8h] [ebp-Ch] BYREF

    v2 = rw;
    v5[0] = x;
    v5[2] = -1;
    v5[1] = y;
    v3 = rw->evOnMouseMove.handlers._Myfirst;
    if (v3 != rw->evOnMouseMove.handlers._Mylast)
    {
        v4 = &v3->second._Impl;
        do
        {
            if (!*v4)
            {
                std::_Xbad_function_call();
                JUMPOUT(0x6E4C28);
            }
            (*v4)->_Do_call(*v4, (const OnMouseMoveEvent*)v5);
            ++v3;
            v4 += 8;
        } while (v3 != v2->evOnMouseMove.handlers._Mylast);
    }
}

void onMouseUp(int x, int y, int button)
{
    RenderWindow* v3; // ebx
    std::pair<void*, std::function<void __cdecl(OnMouseUpEvent const&)> >* v4; // esi
    std::_Func_base<void, OnMouseUpEvent const&>** v5; // edi
    int v6[3]; // [esp+8h] [ebp-Ch] BYREF

    v6[0] = x;
    v3 = rw;
    v6[1] = y;
    v6[2] = button;
    v4 = rw->evOnMouseUp.handlers._Myfirst;
    if (v4 != rw->evOnMouseUp.handlers._Mylast)
    {
        v5 = &v4->second._Impl;
        do
        {
            if (!*v5)
            {
                std::_Xbad_function_call();
                JUMPOUT(0x6E4C88);
            }
            (*v5)->_Do_call(*v5, (const OnMouseUpEvent*)v6);
            ++v4;
            v5 += 8;
        } while (v4 != v3->evOnMouseUp.handlers._Mylast);
    }
}

void onMouseWheel(int x, int y, float v)
{
    RenderWindow* v3; // ebx
    std::pair<void*, std::function<void __cdecl(OnMouseWheelMovedEvent const&)> >* v4; // esi
    std::_Func_base<void, OnMouseWheelMovedEvent const&>** v5; // edi
    int v6[4]; // [esp+0h] [ebp-10h] BYREF

    v3 = rw;
    v6[0] = x;
    v6[2] = -1;
    v6[1] = y;
    *(float*)&v6[3] = v;
    v4 = rw->evOnMouseWheelMoved.handlers._Myfirst;
    if (v4 != rw->evOnMouseWheelMoved.handlers._Mylast)
    {
        v5 = &v4->second._Impl;
        do
        {
            if (!*v5)
            {
                std::_Xbad_function_call();
                JUMPOUT(0x6E4CF8);
            }
            (*v5)->_Do_call(*v5, (const OnMouseWheelMovedEvent*)v6);
            ++v4;
            v5 += 8;
        } while (v4 != v3->evOnMouseWheelMoved.handlers._Mylast);
    }
}

void onResize(unsigned int width, unsigned int height)
{
    RenderWindow* v2; // ebx
    std::pair<void*, std::function<void __cdecl(OnWindowResizeEvent const&)> >* v3; // esi
    std::_Func_base<void, OnWindowResizeEvent const&>** v4; // edi
    int v5[3]; // [esp+8h] [ebp-Ch] BYREF

    v2 = rw;
    v5[0] = width;
    v5[1] = height;
    v5[2] = (int)rw;
    v3 = rw->evOnWindowResize.handlers._Myfirst;
    if (v3 != rw->evOnWindowResize.handlers._Mylast)
    {
        v4 = &v3->second._Impl;
        do
        {
            if (!*v4)
            {
                std::_Xbad_function_call();
                JUMPOUT(0x6E4D58);
            }
            (*v4)->_Do_call(*v4, (const OnWindowResizeEvent*)v5);
            ++v3;
            v4 += 8;
        } while (v3 != v2->evOnWindowResize.handlers._Mylast);
    }
}