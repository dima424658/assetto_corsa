#pragma once

class Sim
{
int Sim::getCarsCount();
void Sim::displayLeaderboard(BOOL value);
bool Sim::isDisplayingResults();
bool Sim::isVrRoom();
// void __userpurge Sim::Sim(@<ecx>, unsigned int a2@<ebx>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, Game *igame);
void Sim::~Sim();
void Sim::activateEscMenu();
void Sim::activateGameGui();
void Sim::activatePauseMenu();
// CarAvatar *__userpurge Sim::addCar@<eax>(@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, const std::wstring *model, const std::wstring *config, const std::wstring *skin);
void Sim::addForm(ksgui::Form *aForm, bool isInDevMode);
CarAvatar *Sim::addNetCar(ClientRemoteCarDef *desc, ACClient *client);
void Sim::applyCustomWeather(const std::wstring *name);
StereoCameraForward *Sim::createCamera(INIReaderDocuments *videoIni, float useBlur);
void Sim::executeOnMainThread(std::function<void __cdecl(void)> f);
CarAvatar *Sim::getCar(unsigned int index);
Console *Sim::getConsole();
unsigned int Sim::getFocusedCarIndex();
Texture *Sim::getNationFlag(const std::wstring *nationCode);
CameraForward *Sim::getSceneCamera();
TrackData *Sim::getTrackData(TrackData *result);
void Sim::initCubemaps();
void Sim::initHDRLevels();
void Sim::initSceneGraph();
void Sim::initStaticCubemap();
bool Sim::isInTripleScreenMode();
// void __userpurge Sim::loadTrack(@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, const std::wstring *tname, const std::wstring *config, int playerPitPosition);
unsigned int Sim::nextCar(const unsigned int anIndex);
void Sim::onKeyDown(const OnKeyEvent *message);
void Sim::onPostLoad();
void Sim::onReplayModeChanged(const OnReplayStatusChanged *message);
unsigned int Sim::previousCar(const unsigned int anIndex);
void Sim::render(float deltaT);
void Sim::renderHUD(float deltaT);
// void __userpurge Sim::renderScene(@<ecx>, __int64 a2@<esi:edi>, float deltaT);
void Sim::setFocusedCarIndex(unsigned int aCarIndex);
void Sim::setPauseMode(bool mode);
void Sim::setSplashLoadingCar(const std::wstring *carUnixName);
void Sim::setSplashMessage(const std::wstring *msg);
void Sim::shutdown();
void Sim::startGame();
void Sim::unloadMeshResources(Node *node);
void Sim::update(float deltaT);
void Sim::writeOutputJson();

};