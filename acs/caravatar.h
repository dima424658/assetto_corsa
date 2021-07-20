#pragma once

#include <string>
#include <memory>
#include <vector>
#include <functional>

class CarAvatar
{
public:

	CarAvatar(Sim* isim, const std::wstring* unixName, const std::wstring* config, const std::wstring* skin, ICarPhysicsStateProvider* physicsStateProvider);
	~CarAvatar();

	std::wstring getCurrentSkin();

	void armFirstLap();
	//void __cdecl assignColliderMaterials(std::shared_ptr<Material>* mat, Node* node);
	void checkACD();

	void cycleAbsMode(int value);
	bool cycleERSHeatCharging();
	std::pair<int, std::wstring> cycleERSPower(int value);
	int cycleERSRecovery(int value);
	int cycleEngineBrake(int value);
	void cycleTcMode(int value);
	void forcePosition(const mat44f* matrix);
	std::pair<unsigned int, unsigned int>* getABSMode(std::pair<unsigned int, unsigned int>* result);
	int getAILapsToComplete();
	DriverModel* getActiveDriverModel();
	bool getAutoBlip();
	bool getAutoShifter();
	double getBallastKG();
	CarColliderManager* getColliderManager();
	ICarControlsProvider* getControlsProvider();
	int getCurrentCompoundIdealPressure(uint16_t tyreIndex);
	std::wstring* getCurrentCompoundShortName(std::wstring* result);
	int getCurrentCompoundStaticPressure(uint16_t tyreIndex);
	void getDistancesOnSpline(CarAvatar* car, float* frontDistance, float* backDistance);
	std::pair<int, std::wstring > getERSPower();
	double getEdlOutLevel();
	double getFFMult();
	double getGraphicSteerDeg();
	vec3f* getGraphicsOffset();
	int getGuid();
	double getKmPerLiter();
	double getPackerRange(int index);
	PitStopTime* getPitstopTime(PitStopTime* result, float fuel_requested, bool changeTyres, bool repairBody, bool repairEngine, bool repairSus, bool useRandomizer);
	double getRestrictor();
	vec3f* getRoadDirection();
	std::wstring* getScreenName(std::wstring* result);
	SetupManager* getSetupManager();
	unsigned int getSpawnPositionIndex(std::wstring setName);
	double getStabilityControl();
	std::vector<DebugLine>* getSuspensionDebugLines(std::vector<DebugLine>* result, int index);
	std::pair<unsigned int, unsigned int>* getTCMode(std::pair<unsigned int, unsigned int>* result);
	double getTimeDifferenceOnSpline(CarAvatar* car);
	TimeTransponder* getTimeTransponder();
	std::wstring* getTyreCompound(std::wstring* result, unsigned int index, bool fullname);
	int getTyreCompoundIndex(unsigned int tyre_index);
	double getUserFFGain();
	double getWingAngle(int wingIndex);
	void goToSpawnPosition(const std::wstring* setName);
	long double hasPenalty();
	void init3D(std::wstring skin);
	// void __usercall CarAvatar::initCameraCar(CarAvatar *this@<ecx>, __m128 a2@<xmm0>);
	void initCommon();
	void initCommonPostPhysics();
	// void __usercall CarAvatar::initControls(CarAvatar *this@<ecx>, char a2@<bl>);
	// void __usercall CarAvatar::initDriver(CarAvatar *this@<ecx>, unsigned int a2@<ebx>);
	void initGhostCar(bool isRecording, bool isPlaying);
	void initMirrorMaterials();
	// void __usercall CarAvatar::initPhysics(CarAvatar *this@<ecx>, char a2@<bl>, __m128 a3@<xmm3>, __m128 a4@<xmm4>);
	bool isAbsAvailable();
	bool isAbsEnabled();
	bool isAbsInAction();
	bool isConnected();
	bool isCurrentLapValid();
	bool isEdlEnabled();
	bool isInPit();
	bool isInPitlane();
	bool isInSpawnPosition(const std::wstring* setName);
	bool isMinSpeedPenaltyClearDisabled();

	bool isRequestingPitStop();
	bool isTcAvailable();
	bool isTcEnabled();
	bool isTcInAction();
	bool isVisible();

	void lockControlsUntilTime(long double time, long double start, bool forceToPits);
	// void __userpurge CarAvatar::makeBodyMatrix(CarAvatar *this@<ecx>, int a2@<edi>, int a3@<esi>, const mat44f *bm, mat44f *res);
	void makeTyresDoubleFacedShadows(Node* node);
	double modifyUserFFGain(float offset);
	void onNewSession();
	// void __usercall CarAvatar::onPostLoad(CarAvatar *this@<ecx>, unsigned int a2@<ebx>);
	void onStartReplay(const bool* mode);
	void onStopReplay(const bool* mode);

	void resetFlames();
	void resetMultVolume();
	void resetPenalty(bool isTotalReset);
	void resetTimeTransponder();
	void setAbsEnabled(bool mode, bool force);
	void setAutoBlip(bool mode);
	void setAutoClutchEnabled(bool mode);
	void setAutoShifter(bool mode);
	void setBallastKG(float ballast);
	void setBlackFlag(PenaltyDescription descr);
	void setControlsLock(bool value);
	void setControlsProvider(ICarControlsProvider* controls);
	void setDamageLevel(float lvl);
	void setDriverInfo(const DriverInfo* info);
	void setFFMult(float mult);
	void setGentleStop(bool mode);
	void setGraphicsOffset(vec3f np);
	void setGraphicsPitchRotation(float v);
	void setHeadlights(bool value);
	void setMultVolume(int value, bool active);
	void setNewPhysicsState(CarPhysicsState* ps, float dt);
	void setP2PActivations(int activations);
	void setP2PStartingActivations(int pos);
	void setRestrictor(float v);
	void setSlipStreamEffects(float receive, float generationSpeedFactor);
	void setSpawnPositionIndex(const std::wstring* setName, int index);
	void setStabilityControl(float gain);
	void setTcEnabled(bool mode, bool force);
	void setTurboBoost(float value);
	void setTyreCompound(unsigned int index, const std::wstring* name);
	void setUserFFGain(float gain);
	void setVisible(bool vis);

	void updateERSCharge();
	void updateFromChannels(float dt);
	void updateInPitlaneState(float dt);
	void updateSkidMarks(float dt);


	bool isHeatChargingBatteries;
	int currentERSPowerIndex;
	std::wstring unixName;
	std::wstring currentSkin;
	Sim* sim;
	Car* physics;
	PhysicsInfo physicsInfo;
};