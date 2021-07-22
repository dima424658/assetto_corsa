#pragma once

class DefaultSystemMessage
{
void DefaultSystemMessage(ksgui::GUI *gui);
// void __userpurge render(@<ecx>, int a2@<esi>, float dt);
void setMessage(std::wstring title, std::wstring description);

};