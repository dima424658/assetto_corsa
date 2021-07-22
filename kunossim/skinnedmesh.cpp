#include "skinnedmesh.h
void SkinnedMesh::SkinnedMesh(SkinnedMesh *this, const SkinnedMesh *mesh)
{
  std::_Ref_count_base *v3; // edx
  Material *v4; // ebx
  std::_Ref_count_base *v5; // edi

  Renderable::Renderable(this, mesh);
  this->__vftable = (SkinnedMesh_vtbl *)&SkinnedMesh::`vftable';
  this->vertices._Myfirst = 0;
  this->vertices._Mylast = 0;
  this->vertices._Myend = 0;
  this->indices._Myfirst = 0;
  this->indices._Mylast = 0;
  this->indices._Myend = 0;
  this->material._Ptr = 0;
  this->material._Rep = 0;
  this->bones._Myfirst = 0;
  this->bones._Mylast = 0;
  this->bones._Myend = 0;
  this->compiledIndicesCount = 0;
  this->compiledVerticesCount = 0;
  this->castShadows = mesh->castShadows;
  this->isTransparent = mesh->isTransparent;
  v3 = mesh->material._Rep;
  v4 = mesh->material._Ptr;
  if ( v3 )
    _InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 1u);
  v5 = this->material._Rep;
  this->material._Rep = v3;
  this->material._Ptr = v4;
  if ( v5 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v5->_Uses, 0xFFFFFFFF) )
    {
      v5->_Destroy(v5);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v5->_Weaks) )
        v5->_Delete_this(v5);
    }
  }
  this->noCull = mesh->noCull;
  this->vb = 0;
  this->ib = 0;
  this->bonesBuffer = 0;
  this->bonesStagingBuffer = 0;
  this->needsMatrixWS = 0;
  std::vector<SkinnedMeshVertex>::operator=(&this->vertices, &mesh->vertices);
  std::vector<unsigned short>::operator=(&this->indices, &mesh->indices);
  std::vector<SkinnedBone>::operator=(&this->bones, &mesh->bones);
}
void SkinnedMesh::SkinnedMesh(SkinnedMesh *this, std::wstring aname)
{
  bool v3; // cf
  std::wstring v4; // [esp-18h] [ebp-30h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  v5 = 0;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, &aname, 0, 0xFFFFFFFF);
  Renderable::Renderable(this, v4);
  v3 = aname._Myres < 8;
  this->__vftable = (SkinnedMesh_vtbl *)&SkinnedMesh::`vftable';
  this->vertices._Myfirst = 0;
  this->vertices._Mylast = 0;
  this->vertices._Myend = 0;
  this->indices._Myfirst = 0;
  this->indices._Mylast = 0;
  this->indices._Myend = 0;
  this->material._Ptr = 0;
  this->material._Rep = 0;
  this->bones._Myfirst = 0;
  this->bones._Mylast = 0;
  this->bones._Myend = 0;
  this->compiledIndicesCount = 0;
  this->compiledVerticesCount = 0;
  this->bonesBuffer = 0;
  this->bonesStagingBuffer = 0;
  this->vb = 0;
  this->ib = 0;
  *(_DWORD *)&this->castShadows = 257;
  this->layer = 0;
  this->needsMatrixWS = 0;
  if ( !v3 )
    operator delete(aname._Bx._Ptr);
}
void SkinnedMesh::~SkinnedMesh(SkinnedMesh *this)
{
  CBuffer *v2; // edi
  VertexBuffer<SkinnedMeshVertex> *v3; // ecx
  IndexBuffer *v4; // ecx
  std::vector<SkinnedBone> *v5; // edi
  std::_Ref_count_base *v6; // edi
  std::vector<unsigned short> *v7; // edi
  std::vector<SkinnedMeshVertex> *v8; // edi

  this->__vftable = (SkinnedMesh_vtbl *)&SkinnedMesh::`vftable';
  v2 = this->bonesBuffer;
  if ( v2 )
  {
    CBuffer::release(v2);
    operator delete(v2);
  }
  if ( this->bonesStagingBuffer )
    operator delete[](this->bonesStagingBuffer);
  v3 = this->vb;
  if ( v3 )
    ((void (*)(VertexBuffer<SkinnedMeshVertex> *, int))v3->~VertexBuffer<SkinnedMeshVertex>)(v3, 1);
  v4 = this->ib;
  if ( v4 )
    ((void (*)(IndexBuffer *, int))v4->~IndexBuffer)(v4, 1);
  v5 = &this->bones;
  if ( this->bones._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->bones);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<SkinnedBone>>>(v5->_Myfirst, this->bones._Mylast);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->bones._Mylast = 0;
    this->bones._Myend = 0;
  }
  v6 = this->material._Rep;
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v6->_Weaks) )
        v6->_Delete_this(v6);
    }
  }
  v7 = &this->indices;
  if ( this->indices._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->indices);
    operator delete(v7->_Myfirst);
    v7->_Myfirst = 0;
    this->indices._Mylast = 0;
    this->indices._Myend = 0;
  }
  v8 = &this->vertices;
  if ( this->vertices._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->vertices);
    operator delete(v8->_Myfirst);
    v8->_Myfirst = 0;
    this->vertices._Mylast = 0;
    this->vertices._Myend = 0;
  }
  Renderable::~Renderable(this);
}
SkinnedMesh *SkinnedMesh::`vector deleting destructor'(SkinnedMesh *this, unsigned int a2)
{
  SkinnedMesh::~SkinnedMesh(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SkinnedMesh::addBone(SkinnedMesh *this, Node *node, mat44f offsetMatrix)
{
  SkinnedBone *v4; // eax
  SkinnedBone v5; // [esp+8h] [ebp-6Ch] BYREF
  int v6; // [esp+70h] [ebp-4h]

  SkinnedBone::SkinnedBone(&v5, node, &offsetMatrix);
  v6 = 0;
  std::vector<SkinnedBone>::push_back(&this->bones, v4);
  if ( v5.connectionName._Myres >= 8 )
    operator delete(v5.connectionName._Bx._Ptr);
}
void __userpurge SkinnedMesh::compile(SkinnedMesh *this@<ecx>, __m128 a2@<xmm0>, CompileContext *cc)
{
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // ebx
  VertexBuffer<SkinnedMeshVertex> *v8; // ecx
  IndexBuffer *v9; // ecx
  VertexBuffer<SkinnedMeshVertex> *v10; // eax
  VertexBuffer<SkinnedMeshVertex> *v11; // ebx
  void *v12; // eax
  IndexBuffer *v13; // eax
  IndexBuffer *v14; // eax

  if ( this->ib || this->vb )
  {
    v4 = &this->name;
    if ( this->name._Myres >= 8 )
      v4 = (std::wstring *)v4->_Bx._Ptr;
    _printf("WARNING: Skinned Mesh %S is already compiled\n", v4->_Bx._Buf);
  }
  if ( this->vertices._Myfirst == this->vertices._Mylast )
  {
    v5 = &this->name;
    if ( this->name._Myres >= 8 )
      v5 = (std::wstring *)v5->_Bx._Ptr;
    _printf("WARNING ZERO VERTICES IN SKINNED MESH %S\n", v5->_Bx._Buf);
    _fflush(0);
  }
  if ( this->indices._Myfirst != this->indices._Mylast )
  {
    if ( !this->material._Ptr )
    {
      v6 = &this->name;
      if ( this->name._Myres >= 8 )
        v6 = (std::wstring *)v6->_Bx._Ptr;
      _printf("WARNING: SKINNED MESH %S has NULL material\n", v6->_Bx._Buf);
    }
    if ( (unsigned int)(this->vertices._Mylast - this->vertices._Myfirst) > 0xFFFA )
    {
      v7 = &this->name;
      if ( this->name._Myres >= 8 )
        v7 = (std::wstring *)v7->_Bx._Ptr;
      _printf(
        "WARNING,SKINNED MESH %S HAS %d vertices\n",
        v7->_Bx._Buf,
        this->vertices._Mylast - this->vertices._Myfirst);
    }
    v8 = this->vb;
    if ( v8 )
      ((void (*)(VertexBuffer<SkinnedMeshVertex> *, int))v8->~VertexBuffer<SkinnedMeshVertex>)(v8, 1);
    v9 = this->ib;
    if ( v9 )
      ((void (*)(IndexBuffer *, int))v9->~IndexBuffer)(v9, 1);
    v10 = (VertexBuffer<SkinnedMeshVertex> *)operator new(8);
    v11 = v10;
    if ( v10 )
    {
      v10->kid = 0;
      v10->__vftable = (VertexBuffer<SkinnedMeshVertex>_vtbl *)&VertexBuffer<SkinnedMeshVertex>::`vftable';
      kglCreateVertexBuffer(
        (int)this,
        (int)this->vertices._Myfirst,
        76 * (this->vertices._Mylast - this->vertices._Myfirst),
        0x4Cu,
        this->vertices._Myfirst);
      v11->kid = v12;
    }
    else
    {
      v11 = 0;
    }
    this->vb = v11;
    v13 = (IndexBuffer *)operator new(8);
    if ( v13 )
      IndexBuffer::IndexBuffer(v13, &this->indices);
    else
      v14 = 0;
    this->ib = v14;
    SkinnedMesh::updateBoundingSphere(this, a2);
    SkinnedMesh::initBonesBuffer(this, cc->graphics);
    this->compiledIndicesCount = this->indices._Mylast - this->indices._Myfirst;
    this->compiledVerticesCount = this->vertices._Mylast - this->vertices._Myfirst;
  }
}
void SkinnedMesh::initBonesBuffer(SkinnedMesh *this, GraphicsManager *graphics)
{
  int v3; // esi
  CBuffer *v4; // eax
  CBuffer *v5; // eax
  int v6; // esi
  mat44f *v7; // eax
  int v8; // edx
  float *v9; // ecx

  v3 = (this->bones._Mylast - this->bones._Myfirst) << 6;
  v4 = (CBuffer *)operator new(24);
  if ( v4 )
    CBuffer::CBuffer(v4, 13, v3);
  else
    v5 = 0;
  this->bonesBuffer = v5;
  v6 = this->bones._Mylast - this->bones._Myfirst;
  v7 = (mat44f *)operator new[](v6 << 6);
  if ( v7 )
  {
    v8 = v6 - 1;
    if ( v6 - 1 >= 0 )
    {
      v9 = &v7->M13;
      do
      {
        --v8;
        *(v9 - 2) = 0.0;
        *(v9 - 1) = 0.0;
        v9 += 16;
        *(v9 - 16) = 0.0;
        *(v9 - 15) = 0.0;
        *(v9 - 14) = 0.0;
        *(v9 - 13) = 0.0;
        *(v9 - 12) = 0.0;
        *(v9 - 11) = 0.0;
        *(v9 - 10) = 0.0;
        *(v9 - 9) = 0.0;
        *(v9 - 8) = 0.0;
        *(v9 - 7) = 0.0;
        *(v9 - 6) = 0.0;
        *(v9 - 5) = 0.0;
        *(v9 - 4) = 0.0;
        *(v9 - 3) = 0.0;
      }
      while ( v8 >= 0 );
    }
    this->bonesStagingBuffer = v7;
  }
  else
  {
    this->bonesStagingBuffer = 0;
  }
}
void SkinnedMesh::render(SkinnedMesh *this, RenderContext *rc)
{
  VertexBuffer<SkinnedMeshVertex> *v3; // eax
  IVertexBuffer *v4; // eax

  if ( this->compiledIndicesCount >= 3
    && rc->meshFilter->isVisible(rc->meshFilter, this, &this->parent->Renderable::matrixWS) )
  {
    if ( this->material._Ptr )
      ((void (__stdcall *)(std::shared_ptr<Material> *, RenderContext *))rc->materialFilter->apply)(&this->material, rc);
    v3 = this->vb;
    if ( v3 )
      v4 = &v3->IVertexBuffer;
    else
      v4 = 0;
    GraphicsManager::setVB(rc->graphics, v4);
    GraphicsManager::setIB(rc->graphics, this->ib);
    GraphicsManager::commitShaderChanges(rc->graphics);
    SkinnedMesh::updateBonesBuffer(this, rc);
    GraphicsManager::drawPrimitive(rc->graphics, this->compiledIndicesCount, 0, 0, this->compiledVerticesCount);
    Node::render(this, rc);
  }
}
void SkinnedMesh::updateBonesBuffer(SkinnedMesh *this, RenderContext *rc)
{
  int c; // [esp+4h] [ebp-Ch] BYREF
  SkinnedMesh::updateBonesBuffer::__l3::<lambda_f7f3c0a4587723a565451995b885d16d> _Func; // [esp+8h] [ebp-8h] BYREF

  c = 0;
  _Func.__this = this;
  _Func.c = &c;
  std::_For_each<SkinnedBone *,_lambda_f7f3c0a4587723a565451995b885d16d_>(
    this->bones._Myfirst,
    this->bones._Mylast,
    &_Func);
  CBuffer::map(this->bonesBuffer, this->bonesStagingBuffer, (this->bones._Mylast - this->bones._Myfirst) << 6);
  CBuffer::commit(this->bonesBuffer);
}
void __usercall SkinnedMesh::updateBoundingSphere(SkinnedMesh *this@<ecx>, __m128 a2@<xmm0>)
{
  unsigned int v2; // ebx
  SkinnedMeshVertex *v3; // edi
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  float v6; // xmm0_4
  unsigned int v7; // ebx
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  SkinnedMeshVertex *v13; // edi
  float v14; // xmm2_4
  float v15; // xmm0_4

  a2.m128_f32[0] = 0.0;
  v2 = 0;
  *(_QWORD *)&this->boundingSphere.center.x = _mm_unpacklo_ps(a2, (__m128)0i64).m128_u64[0];
  this->boundingSphere.center.z = 0.0;
  this->boundingSphere.radius = 0.0;
  if ( this->vertices._Mylast - this->vertices._Myfirst )
  {
    v3 = this->vertices._Myfirst;
    do
    {
      v4 = (__m128)LODWORD(this->boundingSphere.center.x);
      ++v2;
      v5 = (__m128)LODWORD(v3->pos.y);
      v4.m128_f32[0] = v4.m128_f32[0] + v3->pos.x;
      v5.m128_f32[0] = v5.m128_f32[0] + this->boundingSphere.center.y;
      v6 = v3->pos.z + this->boundingSphere.center.z;
      ++v3;
      *(_QWORD *)&this->boundingSphere.center.x = _mm_unpacklo_ps(v4, v5).m128_u64[0];
      this->boundingSphere.center.z = v6;
    }
    while ( v2 < this->vertices._Mylast - this->vertices._Myfirst );
  }
  v7 = 0;
  v8 = (__m128)LODWORD(this->boundingSphere.center.x);
  v9 = (__m128)LODWORD(this->boundingSphere.center.y);
  v10 = (float)(unsigned int)(this->vertices._Mylast - this->vertices._Myfirst);
  v8.m128_f32[0] = v8.m128_f32[0] * (float)(1.0 / v10);
  v9.m128_f32[0] = v9.m128_f32[0] * (float)(1.0 / v10);
  v11 = this->boundingSphere.center.z * (float)(1.0 / v10);
  *(_QWORD *)&this->boundingSphere.center.x = _mm_unpacklo_ps(v8, v9).m128_u64[0];
  v12 = 0.0;
  this->boundingSphere.center.z = v11;
  if ( this->vertices._Mylast - this->vertices._Myfirst )
  {
    v13 = this->vertices._Myfirst;
    do
    {
      v14 = (float)((float)((float)(v13->pos.y - this->boundingSphere.center.y)
                          * (float)(v13->pos.y - this->boundingSphere.center.y))
                  + (float)((float)(v13->pos.x - this->boundingSphere.center.x)
                          * (float)(v13->pos.x - this->boundingSphere.center.x)))
          + (float)((float)(v13->pos.z - this->boundingSphere.center.z)
                  * (float)(v13->pos.z - this->boundingSphere.center.z));
      v15 = 0.0;
      if ( v14 != 0.0 )
        v15 = fsqrt(v14);
      if ( v15 > v12 )
      {
        v12 = v15;
        this->boundingSphere.radius = v15;
      }
      ++v7;
      ++v13;
    }
    while ( v7 < this->vertices._Mylast - this->vertices._Myfirst );
  }
}
