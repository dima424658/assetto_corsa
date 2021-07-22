#include "constrainedobjectsmanager.h"
void ConstrainedObjectsManager::ConstrainedObjectsManager(ConstrainedObjectsManager *this, CarAvatar *car)
{
  Event<float> *v3; // ecx
  std::wstring v4; // [esp-1Ch] [ebp-3Ch] BYREF
  Game *v5; // [esp-4h] [ebp-24h]
  ConstrainedObjectsManager *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  v5 = car->game;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"CONSTRAINT_MANAGER", 0x12u);
  GameObject::GameObject(this, v4, v5);
  this->__vftable = (ConstrainedObjectsManager_vtbl *)&ConstrainedObjectsManager::`vftable';
  this->car = car;
  v7 = 0;
  this->objects._Myfirst = 0;
  this->objects._Mylast = 0;
  this->objects._Myend = 0;
  v5 = (Game *)this;
  v4._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_f72a3f96ea94bf48a593368c3bf259b3_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
  *(_DWORD *)&v4._Bx._Alias[4] = this;
  v4._Mysize = (unsigned int)&v4;
  v3 = &this->game->evOnPostUpdate;
  LOBYTE(v7) = 1;
  Event<float>::addHandler((Event<SessionInfo> *)v3, (std::function<void __cdecl(SessionInfo const &)>)v4, this);
}
ConstrainedObjectsManager *ConstrainedObjectsManager::`vector deleting destructor'(ConstrainedObjectsManager *this, unsigned int a2)
{
  this->__vftable = (ConstrainedObjectsManager_vtbl *)&ConstrainedObjectsManager::`vftable';
  if ( this->objects._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->objects);
    operator delete(this->objects._Myfirst);
    this->objects._Myfirst = 0;
    this->objects._Mylast = 0;
    this->objects._Myend = 0;
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ConstrainedObjectsManager::addModel(ConstrainedObjectsManager *this, Node *root)
{
  ConstrainedObjectsManager::addNodes(this, root, root);
}
void ConstrainedObjectsManager::addNodes(ConstrainedObjectsManager *this, Node *root, Node *node)
{
  ConstrainedObjectsManager *v3; // ebx
  std::wstring *v4; // esi
  std::wstring *v5; // eax
  Node *v6; // esi
  __m128i v7; // xmm0
  std::wstring *v8; // eax
  Node **v9; // esi
  int v10; // edi
  unsigned int v11; // ebx
  ConstrainedObjectDef d; // [esp+18h] [ebp-70h] BYREF
  std::wstring on; // [esp+60h] [ebp-28h] BYREF
  int v15; // [esp+84h] [ebp-4h]

  v3 = this;
  v4 = &node->name;
  if ( !std::wstring::find(&node->name, L"DIR_", 0, 4u) )
  {
    std::wstring::substr(v4, &on, 4u, 0xFFFFFFFF);
    v5 = &on;
    v15 = 0;
    if ( on._Myres >= 8 )
      v5 = (std::wstring *)on._Bx._Ptr;
    if ( node->name._Myres >= 8 )
      v4 = (std::wstring *)v4->_Bx._Ptr;
    _printf("Found target object: %S looking for constrained node:%S\n", v4->_Bx._Buf, v5->_Bx._Buf);
    v6 = root->findChildByName(root, &on, 1);
    if ( v6 )
    {
      mat44f::mat44f(&d.orgMatrix);
      v7 = _mm_loadu_si128((const __m128i *)&v6->matrix);
      d.node = v6;
      *(__m128i *)&d.orgMatrix.M11 = v7;
      d.target = node;
      *(__m128i *)&d.orgMatrix.M21 = _mm_loadu_si128((const __m128i *)&v6->matrix.M21);
      *(__m128i *)&d.orgMatrix.M31 = _mm_loadu_si128((const __m128i *)&v6->matrix.M31);
      *(__m128i *)&d.orgMatrix.M41 = _mm_loadu_si128((const __m128i *)&v6->matrix.M41);
      std::vector<ConstrainedObjectDef>::push_back(&v3->objects, &d);
    }
    else
    {
      v8 = &on;
      if ( on._Myres >= 8 )
        v8 = (std::wstring *)on._Bx._Ptr;
      _printf("WARNING: Costrained node %S not found\n", v8->_Bx._Buf);
    }
    v15 = -1;
    if ( on._Myres >= 8 )
      operator delete(on._Bx._Ptr);
    on._Myres = 7;
    on._Mysize = 0;
    on._Bx._Buf[0] = 0;
  }
  v9 = node->nodes._Myfirst;
  v10 = 0;
  v11 = (unsigned int)((char *)node->nodes._Mylast - (char *)v9 + 3) >> 2;
  if ( v9 > node->nodes._Mylast )
    v11 = 0;
  if ( v11 )
  {
    do
    {
      ConstrainedObjectsManager::addNodes(this, root, *v9);
      ++v10;
      ++v9;
    }
    while ( v10 != v11 );
  }
}
void ConstrainedObjectsManager::updateConstraints(ConstrainedObjectsManager *this, float deltaT)
{
  ConstrainedObjectDef *v2; // esi
  ConstrainedObjectDef *v3; // edi
  int v4; // eax
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 v7; // xmm1
  __m128 v8; // xmm7
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  float v15; // xmm1_4
  __m128 v16; // xmm0
  float v17; // xmm2_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm2_4
  __int128 v25; // xmm3
  __m128 v26; // xmm0
  __int128 v27; // xmm1
  __int128 v28; // xmm2
  Node *v29; // eax
  int v30; // [esp+0h] [ebp-1B0h]
  int v31; // [esp+4h] [ebp-1ACh]
  unsigned int v32; // [esp+10h] [ebp-1A0h]
  unsigned int v33; // [esp+14h] [ebp-19Ch]
  float v34; // [esp+14h] [ebp-19Ch]
  unsigned __int64 v35; // [esp+18h] [ebp-198h]
  float v36; // [esp+20h] [ebp-190h]
  int v37; // [esp+20h] [ebp-190h]
  unsigned int *v38; // [esp+24h] [ebp-18Ch]
  unsigned __int64 v39; // [esp+28h] [ebp-188h]
  unsigned __int64 v40; // [esp+34h] [ebp-17Ch]
  float v41; // [esp+40h] [ebp-170h]
  float v42; // [esp+44h] [ebp-16Ch]
  __m128 v43; // [esp+48h] [ebp-168h]
  __m128 v44; // [esp+58h] [ebp-158h]
  _BYTE v45[32]; // [esp+68h] [ebp-148h]
  float v46; // [esp+9Ch] [ebp-114h]
  __m128 v47; // [esp+A0h] [ebp-110h]
  __m128 v48; // [esp+C0h] [ebp-F0h]
  __m128 v49; // [esp+D0h] [ebp-E0h]
  DirectX::XMMATRIX M2; // [esp+E0h] [ebp-D0h] BYREF
  char v51[48]; // [esp+120h] [ebp-90h] BYREF
  float v52; // [esp+150h] [ebp-60h]
  float v53; // [esp+154h] [ebp-5Ch]
  float v54; // [esp+158h] [ebp-58h]
  __m128 pDeterminant; // [esp+160h] [ebp-50h] BYREF
  mat44f v56; // [esp+170h] [ebp-40h] BYREF

  v2 = this->objects._Myfirst;
  v3 = this->objects._Mylast;
  if ( v2 != v3 )
  {
    v38 = (unsigned int *)&v2->orgMatrix.M13;
    do
    {
      v4 = (int)v2->node->parent->getWorldMatrix(v2->node->parent, &v56);
      v5 = *(__m128 *)(v4 + 16);
      v47 = *(__m128 *)(v4 + 48);
      v48 = *(__m128 *)(v4 + 32);
      v49 = DirectX::XMMatrixInverse(&pDeterminant, *(__m128 *)v4, v5, v48, v47);
      (*(void (**)(unsigned int, char *))(*(_DWORD *)v38[14] + 32))(v38[14], v51);
      v6 = v5;
      *(float *)&v33 = (float)((float)((float)(v53 * v5.m128_f32[0]) + (float)(v52 * v49.m128_f32[0]))
                             + (float)(v54 * v48.m128_f32[0]))
                     + v47.m128_f32[0];
      *(float *)&v32 = (float)((float)(v53 * _mm_shuffle_ps(v6, v6, 85).m128_f32[0])
                             + (float)(v52 * _mm_shuffle_ps(v49, v49, 85).m128_f32[0]))
                     + (float)(v54 * _mm_shuffle_ps(v48, v48, 85).m128_f32[0]);
      v7 = (__m128)v32;
      v8 = (__m128)v33;
      v8.m128_f32[0] = *(float *)&v33 - *((float *)v38 + 10);
      v7.m128_f32[0] = (float)(*(float *)&v32 + _mm_shuffle_ps(v47, v47, 85).m128_f32[0]) - *((float *)v38 + 11);
      v39 = _mm_unpacklo_ps(v8, v7).m128_u64[0];
      v9 = *((float *)&v39 + 1);
      v10 = (float)((float)((float)((float)(v53 * v6.m128_f32[2]) + (float)(v52 * v49.m128_f32[2]))
                          + (float)(v54 * v48.m128_f32[2]))
                  + v47.m128_f32[2])
          - *((float *)v38 + 12);
      v11 = fsqrt(
              (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8.m128_f32[0] * v8.m128_f32[0]))
            + (float)(v10 * v10));
      if ( v11 == 0.0 )
      {
        v12 = *(float *)&v39;
      }
      else
      {
        v12 = v8.m128_f32[0] * (float)(1.0 / v11);
        v9 = *((float *)&v39 + 1) * (float)(1.0 / v11);
        v10 = v10 * (float)(1.0 / v11);
      }
      v13 = (__m128)*(v38 - 2);
      v14 = (__m128)*v38;
      v36 = *((float *)v38 - 1);
      v42 = *((float *)v38 - 2);
      v41 = *(float *)v38;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v42 * v12) + (float)(v36 * v9)) + (float)(v14.m128_f32[0] * v10)) & _xmm) < 1.0 )
      {
        __libm_sse2_acosf();
        v14 = (__m128)LODWORD(v41);
        v13 = (__m128)LODWORD(v42);
      }
      v15 = (float)(v36 * v10) - (float)(v14.m128_f32[0] * v9);
      v16 = v13;
      v14.m128_f32[0] = (float)(v14.m128_f32[0] * v12) - (float)(v13.m128_f32[0] * v10);
      v16.m128_f32[0] = v15;
      v46 = (float)(v13.m128_f32[0] * v9) - (float)(v36 * v12);
      v40 = _mm_unpacklo_ps(v16, v14).m128_u64[0];
      v17 = fsqrt((float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v15 * v15)) + (float)(v46 * v46));
      if ( v17 == 0.0 )
      {
        v34 = (float)(v13.m128_f32[0] * v9) - (float)(v36 * v12);
        v35 = v40;
      }
      else
      {
        *(float *)&v35 = v15 * (float)(1.0 / v17);
        *((float *)&v35 + 1) = *((float *)&v40 + 1) * (float)(1.0 / v17);
        v34 = v46 * (float)(1.0 / v17);
      }
      v18 = __libm_sse2_cosf(v30, v31).m128_f32[0];
      v19 = __libm_sse2_sinf().m128_f32[0];
      v20 = 1.0 - v18;
      *(_OWORD *)&v45[12] = 0i64;
      v37 = (int)&v2->node->matrix;
      v43.m128_i32[3] = 0;
      *(_DWORD *)&v45[28] = 1065353216;
      v43.m128_f32[0] = (float)((float)(*(float *)&v35 * *(float *)&v35) * (float)(1.0 - v18)) + v18;
      v44.m128_f32[1] = (float)((float)(*((float *)&v35 + 1) * *((float *)&v35 + 1)) * (float)(1.0 - v18)) + v18;
      v21 = (float)((float)(v34 * v34) * (float)(1.0 - v18)) + v18;
      v22 = (float)(*(float *)&v35 * *((float *)&v35 + 1)) * (float)(1.0 - v18);
      *(float *)&v45[8] = v21;
      v44.m128_f32[0] = v22 - (float)(v34 * v19);
      v43.m128_f32[1] = (float)(v34 * v19) + v22;
      v23 = (float)(*((float *)&v35 + 1) * v34) * v20;
      v24 = (float)(*(float *)&v35 * v34) * v20;
      M2.r[3] = *(__m128 *)&v45[16];
      v25 = *(_OWORD *)(v38 + 10);
      v43.m128_f32[2] = v24 - (float)(*((float *)&v35 + 1) * v19);
      *(float *)v45 = (float)(*((float *)&v35 + 1) * v19) + v24;
      v44.m128_u64[1] = COERCE_UNSIGNED_INT((float)(*(float *)&v35 * v19) + v23);
      *(float *)&v45[4] = v23 - (float)(*(float *)&v35 * v19);
      M2.r[0] = v43;
      v26 = *(__m128 *)(v38 - 2);
      M2.r[1] = v44;
      v27 = *(_OWORD *)(v38 + 2);
      M2.r[2] = *(__m128 *)v45;
      v28 = *(_OWORD *)(v38 + 6);
      *(__m128 *)v37 = DirectX::XMMatrixMultiply(M2.r, v26);
      *(_OWORD *)(v37 + 16) = v27;
      *(_OWORD *)(v37 + 32) = v28;
      *(_OWORD *)(v37 + 48) = v25;
      v29 = v2->node;
      ++v2;
      LODWORD(v27) = v38[11];
      LODWORD(v28) = v38[12];
      LODWORD(v29->matrix.M41) = v38[10];
      LODWORD(v29->matrix.M42) = v27;
      LODWORD(v29->matrix.M43) = v28;
      v38 += 18;
    }
    while ( v2 != v3 );
  }
}
