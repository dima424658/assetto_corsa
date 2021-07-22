#include "camerafacing.h"
void CameraFacing::CameraFacing(CameraFacing *this, TrackAvatar *track, Sim *sim)
{
  Sim *v4; // ebp
  std::wstring *v5; // eax
  const std::wstring *v6; // eax
  Game *v7; // esi
  int v8; // ebx
  int v9; // eax
  std::wstring *v10; // ecx
  std::wostream *v11; // eax
  const std::wstring *v12; // eax
  bool v13; // al
  char v14; // al
  const std::wstring *v15; // eax
  const std::wstring *v16; // eax
  unsigned int v17; // edi
  const std::wstring *v18; // eax
  const std::wstring *v19; // eax
  const std::wstring *v20; // eax
  const std::wstring *v21; // eax
  const std::wstring *v22; // eax
  const std::wstring *v23; // eax
  const std::wstring *v24; // eax
  Node *v25; // ecx
  Node_vtbl *v26; // eax
  int v27; // eax
  int v28; // eax
  Game *v29; // ecx
  _DWORD *v30; // esi
  StaticParticleSystem *v31; // ebp
  std::wstring *v32; // eax
  int v33; // ebx
  const std::wstring *v34; // eax
  Sim *v35; // edi
  int v36; // eax
  int v37; // ebp
  unsigned int v38; // ebp
  unsigned int v39; // ecx
  Triangle *v40; // ecx
  unsigned int v41; // esi
  int v42; // eax
  float *v43; // edi
  double v44; // st7
  signed int v45; // ebx
  signed int v46; // edi
  float *v47; // esi
  unsigned int v48; // ebx
  float *v49; // esi
  unsigned int v50; // ecx
  unsigned int v51; // ebp
  float v52; // xmm2_4
  int v53; // eax
  float v54; // xmm4_4
  float v55; // xmm7_4
  float v56; // xmm5_4
  float v57; // xmm2_4
  float v58; // xmm6_4
  float v59; // xmm3_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm3_4
  float v64; // xmm4_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm5_4
  float v68; // xmm1_4
  float v69; // xmm2_4
  __int64 v70; // xmm7_8
  __int64 v71; // xmm1_8
  int v72; // edi
  int v73; // eax
  __m128 v74; // xmm2
  unsigned __int64 v75; // xmm0_8
  unsigned int v76; // eax
  std::wstring v77; // [esp-8h] [ebp-304h] BYREF
  Game *v78; // [esp+10h] [ebp-2ECh]
  unsigned int v79; // [esp+2Ch] [ebp-2D0h]
  float v80; // [esp+30h] [ebp-2CCh]
  int v81; // [esp+34h] [ebp-2C8h]
  __int64 v82; // [esp+38h] [ebp-2C4h]
  Sim *v83; // [esp+40h] [ebp-2BCh]
  float v84; // [esp+44h] [ebp-2B8h]
  unsigned int _Count; // [esp+48h] [ebp-2B4h]
  std::vector<float> distribution; // [esp+4Ch] [ebp-2B0h] BYREF
  std::vector<float> areaSoFar; // [esp+58h] [ebp-2A4h] BYREF
  __m128i v88; // [esp+64h] [ebp-298h] BYREF
  int v89; // [esp+74h] [ebp-288h]
  int v90; // [esp+78h] [ebp-284h]
  std::vector<Triangle> triangles; // [esp+7Ch] [ebp-280h] BYREF
  vec2f v92; // [esp+88h] [ebp-274h]
  float v93; // [esp+90h] [ebp-26Ch]
  CameraFacing *v94; // [esp+94h] [ebp-268h]
  float v95; // [esp+98h] [ebp-264h]
  float v96; // [esp+9Ch] [ebp-260h]
  vec2f v97; // [esp+A0h] [ebp-25Ch]
  unsigned int v98; // [esp+A8h] [ebp-254h]
  float v99; // [esp+ACh] [ebp-250h]
  int v100; // [esp+B0h] [ebp-24Ch]
  vec2f size; // [esp+B4h] [ebp-248h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > section; // [esp+BCh] [ebp-240h] BYREF
  vec3f diffuse; // [esp+16Ch] [ebp-190h] BYREF
  vec3f ambient; // [esp+178h] [ebp-184h] BYREF
  CameraFacing *v105; // [esp+184h] [ebp-178h]
  float v106; // [esp+190h] [ebp-16Ch]
  std::wstring key; // [esp+194h] [ebp-168h] BYREF
  std::wstring v108; // [esp+1ACh] [ebp-150h] BYREF
  std::wstring v109; // [esp+1C4h] [ebp-138h] BYREF
  std::wstring v110; // [esp+1DCh] [ebp-120h] BYREF
  std::wstring textureName; // [esp+1F4h] [ebp-108h] BYREF
  std::wstring result; // [esp+20Ch] [ebp-F0h] BYREF
  std::wstring v113; // [esp+224h] [ebp-D8h] BYREF
  INIReader ini; // [esp+23Ch] [ebp-C0h] BYREF
  StaticParticle particle; // [esp+280h] [ebp-7Ch] BYREF
  std::wstring surfaceName; // [esp+2B8h] [ebp-44h] BYREF
  Texture texture; // [esp+2D0h] [ebp-2Ch] BYREF
  int v118; // [esp+2F8h] [ebp-4h]

  v94 = this;
  v4 = sim;
  *(float *)&v79 = 0.0;
  v105 = this;
  v78 = sim->game;
  v83 = sim;
  v77._Myres = 7;
  v77._Mysize = 0;
  v77._Bx._Buf[0] = 0;
  std::wstring::assign(&v77, L"CAMERA_FACING", 0xDu);
  GameObject::GameObject(this, v77, v78);
  v78 = 0;
  v118 = 0;
  this->__vftable = (CameraFacing_vtbl *)&CameraFacing::`vftable';
  _srand((unsigned int)v78);
  v5 = TrackAvatar::getDataFolder(track, &result);
  LOBYTE(v118) = 1;
  v6 = std::operator+<wchar_t>(&v113, v5, L"/data/camera_facing.ini");
  LOBYTE(v118) = 2;
  INIReader::INIReader(&ini, v6);
  if ( v113._Myres >= 8 )
    operator delete(v113._Bx._Ptr);
  v113._Myres = 7;
  v113._Mysize = 0;
  v113._Bx._Buf[0] = 0;
  LOBYTE(v118) = 5;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    *(_DWORD *)section.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    v7 = 0;
    *(_DWORD *)section.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(section.gap68);
    LOBYTE(v118) = 6;
    v8 = 4;
    LODWORD(v82) = 4;
    v79 = 4;
    std::wiostream::basic_iostream<wchar_t>(&section, &section.gap10[8], 0);
    v118 = 7;
    *(_DWORD *)&section.gap0[*(_DWORD *)(*(_DWORD *)section.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&size.y + *(_DWORD *)(*(_DWORD *)section.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)section.gap0 + 4)
                                                                            - 104;
    std::wstreambuf::wstreambuf(&section.gap10[8]);
    *(_DWORD *)&section.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&section.gap10[64] = 0;
    *(_DWORD *)&section.gap10[68] = 0;
    LOBYTE(v118) = 9;
    while ( 1 )
    {
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, word_17BE9D8, 0);
      LOBYTE(v118) = 10;
      if ( (section.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&section.gap10[8]) )
          std::wstreambuf::epptr(&section.gap10[8]);
        else
          std::wstreambuf::egptr(&section.gap10[8]);
        std::wstreambuf::eback(&section.gap10[8]);
        v9 = std::wstreambuf::eback(&section.gap10[8]);
        operator delete(v9);
      }
      std::wstreambuf::setg(&section.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&section.gap10[8], 0, 0);
      v10 = &key;
      *(_DWORD *)&section.gap10[64] = 0;
      v78 = (Game *)(*(_DWORD *)&section.gap10[68] & 0xFFFFFFFE);
      if ( key._Myres >= 8 )
        v10 = (std::wstring *)key._Bx._Ptr;
      *(_DWORD *)&section.gap10[68] &= 0xFFFFFFFE;
      std::wstringbuf::_Init((std::wstringbuf *)&section.gap10[8], v10->_Bx._Buf, key._Mysize, (int)v78);
      LOBYTE(v118) = 9;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v78 = v7;
      v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)section.gap10, "CAMERA_FACING_");
      std::wostream::operator<<(v11, v78);
      v88.m128i_i32[3] = (int)&v7->__vftable + 1;
      v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v110);
      LOBYTE(v118) = 11;
      v13 = INIReader::hasSection(&ini, v12);
      LOBYTE(v118) = 9;
      v14 = !v13;
      HIBYTE(v81) = v14;
      if ( v110._Myres >= 8 )
      {
        operator delete(v110._Bx._Ptr);
        v14 = HIBYTE(v81);
      }
      if ( v14 )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"SURFACE", 7u);
      LOBYTE(v118) = 12;
      v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v108);
      LOBYTE(v118) = 13;
      INIReader::getString(&ini, &surfaceName, v15, &key);
      if ( v108._Myres >= 8 )
        operator delete(v108._Bx._Ptr);
      v108._Myres = 7;
      v108._Mysize = 0;
      v108._Bx._Buf[0] = 0;
      LOBYTE(v118) = 16;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      std::wstring::assign(&v109, L"ELEMENTS", 8u);
      LOBYTE(v118) = 17;
      v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v110);
      LOBYTE(v118) = 18;
      *(float *)&v17 = COERCE_FLOAT(INIReader::getInt(&ini, v16, &v109));
      _Count = v17;
      if ( v110._Myres >= 8 )
        operator delete(v110._Bx._Ptr);
      v110._Myres = 7;
      v110._Mysize = 0;
      v110._Bx._Buf[0] = 0;
      LOBYTE(v118) = 16;
      if ( v109._Myres >= 8 )
        operator delete(v109._Bx._Ptr);
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      std::wstring::assign(&v109, L"SIZE", 4u);
      LOBYTE(v118) = 19;
      v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v110);
      LOBYTE(v118) = 20;
      INIReader::getFloat2(&ini, &size, v18, &v109);
      if ( v110._Myres >= 8 )
        operator delete(v110._Bx._Ptr);
      v110._Myres = 7;
      v110._Mysize = 0;
      v110._Bx._Buf[0] = 0;
      LOBYTE(v118) = 16;
      if ( v109._Myres >= 8 )
        operator delete(v109._Bx._Ptr);
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      std::wstring::assign(&v109, L"TEXTURE", 7u);
      LOBYTE(v118) = 21;
      v19 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v110);
      LOBYTE(v118) = 22;
      INIReader::getString(&ini, &textureName, v19, &v109);
      if ( v110._Myres >= 8 )
        operator delete(v110._Bx._Ptr);
      v110._Myres = 7;
      v110._Mysize = 0;
      v110._Bx._Buf[0] = 0;
      LOBYTE(v118) = 25;
      if ( v109._Myres >= 8 )
        operator delete(v109._Bx._Ptr);
      v109._Myres = 7;
      v109._Mysize = 0;
      v109._Bx._Buf[0] = 0;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"TEXTURE_ROWS", 0xCu);
      LOBYTE(v118) = 26;
      v20 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v108);
      LOBYTE(v118) = 27;
      v90 = INIReader::getInt(&ini, v20, &key);
      if ( v108._Myres >= 8 )
        operator delete(v108._Bx._Ptr);
      v108._Myres = 7;
      v108._Mysize = 0;
      v108._Bx._Buf[0] = 0;
      LOBYTE(v118) = 25;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"TEXTURE_COLUMNS", 0xFu);
      LOBYTE(v118) = 28;
      v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v108);
      LOBYTE(v118) = 29;
      v89 = INIReader::getInt(&ini, v21, &key);
      if ( v108._Myres >= 8 )
        operator delete(v108._Bx._Ptr);
      v108._Myres = 7;
      v108._Mysize = 0;
      v108._Bx._Buf[0] = 0;
      LOBYTE(v118) = 25;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"SHADED", 6u);
      LOBYTE(v118) = 30;
      v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v108);
      LOBYTE(v118) = 31;
      INIReader::getInt(&ini, v22, &key);
      if ( v108._Myres >= 8 )
        operator delete(v108._Bx._Ptr);
      v108._Myres = 7;
      v108._Mysize = 0;
      v108._Bx._Buf[0] = 0;
      LOBYTE(v118) = 25;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"DIFFUSE", 7u);
      LOBYTE(v118) = 32;
      v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v108);
      LOBYTE(v118) = 33;
      INIReader::getFloat3(&ini, &diffuse, v23, &key);
      if ( v108._Myres >= 8 )
        operator delete(v108._Bx._Ptr);
      v108._Myres = 7;
      v108._Mysize = 0;
      v108._Bx._Buf[0] = 0;
      LOBYTE(v118) = 25;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"AMBIENT", 7u);
      LOBYTE(v118) = 34;
      v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &v108);
      LOBYTE(v118) = 35;
      INIReader::getFloat3(&ini, &ambient, v24, &key);
      if ( v108._Myres >= 8 )
        operator delete(v108._Bx._Ptr);
      v108._Myres = 7;
      v108._Mysize = 0;
      v108._Bx._Buf[0] = 0;
      LOBYTE(v118) = 25;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v25 = v4->trackNode;
      v78 = 0;
      v77._Myres = (unsigned int)&Mesh `RTTI Type Descriptor';
      v77._Mysize = (unsigned int)&Node `RTTI Type Descriptor';
      v26 = v25->__vftable;
      *(_DWORD *)&v77._Bx._Alias[12] = 0;
      v27 = (int)v26->findChildByName(v25, &surfaceName, 1);
      v28 = __RTDynamicCast(v27, *(_DWORD *)&v77._Bx._Alias[12], v77._Mysize, v77._Myres, v78);
      v29 = v4->game;
      v30 = (_DWORD *)v28;
      HIDWORD(v82) = v28;
      ResourceStore::getTexture(v29->graphics->resourceStore._Myptr, &texture, &textureName, 0);
      LOBYTE(v118) = 36;
      *(float *)&v31 = COERCE_FLOAT(operator new(324));
      v84 = *(float *)&v31;
      LOBYTE(v118) = 37;
      if ( *(float *)&v31 == 0.0 )
      {
        v35 = v83;
        v37 = 0;
      }
      else
      {
        v32 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&section, &key);
        LOBYTE(v118) = 38;
        v33 = v8 | 1;
        v79 = v33;
        v34 = std::operator+<wchar_t>(&v108, L"CF_PARTICLES_", v32);
        v118 = 39;
        v78 = (Game *)&texture;
        v77._Myres = v17;
        v35 = v83;
        v8 = v33 | 2;
        LODWORD(v82) = v8;
        v79 = v8;
        StaticParticleSystem::StaticParticleSystem(v31, v34, v83->game->graphics, v77._Myres, &texture);
        v37 = v36;
      }
      v88.m128i_i32[2] = v37;
      if ( (v8 & 2) != 0 )
      {
        v8 &= 0xFFFFFFFD;
        LODWORD(v82) = v8;
        if ( v108._Myres >= 8 )
          operator delete(v108._Bx._Ptr);
        v108._Myres = 7;
        v108._Mysize = 0;
        v108._Bx._Buf[0] = 0;
      }
      v118 = 36;
      if ( (v8 & 1) != 0 )
      {
        LODWORD(v82) = v8 & 0xFFFFFFFE;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
      }
      v35->blurredNode->addChild(v35->blurredNode, (Node *)v37);
      *(_DWORD *)(v37 + 196) = 2;
      *(_DWORD *)(v37 + 200) = 0;
      *(vec3f *)(v37 + 204) = diffuse;
      *(vec3f *)(v37 + 216) = ambient;
      *(_DWORD *)(v37 + 228) = v30[52];
      std::vector<Triangle>::vector<Triangle>(&triangles, ((v30[60] - v30[59]) >> 1) / 3u);
      LOBYTE(v118) = 42;
      std::vector<float>::vector<float>(&areaSoFar, triangles._Mylast - triangles._Myfirst);
      v38 = 0;
      v39 = (v30[60] - v30[59]) >> 1;
      LOBYTE(v118) = 43;
      if ( v39 / 3 )
      {
        do
        {
          Triangle::Triangle(
            (Triangle *)&particle,
            (const vec3f *)(v30[56] + 44 * *(unsigned __int16 *)(v30[59] + 6 * v38)),
            (const vec3f *)(v30[56] + 44 * *(unsigned __int16 *)(v30[59] + 6 * v38 + 2)),
            (const vec3f *)(v30[56] + 44 * *(unsigned __int16 *)(v30[59] + 6 * v38 + 4)));
          v40 = triangles._Myfirst;
          v41 = v38;
          *(_QWORD *)&triangles._Myfirst[v41].points[0].x = *(_QWORD *)(v42 + 4);
          v40[v41].points[0].z = *(float *)(v42 + 12);
          *(_QWORD *)&v40[v41].points[1].x = *(_QWORD *)(v42 + 16);
          v40[v41].points[1].z = *(float *)(v42 + 24);
          *(_QWORD *)&v40[v41].points[2].x = *(_QWORD *)(v42 + 28);
          v40[v41].points[2].z = *(float *)(v42 + 36);
          v40[v41].plane = (plane4f)_mm_loadu_si128((const __m128i *)(v42 + 40));
          Triangle::~Triangle((Triangle *)&particle);
          v43 = areaSoFar._Myfirst;
          if ( v38 )
            v80 = areaSoFar._Myfirst[v38 - 1];
          else
            v80 = 0.0;
          v44 = Triangle::computeArea(&triangles._Myfirst[v38]);
          v30 = (_DWORD *)HIDWORD(v82);
          v43[v38++] = v44 + v80;
        }
        while ( v38 < ((v30[60] - v30[59]) >> 1) / 3u );
      }
      v45 = _Count;
      v78 = (Game *)_Count;
      v80 = *(areaSoFar._Mylast - 1);
      std::vector<float>::vector<float>(&distribution, _Count);
      v46 = 0;
      for ( LOBYTE(v118) = 44; v46 < v45; ++v46 )
      {
        v47 = distribution._Myfirst;
        v47[v46] = (float)_rand() * 0.000030518509;
      }
      LOBYTE(v100) = 0;
      std::_Sort<float *,int,std::less<void>>(
        distribution._Myfirst,
        distribution._Mylast,
        distribution._Mylast - distribution._Myfirst,
        0);
      v48 = 0;
      v49 = distribution._Myfirst;
      HIDWORD(v82) = 0;
      v50 = (unsigned int)((char *)distribution._Mylast - (char *)distribution._Myfirst + 3) >> 2;
      if ( distribution._Myfirst > distribution._Mylast )
        v50 = 0;
      v98 = v50;
      if ( v50 )
      {
        v51 = 0;
        v52 = 1.0 / v80;
        v99 = 1.0 / (float)v89;
        v84 = 1.0 / v80;
        v93 = 1.0 / (float)v90;
        do
        {
          if ( *v49 >= (float)(areaSoFar._Myfirst[v51] * v52) )
          {
            do
            {
              if ( v48 >= areaSoFar._Mylast - areaSoFar._Myfirst - 1 )
                break;
              v51 = ++v48;
            }
            while ( *v49 >= (float)(areaSoFar._Myfirst[v48] * v52) );
          }
          *(float *)&_Count = (float)_rand() * 0.000030518509;
          v53 = _rand();
          v54 = triangles._Myfirst[v48].points[0].x;
          v55 = (float)v53 * 0.000030518509;
          v56 = triangles._Myfirst[v48].points[0].y;
          v57 = triangles._Myfirst[v48].points[1].x - v54;
          v58 = triangles._Myfirst[v48].points[0].z;
          v59 = triangles._Myfirst[v48].points[1].y - v56;
          v60 = triangles._Myfirst[v48].points[1].z - v58;
          v88.m128i_i64[0] = LODWORD(v54);
          v61 = v55 * v57;
          v62 = v55 * v59;
          v63 = v55 * v60;
          v64 = v54 + v61;
          v65 = triangles._Myfirst[v48].points[2].x - *(float *)v88.m128i_i32;
          v66 = triangles._Myfirst[v48].points[2].y;
          *(float *)&v79 = v56;
          v67 = v56 + v62;
          v68 = (float)(v66 - *(float *)&v79) * v55;
          v69 = (float)(triangles._Myfirst[v48].points[2].z - v58) * v55;
          HIDWORD(v70) = v88.m128i_i32[1];
          *(float *)&v70 = *(float *)v88.m128i_i32 + (float)(v65 * v55);
          v88.m128i_i64[0] = v70;
          *(float *)&v70 = *(float *)&v79 + v68;
          HIDWORD(v71) = v88.m128i_i32[1];
          *(float *)&v71 = (float)((float)(*(float *)v88.m128i_i32 - v64) * *(float *)&_Count) + v64;
          v80 = (float)((float)((float)(v58 + v69) - (float)(v58 + v63)) * *(float *)&_Count) + (float)(v58 + v63);
          v88.m128i_i64[0] = v71;
          *(float *)&v79 = (float)((float)(*(float *)&v70 - v67) * *(float *)&_Count) + v67;
          v72 = _rand() % v90;
          v73 = _rand();
          v74 = (__m128)v79;
          v74.m128_f32[0] = *(float *)&v79 + (float)(size.y * 0.5);
          v75 = _mm_unpacklo_ps((__m128)_mm_loadl_epi64(&v88), v74).m128_u64[0];
          v106 = v80;
          *(_QWORD *)&particle.position.x = v75;
          particle.position.z = v80;
          v96 = size.y * 0.5;
          v97.x = (float)(v73 % v89) * v99;
          v97.y = (float)(v73 % v89 + 1) * v99;
          particle.uRange = v97;
          v92.x = (float)v72 * v93;
          v92.y = (float)(v72 + 1) * v93;
          particle.vRange = v92;
          v95 = size.x * 0.5;
          particle.halfSize.x = size.x * 0.5;
          particle.halfSize.y = size.y * 0.5;
          StaticParticleSystem::addParticle((StaticParticleSystem *)v88.m128i_i32[2], &particle);
          ++v49;
          v52 = v84;
          ++HIDWORD(v82);
        }
        while ( HIDWORD(v82) != v98 );
        v49 = distribution._Myfirst;
      }
      LOBYTE(v118) = 43;
      if ( v49 )
      {
        std::_Container_base0::_Orphan_all(&distribution);
        operator delete(distribution._Myfirst);
        distribution._Myfirst = 0;
        distribution._Mylast = 0;
        distribution._Myend = 0;
      }
      LOBYTE(v118) = 42;
      if ( areaSoFar._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&areaSoFar);
        operator delete(areaSoFar._Myfirst);
        areaSoFar._Myfirst = 0;
        areaSoFar._Mylast = 0;
        areaSoFar._Myend = 0;
      }
      LOBYTE(v118) = 36;
      std::vector<Triangle>::_Tidy(&triangles);
      LOBYTE(v118) = 25;
      OnSetupAppCreated::~OnSetupAppCreated(&texture);
      if ( textureName._Myres >= 8 )
        operator delete(textureName._Bx._Ptr);
      v8 = v82;
      v4 = v83;
      v7 = (Game *)v88.m128i_i32[3];
      textureName._Myres = 7;
      textureName._Mysize = 0;
      textureName._Bx._Buf[0] = 0;
      LOBYTE(v118) = 9;
      if ( surfaceName._Myres >= 8 )
        operator delete(surfaceName._Bx._Ptr);
    }
    v76 = GetTickCount64();
    _srand(v76);
    LOBYTE(v118) = 5;
    *(_DWORD *)&section.gap0[*(_DWORD *)(*(_DWORD *)section.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&size.y + *(_DWORD *)(*(_DWORD *)section.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)section.gap0 + 4)
                                                                            - 104;
    *(_DWORD *)&section.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&section.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&section.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&section.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(section.gap68);
    LOBYTE(v118) = 0;
    INIReader::~INIReader(&ini);
  }
  else
  {
    LOBYTE(v118) = 0;
    INIReader::~INIReader(&ini);
  }
}
