#include "trackobject.h"
void TrackObject::TrackObject(TrackObject *this, std::wstring iname, Sim *isim, Node *iroot)
{
  Sim *v5; // esi
  Node *v6; // ecx
  vec3f *v7; // esi
  int v8; // ebp
  int v9; // ecx
  int v10; // edi
  PhysicsObjectDesc *v11; // eax
  Node *v12; // eax
  Sim *v13; // ebp
  __m128i v14; // xmm0
  GameObject **v15; // esi
  int v16; // edi
  PhysicsObject *v17; // ecx
  PhysicsObject *v18; // eax
  bool v19; // cf
  Node *v20; // eax
  std::wstring v21; // [esp-1Ch] [ebp-C0h] BYREF
  unsigned int v22; // [esp-4h] [ebp-A8h]
  PhysicsObject *v23; // [esp+14h] [ebp-90h]
  std::vector<vec3f> vertices; // [esp+18h] [ebp-8Ch] BYREF
  TrackObject *v25; // [esp+24h] [ebp-80h]
  PhysicsObjectDesc desc; // [esp+28h] [ebp-7Ch] BYREF
  int v27; // [esp+A0h] [ebp-4h]

  v5 = isim;
  v25 = this;
  v22 = (unsigned int)isim->game;
  v27 = 0;
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  std::wstring::assign(&v21, &iname, 0, 0xFFFFFFFF);
  GameObject::GameObject(this, v21, (Game *)v22);
  v22 = 64;
  LOBYTE(v27) = 1;
  this->__vftable = (TrackObject_vtbl *)&TrackObject::`vftable';
  this->physicsObject = 0;
  this->root = 0;
  this->sim = 0;
  Concurrency::details::_Concurrent_queue_base_v4::_Concurrent_queue_base_v4(&this->chIn.queue, v22);
  this->chIn.queue.__vftable = (Concurrency::concurrent_queue<mat44f,std::allocator<mat44f> >_vtbl *)&Concurrency::concurrent_queue<mat44f,std::allocator<mat44f>>::`vftable';
  LOBYTE(v27) = 2;
  mat44f::mat44f(&this->orgMatrix);
  v6 = iroot;
  this->root = iroot;
  this->sim = v5;
  if ( (((char *)v6->nodes._Mylast - (char *)v6->nodes._Myfirst) & 0xFFFFFFFC) != 0
    && __RTDynamicCast(*v6->nodes._Myfirst, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0) )
  {
    v7 = 0;
    v8 = __RTDynamicCast(*this->root->nodes._Myfirst, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
    vertices._Myfirst = 0;
    vertices._Mylast = 0;
    vertices._Myend = 0;
    v9 = *(_DWORD *)(v8 + 228) - *(_DWORD *)(v8 + 224);
    LOBYTE(v27) = 3;
    v23 = (PhysicsObject *)(v9 / 44);
    if ( v9 / 44 > 0 )
    {
      v10 = v9 / 44;
      do
      {
        std::vector<DRSZone>::push_back(&vertices, (vec3f *)((char *)v7 + *(_DWORD *)(v8 + 224)));
        v7 = (vec3f *)((char *)v7 + 44);
        --v10;
      }
      while ( v10 );
      v7 = vertices._Myfirst;
    }
    desc.name._Myres = 7;
    desc.name._Mysize = 0;
    desc.name._Bx._Buf[0] = 0;
    mat44f::mat44f(&desc.worldMatrix);
    desc.indices = *(unsigned __int16 **)(v8 + 236);
    desc.indexCount = (*(_DWORD *)(v8 + 240) - *(_DWORD *)(v8 + 236)) >> 1;
    desc.vertexCount = (int)v23;
    v11 = (PhysicsObjectDesc *)&this->root->name;
    LOBYTE(v27) = 4;
    desc.vertices = &v7->x;
    if ( &desc != v11 )
      std::wstring::assign(&desc.name, &v11->name, 0, 0xFFFFFFFF);
    v12 = this->root;
    v13 = this->sim;
    *(__m128i *)&desc.worldMatrix.M11 = _mm_loadu_si128((const __m128i *)&v12->matrix);
    *(__m128i *)&desc.worldMatrix.M21 = _mm_loadu_si128((const __m128i *)&v12->matrix.M21);
    *(__m128i *)&desc.worldMatrix.M31 = _mm_loadu_si128((const __m128i *)&v12->matrix.M31);
    v14 = _mm_loadu_si128((const __m128i *)&v12->matrix.M41);
    desc.mass = 1.0;
    *(__m128i *)&desc.worldMatrix.M41 = v14;
    v15 = v13->gameObjects._Myfirst;
    if ( v15 == v13->gameObjects._Mylast )
    {
LABEL_12:
      v16 = 0;
    }
    else
    {
      while ( 1 )
      {
        v16 = __RTDynamicCast(*v15, 0, &GameObject `RTTI Type Descriptor', &PhysicsAvatar `RTTI Type Descriptor', 0);
        if ( v16 )
          break;
        if ( ++v15 == v13->gameObjects._Mylast )
          goto LABEL_12;
      }
    }
    v17 = (PhysicsObject *)operator new(16);
    v23 = v17;
    LOBYTE(v27) = 5;
    if ( v17 )
      PhysicsObject::PhysicsObject(v17, (PhysicsEngine *)(v16 + 56), &desc, &this->chIn);
    else
      v18 = 0;
    v19 = desc.name._Myres < 8;
    this->physicsObject = v18;
    v20 = this->root;
    *(__m128i *)&this->orgMatrix.M11 = _mm_loadu_si128((const __m128i *)&v20->matrix);
    *(__m128i *)&this->orgMatrix.M21 = _mm_loadu_si128((const __m128i *)&v20->matrix.M21);
    *(__m128i *)&this->orgMatrix.M31 = _mm_loadu_si128((const __m128i *)&v20->matrix.M31);
    *(__m128i *)&this->orgMatrix.M41 = _mm_loadu_si128((const __m128i *)&v20->matrix.M41);
    if ( !v19 )
      operator delete(desc.name._Bx._Ptr);
    desc.name._Myres = 7;
    desc.name._Mysize = 0;
    desc.name._Bx._Buf[0] = 0;
    LOBYTE(v27) = 2;
    if ( vertices._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&vertices);
      operator delete(vertices._Myfirst);
    }
  }
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
}
TrackObject *TrackObject::`scalar deleting destructor'(TrackObject *this, unsigned int a2)
{
  this->__vftable = (TrackObject_vtbl *)&TrackObject::`vftable';
  Concurrency::concurrent_queue<mat44f,std::allocator<mat44f>>::~concurrent_queue<mat44f,std::allocator<mat44f>>(&this->chIn.queue);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TrackObject::resetOrgMatrix(TrackObject *this)
{
  if ( this->physicsObject )
    PhysicsObject::setWorldMatrix(this->physicsObject, &this->orgMatrix);
}
void TrackObject::setMatrix(TrackObject *this, mat44f matrix)
{
  Node *v2; // eax

  v2 = this->root;
  *(__m128i *)&v2->matrix.M11 = _mm_loadu_si128((const __m128i *)&matrix);
  *(__m128i *)&v2->matrix.M21 = _mm_loadu_si128((const __m128i *)&matrix.M21);
  *(__m128i *)&v2->matrix.M31 = _mm_loadu_si128((const __m128i *)&matrix.M31);
  *(__m128i *)&v2->matrix.M41 = _mm_loadu_si128((const __m128i *)&matrix.M41);
}
void TrackObject::update(TrackObject *this, float deltaT)
{
  BufferedChannel<mat44f> *v2; // edi
  mat44f *v3; // esi

  v2 = &this->chIn;
  v3 = &this->root->matrix;
  if ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(&this->chIn.queue, v3) )
  {
    while ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(&v2->queue, v3) )
      ;
  }
}
