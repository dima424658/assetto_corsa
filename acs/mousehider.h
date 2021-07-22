#pragma once

class MouseHider
{
void MouseHider(Sim *aSim);
bool isCursorInsideWindow(const tagPOINT *point);
void showCursor(bool value);
void update(float deltaT);

};