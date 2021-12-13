#include "pvsprocessor.h"
void PvsProcessor::PvsProcessor(PvsProcessor *this)
{
  int v2; // edx
  sphere *v3; // eax

  v2 = 4095;
  this->rc = 0;
  v3 = this->bounds;
  this->renderMode = Default;
  this->shadowMaps = 0;
  this->cubeMap = 0;
  this->meshCount = 0;
  do
  {
    --v2;
    v3->center.x = 0.0;
    v3->center.y = 0.0;
    ++v3;
    v3[-1].center.z = 0.0;
    v3[-1].radius = 0.0;
  }
  while ( v2 >= 0 );
  std::array<PvsProcessor::DrawCall,4096>::array<PvsProcessor::DrawCall,4096>(&this->drawCalls);
  this->drawCallCount = 0;
}
void PvsProcessor::begin(PvsProcessor *this, RenderContext *rc, const PvsRenderMode renderMode, std::vector<RenderTarget *> *shadowMaps, CubeMap *cubeMap)
{
  this->rc = rc;
  this->renderMode = renderMode;
  this->shadowMaps = shadowMaps;
  this->cubeMap = cubeMap;
  this->meshCount = 0;
}
bool __cdecl PvsProcessor::compareDrawCalls(const PvsProcessor::DrawCall *a, const PvsProcessor::DrawCall *b)
{
  bool v2; // cf
  bool result; // al
  Material *v4; // edx
  Material *v5; // esi
  __int32 v6; // edx
  __int32 v7; // esi
  VertexBuffer<MeshVertex> *v8; // edx
  VertexBuffer<MeshVertex> *v9; // esi
  IndexBuffer *v10; // edx
  IndexBuffer *v11; // esi
  char v12; // dl
  char v13; // al

  v2 = a->shader < b->shader;
  if ( a->shader != b->shader )
    return v2;
  v4 = a->material;
  v5 = b->material;
  v2 = v4 < v5;
  if ( v4 != v5 )
    return v2;
  v6 = a->blendMode;
  v7 = b->blendMode;
  if ( v6 != v7 )
    return v6 < v7;
  v6 = a->cullMode;
  v7 = b->cullMode;
  if ( v6 != v7 )
    return v6 < v7;
  v6 = a->depthMode;
  v7 = b->depthMode;
  if ( v6 != v7 )
    return v6 < v7;
  v8 = a->vb;
  v9 = b->vb;
  v2 = v8 < v9;
  if ( v8 != v9 )
    return v2;
  v10 = a->ib;
  v11 = b->ib;
  v2 = v10 < v11;
  if ( v10 != v11 )
    return v2;
  v12 = a->hasMatrix;
  v13 = b->hasMatrix;
  if ( v12 == v13 )
    result = 0;
  else
    result = !v12 && v13 == 1;
  return result;
}
void PvsProcessor::doDistanceAndLod(PvsProcessor *this)
{
  float v2; // xmm5_4
  Camera *v3; // eax
  float v4; // xmm6_4
  float v5; // xmm7_4
  float v6; // xmm0_4
  bool *v7; // ecx
  float *v8; // edx
  unsigned __int16 *v9; // esi
  float *v10; // edi
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // [esp+4h] [ebp-4h]

  if ( (_S2 & 1) == 0 )
  {
    perfCounter_10.name = "PvsProcessor::doDistanceAndLod";
    _S2 |= 1u;
    perfCounter_10.group = Render;
    perfCounter_10.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PvsProcessor::doDistanceAndLod" | 0xFF000000;
  }
  v2 = FLOAT_1_0;
  v3 = this->rc->camera;
  v4 = v3->matrix.M41;
  v5 = v3->matrix.M42;
  v14 = v3->matrix.M43;
  v6 = v3->fov * 0.0125;
  if ( v6 <= 1.0 )
  {
    if ( v6 >= 0.0 )
      v2 = v3->fov * 0.0125;
    else
      v2 = 0.0;
  }
  if ( this->meshCount > 0 )
  {
    v7 = this->inPvs;
    v8 = this->lodOuts;
    v9 = this->flags;
    v10 = &this->bounds[0].center.z;
    do
    {
      if ( *v7 && (*(_BYTE *)v9 & 0x10) == 0 )
      {
        v11 = *(v8 - 4096);
        if ( v11 != 0.0 || *v8 != 0.0 )
        {
          v12 = *v8;
          v13 = (float)((float)((float)((float)((float)(v5 - *(v10 - 1)) * (float)(v5 - *(v10 - 1)))
                                      + (float)((float)(v4 - *(v10 - 2)) * (float)(v4 - *(v10 - 2))))
                              + (float)((float)(v14 - *v10) * (float)(v14 - *v10)))
                      * v2)
              * v2;
          if ( *v8 <= v10[1] )
            v12 = v10[1];
          if ( (float)(v11 * v11) > v13 || v13 > (float)(v12 * v12) )
            *v7 = 0;
        }
      }
      ++v7;
      ++v9;
      ++v8;
      v10 += 4;
    }
    while ( (int)&v7[-139284 - (_DWORD)this] < this->meshCount );
  }
}
void PvsProcessor::doExclusion(PvsProcessor *this)
{
  bool *v2; // ecx
  int *v3; // ebp
  unsigned __int16 *v4; // esi
  IMeshRenderFilter *v5; // edx
  RenderPassID v6; // eax

  if ( (_S1 & 1) == 0 )
  {
    perfCounter_9.name = "PvsProcessor::doExclusion";
    _S1 |= 1u;
    perfCounter_9.group = Render;
    perfCounter_9.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PvsProcessor::doExclusion" | 0xFF000000;
  }
  if ( this->meshCount > 0 )
  {
    v2 = this->inPvs;
    v3 = this->layers;
    v4 = this->flags;
    do
    {
      *v2 = 0;
      v5 = this->rc->meshFilter;
      if ( *v3 <= v5->maxLayer )
      {
        v6 = v5->passID;
        if ( (v6 != Shadowgen || (*(_BYTE *)v4 & 2) != 0)
          && ((*v4 & 4) == 0 || v6 == Transparent || v6 == Shadowgen)
          && ((*v4 & 4) != 0 || v6 != Transparent)
          && (v6 == Shadowgen || (*v4 & 8) != 0) )
        {
          *v2 = 1;
        }
      }
      ++v2;
      ++v3;
      ++v4;
    }
    while ( (int)&v2[-139284 - (_DWORD)this] < this->meshCount );
  }
}
void PvsProcessor::doFrustumCulling(PvsProcessor *this)
{
  bool *v2; // esi
  int v3; // eax
  sphere *v4; // ebp
  unsigned __int16 *v5; // edi
  bool v6; // cc
  int v7; // [esp+4h] [ebp-4h]

  if ( (_S3 & 1) == 0 )
  {
    perfCounter_11.name = "PvsProcessor::doCulling";
    _S3 |= 1u;
    perfCounter_11.group = Render;
    perfCounter_11.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PvsProcessor::doCulling" | 0xFF000000;
  }
  if ( this->meshCount > 0 )
  {
    v2 = this->inPvs;
    v3 = -139284 - (_DWORD)this;
    v4 = this->bounds;
    v5 = this->flags;
    v7 = -139284 - (_DWORD)this;
    do
    {
      if ( *v2 && (*(_BYTE *)v5 & 0x10) == 0 )
      {
        *v2 = BoundingFrustum::intersect(&this->rc->camera->frustum, v4);
        v3 = v7;
      }
      ++v2;
      ++v5;
      ++v4;
      v6 = (int)&v2[v3] < this->meshCount;
      v3 = v7;
    }
    while ( v6 );
  }
}
void PvsProcessor::doRenderCalls(PvsProcessor *this)
{
  unsigned int v2; // ecx
  std::array<PvsProcessor::DrawCall,4096> *v3; // ebx
  _DWORD *v4; // ebp
  std::vector<RenderTarget *> *v5; // ecx
  unsigned int i; // esi
  CubeMap *v7; // eax
  std::array<PvsProcessor::DrawCall,4096> *v8; // ebp
  Material *v9; // esi
  _DWORD *v10; // ecx
  Material *v11; // esi
  CBuffer *v12; // edi
  CBuffer *k; // esi
  PvsProcessor *v14; // [esp+10h] [ebp-10h]
  std::array<PvsProcessor::DrawCall,4096> *v15; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]
  SystemCBuffers *v17; // [esp+1Ch] [ebp-4h]

  v2 = _S6;
  v14 = this;
  if ( (_S6 & 1) == 0 )
  {
    perfCounter_14.name = "PvsProcessor::doRenderCalls";
    v2 = _S6 | 1;
    perfCounter_14.group = Render;
    _S6 |= 1u;
    perfCounter_14.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PvsProcessor::doRenderCalls" | 0xFF000000;
  }
  if ( (v2 & 2) == 0 )
  {
    perfCounter_15.name = "PvsProcessor::doRenderCalls (sort)";
    perfCounter_15.group = Render;
    _S6 = v2 | 2;
    perfCounter_15.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PvsProcessor::doRenderCalls (sort)" | 0xFF000000;
  }
  v3 = &this->drawCalls;
  std::_Sort<PvsProcessor::DrawCall *,int,bool (__cdecl *)(PvsProcessor::DrawCall const &,PvsProcessor::DrawCall const &)>(
    this->drawCalls._Elems,
    &this->drawCalls._Elems[this->drawCallCount],
    100 * this->drawCallCount / 100,
    PvsProcessor::compareDrawCalls);
  v17 = &this->rc->graphics->sysBuffers;
  v4 = &v17->cbCamera.size;
  CBuffer::touch(&v17->cbCamera);
  CBuffer::commit(&v17->cbCamera);
  CBuffer::touch(&v17->cbLighting);
  CBuffer::commit(&v17->cbLighting);
  CBuffer::touch(&v17->cbShadowMap);
  CBuffer::commit(&v17->cbShadowMap);
  v5 = this->shadowMaps;
  if ( v5 )
  {
    for ( i = 0; i < v5->_Mylast - v5->_Myfirst; ++i )
    {
      if ( v5->_Mylast - v5->_Myfirst <= i )
      {
        std::_Xout_of_range("invalid vector<T> subscript");
        goto $LN193_0;
      }
      kglSetTextureRT(i + 6, v5->_Myfirst[i]->kidDepth);
      v5 = this->shadowMaps;
    }
  }
  v7 = this->cubeMap;
  if ( v7 )
    kglSetTextureCubeMap(v7->kid, 0xAu);
  v8 = 0;
  v15 = 0;
  for ( j = 0; j < this->drawCallCount; v3 = (std::array<PvsProcessor::DrawCall,4096> *)((char *)v3 + 100) )
  {
    if ( !v8 || v3->_Elems[0].shader != v8->_Elems[0].shader )
      kglSetShader(v3->_Elems[0].shader->kid);
    if ( !v8 || v3->_Elems[0].material != v8->_Elems[0].material )
    {
      v9 = v3->_Elems[0].material;
      this = (PvsProcessor *)v9->resources._Mylast;
      i = (unsigned int)v9->resources._Myfirst;
      if ( (PvsProcessor *)i != this )
      {
        v4 = &v14->rc;
        do
        {
          v10 = (_DWORD *)v4[2];
          if ( (!v10 || *(int *)i < 6 || *(_DWORD *)i >= (unsigned int)(((v10[1] - *v10) >> 2) + 6))
            && (!v4[3] || *(_DWORD *)i != 10) )
          {
            if ( *(_DWORD *)(i + 4) )
              kglSetTexture(*(_DWORD *)i, *(void **)(i + 4));
            else
$LN193_0:
              kglSetTexture(*(_DWORD *)i, 0);
          }
          i += 56;
        }
        while ( (PvsProcessor *)i != this );
        v8 = v15;
      }
      v11 = v3->_Elems[0].material;
      v12 = v11->cBuffers._Mylast;
      for ( k = v11->cBuffers._Myfirst; k != v12; ++k )
        CBuffer::commit(k);
      this = v14;
    }
    if ( !v8 || v3->_Elems[0].blendMode != v8->_Elems[0].blendMode )
      kglSetBlendState(v3->_Elems[0].blendMode);
    if ( !v8 || v3->_Elems[0].cullMode != v8->_Elems[0].cullMode )
      kglSetCullState(v3->_Elems[0].cullMode);
    if ( !v8 || v3->_Elems[0].depthMode != v8->_Elems[0].depthMode )
      kglSetDepthState(v3->_Elems[0].depthMode);
    if ( !v8 || v3->_Elems[0].vb != v8->_Elems[0].vb )
      kglSetVertexBuffer(v3->_Elems[0].vb->kid);
    if ( !v8 || v3->_Elems[0].ib != v8->_Elems[0].ib )
      kglSetIndexBuffer(v3->_Elems[0].ib->kid);
    if ( v3->_Elems[0].hasMatrix )
    {
      CBuffer::set(&v17->cbPerObject, &v3->_Elems[0].worldMatrix.M11, 0, 64);
      CBuffer::commit(&v17->cbPerObject);
    }
    kglDrawIndexed(v3->_Elems[0].indexCount, 0, 0);
    v8 = v3;
    v15 = v3;
    ++j;
  }
}
void PvsProcessor::doRenderClassic(PvsProcessor *this)
{
  int v2; // ebx
  Mesh **v3; // ebp
  Mesh *v4; // esi
  Node *v5; // eax
  IVertexBuffer *v6; // eax
  IVertexBuffer *v7; // eax

  if ( (_S4 & 1) == 0 )
  {
    perfCounter_12.name = "PvsProcessor::doRenderClassic";
    _S4 |= 1u;
    perfCounter_12.group = Render;
    perfCounter_12.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PvsProcessor::doRenderClassic" | 0xFF000000;
  }
  v2 = 0;
  if ( this->meshCount > 0 )
  {
    v3 = this->meshPtrs;
    do
    {
      if ( this->inPvs[v2] )
      {
        v4 = *v3;
        if ( (*v3)->material._Ptr )
          this->rc->materialFilter->apply(this->rc->materialFilter, &v4->material, this->rc);
        v5 = v4->parent;
        if ( v5 )
          GraphicsManager::setWorldMatrix(this->rc->graphics, &v5->matrixWS);
        v6 = (IVertexBuffer *)v4->vb;
        if ( v6 )
          v7 = v6 + 1;
        else
          v7 = 0;
        GraphicsManager::setVB(this->rc->graphics, v7);
        GraphicsManager::setIB(this->rc->graphics, v4->ib);
        GraphicsManager::commitShaderChanges(this->rc->graphics);
        GraphicsManager::drawPrimitive(this->rc->graphics, v4->compiledIndicesCount, 0, 0, v4->compiledVerticesCount);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->meshCount );
  }
}
void PvsProcessor::end(PvsProcessor *this)
{
  PvsRenderMode v2; // eax

  if ( (_S13 & 1) == 0 )
  {
    perfCounter_16.name = "PvsProcessor::end";
    _S13 |= 1u;
    perfCounter_16.group = Render;
    perfCounter_16.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PvsProcessor::end" | 0xFF000000;
  }
  PvsProcessor::doExclusion(this);
  PvsProcessor::doDistanceAndLod(this);
  PvsProcessor::doFrustumCulling(this);
  v2 = this->renderMode;
  switch ( v2 )
  {
    case Default:
      goto LABEL_7;
    case Skinned:
      PvsProcessor::prepareDrawCallsDefault(this);
      PvsProcessor::doRenderCalls(this);
      return;
    case Particle:
LABEL_7:
      PvsProcessor::doRenderClassic(this);
      break;
  }
}
void PvsProcessor::prepareDrawCallsDefault(PvsProcessor *this)
{
  int v2; // ebx
  Mesh **v3; // ebp
  int v4; // ecx
  Mesh *v5; // edi
  int v6; // esi
  float *v7; // ecx

  if ( (_S5 & 1) == 0 )
  {
    perfCounter_13.name = "PvsProcessor::prepareDrawCallsDefault";
    _S5 |= 1u;
    perfCounter_13.group = Render;
    perfCounter_13.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PvsProcessor::prepareDrawCallsDefault" | 0xFF000000;
  }
  v2 = 0;
  this->drawCallCount = 0;
  if ( this->meshCount > 0 )
  {
    v3 = this->meshPtrs;
    do
    {
      if ( this->inPvs[v2] )
      {
        v4 = this->drawCallCount;
        v5 = *v3;
        v6 = v4;
        this->drawCallCount = v4 + 1;
        this->drawCalls._Elems[v6].shader = v5->material._Ptr->shader;
        this->drawCalls._Elems[v6].material = v5->material._Ptr;
        this->drawCalls._Elems[v6].blendMode = v5->material._Ptr->blendMode;
        if ( !this->rc->graphics->state.overrideNoMS || v5->material._Ptr->cullMode )
          this->drawCalls._Elems[v6].cullMode = v5->material._Ptr->cullMode;
        else
          this->drawCalls._Elems[v6].cullMode = eCullFrontNoMS;
        this->drawCalls._Elems[v6].depthMode = v5->material._Ptr->depthMode;
        this->drawCalls._Elems[v6].vb = v5->vb;
        this->drawCalls._Elems[v6].ib = v5->ib;
        this->drawCalls._Elems[v6].indexCount = v5->compiledIndicesCount;
        if ( v5->parent )
        {
          this->drawCalls._Elems[v6].hasMatrix = 1;
          v7 = (float *)v5->parent;
          this->drawCalls._Elems[v6].worldMatrix.M11 = v7[17];
          this->drawCalls._Elems[v6].worldMatrix.M12 = v7[21];
          this->drawCalls._Elems[v6].worldMatrix.M13 = v7[25];
          this->drawCalls._Elems[v6].worldMatrix.M14 = v7[29];
          this->drawCalls._Elems[v6].worldMatrix.M21 = v7[18];
          this->drawCalls._Elems[v6].worldMatrix.M22 = v7[22];
          this->drawCalls._Elems[v6].worldMatrix.M23 = v7[26];
          this->drawCalls._Elems[v6].worldMatrix.M24 = v7[30];
          this->drawCalls._Elems[v6].worldMatrix.M31 = v7[19];
          this->drawCalls._Elems[v6].worldMatrix.M32 = v7[23];
          this->drawCalls._Elems[v6].worldMatrix.M33 = v7[27];
          this->drawCalls._Elems[v6].worldMatrix.M34 = v7[31];
          this->drawCalls._Elems[v6].worldMatrix.M41 = v7[20];
          this->drawCalls._Elems[v6].worldMatrix.M42 = v7[24];
          this->drawCalls._Elems[v6].worldMatrix.M43 = v7[28];
          this->drawCalls._Elems[v6].worldMatrix.M44 = v7[32];
        }
        else
        {
          this->drawCalls._Elems[v6].hasMatrix = 0;
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->meshCount );
  }
}
