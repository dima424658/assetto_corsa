#include "mesh.h
void Mesh::Mesh(Mesh *this, const Mesh *mesh)
{
  std::_Ref_count_base *v3; // edx
  Material *v4; // ebp
  std::_Ref_count_base *v5; // edi

  Renderable::Renderable(this, mesh);
  this->__vftable = (Mesh_vtbl *)&Mesh::`vftable';
  this->vertices._Myfirst = 0;
  this->vertices._Mylast = 0;
  this->vertices._Myend = 0;
  this->indices._Myfirst = 0;
  this->indices._Mylast = 0;
  this->indices._Myend = 0;
  this->material._Ptr = 0;
  this->material._Rep = 0;
  this->isRenderable = 1;
  this->vb = 0;
  this->ib = 0;
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
  this->layer = mesh->layer;
  this->isRenderable = mesh->isRenderable;
  this->needsMatrixWS = 0;
  this->vb = 0;
  this->ib = 0;
  std::vector<MeshVertex>::operator=(&this->vertices, &mesh->vertices);
  std::vector<unsigned short>::operator=(&this->indices, &mesh->indices);
}
void Mesh::Mesh(Mesh *this, std::wstring name)
{
  bool v3; // cf
  std::wstring v4; // [esp-18h] [ebp-30h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  v5 = 0;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, &name, 0, 0xFFFFFFFF);
  Renderable::Renderable(this, v4);
  v3 = name._Myres < 8;
  this->__vftable = (Mesh_vtbl *)&Mesh::`vftable';
  this->vertices._Myfirst = 0;
  this->vertices._Mylast = 0;
  this->vertices._Myend = 0;
  this->indices._Myfirst = 0;
  this->indices._Mylast = 0;
  this->indices._Myend = 0;
  this->material._Ptr = 0;
  this->material._Rep = 0;
  this->isRenderable = 1;
  this->compiledIndicesCount = 0;
  this->compiledVerticesCount = 0;
  this->needsMatrixWS = 0;
  this->vb = 0;
  this->ib = 0;
  if ( !v3 )
    operator delete(name._Bx._Ptr);
}
void Mesh::~Mesh(Mesh *this)
{
  VertexBuffer<MeshVertex> *v2; // ecx
  IndexBuffer *v3; // ecx
  std::_Ref_count_base *v4; // edi
  std::vector<unsigned short> *v5; // edi
  std::vector<MeshVertex> *v6; // edi

  this->__vftable = (Mesh_vtbl *)&Mesh::`vftable';
  v2 = this->vb;
  if ( v2 )
    ((void (*)(VertexBuffer<MeshVertex> *, int))v2->~VertexBuffer<MeshVertex>)(v2, 1);
  v3 = this->ib;
  if ( v3 )
    ((void (*)(IndexBuffer *, int))v3->~IndexBuffer)(v3, 1);
  v4 = this->material._Rep;
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v4->_Uses, 0xFFFFFFFF) )
    {
      v4->_Destroy(v4);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v4->_Weaks) )
        v4->_Delete_this(v4);
    }
  }
  v5 = &this->indices;
  if ( this->indices._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->indices);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->indices._Mylast = 0;
    this->indices._Myend = 0;
  }
  v6 = &this->vertices;
  if ( this->vertices._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->vertices);
    operator delete(v6->_Myfirst);
    v6->_Myfirst = 0;
    this->vertices._Mylast = 0;
    this->vertices._Myend = 0;
  }
  Renderable::~Renderable(this);
}
Mesh *Mesh::`scalar deleting destructor'(Mesh *this, unsigned int a2)
{
  Mesh::~Mesh(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Mesh::addChild(Mesh *this, Node *n)
{
  _printf("ERROR:  Mesh::addChild is not allowed\n");
  ksGenerateCrash();
}
void Mesh::compile(Mesh *this, CompileContext *cc)
{
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  std::vector<unsigned short> *v5; // ebx
  std::wstring *v6; // eax
  std::wstring *v7; // ebx
  VertexBuffer<MeshVertex> *v8; // ecx
  IndexBuffer *v9; // ecx
  VertexBuffer<MeshVertex> *v10; // eax
  VertexBuffer<MeshVertex> *v11; // eax
  IndexBuffer *v12; // eax
  IndexBuffer *v13; // eax
  __m128 v14; // xmm0
  __int64 v15; // [esp-4h] [ebp-28h]

  if ( this->ib || this->vb )
  {
    v3 = &this->name;
    if ( this->name._Myres >= 8 )
      v3 = (std::wstring *)v3->_Bx._Ptr;
    _printf("WARNING: Mesh %S is already compiled, recompiling\n", v3->_Bx._Buf);
    this->boundingSphere.radius = 0.0;
  }
  if ( this->vertices._Myfirst == this->vertices._Mylast )
  {
    v4 = &this->name;
    if ( this->name._Myres >= 8 )
      v4 = (std::wstring *)v4->_Bx._Ptr;
    _printf("WARNING: ZERO VERTICES IN MESH %S\n", v4->_Bx._Buf);
  }
  v5 = &this->indices;
  if ( this->indices._Myfirst != this->indices._Mylast && this->isRenderable )
  {
    if ( !this->material._Ptr )
    {
      v6 = &this->name;
      if ( this->name._Myres >= 8 )
        v6 = (std::wstring *)v6->_Bx._Ptr;
      _printf("WARNING: MESH %S HAS NULL MATERIAL\n", v6->_Bx._Buf);
    }
    if ( (unsigned int)(this->vertices._Mylast - this->vertices._Myfirst) > 0xFFFA )
    {
      v7 = &this->name;
      if ( this->name._Myres >= 8 )
        v7 = (std::wstring *)v7->_Bx._Ptr;
      LODWORD(v15) = this->vertices._Mylast - this->vertices._Myfirst;
      _printf("WARNING: MESH %S HAS %llu vertices\n", v7->_Bx._Buf, v15);
      v5 = &this->indices;
    }
    v8 = this->vb;
    if ( v8 )
      ((void (*)(VertexBuffer<MeshVertex> *, int))v8->~VertexBuffer<MeshVertex>)(v8, 1);
    v9 = this->ib;
    if ( v9 )
      ((void (*)(IndexBuffer *, int))v9->~IndexBuffer)(v9, 1);
    v10 = (VertexBuffer<MeshVertex> *)operator new(8);
    if ( v10 )
      VertexBuffer<MeshVertex>::VertexBuffer<MeshVertex>(v10, &this->vertices);
    else
      v11 = 0;
    this->vb = v11;
    v12 = (IndexBuffer *)operator new(8);
    if ( v12 )
      IndexBuffer::IndexBuffer(v12, v5);
    else
      v13 = 0;
    v14 = (__m128)LODWORD(this->boundingSphere.radius);
    this->ib = v13;
    if ( v14.m128_f32[0] == 0.0 )
      Mesh::updateBoundingSphere(this, v14);
    this->compiledIndicesCount = v5->_Mylast - v5->_Myfirst;
    this->compiledVerticesCount = this->vertices._Mylast - this->vertices._Myfirst;
  }
}
Triangle *Mesh::getTriangle(Mesh *this, Triangle *result, int index)
{
  Triangle::Triangle(
    result,
    &this->vertices._Myfirst[this->indices._Myfirst[3 * index]].pos,
    &this->vertices._Myfirst[this->indices._Myfirst[3 * index + 1]].pos,
    &this->vertices._Myfirst[this->indices._Myfirst[3 * index + 2]].pos);
  return result;
}
void Mesh::render(Mesh *this, RenderContext *rc)
{
  Node *v3; // eax
  VertexBuffer<MeshVertex> *v4; // eax
  IVertexBuffer *v5; // eax

  if ( this->ib )
  {
    if ( this->vb )
    {
      if ( this->isRenderable )
      {
        v3 = this->parent;
        if ( !v3 || rc->meshFilter->isVisible(rc->meshFilter, this, &v3->matrixWS) )
        {
          if ( this->material._Ptr )
            ((void (__stdcall *)(std::shared_ptr<Material> *, RenderContext *))rc->materialFilter->apply)(
              &this->material,
              rc);
          v4 = this->vb;
          if ( v4 )
            v5 = &v4->IVertexBuffer;
          else
            v5 = 0;
          GraphicsManager::setVB(rc->graphics, v5);
          GraphicsManager::setIB(rc->graphics, this->ib);
          GraphicsManager::commitShaderChanges(rc->graphics);
          GraphicsManager::drawPrimitive(rc->graphics, this->compiledIndicesCount, 0, 0, this->compiledVerticesCount);
        }
      }
    }
  }
}
void __usercall Mesh::updateBoundingSphere(Mesh *this@<ecx>, __m128 a2@<xmm0>)
{
  unsigned int v2; // ebx
  MeshVertex *v3; // edi
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  float v6; // xmm0_4
  unsigned int v7; // ebx
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  MeshVertex *v13; // edi
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
