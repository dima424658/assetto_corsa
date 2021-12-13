#include "trackmaphandler.h"
void __userpurge TrackMapHandler::TrackMapHandler(TrackMapHandler *this@<ecx>, unsigned int a2@<ebx>, Sim *sim)
{
  TrackAvatar *v4; // eax
  char v5; // al
  char v6; // bl
  Texture *v7; // eax
  std::wstring path; // [esp+10h] [ebp-44h] BYREF
  Texture result; // [esp+28h] [ebp-2Ch] BYREF
  int v10; // [esp+50h] [ebp-4h]

  this->pointsToDraw._Myfirst = 0;
  this->pointsToDraw._Mylast = 0;
  this->pointsToDraw._Myend = 0;
  v10 = 0;
  this->roadTexture.kid = 0;
  this->roadTexture.fileName._Myres = 7;
  this->roadTexture.fileName._Mysize = 0;
  this->roadTexture.fileName._Bx._Buf[0] = 0;
  LOBYTE(v10) = 1;
  this->graphics = sim->game->graphics;
  v4 = GameObject::getGameObject<TrackAvatar>(sim);
  this->aiSpline = TrackAvatar::getAISpline(v4);
  this->margin = 20.0;
  this->mapSquareSize = 0.0;
  this->scaleFactor = 1.0;
  this->drawingSize = 10.0;
  this->coordOffsetX = 0.0;
  this->coordOffsetZ = 0.0;
  this->width = 0.0;
  this->height = 0.0;
  this->minX = 0.0;
  this->maxX = 0.0;
  this->minZ = 0.0;
  this->maxZ = 0.0;
  this->finishingSplineLinkThresholdMeters = 20.0;
  this->textured = 0;
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  std::wstring::assign(&path, L"content/texture/mapRoad.png", 0x1Bu);
  LOBYTE(v10) = 2;
  v5 = Path::fileExists(a2, &path, 0);
  LOBYTE(v10) = 1;
  v6 = v5;
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  if ( v6 )
  {
    path._Myres = 7;
    path._Mysize = 0;
    path._Bx._Buf[0] = 0;
    std::wstring::assign(&path, L"content/texture/mapRoad.png", 0x1Bu);
    LOBYTE(v10) = 3;
    v7 = ResourceStore::getTexture(this->graphics->resourceStore._Myptr, &result, &path, 0);
    LOBYTE(v10) = 4;
    this->roadTexture.kid = v7->kid;
    if ( &this->roadTexture.fileName != &v7->fileName )
      std::wstring::assign(&this->roadTexture.fileName, &v7->fileName, 0, 0xFFFFFFFF);
    LOBYTE(v10) = 3;
    OnSetupAppCreated::~OnSetupAppCreated(&result);
    if ( path._Myres >= 8 )
      operator delete(path._Bx._Ptr);
    this->textured = 1;
  }
  else
  {
    this->textured = 0;
  }
}
void __userpurge TrackMapHandler::loadParameters(TrackMapHandler *this@<ecx>, float a2@<xmm1>, float a3@<xmm2>, std::wstring iniPath)
{
  double v7; // st7
  bool v8; // cf
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  std::wstring section; // [esp+14h] [ebp-88h] BYREF
  std::wstring key; // [esp+2Ch] [ebp-70h] BYREF
  INIReader r; // [esp+44h] [ebp-58h] BYREF
  int v16; // [esp+98h] [ebp-4h]

  v16 = 0;
  INIReader::INIReader(&r, &iniPath);
  LOBYTE(v16) = 1;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SCALE_FACTOR", 0xCu);
    LOBYTE(v16) = 2;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"PARAMETERS", 0xAu);
    LOBYTE(v16) = 3;
    v7 = INIReader::getFloat(&r, &section, &key);
    v8 = section._Myres < 8;
    this->scaleFactor = v7;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v16) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    this->width = a2;
    this->height = a3;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MARGIN", 6u);
    LOBYTE(v16) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"PARAMETERS", 0xAu);
    LOBYTE(v16) = 5;
    v9 = INIReader::getFloat(&r, &section, &key);
    v8 = section._Myres < 8;
    this->margin = v9;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v16) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"X_OFFSET", 8u);
    LOBYTE(v16) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"PARAMETERS", 0xAu);
    LOBYTE(v16) = 7;
    v10 = INIReader::getFloat(&r, &section, &key);
    v8 = section._Myres < 8;
    this->coordOffsetX = v10;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v16) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"Z_OFFSET", 8u);
    LOBYTE(v16) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"PARAMETERS", 0xAu);
    LOBYTE(v16) = 9;
    v11 = INIReader::getFloat(&r, &section, &key);
    v8 = section._Myres < 8;
    this->coordOffsetZ = v11;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v16) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DRAWING_SIZE", 0xCu);
    LOBYTE(v16) = 10;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"PARAMETERS", 0xAu);
    LOBYTE(v16) = 11;
    v12 = INIReader::getFloat(&r, &section, &key);
    v8 = section._Myres < 8;
    this->drawingSize = v12;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  LOBYTE(v16) = 0;
  INIReader::~INIReader(&r);
  if ( iniPath._Myres >= 8 )
    operator delete(iniPath._Bx._Ptr);
}
void TrackMapHandler::saveParameters(TrackMapHandler *this, std::wstring iniPath)
{
  std::wstring *v2; // eax
  bool v3; // zf
  int v4; // eax
  std::ostream *v5; // eax
  std::ostream *v6; // eax
  int v7; // eax
  std::ostream *v8; // eax
  int v9; // eax
  std::ostream *v10; // eax
  int v11; // eax
  std::ostream *v12; // eax
  int v13; // eax
  std::ostream *v14; // eax
  int v15; // eax
  std::ostream *v16; // eax
  int v17; // eax
  std::ostream *v18; // eax
  int v19; // eax
  std::ofstream myINIfile; // [esp+50h] [ebp-B8h] BYREF
  int v21; // [esp+104h] [ebp-4h]

  v21 = 0;
  std::ofstream::ofstream(&myINIfile, 1);
  LOBYTE(v21) = 1;
  v2 = &iniPath;
  if ( iniPath._Myres >= 8 )
    v2 = (std::wstring *)iniPath._Bx._Ptr;
  v3 = std::filebuf::open((std::filebuf *)&myINIfile.gap0[4], v2->_Bx._Buf, 2, 64) == 0;
  v4 = *(_DWORD *)(*(_DWORD *)myINIfile.gap0 + 4);
  if ( v3 )
    std::ios::setstate((char *)&myINIfile + v4, 2, 0);
  else
    std::ios::clear((char *)&myINIfile + v4, 0, 0);
  v5 = std::operator<<<std::char_traits<char>>(&myINIfile, "[PARAMETERS]");
  std::ostream::operator<<(v5);
  v6 = std::operator<<<std::char_traits<char>>(&myINIfile, "WIDTH=");
  v7 = std::ostream::operator<<(v6);
  std::ostream::operator<<(v7);
  v8 = std::operator<<<std::char_traits<char>>(&myINIfile, "HEIGHT=");
  v9 = std::ostream::operator<<(v8);
  std::ostream::operator<<(v9);
  v10 = std::operator<<<std::char_traits<char>>(&myINIfile, "MARGIN=");
  v11 = std::ostream::operator<<(v10);
  std::ostream::operator<<(v11);
  v12 = std::operator<<<std::char_traits<char>>(&myINIfile, "SCALE_FACTOR=");
  v13 = std::ostream::operator<<(v12);
  std::ostream::operator<<(v13);
  v14 = std::operator<<<std::char_traits<char>>(&myINIfile, "X_OFFSET=");
  v15 = std::ostream::operator<<(v14);
  std::ostream::operator<<(v15);
  v16 = std::operator<<<std::char_traits<char>>(&myINIfile, "Z_OFFSET=");
  v17 = std::ostream::operator<<(v16);
  std::ostream::operator<<(v17);
  v18 = std::operator<<<std::char_traits<char>>(&myINIfile, "DRAWING_SIZE=");
  v19 = std::ostream::operator<<(v18);
  std::ostream::operator<<(v19);
  std::ofstream::close(&myINIfile);
  std::ofstream::~ofstream<char,std::char_traits<char>>((std::ofstream *)&myINIfile.gap58[8]);
  std::ios::~ios<char,std::char_traits<char>>(&myINIfile.gap58[8]);
  if ( iniPath._Myres >= 8 )
    operator delete(iniPath._Bx._Ptr);
}
void TrackMapHandler::makePositiveCoordAndCalculateWidthAndHeightRT(TrackMapHandler *this)
{
  float v1; // xmm2_4
  float v2; // xmm3_4
  vec3f *v3; // ebx
  int v4; // esi
  vec3f *v5; // eax
  float v6; // xmm0_4
  unsigned int v7; // [esp+4h] [ebp-4h]

  v1 = 0.0;
  v7 = 0;
  v2 = 0.0;
  this->coordOffsetX = COERCE_FLOAT(LODWORD(this->minX) & _xmm) + this->margin;
  this->coordOffsetZ = COERCE_FLOAT(LODWORD(this->minZ) & _xmm) + this->margin;
  if ( this->pointsToDraw._Mylast - this->pointsToDraw._Myfirst )
  {
    v3 = this->pointsToDraw._Myfirst;
    v4 = 0;
    do
    {
      v3[v4].x = v3[v4].x + this->coordOffsetX;
      v5 = this->pointsToDraw._Myfirst;
      if ( v5[v4].x > v1 )
        v1 = v5[v4].x;
      v5[v4].z = this->coordOffsetZ + v5[v4].z;
      v3 = this->pointsToDraw._Myfirst;
      if ( v3[v4].z > v2 )
        v2 = v3[v4].z;
      ++v7;
      ++v4;
    }
    while ( v7 < this->pointsToDraw._Mylast - v3 );
  }
  v6 = this->margin;
  this->height = v6 + v2;
  this->width = v6 + v1;
}
void TrackMapHandler::createListOfPointsToDrawFromSpline(TrackMapHandler *this)
{
  int v2; // ebp
  signed int v3; // ebx
  int v4; // edi
  const vec3f *v5; // eax
  vec3f *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  InterpolatingSpline *v11; // [esp+Ch] [ebp-10h]
  vec3f result; // [esp+10h] [ebp-Ch] BYREF

  v11 = &this->aiSpline->spline;
  v2 = Spline::pointsCount(v11);
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = 0;
    do
    {
      v5 = Spline::pointAt(v11, &result, v3);
      std::vector<DRSZone>::push_back(&this->pointsToDraw, v5);
      v6 = this->pointsToDraw._Myfirst;
      v7 = v6[v4].x;
      if ( v7 > this->maxX )
        this->maxX = v7;
      v8 = v6[v4].x;
      if ( this->minX > v8 )
        this->minX = v8;
      v9 = v6[v4].z;
      if ( v9 > this->maxZ )
        this->maxZ = v9;
      v10 = v6[v4].z;
      if ( this->minZ > v10 )
        this->minZ = v10;
      ++v3;
      ++v4;
    }
    while ( v3 < v2 );
  }
}
void TrackMapHandler::drawMapOnRenderTarget(TrackMapHandler *this, std::wstring filePath)
{
  ID3D11RenderTargetView **v3; // esi
  GraphicsManager *v4; // ecx
  GLRenderer *v5; // edi
  unsigned int v6; // ebp
  vec3f *v7; // edx
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm7_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm6_4
  float v28; // xmm0_4
  int v29; // ecx
  std::wstring *v30; // eax
  float v31; // [esp+40h] [ebp-124h]
  float x; // [esp+44h] [ebp-120h]
  float v33; // [esp+48h] [ebp-11Ch]
  float v34; // [esp+4Ch] [ebp-118h]
  float y; // [esp+50h] [ebp-114h]
  float v36; // [esp+54h] [ebp-110h] BYREF
  vec2f previousRightEnding; // [esp+58h] [ebp-10Ch]
  float v38; // [esp+60h] [ebp-104h]
  vec2f previousLeftEnding; // [esp+64h] [ebp-100h]
  float v40; // [esp+6Ch] [ebp-F8h]
  float v41; // [esp+70h] [ebp-F4h]
  float v42; // [esp+74h] [ebp-F0h]
  float v43; // [esp+78h] [ebp-ECh]
  float v44; // [esp+7Ch] [ebp-E8h]
  vec2f pNewLeftSide; // [esp+80h] [ebp-E4h]
  vec2f pOldLeftSide; // [esp+88h] [ebp-DCh]
  vec2f startRight; // [esp+90h] [ebp-D4h]
  vec2f startLeft; // [esp+98h] [ebp-CCh]
  vec2f pOldRightSide; // [esp+A0h] [ebp-C4h]
  vec4f pNewRightSide; // [esp+A8h] [ebp-BCh] OVERLAPPED BYREF
  RenderTarget renderTarget; // [esp+B8h] [ebp-ACh] BYREF
  mat44f id; // [esp+D4h] [ebp-90h] BYREF
  mat44f ortho; // [esp+114h] [ebp-50h] BYREF
  int v54; // [esp+160h] [ebp-4h]

  v54 = 0;
  RenderTarget::RenderTarget(&renderTarget, this->graphics, eR8G8B8A8, (int)this->width, (int)this->height, 1, 0, 1);
  LOBYTE(v54) = 1;
  activeDepthStencilView = 0;
  if ( renderTarget.kidColor )
  {
    v3 = (ID3D11RenderTargetView **)((char *)renderTarget.kidColor + 4);
    immediateContext->OMSetRenderTargets(
      immediateContext,
      1u,
      (ID3D11RenderTargetView *const *)((char *)renderTarget.kidColor + 4),
      0);
    activeRenderTargetView = *v3;
  }
  else
  {
    v36 = 0.0;
    immediateContext->OMSetRenderTargets(immediateContext, 1u, (ID3D11RenderTargetView *const *)&v36, 0);
    activeRenderTargetView = 0;
  }
  GraphicsManager::setViewport(this->graphics, 0, 0, (int)this->width, (int)this->height);
  GLRenderer::color4f(this->graphics->gl, 1.0, 1.0, 1.0, 1.0);
  v4 = this->graphics;
  pNewRightSide = 0i64;
  GraphicsManager::clearRenderTarget(v4, &pNewRightSide);
  GraphicsManager::setDepthMode(this->graphics, eDepthOff);
  GraphicsManager::setBlendMode(this->graphics, eOpaque);
  mat44f::createOrtho(&ortho, 0.0, this->width, this->height, 0.0, -1.0, 1.0);
  GraphicsManager::setProjectionMatrix(this->graphics, &ortho);
  mat44f::mat44f(&id);
  mat44f::loadIdentity(&id);
  GraphicsManager::setViewMatrix(this->graphics, &id, 0);
  GraphicsManager::setWorldMatrix(this->graphics, &id);
  GraphicsManager::setCullMode(this->graphics, eCullNone);
  v34 = 0.0;
  v33 = 0.0;
  v5 = this->graphics->gl;
  x = 0.0;
  y = 0.0;
  v43 = 0.0;
  v42 = 0.0;
  v36 = 0.0;
  v41 = 0.0;
  GLRenderer::color4f(v5, 1.0, 1.0, 1.0, 1.0);
  if ( this->textured )
    GraphicsManager::setTexture(this->graphics, 0, &this->roadTexture);
  v6 = 1;
  if ( (unsigned int)(this->pointsToDraw._Mylast - this->pointsToDraw._Myfirst) > 1 )
  {
    while ( 1 )
    {
      v7 = this->pointsToDraw._Myfirst;
      v8 = 0.0;
      v9 = v7[v6].x - v7[v6 - 1].x;
      v10 = v7[v6].z - v7[v6 - 1].z;
      v11 = fsqrt((float)(v9 * v9) + (float)(v10 * v10));
      if ( v11 != 0.0 )
      {
        v9 = (float)(1.0 / v11) * v9;
        v8 = (float)(1.0 / v11) * 0.0;
        v10 = (float)(1.0 / v11) * v10;
      }
      v12 = this->drawingSize * 0.5;
      v13 = v8 * 0.0;
      v14 = 1.0 / this->scaleFactor;
      v15 = v9 - v13;
      v16 = v13 - v10;
      v17 = v7[v6 - 1].z * v14;
      v18 = v14 * v7[v6 - 1].x;
      v38 = v14 * v7[v6].x;
      v31 = v15;
      v19 = v12 * v15;
      v20 = v7[v6].z * v14;
      v21 = v12 * v16;
      v22 = v17 + v19;
      v23 = v17 - v19;
      v24 = v20;
      v25 = v18 + (float)(v12 * v16);
      pOldLeftSide.y = v22;
      v26 = v12;
      v27 = v12 * v31;
      v28 = v26 * v16;
      pOldLeftSide.x = v25;
      pOldRightSide.y = v23;
      pOldRightSide.x = v18 - v21;
      v44 = v38 + v28;
      pNewLeftSide.x = v38 + v28;
      pNewLeftSide.y = v24 + v27;
      v38 = v38 - v28;
      v40 = v24 - v27;
      pNewRightSide.x = v38;
      pNewRightSide.y = v24 - v27;
      if ( v6 == 1 )
      {
        previousLeftEnding = pOldLeftSide;
        v33 = pOldLeftSide.y;
        v34 = pOldLeftSide.x;
        previousRightEnding = pOldRightSide;
        y = pOldRightSide.y;
        x = pOldRightSide.x;
        startLeft = pOldLeftSide;
        v42 = pOldLeftSide.y;
        v43 = pOldLeftSide.x;
        startRight = pOldRightSide;
        v41 = pOldRightSide.y;
        v36 = pOldRightSide.x;
      }
      if ( (float)v6 < (float)((float)(unsigned int)(this->pointsToDraw._Mylast - this->pointsToDraw._Myfirst)
                             - this->finishingSplineLinkThresholdMeters) )
      {
        GLRenderer::begin(v5, eQuads, 0);
        if ( this->textured )
          GLRenderer::texCoord2f(v5, 0.0, 0.0);
        GLRenderer::vertex3f(v5, x, y, 0.0);
        if ( this->textured )
          GLRenderer::texCoord2f(v5, 1.0, 0.0);
        GLRenderer::vertex3f(v5, v34, v33, 0.0);
        if ( this->textured )
          GLRenderer::texCoord2f(v5, 1.0, 1.0);
        GLRenderer::vertex3f(v5, v44, v24 + v27, 0.0);
        if ( this->textured )
          GLRenderer::texCoord2f(v5, 0.0, 1.0);
        GLRenderer::vertex3f(v5, v38, v40, 0.0);
      }
      else
      {
        GLRenderer::begin(v5, eQuads, 0);
        if ( this->textured )
          GLRenderer::texCoord2f(v5, 0.0, 0.0);
        GLRenderer::vertex3f(v5, x, y, 0.0);
        if ( this->textured )
          GLRenderer::texCoord2f(v5, 1.0, 0.0);
        GLRenderer::vertex3f(v5, v34, v33, 0.0);
        if ( this->textured )
          GLRenderer::texCoord2f(v5, 1.0, 1.0);
        GLRenderer::vertex3f(v5, v43, v42, 0.0);
        if ( this->textured )
          GLRenderer::texCoord2f(v5, 0.0, 1.0);
        GLRenderer::vertex3f(v5, v36, v41, 0.0);
      }
      GLRenderer::end(v5);
      ++v6;
      v29 = (char *)this->pointsToDraw._Mylast - (char *)this->pointsToDraw._Myfirst;
      previousLeftEnding = pNewLeftSide;
      previousRightEnding.x = pNewRightSide.x;
      previousRightEnding.y = pNewRightSide.y;
      if ( v6 >= v29 / 12 )
        break;
      v33 = previousLeftEnding.y;
      v34 = previousLeftEnding.x;
      y = previousRightEnding.y;
      x = previousRightEnding.x;
    }
  }
  immediateContext->Flush(immediateContext);
  v30 = &filePath;
  if ( filePath._Myres >= 8 )
    v30 = (std::wstring *)filePath._Bx._Ptr;
  D3DX11SaveTextureToFileW(immediateContext, *(_DWORD *)renderTarget.kidColor, 3, v30);
  LOBYTE(v54) = 0;
  RenderTarget::~RenderTarget(&renderTarget);
  if ( filePath._Myres >= 8 )
    operator delete(filePath._Bx._Ptr);
}
void TrackMapHandler::~TrackMapHandler(TrackMapHandler *this)
{
  this->pointsToDraw._Mylast = this->pointsToDraw._Myfirst;
  OnSetupAppCreated::~OnSetupAppCreated(&this->roadTexture);
  if ( this->pointsToDraw._Myfirst )
  {
    operator delete(this->pointsToDraw._Myfirst);
    this->pointsToDraw._Myfirst = 0;
    this->pointsToDraw._Mylast = 0;
    this->pointsToDraw._Myend = 0;
  }
}
