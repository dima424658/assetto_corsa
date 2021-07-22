#include "modelboundaries.h
ModelBoundariesCoordinates *__cdecl ModelBoundaries::computeAAModelBoundaries(ModelBoundariesCoordinates *result, Node *base)
{
  __m128i v2; // xmm0
  mat44f v4; // [esp-40h] [ebp-84h]
  mat44f matrix; // [esp+4h] [ebp-40h] BYREF

  mat44f::mat44f(&matrix);
  mat44f::loadIdentity(&matrix);
  v2 = _mm_loadu_si128((const __m128i *)&matrix);
  result->front = 0.0;
  result->rear = 0.0;
  result->left = 0.0;
  result->right = 0.0;
  result->top = 0.0;
  result->bottom = 0.0;
  *(__m128i *)&v4.M11 = v2;
  *(__m128i *)&v4.M21 = _mm_loadu_si128((const __m128i *)&matrix.M21);
  *(__m128i *)&v4.M31 = _mm_loadu_si128((const __m128i *)&matrix.M31);
  *(__m128i *)&v4.M41 = _mm_loadu_si128((const __m128i *)&matrix.M41);
  ModelBoundaries::computeAAModelBoundariesRecursive(base, result, v4);
  return result;
}
void __cdecl ModelBoundaries::computeAAModelBoundariesRecursive(Node *base, ModelBoundariesCoordinates *mb, mat44f currentMatrix)
{
  Node *v3; // edi
  int v4; // eax
  const MeshVertex *v5; // edi
  const MeshVertex *v6; // esi
  float *v7; // eax
  ModelBoundariesCoordinates *v8; // edx
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  __m128 v17; // xmm0
  __int128 v18; // xmm1
  __int128 v19; // xmm2
  __int128 v20; // xmm3
  Node **v21; // esi
  Node **v22; // eax
  unsigned int v23; // edi
  mat44f v24; // [esp-40h] [ebp-A0h]
  int v25; // [esp+14h] [ebp-4Ch]
  int v26; // [esp+1Ch] [ebp-44h]
  __m128 v27[4]; // [esp+20h] [ebp-40h] BYREF

  v3 = base;
  v4 = __RTDynamicCast(base, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
  v26 = v4;
  if ( !v4 )
  {
    v27[0] = *(__m128 *)&currentMatrix.M11;
    v17 = *(__m128 *)&base->matrix.M11;
    v27[1] = *(__m128 *)&currentMatrix.M21;
    v18 = *(_OWORD *)&base->matrix.M21;
    v27[2] = *(__m128 *)&currentMatrix.M31;
    v19 = *(_OWORD *)&base->matrix.M31;
    v27[3] = *(__m128 *)&currentMatrix.M41;
    v20 = *(_OWORD *)&base->matrix.M41;
    *(__m128 *)&currentMatrix.M11 = DirectX::XMMatrixMultiply(v27, v17);
    *(_OWORD *)&currentMatrix.M21 = v18;
    *(_OWORD *)&currentMatrix.M31 = v19;
    *(_OWORD *)&currentMatrix.M41 = v20;
    goto LABEL_25;
  }
  v5 = *(const MeshVertex **)(v4 + 228);
  v6 = *(const MeshVertex **)(v4 + 224);
  if ( v6 == v5 )
  {
    v3 = base;
LABEL_25:
    v8 = mb;
    goto LABEL_26;
  }
  do
  {
    MeshVertex::MeshVertex((MeshVertex *)v27, v6);
    v7 = *(float **)(v26 + 148);
    v8 = mb;
    v9 = (float)((float)((float)(v7[21] * v27[0].m128_f32[1]) + (float)(v7[17] * v27[0].m128_f32[0]))
               + (float)(v7[25] * v27[0].m128_f32[2]))
       + v7[29];
    v10 = (float)((float)((float)(v7[22] * v27[0].m128_f32[1]) + (float)(v7[18] * v27[0].m128_f32[0]))
                + (float)(v7[26] * v27[0].m128_f32[2]))
        + v7[30];
    v11 = (float)((float)((float)(v7[23] * v27[0].m128_f32[1]) + (float)(v7[19] * v27[0].m128_f32[0]))
                + (float)(v7[27] * v27[0].m128_f32[2]))
        + v7[31];
    if ( mb->front == 0.0 || v11 > mb->front )
      mb->front = v11;
    v12 = mb->rear;
    if ( v12 == 0.0 || v12 > v11 )
      mb->rear = v11;
    v13 = mb->left;
    if ( v13 == 0.0 || v13 > v9 )
      mb->left = v9;
    v14 = mb->right;
    if ( v14 == 0.0 || v9 > v14 )
      mb->right = v9;
    v15 = mb->top;
    if ( v15 == 0.0 || v10 > v15 )
      mb->top = v10;
    v16 = mb->bottom;
    if ( v16 == 0.0 || v16 > v10 )
      mb->bottom = v10;
    ++v6;
  }
  while ( v6 != v5 );
  v3 = base;
LABEL_26:
  v21 = v3->nodes._Myfirst;
  v22 = v3->nodes._Mylast;
  v25 = 0;
  v23 = (unsigned int)((char *)v22 - (char *)v21 + 3) >> 2;
  if ( v21 > v22 )
    v23 = 0;
  if ( v23 )
  {
    do
    {
      *(__m128i *)&v24.M11 = _mm_loadu_si128((const __m128i *)&currentMatrix);
      *(__m128i *)&v24.M21 = _mm_loadu_si128((const __m128i *)&currentMatrix.M21);
      *(__m128i *)&v24.M31 = _mm_loadu_si128((const __m128i *)&currentMatrix.M31);
      *(__m128i *)&v24.M41 = _mm_loadu_si128((const __m128i *)&currentMatrix.M41);
      ModelBoundaries::computeAAModelBoundariesRecursive(*v21++, v8, v24);
      v8 = mb;
      ++v25;
    }
    while ( v25 != v23 );
  }
}
