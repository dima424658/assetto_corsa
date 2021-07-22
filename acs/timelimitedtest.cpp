#include "timelimitedtest.h
void __userpurge TimeLimitedTest::TimeLimitedTest(TimeLimitedTest *this@<ecx>, unsigned int a2@<ebx>, Sim *isim)
{
  bool v4; // zf
  int v5; // eax
  bool v6; // cf
  char v7; // bl
  int v8; // eax
  Font *v9; // eax
  Font *v10; // eax
  std::wstring v11; // [esp-10h] [ebp-B8h] BYREF
  Game *v12; // [esp+8h] [ebp-A0h]
  Font *v13; // [esp+1Ch] [ebp-8Ch]
  TimeLimitedTest *v14; // [esp+20h] [ebp-88h]
  std::wstring section; // [esp+24h] [ebp-84h] BYREF
  std::wstring key; // [esp+3Ch] [ebp-6Ch] BYREF
  INIReaderDocuments r; // [esp+54h] [ebp-54h] BYREF
  int v18; // [esp+A4h] [ebp-4h]

  v14 = this;
  v12 = isim->game;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, L"TIME LIMITED TEST", 0x11u);
  GameObject::GameObject(this, v11, v12);
  v12 = 0;
  this->__vftable = (TimeLimitedTest_vtbl *)&TimeLimitedTest::`vftable';
  this->writeJsonOnSessionEnd = 0;
  this->sim = isim;
  this->font = 0;
  this->srcBeep = 0;
  this->lastRemainingTime = -1;
  v11._Myres = 7;
  v11._Mysize = 0;
  v18 = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, L"cfg/time_limited_test.ini", 0x19u);
  INIReaderDocuments::INIReaderDocuments(&r, a2, v11, (bool)v12);
  v4 = !r.ready;
  LOBYTE(v18) = 1;
  this->writeJsonOnSessionEnd = 0;
  if ( v4 )
  {
    this->isActive = 0;
  }
  else
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_RUNNING_TIME", 0x10u);
    LOBYTE(v18) = 2;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v18) = 3;
    v5 = INIReader::getInt(&r, &section, &key);
    v6 = section._Myres < 8;
    this->maxRunningTime = v5;
    if ( !v6 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v18) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"JSON_ON_SESSION_END", 0x13u);
    LOBYTE(v18) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v18) = 5;
    v7 = INIReader::hasKey(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v18) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v7 )
    {
      std::wstring::wstring(&section, L"JSON_ON_SESSION_END");
      LOBYTE(v18) = 6;
      std::wstring::wstring(&key, L"SETTINGS");
      LOBYTE(v18) = 7;
      v8 = INIReader::getInt(&r, &key, &section);
      v6 = key._Myres < 8;
      this->writeJsonOnSessionEnd = v8 > 0;
      if ( !v6 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v18) = 1;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    v4 = this->maxRunningTime == 0;
    v12 = (Game *)24;
    this->isActive = !v4;
    v9 = (Font *)operator new(v12);
    v13 = v9;
    LOBYTE(v18) = 8;
    if ( v9 )
    {
      Font::Font(v9, eFontProportional, 28.0, 0, 0);
      this->font = v10;
    }
    else
    {
      this->font = 0;
    }
  }
  LOBYTE(v18) = 0;
  INIReaderDocuments::~INIReaderDocuments(&r);
}
TimeLimitedTest *TimeLimitedTest::`scalar deleting destructor'(TimeLimitedTest *this, unsigned int a2)
{
  Font *v3; // edi

  this->__vftable = (TimeLimitedTest_vtbl *)&TimeLimitedTest::`vftable';
  v3 = this->font;
  if ( v3 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v3);
    operator delete(v3);
  }
  if ( this->srcBeep )
    operator delete(this->srcBeep);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
int TimeLimitedTest::getMaxRunningTime(TimeLimitedTest *this)
{
  return this->maxRunningTime;
}
void TimeLimitedTest::renderHUD(TimeLimitedTest *this, float deltaT)
{
  Font *v3; // edx
  GraphicsManager *v4; // esi
  std::wstring s; // [esp+20h] [ebp-28h] BYREF
  int v6; // [esp+44h] [ebp-4h]

  v3 = this->font;
  if ( v3 && this->game->gameTime.now - this->game->gameTime.startTime > (double)(60000 * this->maxRunningTime) )
  {
    Font::setColor(v3, 1.0, 0.0, 0.0, 1.0);
    this->font->shadowed = 1;
    std::wstring::wstring(&s, L"SESSION COMPLETE");
    v4 = this->game->graphics;
    v6 = 0;
    Font::blitString(
      this->font,
      (float)(v4->videoSettings.width / 2),
      (float)(v4->videoSettings.height / 3),
      &s,
      3.0,
      eAlignCenter);
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
  }
}
void TimeLimitedTest::shutdown(TimeLimitedTest *this)
{
  if ( this->srcBeep )
  {
    operator delete(this->srcBeep);
    this->srcBeep = 0;
  }
}
void TimeLimitedTest::update(TimeLimitedTest *this, float dt)
{
  int v3; // edi
  CarAvatar *v4; // eax

  v3 = 60000 * this->maxRunningTime - (int)(this->game->gameTime.now - this->game->gameTime.startTime);
  if ( v3 <= 0 )
  {
    if ( this->writeJsonOnSessionEnd )
    {
      Sim::writeOutputJson(this->sim);
      this->writeJsonOnSessionEnd = 0;
    }
    v4 = Sim::getCar(this->sim, 0);
    CarAvatar::setGentleStop(v4, 1);
  }
  this->lastRemainingTime = v3;
}
