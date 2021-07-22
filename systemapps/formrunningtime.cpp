#include "formrunningtime.h
void __userpurge FormRunningTime::FormRunningTime(FormRunningTime *this@<ecx>, unsigned int a2@<ebx>, Sim *isim)
{
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // esi
  Font *v7; // eax
  ksgui::Label *v8; // esi
  int v9; // eax
  int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  TimeLimitedTest *v16; // eax
  FormRunningTime_vtbl *v17; // edx
  float v18; // xmm0_4
  _BYTE v19[28]; // [esp-Ch] [ebp-6Ch] BYREF
  float h; // [esp+10h] [ebp-50h]
  int _Val; // [esp+28h] [ebp-38h] BYREF
  std::shared_ptr<Font> v22; // [esp+2Ch] [ebp-34h] BYREF
  FormRunningTime *v23; // [esp+34h] [ebp-2Ch]
  std::wstring v24; // [esp+38h] [ebp-28h] BYREF
  int v25; // [esp+5Ch] [ebp-4h]

  LODWORD(h) = 1;
  v23 = this;
  *(_DWORD *)&v19[24] = isim->game->gui;
  *(_DWORD *)&v19[20] = 7;
  *(_DWORD *)&v19[16] = 0;
  *(_WORD *)v19 = 0;
  std::wstring::assign((std::wstring *)v19, L"RUNNING_TIME", 0xCu);
  ksgui::Form::Form(this, a2, *(std::wstring *)v19, *(ksgui::GUI **)&v19[24], SLOBYTE(h));
  v25 = 0;
  LODWORD(h) = 12;
  this->__vftable = (FormRunningTime_vtbl *)&FormRunningTime::`vftable';
  *(_DWORD *)&v19[24] = L"Running Time";
  this->sim = isim;
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  std::wstring::assign(&v24, *(const wchar_t **)&v19[24], LODWORD(h));
  LOBYTE(v25) = 1;
  this->formTitle->setText(this->formTitle, &v24);
  LOBYTE(v25) = 0;
  if ( v24._Myres >= 8 )
    operator delete(v24._Bx._Ptr);
  LODWORD(h) = 24;
  this->devApp = 0;
  v4 = (Font *)operator new(LODWORD(h));
  _Val = (int)v4;
  LOBYTE(v25) = 2;
  if ( v4 )
    Font::Font(v4, eFontMonospaced, 64.0, 0, 0);
  else
    v5 = 0;
  LOBYTE(v25) = 0;
  v22 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v22, v5);
  v6 = this->font._Rep;
  this->font = v22;
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v6->_Weaks) )
        v6->_Delete_this(v6);
    }
  }
  v7 = this->font._Ptr;
  LODWORD(h) = 284;
  v7->shadowed = 1;
  v8 = (ksgui::Label *)operator new(LODWORD(h));
  _Val = (int)v8;
  LOBYTE(v25) = 3;
  if ( v8 )
  {
    h = *(float *)&this->sim->game->gui;
    *(_DWORD *)&v19[24] = 7;
    *(_DWORD *)&v19[20] = 0;
    *(_WORD *)&v19[4] = 0;
    std::wstring::assign((std::wstring *)&v19[4], word_17BE9D8, 0);
    ksgui::Label::Label(v8, *(std::wstring *)&v19[4], (ksgui::GUI *)LODWORD(h));
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  LOBYTE(v25) = 0;
  this->timeLeft = (ksgui::Label *)v10;
  v11 = *(float *)(v10 + 264);
  v12 = *(float *)(v10 + 32) - *(float *)(v10 + 28);
  v13 = *(float *)(v10 + 40) - *(float *)(v10 + 36);
  *(_DWORD *)(v10 + 36) = 1103626240;
  *(_DWORD *)(v10 + 28) = 1084227584;
  v14 = v12 + 5.0;
  v15 = v13 + 25.0;
  *(float *)(v10 + 32) = v14;
  *(float *)(v10 + 40) = v15;
  if ( v11 == 0.0 && *(float *)(v10 + 272) == 0.0 )
  {
    *(_DWORD *)(v10 + 264) = 1084227584;
    *(_DWORD *)(v10 + 272) = 1103626240;
    *(float *)(v10 + 268) = v14;
    *(float *)(v10 + 276) = v15;
  }
  ((void (*)(ksgui::Label *, int, int))this->timeLeft->setSize)(this->timeLeft, 1137180672, 1107296256);
  std::shared_ptr<Font>::operator=(&this->timeLeft->font, &this->font);
  this->timeLeft->foreColor = (vec4f)_xmm;
  _Val = (int)this->timeLeft;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  h = 50.0;
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Form::setSize(this, 500.0, h);
  ksgui::Form::setAutoHideMode(this, 1);
  v16 = GameObject::getGameObject<TimeLimitedTest>(this->sim);
  v17 = this->__vftable;
  v18 = this->scaleMult;
  this->timeLimitedTest = v16;
  v17->scaleByMult(this, COERCE_FLOAT(LODWORD(v18)));
}
void FormRunningTime::render(FormRunningTime *this, float dt)
{
  Game *v3; // esi
  int v4; // ecx
  vec4f v5; // xmm0
  const std::wstring *v6; // eax
  __int64 v7; // [esp+8h] [ebp-54h]
  float v8; // [esp+10h] [ebp-4Ch]
  std::wstring v9; // [esp+18h] [ebp-44h] BYREF
  std::wstring result; // [esp+30h] [ebp-2Ch] BYREF
  int v11; // [esp+58h] [ebp-4h]

  v3 = this->sim->game;
  v4 = 60000 * TimeLimitedTest::getMaxRunningTime(this->timeLimitedTest)
     - (int)(v3->gameTime.now - v3->gameTime.startTime);
  if ( v4 <= 0 )
  {
    this->timeLeft->foreColor = (vec4f)_xmm;
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    std::wstring::assign(&v9, L"TIME:TEST ENDED", 0xFu);
    v11 = 1;
    this->timeLeft->setText(this->timeLeft, &v9);
    v11 = -1;
    if ( v9._Myres >= 8 )
      operator delete(v9._Bx._Ptr);
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
  }
  else
  {
    v5 = (vec4f)_xmm;
    if ( v4 < 30000 && v4 / 500 % 2 )
      v5 = (vec4f)_xmm;
    this->timeLeft->foreColor = v5;
    v6 = timeToString(&result, v4, 3);
    v11 = 0;
    this->timeLeft->setText(this->timeLeft, v6);
    v11 = -1;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  ksgui::Control::render(this, (int)this, (int)v3, dt, v7, v8);
}
