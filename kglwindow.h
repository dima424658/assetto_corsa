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
