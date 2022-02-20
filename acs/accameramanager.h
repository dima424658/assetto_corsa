#pragma once

class ACCameraManager
{
public:
    void ACCameraManager::ACCameraManager(Sim *isim, CameraForward *icamera);
    void ACCameraManager::~ACCameraManager();

    void ACCameraManager::fadeIn(FadeModeDef aFadeMode);
    bool ACCameraManager::isCameraOnBoard(CarAvatar *car);
    bool ACCameraManager::isVirtualMirrorOn();
    void ACCameraManager::loadPreviousSessionUserCamera();
    void ACCameraManager::registerToFadeInEvent(std::function<void __cdecl(bool const &)> f, void *sender);
    void ACCameraManager::setAudioDistanceScale();
    void ACCameraManager::setCameraCarIndex(int index);
    void ACCameraManager::setDrivableCarIndex(int index);
    void ACCameraManager::setKeyboardInputEnabled(bool value);
    void ACCameraManager::setMode(CameraMode imode, bool force, bool pIsRandom);
    void ACCameraManager::stepCameraRandom(int lastCarIndex);
    void ACCameraManager::update(float deltaT);

private:
    Event<int> evOnCameraSelectedIndex;
    Event<bool> evOnCameraUpdateDone;
    CameraOnBoard *cameraOnBoard;
    CameraMouseControl *mouseControl;
    CinematicFreeCamera *cinematicMouseControl;
    CameraTrack *cameraTrack;
    CameraHelicopter *cameraHelicopter;
    CameraOnBoardFree *cameraOnBoardFree;
    CameraCarManager *cameraCar;
    CameraDrivableManager *cameraDrivable;
    CameraModeStart *cameraStart;
    ImageGeneratorCamera *imageGeneratorCamera;
    bool isKeyboardCameraControlEnabled;
    int currentGlobalCameraIndex;
    float randomCameraTime;
    float randomOldCameraTime;
    float randomCameraMinTime;
    float randomCameraMaxTime;
    std::vector<int> randomCameraProbabilities;
    bool randomMode;
    CameraMode lastRandomCamera;
    Sim *sim;
    CameraForward *camera;
    CameraMode mode;
    CameraMode lastDrivingMode;
    FadeModeDef fadeMode;
    Texture fadeTexture;
    vec3f fadeColor;
    Event<bool> evOnFadeInFinished;
    PersistanceCameraModeDef persistanceCameraMode;
};