#include "microsectors.h
void __userpurge MicroSectors::MicroSectors(MicroSectors *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  std::_Tree_node<std::pair<int const ,CarPerformance>,void *> *v4; // eax
  char v5; // bl
  int v6; // eax
  bool v7; // cf
  std::wstring v8; // [esp-1Ch] [ebp-B8h] BYREF
  Game *v9; // [esp-4h] [ebp-A0h]
  MicroSectors *v10; // [esp+14h] [ebp-88h]
  std::wstring section; // [esp+18h] [ebp-84h] BYREF
  std::wstring key; // [esp+30h] [ebp-6Ch] BYREF
  INIReaderDocuments acINI; // [esp+48h] [ebp-54h] BYREF
  int v14; // [esp+98h] [ebp-4h]

  v10 = this;
  v9 = aSim->game;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, L"MICRO_SECTORS", 0xDu);
  GameObject::GameObject(this, v8, v9);
  this->__vftable = (MicroSectors_vtbl *)&MicroSectors::`vftable';
  this->sim = aSim;
  v14 = 0;
  this->cars._Myhead = 0;
  this->cars._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<int const,CarPerformance>>>::_Buyheadnode(&this->cars);
  this->cars._Myhead = v4;
  this->bestSectors._Myfirst = 0;
  this->bestSectors._Mylast = 0;
  this->bestSectors._Myend = 0;
  v9 = 0;
  this->enabled = 0;
  LOBYTE(v14) = 2;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, L"cfg/gameplay.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&acINI, a2, v8, (bool)v9);
  LOBYTE(v14) = 3;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SHOW_SECTORS", 0xCu);
  LOBYTE(v14) = 4;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"GUI", 3u);
  LOBYTE(v14) = 5;
  v5 = INIReader::hasKey(&acINI, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v14) = 3;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v5 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SHOW_SECTORS", 0xCu);
    LOBYTE(v14) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GUI", 3u);
    LOBYTE(v14) = 7;
    v6 = INIReader::getInt(&acINI, &section, &key);
    v7 = section._Myres < 8;
    this->enabled = v6 != 0;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v14) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( this->enabled )
    std::vector<BestSector>::resize(&this->bestSectors, 0x18u);
  LOBYTE(v14) = 2;
  INIReaderDocuments::~INIReaderDocuments(&acINI);
}
void MicroSectors::~MicroSectors(MicroSectors *this)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const ,CarPerformance> > > > result; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (MicroSectors_vtbl *)&MicroSectors::`vftable';
  if ( this->bestSectors._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->bestSectors);
    operator delete(this->bestSectors._Myfirst);
    this->bestSectors._Myfirst = 0;
    this->bestSectors._Mylast = 0;
    this->bestSectors._Myend = 0;
  }
  std::_Tree<std::_Tmap_traits<int,CarPerformance,std::less<int>,std::allocator<std::pair<int const,CarPerformance>>,0>>::erase(
    &this->cars,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const ,CarPerformance> > > >)this->cars._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const ,CarPerformance> > > >)this->cars._Myhead);
  operator delete(this->cars._Myhead);
  GameObject::~GameObject(this);
}
MicroSectors *MicroSectors::`vector deleting destructor'(MicroSectors *this, unsigned int a2)
{
  MicroSectors::~MicroSectors(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void MicroSectors::drawSectors(MicroSectors *this, GLRenderer *gl, int guid, float x, float y, float cellWidth, float cellHeight, vec4f backColor)
{
  MicroSectors *v8; // ebx
  int v9; // esi
  SectorData *v10; // edi
  int v11; // ebx
  float v12; // xmm3_4
  int v13; // ebp
  float v14; // xmm2_4
  float v15; // xmm4_4
  float width; // xmm1_4
  int v17; // ecx
  GLRenderer *v18; // edi
  float v19; // [esp+2Ch] [ebp-24h]
  float v20; // [esp+30h] [ebp-20h]
  std::vector<SectorData> sectors; // [esp+38h] [ebp-18h] BYREF
  int v23; // [esp+4Ch] [ebp-4h]
  float ya; // [esp+60h] [ebp+10h]
  float cellHeighta; // [esp+68h] [ebp+18h]

  v8 = this;
  if ( this->enabled )
  {
    v9 = 0;
    v19 = FLOAT_1_0;
    v20 = (float)(cellWidth - 1.0) * 0.03846154;
    GLRenderer::color4f(gl, &backColor);
    GLRenderer::quad(gl, x, y + 1.0, cellWidth, cellHeight - 1.0, 0, 0);
    cellHeighta = cellHeight - 5.0;
    MicroSectors::getSectorsPerformance(v8, &sectors, guid);
    v10 = sectors._Myfirst;
    v11 = 0;
    v23 = 0;
    if ( sectors._Mylast - sectors._Myfirst )
    {
      v12 = (float)(cellWidth - 1.0) * 0.03846154;
      v13 = 0;
      v14 = FLOAT_1_0;
      v15 = y + 3.0;
      width = v20 - 1.0;
      ya = y + 3.0;
      do
      {
        v17 = v10[v13].performance;
        if ( this->bestSectors._Myfirst[v11].idCar == guid )
          v17 = 2;
        switch ( v17 )
        {
          case 0:
            v18 = gl;
            GLRenderer::color4f(gl, 0.1, 0.1, 0.1, 0.0);
            v14 = v19;
            v12 = (float)(cellWidth - 1.0) * 0.03846154;
            width = v20 - 1.0;
            v15 = ya;
            break;
          case 1:
            v18 = gl;
            GLRenderer::color4f(gl, 0.60000002, 0.60000002, 0.60000002, 0.69999999);
            v14 = v19;
            v12 = (float)(cellWidth - 1.0) * 0.03846154;
            width = v20 - 1.0;
            v15 = ya;
            break;
          case 2:
            v18 = gl;
            GLRenderer::color4f(gl, 0.80000001, 0.0, 0.80000001, 0.69999999);
            v14 = v19;
            v12 = (float)(cellWidth - 1.0) * 0.03846154;
            width = v20 - 1.0;
            v15 = ya;
            break;
          case 3:
            v18 = gl;
            GLRenderer::color4f(gl, 0.0, 0.80000001, 0.0, 0.69999999);
            v14 = v19;
            v12 = (float)(cellWidth - 1.0) * 0.03846154;
            width = v20 - 1.0;
            v15 = ya;
            break;
          default:
            v18 = gl;
            break;
        }
        if ( (float)v9 >= 8.0 )
        {
          v14 = v14 + v12;
          v9 = 0;
          v19 = v14;
        }
        ++v9;
        GLRenderer::quad(v18, (float)((float)v11 * v12) + (float)(v14 + x), v15, width, cellHeighta, 0, 0);
        v10 = sectors._Myfirst;
        ++v11;
        v14 = v19;
        v12 = (float)(cellWidth - 1.0) * 0.03846154;
        ++v13;
        width = v20 - 1.0;
        v15 = ya;
      }
      while ( v11 < (unsigned int)(sectors._Mylast - sectors._Myfirst) );
    }
    v23 = -1;
    if ( v10 )
    {
      std::_Container_base0::_Orphan_all(&sectors);
      operator delete(sectors._Myfirst);
    }
  }
}
std::vector<SectorData> *MicroSectors::getSectorsPerformance(MicroSectors *this, std::vector<SectorData> *result, int carId)
{
  std::_Tree_node<std::pair<int const ,CarPerformance>,void *> *v4; // edi
  std::_Tree_node<std::pair<int const ,CarPerformance>,void *> *v5; // edx
  std::_Tree_node<std::pair<int const ,CarPerformance>,void *> *v6; // eax
  std::vector<SectorData> *v7; // eax
  std::_Tree_node<std::pair<int const ,CarPerformance>,void *> *carIda; // [esp+14h] [ebp+8h]

  v4 = this->cars._Myhead;
  v5 = v4;
  v6 = v4->_Parent;
  while ( !v6->_Isnil )
  {
    if ( v6->_Myval.first >= carId )
    {
      v5 = v6;
      v6 = v6->_Left;
    }
    else
    {
      v6 = v6->_Right;
    }
  }
  if ( v5 == v4 || (carIda = v5, carId < v5->_Myval.first) )
    carIda = this->cars._Myhead;
  if ( carIda == v4 )
  {
    v7 = result;
    result->_Myfirst = 0;
    result->_Mylast = 0;
    result->_Myend = 0;
  }
  else
  {
    std::vector<SectorData>::vector<SectorData>(result, &carIda->_Myval.second.sectors);
    v7 = result;
  }
  return v7;
}
void MicroSectors::initialize(MicroSectors *this)
{
  unsigned int v2; // ecx

  std::_Tree<std::_Tmap_traits<int,CarPerformance,std::less<int>,std::allocator<std::pair<int const,CarPerformance>>,0>>::_Erase(
    &this->cars,
    this->cars._Myhead->_Parent);
  v2 = 0;
  this->cars._Myhead->_Parent = this->cars._Myhead;
  this->cars._Myhead->_Left = this->cars._Myhead;
  this->cars._Myhead->_Right = this->cars._Myhead;
  for ( this->cars._Mysize = 0; v2 < this->bestSectors._Mylast - this->bestSectors._Myfirst; ++v2 )
  {
    this->bestSectors._Myfirst[v2].best = 3.4028235e38;
    this->bestSectors._Myfirst[v2].idCar = -1;
  }
}
void MicroSectors::update(MicroSectors *this, float deltaT)
{
  Sim *v3; // ecx
  unsigned int v4; // edx
  CarAvatar *v5; // esi
  float v6; // xmm4_4
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm0
  float v10; // xmm2_4
  int v11; // edi
  int v12; // edi
  std::_Tree_node<std::pair<enum DWRITE_RENDERING_MODE const ,IDWriteRenderingParams *>,void *> *v13; // esi
  int v14; // eax
  DWRITE_RENDERING_MODE v15; // edi
  int v16; // ecx
  int j; // edx
  BestSector *v18; // eax
  std::_Tree_node<std::pair<enum DWRITE_RENDERING_MODE const ,IDWriteRenderingParams *>,void *> *v19; // edx
  float v20; // xmm1_4
  BestSector *v21; // eax
  int v22; // edx
  int v23; // ecx
  std::_Tree_node<std::pair<int const ,CarPerformance>,void *> *v24; // eax
  DWRITE_RENDERING_MODE _Keyval; // [esp+10h] [ebp-58h] BYREF
  int v26; // [esp+14h] [ebp-54h]
  CarAvatar *v27; // [esp+18h] [ebp-50h]
  unsigned int i; // [esp+1Ch] [ebp-4Ch]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<enum DWRITE_RENDERING_MODE const ,IDWriteRenderingParams *> > > > result[2]; // [esp+20h] [ebp-48h] BYREF
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const ,CarPerformance> > > >,bool> v30; // [esp+28h] [ebp-40h] BYREF
  char v31; // [esp+30h] [ebp-38h]
  __int128 v32; // [esp+34h] [ebp-34h] BYREF
  std::pair<int,CarPerformance> v33; // [esp+44h] [ebp-24h] BYREF
  int v34; // [esp+64h] [ebp-4h]

  if ( this->enabled )
  {
    *(double *)&result[0]._Ptr = RaceManager::getTimeToSessionStart(this->sim->raceManager);
    if ( *(double *)&result[0]._Ptr <= 0.0 )
    {
      v3 = this->sim;
      v4 = 0;
      for ( i = 0; v4 < v3->cars._Mylast - v3->cars._Myfirst; i = v4 )
      {
        v5 = Sim::getCar(v3, v4);
        v27 = v5;
        if ( !CarAvatar::isInPit(v5) )
        {
          _Keyval = CarAvatar::getGuid(v5);
          std::_Tree<std::_Tmap_traits<enum SessionType,ReplayAutosave,std::less<enum SessionType>,std::allocator<std::pair<enum SessionType const,ReplayAutosave>>,0>>::find(
            (std::_Tree<std::_Tmap_traits<enum DWRITE_RENDERING_MODE,IDWriteRenderingParams *,std::less<enum DWRITE_RENDERING_MODE>,std::allocator<std::pair<enum DWRITE_RENDERING_MODE const ,IDWriteRenderingParams *> >,0> > *)&this->cars,
            result,
            &_Keyval);
          v6 = v5->physicsState.normalizedSplinePosition * 24.0;
          v7.m128_f32[0] = FLOAT_8388608_0;
          v8.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v6);
          v9.m128_i32[0] = LODWORD(v6) ^ LODWORD(FLOAT_N0_0) & LODWORD(v6);
          v9.m128_f32[0] = _mm_cmplt_ss(v9, v7).m128_f32[0];
          v10 = (float)(v6 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v9.m128_i32[0] | v8.m128_i32[0]))
              - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v9.m128_i32[0] | v8.m128_i32[0]);
          v9.m128_f32[0] = v10 - v6;
          v11 = (int)(float)(v10 - COERCE_FLOAT(_mm_cmpgt_ss(v9, v8).m128_u32[0] & LODWORD(FLOAT_1_0)));
          if ( v11 )
            v12 = v11 - 1;
          else
            v12 = 23;
          v26 = v12;
          v31 = 0;
          v32 = 0i64;
          v13 = result[0]._Ptr;
          v34 = 0;
          if ( result[0]._Ptr == (std::_Tree_node<std::pair<enum DWRITE_RENDERING_MODE const ,IDWriteRenderingParams *>,void *> *)this->cars._Myhead )
          {
            std::vector<SectorData>::resize((std::vector<SectorData> *)((char *)&v32 + 4), 0x18u);
            v23 = v12 + 1;
            if ( v12 + 1 > 24 )
              v23 = 0;
            v33.first = _Keyval;
            v33.second.started = v31;
            LODWORD(v32) = v23;
            v33.second.sectorStarted = v23;
            std::vector<SectorData>::vector<SectorData>(
              &v33.second.sectors,
              (const std::vector<SectorData> *)((char *)&v32 + 4));
            LOBYTE(v34) = 1;
            v24 = (std::_Tree_node<std::pair<int const ,CarPerformance>,void *> *)std::_Tree_buy<std::pair<int const,CarPerformance>>::_Buynode<std::pair<int,CarPerformance>>(
                                                                                    &this->cars,
                                                                                    &v33);
            std::_Tree<std::_Tmap_traits<int,CarPerformance,std::less<int>,std::allocator<std::pair<int const,CarPerformance>>,0>>::_Insert_nohint<std::pair<int const,CarPerformance> &,std::_Tree_node<std::pair<int const,CarPerformance>,void *> *>(
              &this->cars,
              &v30,
              0,
              &v24->_Myval,
              v24);
            LOBYTE(v34) = 0;
            if ( v33.second.sectors._Myfirst )
            {
              std::_Container_base0::_Orphan_all(&v33.second.sectors);
              operator delete(v33.second.sectors._Myfirst);
            }
          }
          else
          {
            v31 = (char)result[0]._Ptr->_Myval.second;
            LODWORD(v32) = result[0]._Ptr[1]._Left;
            std::vector<SectorData>::operator=(
              (std::vector<SectorData> *)((char *)&v32 + 4),
              (const std::vector<SectorData> *)&result[0]._Ptr[1]._Parent);
            if ( LOBYTE(v13->_Myval.second)
              || (v14 = (int)v13[1]._Left, v12 <= v14) && ((float)v12 >= 12.0 || (float)v14 <= 12.0) )
            {
              if ( !v12 && v13[1]._Parent[6]._Right )
              {
                v15 = _Keyval;
                v16 = 0;
                for ( j = 0; j < 288; j += 12 )
                {
                  *(std::_Tree_node<std::pair<enum DWRITE_RENDERING_MODE const ,IDWriteRenderingParams *>,void *> **)((char *)&v13[1]._Parent->_Right + j) = 0;
                  v18 = this->bestSectors._Myfirst;
                  if ( v18[v16].idCar == v15 )
                    v18[v16].idCar = -1;
                  ++v16;
                }
                v12 = v26;
              }
            }
            else
            {
              LOBYTE(v13->_Myval.second) = 1;
            }
            v19 = v13[1]._Parent;
            if ( !*((_DWORD *)&v19->_Right + 3 * v12) && LOBYTE(v13->_Myval.second) )
            {
              v20 = (float)v27->physicsState.lapTime;
              if ( v12 > 0 )
                v20 = v20 - *((float *)v19 + 3 * v12 - 2);
              if ( *((float *)&v19->_Left + 3 * v12) <= v20 )
              {
                *((_DWORD *)&v19->_Right + 3 * v12) = 1;
              }
              else
              {
                *((float *)&v19->_Left + 3 * v12) = v20;
                *((_DWORD *)&v13[1]._Parent->_Right + 3 * v12) = 3;
                v21 = this->bestSectors._Myfirst;
                if ( v21[v12].best > v20 )
                {
                  v22 = _Keyval;
                  v21[v12].best = v20;
                  this->bestSectors._Myfirst[v12].idCar = v22;
                }
              }
              *((float *)&v13[1]._Parent->_Parent + 3 * v12) = (float)v27->physicsState.lapTime;
            }
          }
          v34 = -1;
          if ( DWORD1(v32) )
          {
            std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v32 + 4);
            operator delete(DWORD1(v32));
          }
        }
        v3 = this->sim;
        v4 = i + 1;
      }
    }
  }
}
