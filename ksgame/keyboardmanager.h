#pragma once

class KeyboardManager
{
void KeyboardManager(RenderWindow *arenderWindow);
void ~KeyboardManager();
void onKeyPressEvent(const OnKeyCharEvent *message);
void releaseFocus(IKeyEventListener *l);

};