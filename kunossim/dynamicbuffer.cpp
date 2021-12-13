#include "dynamicbuffer.h"
void DynamicBuffer::DynamicBuffer(DynamicBuffer *this, unsigned int isize)
{
  int v3; // eax
  MeshVertex *v4; // edi
  signed int v5; // edx
  int v6; // ecx
  size_t v7; // eax
  unsigned int v8; // ecx
  void *v9; // eax

  this->__vftable = (DynamicBuffer_vtbl *)&DynamicBuffer::`vftable';
  this->oldNumberOfVerticesToCommit = 0;
  this->size = isize;
  v3 = operator new[](44 * isize);
  v4 = (MeshVertex *)v3;
  if ( v3 )
  {
    v5 = isize - 1;
    if ( (int)(isize - 1) >= 0 )
    {
      v6 = v3 + 20;
      do
      {
        --v5;
        *(_DWORD *)(v6 - 20) = 0;
        *(_DWORD *)(v6 - 16) = 0;
        v6 += 44;
        *(_DWORD *)(v6 - 56) = 0;
        *(_DWORD *)(v6 - 52) = 0;
        *(_DWORD *)(v6 - 48) = 0;
        *(_DWORD *)(v6 - 44) = 0;
        *(_DWORD *)(v6 - 40) = 0;
        *(_DWORD *)(v6 - 36) = 0;
        *(_DWORD *)(v6 - 32) = 0;
        *(_DWORD *)(v6 - 28) = 0;
        *(_DWORD *)(v6 - 24) = 0;
      }
      while ( v5 >= 0 );
    }
  }
  else
  {
    v4 = 0;
  }
  v7 = 44 * this->size;
  this->vertices = v4;
  memset(v4, 0, v7);
  kglCreateDynamicVertexBuffer((int)v4, (int)this, 44 * this->size, 0x2Cu, this->vertices);
  v8 = 44 * this->size;
  this->kid = v9;
  kglVertexBufferMap(v9, this->vertices, v8);
}
void DynamicBuffer::~DynamicBuffer(DynamicBuffer *this)
{
  void *v2; // eax

  v2 = this->kid;
  this->__vftable = (DynamicBuffer_vtbl *)&DynamicBuffer::`vftable';
  if ( v2 )
    kglDestroyVertexBuffer(v2);
  if ( this->vertices )
    operator delete[](this->vertices);
}
DynamicBuffer *DynamicBuffer::`scalar deleting destructor'(DynamicBuffer *this, unsigned int a2)
{
  void *v3; // eax

  v3 = this->kid;
  this->__vftable = (DynamicBuffer_vtbl *)&DynamicBuffer::`vftable';
  if ( v3 )
    kglDestroyVertexBuffer(v3);
  if ( this->vertices )
    operator delete[](this->vertices);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DynamicBuffer::commit(DynamicBuffer *this, int numberOfVerticesToCommit)
{
  unsigned int v3; // eax

  v3 = this->size;
  if ( numberOfVerticesToCommit >= v3 )
  {
    kglVertexBufferMap(this->kid, this->vertices, 44 * v3);
  }
  else
  {
    kglVertexBufferMapNoOverwrite(
      this->kid,
      this->vertices,
      44 * this->oldNumberOfVerticesToCommit,
      44 * (numberOfVerticesToCommit - this->oldNumberOfVerticesToCommit));
    this->oldNumberOfVerticesToCommit = numberOfVerticesToCommit;
  }
}
void DynamicBuffer::render(DynamicBuffer *this, unsigned int startIndex, unsigned int vertexCount)
{
  kglSetVertexBuffer(this->kid);
  kglDraw(vertexCount, startIndex);
}
