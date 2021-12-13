#include "tyrethermalmodel.h"
void TyreThermalModel::TyreThermalModel(TyreThermalModel *this)
{
  this->elements = 0;
  this->stripes = 0;
  this->patches._Myfirst = 0;
  this->patches._Mylast = 0;
  this->patches._Myend = 0;
  this->phase = 0.0;
  this->patchData.internalCoreTransfer = 0.0040000002;
  this->patchData.coolFactorGain = 0.0;
  this->patchData.surfaceTransfer = 0.30000001;
  this->patchData.patchTransfer = 0.2;
  this->patchData.patchCoreTransfer = 0.2;
  this->coreTemp = 0.0;
  Curve::Curve(&this->performanceCurve);
  this->isActive = 1;
  this->thermalMultD = 1.0;
  this->practicalTemp = 0.0;
  this->camberSpreadK = 1.4;
  this->car = 0;
  this->coreTInput = 0.0;
}
void TyreThermalModel::~TyreThermalModel(TyreThermalModel *this)
{
  Curve::~Curve(&this->performanceCurve);
  if ( this->patches._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->patches);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<TyreThermalPatch>>>(
      this->patches._Myfirst,
      this->patches._Mylast);
    operator delete(this->patches._Myfirst);
    this->patches._Myfirst = 0;
    this->patches._Mylast = 0;
    this->patches._Myend = 0;
  }
}
void TyreThermalModel::addThermalCoreInput(TyreThermalModel *this, float temp)
{
  this->coreTInput = temp + this->coreTInput;
}
void TyreThermalModel::addThermalInput(TyreThermalModel *this, float xpos, float pressureRel, float temp)
{
  Car *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm3_4
  TyreThermalPatch *v8; // eax
  TyreThermalPatch *v9; // eax
  TyreThermalPatch *v10; // eax
  float v11; // [esp+Ch] [ebp-Ch]
  float xposa; // [esp+1Ch] [ebp+4h]
  float pressureRela; // [esp+20h] [ebp+8h]
  float tempa; // [esp+24h] [ebp+Ch]

  v5 = this->car;
  if ( v5 )
    tempa = v5->ksPhysics->roadTemperature + temp;
  else
    tempa = temp + 26.0;
  v6 = this->camberSpreadK * xpos;
  xposa = FLOAT_N1_0;
  if ( v6 <= 1.0 )
  {
    if ( v6 >= -1.0 )
      v7 = v6;
    else
      v7 = FLOAT_N1_0;
  }
  else
  {
    v7 = FLOAT_1_0;
  }
  if ( v6 <= 1.0 )
  {
    if ( v6 >= -1.0 )
      xposa = v6;
  }
  else
  {
    xposa = FLOAT_1_0;
  }
  v11 = pressureRel * 0.1;
  pressureRela = (float)(pressureRel * -0.5) + 1.0;
  v8 = TyreThermalModel::getPatchAt(
         this,
         0,
         (unsigned __int64)(this->phase * 0.1591549430964443 * (double)this->elements) % this->elements);
  v8->inputT = (float)((float)((float)((float)(v7 + 1.0) - (float)(v11 * 0.5)) * pressureRela) * tempa) + v8->inputT;
  v9 = TyreThermalModel::getPatchAt(
         this,
         1,
         (unsigned __int64)(this->phase * 0.1591549430964443 * (double)this->elements) % this->elements);
  v9->inputT = (float)((float)((float)(v11 + 1.0) * pressureRela) * tempa) + v9->inputT;
  v10 = TyreThermalModel::getPatchAt(
          this,
          2,
          (unsigned __int64)(this->phase * 0.1591549430964443 * (double)this->elements) % this->elements);
  v10->inputT = (float)((float)((float)((float)(1.0 - xposa) - (float)(v11 * 0.5)) * pressureRela) * tempa)
              + v10->inputT;
}
void TyreThermalModel::buildTyre(TyreThermalModel *this)
{
  TyreThermalModel *v1; // ebx
  int v2; // ebp
  int v3; // eax
  TyreThermalPatch *v4; // esi
  int v5; // eax
  Car *v6; // ecx
  TyreThermalPatch *v7; // eax
  TyreThermalPatch **v8; // ecx
  std::vector<TyreThermalPatch *> *v9; // edi
  TyreThermalPatch **v10; // ebp
  TyreThermalPatch **v11; // edx
  int v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // edx
  TyreThermalPatch **v15; // ecx
  TyreThermalPatch **v16; // edx
  int v17; // ecx
  unsigned int v18; // edx
  unsigned int v19; // edx
  _DWORD *v20; // eax
  TyreThermalPatch **v21; // ecx
  TyreThermalPatch **v22; // ebp
  TyreThermalPatch **v23; // edx
  int v24; // ecx
  unsigned int v25; // edx
  unsigned int v26; // edx
  TyreThermalPatch **v27; // ecx
  TyreThermalPatch **v28; // edx
  int v29; // ecx
  unsigned int v30; // edx
  unsigned int v31; // edx
  TyreThermalPatch **v32; // eax
  TyreThermalPatch *v33; // eax
  TyreThermalPatch **v34; // ecx
  std::vector<TyreThermalPatch *> *v35; // edi
  TyreThermalPatch **v36; // ebp
  TyreThermalPatch **v37; // edx
  int v38; // ecx
  unsigned int v39; // edx
  unsigned int v40; // edx
  TyreThermalPatch **v41; // ecx
  TyreThermalPatch **v42; // edx
  int v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edx
  _DWORD *v46; // eax
  TyreThermalPatch **v47; // ecx
  TyreThermalPatch **v48; // ebp
  TyreThermalPatch **v49; // edx
  int v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // edx
  TyreThermalPatch **v53; // ecx
  TyreThermalPatch **v54; // edx
  int v55; // ecx
  unsigned int v56; // edx
  unsigned int v57; // edx
  TyreThermalPatch **v58; // eax
  TyreThermalPatch *v59; // eax
  TyreThermalPatch **v60; // ecx
  std::vector<TyreThermalPatch *> *v61; // edi
  TyreThermalPatch **v62; // ebp
  TyreThermalPatch **v63; // edx
  int v64; // ecx
  unsigned int v65; // edx
  unsigned int v66; // edx
  TyreThermalPatch **v67; // ecx
  TyreThermalPatch **v68; // edx
  int v69; // ecx
  unsigned int v70; // edx
  unsigned int v71; // edx
  _DWORD *v72; // eax
  TyreThermalPatch **v73; // ecx
  TyreThermalPatch **v74; // ebx
  TyreThermalPatch **v75; // edx
  int v76; // ecx
  unsigned int v77; // edx
  unsigned int v78; // edx
  TyreThermalPatch **v79; // ecx
  TyreThermalPatch **v80; // edx
  int v81; // ecx
  unsigned int v82; // edx
  unsigned int v83; // edx
  TyreThermalPatch **v84; // eax
  TyreThermalPatch *np; // [esp+8h] [ebp-20h] BYREF
  TyreThermalModel *v86; // [esp+Ch] [ebp-1Ch]
  int y; // [esp+10h] [ebp-18h]
  int x; // [esp+14h] [ebp-14h]
  TyreThermalPatch *pp; // [esp+18h] [ebp-10h] BYREF
  TyreThermalPatch *v90; // [esp+1Ch] [ebp-Ch] BYREF
  TyreThermalPatch *v91; // [esp+20h] [ebp-8h] BYREF
  unsigned int _Count; // [esp+24h] [ebp-4h]

  v1 = this;
  v86 = this;
  std::vector<TyreThermalPatch>::resize(&this->patches, this->stripes * this->elements);
  v2 = 0;
  for ( x = 0; v2 < v1->stripes; x = v2 )
  {
    v3 = 0;
    for ( y = 0; v3 < v1->elements; y = v3 )
    {
      v4 = TyreThermalModel::getPatchAt(v1, v2, v3);
      v5 = y;
      np = v4;
      v4->elementIndex = y;
      v4->stripeIndex = v2;
      v6 = v1->car;
      if ( v6 )
        v4->T = v6->ksPhysics->ambientTemperature;
      else
        v4->T = 26.0;
      if ( v2 > 0 )
      {
        v7 = TyreThermalModel::getPatchAt(v1, v2 - 1, v5);
        v8 = v4->connections._Mylast;
        v9 = &v7->connections;
        pp = v7;
        if ( &pp >= v8 || (v10 = v4->connections._Myfirst, v4->connections._Myfirst > &pp) )
        {
          v16 = v4->connections._Myend;
          if ( v8 == v16 && !(v16 - v8) )
          {
            v17 = v8 - v4->connections._Myfirst;
            if ( v17 == 0x3FFFFFFF )
              goto LABEL_159;
            v18 = v16 - v4->connections._Myfirst;
            if ( 0x3FFFFFFF - (v18 >> 1) >= v18 )
              v19 = (v18 >> 1) + v18;
            else
              v19 = 0;
            if ( v19 < v17 + 1 )
              v19 = v17 + 1;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(&v4->connections, v19);
          }
          v20 = v4->connections._Mylast;
          if ( v20 )
            *v20 = v9;
        }
        else
        {
          v11 = v4->connections._Myend;
          if ( v8 == v11 && !(v11 - v8) )
          {
            v12 = v8 - v10;
            if ( v12 == 0x3FFFFFFF )
              goto LABEL_159;
            v13 = v11 - v10;
            _Count = v12 + 1;
            if ( 0x3FFFFFFF - (v13 >> 1) >= v13 )
              v14 = (v13 >> 1) + v13;
            else
              v14 = 0;
            if ( v14 < _Count )
              v14 = _Count;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(&v4->connections, v14);
          }
          v15 = v4->connections._Mylast;
          if ( v15 )
            *v15 = v4->connections._Myfirst[&pp - v10];
        }
        ++v4->connections._Mylast;
        v21 = v9->_Mylast;
        if ( &np >= v21 || (v22 = v9->_Myfirst, v9->_Myfirst > &np) )
        {
          v28 = v9->_Myend;
          if ( v21 == v28 && !(v28 - v21) )
          {
            v29 = v21 - v9->_Myfirst;
            if ( v29 == 0x3FFFFFFF )
              goto LABEL_159;
            v30 = v28 - v9->_Myfirst;
            if ( 0x3FFFFFFF - (v30 >> 1) >= v30 )
              v31 = (v30 >> 1) + v30;
            else
              v31 = 0;
            if ( v31 < v29 + 1 )
              v31 = v29 + 1;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(v9, v31);
          }
          v32 = v9->_Mylast;
          if ( v32 )
            *v32 = v4;
        }
        else
        {
          v23 = v9->_Myend;
          if ( v21 == v23 && !(v23 - v21) )
          {
            v24 = v21 - v22;
            if ( v24 == 0x3FFFFFFF )
              goto LABEL_159;
            v25 = v23 - v22;
            _Count = v24 + 1;
            if ( 0x3FFFFFFF - (v25 >> 1) >= v25 )
              v26 = (v25 >> 1) + v25;
            else
              v26 = 0;
            if ( v26 < _Count )
              v26 = _Count;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(v9, v26);
          }
          v27 = v9->_Mylast;
          if ( v27 )
            *v27 = v9->_Myfirst[&np - v22];
        }
        v2 = x;
        v1 = v86;
        v5 = y;
        ++v9->_Mylast;
      }
      if ( v5 > 0 )
      {
        v33 = TyreThermalModel::getPatchAt(v1, v2, v5 - 1);
        v34 = v4->connections._Mylast;
        v35 = &v33->connections;
        v90 = v33;
        if ( &v90 >= v34 || (v36 = v4->connections._Myfirst, v4->connections._Myfirst > &v90) )
        {
          v42 = v4->connections._Myend;
          if ( v34 == v42 && !(v42 - v34) )
          {
            v43 = v34 - v4->connections._Myfirst;
            if ( v43 == 0x3FFFFFFF )
              goto LABEL_159;
            v44 = v42 - v4->connections._Myfirst;
            if ( 0x3FFFFFFF - (v44 >> 1) >= v44 )
              v45 = (v44 >> 1) + v44;
            else
              v45 = 0;
            if ( v45 < v43 + 1 )
              v45 = v43 + 1;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(&v4->connections, v45);
          }
          v46 = v4->connections._Mylast;
          if ( v46 )
            *v46 = v35;
        }
        else
        {
          v37 = v4->connections._Myend;
          if ( v34 == v37 && !(v37 - v34) )
          {
            v38 = v34 - v36;
            if ( v38 == 0x3FFFFFFF )
              goto LABEL_159;
            v39 = v37 - v36;
            _Count = v38 + 1;
            if ( 0x3FFFFFFF - (v39 >> 1) >= v39 )
              v40 = (v39 >> 1) + v39;
            else
              v40 = 0;
            if ( v40 < _Count )
              v40 = _Count;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(&v4->connections, v40);
          }
          v41 = v4->connections._Mylast;
          if ( v41 )
            *v41 = v4->connections._Myfirst[&v90 - v36];
        }
        ++v4->connections._Mylast;
        v47 = v35->_Mylast;
        if ( &np >= v47 || (v48 = v35->_Myfirst, v35->_Myfirst > &np) )
        {
          v54 = v35->_Myend;
          if ( v47 == v54 && !(v54 - v47) )
          {
            v55 = v47 - v35->_Myfirst;
            if ( v55 == 0x3FFFFFFF )
              goto LABEL_159;
            v56 = v54 - v35->_Myfirst;
            if ( 0x3FFFFFFF - (v56 >> 1) >= v56 )
              v57 = (v56 >> 1) + v56;
            else
              v57 = 0;
            if ( v57 < v55 + 1 )
              v57 = v55 + 1;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(v35, v57);
          }
          v58 = v35->_Mylast;
          if ( v58 )
            *v58 = v4;
        }
        else
        {
          v49 = v35->_Myend;
          if ( v47 == v49 && !(v49 - v47) )
          {
            v50 = v47 - v48;
            if ( v50 == 0x3FFFFFFF )
              goto LABEL_159;
            v51 = v49 - v48;
            _Count = v50 + 1;
            if ( 0x3FFFFFFF - (v51 >> 1) >= v51 )
              v52 = (v51 >> 1) + v51;
            else
              v52 = 0;
            if ( v52 < _Count )
              v52 = _Count;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(v35, v52);
          }
          v53 = v35->_Mylast;
          if ( v53 )
            *v53 = v35->_Myfirst[&np - v48];
        }
        v1 = v86;
        ++v35->_Mylast;
      }
      if ( y == v1->elements - 1 )
      {
        v59 = TyreThermalModel::getPatchAt(v1, x, 0);
        v60 = v4->connections._Mylast;
        v61 = &v59->connections;
        v91 = v59;
        if ( &v91 >= v60 || (v62 = v4->connections._Myfirst, v4->connections._Myfirst > &v91) )
        {
          v68 = v4->connections._Myend;
          if ( v60 == v68 && !(v68 - v60) )
          {
            v69 = v60 - v4->connections._Myfirst;
            if ( v69 == 0x3FFFFFFF )
              goto LABEL_159;
            v70 = v68 - v4->connections._Myfirst;
            if ( 0x3FFFFFFF - (v70 >> 1) >= v70 )
              v71 = (v70 >> 1) + v70;
            else
              v71 = 0;
            if ( v71 < v69 + 1 )
              v71 = v69 + 1;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(&v4->connections, v71);
          }
          v72 = v4->connections._Mylast;
          if ( v72 )
            *v72 = v61;
        }
        else
        {
          v63 = v4->connections._Myend;
          if ( v60 == v63 && !(v63 - v60) )
          {
            v64 = v60 - v62;
            if ( v64 == 0x3FFFFFFF )
              goto LABEL_159;
            v65 = v63 - v62;
            _Count = v64 + 1;
            if ( 0x3FFFFFFF - (v65 >> 1) >= v65 )
              v66 = (v65 >> 1) + v65;
            else
              v66 = 0;
            if ( v66 < _Count )
              v66 = _Count;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(&v4->connections, v66);
          }
          v67 = v4->connections._Mylast;
          if ( v67 )
            *v67 = v4->connections._Myfirst[&v91 - v62];
        }
        ++v4->connections._Mylast;
        v73 = v61->_Mylast;
        if ( &np >= v73 || (v74 = v61->_Myfirst, v61->_Myfirst > &np) )
        {
          v80 = v61->_Myend;
          if ( v73 == v80 && !(v80 - v73) )
          {
            v81 = v73 - v61->_Myfirst;
            if ( v81 == 0x3FFFFFFF )
LABEL_159:
              std::_Xlength_error("vector<T> too long");
            v82 = v80 - v61->_Myfirst;
            if ( 0x3FFFFFFF - (v82 >> 1) >= v82 )
              v83 = (v82 >> 1) + v82;
            else
              v83 = 0;
            if ( v83 < v81 + 1 )
              v83 = v81 + 1;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(v61, v83);
          }
          v84 = v61->_Mylast;
          if ( v84 )
            *v84 = v4;
        }
        else
        {
          v75 = v61->_Myend;
          if ( v73 == v75 && !(v75 - v73) )
          {
            v76 = v73 - v74;
            if ( v76 == 0x3FFFFFFF )
              goto LABEL_159;
            v77 = v75 - v74;
            if ( 0x3FFFFFFF - (v77 >> 1) >= v77 )
              v78 = (v77 >> 1) + v77;
            else
              v78 = 0;
            if ( v78 < v76 + 1 )
              v78 = v76 + 1;
            std::vector<ID3D11ShaderResourceView *>::_Reallocate(v61, v78);
          }
          v79 = v61->_Mylast;
          if ( v79 )
            *v79 = v61->_Myfirst[&np - v74];
        }
        v1 = v86;
        ++v61->_Mylast;
      }
      v2 = x;
      v3 = y + 1;
    }
    ++v2;
  }
}
double TyreThermalModel::getAvgSurfaceTemp(TyreThermalModel *this)
{
  TyreThermalPatch *v1; // edx
  float v2; // xmm1_4
  TyreThermalPatch *v3; // eax
  float tt; // [esp+0h] [ebp-4h]

  v1 = this->patches._Mylast;
  v2 = 0.0;
  v3 = this->patches._Myfirst;
  tt = 0.0;
  if ( v3 != v1 )
  {
    do
    {
      v2 = v2 + v3->T;
      ++v3;
    }
    while ( v3 != v1 );
    tt = v2;
  }
  return tt * 0.027777778;
}
double TyreThermalModel::getCorrectedD(TyreThermalModel *this, float d, float camberRAD)
{
  double result; // st7

  if ( this->isActive )
    result = this->thermalMultD * d;
  else
    result = d;
  return result;
}
double TyreThermalModel::getCurrentCPTemp(TyreThermalModel *this, float camber)
{
  TyreThermalModel *v2; // ebx
  float v3; // xmm0_4
  float v4; // xmm3_4
  TyreThermalPatch *v5; // ebp
  TyreThermalPatch *v6; // ebx
  float cambera; // [esp+Ch] [ebp+4h]

  v2 = this;
  v3 = this->camberSpreadK * camber;
  cambera = FLOAT_N1_0;
  if ( v3 <= 1.0 )
  {
    if ( v3 >= -1.0 )
      v4 = v3;
    else
      v4 = FLOAT_N1_0;
  }
  else
  {
    v4 = FLOAT_1_0;
  }
  if ( v3 <= 1.0 )
  {
    if ( v3 >= -1.0 )
      cambera = v3;
  }
  else
  {
    cambera = FLOAT_1_0;
  }
  v5 = TyreThermalModel::getPatchAt(
         this,
         0,
         (unsigned __int64)(this->phase * 0.1591549430964443 * (double)this->elements) % this->elements);
  v6 = TyreThermalModel::getPatchAt(
         v2,
         1,
         (unsigned __int64)(v2->phase * 0.1591549430964443 * (double)v2->elements) % v2->elements);
  return (float)((float)((float)((float)(v5->T * (float)(v4 + 1.0)) + v6->T)
                       + (float)((float)(1.0 - cambera)
                               * TyreThermalModel::getPatchAt(
                                   this,
                                   2,
                                   (unsigned __int64)(this->phase * 0.1591549430964443 * (double)this->elements)
                                 % this->elements)->T))
               * 0.33333334);
}
void TyreThermalModel::getIMO(TyreThermalModel *this, float *out)
{
  float *v3; // eax
  int v4; // ebx
  int i; // edi
  TyreThermalPatch *v6; // eax
  std::wstring *v7; // esi
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  bool v12; // cf
  float v13; // xmm0_4
  float *v14; // [esp+14h] [ebp-8Ch]
  std::wstring v15; // [esp+18h] [ebp-88h] BYREF
  std::wstring v16; // [esp+30h] [ebp-70h] BYREF
  std::wstring v17; // [esp+48h] [ebp-58h] BYREF
  std::wstring v18; // [esp+60h] [ebp-40h] BYREF
  std::wstring result; // [esp+78h] [ebp-28h] BYREF
  int v20; // [esp+9Ch] [ebp-4h]

  v3 = out;
  v4 = 0;
  v14 = out;
  do
  {
    *v3 = 0.0;
    for ( i = 0; i < 12; ++i )
    {
      if ( v4 < 0 || v4 >= this->stripes || i < 0 || i >= this->elements )
      {
        v7 = std::to_wstring(&result, i);
        v20 = 0;
        v8 = std::to_wstring(&v17, v4);
        LOBYTE(v20) = 1;
        v9 = std::operator+<wchar_t>(&v16, L"ERROR, CANNOT FIND PATCH AT:", v8);
        LOBYTE(v20) = 2;
        v10 = std::operator+<wchar_t>(&v15, v9, L" ");
        LOBYTE(v20) = 3;
        v11 = std::operator+<wchar_t>(&v18, v10, v7);
        v12 = v11->_Myres < 8;
        LOBYTE(v20) = 4;
        if ( !v12 )
          v11 = (std::wstring *)v11->_Bx._Ptr;
        _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v11->_Bx._Buf);
        ksGenerateCrash();
        if ( v18._Myres >= 8 )
          operator delete(v18._Bx._Ptr);
        v18._Myres = 7;
        v18._Mysize = 0;
        v18._Bx._Buf[0] = 0;
        if ( v15._Myres >= 8 )
          operator delete(v15._Bx._Ptr);
        v15._Myres = 7;
        v15._Mysize = 0;
        v15._Bx._Buf[0] = 0;
        if ( v16._Myres >= 8 )
          operator delete(v16._Bx._Ptr);
        v16._Myres = 7;
        v16._Mysize = 0;
        v16._Bx._Buf[0] = 0;
        if ( v17._Myres >= 8 )
          operator delete(v17._Bx._Ptr);
        v17._Myres = 7;
        v17._Mysize = 0;
        v17._Bx._Buf[0] = 0;
        v20 = -1;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Bx._Buf[0] = 0;
        v6 = this->patches._Myfirst;
        result._Mysize = 0;
      }
      else
      {
        v6 = &this->patches._Myfirst[i + v4 * this->elements];
      }
      v13 = v6->T + *v14;
      *v14 = v13;
    }
    ++v4;
    *v14 = v13 * 0.083333336;
    v3 = ++v14;
  }
  while ( v4 < 3 );
}
TyreThermalPatch *TyreThermalModel::getPatchAt(TyreThermalModel *this, int x, int y)
{
  std::wstring *v5; // esi
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  bool v10; // cf
  std::wstring v11; // [esp+10h] [ebp-88h] BYREF
  std::wstring v12; // [esp+28h] [ebp-70h] BYREF
  std::wstring v13; // [esp+40h] [ebp-58h] BYREF
  std::wstring v14; // [esp+58h] [ebp-40h] BYREF
  std::wstring result; // [esp+70h] [ebp-28h] BYREF
  int v16; // [esp+94h] [ebp-4h]

  if ( x >= 0 && x < this->stripes && y >= 0 && y < this->elements )
    return &this->patches._Myfirst[y + x * this->elements];
  v5 = std::to_wstring(&result, y);
  v16 = 0;
  v6 = std::to_wstring(&v13, x);
  LOBYTE(v16) = 1;
  v7 = std::operator+<wchar_t>(&v11, L"ERROR, CANNOT FIND PATCH AT:", v6);
  LOBYTE(v16) = 2;
  v8 = std::operator+<wchar_t>(&v14, v7, L" ");
  LOBYTE(v16) = 3;
  v9 = std::operator+<wchar_t>(&v12, v8, v5);
  v10 = v9->_Myres < 8;
  LOBYTE(v16) = 4;
  if ( !v10 )
    v9 = (std::wstring *)v9->_Bx._Ptr;
  _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v9->_Bx._Buf);
  ksGenerateCrash();
  if ( v12._Myres >= 8 )
    operator delete(v12._Bx._Ptr);
  v12._Myres = 7;
  v12._Mysize = 0;
  v12._Bx._Buf[0] = 0;
  if ( v14._Myres >= 8 )
    operator delete(v14._Bx._Ptr);
  v14._Myres = 7;
  v14._Mysize = 0;
  v14._Bx._Buf[0] = 0;
  if ( v11._Myres >= 8 )
    operator delete(v11._Bx._Ptr);
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  if ( v13._Myres >= 8 )
    operator delete(v13._Bx._Ptr);
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  return this->patches._Myfirst;
}
double TyreThermalModel::getPracticalTemp(TyreThermalModel *this, float camberRAD)
{
  float v3; // [esp+4h] [ebp-4h]
  float camberRADa; // [esp+Ch] [ebp+4h]

  v3 = this->coreTemp;
  camberRADa = TyreThermalModel::getCurrentCPTemp(this, camberRAD);
  return (float)((float)((float)(camberRADa - v3) * 0.25) + v3);
}
void TyreThermalModel::init(TyreThermalModel *this, int a_elements, int a_stripes, Car *car)
{
  this->elements = a_elements;
  this->car = car;
  this->stripes = a_stripes;
  this->phase = 0.0;
  if ( car )
    this->coreTemp = car->ksPhysics->ambientTemperature;
  else
    this->coreTemp = 26.0;
  this->isActive = 1;
  TyreThermalModel::buildTyre(this);
}
void TyreThermalModel::reset(TyreThermalModel *this)
{
  Car *v2; // eax
  TyreThermalPatch *v3; // ecx
  TyreThermalPatch *i; // eax

  v2 = this->car;
  if ( v2 )
    this->coreTemp = v2->ksPhysics->ambientTemperature;
  else
    this->coreTemp = 26.0;
  v3 = this->patches._Mylast;
  for ( i = this->patches._Myfirst; i != v3; ++i )
    i->T = this->coreTemp;
  this->phase = 0.0;
}
void TyreThermalModel::setTemperature(TyreThermalModel *this, float optimumTemp)
{
  TyreThermalPatch *v2; // edx
  TyreThermalPatch *v3; // eax

  v2 = this->patches._Mylast;
  v3 = this->patches._Myfirst;
  for ( this->coreTemp = optimumTemp; v3 != v2; ++v3 )
    v3->T = optimumTemp;
}
void TyreThermalModel::step(TyreThermalModel *this, float dt, float angularSpeed, float camberRAD)
{
  char v4; // bl
  double v6; // xmm0_8
  double v7; // xmm1_8
  Car *v8; // edx
  float *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm0_4
  float *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  TyreThermalPatch *v16; // esi
  float v17; // xmm5_4
  TyreThermalPatch *v18; // ecx
  float v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  TyreThermalPatch **v22; // edx
  int v23; // ebp
  int v24; // ebx
  unsigned int v25; // ebx
  float v26; // xmm2_4
  TyreThermalPatch *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  TyreThermalPatch **v30; // edx
  int v31; // ebp
  int v32; // ebx
  unsigned int v33; // ebx
  float v34; // xmm2_4
  TyreThermalPatch *v35; // eax
  float v36; // xmm2_4
  float v37; // xmm0_4
  float Px; // [esp+14h] [ebp-4h] BYREF
  float dta; // [esp+1Ch] [ebp+4h]

  v4 = 0;
  Px = angularSpeed;
  if ( __fdtest(&Px) > 0 )
    _printf("TyreThermalModel::step: angularSpeed is NaN\n");
  v6 = (float)(dt * angularSpeed) + this->phase;
  this->phase = v6;
  if ( v6 > 100000.0 )
    this->phase = v6 - 100000.0;
  v7 = this->phase;
  if ( v7 < 0.0 )
    this->phase = v7 + 100000.0;
  v8 = this->car;
  v9 = &this->coreTInput;
  if ( v8 )
  {
    v10 = v8->ksPhysics->ambientTemperature;
    if ( v10 <= *v9 )
      v10 = *v9;
    *v9 = v10;
  }
  else
  {
    v11 = *v9;
    v12 = &angularSpeed;
    angularSpeed = 26.0;
    if ( v11 > 26.0 )
      v12 = &this->coreTInput;
    *v9 = *v12;
  }
  v13 = *v9;
  v14 = this->patchData.internalCoreTransfer * dt;
  *v9 = 0.0;
  this->coreTemp = (float)((float)(v13 - this->coreTemp) * v14) + this->coreTemp;
  if ( v8 )
  {
    v4 = 1;
    v15 = Car::getSpeed(v8, (Speed *)&Px)->value;
  }
  else
  {
    v15 = FLOAT_30_0;
  }
  angularSpeed = v15;
  if ( (v4 & 1) != 0 )
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&Px);
  v16 = this->patches._Mylast;
  v17 = dt * this->patchData.patchCoreTransfer;
  v18 = this->patches._Myfirst;
  v19 = (float)((float)((float)((float)(angularSpeed * angularSpeed) * this->patchData.coolFactorGain) + 1.0)
              * this->patchData.surfaceTransfer)
      * dt;
  if ( this->car )
  {
    for ( ; v18 != v16; this->coreTemp = (float)((float)(v28 - this->coreTemp) * v17) + this->coreTemp )
    {
      v20 = v18->inputT;
      v21 = this->car->ksPhysics->ambientTemperature;
      if ( v20 <= v21 )
        v18->T = (float)((float)(v21 - v18->T) * v19) + v18->T;
      else
        v18->T = (float)((float)(v20 - v18->T) * (float)(this->patchData.surfaceTransfer * dt)) + v18->T;
      v22 = v18->connections._Myfirst;
      v23 = 0;
      v24 = (char *)v18->connections._Mylast - (char *)v18->connections._Myfirst;
      v18->inputT = 0.0;
      v25 = (unsigned int)(v24 + 3) >> 2;
      if ( v22 > v18->connections._Mylast )
        v25 = 0;
      if ( v25 )
      {
        v26 = v18->T;
        do
        {
          v27 = *v22;
          ++v23;
          ++v22;
          v26 = v26 + (float)((float)(v27->T - v26) * (float)(dt * this->patchData.patchTransfer));
          v18->T = v26;
        }
        while ( v23 != v25 );
      }
      v28 = (float)((float)(this->coreTemp - v18->T) * v17) + v18->T;
      v18->T = v28;
      ++v18;
    }
  }
  else
  {
    for ( ;
          v18 != v16;
          this->coreTemp = (float)((float)(v36 - this->coreTemp) * (float)(dt * this->patchData.patchCoreTransfer))
                         + this->coreTemp )
    {
      v29 = v18->inputT;
      if ( v29 <= 26.0 )
        v18->T = (float)((float)((float)((float)((float)(this->patchData.coolFactorGain * 300.0) + 1.0)
                                       * this->patchData.surfaceTransfer)
                               * dt)
                       * (float)(26.0 - v18->T))
               + v18->T;
      else
        v18->T = (float)((float)(v29 - v18->T) * (float)(this->patchData.surfaceTransfer * dt)) + v18->T;
      v30 = v18->connections._Myfirst;
      v31 = 0;
      v32 = (char *)v18->connections._Mylast - (char *)v18->connections._Myfirst;
      v18->inputT = 0.0;
      v33 = (unsigned int)(v32 + 3) >> 2;
      if ( v30 > v18->connections._Mylast )
        v33 = 0;
      if ( v33 )
      {
        v34 = v18->T;
        do
        {
          v35 = *v30;
          ++v31;
          ++v30;
          v34 = v34 + (float)((float)(v35->T - v34) * (float)(dt * this->patchData.patchTransfer));
          v18->T = v34;
        }
        while ( v31 != v33 );
      }
      v36 = (float)((float)(this->coreTemp - v18->T) * (float)(dt * this->patchData.patchCoreTransfer)) + v18->T;
      v18->T = v36;
      ++v18;
    }
  }
  if ( this->isActive && Curve::getCount(&this->performanceCurve) > 0 )
  {
    dta = this->coreTemp;
    angularSpeed = TyreThermalModel::getCurrentCPTemp(this, camberRAD);
    v37 = (float)((float)(angularSpeed - dta) * 0.25) + dta;
    this->practicalTemp = v37;
    this->thermalMultD = Curve::getValue(&this->performanceCurve, v37);
  }
}
