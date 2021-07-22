#pragma once

class TabBar
{
void TabBar::TabBar(std::wstring name, ksgui::GUI *igui);
void TabBar::orderAlphabetically(unsigned int beginIndex, unsigned int endIndex);
void TabBar::~TabBar();
void TabBar::addTab(std::wstring name, unsigned int myIndex);
void TabBar::updateTabBarPosition();
// void __userpurge TabBar::render(@<ecx>, int a2@<edi>, float dt);
void TabBar::onTabClicked(const ksgui::OnControlClicked *message);
void TabBar::updateRollOnIndex(const LastMousePosition *lm);
void TabBar::onMouseMove(const OnMouseMoveEvent *message);
int TabBar::getTabNamesCount();

};