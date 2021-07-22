#include "telemetryapp.h
void __userpurge TelemetryApp::TelemetryApp(TelemetryApp *this@<ecx>, unsigned int a2@<ebx>, CarAvatar *car)
{
  const std::wstring *v4; // eax
  std::vector<unsigned int> *v5; // ebx
  ksgui::Graph **v6; // ebp
  signed int v7; // edi
  wchar_t *v8; // esi
  float *v9; // eax
  float *v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  ksgui::Graph *v17; // esi
  _DWORD *v18; // eax
  unsigned int v19; // edi
  unsigned int *v20; // ecx
  int v21; // eax
  std::vector<ksgui::CustomSpinner *> *v22; // esi
  ksgui::CustomSpinner **v23; // eax
  int v24; // edi
  ksgui::CustomSpinner **v25; // ecx
  _DWORD *v26; // eax
  ksgui::Graph *v27; // esi
  _DWORD *v28; // eax
  unsigned int v29; // edi
  unsigned int *v30; // ecx
  int v31; // eax
  std::vector<ksgui::CustomSpinner *> *v32; // esi
  ksgui::CustomSpinner **v33; // eax
  int v34; // edi
  ksgui::CustomSpinner **v35; // ecx
  _DWORD *v36; // eax
  unsigned int *v37; // eax
  ksgui::Graph *v38; // edi
  int v39; // esi
  unsigned int *v40; // ecx
  unsigned int *v41; // eax
  _BYTE v42[28]; // [esp-14h] [ebp-ACh] BYREF
  float h; // [esp+8h] [ebp-90h]
  unsigned int v44; // [esp+20h] [ebp-78h] BYREF
  ksgui::Graph *v45; // [esp+24h] [ebp-74h] BYREF
  unsigned int _Count[2]; // [esp+28h] [ebp-70h] BYREF
  TelemetryApp *v47; // [esp+30h] [ebp-68h]
  __int64 v48; // [esp+34h] [ebp-64h]
  int v49; // [esp+3Ch] [ebp-5Ch]
  __int64 v50; // [esp+40h] [ebp-58h]
  int v51; // [esp+48h] [ebp-50h]
  TelemetryApp *v52; // [esp+4Ch] [ebp-4Ch]
  std::wstring text; // [esp+54h] [ebp-44h] BYREF
  std::wstring result; // [esp+6Ch] [ebp-2Ch] BYREF
  unsigned int v55; // [esp+84h] [ebp-14h]
  int v56; // [esp+94h] [ebp-4h]

  v47 = this;
  h = 0.0;
  v52 = this;
  *(_DWORD *)&v42[24] = car->game->gui;
  *(_DWORD *)&v42[20] = 7;
  *(_DWORD *)&v42[16] = 0;
  *(_WORD *)v42 = 0;
  std::wstring::assign((std::wstring *)v42, L"SUS_TELEMETRY", 0xDu);
  ksgui::Form::Form(this, a2, *(std::wstring *)v42, *(ksgui::GUI **)&v42[24], SLOBYTE(h));
  v56 = 0;
  LODWORD(h) = 12;
  this->__vftable = (TelemetryApp_vtbl *)&TelemetryApp::`vftable';
  result._Bx._Ptr = (wchar_t *)7;
  text._Myres = 0;
  text._Bx._Buf[2] = 0;
  std::wstring::assign((std::wstring *)&text._Bx._Alias[4], L"SusTelemetry", LODWORD(h));
  LOBYTE(v56) = 1;
  v4 = acTranslate((std::wstring *)&result._Bx._Alias[4], (const std::wstring *)&text._Bx._Alias[4]);
  LOBYTE(v56) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( v55 >= 8 )
    operator delete(*(void **)&result._Bx._Alias[4]);
  v55 = 7;
  LOBYTE(v56) = 0;
  result._Myres = 0;
  result._Bx._Buf[2] = 0;
  if ( result._Bx._Ptr >= (wchar_t *)8 )
    operator delete(*(void **)&text._Bx._Alias[4]);
  this->devApp = 1;
  this->car = car;
  ksgui::Form::setSize(this, 600.0, 400.0);
  v5 = (std::vector<unsigned int> *)&this->controls;
  *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&text._Bx + 4) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
  v6 = this->grSusTravel;
  v7 = 0;
  *(std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)((char *)&result._Bx + 4) = (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty)_xmm;
  v50 = 0x3F8000003F800000i64;
  v51 = 0;
  v48 = 1065353216i64;
  v49 = 0;
  _Count[1] = 0;
  do
  {
    v8 = (wchar_t *)operator new(0x140u);
    text._Bx._Ptr = v8;
    LOBYTE(v56) = 3;
    if ( v8 )
    {
      h = *(float *)&v47->gui;
      *(_DWORD *)&v42[24] = 7;
      *(_DWORD *)&v42[20] = 0;
      *(_WORD *)&v42[4] = 0;
      std::wstring::assign((std::wstring *)&v42[4], L"SUS_TRAVEL", 0xAu);
      ksgui::Graph::Graph((ksgui::Graph *)v8, *(std::wstring *)&v42[4], (ksgui::GUI *)LODWORD(h));
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    LOBYTE(v56) = 0;
    v11 = *(float *)&result._Bx._Alias[v7 + 4];
    v12 = *(float *)&text._Bx._Alias[v7 + 4];
    *v6 = (ksgui::Graph *)v10;
    v13 = v10[66];
    v14 = v10[10] - v10[9];
    v15 = (float)(v10[8] - v10[7]) + v12;
    v10[9] = v11;
    v16 = v14 + v11;
    v10[7] = v12;
    v10[8] = v15;
    v10[10] = v16;
    if ( v13 == 0.0 && v10[68] == 0.0 )
    {
      v10[66] = v12;
      v10[68] = v11;
      v10[67] = v15;
      v10[69] = v16;
    }
    ((void (*)(ksgui::Graph *, int, int))(*v6)->setSize)(*v6, 1132068864, 1117782016);
    v17 = *v6;
    v18 = operator new(0x18u);
    v19 = (unsigned int)v18;
    if ( v18 )
    {
      *v18 = 0;
      v18[1] = 0;
      v18[2] = 0;
      v18[3] = 0;
      v18[4] = 0;
      v18[5] = 0;
    }
    else
    {
      v19 = 0;
    }
    v20 = _Count;
    v21 = v51;
    v22 = (std::vector<ksgui::CustomSpinner *> *)&v17->series;
    *(_QWORD *)v19 = v50;
    *(_DWORD *)(v19 + 8) = v21;
    _Count[0] = v19;
    v23 = v22->_Mylast;
    if ( _Count >= (unsigned int *)v23
      || (v20 = (unsigned int *)v22->_Myfirst, v22->_Myfirst > (ksgui::CustomSpinner **)_Count) )
    {
      if ( v23 == v22->_Myend )
        std::vector<ksgui::CustomSpinner *>::_Reserve(v22, (unsigned int)v20);
      v26 = v22->_Mylast;
      if ( v26 )
        *v26 = v19;
    }
    else
    {
      v24 = _Count - v20;
      if ( v23 == v22->_Myend )
        std::vector<ksgui::CustomSpinner *>::_Reserve(v22, (unsigned int)v22->_Myfirst);
      v25 = v22->_Mylast;
      if ( v25 )
        *v25 = v22->_Myfirst[v24];
    }
    ++v22->_Mylast;
    v27 = *v6;
    v28 = operator new(0x18u);
    v29 = (unsigned int)v28;
    if ( v28 )
    {
      *v28 = 0;
      v28[1] = 0;
      v28[2] = 0;
      v28[3] = 0;
      v28[4] = 0;
      v28[5] = 0;
    }
    else
    {
      v29 = 0;
    }
    v30 = &v44;
    v31 = v49;
    v32 = (std::vector<ksgui::CustomSpinner *> *)&v27->series;
    *(_QWORD *)v29 = v48;
    *(_DWORD *)(v29 + 8) = v31;
    v44 = v29;
    v33 = v32->_Mylast;
    if ( &v44 >= (unsigned int *)v33
      || (v30 = (unsigned int *)v32->_Myfirst, v32->_Myfirst > (ksgui::CustomSpinner **)&v44) )
    {
      if ( v33 == v32->_Myend )
        std::vector<ksgui::CustomSpinner *>::_Reserve(v32, (unsigned int)v30);
      v36 = v32->_Mylast;
      if ( v36 )
        *v36 = v29;
    }
    else
    {
      v34 = &v44 - v30;
      if ( v33 == v32->_Myend )
        std::vector<ksgui::CustomSpinner *>::_Reserve(v32, (unsigned int)v32->_Myfirst);
      v35 = v32->_Mylast;
      if ( v35 )
        *v35 = v32->_Myfirst[v34];
    }
    ++v32->_Mylast;
    (*v6)->maxValuesCount = 100;
    (*v6)->maxY = 0.2;
    (*v6)->minY = -0.2;
    v37 = v5->_Mylast;
    v38 = *v6;
    v45 = *v6;
    if ( &v45 >= (ksgui::Graph **)v37 || v5->_Myfirst > (unsigned int *)&v45 )
    {
      if ( v37 == v5->_Myend )
        std::vector<unsigned int>::_Reserve(v5, 1u);
      v41 = v5->_Mylast;
      if ( v41 )
        *v41 = (unsigned int)v38;
    }
    else
    {
      v39 = ((char *)&v45 - (char *)v5->_Myfirst) >> 2;
      if ( v37 == v5->_Myend )
        std::vector<unsigned int>::_Reserve(v5, 1u);
      v40 = v5->_Mylast;
      if ( v40 )
        *v40 = v5->_Myfirst[v39];
    }
    ++v5->_Mylast;
    ++v6;
    v38->parent = v47;
    v7 = _Count[1] + 4;
    _Count[1] = v7;
  }
  while ( v7 < 16 );
}
void __userpurge TelemetryApp::render(TelemetryApp *this@<ecx>, int a2@<edi>, std::vector<unsigned int> *a3@<esi>, float dt)
{
  TelemetryApp *v4; // edx
  int v5; // ebp
  ksgui::Graph **v6; // ebx
  double v7; // st7
  ksgui::Graph *v8; // ecx
  float v9; // xmm0_4
  ksgui::ValueSerie **v10; // eax
  int v11; // eax
  std::vector<unsigned int> **v12; // eax
  unsigned int *v13; // eax
  unsigned int *v14; // ecx
  int *v15; // edi
  unsigned int *v16; // ecx
  unsigned int *v17; // eax
  int v18; // eax
  std::vector<unsigned int> **v19; // eax
  unsigned int *v20; // eax
  float v21; // xmm0_4
  ksgui::Graph *v22; // ecx
  unsigned int *v23; // eax
  unsigned int *v24; // ecx
  unsigned int *v25; // ecx
  float *v26; // eax
  __int64 v27; // [esp+4h] [ebp-28h]
  float v28; // [esp+Ch] [ebp-20h]
  float v29; // [esp+14h] [ebp-18h] BYREF
  int v30; // [esp+18h] [ebp-14h] BYREF
  float v31; // [esp+1Ch] [ebp-10h] BYREF
  ksgui::Control *v32; // [esp+20h] [ebp-Ch]
  float pkr; // [esp+24h] [ebp-8h]
  int v34; // [esp+28h] [ebp-4h]

  v4 = this;
  v5 = 0;
  v32 = this;
  v6 = this->grSusTravel;
  v34 = 1860 - (_DWORD)this;
  do
  {
    v7 = CarAvatar::getPackerRange(v4->car, v5);
    v8 = *v6;
    pkr = v7;
    v9 = pkr;
    v10 = v8->series._Mylast;
    if ( pkr == 0.0 )
    {
      v18 = v10 - v8->series._Myfirst;
      v30 = 1036831949;
      if ( !v18 )
        goto LABEL_30;
      if ( v8->autoAdjustMaxValue && v8->maxY < 0.1 )
        v8->maxY = 0.1;
      v19 = (std::vector<unsigned int> **)v8->series._Myfirst;
      a3 = *v19;
      v13 = (*v19)[1]._Mylast;
      if ( &v30 >= (int *)v13 || (v14 = a3[1]._Myfirst, v14 > (unsigned int *)&v30) )
      {
        if ( v13 == a3[1]._Myend )
          std::vector<unsigned int>::_Reserve(a3 + 1, 1u);
        v20 = a3[1]._Mylast;
        if ( v20 )
          *v20 = 1036831949;
        goto LABEL_29;
      }
      v15 = &v30;
    }
    else
    {
      v11 = v10 - v8->series._Myfirst;
      v29 = pkr;
      if ( !v11 )
        goto LABEL_30;
      if ( v8->autoAdjustMaxValue && pkr > v8->maxY )
        v8->maxY = pkr;
      v12 = (std::vector<unsigned int> **)v8->series._Myfirst;
      a3 = *v12;
      v13 = (*v12)[1]._Mylast;
      if ( &v29 >= (float *)v13 || (v14 = a3[1]._Myfirst, v14 > (unsigned int *)&v29) )
      {
        if ( v13 == a3[1]._Myend )
        {
          std::vector<unsigned int>::_Reserve(a3 + 1, 1u);
          v9 = pkr;
        }
        v17 = a3[1]._Mylast;
        if ( v17 )
          *(float *)v17 = v9;
        goto LABEL_29;
      }
      v15 = (int *)&v29;
    }
    a2 = ((char *)v15 - (char *)v14) >> 2;
    if ( v13 == a3[1]._Myend )
      std::vector<unsigned int>::_Reserve(a3 + 1, 1u);
    v16 = a3[1]._Mylast;
    if ( v16 )
      *v16 = a3[1]._Myfirst[a2];
LABEL_29:
    ++a3[1]._Mylast;
LABEL_30:
    v4 = (TelemetryApp *)v32;
    v21 = *(float *)((char *)v6 + LODWORD(v32[1].rect.bottom) + v34);
    v22 = *v6;
    pkr = v21;
    v31 = v21;
    if ( (unsigned int)(v22->series._Mylast - v22->series._Myfirst) > 1 )
    {
      if ( v22->autoAdjustMaxValue && v21 > v22->maxY )
        v22->maxY = v21;
      a3 = (std::vector<unsigned int> *)*((_DWORD *)v22->series._Myfirst + 1);
      v23 = a3[1]._Mylast;
      if ( &v31 >= (float *)v23 || (v24 = a3[1]._Myfirst, a2 = (int)&v31, v24 > (unsigned int *)&v31) )
      {
        if ( v23 == a3[1]._Myend )
        {
          std::vector<unsigned int>::_Reserve(a3 + 1, 1u);
          v21 = pkr;
          v4 = (TelemetryApp *)v32;
        }
        v26 = (float *)a3[1]._Mylast;
        if ( v26 )
          *v26 = v21;
      }
      else
      {
        a2 = ((char *)&v31 - (char *)v24) >> 2;
        if ( v23 == a3[1]._Myend )
        {
          std::vector<unsigned int>::_Reserve(a3 + 1, 1u);
          v4 = (TelemetryApp *)v32;
        }
        v25 = a3[1]._Mylast;
        if ( v25 )
          *v25 = a3[1]._Myfirst[a2];
      }
      ++a3[1]._Mylast;
    }
    ++v5;
    ++v6;
  }
  while ( v5 < 4 );
  ksgui::Control::render(v4, a2, (int)a3, dt, v27, v28);
}
