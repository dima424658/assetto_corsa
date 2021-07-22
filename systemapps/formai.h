#pragma once

class FormAI
{
void FormAI(Sim *isim);
void render(float dt);
void onBeginPitlaneClicked(const ksgui::OnControlClicked *message);
void renderSplines();

};