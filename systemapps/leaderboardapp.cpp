#include "leaderboardapp.h
void LeaderboardApp::LeaderboardApp(LeaderboardApp *this, Sim *aSim)
{
  const std::wstring *v3; // eax
  ACStandardLeaderboard *v4; // eax
  int v5; // eax
  int v6; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  std::wstring v11; // [esp-Ch] [ebp-78h] BYREF
  float w; // [esp+Ch] [ebp-60h]
  float h; // [esp+10h] [ebp-5Ch]
  int _Val[2]; // [esp+24h] [ebp-48h] BYREF
  std::wstring text; // [esp+2Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+44h] [ebp-28h] BYREF
  int v17; // [esp+68h] [ebp-4h]

  h = 0.0;
  _Val[1] = (int)this;
  w = *(float *)&aSim->game->gui;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, L"LEADERBOARD_APP", 0xFu);
  ksgui::Form::Form(this, (unsigned int)aSim, v11, (ksgui::GUI *)LODWORD(w), SLOBYTE(h));
  v17 = 0;
  LODWORD(h) = 11;
  this->__vftable = (LeaderboardApp_vtbl *)&LeaderboardApp::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Leaderboard", LODWORD(h));
  LOBYTE(v17) = 1;
  v3 = acTranslate(&result, &text);
  LOBYTE(v17) = 2;
  this->formTitle->setText(this->formTitle, v3);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v17) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  LODWORD(h) = 536;
  this->devApp = 0;
  v4 = (ACStandardLeaderboard *)operator new(LODWORD(h));
  _Val[0] = (int)v4;
  LOBYTE(v17) = 3;
  if ( v4 )
  {
    ACStandardLeaderboard::ACStandardLeaderboard(v4, aSim, 5, 1);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  LOBYTE(v17) = 0;
  v7 = *(float *)(v6 + 264);
  v8 = *(float *)(v6 + 40) - *(float *)(v6 + 36);
  v9 = *(float *)(v6 + 32) - *(float *)(v6 + 28);
  *(_DWORD *)(v6 + 36) = 1106247680;
  *(_DWORD *)(v6 + 28) = 0;
  v10 = v8 + 30.0;
  *(float *)(v6 + 32) = v9;
  *(float *)(v6 + 40) = v10;
  if ( v7 == 0.0 && *(float *)(v6 + 272) == 0.0 )
  {
    *(_DWORD *)(v6 + 264) = 0;
    *(_DWORD *)(v6 + 272) = 1106247680;
    *(float *)(v6 + 268) = v9;
    *(float *)(v6 + 276) = v10;
  }
  (*(void (**)(int, float, int))(*(_DWORD *)v6 + 28))(v6, COERCE_FLOAT(LODWORD(v9)), 1126989824);
  _Val[0] = v6;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, _Val);
  *(_DWORD *)(_Val[0] + 148) = this;
  ksgui::Form::setSize(
    this,
    *(float *)(v6 + 32) - *(float *)(v6 + 28),
    (float)((float)(*(float *)(v6 + 40) - *(float *)(v6 + 36)) + *(float *)(v6 + 36)) + 40.0);
  this->autohide = 1;
  *(_DWORD *)(v6 + 436) = 1;
  *(_BYTE *)(v6 + 440) = 0;
}
