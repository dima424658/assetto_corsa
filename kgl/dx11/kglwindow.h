#pragma once

#include <Windows.h>

HWND kglOpenWindow(const std::wstring& title, unsigned int width, unsigned int height, unsigned int window_mode);

int kglWindowStep();
void kglWindowSetOnResize(void (*onResize)(unsigned int, unsigned int));
void kglWindowSetOnMouseDown(void (*f)(int, int, int));
void kglWindowSetOnMouseUp(void (*f)(int, int, int));
void kglWindowSetOnMouseWheel(void (*f)(int, int, float));
void kglWindowSetOnMouseMove(void (*f)(int, int));
void kglWindowSetOnChar(void (*f)(unsigned int));
void kglWindowSetOnKeyDown(void (*f)(unsigned int));
void kglWindowSetOnKeyUp(void (*f)(unsigned int));
void kglWindowSetOnClose(void (*f)());
bool kglWindowHasFocus(HWND window);
void kglWindowSetFocus(HWND window);