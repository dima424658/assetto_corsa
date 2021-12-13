#include "rigidbodyode.h"
void RigidBodyODE::RigidBodyODE(RigidBodyODE *this, PhysicsCore *core)
{
  int v3; // edx
  unsigned int v4; // ecx
  dxBody *v5; // eax
  dxBody *v6; // eax
  dxBody *v7; // eax

  this->__vftable = (RigidBodyODE_vtbl *)&RigidBodyODE::`vftable';
  this->geoms._Myfirst = 0;
  this->geoms._Mylast = 0;
  this->geoms._Myend = 0;
  this->core = core;
  this->collisionMeshes._Myfirst = 0;
  this->collisionMeshes._Mylast = 0;
  this->collisionMeshes._Myend = 0;
  v3 = dBodyCreate((_DWORD *)core->id);
  this->id = (dxBody *)v3;
  v4 = *(_DWORD *)(v3 + 28) & 0xFFFFFFFD | 1;
  *(_DWORD *)(v3 + 28) = v4;
  if ( *(float *)(v3 + 300) != 0.0 || *(float *)(v3 + 304) != 0.0 || *(float *)(v3 + 308) != 0.0 )
    *(_DWORD *)(v3 + 28) = v4 | 2;
  v5 = this->id;
  *((_DWORD *)v5 + 7) &= 0xFFFFFFFD;
  *((_DWORD *)v5 + 75) = 0;
  *((_DWORD *)v5 + 76) = 0;
  *((_DWORD *)v5 + 77) = 0;
  v6 = this->id;
  *((_DWORD *)v6 + 7) &= 0xFFFFFFDF;
  *((_DWORD *)v6 + 91) = 0;
  v7 = this->id;
  *((_DWORD *)v7 + 7) &= 0xFFFFFFBF;
  *((_DWORD *)v7 + 92) = 0;
  *((_DWORD *)this->id + 5) = this;
}
RigidBodyODE *RigidBodyODE::`vector deleting destructor'(RigidBodyODE *this, unsigned int a2)
{
  RigidBodyODE::~RigidBodyODE(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void RigidBodyODE::~RigidBodyODE(RigidBodyODE *this)
{
  dxBody *v2; // ecx
  std::shared_ptr<BodyCollisionMesh> *v3; // ecx

  v2 = this->id;
  this->__vftable = (RigidBodyODE_vtbl *)&RigidBodyODE::`vftable';
  if ( v2 )
    dBodyDestroy(v2);
  v3 = this->collisionMeshes._Myfirst;
  if ( v3 )
  {
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::shared_ptr<BodyCollisionMesh>>>>(
      v3,
      this->collisionMeshes._Mylast);
    operator delete(this->collisionMeshes._Myfirst);
    this->collisionMeshes._Myfirst = 0;
    this->collisionMeshes._Mylast = 0;
    this->collisionMeshes._Myend = 0;
  }
  if ( this->geoms._Myfirst )
  {
    operator delete(this->geoms._Myfirst);
    this->geoms._Myfirst = 0;
    this->geoms._Mylast = 0;
    this->geoms._Myend = 0;
  }
  this->__vftable = (RigidBodyODE_vtbl *)&IRigidBody::`vftable';
}
double RigidBodyODE::getMass(RigidBodyODE *this)
{
  dMass lmass; // [esp+4h] [ebp-48h] BYREF

  dMassSetZero(&lmass);
  return *(float *)_mm_loadu_si128((const __m128i *)((char *)this->id + 36)).m128i_i32;
}
void RigidBodyODE::release(RigidBodyODE *this)
{
  if ( this )
    ((void (*)(RigidBodyODE *, int))this->~IRigidBody)(this, 1);
}
void RigidBodyODE::setMassExplicitInertia(RigidBodyODE *this, float totalMass, float x, float y, float z)
{
  dxBody *v6; // esi
  float v7; // eax
  dMass m; // [esp+8h] [ebp-48h] BYREF

  dMassSetZero(&m);
  dMassSetZero(&m);
  v6 = this->id;
  m.mass = totalMass;
  v7 = m.I[11];
  m.I[0] = x;
  m.I[4] = y;
  m.I[8] = z;
  *(__m128i *)((char *)v6 + 36) = _mm_loadu_si128((const __m128i *)&m);
  *(__m128i *)((char *)v6 + 52) = _mm_loadu_si128((const __m128i *)&m.c[3]);
  *(__m128i *)((char *)v6 + 68) = _mm_loadu_si128((const __m128i *)&m.I[3]);
  *(__m128i *)((char *)v6 + 84) = _mm_loadu_si128((const __m128i *)&m.I[7]);
  *((float *)v6 + 25) = v7;
  if ( !_dInvertPDMatrix((char *)v6 + 56, (unsigned int)v6 + 104) )
    dRSetIdentity((_DWORD *)v6 + 26);
  *((float *)v6 + 38) = 1.0 / *((float *)v6 + 9);
}
void RigidBodyODE::setMassBox(RigidBodyODE *this, float m, float x, float y, float z)
{
  dxBody *v6; // esi
  float v7; // eax
  __m128i v8; // xmm0
  dMass mass; // [esp+8h] [ebp-48h] BYREF

  dMassSetZero(&mass);
  dMassSetZero(&mass);
  v6 = this->id;
  v7 = mass.I[11];
  mass.mass = m;
  mass.I[0] = (float)((float)(z * z) + (float)(y * y)) * (float)(m * 0.083333336);
  mass.I[5] = (float)((float)(x * x) + (float)(z * z)) * (float)(m * 0.083333336);
  v8 = _mm_loadu_si128((const __m128i *)&mass);
  mass.I[10] = (float)((float)(x * x) + (float)(y * y)) * (float)(m * 0.083333336);
  *(__m128i *)((char *)v6 + 36) = v8;
  *(__m128i *)((char *)v6 + 52) = _mm_loadu_si128((const __m128i *)&mass.c[3]);
  *(__m128i *)((char *)v6 + 68) = _mm_loadu_si128((const __m128i *)&mass.I[3]);
  *(__m128i *)((char *)v6 + 84) = _mm_loadu_si128((const __m128i *)&mass.I[7]);
  *((float *)v6 + 25) = v7;
  if ( !_dInvertPDMatrix((char *)v6 + 56, (unsigned int)v6 + 104) )
    dRSetIdentity((_DWORD *)v6 + 26);
  *((float *)v6 + 38) = 1.0 / *((float *)v6 + 9);
}
vec3f *RigidBodyODE::getLocalInertia(RigidBodyODE *this, vec3f *result)
{
  dxBody *v3; // eax
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  vec3f *v7; // eax
  dMass mass; // [esp+8h] [ebp-48h] BYREF

  dMassSetZero(&mass);
  v3 = this->id;
  v4 = (__m128)_mm_loadu_si128((const __m128i *)((char *)v3 + 68));
  v5 = (__m128)_mm_loadu_si128((const __m128i *)((char *)v3 + 84));
  *(__m128i *)&mass.mass = _mm_loadu_si128((const __m128i *)((char *)v3 + 36));
  v6 = (__m128)_mm_loadu_si128((const __m128i *)((char *)v3 + 52));
  v7 = result;
  LODWORD(result->x) = _mm_shuffle_ps(v6, v6, 85).m128_u32[0];
  LODWORD(result->y) = _mm_shuffle_ps(v4, v4, 170).m128_u32[0];
  LODWORD(result->z) = _mm_shuffle_ps(v5, v5, 255).m128_u32[0];
  return v7;
}
mat44f *RigidBodyODE::getWorldMatrix(RigidBodyODE *this, mat44f *result, float interpolationT)
{
  float *v3; // edi
  mat44f *v4; // eax

  v3 = (float *)this->id;
  mat44f::mat44f(result);
  result->M11 = v3[43];
  result->M12 = v3[47];
  result->M13 = v3[51];
  result->M14 = 0.0;
  result->M21 = v3[44];
  result->M22 = v3[48];
  result->M23 = v3[52];
  result->M24 = 0.0;
  result->M31 = v3[45];
  result->M32 = v3[49];
  v4 = result;
  result->M33 = v3[53];
  result->M34 = 0.0;
  result->M41 = v3[39];
  result->M42 = v3[40];
  result->M43 = v3[41];
  result->M44 = 1.0;
  return v4;
}
vec3f *RigidBodyODE::localToWorld(RigidBodyODE *this, vec3f *result, const vec3f *p)
{
  float *v3; // ecx
  float v4; // xmm4_4
  float v5; // xmm5_4
  vec3f *v6; // eax
  float v7; // xmm2_4
  float v8; // xmm1_4

  v3 = (float *)this->id;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  v4 = p->y;
  v5 = p->z;
  v6 = result;
  v7 = (float)((float)(v3[48] * v4) + (float)(v3[47] * p->x)) + (float)(v3[49] * v5);
  v8 = (float)((float)(v3[52] * v4) + (float)(p->x * v3[51])) + (float)(v3[53] * v5);
  result->x = v3[39] + (float)((float)((float)(v3[44] * v4) + (float)(v3[43] * p->x)) + (float)(v3[45] * v5));
  result->y = v3[40] + v7;
  result->z = v3[41] + v8;
  return v6;
}
vec3f *RigidBodyODE::worldToLocal(RigidBodyODE *this, vec3f *result, const vec3f *p)
{
  float *v3; // ecx
  float v4; // xmm6_4
  float v5; // xmm4_4
  vec3f *v6; // eax
  float v7; // xmm5_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  v3 = (float *)this->id;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  v4 = p->x - v3[39];
  v5 = p->y - v3[40];
  v6 = result;
  v7 = p->z - v3[41];
  v8 = (float)((float)(v3[49] * v5) + (float)(v3[45] * v4)) + (float)(v3[53] * v7);
  v9 = (float)(v3[47] * v5) + (float)(v3[43] * v4);
  v10 = v3[51] * v7;
  result->y = (float)((float)(v3[48] * v5) + (float)(v3[44] * v4)) + (float)(v3[52] * v7);
  result->z = v8;
  result->x = v9 + v10;
  return v6;
}
vec3f *RigidBodyODE::localToWorldNormal(RigidBodyODE *this, vec3f *result, const vec3f *p)
{
  float *v3; // ecx
  float v4; // xmm3_4
  float v5; // xmm5_4
  vec3f *v6; // eax
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4

  v3 = (float *)((char *)this->id + 172);
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  v4 = p->y;
  v5 = p->z;
  v6 = result;
  v7 = (float)((float)(v3[9] * v4) + (float)(v3[8] * p->x)) + (float)(v3[10] * v5);
  v8 = (float)(v3[1] * v4) + (float)(*v3 * p->x);
  v9 = v3[2] * v5;
  result->y = (float)((float)(v3[5] * v4) + (float)(v3[4] * p->x)) + (float)(v3[6] * v5);
  result->z = v7;
  result->x = v8 + v9;
  return v6;
}
vec3f *RigidBodyODE::worldToLocalNormal(RigidBodyODE *this, vec3f *result, const vec3f *p)
{
  float *v3; // ecx
  float v4; // xmm3_4
  float v5; // xmm5_4
  vec3f *v6; // eax
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4

  v3 = (float *)((char *)this->id + 172);
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  v4 = p->y;
  v5 = p->z;
  v6 = result;
  v7 = (float)((float)(v3[6] * v4) + (float)(v3[2] * p->x)) + (float)(v3[10] * v5);
  v8 = (float)(v3[4] * v4) + (float)(*v3 * p->x);
  v9 = v3[8] * v5;
  result->y = (float)((float)(v3[5] * v4) + (float)(v3[1] * p->x)) + (float)(v3[9] * v5);
  result->z = v7;
  result->x = v8 + v9;
  return v6;
}
void RigidBodyODE::stop(RigidBodyODE *this, float amount)
{
  dxBody *v2; // eax

  v2 = this->id;
  *((_DWORD *)v2 + 59) = 0;
  *((_DWORD *)v2 + 60) = 0;
  *((_DWORD *)v2 + 61) = 0;
  *((_DWORD *)v2 + 63) = 0;
  *((_DWORD *)v2 + 64) = 0;
  *((_DWORD *)v2 + 65) = 0;
  *((_DWORD *)v2 + 67) = 0;
  *((_DWORD *)v2 + 68) = 0;
  *((_DWORD *)v2 + 69) = 0;
  *((_DWORD *)v2 + 71) = 0;
  *((_DWORD *)v2 + 72) = 0;
  *((_DWORD *)v2 + 73) = 0;
}
vec3f *RigidBodyODE::getVelocity(RigidBodyODE *this, vec3f *result)
{
  dxBody *v2; // ecx
  float v3; // xmm6_4
  float v4; // xmm5_4
  float v5; // xmm7_4
  float v6; // xmm6_4
  float v7; // xmm5_4
  vec3f *v8; // eax
  float v9; // xmm7_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm4_4
  float v13; // xmm0_4

  v2 = this->id;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  v3 = (float)(*((float *)v2 + 48) + *((float *)v2 + 47)) + *((float *)v2 + 49);
  v4 = (float)(*((float *)v2 + 52) + *((float *)v2 + 51)) + *((float *)v2 + 53);
  v5 = (float)(*((float *)v2 + 44) + *((float *)v2 + 43)) + *((float *)v2 + 45);
  *result = *(vec3f *)((char *)v2 + 236);
  v6 = v3 * 0.0;
  v7 = v4 * 0.0;
  v8 = result;
  v9 = v5 * 0.0;
  v10 = *((float *)v2 + 63);
  v11 = (float)(v10 * v6) - (float)(*((float *)v2 + 64) * v9);
  v12 = (float)(*((float *)v2 + 65) * v9) - (float)(v10 * v7);
  v13 = result->y;
  result->x = (float)((float)(*((float *)v2 + 64) * v7) - (float)(*((float *)v2 + 65) * v6)) + result->x;
  result->y = v13 + v12;
  result->z = result->z + v11;
  return v8;
}
void RigidBodyODE::setVelocity(RigidBodyODE *this, const vec3f *vel)
{
  dxBody *v2; // ecx
  float v3; // xmm0_4
  float v4; // xmm1_4

  v2 = this->id;
  v3 = vel->y;
  v4 = vel->z;
  *((_DWORD *)v2 + 59) = LODWORD(vel->x);
  *((float *)v2 + 60) = v3;
  *((float *)v2 + 61) = v4;
}
void RigidBodyODE::setPosition(RigidBodyODE *this, const vec3f *pos)
{
  dBodySetPosition((_DWORD *)this->id, LODWORD(pos->x), LODWORD(pos->y), LODWORD(pos->z));
}
void __userpurge RigidBodyODE::setRotation(RigidBodyODE *this@<ecx>, char a2@<efl>, const mat44f *mat)
{
  dxBody *v3; // ecx
  float v4; // xmm0_4
  float R[12]; // [esp+0h] [ebp-30h] BYREF

  v3 = this->id;
  R[3] = 0.0;
  R[7] = 0.0;
  R[0] = mat->M11;
  R[4] = mat->M12;
  R[8] = mat->M13;
  R[1] = mat->M21;
  R[5] = mat->M22;
  R[9] = mat->M23;
  R[2] = mat->M31;
  R[6] = mat->M32;
  v4 = mat->M33;
  R[11] = 0.0;
  R[10] = v4;
  dBodySetRotation((__m128i *)R, (int)v3, a2);
}
vec3f *RigidBodyODE::getPosition(RigidBodyODE *this, vec3f *result, float interpolationT)
{
  vec3f *v3; // eax

  v3 = result;
  *result = *(vec3f *)((_BYTE *)this->id + 13);
  return v3;
}
vec3f *RigidBodyODE::getAngularVelocity(RigidBodyODE *this, vec3f *result)
{
  vec3f *v2; // eax

  v2 = result;
  *result = *(vec3f *)((_BYTE *)this->id + 21);
  return v2;
}
vec3f *RigidBodyODE::getLocalAngularVelocity(RigidBodyODE *this, vec3f *result)
{
  RigidBodyODE_vtbl *v3; // edi
  vec3f *v4; // eax
  char v6[12]; // [esp+8h] [ebp-Ch] BYREF

  v3 = this->__vftable;
  v4 = this->getAngularVelocity(this, v6);
  v3->worldToLocalNormal(this, result, v4);
  return result;
}
vec3f *RigidBodyODE::getLocalVelocity(RigidBodyODE *this, vec3f *result)
{
  RigidBodyODE_vtbl *v3; // edi
  vec3f *v4; // eax
  char v6[12]; // [esp+8h] [ebp-Ch] BYREF

  v3 = this->__vftable;
  v4 = this->getVelocity(this, v6);
  v3->worldToLocalNormal(this, result, v4);
  return result;
}
void RigidBodyODE::addMeshCollider(RigidBodyODE *this, float *vertices, unsigned int verticesCount, unsigned __int16 *indices, unsigned int indicesCount, mat44f mat, unsigned int category, unsigned int collideMask, unsigned int spaceId)
{
  BodyCollisionMesh *v9; // eax
  dxTriMeshData *v10; // eax
  unsigned __int16 *v11; // eax
  BodyCollisionMesh *v12; // esi
  unsigned int i; // edx
  int v14; // ecx
  dxTriMesh *v15; // eax
  dxTriMesh *v16; // edi
  dxSpace *v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // ecx
  dxGeom *v20; // eax
  dxGeom *v21; // esi
  bool v22; // zf
  __m128i *v23; // eax
  dxGeom *j; // edi
  int v25; // eax
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  dxGeom *v29; // esi
  dxGeom *k; // edi
  int v31; // eax
  BodyCollisionMesh *v32; // ecx
  std::_Ref_count_base *v33; // esi
  int v34; // [esp-Ch] [ebp-70h]
  const void *v35; // [esp-8h] [ebp-6Ch]
  bool v36; // [esp-4h] [ebp-68h]
  dxTriMeshData *v38; // [esp+10h] [ebp-54h]
  std::shared_ptr<BodyCollisionMesh> _Val; // [esp+1Ch] [ebp-48h] BYREF
  __m128i v40; // [esp+24h] [ebp-40h] BYREF
  __m128i v41; // [esp+34h] [ebp-30h] BYREF
  __m128i v42; // [esp+44h] [ebp-20h] BYREF
  int v43; // [esp+60h] [ebp-4h]

  v9 = (BodyCollisionMesh *)operator new(0xCu);
  if ( v9 )
  {
    v9->vertices = 0;
    v9->indices = 0;
    v9->geomID = 0;
  }
  else
  {
    v9 = 0;
  }
  _Val._Ptr = 0;
  _Val._Rep = 0;
  std::shared_ptr<BodyCollisionMesh>::_Resetp<BodyCollisionMesh>(&_Val, v9);
  v43 = 0;
  if ( dword_1872CAC )
    v10 = (dxTriMeshData *)dword_1872CAC(92);
  else
    v10 = (dxTriMeshData *)_malloc(0x5Cu);
  if ( v10 )
    v38 = dxTriMeshData::dxTriMeshData(v10);
  else
    v38 = 0;
  v11 = (unsigned __int16 *)operator new[](2 * indicesCount);
  v12 = _Val._Ptr;
  _Val._Ptr->indices = v11;
  v12->vertices = (float *)operator new[](12 * verticesCount);
  for ( i = 0; i < indicesCount; ++i )
    v12->indices[i] = indices[i];
  memcpy(v12->vertices, vertices, 12 * verticesCount);
  dxTriMeshData::Build(v38, (char *)v12->vertices, v14, verticesCount, v12->indices, indicesCount, v34, v35, v36);
  if ( dword_1872CAC )
    v15 = (dxTriMesh *)dword_1872CAC(212);
  else
    v15 = (dxTriMesh *)_malloc(0xD4u);
  if ( v15 )
    v16 = dxTriMesh::dxTriMesh(v15, 0, v38);
  else
    v16 = 0;
  *((_DWORD *)v16 + 21) = 0;
  *((_DWORD *)v16 + 22) = 0;
  *((_DWORD *)v16 + 23) = 0;
  v12->geomID = v16;
  v17 = PhysicsCore::getDynamicSubSpace(this->core, spaceId);
  (*(void (**)(dxSpace *, dxTriMesh *))(*(_DWORD *)v17 + 20))(v17, v16);
  dGeomSetBody((int)v12->geomID, (int)this->id);
  v18 = operator new(0x14u);
  v19 = v18;
  if ( v18 )
  {
    v18[1] = category;
    *v18 = &RBCollisionMesh::`vftable';
    v18[2] = collideMask;
    v18[3] = this;
    v18[4] = 0;
  }
  else
  {
    v19 = 0;
  }
  v20 = v12->geomID;
  v40.m128i_i32[3] = 0;
  v41.m128i_i32[3] = 0;
  v42.m128i_i32[3] = 0;
  *((_DWORD *)v20 + 3) = v19;
  v21 = v12->geomID;
  v40.m128i_i64[0] = __PAIR64__(LODWORD(mat.M21), LODWORD(mat.M11));
  v41.m128i_i64[0] = __PAIR64__(LODWORD(mat.M22), LODWORD(mat.M12));
  v22 = *((_DWORD *)v21 + 7) == 0;
  v42.m128i_i64[0] = __PAIR64__(LODWORD(mat.M23), LODWORD(mat.M13));
  v40.m128i_i32[2] = LODWORD(mat.M31);
  v41.m128i_i32[2] = LODWORD(mat.M32);
  v42.m128i_i32[2] = LODWORD(mat.M33);
  if ( v22 )
    dGeomCreateOffset(v21);
  v23 = (__m128i *)*((_DWORD *)v21 + 7);
  v23[1] = _mm_loadu_si128(&v40);
  v23[2] = _mm_loadu_si128(&v41);
  v23[3] = _mm_loadu_si128(&v42);
  if ( *((_DWORD *)v21 + 7) )
    *((_DWORD *)v21 + 2) |= 2u;
  for ( j = (dxGeom *)*((_DWORD *)v21 + 12); j; j = (dxGeom *)*((_DWORD *)j + 12) )
  {
    v25 = *((_DWORD *)v21 + 2);
    if ( (v25 & 1) != 0 )
      break;
    *((_DWORD *)v21 + 2) = v25 | 5;
    (*(void (**)(dxGeom *, dxGeom *))(*(_DWORD *)j + 28))(j, v21);
    v21 = j;
  }
  for ( ; v21; v21 = (dxGeom *)*((_DWORD *)v21 + 12) )
    *((_DWORD *)v21 + 2) |= 5u;
  v26 = mat.M41;
  v27 = mat.M42;
  v28 = mat.M43;
  v29 = _Val._Ptr->geomID;
  if ( !*((_DWORD *)v29 + 7) )
  {
    dGeomCreateOffset(v29);
    v26 = mat.M41;
    v27 = mat.M42;
    v28 = mat.M43;
  }
  **((float **)v29 + 7) = v26;
  *(float *)(*((_DWORD *)v29 + 7) + 4) = v27;
  *(float *)(*((_DWORD *)v29 + 7) + 8) = v28;
  if ( *((_DWORD *)v29 + 7) )
    *((_DWORD *)v29 + 2) |= 2u;
  for ( k = (dxGeom *)*((_DWORD *)v29 + 12); k; k = (dxGeom *)*((_DWORD *)k + 12) )
  {
    v31 = *((_DWORD *)v29 + 2);
    if ( (v31 & 1) != 0 )
      break;
    *((_DWORD *)v29 + 2) = v31 | 5;
    (*(void (**)(dxGeom *, dxGeom *))(*(_DWORD *)k + 28))(k, v29);
    v29 = k;
  }
  for ( ; v29; v29 = (dxGeom *)*((_DWORD *)v29 + 12) )
    *((_DWORD *)v29 + 2) |= 5u;
  v32 = _Val._Ptr;
  *((_DWORD *)_Val._Ptr->geomID + 20) = collideMask;
  *((_DWORD *)v32->geomID + 19) = category;
  std::vector<std::shared_ptr<BodyCollisionMesh>>::push_back(&this->collisionMeshes, &_Val);
  v43 = -1;
  v33 = _Val._Rep;
  if ( _Val._Rep && !_InterlockedExchangeAdd((volatile signed __int32 *)&_Val._Rep->_Uses, 0xFFFFFFFF) )
  {
    v33->_Destroy(v33);
    if ( !_InterlockedDecrement((volatile signed __int32 *)&v33->_Weaks) )
      ((void (*)(void))v33->_Delete_this)();
  }
}
void RigidBodyODE::setMeshCollideMask(RigidBodyODE *this, unsigned int meshIndex, unsigned int mask)
{
  *((_DWORD *)this->collisionMeshes._Myfirst[meshIndex]._Ptr->geomID + 20) = mask;
}
void RigidBodyODE::setMeshCollideCategory(RigidBodyODE *this, unsigned int meshIndex, unsigned int category)
{
  *((_DWORD *)this->collisionMeshes._Myfirst[meshIndex]._Ptr->geomID + 19) = category;
}
unsigned int RigidBodyODE::getMeshCollideCategory(RigidBodyODE *this, unsigned int meshIndex)
{
  unsigned int result; // eax

  if ( meshIndex >= this->collisionMeshes._Mylast - this->collisionMeshes._Myfirst )
    result = 0;
  else
    result = *((_DWORD *)this->collisionMeshes._Myfirst[meshIndex]._Ptr->geomID + 19);
  return result;
}
unsigned int RigidBodyODE::getMeshCollideMask(RigidBodyODE *this, unsigned int meshIndex)
{
  unsigned int result; // eax

  if ( meshIndex >= this->collisionMeshes._Mylast - this->collisionMeshes._Myfirst )
    result = 0;
  else
    result = *((_DWORD *)this->collisionMeshes._Myfirst[meshIndex]._Ptr->geomID + 20);
  return result;
}
void RigidBodyODE::setBoxColliderMask(RigidBodyODE *this, unsigned int box, unsigned int mask)
{
  *(_DWORD *)(box + 80) = mask;
}
unsigned int RigidBodyODE::addBoxCollider(RigidBodyODE *this, const vec3f *pos, const vec3f *size, unsigned int category, unsigned int mask, unsigned int spaceId)
{
  dxSpace *v7; // eax
  dxGeom *v8; // eax
  dxBody *v9; // edx
  dxGeom *v10; // esi
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  char v14; // fl
  unsigned int result; // eax
  float sizea; // [esp+14h] [ebp+8h]

  v7 = PhysicsCore::getDynamicSubSpace(this->core, spaceId);
  v8 = dCreateBox(v7, size->x, size->y, size->z);
  v9 = this->id;
  v10 = v8;
  spaceId = (unsigned int)v8;
  dGeomSetBody((int)v8, (int)v9);
  v11 = pos->x;
  v12 = pos->y;
  v13 = pos->z;
  sizea = pos->x;
  if ( !*((_DWORD *)v10 + 7) )
  {
    dGeomCreateOffset(v10);
    v11 = sizea;
  }
  **((float **)v10 + 7) = v11;
  *(float *)(*((_DWORD *)v10 + 7) + 4) = v12;
  *(float *)(*((_DWORD *)v10 + 7) + 8) = v13;
  dGeomMoved(v10);
  dGeomSetRotation((__m128i *)((char *)this->id + 172), v10, v14);
  std::vector<IDWriteFontFile *>::push_back(
    (std::vector<ksgui::CustomSpinner *> *)&this->geoms,
    (ksgui::CustomSpinner *const *)&spaceId);
  result = spaceId;
  *(_DWORD *)(spaceId + 80) = mask;
  *(_DWORD *)(result + 76) = category;
  return result;
}
void RigidBodyODE::addLocalForce(RigidBodyODE *this, const vec3f *f)
{
  dBodyAddRelForceAtRelPos((float *)this->id, f->x, f->y, f->z, 0.0, 0.0, 0.0);
}
void RigidBodyODE::addLocalTorque(RigidBodyODE *this, const vec3f *t)
{
  float *v2; // ecx
  float v3; // xmm3_4
  float v4; // xmm5_4
  float v5; // xmm2_4
  float v6; // xmm1_4

  v2 = (float *)this->id;
  v3 = t->y;
  v4 = t->z;
  v5 = (float)((float)(v2[48] * v3) + (float)(v2[47] * t->x)) + (float)(v2[49] * v4);
  v6 = (float)((float)(v2[52] * v3) + (float)(v2[51] * t->x)) + (float)(v2[53] * v4);
  v2[71] = v2[71] + (float)((float)((float)(v2[44] * v3) + (float)(v2[43] * t->x)) + (float)(v2[45] * v4));
  v2[72] = v2[72] + v5;
  v2[73] = v2[73] + v6;
}
void RigidBodyODE::addLocalForceAtPos(RigidBodyODE *this, const vec3f *f, const vec3f *p)
{
  float *v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm4_4

  v3 = (float *)this->id;
  v4 = f->y;
  v5 = f->z;
  v6 = p->y - v3[40];
  v7 = (float)((float)(v3[44] * v4) + (float)(f->x * v3[43])) + (float)(v3[45] * v5);
  v8 = (float)((float)(v3[48] * v4) + (float)(v3[47] * f->x)) + (float)(v3[49] * v5);
  v9 = p->x - v3[39];
  v10 = v3[53] * v5;
  v11 = p->z - v3[41];
  v12 = (float)((float)(v3[52] * v4) + (float)(v3[51] * f->x)) + v10;
  v3[67] = v3[67] + v7;
  v3[68] = v3[68] + v8;
  v3[69] = v3[69] + v12;
  v3[71] = v3[71] + (float)((float)(v6 * v12) - (float)(v11 * v8));
  v3[72] = v3[72] + (float)((float)(v11 * v7) - (float)(v9 * v12));
  v3[73] = v3[73] + (float)((float)(v9 * v8) - (float)(v6 * v7));
}
void RigidBodyODE::addLocalForceAtLocalPos(RigidBodyODE *this, const vec3f *f, const vec3f *p)
{
  dBodyAddRelForceAtRelPos((float *)this->id, f->x, f->y, f->z, p->x, p->y, p->z);
}
void RigidBodyODE::addForceAtLocalPos(RigidBodyODE *this, const vec3f *f, const vec3f *p)
{
  float *v3; // ecx
  float v4; // xmm6_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm7_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm5_4

  v3 = (float *)this->id;
  v4 = f->z;
  v5 = p->y;
  v6 = p->z;
  v7 = (float)((float)(v3[44] * v5) + (float)(p->x * v3[43])) + (float)(v3[45] * v6);
  v8 = (float)((float)(v3[48] * v5) + (float)(p->x * v3[47])) + (float)(v3[49] * v6);
  v9 = f->x;
  v10 = (float)(v3[52] * v5) + (float)(v3[51] * p->x);
  v11 = v3[53] * v6;
  v12 = f->y;
  v13 = v8 * v4;
  v14 = v10 + v11;
  v15 = v8 * f->x;
  v3[67] = v3[67] + f->x;
  v3[68] = v3[68] + v12;
  v3[69] = v3[69] + v4;
  v3[71] = v3[71] + (float)(v13 - (float)(v14 * v12));
  v3[72] = v3[72] + (float)((float)(v14 * v9) - (float)(v7 * v4));
  v3[73] = v3[73] + (float)((float)(v7 * v12) - v15);
}
vec3f *RigidBodyODE::getLocalPointVelocity(RigidBodyODE *this, vec3f *result, const vec3f *p)
{
  dxBody *v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm7_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm5_4
  vec3f *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm4_4

  v3 = this->id;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  v4 = p->y;
  v5 = p->z;
  v6 = (float)((float)(*((float *)v3 + 44) * v4) + (float)(*((float *)v3 + 43) * p->x))
     + (float)(*((float *)v3 + 45) * v5);
  v7 = (float)(*((float *)v3 + 52) * v4) + (float)(p->x * *((float *)v3 + 51));
  v8 = (float)((float)(*((float *)v3 + 48) * v4) + (float)(*((float *)v3 + 47) * p->x))
     + (float)(*((float *)v3 + 49) * v5);
  v9 = *((float *)v3 + 53) * v5;
  *result = *(vec3f *)((char *)v3 + 236);
  v10 = v7 + v9;
  v11 = result;
  v12 = *((float *)v3 + 63);
  v13 = (float)(v12 * v8) - (float)(*((float *)v3 + 64) * v6);
  v14 = (float)(*((float *)v3 + 65) * v6) - (float)(v12 * v10);
  result->x = result->x + (float)((float)(*((float *)v3 + 64) * v10) - (float)(*((float *)v3 + 65) * v8));
  result->y = result->y + v14;
  result->z = result->z + v13;
  return v11;
}
vec3f *RigidBodyODE::getPointVelocity(RigidBodyODE *this, vec3f *result, const vec3f *p)
{
  dxBody *v3; // ecx
  float v4; // xmm7_4
  float v5; // xmm6_4
  float v6; // xmm4_4
  vec3f *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm5_4

  v3 = this->id;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  v4 = p->x - *((float *)v3 + 39);
  v5 = p->y - *((float *)v3 + 40);
  v6 = p->z - *((float *)v3 + 41);
  *result = *(vec3f *)((char *)v3 + 236);
  v7 = result;
  v8 = *((float *)v3 + 63);
  v9 = (float)(v8 * v5) - (float)(*((float *)v3 + 64) * v4);
  v10 = (float)(*((float *)v3 + 65) * v4) - (float)(v8 * v6);
  result->x = result->x + (float)((float)(*((float *)v3 + 64) * v6) - (float)(*((float *)v3 + 65) * v5));
  result->y = result->y + v10;
  result->z = result->z + v9;
  return v7;
}
void RigidBodyODE::addForceAtPos(RigidBodyODE *this, const vec3f *f, const vec3f *p)
{
  float *v3; // ecx
  float v4; // xmm6_4
  float v5; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm7_4
  float v10; // xmm5_4

  v3 = (float *)this->id;
  v4 = f->x;
  v5 = f->y;
  v6 = f->z;
  v7 = p->z - v3[41];
  v8 = p->y - v3[40];
  v9 = p->x - v3[39];
  v3[67] = v3[67] + f->x;
  v3[68] = v3[68] + v5;
  v3[69] = v3[69] + v6;
  v3[71] = (float)((float)(v8 * v6) - (float)(v7 * v5)) + v3[71];
  v10 = (float)((float)(v7 * v4) - (float)(v9 * v6)) + v3[72];
  v3[73] = (float)((float)(v9 * v5) - (float)(v8 * v4)) + v3[73];
  v3[72] = v10;
}
void RigidBodyODE::addTorque(RigidBodyODE *this, const vec3f *t)
{
  float *v2; // ecx
  float v3; // xmm1_4
  float v4; // xmm2_4

  v2 = (float *)this->id;
  v3 = t->y;
  v4 = t->z;
  v2[71] = v2[71] + t->x;
  v2[72] = v2[72] + v3;
  v2[73] = v2[73] + v4;
}
void RigidBodyODE::setAngularVelocity(RigidBodyODE *this, const vec3f *vel)
{
  dxBody *v2; // ecx
  float v3; // xmm0_4
  float v4; // xmm1_4

  v2 = this->id;
  v3 = vel->y;
  v4 = vel->z;
  *((_DWORD *)v2 + 63) = LODWORD(vel->x);
  *((float *)v2 + 64) = v3;
  *((float *)v2 + 65) = v4;
}
void RigidBodyODE::setAutoDisable(RigidBodyODE *this, bool mode)
{
  dxBody *v2; // ecx
  _DWORD *v3; // edx

  if ( mode )
  {
    *((_DWORD *)this->id + 7) |= 0x10u;
  }
  else
  {
    v2 = this->id;
    v3 = (_DWORD *)*((_DWORD *)v2 + 1);
    *((_DWORD *)v2 + 7) &= 0xFFFFFFEB;
    *((_DWORD *)v2 + 80) = v3[15];
    *((_DWORD *)v2 + 79) = v3[14];
    dBodySetAutoDisableAverageSamplesCount((int)v2, v3[16]);
  }
}
BOOL RigidBodyODE::isEnabled(RigidBodyODE *this)
{
  return (*((_DWORD *)this->id + 7) & 4) == 0;
}
void RigidBodyODE::setEnabled(RigidBodyODE *this, bool value)
{
  dxBody *v2; // ecx
  int v3; // eax

  if ( value )
  {
    v2 = this->id;
    v3 = *((_DWORD *)v2 + 80);
    *((_DWORD *)v2 + 7) &= 0xFFFFFFFB;
    *((_DWORD *)v2 + 85) = v3;
    *((_DWORD *)v2 + 84) = *((_DWORD *)v2 + 79);
  }
  else
  {
    *((_DWORD *)this->id + 7) |= 4u;
  }
}
