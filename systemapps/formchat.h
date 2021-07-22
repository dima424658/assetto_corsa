#pragma once

class FormChat
{
void FormChat::FormChat(Sim *a_sim);
FormChat *FormChat::`vector deleting destructor'(unsigned int a2);
void FormChat::~FormChat();
void FormChat::render(float dt);
void FormChat::addMessage(const FormChat::ChatMessage data, int *lines);
void FormChat::onChatMessage(const OnChatMessageEvent *message);
void FormChat::onMouseMove(const OnMouseMoveEvent *message);

};