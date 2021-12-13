#include "cbuffer.h"
void CBuffer::CBuffer(CBuffer *this, int islot, int isize)
{
  unsigned __int8 *v4; // eax
  void *v5; // eax
  int v6; // [esp-14h] [ebp-18h]
  int v7; // [esp-8h] [ebp-Ch]

  this->slot = 0;
  *(_WORD *)&this->isPS = 0;
  this->kid = 0;
  this->data = 0;
  this->touched = 0;
  this->isSystem = 0;
  this->size = isize;
  v4 = (unsigned __int8 *)operator new[](isize);
  v7 = this->size;
  this->data = v4;
  memset(v4, 0, v7);
  v6 = this->size;
  *(_WORD *)&this->isPS = 0;
  this->slot = islot;
  kglCreateCBuffer(v6);
  this->kid = v5;
  this->touched = 1;
}
void CBuffer::CBuffer(CBuffer *this)
{
  this->size = 0;
  this->slot = 0;
  *(_WORD *)&this->isSystem = 0;
  this->isVS = 0;
  this->kid = 0;
  this->data = 0;
  this->touched = 0;
}
void CBuffer::commit(CBuffer *this)
{
  if ( this->touched )
  {
    kglCBufferMap(this->kid, this->data);
    if ( !this->isSystem )
    {
LABEL_5:
      kglCBufferBind(this->kid, this->slot);
      goto LABEL_6;
    }
    kglCBufferBind(this->kid, this->slot);
  }
  if ( !this->isSystem )
    goto LABEL_5;
LABEL_6:
  this->touched = 0;
}
void CBuffer::get(CBuffer *this, float *value, int offset, int size)
{
  memcpy(value, &this->data[offset], size);
}
void CBuffer::init(CBuffer *this, int islot, int isize)
{
  unsigned __int8 *v4; // eax
  void *v5; // eax
  int v6; // [esp-14h] [ebp-18h]
  int v7; // [esp-8h] [ebp-Ch]

  this->isSystem = 0;
  this->size = isize;
  v4 = (unsigned __int8 *)operator new[](isize);
  v7 = this->size;
  this->data = v4;
  memset(v4, 0, v7);
  v6 = this->size;
  *(_WORD *)&this->isPS = 0;
  this->slot = islot;
  kglCreateCBuffer(v6);
  this->kid = v5;
  this->touched = 1;
}
void CBuffer::map(CBuffer *this, void *bdata, int bsize)
{
  kglCBufferMap(this->kid, bdata);
  this->touched = 0;
}
void CBuffer::release(CBuffer *this)
{
  if ( this->data && this->kid )
  {
    operator delete[](this->data);
    kglDestroyCBuffer(this->kid);
  }
  this->data = 0;
  this->kid = 0;
}
void CBuffer::set(CBuffer *this, float *value, int offset, int size)
{
  memcpy(&this->data[offset], value, size);
  this->touched = 1;
}
void CBuffer::touch(CBuffer *this)
{
  this->touched = 1;
}
