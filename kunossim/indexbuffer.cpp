#include "indexbuffer.h
void IndexBuffer::IndexBuffer(IndexBuffer *this, std::vector<unsigned short> *indices)
{
  void *v3; // eax

  this->__vftable = (IndexBuffer_vtbl *)&IndexBuffer::`vftable';
  this->kid = 0;
  kglCreateIndexBuffer(2 * (indices->_Mylast - indices->_Myfirst), indices->_Myfirst);
  this->kid = v3;
}
IndexBuffer *IndexBuffer::`vector deleting destructor'(IndexBuffer *this, unsigned int a2)
{
  void *v3; // eax

  v3 = this->kid;
  this->__vftable = (IndexBuffer_vtbl *)&IndexBuffer::`vftable';
  if ( v3 )
    kglDestroyVertexBuffer(v3);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
