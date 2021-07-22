#include "shapebuilder.h
Mesh *__cdecl ShapeBuilder::buildHemiSphere(float radius, int subs, std::wstring name)
{
  Mesh *v3; // esi
  int v4; // eax
  int v5; // edi
  int v6; // ecx
  int v7; // xmm2_4
  float v8; // xmm3_4
  int v9; // eax
  int v10; // esi
  float v11; // xmm1_4
  __int64 v12; // xmm0_8
  int v13; // esi
  __m128 v14; // xmm1
  std::vector<MeshVertex> *v15; // edi
  unsigned int v16; // ecx
  __m128 v17; // xmm1
  int v18; // esi
  MeshVertex *v19; // ecx
  const MeshVertex *v20; // eax
  float v21; // eax
  MeshVertex *v22; // eax
  int v23; // esi
  MeshVertex *v24; // ecx
  const MeshVertex *v25; // eax
  float v26; // eax
  MeshVertex *v27; // eax
  int v28; // esi
  MeshVertex *v29; // ecx
  const MeshVertex *v30; // eax
  float v31; // eax
  MeshVertex *v32; // eax
  int v33; // esi
  MeshVertex *v34; // ecx
  const MeshVertex *v35; // eax
  int v36; // edx
  int v37; // ecx
  MeshVertex *v38; // esi
  float v39; // eax
  float v40; // xmm0_4
  float v41; // ecx
  float v42; // xmm0_4
  bool v43; // zf
  int v44; // eax
  int v45; // ecx
  int v46; // edx
  std::vector<unsigned short> *v47; // edi
  unsigned __int16 *v48; // ecx
  unsigned __int16 v49; // si
  unsigned __int16 *v50; // edx
  int v51; // esi
  int v52; // ecx
  unsigned int v53; // edx
  unsigned int v54; // edx
  unsigned __int16 *v55; // ecx
  unsigned __int16 *v56; // edx
  int v57; // ecx
  unsigned int v58; // edx
  unsigned int v59; // edx
  unsigned __int16 *v60; // eax
  unsigned __int16 v61; // si
  unsigned __int16 *v62; // ecx
  unsigned __int16 *v63; // edx
  int v64; // esi
  int v65; // ecx
  unsigned int v66; // edx
  unsigned int v67; // edx
  unsigned __int16 *v68; // ecx
  unsigned __int16 *v69; // edx
  int v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edx
  unsigned __int16 *v73; // eax
  int v74; // eax
  unsigned __int16 *v75; // ecx
  unsigned __int16 v76; // si
  unsigned __int16 *v77; // edx
  int v78; // esi
  int v79; // ecx
  unsigned int v80; // edx
  unsigned int v81; // edx
  unsigned __int16 *v82; // ecx
  unsigned __int16 *v83; // edx
  int v84; // ecx
  unsigned int v85; // edx
  unsigned int v86; // edx
  unsigned __int16 *v87; // eax
  unsigned __int16 v88; // si
  unsigned __int16 *v89; // ecx
  unsigned __int16 *v90; // edx
  int v91; // esi
  int v92; // ecx
  unsigned int v93; // edx
  unsigned int v94; // edx
  unsigned __int16 *v95; // ecx
  unsigned __int16 *v96; // edx
  int v97; // ecx
  unsigned int v98; // edx
  unsigned int v99; // edx
  unsigned __int16 *v100; // eax
  int v101; // eax
  unsigned __int16 *v102; // ecx
  unsigned __int16 v103; // si
  unsigned __int16 *v104; // edx
  int v105; // esi
  int v106; // ecx
  unsigned int v107; // edx
  unsigned int v108; // edx
  unsigned __int16 *v109; // ecx
  unsigned __int16 *v110; // edx
  int v111; // ecx
  unsigned int v112; // edx
  unsigned int v113; // edx
  unsigned __int16 *v114; // eax
  unsigned __int16 v115; // si
  unsigned __int16 *v116; // ecx
  unsigned __int16 *v117; // edx
  int v118; // esi
  int v119; // ecx
  unsigned int v120; // edx
  unsigned int v121; // edx
  unsigned __int16 *v122; // ecx
  unsigned __int16 *v123; // edx
  int v124; // ecx
  unsigned int v125; // edx
  unsigned int v126; // edx
  unsigned __int16 *v127; // eax
  std::wstring v129; // [esp-10h] [ebp-1ACh] BYREF
  float v130; // [esp+1Ch] [ebp-180h]
  __int64 v131; // [esp+20h] [ebp-17Ch] BYREF
  float v132; // [esp+28h] [ebp-174h]
  __int64 v133; // [esp+2Ch] [ebp-170h]
  float v134; // [esp+34h] [ebp-168h]
  __int128 v135; // [esp+38h] [ebp-164h]
  int v136; // [esp+48h] [ebp-154h]
  unsigned __int64 v137; // [esp+4Ch] [ebp-150h] BYREF
  float v138; // [esp+54h] [ebp-148h]
  vec3f v139; // [esp+58h] [ebp-144h]
  __int128 v140; // [esp+64h] [ebp-138h]
  int v141; // [esp+74h] [ebp-128h]
  __int64 v142; // [esp+78h] [ebp-124h] BYREF
  float v143; // [esp+80h] [ebp-11Ch]
  __int64 v144; // [esp+84h] [ebp-118h]
  float v145; // [esp+8Ch] [ebp-110h]
  __int128 v146; // [esp+90h] [ebp-10Ch]
  int v147; // [esp+A0h] [ebp-FCh]
  __int64 v148; // [esp+A4h] [ebp-F8h] BYREF
  float v149; // [esp+ACh] [ebp-F0h]
  __int64 v150; // [esp+B0h] [ebp-ECh]
  float v151; // [esp+B8h] [ebp-E4h]
  __int128 v152; // [esp+BCh] [ebp-E0h]
  int v153; // [esp+CCh] [ebp-D0h]
  __int64 v154; // [esp+D0h] [ebp-CCh]
  float v155; // [esp+D8h] [ebp-C4h]
  __int64 v156; // [esp+DCh] [ebp-C0h]
  float v157; // [esp+E4h] [ebp-B8h]
  __int64 v158; // [esp+E8h] [ebp-B4h]
  float v159; // [esp+F0h] [ebp-ACh]
  __int64 v160; // [esp+F4h] [ebp-A8h]
  float v161; // [esp+FCh] [ebp-A0h]
  vec3f v162; // [esp+100h] [ebp-9Ch] BYREF
  std::vector<unsigned short> *v163; // [esp+10Ch] [ebp-90h]
  vec3f v164; // [esp+110h] [ebp-8Ch] BYREF
  float v165; // [esp+11Ch] [ebp-80h]
  float v166; // [esp+120h] [ebp-7Ch]
  vec3f v167; // [esp+124h] [ebp-78h] BYREF
  int v168; // [esp+130h] [ebp-6Ch]
  vec3f result; // [esp+134h] [ebp-68h] BYREF
  int v170; // [esp+140h] [ebp-5Ch]
  int v171; // [esp+144h] [ebp-58h]
  float v172; // [esp+148h] [ebp-54h]
  int v173; // [esp+14Ch] [ebp-50h]
  float v174; // [esp+150h] [ebp-4Ch]
  float v175; // [esp+154h] [ebp-48h]
  int v176; // [esp+158h] [ebp-44h] BYREF
  int v177; // [esp+15Ch] [ebp-40h] BYREF
  __m128i v178; // [esp+160h] [ebp-3Ch] BYREF
  int v179; // [esp+170h] [ebp-2Ch] BYREF
  int v180; // [esp+174h] [ebp-28h] BYREF
  int v181; // [esp+178h] [ebp-24h]
  int v182; // [esp+17Ch] [ebp-20h]
  int v183; // [esp+180h] [ebp-1Ch]
  float v184; // [esp+184h] [ebp-18h]
  __m128i _Count; // [esp+188h] [ebp-14h] BYREF
  int v186; // [esp+198h] [ebp-4h]

  v186 = 1;
  *(float *)&v3 = COERCE_FLOAT(operator new(276));
  v171 = (int)v3;
  if ( *(float *)&v3 == 0.0 )
  {
    v5 = 0;
    v182 = 0;
  }
  else
  {
    v129._Myres = 7;
    v129._Mysize = 0;
    v129._Bx._Buf[0] = 0;
    std::wstring::assign(&v129, L"HemiSphere", 0xAu);
    Mesh::Mesh(v3, v129);
    v5 = v4;
    v182 = v4;
  }
  v6 = -1;
  LOBYTE(v186) = 0;
  v181 = 0;
  v173 = -1;
  *(float *)&v7 = (float)(1.0 / (float)subs) * 360.0;
  v8 = (float)(1.0 / (float)subs) * 180.0;
  v171 = v7;
  v175 = v8;
  if ( subs <= -1 )
    goto $LN1302;
  v9 = subs / 2;
  v170 = subs / 2;
  while ( 2 )
  {
    v10 = -1;
    if ( v9 <= -1 )
      goto LABEL_206;
    v163 = (std::vector<unsigned short> *)(v5 + 236);
    v11 = (float)v6 * *(float *)&v7;
    v174 = v11;
    v172 = (float)(v6 + 1) * *(float *)&v7;
    do
    {
      *(float *)&v129._Myres = (float)v10 * v8;
      *(float *)&v129._Mysize = v11;
      v184 = *(float *)&v129._Myres;
      ShapeBuilder::getSpherePos(v10, &result);
      v12 = LODWORD(result.x);
      v178.m128i_i64[0] = LODWORD(result.x);
      *(float *)&v12 = result.x * radius;
      _Count.m128i_i64[0] = v12;
      *(float *)&v183 = result.y * radius;
      v130 = result.z * radius;
      *(float *)&v129._Myres = v184;
      *(float *)&v129._Mysize = v172;
      ShapeBuilder::getSpherePos(v10, &v167);
      v13 = v10 + 1;
      v168 = v13;
      *(float *)&v158 = v167.x * radius;
      *((float *)&v158 + 1) = v167.y * radius;
      v159 = v167.z * radius;
      *(float *)&v129._Myres = (float)v13 * v175;
      v184 = *(float *)&v129._Myres;
      *(float *)&v129._Mysize = v172;
      ShapeBuilder::getSpherePos(v13, &v164);
      *(float *)&v160 = v164.x * radius;
      *((float *)&v160 + 1) = v164.y * radius;
      v161 = v164.z * radius;
      *(float *)&v129._Myres = v184;
      *(float *)&v129._Mysize = v174;
      ShapeBuilder::getSpherePos(v13, &v162);
      *(float *)&v156 = v162.x * radius;
      *((float *)&v156 + 1) = v162.y * radius;
      v157 = v162.z * radius;
      v14 = (__m128)_mm_loadl_epi64(&_Count);
      v15 = (std::vector<MeshVertex> *)(v182 + 224);
      v140 = 0i64;
      v138 = v130;
      v16 = *(_DWORD *)(v182 + 228);
      v137 = _mm_unpacklo_ps(v14, (__m128)(unsigned int)v183).m128_u64[0];
      v17 = (__m128)_mm_loadl_epi64(&v178);
      v141 = 0;
      *(_QWORD *)&result.x = _mm_unpacklo_ps(v17, (__m128)LODWORD(result.y)).m128_u64[0];
      v139 = result;
      if ( (unsigned int)&v137 >= v16 || v15->_Myfirst > (MeshVertex *)&v137 )
      {
        if ( v16 == *(_DWORD *)(v182 + 232) )
          std::vector<MeshVertex>::_Reserve((std::vector<MeshVertex> *)(v182 + 224), 1u);
        v19 = v15->_Mylast;
        if ( v19 )
        {
          v20 = (const MeshVertex *)&v137;
          goto LABEL_18;
        }
      }
      else
      {
        v18 = ((char *)&v137 - (char *)v15->_Myfirst) / 44;
        if ( *(_DWORD *)(v182 + 228) == *(_DWORD *)(v182 + 232) )
          std::vector<MeshVertex>::_Reserve((std::vector<MeshVertex> *)(v182 + 224), 1u);
        v19 = v15->_Mylast;
        if ( v19 )
        {
          v20 = &v15->_Myfirst[v18];
LABEL_18:
          MeshVertex::MeshVertex(v19, v20);
          goto LABEL_19;
        }
      }
LABEL_19:
      v21 = v159;
      ++v15->_Mylast;
      v146 = 0i64;
      v143 = v21;
      v142 = v158;
      v145 = v167.z;
      v22 = v15->_Mylast;
      v147 = 0;
      v144 = *(_QWORD *)&v167.x;
      if ( &v142 >= (__int64 *)v22 || v15->_Myfirst > (MeshVertex *)&v142 )
      {
        if ( v22 == v15->_Myend )
          std::vector<MeshVertex>::_Reserve(v15, 1u);
        v24 = v15->_Mylast;
        if ( v24 )
        {
          v25 = (const MeshVertex *)&v142;
          goto LABEL_29;
        }
      }
      else
      {
        v23 = ((char *)&v142 - (char *)v15->_Myfirst) / 44;
        if ( v15->_Mylast == v15->_Myend )
          std::vector<MeshVertex>::_Reserve(v15, 1u);
        v24 = v15->_Mylast;
        if ( v24 )
        {
          v25 = &v15->_Myfirst[v23];
LABEL_29:
          MeshVertex::MeshVertex(v24, v25);
          goto LABEL_30;
        }
      }
LABEL_30:
      v26 = v161;
      ++v15->_Mylast;
      v135 = 0i64;
      v132 = v26;
      v131 = v160;
      v134 = v164.z;
      v27 = v15->_Mylast;
      v136 = 0;
      v133 = *(_QWORD *)&v164.x;
      if ( &v131 >= (__int64 *)v27 || v15->_Myfirst > (MeshVertex *)&v131 )
      {
        if ( v27 == v15->_Myend )
          std::vector<MeshVertex>::_Reserve(v15, 1u);
        v29 = v15->_Mylast;
        if ( v29 )
        {
          v30 = (const MeshVertex *)&v131;
          goto LABEL_40;
        }
      }
      else
      {
        v28 = ((char *)&v131 - (char *)v15->_Myfirst) / 44;
        if ( v15->_Mylast == v15->_Myend )
          std::vector<MeshVertex>::_Reserve(v15, 1u);
        v29 = v15->_Mylast;
        if ( v29 )
        {
          v30 = &v15->_Myfirst[v28];
LABEL_40:
          MeshVertex::MeshVertex(v29, v30);
          goto LABEL_41;
        }
      }
LABEL_41:
      v31 = v157;
      ++v15->_Mylast;
      v152 = 0i64;
      v149 = v31;
      v148 = v156;
      v151 = v162.z;
      v32 = v15->_Mylast;
      v153 = 0;
      v150 = *(_QWORD *)&v162.x;
      if ( &v148 >= (__int64 *)v32 || v15->_Myfirst > (MeshVertex *)&v148 )
      {
        if ( v32 == v15->_Myend )
          std::vector<MeshVertex>::_Reserve(v15, 1u);
        v34 = v15->_Mylast;
        if ( v34 )
        {
          v35 = (const MeshVertex *)&v148;
          goto LABEL_51;
        }
      }
      else
      {
        v33 = ((char *)&v148 - (char *)v15->_Myfirst) / 44;
        if ( v15->_Mylast == v15->_Myend )
          std::vector<MeshVertex>::_Reserve(v15, 1u);
        v34 = v15->_Mylast;
        if ( v34 )
        {
          v35 = &v15->_Myfirst[v33];
LABEL_51:
          MeshVertex::MeshVertex(v34, v35);
          goto LABEL_52;
        }
      }
LABEL_52:
      v36 = (unsigned __int64)(780903145i64 * ((char *)++v15->_Mylast - (char *)v15->_Myfirst)) >> 32;
      v183 = 4;
      v37 = 44 * ((v36 >> 3) + ((unsigned int)v36 >> 31));
      _Count.m128i_i32[1] = v37;
      v184 = *(float *)&v37;
      do
      {
        v38 = v15->_Myfirst;
        v39 = *(float *)((char *)v15->_Myfirst + v37 - 24);
        v154 = *(_QWORD *)((char *)v15->_Myfirst + v37 - 32);
        v155 = v39;
        v40 = __libm_sse2_asinf().m128_f32[0];
        v41 = v184;
        *(float *)&v178.m128i_i32[1] = atan2(v155, *(float *)&v154);
        v165 = (float)(v40 * 0.31830984) + 0.5;
        v42 = *(float *)&v178.m128i_i32[1] * 0.31830984;
        *(float *)((char *)v38 + LODWORD(v184) - 20) = v165;
        v166 = (float)(v42 + 1.0) * 0.5;
        *(float *)((char *)v38 + LODWORD(v41) - 16) = v166;
        v37 = LODWORD(v41) - 44;
        v43 = v183-- == 1;
        v184 = *(float *)&v37;
      }
      while ( !v43 );
      v44 = v182;
      v45 = _Count.m128i_i32[1];
      v46 = *(_DWORD *)(v182 + 224);
      v47 = v163;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(_Count.m128i_i32[1] + v46 - 104) - *(float *)(_Count.m128i_i32[1] + v46 - 148)) & _xmm) > 0.1
        || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(_Count.m128i_i32[1] + v46 - 16) - *(float *)(_Count.m128i_i32[1]
                                                                                                  + v46
                                                                                                  - 60)) & _xmm) > 0.1 )
      {
        *(float *)(_Count.m128i_i32[1] + v46 - 60) = *(float *)(_Count.m128i_i32[1] + v46 - 60) - 1.0;
        *(float *)(v45 + v46 - 104) = *(float *)(v45 + v46 - 104) - 1.0;
      }
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(v45 + v46 - 20) - 1.0) & _xmm) < 0.001
        && COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(v45 + v46 - 64) - 1.0) & _xmm) < 0.001 )
      {
        *(float *)(v45 + v46 - 16) = (float)(*(float *)(v45 + v46 - 148) + *(float *)(v45 + v46 - 104)) * 0.5;
        *(float *)(v45 + *(_DWORD *)(v44 + 224) - 60) = (float)(*(float *)(v45 + *(_DWORD *)(v44 + 224) - 148)
                                                              + *(float *)(v45 + *(_DWORD *)(v44 + 224) - 104))
                                                      * 0.5;
      }
      v48 = v47->_Mylast;
      v49 = 4 * v181;
      LODWORD(v184) = 4 * v181;
      v183 = 4 * v181 + 2;
      v178.m128i_i32[2] = (unsigned __int16)(4 * v181);
      if ( &v178.m128i_u64[1] >= (unsigned __int64 *)v48 || v47->_Myfirst > &v178.m128i_u16[4] )
      {
        v56 = v47->_Myend;
        if ( v48 == v56 && !(v56 - v48) )
        {
          v57 = v48 - v47->_Myfirst;
          if ( v57 == 0x7FFFFFFF )
            goto LABEL_208;
          v58 = v56 - v47->_Myfirst;
          _Count.m128i_i32[1] = v57 + 1;
          if ( 0x7FFFFFFF - (v58 >> 1) >= v58 )
            v59 = (v58 >> 1) + v58;
          else
            v59 = 0;
          if ( v59 < _Count.m128i_i32[1] )
            v59 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v59);
          v49 = LOWORD(v184);
        }
        v60 = v47->_Mylast;
        if ( v60 )
          *v60 = v49;
      }
      else
      {
        v50 = v47->_Myend;
        v51 = ((char *)&v178.m128i_u64[1] - (char *)v47->_Myfirst) >> 1;
        if ( v48 == v50 && !(v50 - v48) )
        {
          v52 = v48 - v47->_Myfirst;
          if ( v52 == 0x7FFFFFFF )
            goto LABEL_208;
          v53 = v50 - v47->_Myfirst;
          _Count.m128i_i32[1] = v52 + 1;
          if ( 0x7FFFFFFF - (v53 >> 1) >= v53 )
            v54 = (v53 >> 1) + v53;
          else
            v54 = 0;
          if ( v54 < _Count.m128i_i32[1] )
            v54 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v54);
        }
        v55 = v47->_Mylast;
        if ( v55 )
          *v55 = v47->_Myfirst[v51];
      }
      v61 = v183;
      v62 = ++v47->_Mylast;
      v176 = v61;
      if ( &v176 >= (int *)v62 || v47->_Myfirst > (unsigned __int16 *)&v176 )
      {
        v69 = v47->_Myend;
        if ( v62 == v69 && !(v69 - v62) )
        {
          v70 = v62 - v47->_Myfirst;
          if ( v70 == 0x7FFFFFFF )
            goto LABEL_208;
          v71 = v69 - v47->_Myfirst;
          _Count.m128i_i32[1] = v70 + 1;
          if ( 0x7FFFFFFF - (v71 >> 1) >= v71 )
            v72 = (v71 >> 1) + v71;
          else
            v72 = 0;
          if ( v72 < _Count.m128i_i32[1] )
            v72 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v72);
          v61 = v183;
        }
        v73 = v47->_Mylast;
        if ( v73 )
          *v73 = v61;
      }
      else
      {
        v63 = v47->_Myend;
        v64 = ((char *)&v176 - (char *)v47->_Myfirst) >> 1;
        if ( v62 == v63 && !(v63 - v62) )
        {
          v65 = v62 - v47->_Myfirst;
          if ( v65 == 0x7FFFFFFF )
            goto LABEL_208;
          v66 = v63 - v47->_Myfirst;
          _Count.m128i_i32[1] = v65 + 1;
          if ( 0x7FFFFFFF - (v66 >> 1) >= v66 )
            v67 = (v66 >> 1) + v66;
          else
            v67 = 0;
          if ( v67 < _Count.m128i_i32[1] )
            v67 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v67);
        }
        v68 = v47->_Mylast;
        if ( v68 )
          *v68 = v47->_Myfirst[v64];
      }
      v74 = v181;
      v75 = ++v47->_Mylast;
      v76 = 4 * v74 + 1;
      v177 = v76;
      v178.m128i_i32[1] = 4 * v74 + 1;
      if ( &v177 >= (int *)v75 || v47->_Myfirst > (unsigned __int16 *)&v177 )
      {
        v83 = v47->_Myend;
        if ( v75 == v83 && !(v83 - v75) )
        {
          v84 = v75 - v47->_Myfirst;
          if ( v84 == 0x7FFFFFFF )
            goto LABEL_208;
          v85 = v83 - v47->_Myfirst;
          _Count.m128i_i32[1] = v84 + 1;
          if ( 0x7FFFFFFF - (v85 >> 1) >= v85 )
            v86 = (v85 >> 1) + v85;
          else
            v86 = 0;
          if ( v86 < _Count.m128i_i32[1] )
            v86 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v86);
          v76 = v178.m128i_u16[2];
        }
        v87 = v47->_Mylast;
        if ( v87 )
          *v87 = v76;
      }
      else
      {
        v77 = v47->_Myend;
        v78 = ((char *)&v177 - (char *)v47->_Myfirst) >> 1;
        if ( v75 == v77 && !(v77 - v75) )
        {
          v79 = v75 - v47->_Myfirst;
          if ( v79 == 0x7FFFFFFF )
            goto LABEL_208;
          v80 = v77 - v47->_Myfirst;
          _Count.m128i_i32[1] = v79 + 1;
          if ( 0x7FFFFFFF - (v80 >> 1) >= v80 )
            v81 = (v80 >> 1) + v80;
          else
            v81 = 0;
          if ( v81 < _Count.m128i_i32[1] )
            v81 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v81);
        }
        v82 = v47->_Mylast;
        if ( v82 )
          *v82 = v47->_Myfirst[v78];
      }
      v88 = LOWORD(v184);
      v89 = ++v47->_Mylast;
      v178.m128i_i32[3] = v88;
      if ( (char *)&v178.m128i_u64[1] + 4 >= (char *)v89 || v47->_Myfirst > &v178.m128i_u16[6] )
      {
        v96 = v47->_Myend;
        if ( v89 == v96 && !(v96 - v89) )
        {
          v97 = v89 - v47->_Myfirst;
          if ( v97 == 0x7FFFFFFF )
            goto LABEL_208;
          v98 = v96 - v47->_Myfirst;
          _Count.m128i_i32[1] = v97 + 1;
          if ( 0x7FFFFFFF - (v98 >> 1) >= v98 )
            v99 = (v98 >> 1) + v98;
          else
            v99 = 0;
          if ( v99 < _Count.m128i_i32[1] )
            v99 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v99);
          v88 = LOWORD(v184);
        }
        v100 = v47->_Mylast;
        if ( v100 )
          *v100 = v88;
      }
      else
      {
        v90 = v47->_Myend;
        v91 = ((char *)&v178.m128i_u64[1] + 4 - (char *)v47->_Myfirst) >> 1;
        if ( v89 == v90 && !(v90 - v89) )
        {
          v92 = v89 - v47->_Myfirst;
          if ( v92 == 0x7FFFFFFF )
            goto LABEL_208;
          v93 = v90 - v47->_Myfirst;
          _Count.m128i_i32[1] = v92 + 1;
          if ( 0x7FFFFFFF - (v93 >> 1) >= v93 )
            v94 = (v93 >> 1) + v93;
          else
            v94 = 0;
          if ( v94 < _Count.m128i_i32[1] )
            v94 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v94);
        }
        v95 = v47->_Mylast;
        if ( v95 )
          *v95 = v47->_Myfirst[v91];
      }
      v101 = v181;
      v102 = ++v47->_Mylast;
      v103 = 4 * v101 + 3;
      v179 = v103;
      v178.m128i_i32[1] = 4 * v101 + 3;
      if ( &v179 >= (int *)v102 || v47->_Myfirst > (unsigned __int16 *)&v179 )
      {
        v110 = v47->_Myend;
        if ( v102 == v110 && !(v110 - v102) )
        {
          v111 = v102 - v47->_Myfirst;
          if ( v111 == 0x7FFFFFFF )
            goto LABEL_208;
          v112 = v110 - v47->_Myfirst;
          _Count.m128i_i32[1] = v111 + 1;
          if ( 0x7FFFFFFF - (v112 >> 1) >= v112 )
            v113 = (v112 >> 1) + v112;
          else
            v113 = 0;
          if ( v113 < _Count.m128i_i32[1] )
            v113 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v113);
          v103 = v178.m128i_u16[2];
        }
        v114 = v47->_Mylast;
        if ( v114 )
          *v114 = v103;
      }
      else
      {
        v104 = v47->_Myend;
        v105 = ((char *)&v179 - (char *)v47->_Myfirst) >> 1;
        if ( v102 == v104 && !(v104 - v102) )
        {
          v106 = v102 - v47->_Myfirst;
          if ( v106 == 0x7FFFFFFF )
            goto LABEL_208;
          v107 = v104 - v47->_Myfirst;
          _Count.m128i_i32[1] = v106 + 1;
          if ( 0x7FFFFFFF - (v107 >> 1) >= v107 )
            v108 = (v107 >> 1) + v107;
          else
            v108 = 0;
          if ( v108 < _Count.m128i_i32[1] )
            v108 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v108);
        }
        v109 = v47->_Mylast;
        if ( v109 )
          *v109 = v47->_Myfirst[v105];
      }
      v115 = v183;
      v116 = ++v47->_Mylast;
      v180 = v115;
      if ( &v180 >= (int *)v116 || v47->_Myfirst > (unsigned __int16 *)&v180 )
      {
        v123 = v47->_Myend;
        if ( v116 == v123 && !(v123 - v116) )
        {
          v124 = v116 - v47->_Myfirst;
          if ( v124 == 0x7FFFFFFF )
LABEL_208:
            std::_Xlength_error("vector<T> too long");
          v125 = v123 - v47->_Myfirst;
          _Count.m128i_i32[1] = v124 + 1;
          if ( 0x7FFFFFFF - (v125 >> 1) >= v125 )
            v126 = (v125 >> 1) + v125;
          else
            v126 = 0;
          if ( v126 < _Count.m128i_i32[1] )
            v126 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v126);
          v115 = v183;
        }
        v127 = v47->_Mylast;
        if ( v127 )
          *v127 = v115;
      }
      else
      {
        v117 = v47->_Myend;
        v118 = ((char *)&v180 - (char *)v47->_Myfirst) >> 1;
        if ( v116 == v117 && !(v117 - v116) )
        {
          v119 = v116 - v47->_Myfirst;
          if ( v119 == 0x7FFFFFFF )
            goto LABEL_208;
          v120 = v117 - v47->_Myfirst;
          _Count.m128i_i32[1] = v119 + 1;
          if ( 0x7FFFFFFF - (v120 >> 1) >= v120 )
            v121 = (v120 >> 1) + v120;
          else
            v121 = 0;
          if ( v121 < _Count.m128i_i32[1] )
            v121 = _Count.m128i_u32[1];
          std::vector<unsigned short>::_Reallocate(v47, v121);
        }
        v122 = v47->_Mylast;
        if ( v122 )
          *v122 = v47->_Myfirst[v118];
      }
      ++v47->_Mylast;
      ++v181;
      v10 = v168;
      v9 = v170;
      v11 = v174;
      v8 = v175;
    }
    while ( v168 < v170 );
    v7 = v171;
    v6 = v173;
LABEL_206:
    v173 = ++v6;
    if ( v6 < subs )
    {
      v5 = v182;
      continue;
    }
    break;
  }
$LN1302:
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  return (Mesh *)v182;
}
vec3f *__usercall ShapeBuilder::getSpherePos@<eax>(int a1@<esi>, vec3f *result)
{
  int v3; // ecx
  float v4; // xmm5_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm7_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  __m128 v11; // xmm6
  __m128 v12; // xmm1
  float v13; // xmm5_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  int v16; // ecx
  float v17; // xmm7_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  __m128 v24; // xmm7
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  __m128 v29; // xmm4
  __m128 v30; // xmm6
  float v31; // xmm0_4
  unsigned __int64 v32; // xmm1_8
  int v33; // ecx
  float v34; // xmm0_4
  vec3f *v35; // eax
  float v36; // xmm4_4
  __m128 v37; // xmm3
  __m128 v38; // xmm0
  float v39; // xmm2_4
  float v40; // xmm4_4
  float v41; // xmm2_4
  float v42; // xmm2_4
  float v43; // xmm2_4
  float v44; // xmm7_4
  int v46; // [esp-4h] [ebp-70h]
  mat44f v47; // [esp+0h] [ebp-6Ch] BYREF
  float v48; // [esp+48h] [ebp-24h]
  unsigned __int64 v49; // [esp+4Ch] [ebp-20h]
  float v50; // [esp+54h] [ebp-18h]
  float v51; // [esp+58h] [ebp-14h]
  float v52; // [esp+5Ch] [ebp-10h]
  float v53; // [esp+60h] [ebp-Ch]
  float v54; // [esp+64h] [ebp-8h]
  float v55; // [esp+68h] [ebp-4h]
  float resulta; // [esp+70h] [ebp+4h]
  float resultb; // [esp+70h] [ebp+4h]
  float resultc; // [esp+70h] [ebp+4h]
  float azimutha; // [esp+74h] [ebp+8h]
  float azimuthb; // [esp+74h] [ebp+8h]
  float azimuthc; // [esp+74h] [ebp+8h]
  float azimuthd; // [esp+74h] [ebp+8h]

  result->x = 0.0;
  result->y = 0.0;
  result->z = -1.0;
  v55 = __libm_sse2_cosf(a1, LODWORD(v47.M11)).m128_f32[0];
  azimutha = __libm_sse2_sinf(v3).m128_f32[0];
  resulta = 1.0 - v55;
  mat44f::mat44f(&v47);
  v4 = resulta * 0.0;
  v5 = resulta * 0.0;
  resultb = resulta + v55;
  v55 = v5 + v55;
  v7 = (float)(azimutha * 0.0) + v4;
  v6 = v4 - (float)(azimutha * 0.0);
  v53 = v4 - azimutha;
  v8 = result->z;
  azimuthb = azimutha + v4;
  v9 = result->y;
  v54 = v6;
  v10 = v9 * v6;
  v11 = (__m128)LODWORD(result->x);
  v12 = v11;
  v13 = v11.m128_f32[0] * v53;
  v11.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] * v55) + v10) + (float)(v8 * azimuthb)) + v47.M41;
  v12.m128_f32[0] = (float)((float)((float)(v12.m128_f32[0] * v7) + (float)(v9 * resultb)) + (float)(v8 * v54))
                  + v47.M42;
  v14 = (float)((float)(v13 + (float)(v9 * v7)) + (float)(v8 * v55)) + v47.M43;
  *(_QWORD *)&result->x = _mm_unpacklo_ps(v11, v12).m128_u64[0];
  v50 = v14;
  result->z = v14;
  v15 = result->z;
  v12.m128_f32[0] = result->y * 0.0;
  v55 = v12.m128_f32[0] - (float)(v15 * -1.0);
  azimuthc = (float)(result->x * -1.0) - v12.m128_f32[0];
  v53 = (float)(v15 * 0.0) - (float)(result->x * 0.0);
  resultc = __libm_sse2_cosf(v46, LODWORD(v47.M11)).m128_f32[0];
  LODWORD(v54) = __libm_sse2_sinf(v16).m128_u32[0];
  mat44f::mat44f(&v47);
  v17 = v53;
  v11.m128_f32[0] = (float)(v53 * v55) * (float)(1.0 - resultc);
  v52 = (float)((float)(v53 * v53) * (float)(1.0 - resultc)) + resultc;
  v51 = (float)((float)(azimuthc * azimuthc) * (float)(1.0 - resultc)) + resultc;
  v18 = (float)(azimuthc * v54) + v11.m128_f32[0];
  v11.m128_f32[0] = v11.m128_f32[0] - (float)(azimuthc * v54);
  v19 = v53 * v54;
  v53 = v18;
  v20 = (float)(azimuthc * v55) * (float)(1.0 - resultc);
  v21 = v20 - v19;
  v22 = v19 + v20;
  v23 = azimuthc * v17;
  v24 = (__m128)LODWORD(result->x);
  v25 = v23 * (float)(1.0 - resultc);
  v12.m128_i32[0] = LODWORD(result->z);
  v26 = result->y;
  azimuthd = v25 - (float)(v55 * v54);
  v30 = (__m128)COERCE_UNSIGNED_INT(v26 * v11.m128_f32[0]);
  v27 = (float)((float)(v55 * v54) + v25) * v26;
  v28 = v12.m128_f32[0] * v22;
  v29 = v24;
  v30.m128_f32[0] = (float)((float)(v30.m128_f32[0]
                                  + (float)((float)((float)((float)(v55 * v55) * (float)(1.0 - resultc)) + resultc)
                                          * v24.m128_f32[0]))
                          + v28)
                  + v47.M41;
  v31 = v51 * v12.m128_f32[0];
  v29.m128_f32[0] = (float)((float)((float)(v24.m128_f32[0] * v53) + (float)(v52 * v26))
                          + (float)(azimuthd * v12.m128_f32[0]))
                  + v47.M42;
  v32 = _mm_unpacklo_ps(v30, v29).m128_u64[0];
  v49 = v32;
  v48 = (float)((float)((float)(v24.m128_f32[0] * v21) + v27) + v31) + v47.M43;
  *(float *)&v33 = v48;
  v50 = v48;
  v34 = fsqrt(
          (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v30.m128_f32[0] * v30.m128_f32[0]))
        + (float)(v48 * v48));
  if ( v34 != 0.0 )
  {
    *(float *)&v49 = (float)(1.0 / v34) * v30.m128_f32[0];
    v50 = (float)(1.0 / v34) * v50;
    *(float *)&v33 = v50;
    *((float *)&v49 + 1) = (float)(1.0 / v34) * *((float *)&v49 + 1);
    v32 = v49;
  }
  v35 = result;
  *(_QWORD *)&result->x = v32;
  result->z = *(float *)&v33;
  v36 = result->x * 1000.0;
  v37.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v36);
  v38.m128_i32[0] = COERCE_UNSIGNED_INT(result->x * 1000.0) ^ LODWORD(FLOAT_N0_0) & LODWORD(v36);
  v38.m128_f32[0] = _mm_cmplt_ss(v38, (__m128)LODWORD(FLOAT_8388608_0)).m128_f32[0];
  v39 = (float)(v36 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v38.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v36)))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v38.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v36));
  v38.m128_f32[0] = v39 - v36;
  v40 = result->y * 1000.0;
  v38.m128_f32[0] = _mm_cmpgt_ss(v38, v37).m128_f32[0];
  v37.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v40);
  v41 = v39 - COERCE_FLOAT(v38.m128_i32[0] & LODWORD(FLOAT_1_0));
  v38.m128_i32[0] = COERCE_UNSIGNED_INT(result->y * 1000.0) ^ LODWORD(FLOAT_N0_0) & LODWORD(v40);
  v38.m128_f32[0] = _mm_cmplt_ss(v38, (__m128)LODWORD(FLOAT_8388608_0)).m128_f32[0];
  result->x = v41 * 0.001;
  v42 = (float)(v40 + COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v38.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v40)))
      - COERCE_FLOAT(LODWORD(FLOAT_8388608_0) & v38.m128_i32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v40));
  v38.m128_f32[0] = v42 - v40;
  result->y = (float)(v42 - COERCE_FLOAT(_mm_cmpgt_ss(v38, v37).m128_u32[0] & LODWORD(FLOAT_1_0))) * 0.001;
  v43 = result->z * 1000.0;
  v37.m128_i32[0] = LODWORD(FLOAT_N0_0) & LODWORD(v43);
  v38.m128_i32[0] = LODWORD(v43) ^ LODWORD(FLOAT_N0_0) & LODWORD(v43);
  LODWORD(v44) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v38, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | LODWORD(FLOAT_N0_0) & LODWORD(v43);
  v38.m128_f32[0] = (float)((float)(v43 + v44) - v44) - v43;
  result->z = (float)((float)((float)(v43 + v44) - v44)
                    - COERCE_FLOAT(_mm_cmpgt_ss(v38, v37).m128_u32[0] & LODWORD(FLOAT_1_0)))
            * 0.001;
  return v35;
}
