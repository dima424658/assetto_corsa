#include "inputdevice.h
void InputDevice::InputDevice(InputDevice *this, _GUID guid, const std::wstring *name, DirectInput *di)
{
  IDirectInputDevice8W **v5; // ebp
  IDirectInputDevice8W *v6; // ecx
  DIPROPRANGE diprg; // [esp+24h] [ebp-38h] BYREF
  __m128i v8; // [esp+3Ch] [ebp-20h] BYREF
  int v9; // [esp+58h] [ebp-4h]

  v8 = _mm_loadu_si128((const __m128i *)guid.Data4);
  InputDeviceState::InputDeviceState(&this->state);
  this->lpFFConstantForce = 0;
  this->lpDirectInputDevice = 0;
  this->lastMagnitude = 0;
  v5 = &this->lpDirectInputDevice;
  this->lastDampGain = 0.0;
  this->isNormalized = 1;
  this->lightCounter = 0;
  this->damperStartCounter = 0;
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  std::wstring::assign(&this->name, (const std::wstring *)guid.Data1, 0, 0xFFFFFFFF);
  v9 = 0;
  if ( (*(int (__stdcall **)(_DWORD, __m128i *, IDirectInputDevice8W **, _DWORD))(**(_DWORD **)(*(_DWORD *)&guid.Data2
                                                                                              + 16)
                                                                                + 12))(
         *(_DWORD *)(*(_DWORD *)&guid.Data2 + 16),
         &v8,
         &this->lpDirectInputDevice,
         0) >= 0 )
    _printf("DI Device created\n");
  else
    _printf("ERROR: CreateDevice failed\n");
  if ( !DirectInput::hWnd )
    _printf("ERROR: creating an Input device with a null hWnd\n");
  (*v5)->SetDataFormat(*v5, &c_dfDIJoystick2);
  if ( (*v5)->SetCooperativeLevel(*v5, DirectInput::hWnd, 9u) < 0 )
    _printf("ERROR: SET COOPERATIVE LEVEL FAILED\n");
  v6 = *v5;
  diprg.diph.dwSize = 24;
  diprg.diph.dwHeaderSize = 16;
  diprg.diph.dwHow = 0;
  diprg.diph.dwObj = 0;
  diprg.lMin = -10000;
  diprg.lMax = 10000;
  v6->SetProperty(v6, (const _GUID *)4, &diprg.diph);
  this->lpFFDamp = 0;
  this->lpFFConstantForce = 0;
  *(_WORD *)&this->isFFStarted = 0;
  InputDevice::initFF(this);
}
void InputDevice::~InputDevice(InputDevice *this)
{
  IDirectInputEffect *v2; // ecx
  IDirectInputEffect *v3; // ecx
  IDirectInputDevice8W *v4; // ecx

  this->lightCounter = 100;
  InputDevice::setG27Leds(this, 0.0, 10.0, 20.0);
  v2 = this->lpFFConstantForce;
  if ( v2 )
  {
    v2->Stop(this->lpFFConstantForce);
    this->lpFFConstantForce->Release(this->lpFFConstantForce);
  }
  v3 = this->lpFFDamp;
  if ( v3 )
  {
    v3->Stop(this->lpFFDamp);
    this->lpFFDamp->Release(this->lpFFDamp);
    this->lpFFDamp = 0;
  }
  v4 = this->lpDirectInputDevice;
  if ( v4 )
    v4->Release(this->lpDirectInputDevice);
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
void InputDevice::setG27Leds(InputDevice *this, float rpm, float minRpm, float maxRpm)
{
  IDirectInputDevice8W *v5; // ecx
  DIEFFESCAPE data_; // [esp+4h] [ebp-30h] BYREF
  LogitechSteeringWheel::WheelData wheelData_; // [esp+1Ch] [ebp-18h] BYREF

  v5 = this->lpDirectInputDevice;
  if ( v5 && this->lightCounter > 50 )
  {
    wheelData_.size = 20;
    wheelData_.rpmData.currentRPM = rpm;
    wheelData_.rpmData.rpmFirstLedTurnsOn = minRpm;
    wheelData_.rpmData.rpmRedLine = maxRpm;
    wheelData_.versionNbr = 1;
    *(_QWORD *)&data_.lpvOutBuffer = 0i64;
    data_.dwSize = 24;
    data_.dwCommand = 0;
    data_.lpvInBuffer = &wheelData_;
    data_.cbInBuffer = 20;
    v5->Escape(v5, &data_);
    this->lightCounter = 0;
  }
  else
  {
    ++this->lightCounter;
  }
}
bool InputDevice::poll(InputDevice *this)
{
  HRESULT v2; // eax
  float v3; // xmm0_4
  float v4; // xmm0_4
  bool result; // al
  DIJOYSTATE2 js; // [esp+10h] [ebp-11Ch] BYREF

  v2 = this->lpDirectInputDevice->Poll(this->lpDirectInputDevice);
  if ( v2 == -2147024884 || v2 == -2147024866 )
  {
    if ( !this->lpDirectInputDevice->Acquire(this->lpDirectInputDevice) && this->lpFFConstantForce )
    {
      *(_WORD *)&this->isFFStarted = 0;
      _printf("ACQUIRED OK, REQUEST FF RESTART\n");
    }
    _printf("DInput input lost:\n");
    result = 0;
  }
  else
  {
    memset(&js, 0, sizeof(js));
    this->lpDirectInputDevice->GetDeviceState(this->lpDirectInputDevice, 272u, &js);
    v3 = (float)js.lX;
    if ( this->isNormalized )
    {
      this->state.x = v3 * 0.000099999997;
      this->state.y = (float)js.lY * 0.000099999997;
      this->state.z = (float)js.lZ * 0.000099999997;
      this->state.rx = (float)js.lRx * 0.000099999997;
      this->state.ry = (float)js.lRy * 0.000099999997;
      this->state.rz = (float)js.lRz * 0.000099999997;
      this->state.slider0 = (float)js.rglSlider[0] * 0.000099999997;
      v4 = (float)js.rglSlider[1] * 0.000099999997;
    }
    else
    {
      this->state.x = v3;
      this->state.y = (float)js.lY;
      this->state.z = (float)js.lZ;
      this->state.rx = (float)js.lRx;
      this->state.ry = (float)js.lRy;
      this->state.rz = (float)js.lRz;
      this->state.slider0 = (float)js.rglSlider[0];
      v4 = (float)js.rglSlider[1];
    }
    this->state.slider1 = v4;
    result = 1;
    *(__m128i *)this->state.pow = _mm_loadu_si128((const __m128i *)js.rgdwPOV);
    qmemcpy(this->state.buttons, js.rgbButtons, sizeof(this->state.buttons));
  }
  return result;
}
void InputDevice::sendFF(InputDevice *this, float v, float damper)
{
  int v4; // eax
  IDirectInputEffect *v5; // edx
  int v6; // ecx
  IDirectInputEffect *v7; // ecx
  int v8; // [esp+Ch] [ebp-74h] BYREF
  int v9[2]; // [esp+10h] [ebp-70h] BYREF
  _QWORD v10[7]; // [esp+18h] [ebp-68h] BYREF
  _DWORD v11[2]; // [esp+50h] [ebp-30h] BYREF
  int v12; // [esp+58h] [ebp-28h]
  int v13; // [esp+5Ch] [ebp-24h]
  int v14; // [esp+60h] [ebp-20h]
  int v15; // [esp+64h] [ebp-1Ch]

  v9[0] = 1;
  v9[1] = 1;
  v4 = (int)(float)(v * 10000.0);
  if ( v4 <= 10000 )
  {
    if ( v4 < -10000 )
      v4 = -10000;
    v8 = v4;
  }
  else
  {
    v8 = 10000;
  }
  memset(v10, 0, sizeof(v10));
  v5 = this->lpFFConstantForce;
  HIDWORD(v10[4]) = v9;
  v10[0] = 0x1200000038i64;
  HIDWORD(v10[3]) = 1;
  v10[5] = 0x400000000i64;
  v10[6] = (unsigned int)&v8;
  if ( v5 )
  {
    v6 = 256;
    if ( !this->isFFStarted )
      v6 = 536871232;
    v5->SetParameters(v5, (const DIEFFECT *)v10, v6);
    if ( !this->isFFStarted )
      this->isFFStarted = 1;
  }
  this->lastMagnitude = v8;
  v14 = 10000;
  v13 = 10000;
  v15 = 0;
  v11[0] = 0;
  v12 = (int)(float)(damper * 10000.0);
  v11[1] = v12;
  memset(v10, 0, sizeof(v10));
  v7 = this->lpFFDamp;
  HIDWORD(v10[4]) = v9;
  v10[0] = 0x1200000038i64;
  HIDWORD(v10[3]) = 1;
  v10[5] = 0x1800000000i64;
  v10[6] = (unsigned int)v11;
  LODWORD(v10[2]) = 10000;
  if ( !v7 )
    goto LABEL_14;
  if ( !this->isDamperStarted )
  {
    v7->SetParameters(v7, (const DIEFFECT *)v10, 536871236u);
    this->isDamperStarted = 1;
LABEL_14:
    this->lastDampGain = damper;
    return;
  }
  if ( this->lastDampGain != damper )
  {
    v7->SetParameters(v7, (const DIEFFECT *)v10, 256u);
    goto LABEL_14;
  }
  this->lastDampGain = damper;
}
void InputDevice::initFF(InputDevice *this)
{
  IDirectInputDevice8W *v2; // eax
  IDirectInputDevice8W *v3; // ecx
  IDirectInputDevice8W *v4; // ecx
  IDirectInputEffect **v5; // edi
  unsigned int dwAxes[1]; // [esp+20h] [ebp-78h] BYREF
  DIEFFECT e; // [esp+24h] [ebp-74h] BYREF
  int lDirection[2]; // [esp+5Ch] [ebp-3Ch] BYREF
  int v9; // [esp+64h] [ebp-34h] BYREF
  DIPROPDWORD DIPropAutoCenter; // [esp+68h] [ebp-30h] BYREF
  DICONDITION dic; // [esp+7Ch] [ebp-1Ch] BYREF

  DIPropAutoCenter.diph.dwSize = 20;
  DIPropAutoCenter.diph.dwHeaderSize = 16;
  DIPropAutoCenter.diph.dwObj = 0;
  v2 = this->lpDirectInputDevice;
  DIPropAutoCenter.diph.dwHow = 0;
  DIPropAutoCenter.dwData = 0;
  if ( v2->SetProperty(v2, (const _GUID *)9, &DIPropAutoCenter.diph) )
  {
    _printf("ERROR: InputDevice::initFF(), lpDirectInputDevice->SetProperty failed\n");
    this->lpFFConstantForce = 0;
  }
  dwAxes[0] = 0;
  lDirection[0] = 0;
  lDirection[1] = 0;
  v9 = 0;
  memset(&e, 0, sizeof(e));
  v3 = this->lpDirectInputDevice;
  e.rgdwAxes = dwAxes;
  e.dwSize = 56;
  e.rglDirection = lDirection;
  e.dwFlags = 18;
  e.dwDuration = -1;
  e.dwSamplePeriod = 0;
  e.dwGain = 10000;
  e.dwTriggerButton = -1;
  e.dwTriggerRepeatInterval = -1;
  e.cAxes = 1;
  e.lpEnvelope = 0;
  e.cbTypeSpecificParams = 4;
  e.lpvTypeSpecificParams = &v9;
  e.dwStartDelay = 0;
  if ( v3->CreateEffect(v3, &GUID_ConstantForce, &e, &this->lpFFConstantForce, 0) )
  {
    this->lpFFConstantForce = 0;
    _printf("ERROR: InputDevice::initFF(), lpDirectInputDevice->CreateEffect failed GUID_ConstantForce\n");
  }
  else
  {
    _printf("lpDirectInputDevice->CreateEffect successful GUID_ConstantForce\n");
  }
  dic.dwNegativeSaturation = 10000;
  dic.dwPositiveSaturation = 10000;
  dic.lDeadBand = 0;
  dic.lNegativeCoefficient = 10000;
  dic.lOffset = 0;
  dic.lPositiveCoefficient = 10000;
  memset(&e, 0, sizeof(e));
  v4 = this->lpDirectInputDevice;
  e.rgdwAxes = dwAxes;
  e.dwSize = 56;
  e.rglDirection = lDirection;
  v5 = &this->lpFFDamp;
  e.dwFlags = 18;
  e.dwDuration = -1;
  e.dwSamplePeriod = 0;
  e.dwGain = 10000;
  e.dwTriggerButton = -1;
  e.dwTriggerRepeatInterval = -1;
  e.cAxes = 1;
  e.lpEnvelope = 0;
  e.dwStartDelay = 0;
  e.lpvTypeSpecificParams = &dic;
  e.cbTypeSpecificParams = 24;
  if ( v4->CreateEffect(v4, &GUID_Damper, &e, v5, 0) )
  {
    _printf("ERROR: DAMPER CREATION FAILED\n");
    *v5 = 0;
  }
  else
  {
    _printf("lpDirectInputDevice->CreateEffect successful GUID_Damper\n");
  }
}
std::wstring *InputDevice::getName(InputDevice *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &this->name, 0, 0xFFFFFFFF);
  return result;
}
