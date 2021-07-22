#include "netmonitorform.h
void __userpurge NetMonitorForm::NetMonitorForm(NetMonitorForm *this@<ecx>, unsigned int a2@<ebx>, Sim *sim)
{
  ACClient *v4; // eax
  ksgui::Graph *v5; // edi
  ksgui::Graph *v6; // eax
  ksgui::Graph *v7; // ecx
  ksgui::Graph *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  __m128 v14; // xmm0
  ksgui::Label *v15; // edi
  int v16; // eax
  int v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  ksgui::Label *v23; // edi
  int v24; // eax
  int v25; // ecx
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  _BYTE v31[36]; // [esp-Ch] [ebp-6Ch] BYREF
  int _Val; // [esp+28h] [ebp-38h] BYREF
  __int64 v33; // [esp+2Ch] [ebp-34h] BYREF
  NetMonitorForm *v34; // [esp+34h] [ebp-2Ch]
  std::wstring v35; // [esp+38h] [ebp-28h] BYREF
  int v36; // [esp+5Ch] [ebp-4h]

  *(_DWORD *)&v31[28] = 0;
  v34 = this;
  *(_DWORD *)&v31[24] = sim->game->gui;
  *(_DWORD *)&v31[20] = 7;
  *(_DWORD *)&v31[16] = 0;
  *(_WORD *)v31 = 0;
  std::wstring::assign((std::wstring *)v31, L"NET_MONITOR", 0xBu);
  ksgui::Form::Form(this, a2, *(std::wstring *)v31, *(ksgui::GUI **)&v31[24], v31[28]);
  v36 = 0;
  *(_DWORD *)&v31[28] = 11;
  this->__vftable = (NetMonitorForm_vtbl *)&NetMonitorForm::`vftable';
  *(_DWORD *)&v31[24] = L"Net monitor";
  this->sim = sim;
  v35._Myres = 7;
  v35._Mysize = 0;
  v35._Bx._Buf[0] = 0;
  std::wstring::assign(&v35, *(const wchar_t **)&v31[24], *(unsigned int *)&v31[28]);
  LOBYTE(v36) = 1;
  this->formTitle->setText(this->formTitle, &v35);
  LOBYTE(v36) = 0;
  if ( v35._Myres >= 8 )
    operator delete(v35._Bx._Ptr);
  v4 = GameObject::getGameObject<ACClient>(sim);
  *(_DWORD *)&v31[28] = 320;
  this->client = v4;
  v5 = (ksgui::Graph *)operator new(*(unsigned int *)&v31[28]);
  _Val = (int)v5;
  LOBYTE(v36) = 2;
  if ( v5 )
  {
    *(_DWORD *)&v31[28] = this->gui;
    *(_DWORD *)&v31[24] = 7;
    *(_DWORD *)&v31[20] = 0;
    *(_WORD *)&v31[4] = 0;
    std::wstring::assign((std::wstring *)&v31[4], L"VELOCITY", 8u);
    ksgui::Graph::Graph(v5, *(std::wstring *)&v31[4], *(ksgui::GUI **)&v31[28]);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  LOBYTE(v36) = 0;
  this->grVelocity = v7;
  ((void (*)(ksgui::Graph *, int, int))v7->setSize)(v7, 1137180672, 1128792064);
  v8 = this->grVelocity;
  v9 = v8->rectBase.left;
  v10 = v8->rect.right - v8->rect.left;
  v11 = v8->rect.bottom - v8->rect.top;
  v8->rect.top = 30.0;
  v8->rect.left = 10.0;
  v12 = v10 + 10.0;
  v13 = v11 + 30.0;
  v8->rect.right = v12;
  v8->rect.bottom = v13;
  if ( v9 == 0.0 && v8->rectBase.top == 0.0 )
  {
    v8->rectBase.left = 10.0;
    v8->rectBase.top = 30.0;
    v8->rectBase.right = v12;
    v8->rectBase.bottom = v13;
  }
  *(_DWORD *)&v35._Bx._Alias[8] = 1065353216;
  v33 = LODWORD(FLOAT_1_0);
  *(_QWORD *)&v31[20] = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_1_0), (__m128)LODWORD(FLOAT_1_0)).m128_u64[0];
  *(_DWORD *)&v31[28] = 1065353216;
  ksgui::Graph::addSerie(this->grVelocity, *(__int128 *)&v31[20]);
  v14 = (__m128)_mm_loadl_epi64((const __m128i *)&v33);
  *(_DWORD *)&v35._Bx._Alias[8] = 1065353216;
  *(_QWORD *)&v31[20] = _mm_unpacklo_ps(v14, (__m128)0i64).m128_u64[0];
  *(_DWORD *)&v31[28] = 1065353216;
  ksgui::Graph::addSerie(this->grVelocity, *(__int128 *)&v31[20]);
  this->grVelocity->maxValuesCount = 400;
  this->grVelocity->maxY = 300.0;
  _Val = (int)this->grVelocity;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&v31[28] = 284;
  *(_DWORD *)(_Val + 148) = this;
  v15 = (ksgui::Label *)operator new(*(unsigned int *)&v31[28]);
  LODWORD(v33) = v15;
  LOBYTE(v36) = 3;
  if ( v15 )
  {
    *(_DWORD *)&v31[28] = this->gui;
    *(_DWORD *)&v31[24] = 7;
    *(_DWORD *)&v31[20] = 0;
    *(_WORD *)&v31[4] = 0;
    std::wstring::assign((std::wstring *)&v31[4], L"ERROR_VECTOR", 0xCu);
    ksgui::Label::Label(v15, *(std::wstring *)&v31[4], *(ksgui::GUI **)&v31[28]);
    v17 = v16;
  }
  else
  {
    v17 = 0;
  }
  LOBYTE(v36) = 0;
  this->lbErrorVector = (ksgui::Label *)v17;
  v18 = *(float *)(v17 + 264);
  v19 = *(float *)(v17 + 32) - *(float *)(v17 + 28);
  v20 = *(float *)(v17 + 40) - *(float *)(v17 + 36);
  *(_DWORD *)(v17 + 36) = 1106247680;
  *(_DWORD *)(v17 + 28) = 1092616192;
  v21 = v19 + 10.0;
  v22 = v20 + 30.0;
  *(float *)(v17 + 32) = v21;
  *(float *)(v17 + 40) = v22;
  if ( v18 == 0.0 && *(float *)(v17 + 272) == 0.0 )
  {
    *(_DWORD *)(v17 + 264) = 1092616192;
    *(_DWORD *)(v17 + 272) = 1106247680;
    *(float *)(v17 + 268) = v21;
    *(float *)(v17 + 276) = v22;
  }
  _Val = (int)this->lbErrorVector;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)&v31[28] = 284;
  *(_DWORD *)(_Val + 148) = this;
  v23 = (ksgui::Label *)operator new(*(unsigned int *)&v31[28]);
  LODWORD(v33) = v23;
  LOBYTE(v36) = 4;
  if ( v23 )
  {
    *(_DWORD *)&v31[28] = this->gui;
    *(_DWORD *)&v31[24] = 7;
    *(_DWORD *)&v31[20] = 0;
    *(_WORD *)&v31[4] = 0;
    std::wstring::assign((std::wstring *)&v31[4], L"PING", 4u);
    ksgui::Label::Label(v23, *(std::wstring *)&v31[4], *(ksgui::GUI **)&v31[28]);
    v25 = v24;
  }
  else
  {
    v25 = 0;
  }
  LOBYTE(v36) = 0;
  this->lbPing = (ksgui::Label *)v25;
  v26 = *(float *)(v25 + 264);
  v27 = *(float *)(v25 + 32) - *(float *)(v25 + 28);
  v28 = *(float *)(v25 + 40) - *(float *)(v25 + 36);
  *(_DWORD *)(v25 + 36) = 1114636288;
  *(_DWORD *)(v25 + 28) = 1092616192;
  v29 = v27 + 10.0;
  v30 = v28 + 60.0;
  *(float *)(v25 + 32) = v29;
  *(float *)(v25 + 40) = v30;
  if ( v26 == 0.0 && *(float *)(v25 + 272) == 0.0 )
  {
    *(_DWORD *)(v25 + 264) = 1092616192;
    *(_DWORD *)(v25 + 272) = 1114636288;
    *(float *)(v25 + 268) = v29;
    *(float *)(v25 + 276) = v30;
  }
  _Val = (int)this->lbPing;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
  *(_DWORD *)(_Val + 148) = this;
  ksgui::Form::setSize(this, 500.0, 400.0);
}
void __userpurge NetMonitorForm::render(NetMonitorForm *this@<ecx>, void (__cdecl *a2)(void *)@<esi>, float dt)
{
  CarAvatar *v4; // eax
  ksgui::Graph *v5; // ecx
  float v6; // xmm0_4
  int v7; // eax
  Sim *v8; // ecx
  CarAvatar *v9; // eax
  ksgui::Graph *v10; // ecx
  float v11; // xmm0_4
  unsigned int v12; // eax
  CarAvatar *v13; // eax
  int v14; // eax
  float *v15; // esi
  int v16; // eax
  float v17; // xmm2_4
  float v18; // xmm0_4
  std::wostream *v19; // eax
  const std::wstring *v20; // eax
  std::wstring *v21; // eax
  CarAvatar *v22; // eax
  std::wostream *v23; // eax
  const std::wstring *v24; // eax
  int v25; // [esp+18h] [ebp-F8h]
  __int64 v26; // [esp+1Ch] [ebp-F4h]
  float v27; // [esp+24h] [ebp-ECh]
  int _Val; // [esp+2Ch] [ebp-E4h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v29; // [esp+30h] [ebp-E0h] BYREF
  std::wstring result; // [esp+E4h] [ebp-2Ch] BYREF
  int v31; // [esp+10Ch] [ebp-4h]

  _Val = 0;
  v4 = Sim::getCar(this->sim, 0);
  v5 = this->grVelocity;
  v6 = v4->physicsState.speed.value * 3.5999999;
  v7 = v5->series._Mylast - v5->series._Myfirst;
  _Val = LODWORD(v6);
  if ( v7 )
  {
    if ( v5->autoAdjustMaxValue && v6 > v5->maxY )
      v5->maxY = v6;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&(*v5->series._Myfirst)->values, &_Val);
  }
  v8 = this->sim;
  if ( (unsigned int)(v8->cars._Mylast - v8->cars._Myfirst) > 1 )
  {
    v9 = Sim::getCar(v8, 1u);
    v10 = this->grVelocity;
    v11 = v9->physicsState.speed.value * 3.5999999;
    v12 = v10->series._Mylast - v10->series._Myfirst;
    _Val = LODWORD(v11);
    if ( v12 > 1 )
    {
      if ( v10->autoAdjustMaxValue && v11 > v10->maxY )
        v10->maxY = v11;
      std::vector<CarAvatar *>::push_back((std::vector<int> *)(*((_DWORD *)v10->series._Myfirst + 1) + 12), &_Val);
    }
    v13 = Sim::getCar(this->sim, 1u);
    v14 = __RTDynamicCast(
            v13->physicsStateProvider,
            0,
            &ICarPhysicsStateProvider `RTTI Type Descriptor',
            &NetCarStateProvider `RTTI Type Descriptor',
            0);
    *(_DWORD *)v29.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v29.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    v15 = (float *)v14;
    std::wios::wios(v29.gap68);
    v31 = 0;
    _Val = 1;
    std::wiostream::basic_iostream<wchar_t>(&v29, &v29.gap10[8], 0);
    v31 = 1;
    *(_DWORD *)&v29.gap0[*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&_Val + *(_DWORD *)(*(_DWORD *)v29.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v29.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v29.gap10[8]);
    *(_DWORD *)&v29.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v29.gap10[64] = 0;
    *(_DWORD *)&v29.gap10[68] = 0;
    v31 = 3;
    v16 = *(_DWORD *)(*(_DWORD *)v29.gap0 + 4);
    *(_DWORD *)&v29.gap10[v16 + 8] = 2;
    *(_DWORD *)&v29.gap10[v16 + 12] = 0;
    v17 = (float)((float)(v15[42] * v15[42]) + (float)(v15[43] * v15[43])) + (float)(v15[44] * v15[44]);
    v18 = 0.0;
    if ( v17 != 0.0 )
      v18 = fsqrt(v17);
    v19 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v29.gap10, "EV: ");
    std::wostream::operator<<(v19, LODWORD(v18));
    v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v29, &result);
    LOBYTE(v31) = 4;
    this->lbErrorVector->setText(this->lbErrorVector, v20);
    LOBYTE(v31) = 3;
    a2 = operator delete;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v31) = 5;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v29.gap10[8]);
    v21 = &result;
    if ( result._Myres >= 8 )
      v21 = (std::wstring *)result._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v29.gap10[8], v21->_Bx._Buf, result._Mysize, *(int *)&v29.gap10[68]);
    LOBYTE(v31) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = Sim::getCar(this->sim, 0);
    v25 = ACClient::getPing(this->client, v22);
    v23 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v29.gap10, "P: ");
    std::wostream::operator<<(v23, v25);
    v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v29, &result);
    LOBYTE(v31) = 6;
    this->lbPing->setText(this->lbPing, v24);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v31 = -1;
    result._Bx._Buf[0] = 0;
    result._Myres = 7;
    result._Mysize = 0;
    *(_DWORD *)&v29.gap0[*(_DWORD *)(*(_DWORD *)v29.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&_Val + *(_DWORD *)(*(_DWORD *)v29.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v29.gap0 + 4) - 104;
    *(_DWORD *)&v29.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v29.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v29.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v29.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v29.gap68);
  }
  ksgui::Control::render(this, (int)this, (int)a2, dt, v26, v27);
}
