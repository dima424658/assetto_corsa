#include "matrixstack.h"
void MatrixStack::MatrixStack(MatrixStack *this)
{
  mat44f *v1; // eax
  int v2; // edx

  this->__vftable = (MatrixStack_vtbl *)&MatrixStack::`vftable';
  v1 = this->stack;
  v2 = 23;
  do
  {
    --v2;
    v1->M11 = 0.0;
    v1->M12 = 0.0;
    ++v1;
    v1[-1].M13 = 0.0;
    v1[-1].M14 = 0.0;
    v1[-1].M21 = 0.0;
    v1[-1].M22 = 0.0;
    v1[-1].M23 = 0.0;
    v1[-1].M24 = 0.0;
    v1[-1].M31 = 0.0;
    v1[-1].M32 = 0.0;
    v1[-1].M33 = 0.0;
    v1[-1].M34 = 0.0;
    v1[-1].M41 = 0.0;
    v1[-1].M42 = 0.0;
    v1[-1].M43 = 0.0;
    v1[-1].M44 = 0.0;
  }
  while ( v2 >= 0 );
  this->currentIndex = 0;
}
void MatrixStack::~MatrixStack(MatrixStack *this)
{
  this->__vftable = (MatrixStack_vtbl *)&MatrixStack::`vftable';
}
MatrixStack *MatrixStack::`scalar deleting destructor'(MatrixStack *this, unsigned int a2)
{
  this->__vftable = (MatrixStack_vtbl *)&MatrixStack::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
mat44f *MatrixStack::getCurrentMatrix(MatrixStack *this, mat44f *result)
{
  char *v2; // ecx
  mat44f *v3; // eax

  v2 = (char *)this + 64 * this->currentIndex;
  v3 = result;
  *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)(v2 + 8));
  *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)(v2 + 24));
  *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)(v2 + 40));
  *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)(v2 + 56));
  return v3;
}
void MatrixStack::multMatrix(MatrixStack *this, mat44f *m)
{
  char *v3; // esi
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm2
  __int128 v10; // xmm3
  DirectX::XMMATRIX M2; // [esp+10h] [ebp-40h] BYREF

  v3 = (char *)this + 64 * this->currentIndex;
  v4 = *(__m128 *)(v3 + 24);
  v5 = *(__m128 *)(v3 + 40);
  v6 = *(__m128 *)(v3 + 56);
  M2.r[0] = *(__m128 *)(v3 + 8);
  v7 = *(__m128 *)&m->M11;
  M2.r[1] = v4;
  v8 = *(_OWORD *)&m->M21;
  M2.r[2] = v5;
  v9 = *(_OWORD *)&m->M31;
  M2.r[3] = v6;
  v10 = *(_OWORD *)&m->M41;
  *(__m128 *)(v3 + 72) = DirectX::XMMatrixMultiply(M2.r, v7);
  *(_OWORD *)(v3 + 88) = v8;
  *(_OWORD *)(v3 + 104) = v9;
  *(_OWORD *)(v3 + 120) = v10;
  ++this->currentIndex;
}
void MatrixStack::popMatrix(MatrixStack *this)
{
  --this->currentIndex;
}
void MatrixStack::pushAndSetMatrix(MatrixStack *this, mat44f *m)
{
  char *v2; // edx

  v2 = (char *)this + 64 * this->currentIndex;
  *(__m128i *)(v2 + 72) = _mm_loadu_si128((const __m128i *)m);
  *(__m128i *)(v2 + 88) = _mm_loadu_si128((const __m128i *)&m->M21);
  *(__m128i *)(v2 + 104) = _mm_loadu_si128((const __m128i *)&m->M31);
  *(__m128i *)(v2 + 120) = _mm_loadu_si128((const __m128i *)&m->M41);
  ++this->currentIndex;
}
void MatrixStack::reset(MatrixStack *this)
{
  mat44f mat; // [esp+4h] [ebp-40h] BYREF

  this->currentIndex = 0;
  mat44f::mat44f(&mat);
  mat44f::loadIdentity(&mat);
  *(__m128i *)&this->stack[0].M11 = _mm_loadu_si128((const __m128i *)&mat);
  *(__m128i *)&this->stack[0].M21 = _mm_loadu_si128((const __m128i *)&mat.M21);
  *(__m128i *)&this->stack[0].M31 = _mm_loadu_si128((const __m128i *)&mat.M31);
  *(__m128i *)&this->stack[0].M41 = _mm_loadu_si128((const __m128i *)&mat.M41);
}
