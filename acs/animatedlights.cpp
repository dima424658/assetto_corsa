#include "animatedlights.h"
void __userpurge AnimatedLights::AnimatedLights(AnimatedLights *this@<ecx>, unsigned int a2@<ebx>, CarBrakeLights *lightsManager)
{
  GameObject *v4; // eax
  int v5; // esi
  std::wstring *v6; // eax
  AnimationPlayer *v7; // eax
  AnimationPlayer *v8; // eax
  std::wstring v9; // [esp-1Ch] [ebp-8Ch] BYREF
  Game *v10; // [esp-4h] [ebp-74h]
  AnimationPlayer *v11; // [esp+10h] [ebp-60h]
  AnimatedLightNode nn; // [esp+14h] [ebp-5Ch] BYREF
  AnimatedLights *v13; // [esp+2Ch] [ebp-44h]
  std::wstring result; // [esp+30h] [ebp-40h] BYREF
  std::wstring animation_name; // [esp+48h] [ebp-28h] BYREF
  int v16; // [esp+6Ch] [ebp-4h]

  v13 = this;
  v10 = lightsManager->game;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"ANIMATED_LIGHTS", 0xFu);
  GameObject::GameObject(this, v9, v10);
  this->__vftable = (AnimatedLights_vtbl *)&AnimatedLights::`vftable';
  this->lightsManager = lightsManager;
  v16 = 0;
  this->lights._Myfirst = 0;
  this->lights._Mylast = 0;
  this->lights._Myend = 0;
  LOBYTE(v16) = 1;
  this->frontLightsOn = 0;
  Trigger::Trigger(&this->frontLightsTrigger);
  v10 = 0;
  v9._Myres = (unsigned int)&CarAvatar `RTTI Type Descriptor';
  v9._Mysize = (unsigned int)&GameObject `RTTI Type Descriptor';
  *(_DWORD *)&v9._Bx._Alias[12] = 0;
  LOBYTE(v16) = 2;
  v4 = GameObject::getParent(lightsManager);
  v5 = __RTDynamicCast(v4, *(_DWORD *)&v9._Bx._Alias[12], v9._Mysize, v9._Myres, v10);
  v6 = std::operator+<wchar_t>(&result, L"content/cars/", (const std::wstring *)(v5 + 176));
  LOBYTE(v16) = 3;
  std::operator+<wchar_t>(&animation_name, v6, L"/animations/lights.ksanim");
  LOBYTE(v16) = 5;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( Path::fileExists(a2, &animation_name, 0) )
  {
    std::vector<MaterialVar *>::vector<MaterialVar *>((AnimationBlender *)&nn);
    nn.time = 2.0;
    nn.currentPos = 0.0;
    nn.player = 0;
    LOBYTE(v16) = 6;
    Animation::load(&nn.animation, &animation_name);
    v7 = (AnimationPlayer *)operator new(28);
    v11 = v7;
    LOBYTE(v16) = 7;
    if ( v7 )
      AnimationPlayer::AnimationPlayer(v7, &nn.animation, *(Node **)(v5 + 272), eOnlyAnimated);
    else
      v8 = 0;
    nn.player = v8;
    LOBYTE(v16) = 6;
    std::vector<AnimatedLightNode>::push_back(&this->lights, &nn);
    LOBYTE(v16) = 5;
    std::vector<AnimationSet>::_Tidy(&nn.animation);
  }
  if ( animation_name._Myres >= 8 )
    operator delete(animation_name._Bx._Ptr);
}
void AnimatedLights::~AnimatedLights(AnimatedLights *this)
{
  AnimatedLights *v1; // ebx
  AnimatedLightNode *v2; // edi
  std::vector<AnimatedLightNode> *v3; // ebp
  AnimatedLightNode *v4; // esi
  AnimationPlayer *v5; // ebx
  AnimatedLightNode *v6; // edi
  Animation *i; // esi

  v1 = this;
  this->__vftable = (AnimatedLights_vtbl *)&AnimatedLights::`vftable';
  v2 = this->lights._Mylast;
  v3 = &this->lights;
  v4 = this->lights._Myfirst;
  if ( v4 != v2 )
  {
    do
    {
      v5 = v4->player;
      if ( v5 )
      {
        std::vector<AnimationPlayerSet>::~vector<AnimationPlayerSet>(v4->player);
        operator delete(v5);
      }
      ++v4;
    }
    while ( v4 != v2 );
    v1 = this;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v1->frontLightsTrigger);
  if ( v3->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v3);
    v6 = v3->_Mylast;
    for ( i = &v3->_Myfirst->animation; i != (Animation *)v6; i += 2 )
      std::vector<AnimationSet>::_Tidy(i);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  GameObject::~GameObject(v1);
}
AnimatedLights *AnimatedLights::`scalar deleting destructor'(AnimatedLights *this, unsigned int a2)
{
  AnimatedLights::~AnimatedLights(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void AnimatedLights::update(AnimatedLights *this, float deltaT)
{
  AnimatedLightNode *v3; // edi
  AnimatedLightNode *i; // esi
  AnimationPlayer *v5; // ecx
  float p; // [esp+0h] [ebp-18h]
  float pa; // [esp+0h] [ebp-18h]
  float v8; // [esp+14h] [ebp-4h]
  float v9; // [esp+14h] [ebp-4h]

  this->frontLightsOn = CarBrakeLights::getFrontLightOn(this->lightsManager);
  v3 = this->lights._Mylast;
  for ( i = this->lights._Myfirst; i != v3; ++i )
  {
    v5 = i->player;
    if ( this->frontLightsOn )
    {
      v8 = AnimationPlayer::getCurrentPos(v5);
      if ( v8 >= 1.0 )
      {
        AnimationPlayer::setCurrentPos(i->player, 1.0, 0.0);
      }
      else
      {
        p = AnimationPlayer::getCurrentPos(i->player) + deltaT;
        AnimationPlayer::setCurrentPos(i->player, p, 0.0);
      }
    }
    else
    {
      v9 = AnimationPlayer::getCurrentPos(v5);
      if ( v9 <= 0.0 )
      {
        AnimationPlayer::setCurrentPos(i->player, 0.0, 0.0);
      }
      else
      {
        pa = AnimationPlayer::getCurrentPos(i->player) - deltaT;
        AnimationPlayer::setCurrentPos(i->player, pa, 0.0);
      }
    }
  }
}
