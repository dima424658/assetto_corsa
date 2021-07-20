#pragma once

#include <string>

#include <Windows.h>

using onResize_t = void(*)(unsigned int, unsigned int);
using onMouseDown_t = void(*)(int, int, int);
using onMouseUp_t = void(*)(int, int, int);
using onMouseWheel_t = void(*)(int, int, float);
using onMouseMove_t = void(*)(int, int);
using onChar_t = void(*)(unsigned int);
using onKeyDown_t = void(*)(unsigned int);
using onKeyUp_t = void(*)(unsigned int);
using onClose_t = void(*)();

HWND kglOpenWindow(const wchar_t* title, unsigned int width, unsigned int height, unsigned int window_mode);
int kglWindowStep();

void kglWindowSetOnResize(onResize_t onResize);
void kglWindowSetOnMouseDown(onMouseDown_t onMouseDown);
void kglWindowSetOnMouseUp(onMouseUp_t onMouseUp);
void kglWindowSetOnMouseWheel(onMouseWheel_t onMouseWheel);
void kglWindowSetOnMouseMove(onMouseMove_t onMouseMove);
void kglWindowSetOnChar(onChar_t onChar);
void kglWindowSetOnKeyDown(onKeyDown_t onKeyDown);
void kglWindowSetOnKeyUp(onKeyUp_t onKeyUp);
void kglWindowSetOnClose(onClose_t onClose);
bool kglWindowHasFocus(HWND window);
void kglWindowSetFocus(HWND window);

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam);