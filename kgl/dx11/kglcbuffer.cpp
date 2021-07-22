#include "kglcbuffer.h
void KGLCBuffer::KGLCBuffer(KGLCBuffer *this, ID3D11Device *device, unsigned int isize)
{
  ID3D11Device *v3; // edx
  ID3D11Buffer **v5; // esi
  D3D11_BUFFER_DESC cbDesc; // [esp+0h] [ebp-1Ch] BYREF

  v3 = ::device;
  *(_QWORD *)&cbDesc.MiscFlags = 0i64;
  v5 = &this->buffer;
  cbDesc.ByteWidth = isize;
  this->size = isize;
  this->buffer = 0;
  cbDesc.Usage = D3D11_USAGE_DEFAULT;
  cbDesc.CPUAccessFlags = 0;
  cbDesc.BindFlags = 4;
  v3->CreateBuffer(v3, &cbDesc, 0, &this->buffer);
  if ( !*v5 )
    _printf("ERROR: CBuffer CreateBuffer failed size=%d\n", this->size);
}
