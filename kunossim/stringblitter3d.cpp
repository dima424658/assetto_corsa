#include "stringblitter3d.h
double StringBlitter3D::getFontSize(StringBlitter3D *this)
{
  return this->sizeY;
}
void StringBlitter3D::StringBlitter3D(StringBlitter3D *this, const std::wstring *name, GraphicsManager *graphics)
{
  unsigned int v4; // eax
  float v5; // xmm0_4
  Shader *v6; // eax
  bool v7; // cf
  std::wstring v8; // [esp+14h] [ebp-28h] BYREF
  int v9; // [esp+38h] [ebp-4h]

  this->use_monospace = 0;
  this->graphics = graphics;
  this->texture.kid = 0;
  this->texture.fileName._Myres = 7;
  this->texture.fileName._Mysize = 0;
  this->texture.fileName._Bx._Buf[0] = 0;
  v9 = 0;
  this->offsets._Myfirst = 0;
  this->offsets._Mylast = 0;
  this->offsets._Myend = 0;
  this->color.x = 0.0;
  this->color.y = 0.0;
  this->color.z = 0.0;
  this->color.w = 0.0;
  this->monospace_size = 0.0;
  this->scaleConst = 0.80000001;
  LOBYTE(v9) = 1;
  if ( !blitterGL )
    blitterGL = GraphicsManager::createGLRenderer(graphics, 0x80u);
  StringBlitter3D::initTexture(this, name);
  StringBlitter3D::initCoords(this, name);
  this->scale = 1.0;
  if ( this->texture.kid )
    v4 = kglTextureGetHeight(this->texture.kid);
  else
    v4 = 0;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  v5 = (float)v4;
  this->sizeY = v5;
  this->color = (vec4f)_xmm;
  std::wstring::assign(&v8, L"ksFont", 6u);
  LOBYTE(v9) = 2;
  v6 = GraphicsManager::getShader(graphics, (unsigned int)graphics, &v8);
  v7 = v8._Myres < 8;
  this->shFont = v6;
  if ( !v7 )
    operator delete(v8._Bx._Ptr);
}
void StringBlitter3D::~StringBlitter3D(StringBlitter3D *this)
{
  if ( this->offsets._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->offsets);
    operator delete(this->offsets._Myfirst);
    this->offsets._Myfirst = 0;
    this->offsets._Mylast = 0;
    this->offsets._Myend = 0;
  }
  OnSetupAppCreated::~OnSetupAppCreated(&this->texture);
}
void StringBlitter3D::blitString(StringBlitter3D *this, const std::wstring *s, float scale, eFontAlign align, vec3f offset)
{
  unsigned int v7; // eax
  double v8; // st7
  GLRenderer *v9; // edi
  unsigned int i; // ebp
  const std::wstring *v11; // eax
  int v12; // edi
  float v13; // xmm0_4
  void *v14; // eax
  unsigned int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // [esp+20h] [ebp-8h]
  float xa; // [esp+2Ch] [ebp+4h]
  GLRenderer *x; // [esp+2Ch] [ebp+4h]
  float aligna; // [esp+34h] [ebp+Ch]
  float alignb; // [esp+34h] [ebp+Ch]

  v18 = 0.0;
  v7 = s->_Mysize;
  if ( !v7 || v7 > 0xA0 )
    return;
  if ( align == eAlignRight )
  {
    v8 = StringBlitter3D::getStringWidth(this, s);
    goto LABEL_7;
  }
  if ( align == eAlignCenter )
  {
    v8 = StringBlitter3D::getStringWidth(this, s) * 0.5;
LABEL_7:
    xa = v8;
    v18 = xa;
  }
  GraphicsManager::setTexture(this->graphics, 0, &this->texture);
  GraphicsManager::setBlendMode(this->graphics, eAlphaBlend);
  v9 = blitterGL;
  x = blitterGL;
  GLRenderer::begin(blitterGL, eQuads, this->shFont);
  for ( i = 0; i < s->_Mysize; v18 = v18 - (float)(alignb * this->scaleConst) )
  {
    if ( s->_Myres < 8 )
      v11 = s;
    else
      v11 = (const std::wstring *)s->_Bx._Ptr;
    v12 = v11->_Bx._Buf[i];
    if ( this->use_monospace )
      v13 = this->monospace_size;
    else
      v13 = this->offsets._Myfirst[v12 - 31] - this->offsets._Myfirst[v12 - 32];
    v14 = this->texture.kid;
    aligna = v13;
    if ( v14 )
      v15 = kglTextureGetWidth(v14);
    else
      v15 = 0;
    v16 = (float)v15;
    GLRenderer::color4f(x, this->color.x, this->color.y, this->color.z, this->color.w);
    GLRenderer::texCoord2f(x, this->offsets._Myfirst[v12 - 31], 1.0);
    GLRenderer::vertex3f(x, v18, 0.0, 0.0);
    GLRenderer::texCoord2f(x, this->offsets._Myfirst[v12 - 31], 0.0);
    GLRenderer::vertex3f(x, v18, this->sizeY * scale, 0.0);
    GLRenderer::texCoord2f(x, this->offsets._Myfirst[v12 - 32], 0.0);
    alignb = (float)(v16 * aligna) * scale;
    GLRenderer::vertex3f(x, alignb + v18, this->sizeY * scale, 0.0);
    v17 = this->offsets._Myfirst[v12 - 32];
    v9 = x;
    GLRenderer::texCoord2f(x, v17, 1.0);
    GLRenderer::vertex3f(x, alignb + v18, 0.0, 0.0);
    ++i;
  }
  GLRenderer::end(v9);
}
void StringBlitter3D::blitString(StringBlitter3D *this, const std::wstring *s, mat44f rotationMatrix, float scale, eFontAlign align, vec3f offset)
{
  float v6; // xmm0_4
  unsigned int v8; // eax
  double v9; // st7
  GraphicsManager *v10; // ecx
  GLRenderer *v11; // esi
  unsigned int *v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // ecx
  const std::wstring *v15; // eax
  int v16; // esi
  double v17; // xmm0_8
  void *v18; // eax
  unsigned int v19; // eax
  float v20; // xmm2_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  float v26; // xmm5_4
  float v27; // xmm0_4
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm0_4
  float v33; // xmm5_4
  float v34; // xmm3_4
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  float v37; // xmm0_4
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  double v40; // xmm0_8
  float xa; // [esp+20h] [ebp-68h]
  GLRenderer *x; // [esp+20h] [ebp-68h]
  unsigned int i; // [esp+24h] [ebp-64h] BYREF
  double v44; // [esp+28h] [ebp-60h] BYREF
  unsigned int v45; // [esp+34h] [ebp-54h]
  double v46; // [esp+38h] [ebp-50h]
  double v47; // [esp+40h] [ebp-48h]
  vec3f point; // [esp+4Ch] [ebp-3Ch] BYREF
  float v49; // [esp+60h] [ebp-28h]
  float v50; // [esp+6Ch] [ebp-1Ch]
  float v51; // [esp+78h] [ebp-10h]
  float v52; // [esp+84h] [ebp-4h]

  v6 = 0.0;
  v8 = s->_Mysize;
  if ( !v8 || v8 > 0xA0 )
    return;
  if ( align == eAlignRight )
  {
    v9 = StringBlitter3D::getStringWidth(this, s);
    goto LABEL_7;
  }
  if ( align == eAlignCenter )
  {
    v9 = StringBlitter3D::getStringWidth(this, s) * 0.5;
LABEL_7:
    xa = v9;
    v6 = xa;
  }
  v10 = this->graphics;
  v46 = v6;
  GraphicsManager::setTexture(v10, 0, &this->texture);
  GraphicsManager::setBlendMode(this->graphics, eAlphaBlend);
  v11 = blitterGL;
  x = blitterGL;
  GLRenderer::begin(blitterGL, eQuads, this->shFont);
  v12 = &i;
  i = s->_Mysize;
  LODWORD(v44) = 20;
  if ( i >= 0x14 )
    v12 = (unsigned int *)&v44;
  v13 = *v12;
  v14 = 0;
  v45 = v13;
  for ( i = 0; v14 < v45; v46 = v46 - v40 * v47 )
  {
    if ( s->_Myres < 8 )
      v15 = s;
    else
      v15 = (const std::wstring *)s->_Bx._Ptr;
    v16 = v15->_Bx._Buf[v14];
    if ( this->use_monospace )
      v17 = this->monospace_size;
    else
      v17 = (float)(this->offsets._Myfirst[v16 - 31] - this->offsets._Myfirst[v16 - 32]);
    v18 = this->texture.kid;
    v44 = v17;
    if ( v18 )
      v19 = kglTextureGetWidth(v18);
    else
      v19 = 0;
    v44 = (double)v19 * v44;
    GLRenderer::color4f(x, this->color.x, this->color.y, this->color.z, this->color.w);
    GLRenderer::texCoord2f(x, this->offsets._Myfirst[v16 - 31], 1.0);
    v20 = v46;
    v21 = rotationMatrix.M12 * v20;
    v22 = (float)(rotationMatrix.M11 * v20) + (float)(rotationMatrix.M21 * 0.0);
    v23 = rotationMatrix.M13 * v20;
    v24 = (__m128)LODWORD(offset.x);
    v24.m128_f32[0] = offset.x + (float)((float)(v22 + (float)(rotationMatrix.M31 * 0.0)) + rotationMatrix.M41);
    v25 = (__m128)LODWORD(offset.y);
    v25.m128_f32[0] = offset.y
                    + (float)((float)((float)(v21 + (float)(rotationMatrix.M22 * 0.0))
                                    + (float)(rotationMatrix.M32 * 0.0))
                            + rotationMatrix.M42);
    *(_QWORD *)&point.x = _mm_unpacklo_ps(v24, v25).m128_u64[0];
    v49 = offset.z
        + (float)((float)((float)(v23 + (float)(rotationMatrix.M23 * 0.0)) + (float)(rotationMatrix.M33 * 0.0))
                + rotationMatrix.M43);
    point.z = v49;
    GLRenderer::vertex3fv(x, &point.x);
    GLRenderer::texCoord2f(x, this->offsets._Myfirst[v16 - 31], 0.0);
    v26 = v46;
    v27 = this->sizeY * scale;
    v28 = (__m128)LODWORD(offset.y);
    v29 = (__m128)LODWORD(offset.x);
    v29.m128_f32[0] = offset.x
                    + (float)((float)((float)((float)(v26 * rotationMatrix.M11) + (float)(v27 * rotationMatrix.M21))
                                    + (float)(rotationMatrix.M31 * 0.0))
                            + rotationMatrix.M41);
    v28.m128_f32[0] = offset.y
                    + (float)((float)((float)((float)(v26 * rotationMatrix.M12) + (float)(v27 * rotationMatrix.M22))
                                    + (float)(rotationMatrix.M32 * 0.0))
                            + rotationMatrix.M42);
    *(_QWORD *)&point.x = _mm_unpacklo_ps(v29, v28).m128_u64[0];
    v50 = offset.z
        + (float)((float)((float)((float)(v26 * rotationMatrix.M13) + (float)(v27 * rotationMatrix.M23))
                        + (float)(rotationMatrix.M33 * 0.0))
                + rotationMatrix.M43);
    point.z = v50;
    GLRenderer::vertex3fv(x, &point.x);
    GLRenderer::texCoord2f(x, this->offsets._Myfirst[v16 - 32], 0.0);
    v28.m128_f32[0] = this->sizeY * scale;
    v47 = scale * v44;
    v30 = v47 + v46;
    v31 = v30 * rotationMatrix.M12;
    *(float *)&v44 = v30;
    v32 = v28.m128_f32[0] * rotationMatrix.M22;
    v33 = (float)((float)((float)(v30 * rotationMatrix.M11) + (float)(v28.m128_f32[0] * rotationMatrix.M21))
                + (float)(rotationMatrix.M31 * 0.0))
        + rotationMatrix.M41;
    v34 = (float)(v30 * rotationMatrix.M13) + (float)(v28.m128_f32[0] * rotationMatrix.M23);
    v35 = (__m128)LODWORD(offset.y);
    v36 = (__m128)LODWORD(offset.x);
    v36.m128_f32[0] = offset.x + v33;
    v35.m128_f32[0] = offset.y
                    + (float)((float)((float)(v31 + v32) + (float)(rotationMatrix.M32 * 0.0)) + rotationMatrix.M42);
    *(_QWORD *)&point.x = _mm_unpacklo_ps(v36, v35).m128_u64[0];
    v51 = offset.z + (float)((float)(v34 + (float)(rotationMatrix.M33 * 0.0)) + rotationMatrix.M43);
    point.z = v51;
    GLRenderer::vertex3fv(x, &point.x);
    v37 = this->offsets._Myfirst[v16 - 32];
    v11 = x;
    GLRenderer::texCoord2f(x, v37, 1.0);
    v38 = (__m128)LODWORD(offset.x);
    v38.m128_f32[0] = offset.x
                    + (float)((float)((float)((float)(*(float *)&v44 * rotationMatrix.M11)
                                            + (float)(rotationMatrix.M21 * 0.0))
                                    + (float)(rotationMatrix.M31 * 0.0))
                            + rotationMatrix.M41);
    v39 = (__m128)LODWORD(offset.y);
    v39.m128_f32[0] = offset.y
                    + (float)((float)((float)((float)(*(float *)&v44 * rotationMatrix.M12)
                                            + (float)(rotationMatrix.M22 * 0.0))
                                    + (float)(rotationMatrix.M32 * 0.0))
                            + rotationMatrix.M42);
    *(_QWORD *)&point.x = _mm_unpacklo_ps(v38, v39).m128_u64[0];
    v52 = offset.z
        + (float)((float)((float)((float)(*(float *)&v44 * rotationMatrix.M13) + (float)(rotationMatrix.M23 * 0.0))
                        + (float)(rotationMatrix.M33 * 0.0))
                + rotationMatrix.M43);
    point.z = v52;
    GLRenderer::vertex3fv(x, &point.x);
    v40 = this->scaleConst;
    v14 = i + 1;
    i = v14;
  }
  GLRenderer::end(v11);
}
void StringBlitter3D::blitStringV2(StringBlitter3D *this, const std::wstring *s, float scale, eFontAlign align, vec3f offset)
{
  const std::wstring *v5; // edi
  unsigned int v7; // eax
  float v8; // xmm0_4
  signed int v9; // eax
  int v10; // edi
  float v11; // xmm0_4
  void *v12; // eax
  unsigned int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm2_4
  bool v16; // sf
  signed int v17; // [esp+18h] [ebp-Ch]
  float x; // [esp+1Ch] [ebp-8h]
  GLRenderer *v19; // [esp+20h] [ebp-4h]
  float alignb; // [esp+30h] [ebp+Ch]
  float alignc; // [esp+30h] [ebp+Ch]
  float aligna; // [esp+30h] [ebp+Ch]

  v5 = s;
  x = 0.0;
  v7 = s->_Mysize;
  if ( !v7 || v7 > 0xA0 )
    return;
  GraphicsManager::setTexture(this->graphics, 0, &this->texture);
  GraphicsManager::setBlendMode(this->graphics, eAlphaBlend);
  v19 = blitterGL;
  GLRenderer::begin(blitterGL, eQuads, this->shFont);
  if ( align == eAlignLeft )
  {
    alignc = StringBlitter3D::getStringWidth(this, s);
    v8 = alignc;
    goto LABEL_7;
  }
  if ( align == eAlignCenter )
  {
    alignb = StringBlitter3D::getStringWidth(this, s) * 0.5;
    v8 = alignb;
LABEL_7:
    LODWORD(x) = LODWORD(v8) ^ _xmm;
  }
  v9 = s->_Mysize - 1;
  v17 = v9;
  if ( v9 >= 0 )
  {
    do
    {
      if ( v5->_Myres >= 8 )
        v5 = (const std::wstring *)v5->_Bx._Ptr;
      v10 = v5->_Bx._Buf[v9];
      if ( this->use_monospace )
        v11 = this->monospace_size;
      else
        v11 = this->offsets._Myfirst[v10 - 31] - this->offsets._Myfirst[v10 - 32];
      v12 = this->texture.kid;
      aligna = v11;
      if ( v12 )
        v13 = kglTextureGetWidth(v12);
      else
        v13 = 0;
      v14 = (float)v13;
      GLRenderer::color4f(v19, this->color.x, this->color.y, this->color.z, this->color.w);
      GLRenderer::texCoord2f(v19, this->offsets._Myfirst[v10 - 31], 1.0);
      GLRenderer::vertex3f(v19, x, 0.0, 0.0);
      GLRenderer::texCoord2f(v19, this->offsets._Myfirst[v10 - 31], 0.0);
      GLRenderer::vertex3f(v19, x, (float)(this->sizeY * scale) * this->scaleConst, 0.0);
      GLRenderer::texCoord2f(v19, this->offsets._Myfirst[v10 - 32], 0.0);
      v15 = (float)(v14 * aligna) * scale;
      GLRenderer::vertex3f(
        v19,
        (float)(v15 * this->scaleConst) + x,
        (float)(this->sizeY * scale) * this->scaleConst,
        0.0);
      GLRenderer::texCoord2f(v19, this->offsets._Myfirst[v10 - 32], 1.0);
      GLRenderer::vertex3f(v19, (float)(this->scaleConst * v15) + x, 0.0, 0.0);
      v5 = s;
      v9 = v17 - 1;
      v16 = --v17 < 0;
      x = (float)(this->scaleConst * v15) + x;
    }
    while ( !v16 );
  }
  GLRenderer::end(v19);
}
double StringBlitter3D::getStringWidth(StringBlitter3D *this, const std::wstring *s)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  float v5; // xmm1_4
  double result; // st7
  unsigned int i; // ebx
  const std::wstring *v8; // eax
  float v9; // xmm0_4
  void *v10; // eax
  unsigned int v11; // eax
  double v12; // [esp+8h] [ebp-10h]
  double v13; // [esp+10h] [ebp-8h]

  v12 = 0.0;
  v13 = 0.0;
  if ( this->use_monospace )
  {
    v3 = s->_Mysize;
    if ( this->texture.kid )
      v4 = kglTextureGetWidth(this->texture.kid);
    else
      v4 = 0;
    v5 = (float)v3;
    result = (float)((float)((float)((float)(v5 * this->monospace_size) * this->scale) * this->scaleConst) * (float)v4);
  }
  else
  {
    for ( i = 0; i < s->_Mysize; v13 = v12 )
    {
      if ( s->_Myres < 8 )
        v8 = s;
      else
        v8 = (const std::wstring *)s->_Bx._Ptr;
      v9 = this->offsets._Myfirst[v8->_Bx._Buf[i] - 31] - this->offsets._Myfirst[v8->_Bx._Buf[i] - 32];
      v10 = this->texture.kid;
      if ( v10 )
        v11 = kglTextureGetWidth(v10);
      else
        v11 = 0;
      ++i;
      v12 = (float)v11 * v9 * this->scale * this->scaleConst + v12;
    }
    result = v13;
  }
  return result;
}
void StringBlitter3D::initCoords(StringBlitter3D *this, const std::wstring *name)
{
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  int v5; // ebx
  double v6; // st7
  float *v7; // ecx
  float v8; // xmm0_4
  float *v9; // eax
  int v10; // edi
  float *v11; // ecx
  float *v12; // eax
  float *v13; // ecx
  float *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  const wchar_t *v18; // eax
  int v19; // ecx
  float v20; // [esp+30h] [ebp-21Ch] BYREF
  float v21; // [esp+34h] [ebp-218h]
  const std::wstring *v22; // [esp+38h] [ebp-214h]
  std::ifstream s; // [esp+3Ch] [ebp-210h] BYREF
  std::wstring v24; // [esp+F4h] [ebp-158h] BYREF
  std::wstring result; // [esp+10Ch] [ebp-140h] BYREF
  std::wstring filename; // [esp+124h] [ebp-128h] BYREF
  char buffer[256]; // [esp+13Ch] [ebp-110h] BYREF
  int v28; // [esp+248h] [ebp-4h]

  v22 = name;
  v3 = std::operator+<wchar_t>(&result, L"content/fonts/", name);
  v28 = 0;
  v4 = std::operator+<wchar_t>(&v24, v3, L".txt");
  std::wstring::wstring(&filename, v4);
  if ( v24._Myres >= 8 )
    operator delete(v24._Bx._Ptr);
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  LOBYTE(v28) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  std::ifstream::ifstream(&s, &filename, 1, 64, 1);
  LOBYTE(v28) = 3;
  v5 = 96;
  do
  {
    std::istream::getline(&s, buffer, 256, 0);
    v6 = _atof(buffer);
    v7 = this->offsets._Mylast;
    v21 = v6;
    v8 = v21;
    v20 = v21;
    if ( &v20 >= v7 || (v9 = this->offsets._Myfirst, v9 > &v20) )
    {
      if ( v7 == this->offsets._Myend )
      {
        std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->offsets, 1u);
        v8 = v21;
      }
      v12 = this->offsets._Mylast;
      if ( v12 )
        *v12 = v8;
    }
    else
    {
      v10 = &v20 - v9;
      if ( v7 == this->offsets._Myend )
        std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->offsets, 1u);
      v11 = this->offsets._Mylast;
      if ( v11 )
        *v11 = this->offsets._Myfirst[v10];
    }
    ++this->offsets._Mylast;
    --v5;
  }
  while ( v5 );
  v13 = this->offsets._Mylast;
  v14 = this->offsets._Myfirst;
  v15 = FLOAT_N1_0;
  v16 = FLOAT_999_0;
  for ( this->monospace_size = -1.0; v14 != v13; ++v14 )
  {
    if ( v15 < 0.0 )
    {
      v15 = *v14;
    }
    else
    {
      v17 = this->monospace_size;
      if ( v17 <= (float)(*v14 - v15) )
        v17 = *v14 - v15;
      this->monospace_size = v17;
      if ( (float)(*v14 - v15) <= v16 )
        v16 = *v14 - v15;
      v15 = *v14;
    }
  }
  v18 = (const wchar_t *)v22;
  if ( v22->_Myres >= 8 )
    v18 = v22->_Bx._Ptr;
  _printf("%S MONOSPACE SIZE:%f (min %f)\n", v18, this->monospace_size, v16);
  LOBYTE(v28) = 2;
  *(_DWORD *)&s.gap0[*(_DWORD *)(*(_DWORD *)s.gap0 + 4)] = &std::ifstream::`vftable';
  *(const std::wstring **)((char *)&v22 + *(_DWORD *)(*(_DWORD *)s.gap0 + 4)) = (const std::wstring *)(*(_DWORD *)(*(_DWORD *)s.gap0 + 4) - 112);
  v19 = *(_DWORD *)s._Filebuffer;
  *(_DWORD *)s.gap10 = &std::filebuf::`vftable';
  if ( *(_DWORD *)s._Filebuffer && **(std::ifstream ***)&s.gap10[12] == (std::ifstream *)&s.gap10[68] )
  {
    std::streambuf::setg(s.gap10, *(_DWORD *)&s.gap10[56], *(_DWORD *)&s.gap10[56], *(_DWORD *)&s.gap10[60]);
    v19 = *(_DWORD *)s._Filebuffer;
  }
  if ( s.gap10[76] )
  {
    if ( v19 )
    {
      std::filebuf::_Endwrite((std::filebuf *)s.gap10);
      _fclose(*(FILE **)s._Filebuffer);
    }
    s.gap10[76] = 0;
    s.gap10[69] = 0;
    std::streambuf::_Init(s.gap10);
    *(_DWORD *)s._Filebuffer = 0;
    *(_DWORD *)&s.gap10[72] = `std::filebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&s.gap10[64] = 0;
  }
  std::streambuf::~streambuf<char,std::char_traits<char>>(s.gap10);
  std::istream::~istream<char,std::char_traits<char>>(&s.gap10[8]);
  std::ios::~ios<char,std::char_traits<char>>(&s.gap64[12]);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void StringBlitter3D::initTexture(StringBlitter3D *this, const std::wstring *name)
{
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  GraphicsManager *v5; // eax
  Texture *v6; // eax
  void *v7; // ecx
  const std::wstring *v8; // eax
  std::wstring result; // [esp+8h] [ebp-74h] BYREF
  std::wstring v10; // [esp+20h] [ebp-5Ch] BYREF
  std::wstring filename; // [esp+38h] [ebp-44h] BYREF
  Texture v12; // [esp+50h] [ebp-2Ch] BYREF
  int v13; // [esp+78h] [ebp-4h]

  v3 = std::operator+<wchar_t>(&result, L"content/fonts/", name);
  v13 = 0;
  v4 = std::operator+<wchar_t>(&v10, v3, L".png");
  std::wstring::wstring(&filename, v4);
  if ( v10._Myres >= 8 )
    operator delete(v10._Bx._Ptr);
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  LOBYTE(v13) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  v5 = this->graphics;
  result._Mysize = 0;
  v6 = ResourceStore::getTexture(v5->resourceStore._Myptr, &v12, &filename, 0);
  v7 = v6->kid;
  v8 = &v6->fileName;
  this->texture.kid = v7;
  LOBYTE(v13) = 3;
  if ( &this->texture.fileName != v8 )
    std::wstring::assign(&this->texture.fileName, v8, 0, 0xFFFFFFFF);
  LOBYTE(v13) = 2;
  OnSetupAppCreated::~OnSetupAppCreated(&v12);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void StringBlitter3D::setColor(StringBlitter3D *this, const vec4f *a_color)
{
  this->color = (vec4f)_mm_loadu_si128((const __m128i *)a_color);
}
void StringBlitter3D::setScaleConst(StringBlitter3D *this, float s)
{
  this->scaleConst = s;
}
