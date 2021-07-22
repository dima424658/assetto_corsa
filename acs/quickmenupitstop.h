#pragma once

class QuickMenuPitstop
{
void QuickMenuPitstop::QuickMenuPitstop(Sim *isim);
void QuickMenuPitstop::~QuickMenuPitstop();
QuickMenuPitstop *QuickMenuPitstop::`vector deleting destructor'(unsigned int a2);
void QuickMenuPitstop::addHeader(ksgui::Label *lbl, const std::wstring *title);
void QuickMenuPitstop::buildControls(INIReader *carsetup);
void QuickMenuPitstop::buildItem(INIReader *ini, QuickMenuPitstopItem *item, const std::wstring *sect, bool readIni);
void QuickMenuPitstop::getItemValues(EQuickMenuPitstopType type, int componentIndex, QuickMenuPitstopItem *item);
double QuickMenuPitstop::getMaxFuel();
double QuickMenuPitstop::getValue(const QuickMenuPitstopItem *item);
double QuickMenuPitstop::getWingPitstopTime(int componentIndex);
void QuickMenuPitstop::itemCompound(const int direction, const int itemIndex);
void QuickMenuPitstop::itemFuel(const int direction, const int itemIndex);
void QuickMenuPitstop::itemPressure(const int direction, const int itemIndex);
void QuickMenuPitstop::itemWing(const int direction, const int itemIndex);
void QuickMenuPitstop::loadFixedSetup(const std::wstring *path);
void QuickMenuPitstop::renderHUD(float dt);
void QuickMenuPitstop::resetControls(const int itemIndex, float value);
void QuickMenuPitstop::sendInput(unsigned int key);
void QuickMenuPitstop::setLabels(const int itemIndex);
void QuickMenuPitstop::updateUI();

};