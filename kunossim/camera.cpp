#include "camera.h
void Camera::Camera(Camera *this, const std::wstring *iname, GraphicsManager *rm)
{
  const mat44f *v4; // eax
  mat44f result; // [esp+14h] [ebp-4Ch] BYREF
  int v6; // [esp+5Ch] [ebp-4h]

  this->__vftable = (Camera_vtbl *)&Camera::`vftable';
  mat44f::mat44f(&this->matrix);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  v6 = 0;
  this->clearColor.x = 0.0;
  this->clearColor.y = 0.0;
  this->clearColor.z = 0.0;
  this->clearColor.w = 0.0;
  v4 = mat44f::createIdentity(&result);
  BoundingFrustum::BoundingFrustum(&this->frustum, v4);
  LOBYTE(v6) = 1;
  this->lodMultiplier = 1.0;
  this->isCubeMapCamera = 0;
  this->graphics = rm;
  mat44f::mat44f(&this->virtualScreenPassOrgMatrix);
  this->axis3d = 0;
  this->axisRenderingMode = eAxisNone;
  if ( &this->name != iname )
    std::wstring::assign(&this->name, iname, 0, 0xFFFFFFFF);
  this->isMirror = 0;
  mat44f::loadIdentity(&this->matrix);
  this->fov = 60.0;
  this->nearPlane = 0.1;
  this->farPlane = 5000.0;
  this->clearMode = eColorAndDepth;
  this->clearDepth = 1.0;
  this->clearColor = (vec4f)_xmm;
  this->skyBox = 0;
  this->renderTarget = 0;
  this->exposure = 40.0;
  this->solveTransparentBuffer = 1;
  this->aspectRatio = -1.0;
  this->maxLayer = 5.0;
  this->minExposure = 0.0;
  this->maxExposure = 10000.0;
  this->dofFactor = 0.0;
  this->dofFocus = 500.0;
  this->dofRange = 10000.0;
  this->renderAudio = 0;
}
void Camera::~Camera(Camera *this)
{
  this->__vftable = (Camera_vtbl *)&Camera::`vftable';
  BoundingFrustum::~BoundingFrustum(&this->frustum);
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
Camera *Camera::`scalar deleting destructor'(Camera *this, unsigned int a2)
{
  this->__vftable = (Camera_vtbl *)&Camera::`vftable';
  BoundingFrustum::~BoundingFrustum(&this->frustum);
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Camera::clearBuffers(Camera *this)
{
  eCameraClearMode v2; // eax
  __int32 v3; // eax

  v2 = this->clearMode;
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 != 1 )
        return;
      GraphicsManager::clearRenderTarget(this->graphics, &this->clearColor);
    }
    GraphicsManager::clearRenderTargetDepth(this->graphics, this->clearDepth);
  }
  else
  {
    GraphicsManager::clearRenderTarget(this->graphics, &this->clearColor);
  }
}
mat44f *Camera::getFinalWorldMatrix(Camera *this, mat44f *result)
{
  mat44f *v2; // eax

  v2 = result;
  *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&this->matrix);
  *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
  *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
  *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
  return v2;
}
mat44f *Camera::getPerspectiveMatrix(Camera *this, mat44f *result)
{
  float aspectRatio; // xmm1_4

  aspectRatio = this->aspectRatio;
  if ( aspectRatio == -1.0 )
    aspectRatio = (float)this->graphics->videoSettings.width / (float)this->graphics->videoSettings.height;
  mat44f::createPerspective(result, this->fov * 0.017453, aspectRatio, this->nearPlane, this->farPlane);
  return result;
}
mat44f *Camera::getViewMatrix(Camera *this, mat44f *result)
{
  float v2; // xmm5_4
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  __m128 v8; // xmm0
  vec3f cameraPosition; // [esp+0h] [ebp-24h] BYREF
  vec3f cameraTarget; // [esp+Ch] [ebp-18h] BYREF
  vec3f cameraUpVector; // [esp+18h] [ebp-Ch] BYREF

  v2 = this->matrix.M31;
  v3 = this->matrix.M32;
  v4 = this->matrix.M33;
  v5 = this->matrix.M42;
  v6 = this->matrix.M43;
  cameraUpVector = *(vec3f *)&this->matrix.M21;
  v7 = this->matrix.M41 + COERCE_FLOAT(LODWORD(v2) ^ _xmm);
  cameraTarget.y = v5 + COERCE_FLOAT(LODWORD(v3) ^ _xmm);
  cameraTarget.x = v7;
  cameraPosition.x = this->matrix.M41;
  cameraPosition.y = this->matrix.M42;
  v8 = (__m128)LODWORD(this->matrix.M43);
  cameraTarget.z = v6 + COERCE_FLOAT(LODWORD(v4) ^ _xmm);
  LODWORD(cameraPosition.z) = v8.m128_i32[0];
  mat44f::createLookAt(v8, result, &cameraPosition, &cameraTarget, &cameraUpVector);
  return result;
}
void Camera::moveForward(Camera *this, float d)
{
  float v2; // xmm2_4
  float v3; // xmm1_4

  v2 = (float)(COERCE_FLOAT(LODWORD(this->matrix.M32) ^ _xmm) * d) + this->matrix.M42;
  v3 = (float)(COERCE_FLOAT(LODWORD(this->matrix.M33) ^ _xmm) * d) + this->matrix.M43;
  this->matrix.M41 = (float)(COERCE_FLOAT(LODWORD(this->matrix.M31) ^ _xmm) * d) + this->matrix.M41;
  this->matrix.M42 = v2;
  this->matrix.M43 = v3;
}
void Camera::moveRight(Camera *this, float d)
{
  float v2; // xmm2_4
  float v3; // xmm3_4

  v2 = (float)(this->matrix.M12 * d) + this->matrix.M42;
  v3 = (float)(this->matrix.M13 * d) + this->matrix.M43;
  this->matrix.M41 = (float)(this->matrix.M11 * d) + this->matrix.M41;
  this->matrix.M42 = v2;
  this->matrix.M43 = v3;
}
void Camera::moveUpWorld(Camera *this, float d)
{
  float v2; // xmm2_4
  float v3; // xmm1_4

  v2 = this->matrix.M42 + d;
  v3 = this->matrix.M43;
  this->matrix.M41 = this->matrix.M41;
  this->matrix.M43 = v3;
  this->matrix.M42 = v2;
}
void Camera::render(Camera *this, Node *root, float dt)
{
  GraphicsManager *v4; // eax
  eCameraClearMode v5; // eax
  __int32 v6; // eax
  MaterialFilter materialFilter; // [esp+Ch] [ebp-74h] BYREF
  RenderContext rc; // [esp+14h] [ebp-6Ch] BYREF
  CameraMeshFilter filter; // [esp+24h] [ebp-5Ch] BYREF
  mat44f id; // [esp+34h] [ebp-4Ch] BYREF
  int v11; // [esp+7Ch] [ebp-4h]

  CameraMeshFilter::CameraMeshFilter(&filter, this, Opaque, (int)this->maxLayer);
  v11 = 0;
  MaterialFilter::MaterialFilter(&materialFilter);
  v4 = this->graphics;
  rc.materialFilter = &materialFilter;
  rc.meshFilter = &filter;
  LOBYTE(v11) = 1;
  rc.graphics = v4;
  rc.camera = this;
  Camera::renderCamera(this);
  v5 = this->clearMode;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 != 1 )
        goto LABEL_7;
      GraphicsManager::clearRenderTarget(this->graphics, &this->clearColor);
    }
    GraphicsManager::clearRenderTargetDepth(this->graphics, this->clearDepth);
  }
  else
  {
    GraphicsManager::clearRenderTarget(this->graphics, &this->clearColor);
  }
LABEL_7:
  if ( this->skyBox )
  {
    mat44f::mat44f(&id);
    mat44f::loadIdentity(&id);
    GraphicsManager::setWorldMatrix(this->graphics, &id);
    GraphicsManager::setDepthMode(this->graphics, eDepthOff);
    PvsProcessor::begin(this->graphics->pvsProcessor, &rc, Default, 0, 0);
    SkyBox::render(this->skyBox, &rc);
    PvsProcessor::end(this->graphics->pvsProcessor);
    GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  }
  PvsProcessor::begin(this->graphics->pvsProcessor, &rc, Default, 0, 0);
  root->render(root, &rc);
  PvsProcessor::end(this->graphics->pvsProcessor);
  LOBYTE(v11) = 0;
  MaterialFilter::~MaterialFilter(&materialFilter);
  v11 = -1;
  CameraMeshFilter::~CameraMeshFilter(&filter);
}
void Camera::renderAxis(Camera *this, bool useZBuffer)
{
  bool v3; // bl
  const mat44f *v4; // eax
  eAxisRendering v5; // eax
  GraphicsManager *v6; // ecx
  GLRenderer *v7; // esi
  Node *a; // [esp+Ch] [ebp-88h]
  MaterialFilter materialFilter; // [esp+20h] [ebp-74h] BYREF
  RenderContext rc; // [esp+28h] [ebp-6Ch] BYREF
  CameraMeshFilter filter; // [esp+38h] [ebp-5Ch] BYREF
  mat44f result; // [esp+48h] [ebp-4Ch] BYREF
  int v13; // [esp+90h] [ebp-4h]

  v3 = useZBuffer;
  if ( !useZBuffer )
    GraphicsManager::setDepthMode(this->graphics, eDepthOff);
  v4 = mat44f::createIdentity(&result);
  GraphicsManager::setWorldMatrix(this->graphics, v4);
  v5 = this->axisRenderingMode;
  if ( v5 == eAxisAfter3d || v5 == eAxisBefore3d )
  {
    v7 = this->graphics->gl;
    GLRenderer::color4f(v7, 3.0, 0.0, 0.0, 1.0);
    GLRenderer::begin(v7, eLines, 0);
    GLRenderer::vertex3f(v7, 0.0, 0.0, 0.0);
    GLRenderer::vertex3f(v7, 1.0, 0.0, 0.0);
    GLRenderer::color4f(v7, 0.0, 3.0, 0.0, 1.0);
    GLRenderer::vertex3f(v7, 0.0, 0.0, 0.0);
    GLRenderer::vertex3f(v7, 0.0, 1.0, 0.0);
    GLRenderer::color4f(v7, 0.0, 0.0, 3.0, 1.0);
    GLRenderer::vertex3f(v7, 0.0, 0.0, 0.0);
    GLRenderer::vertex3f(v7, 0.0, 0.0, 1.0);
    GLRenderer::end(v7);
  }
  else if ( this->axis3d )
  {
    CameraMeshFilter::CameraMeshFilter(&filter, this, Opaque, (int)this->maxLayer);
    v13 = 0;
    MaterialFilter::MaterialFilter(&materialFilter);
    v6 = this->graphics;
    rc.materialFilter = &materialFilter;
    LOBYTE(v13) = 1;
    rc.meshFilter = &filter;
    rc.graphics = v6;
    rc.camera = 0;
    GraphicsManager::setDepthMode(v6, eDepthNormal);
    rc.camera = this;
    FolderEncrypter::FolderEncrypter((std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > *)&useZBuffer);
    a = this->axis3d;
    LOBYTE(v13) = 2;
    WorldMatrixTraverser::traverse((WorldMatrixTraverser *)&useZBuffer, a);
    this->axis3d->render(this->axis3d, &rc);
    LOBYTE(v13) = 1;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&useZBuffer);
    LOBYTE(v13) = 0;
    MaterialFilter::~MaterialFilter(&materialFilter);
    v13 = -1;
    CameraMeshFilter::~CameraMeshFilter(&filter);
  }
  if ( !v3 )
    GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
}
void Camera::renderCamera(Camera *this)
{
  mat44f *v2; // eax
  __m128 v3; // xmm0
  __int128 v4; // xmm1
  __int128 v5; // xmm2
  __int128 v6; // xmm3
  __int128 v7; // xmm1
  __int128 v8; // xmm2
  __int128 v9; // xmm3
  vec3f scale; // [esp+4h] [ebp-14Ch] BYREF
  mat44f matrix; // [esp+10h] [ebp-140h] BYREF
  DirectX::XMMATRIX M2; // [esp+50h] [ebp-100h] BYREF
  mat44f v13; // [esp+90h] [ebp-C0h] BYREF
  mat44f value; // [esp+D0h] [ebp-80h] BYREF
  mat44f result; // [esp+110h] [ebp-40h] BYREF

  this->getPerspectiveMatrix(this, &matrix);
  if ( this->isMirror )
  {
    scale.x = -1.0;
    scale.y = 1.0;
    scale.z = 1.0;
    v2 = mat44f::createScale(&result, &scale);
    M2.r[0] = *(__m128 *)&matrix.M11;
    v3 = *(__m128 *)&v2->M11;
    M2.r[1] = *(__m128 *)&matrix.M21;
    v4 = *(_OWORD *)&v2->M21;
    M2.r[2] = *(__m128 *)&matrix.M31;
    v5 = *(_OWORD *)&v2->M31;
    M2.r[3] = *(__m128 *)&matrix.M41;
    v6 = *(_OWORD *)&v2->M41;
    *(__m128 *)&matrix.M11 = DirectX::XMMatrixMultiply(M2.r, v3);
    *(_OWORD *)&matrix.M21 = v4;
    *(_OWORD *)&matrix.M31 = v5;
    *(_OWORD *)&matrix.M41 = v6;
  }
  this->getViewMatrix(this, &v13);
  GraphicsManager::setProjectionMatrix(this->graphics, &matrix);
  GraphicsManager::setViewMatrix(this->graphics, &v13, this);
  mat44f::mat44f(&value);
  M2 = (DirectX::XMMATRIX)matrix;
  v7 = *(_OWORD *)&v13.M21;
  v8 = *(_OWORD *)&v13.M31;
  v9 = *(_OWORD *)&v13.M41;
  *(__m128 *)&value.M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v13.M11);
  *(_OWORD *)&value.M21 = v7;
  *(_OWORD *)&value.M31 = v8;
  *(_OWORD *)&value.M41 = v9;
  BoundingFrustum::setMatrix(&this->frustum, &value);
}
void Camera::renderCameraCustomPerspective(Camera *this, float left, float right, float top, float bottom)
{
  mat44f *v6; // eax
  __m128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm2
  __int128 v10; // xmm3
  float v11; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  __m128 v17; // xmm0
  __int128 v18; // xmm1
  __int128 v19; // xmm2
  __int128 v20; // xmm3
  vec3f scale; // [esp+24h] [ebp-164h] BYREF
  vec3f cameraTarget; // [esp+30h] [ebp-158h] BYREF
  vec3f cameraPosition; // [esp+3Ch] [ebp-14Ch] BYREF
  mat44f result; // [esp+48h] [ebp-140h] BYREF
  DirectX::XMMATRIX M2; // [esp+88h] [ebp-100h] BYREF
  mat44f value; // [esp+C8h] [ebp-C0h] BYREF
  mat44f matrix; // [esp+108h] [ebp-80h] BYREF
  mat44f v28; // [esp+148h] [ebp-40h] BYREF

  mat44f::createPerspectiveOffCenter(&result, left, right, top, bottom, this->nearPlane, this->farPlane);
  if ( this->isMirror )
  {
    scale.x = -1.0;
    scale.y = 1.0;
    scale.z = 1.0;
    v6 = mat44f::createScale(&v28, &scale);
    M2.r[0] = *(__m128 *)&result.M11;
    v7 = *(__m128 *)&v6->M11;
    M2.r[1] = *(__m128 *)&result.M21;
    v8 = *(_OWORD *)&v6->M21;
    M2.r[2] = *(__m128 *)&result.M31;
    v9 = *(_OWORD *)&v6->M31;
    M2.r[3] = *(__m128 *)&result.M41;
    v10 = *(_OWORD *)&v6->M41;
    *(__m128 *)&result.M11 = DirectX::XMMatrixMultiply(M2.r, v7);
    *(_OWORD *)&result.M21 = v8;
    *(_OWORD *)&result.M31 = v9;
    *(_OWORD *)&result.M41 = v10;
  }
  v11 = this->matrix.M31;
  v12 = this->matrix.M32;
  v13 = this->matrix.M33;
  v14 = this->matrix.M42;
  v15 = this->matrix.M43;
  scale = *(vec3f *)&this->matrix.M21;
  v16 = this->matrix.M41 + COERCE_FLOAT(LODWORD(v11) ^ _xmm);
  cameraTarget.y = v14 + COERCE_FLOAT(LODWORD(v12) ^ _xmm);
  cameraTarget.x = v16;
  cameraPosition.x = this->matrix.M41;
  cameraPosition.y = this->matrix.M42;
  v17 = (__m128)LODWORD(this->matrix.M43);
  cameraTarget.z = v15 + COERCE_FLOAT(LODWORD(v13) ^ _xmm);
  LODWORD(cameraPosition.z) = v17.m128_i32[0];
  mat44f::createLookAt(v17, &matrix, &cameraPosition, &cameraTarget, &scale);
  GraphicsManager::setProjectionMatrix(this->graphics, &result);
  GraphicsManager::setViewMatrix(this->graphics, &matrix, this);
  mat44f::mat44f(&value);
  M2 = (DirectX::XMMATRIX)result;
  v18 = *(_OWORD *)&matrix.M21;
  v19 = *(_OWORD *)&matrix.M31;
  v20 = *(_OWORD *)&matrix.M41;
  *(__m128 *)&value.M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&matrix.M11);
  *(_OWORD *)&value.M21 = v18;
  *(_OWORD *)&value.M31 = v19;
  *(_OWORD *)&value.M41 = v20;
  BoundingFrustum::setMatrix(&this->frustum, &value);
}
void __userpurge Camera::rotateHeading(Camera *this@<ecx>, int a2@<esi>, float rads)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm1
  __m128 v6; // xmm0
  __int128 v7; // xmm2
  __int128 v8; // xmm1
  __int128 v9; // xmm3
  float v11; // [esp+4h] [ebp-88h]
  float v12; // [esp+8h] [ebp-84h]
  mat44f v13; // [esp+Ch] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+4Ch] [ebp-40h] BYREF

  v11 = __libm_sse2_cosf(a2, LODWORD(rads)).m128_f32[0];
  v12 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f(&v13);
  v13.M44 = 1.0;
  v13.M22 = (float)(1.0 - v11) + v11;
  M2.r[2] = *(__m128 *)&this->matrix.M31;
  v13.M33 = (float)((float)(1.0 - v11) * 0.0) + v11;
  v13.M11 = v13.M33;
  v13.M12 = (float)(v12 * 0.0) + (float)((float)(1.0 - v11) * 0.0);
  v13.M21 = (float)((float)(1.0 - v11) * 0.0) - (float)(v12 * 0.0);
  v13.M13 = (float)((float)(1.0 - v11) * 0.0) - v12;
  v13.M31 = v12 + (float)((float)(1.0 - v11) * 0.0);
  v4 = *(__m128 *)&this->matrix.M41;
  v5 = *(__m128 *)&this->matrix.M21;
  v13.M23 = v13.M12;
  v6 = *(__m128 *)&this->matrix.M11;
  v13.M32 = v13.M21;
  v7 = *(_OWORD *)&v13.M31;
  M2.r[0] = v6;
  M2.r[1] = v5;
  v8 = *(_OWORD *)&v13.M21;
  M2.r[3] = v4;
  v9 = *(_OWORD *)&v13.M41;
  *(__m128 *)&this->matrix.M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v13.M11);
  *(_OWORD *)&this->matrix.M21 = v8;
  *(_OWORD *)&this->matrix.M31 = v7;
  *(_OWORD *)&this->matrix.M41 = v9;
}
void __userpurge Camera::rotateOnAxis(Camera *this@<ecx>, int a2@<edi>, int a3@<esi>, const vec3f *axis, float rads)
{
  float v6; // xmm6_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  __int128 v15; // xmm3
  float v16; // xmm1_4
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __int128 v20; // xmm1
  __int128 v21; // xmm2
  float v23; // [esp+10h] [ebp-88h]
  float v24; // [esp+14h] [ebp-84h]
  mat44f v25; // [esp+18h] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+58h] [ebp-40h] BYREF

  v23 = __libm_sse2_cosf(a2, a3).m128_f32[0];
  v24 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f(&v25);
  v6 = axis->x;
  v7 = axis->y;
  v25.M44 = 1.0;
  v8 = axis->z;
  v9 = (float)(v7 * v6) * (float)(1.0 - v23);
  v25.M11 = (float)((float)(v6 * v6) * (float)(1.0 - v23)) + v23;
  v25.M22 = (float)((float)(v7 * v7) * (float)(1.0 - v23)) + v23;
  v25.M33 = (float)((float)(v8 * v8) * (float)(1.0 - v23)) + v23;
  v10 = v7 * v24;
  v25.M12 = (float)(v8 * v24) + v9;
  v25.M21 = v9 - (float)(v8 * v24);
  v11 = (float)(v8 * v6) * (float)(1.0 - v23);
  v12 = v6 * v24;
  v13 = (float)(v8 * v7) * (float)(1.0 - v23);
  v14 = v11 - (float)(v7 * v24);
  M2.r[3] = *(__m128 *)&this->matrix.M41;
  v15 = *(_OWORD *)&v25.M41;
  v16 = v10 + v11;
  v17 = *(__m128 *)&this->matrix.M31;
  v25.M13 = v14;
  v25.M31 = v16;
  v18 = *(__m128 *)&this->matrix.M21;
  M2.r[2] = v17;
  M2.r[1] = v18;
  v25.M23 = v12 + v13;
  v19 = *(__m128 *)&this->matrix.M11;
  v20 = *(_OWORD *)&v25.M21;
  v25.M32 = v13 - v12;
  v21 = *(_OWORD *)&v25.M31;
  M2.r[0] = v19;
  *(__m128 *)&this->matrix.M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v25.M11);
  *(_OWORD *)&this->matrix.M21 = v20;
  *(_OWORD *)&this->matrix.M31 = v21;
  *(_OWORD *)&this->matrix.M41 = v15;
}
void __userpurge Camera::rotatePitch(Camera *this@<ecx>, int a2@<esi>, float rads)
{
  __m128 v4; // xmm0
  __int128 v5; // xmm1
  __m128 v6; // xmm3
  __int128 v7; // xmm2
  __int128 v8; // xmm3
  float v10; // [esp+4h] [ebp-88h]
  float v11; // [esp+8h] [ebp-84h]
  mat44f v12; // [esp+Ch] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+4Ch] [ebp-40h] BYREF

  v10 = __libm_sse2_cosf(a2, LODWORD(rads)).m128_f32[0];
  v11 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f(&v12);
  v12.M44 = 1.0;
  v12.M11 = (float)(1.0 - v10) + v10;
  M2.r[1] = *(__m128 *)&this->matrix.M21;
  v12.M22 = (float)((float)(1.0 - v10) * 0.0) + v10;
  v12.M33 = v12.M22;
  v12.M12 = (float)(v11 * 0.0) + (float)((float)(1.0 - v10) * 0.0);
  v12.M21 = (float)((float)(1.0 - v10) * 0.0) - (float)(v11 * 0.0);
  v12.M13 = v12.M21;
  v12.M31 = v12.M12;
  M2.r[2] = *(__m128 *)&this->matrix.M31;
  v12.M23 = v11 + (float)((float)(1.0 - v10) * 0.0);
  v4 = *(__m128 *)&this->matrix.M11;
  v5 = *(_OWORD *)&v12.M21;
  v12.M32 = (float)((float)(1.0 - v10) * 0.0) - v11;
  v6 = *(__m128 *)&this->matrix.M41;
  v7 = *(_OWORD *)&v12.M31;
  M2.r[0] = v4;
  M2.r[3] = v6;
  v8 = *(_OWORD *)&v12.M41;
  *(__m128 *)&this->matrix.M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v12.M11);
  *(_OWORD *)&this->matrix.M21 = v5;
  *(_OWORD *)&this->matrix.M31 = v7;
  *(_OWORD *)&this->matrix.M41 = v8;
}
void __userpurge Camera::rotateRoll(Camera *this@<ecx>, int a2@<esi>, float rads)
{
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __int128 v6; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __int128 v9; // xmm2
  __int128 v10; // xmm1
  float v12; // [esp+4h] [ebp-88h]
  float v13; // [esp+8h] [ebp-84h]
  mat44f v14; // [esp+Ch] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+4Ch] [ebp-40h] BYREF

  v12 = __libm_sse2_cosf(a2, LODWORD(rads)).m128_f32[0];
  v13 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f(&v14);
  v14.M44 = 1.0;
  v4 = *(__m128 *)&this->matrix.M31;
  v14.M33 = (float)(1.0 - v12) + v12;
  M2.r[2] = v4;
  v14.M22 = (float)((float)(1.0 - v12) * 0.0) + v12;
  v14.M11 = v14.M22;
  v14.M12 = v13 + (float)((float)(1.0 - v12) * 0.0);
  v5 = *(__m128 *)&this->matrix.M41;
  v14.M21 = (float)((float)(1.0 - v12) * 0.0) - v13;
  M2.r[3] = v5;
  v6 = *(_OWORD *)&v14.M41;
  v14.M13 = (float)((float)(1.0 - v12) * 0.0) - (float)(v13 * 0.0);
  v14.M31 = (float)(v13 * 0.0) + (float)((float)(1.0 - v12) * 0.0);
  v7 = *(__m128 *)&this->matrix.M21;
  v14.M23 = v14.M31;
  v8 = *(__m128 *)&this->matrix.M11;
  v14.M32 = v14.M13;
  v9 = *(_OWORD *)&v14.M31;
  M2.r[0] = v8;
  M2.r[1] = v7;
  v10 = *(_OWORD *)&v14.M21;
  *(__m128 *)&this->matrix.M11 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v14.M11);
  *(_OWORD *)&this->matrix.M21 = v10;
  *(_OWORD *)&this->matrix.M31 = v9;
  *(_OWORD *)&this->matrix.M41 = v6;
}
void Camera::setClearColor(Camera *this, float r, float g, float b, float a)
{
  __m128i v5; // [esp+0h] [ebp-10h] BYREF

  v5.m128i_i64[0] = __PAIR64__(LODWORD(g), LODWORD(r));
  v5.m128i_i64[1] = __PAIR64__(LODWORD(a), LODWORD(b));
  this->clearColor = (vec4f)_mm_loadu_si128(&v5);
}
