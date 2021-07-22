#include "worldmatrixtraverser.h
void WorldMatrixTraverser::traverse(WorldMatrixTraverser *this, Node *node)
{
  Node *v3; // eax
  Node **v4; // eax
  Node **v5; // esi
  int v6; // edi
  unsigned int v7; // ebx

  if ( node->isActive && (node->needsMatrixWS || node->nodes._Myfirst != node->nodes._Mylast) )
  {
    v3 = node->parent;
    if ( v3 )
    {
      mul(&node->matrixWS, &node->matrix, &v3->matrixWS);
    }
    else
    {
      *(__m128i *)&node->matrixWS.M11 = _mm_loadu_si128((const __m128i *)&node->matrix);
      *(__m128i *)&node->matrixWS.M21 = _mm_loadu_si128((const __m128i *)&node->matrix.M21);
      *(__m128i *)&node->matrixWS.M31 = _mm_loadu_si128((const __m128i *)&node->matrix.M31);
      *(__m128i *)&node->matrixWS.M41 = _mm_loadu_si128((const __m128i *)&node->matrix.M41);
    }
    v4 = node->nodes._Mylast;
    v5 = node->nodes._Myfirst;
    v6 = 0;
    v7 = (unsigned int)((char *)v4 - (char *)v5 + 3) >> 2;
    if ( v5 > v4 )
      v7 = 0;
    if ( v7 )
    {
      do
      {
        WorldMatrixTraverser::traverse(this, *v5);
        ++v6;
        ++v5;
      }
      while ( v6 != v7 );
    }
  }
}
