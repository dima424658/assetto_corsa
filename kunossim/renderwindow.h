#pragma once

#include <string>

#include <Windows.h>

#include "kgl/dx11/kglwindow.h"

struct VideoSettings
{
	bool isFullscreen;
	HWND hwnd;
	unsigned int width, height;
};

class RenderWindow
{
public:
	RenderWindow(std::wstring name, VideoSettings& videoSettings);
	~RenderWindow();

	bool hasFocus();
	void setFocus();
	bool step();

    int disableEventsWithMouseHidden;
    HWND hwnd;

    /*
    containers

    evOnMouseDown
    evOnMouseWheelMoved
    evOnMouseUp
    evOnMouseMove
    evOnWindowResize
    evOnKeyChar
    evOnKeyDown
    evOnWindowClosed
    evOnKeyUp
    */
};
