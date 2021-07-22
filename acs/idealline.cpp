#include "idealline.h"
void IdealLine::IdealLine(IdealLine *this, AISpline *spline, GraphicsManager *graphics, IRayTrackCollisionProvider *collisionProvider)
{
  unsigned int v5; // ebx
  IRayTrackCollisionProvider *v6; // ebp
  float v7; // xmm1_4
  float v8; // xmm0_4
  IRayTrackCollisionProvider_vtbl *v9; // esi
  vec3f *v10; // eax
  double v11; // st7
  float v12; // xmm0_4
  IRayTrackCollisionProvider_vtbl *v13; // esi
  vec3f *v14; // eax
  Mesh *v15; // eax
  Spline *v16; // esi
  GraphicsManager *v17; // ebp
  Material *v18; // eax
  std::_Ref_count_base *v19; // esi
  Mesh *v20; // eax
  Mesh *v21; // eax
  Material *v22; // eax
  ResourceStore *v23; // ecx
  Mesh *v24; // eax
  std::wstring v25; // [esp+8h] [ebp-26Ch] BYREF
  float pos; // [esp+20h] [ebp-254h]
  float splinePosition; // [esp+38h] [ebp-23Ch]
  float v28; // [esp+3Ch] [ebp-238h]
  Spline *v29; // [esp+40h] [ebp-234h]
  std::shared_ptr<Material> _Right; // [esp+44h] [ebp-230h] BYREF
  float v31; // [esp+4Ch] [ebp-228h]
  float v32; // [esp+50h] [ebp-224h]
  int v33; // [esp+54h] [ebp-220h]
  vec3f color; // [esp+58h] [ebp-21Ch] BYREF
  vec3f normal; // [esp+64h] [ebp-210h] BYREF
  IRayTrackCollisionProvider *v36; // [esp+70h] [ebp-204h]
  int v37[3]; // [esp+74h] [ebp-200h] BYREF
  RayCastResult res; // [esp+80h] [ebp-1F4h] BYREF
  IdealLine *v39; // [esp+A4h] [ebp-1D0h]
  std::wstring v40; // [esp+A8h] [ebp-1CCh] BYREF
  std::wstring p; // [esp+C0h] [ebp-1B4h] BYREF
  std::wstring n; // [esp+D8h] [ebp-19Ch] BYREF
  Texture v43; // [esp+F0h] [ebp-184h] BYREF
  char v44; // [esp+10Ch] [ebp-168h]
  int v45; // [esp+110h] [ebp-164h]
  SplineStripBuilder b; // [esp+114h] [ebp-160h] BYREF
  AISplinePayload result; // [esp+178h] [ebp-FCh] BYREF
  AISplinePayload pl; // [esp+1CCh] [ebp-A8h] BYREF
  INIReaderDocuments ini; // [esp+220h] [ebp-54h] BYREF
  int v50; // [esp+270h] [ebp-4h]

  v5 = (unsigned int)spline;
  v36 = collisionProvider;
  v33 = 0;
  v39 = this;
  _Right._Ptr = (Material *)graphics;
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  std::wstring::assign(&n, L"IDEAL_LINE", 0xAu);
  v50 = 0;
  Node::Node(this, &n);
  LOBYTE(v50) = 2;
  if ( n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  n._Myres = 7;
  pos = *(float *)&graphics;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  this->__vftable = (IdealLine_vtbl *)&IdealLine::`vftable';
  this->idealLineMesh = 0;
  SplineStripBuilder::SplineStripBuilder(&b, (GraphicsManager *)LODWORD(pos));
  pos = 0.0;
  b.textureStep = 4.0;
  b.width = 2.0;
  LOBYTE(v50) = 3;
  v25._Myres = 7;
  v25._Mysize = 0;
  v25._Bx._Buf[0] = 0;
  std::wstring::assign(&v25, L"cfg/assists.ini", 0xFu);
  INIReaderDocuments::INIReaderDocuments(&ini, (unsigned int)spline, v25, SLOBYTE(pos));
  v6 = v36;
  v7 = 0.0;
  splinePosition = 0.0;
  v32 = 0.0;
  LOBYTE(v50) = 4;
  v31 = 0.0;
  v29 = &spline->spline;
  v28 = FLOAT_0_5;
  do
  {
    AISpline::payloadAtPosition(spline, &result, v7);
    splinePosition = FLOAT_0_5;
    if ( result.brake <= 0.1 )
    {
      if ( result.gas <= 0.89999998 )
        goto LABEL_9;
      v8 = FLOAT_1_0;
    }
    else
    {
      v8 = 0.0;
    }
    splinePosition = v8;
LABEL_9:
    v9 = v6->__vftable;
    pos = 100.0;
    v25._Myres = (unsigned int)&v43;
    v43.fileName._Mysize = 0;
    v25._Mysize = (unsigned int)v37;
    v43.fileName._Bx = 0i64;
    v43.fileName._Myres = 0;
    v43.kid = 0;
    v44 = 0;
    v45 = 0;
    v37[0] = 0;
    v37[1] = -1082130432;
    v37[2] = 0;
    v10 = InterpolatingSpline::splineToWorld(&spline->spline, (vec3f *)&v40, v31);
    ((void (*)(IRayTrackCollisionProvider *, vec3f *, unsigned int, unsigned int, _DWORD))v9->rayCast)(
      v6,
      v10,
      v25._Mysize,
      v25._Myres,
      LODWORD(pos));
    color.y = splinePosition * 3.0;
    color.x = (float)(1.0 - splinePosition) * 3.0;
    color.z = 0.0;
    normal.x = 0.0;
    normal.y = 1.0;
    normal.z = 0.0;
    p._Bx._Ptr = v43.fileName._Bx._Ptr;
    *(float *)&p._Bx._Alias[4] = *(float *)&v43.fileName._Bx._Alias[4] + 0.090000004;
    *(_DWORD *)&p._Bx._Alias[8] = *(_DWORD *)&v43.fileName._Bx._Alias[8];
    SplineStripBuilder::addPoint(&b, (const vec3f *)&p, &normal, &color, 1.0);
    v11 = Spline::length(&spline->spline);
    v32 = 5.0 / v11 + v32;
    splinePosition = v32;
    v7 = v32;
    v31 = v32;
  }
  while ( v32 < 1.0 );
  pos = 5.0 / Spline::length(&spline->spline);
  AISpline::payloadAtPosition(spline, &pl, pos);
  if ( pl.brake > 0.1 )
  {
    v12 = 0.0;
    goto LABEL_14;
  }
  if ( pl.gas > 0.89999998 )
  {
    v12 = FLOAT_1_0;
LABEL_14:
    v28 = v12;
  }
  v13 = v6->__vftable;
  pos = 100.0;
  v25._Myres = (unsigned int)&res;
  res.normal.y = 0.0;
  v25._Mysize = (unsigned int)&p;
  *(_OWORD *)&res.pos.x = 0i64;
  res.normal.z = 0.0;
  res.surfaceDef = 0;
  res.hasHit = 0;
  res.collisionObject = 0;
  *(_QWORD *)p._Bx._Buf = 0xBF80000000000000ui64;
  *(_DWORD *)&p._Bx._Alias[8] = 0;
  *(float *)&v25._Bx._Alias[12] = 5.0 / Spline::length(v29);
  v14 = InterpolatingSpline::splineToWorld((InterpolatingSpline *)v29, (vec3f *)&v40, *(float *)&v25._Bx._Alias[12]);
  ((void (*)(IRayTrackCollisionProvider *, vec3f *, unsigned int, unsigned int, _DWORD))v13->rayCast)(
    v6,
    v14,
    v25._Mysize,
    v25._Myres,
    LODWORD(pos));
  *(float *)&p._Bx._Alias[4] = v28 * 3.0;
  *(float *)&p._Bx._Ptr = (float)(1.0 - v28) * 3.0;
  *(_DWORD *)&p._Bx._Alias[8] = 0;
  normal.x = 0.0;
  normal.y = 1.0;
  normal.z = 0.0;
  color.x = res.pos.x;
  color.y = res.pos.y + 0.090000004;
  color.z = res.pos.z;
  SplineStripBuilder::addPoint(&b, &color, &normal, (const vec3f *)&p, 1.0);
  v15 = SplineStripBuilder::buildMesh(&b);
  LODWORD(pos) = 104;
  this->idealLineMesh = v15;
  v16 = (Spline *)operator new(LODWORD(pos));
  v29 = v16;
  v17 = (GraphicsManager *)_Right._Ptr;
  LOBYTE(v50) = 5;
  if ( v16 )
  {
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, L"IDEAL_LINE", 0xAu);
    LOBYTE(v50) = 6;
    v33 = 1;
    Material::Material((Material *)v16, &v40, v17);
  }
  else
  {
    v18 = 0;
  }
  v50 = 7;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Material>::_Resetp<Material>(&_Right, v18);
  std::shared_ptr<Material>::operator=(&this->idealLineMesh->material, &_Right);
  v19 = _Right._Rep;
  if ( _Right._Rep )
  {
    v5 = -1;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v19->_Destroy(v19);
      v5 = _InterlockedDecrement((volatile signed __int32 *)&v19->_Weaks);
      if ( !v5 )
        v19->_Delete_this(v19);
    }
  }
  v50 = 4;
  if ( (v33 & 1) != 0 && v40._Myres >= 8 )
    operator delete(v40._Bx._Ptr);
  v40._Myres = 7;
  v40._Mysize = 0;
  v40._Bx._Buf[0] = 0;
  std::wstring::assign(&v40, L"ksIdealLine", 0xBu);
  v20 = this->idealLineMesh;
  LOBYTE(v50) = 8;
  Material::setShader(v20->material._Ptr, v5, &v40);
  LOBYTE(v50) = 4;
  if ( v40._Myres >= 8 )
    operator delete(v40._Bx._Ptr);
  v21 = this->idealLineMesh;
  LODWORD(pos) = 30;
  v25._Myres = (unsigned int)L"content/texture/ideal_line.png";
  p._Myres = 7;
  v22 = v21->material._Ptr;
  p._Mysize = 0;
  v22->blendMode = eAlphaBlend;
  this->idealLineMesh->isTransparent = 1;
  this->idealLineMesh->castShadows = 0;
  p._Bx._Buf[0] = 0;
  std::wstring::assign(&p, (const wchar_t *)v25._Myres, LODWORD(pos));
  LOBYTE(v50) = 9;
  v40._Myres = 7;
  v40._Mysize = 0;
  v40._Bx._Buf[0] = 0;
  std::wstring::assign(&v40, L"txDiffuse", 9u);
  v23 = v17->resourceStore._Myptr;
  LOBYTE(v50) = 10;
  pos = COERCE_FLOAT(ResourceStore::getTexture(v23, &v43, &p, 0));
  v24 = this->idealLineMesh;
  LOBYTE(v50) = 11;
  Material::setTexture(v24->material._Ptr, &v40, (const Texture *)LODWORD(pos));
  LOBYTE(v50) = 10;
  OnSetupAppCreated::~OnSetupAppCreated(&v43);
  if ( v40._Myres >= 8 )
    operator delete(v40._Bx._Ptr);
  v40._Myres = 7;
  v40._Mysize = 0;
  v40._Bx._Buf[0] = 0;
  LOBYTE(v50) = 4;
  if ( p._Myres >= 8 )
    operator delete(p._Bx._Ptr);
  Node::addChild(this, this->idealLineMesh);
  LOBYTE(v50) = 3;
  INIReaderDocuments::~INIReaderDocuments(&ini);
  LOBYTE(v50) = 2;
  SplineStripBuilder::~SplineStripBuilder(&b);
}
IdealLine *IdealLine::`vector deleting destructor'(IdealLine *this, unsigned int a2)
{
  this->__vftable = (IdealLine_vtbl *)&IdealLine::`vftable';
  Node::~Node(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
