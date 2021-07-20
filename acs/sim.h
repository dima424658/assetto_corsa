#pragma once

#include <string>
#include <functional>

#include "physicsavatar.h"
#include "systemmessage.h"

class Sim
{
public:
	int getCarsCount();
	void displayLeaderboard(bool value);
	bool isDisplayingResults();
	bool isVrRoom();
	// void __userpurge Sim::Sim(Sim *this@<ecx>, unsigned int a2@<ebx>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, Game *igame);
	
	~Sim();
	void activateEscMenu();
	void activateGameGui();
	void activatePauseMenu();
	// CarAvatar *__userpurge Sim::addCar@<eax>(Sim *this@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, const std::wstring *model, const std::wstring *config, const std::wstring *skin);
	void addForm(ksgui::Form* aForm, bool isInDevMode);
	CarAvatar* addNetCar(ClientRemoteCarDef* desc, ACClient* client);
	void applyCustomWeather(const std::wstring* name);
	StereoCameraForward* createCamera(INIReaderDocuments* videoIni, float useBlur);

	void executeOnMainThread(std::function<void()> f);
	CarAvatar* getCar(unsigned int index);
	Console* getConsole();
	unsigned int getFocusedCarIndex();
	Texture* getNationFlag(const std::wstring* nationCode);
	CameraForward* getSceneCamera();
	TrackData* getTrackData(TrackData* result);
	void initCubemaps();
	void initHDRLevels();
	void initSceneGraph();
	void initStaticCubemap();
	bool isInTripleScreenMode();
	
	// void __userpurge Sim::loadTrack(Sim *this@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, const std::wstring *tname, const std::wstring *config, int playerPitPosition);
	unsigned int nextCar(const unsigned int anIndex);
	void onKeyDown(const OnKeyEvent* message);
	void onPostLoad();
	void onReplayModeChanged(const OnReplayStatusChanged* message);
	unsigned int previousCar(const unsigned int anIndex);
	void render(float deltaT);
	void renderHUD(float deltaT);
	// void __userpurge Sim::renderScene(Sim *this@<ecx>, __int64 a2@<esi:edi>, float deltaT);
	void setFocusedCarIndex(unsigned int aCarIndex);
	void setPauseMode(bool mode);
	
	void setSplashLoadingCar(const std::wstring* carUnixName);
	void setSplashMessage(const std::wstring* msg);
	
	void shutdown();
	void startGame();

	void stepPhysicsEvent(int a1, float colliderCategory);
	void unloadMeshResources(Node* node);
	void update(float deltaT);
	void writeOutputJson();

	std::wstring acVersionString;
	bool benchmarkMode = false;
	bool forceOnline = false;

	PhysicsAvatar* physicsAvatar;
	SystemMessage* systemMessage;
};