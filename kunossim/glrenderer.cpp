#include "glrenderer.h"
void GLRenderer::GLRenderer(GLRenderer *this, GraphicsManager *r, unsigned int maxVertices, bool withFullScreenQuad)
{
  std::vector<SplineIndexBound> *v5; // esi
  unsigned int v6; // edi
  MeshVertex *v7; // eax
  signed int v8; // edx
  float *v9; // ecx
  unsigned int v10; // ecx
  int v11; // ebx
  SplineIndexBound *v12; // ecx
  int v13; // eax
  SplineIndexBound *v14; // edx
  int v15; // edi
  int v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // edx
  SplineIndexBound *v19; // ecx
  SplineIndexBound *v20; // edx
  SplineIndexBound *v21; // edx
  int v22; // ecx
  unsigned int v23; // edx
  unsigned int v24; // edx
  SplineIndexBound *v25; // eax
  int v26; // ecx
  GLRenderer *v27; // ebx
  void *v28; // eax
  std::pair<int,void *> _Count; // [esp+10h] [ebp-24h] BYREF
  GLRenderer *v30; // [esp+18h] [ebp-1Ch]
  int v31; // [esp+1Ch] [ebp-18h] BYREF
  int v32; // [esp+20h] [ebp-14h]
  int v33; // [esp+30h] [ebp-4h]

  v30 = this;
  v5 = (std::vector<SplineIndexBound> *)&this->buffers;
  this->__vftable = (GLRenderer_vtbl *)&GLRenderer::`vftable';
  this->buffers._Myfirst = 0;
  this->buffers._Mylast = 0;
  this->buffers._Myend = 0;
  this->graphics = r;
  this->color.x = 0.0;
  this->color.y = 0.0;
  this->color.z = 0.0;
  this->color.w = 0.0;
  this->texCoord.x = 0.0;
  this->texCoord.y = 0.0;
  this->tempCounter = 0;
  this->tempVertices[0].pos.x = 0.0;
  this->tempVertices[0].pos.y = 0.0;
  this->tempVertices[0].pos.z = 0.0;
  this->tempVertices[0].normal.x = 0.0;
  this->tempVertices[0].normal.y = 0.0;
  this->tempVertices[0].normal.z = 0.0;
  this->tempVertices[0].texCoord.x = 0.0;
  v6 = maxVertices;
  this->tempVertices[0].texCoord.y = 0.0;
  this->tempVertices[0].tangent.x = 0.0;
  this->tempVertices[0].tangent.y = 0.0;
  this->tempVertices[0].tangent.z = 0.0;
  this->tempVertices[1].pos.x = 0.0;
  this->tempVertices[1].pos.y = 0.0;
  this->tempVertices[1].pos.z = 0.0;
  this->tempVertices[1].normal.x = 0.0;
  this->tempVertices[1].normal.y = 0.0;
  this->tempVertices[1].normal.z = 0.0;
  this->tempVertices[1].texCoord.x = 0.0;
  this->tempVertices[1].texCoord.y = 0.0;
  this->tempVertices[1].tangent.x = 0.0;
  this->tempVertices[1].tangent.y = 0.0;
  this->tempVertices[1].tangent.z = 0.0;
  this->tempVertices[2].pos.x = 0.0;
  this->tempVertices[2].pos.y = 0.0;
  this->tempVertices[2].pos.z = 0.0;
  this->tempVertices[2].normal.x = 0.0;
  this->tempVertices[2].normal.y = 0.0;
  this->tempVertices[2].normal.z = 0.0;
  this->tempVertices[2].texCoord.x = 0.0;
  this->tempVertices[2].texCoord.y = 0.0;
  this->tempVertices[2].tangent.x = 0.0;
  this->tempVertices[2].tangent.y = 0.0;
  this->tempVertices[2].tangent.z = 0.0;
  v33 = 0;
  this->tempBuffer = 0;
  this->maxVertices = maxVertices;
  this->currentIndex = 0;
  v7 = (MeshVertex *)operator new[](44 * maxVertices);
  if ( v7 )
  {
    v8 = maxVertices - 1;
    if ( (int)(maxVertices - 1) >= 0 )
    {
      v9 = &v7->normal.z;
      do
      {
        --v8;
        *(v9 - 5) = 0.0;
        *(v9 - 4) = 0.0;
        v9 += 11;
        *(v9 - 14) = 0.0;
        *(v9 - 13) = 0.0;
        *(v9 - 12) = 0.0;
        *(v9 - 11) = 0.0;
        *(v9 - 10) = 0.0;
        *(v9 - 9) = 0.0;
        *(v9 - 8) = 0.0;
        *(v9 - 7) = 0.0;
        *(v9 - 6) = 0.0;
      }
      while ( v8 >= 0 );
    }
  }
  else
  {
    v7 = 0;
  }
  this->tempBuffer = v7;
  v10 = 6;
  while ( v10 <= v6 || v5->_Myfirst == v5->_Mylast )
  {
    v11 = v6;
    if ( v10 < v6 )
      v11 = v10;
    v31 = v11;
    kglCreateDynamicVertexBuffer(v6, (int)v5, 44 * v11, 0x2Cu, 0);
    v12 = v5->_Mylast;
    v32 = v13;
    if ( &v31 >= (int *)v12 || v5->_Myfirst > (SplineIndexBound *)&v31 )
    {
      v21 = v5->_Myend;
      if ( v12 == v21 && !(v21 - v12) )
      {
        v22 = v12 - v5->_Myfirst;
        if ( v22 == 0x1FFFFFFF )
LABEL_43:
          std::_Xlength_error("vector<T> too long");
        v23 = v21 - v5->_Myfirst;
        _Count.first = v22 + 1;
        if ( 0x1FFFFFFF - (v23 >> 1) >= v23 )
          v24 = (v23 >> 1) + v23;
        else
          v24 = 0;
        if ( v24 < _Count.first )
          v24 = _Count.first;
        std::vector<ReplayLap>::_Reallocate(v5, v24);
      }
      v25 = v5->_Mylast;
      if ( v25 )
      {
        v26 = v32;
        v25->minIndex = v11;
        v25->maxIndex = v26;
      }
      ++v5->_Mylast;
      v10 = 2 * v11;
    }
    else
    {
      v14 = v5->_Myend;
      v15 = ((char *)&v31 - (char *)v5->_Myfirst) >> 3;
      if ( v12 == v14 && !(v14 - v12) )
      {
        v16 = v12 - v5->_Myfirst;
        if ( v16 == 0x1FFFFFFF )
          goto LABEL_43;
        v17 = v14 - v5->_Myfirst;
        _Count.first = v16 + 1;
        if ( 0x1FFFFFFF - (v17 >> 1) >= v17 )
          v18 = (v17 >> 1) + v17;
        else
          v18 = 0;
        if ( v18 < _Count.first )
          v18 = _Count.first;
        std::vector<ReplayLap>::_Reallocate(v5, v18);
      }
      v19 = v5->_Mylast;
      v20 = v5->_Myfirst;
      if ( v19 )
      {
        v19->minIndex = v20[v15].minIndex;
        v19->maxIndex = v20[v15].maxIndex;
      }
      v6 = maxVertices;
      v10 = 2 * v11;
      ++v5->_Mylast;
    }
  }
  v27 = v30;
  if ( v30->buffers._Mylast[-1].first < v6 )
  {
    _Count.first = v6;
    kglCreateDynamicVertexBuffer(v6, (int)v5, 44 * v6, 0x2Cu, 0);
    _Count.second = v28;
    std::vector<std::pair<int,void *>>::push_back((std::vector<std::pair<int,void *>> *)v5, &_Count);
  }
  v27->primitive = eTriangles;
  v27->useTexture = 0;
  v27->shader = 0;
  v27->glShader = 0;
  v27->glShaderTex = 0;
  if ( withFullScreenQuad )
  {
    GLRenderer::initFullScreenQuad(v27, (int)v5);
  }
  else
  {
    v27->fullQuadIB = 0;
    v27->fullQuadVB = 0;
  }
}
void GLRenderer::~GLRenderer(GLRenderer *this)
{
  std::pair<int,void *> *v2; // edi
  std::pair<int,void *> *i; // esi
  IndexBuffer *v4; // ecx
  VertexBuffer<MeshVertex> *v5; // ecx

  this->__vftable = (GLRenderer_vtbl *)&GLRenderer::`vftable';
  v2 = this->buffers._Mylast;
  for ( i = this->buffers._Myfirst; i != v2; ++i )
    kglDestroyVertexBuffer(i->second);
  if ( this->fullQuadVB )
  {
    v4 = this->fullQuadIB;
    if ( v4 )
      ((void (*)(IndexBuffer *, int))v4->~IndexBuffer)(v4, 1);
    v5 = this->fullQuadVB;
    if ( v5 )
      ((void (*)(VertexBuffer<MeshVertex> *, int))v5->~VertexBuffer<MeshVertex>)(v5, 1);
  }
  operator delete[](this->tempBuffer);
  if ( this->buffers._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->buffers);
    operator delete(this->buffers._Myfirst);
    this->buffers._Myfirst = 0;
    this->buffers._Mylast = 0;
    this->buffers._Myend = 0;
  }
}
GLRenderer *GLRenderer::`vector deleting destructor'(GLRenderer *this, unsigned int a2)
{
  GLRenderer::~GLRenderer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void GLRenderer::begin(GLRenderer *this, eGLPrimitiveType type, Shader *ishader)
{
  this->primitive = type;
  this->currentIndex = 0;
  this->tempCounter = 0;
  this->useTexture = 0;
  this->shader = ishader;
}
void GLRenderer::color3f(GLRenderer *this, float r, float g, float b)
{
  this->color.x = r;
  this->color.y = g;
  this->color.z = b;
  this->color.w = 1.0;
}
void GLRenderer::color4f(GLRenderer *this, const vec4f *v)
{
  this->color = (vec4f)_mm_loadu_si128((const __m128i *)v);
}
void GLRenderer::color4f(GLRenderer *this, float r, float g, float b, float a)
{
  this->color.x = r;
  this->color.y = g;
  this->color.z = b;
  this->color.w = a;
}
void GLRenderer::end(GLRenderer *this)
{
  int v2; // edx
  std::pair<int,void *> *v3; // eax
  std::pair<int,void *> *v4; // ecx
  std::pair<int,void *> *v5; // edi
  std::pair<int,void *> *i; // esi
  GraphicsManager *v7; // ecx
  Shader *v8; // eax
  bool v9; // cf
  GraphicsManager *v10; // ecx
  Shader *v11; // eax
  bool v12; // cc
  void *vb; // [esp+14h] [ebp-44h]
  std::wstring v14; // [esp+18h] [ebp-40h] BYREF
  std::wstring name; // [esp+30h] [ebp-28h] BYREF
  int v16; // [esp+54h] [ebp-4h]

  v2 = this->currentIndex;
  if ( v2 > this->maxVertices )
    this->maxVertices = v2;
  v3 = this->buffers._Myfirst;
  v4 = this->buffers._Mylast;
  vb = 0;
  if ( v3 == v4 )
    goto LABEL_8;
  while ( v2 > v3->first )
  {
    if ( ++v3 == v4 )
      goto LABEL_8;
  }
  vb = v3->second;
  if ( !vb )
  {
LABEL_8:
    _printf("ERROR: Could not find suitable buffer for %d vertices in %d buffers\n", v2, v4 - this->buffers._Myfirst);
    v5 = this->buffers._Mylast;
    for ( i = this->buffers._Myfirst; i != v5; ++i )
      _printf("BUFFER: %d v\n", i->first);
  }
  kglVertexBufferMap(vb, this->tempBuffer, 44 * this->currentIndex);
  kglSetVertexBuffer(vb);
  if ( this->shader )
  {
    GraphicsManager::setShader(this->graphics, this->shader);
  }
  else if ( this->useTexture )
  {
    if ( !this->glShaderTex )
    {
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      std::wstring::assign(&name, L"GLTextured", 0xAu);
      v7 = this->graphics;
      v16 = 0;
      v8 = GraphicsManager::getShader(v7, (unsigned int)this, &name);
      v9 = name._Myres < 8;
      this->glShaderTex = v8;
      v16 = -1;
      if ( !v9 )
        operator delete(name._Bx._Ptr);
    }
    GraphicsManager::setShader(this->graphics, this->glShaderTex);
  }
  else
  {
    if ( !this->glShader )
    {
      v14._Myres = 7;
      v14._Mysize = 0;
      v14._Bx._Buf[0] = 0;
      std::wstring::assign(&v14, L"GL", 2u);
      v10 = this->graphics;
      v16 = 1;
      v11 = GraphicsManager::getShader(v10, (unsigned int)this, &v14);
      v9 = v14._Myres < 8;
      this->glShader = v11;
      v16 = -1;
      if ( !v9 )
        operator delete(v14._Bx._Ptr);
      v14._Myres = 7;
      v14._Mysize = 0;
      v14._Bx._Buf[0] = 0;
    }
    GraphicsManager::setShader(this->graphics, this->glShader);
  }
  GraphicsManager::commitShaderChanges(this->graphics);
  switch ( this->primitive )
  {
    case eLines:
      if ( this->currentIndex >= 1 )
      {
        kglSetPrimitiveType(1u);
        goto LABEL_31;
      }
      return;
    case eLinesStrip:
      if ( this->currentIndex >= 1 )
      {
        kglSetPrimitiveType(2u);
        goto LABEL_31;
      }
      return;
    case eTriangles:
      v12 = this->currentIndex < 3;
      goto LABEL_29;
    case eQuads:
      v12 = this->currentIndex < 4;
LABEL_29:
      if ( v12 )
        return;
      kglSetPrimitiveType(0);
LABEL_31:
      kglDraw(this->currentIndex, 0);
      kglSetPrimitiveType(0);
      return;
    default:
      goto LABEL_31;
  }
}
void GLRenderer::fullScreenQuad(GLRenderer *this, Shader *ishader)
{
  GraphicsManager *v3; // ecx
  VertexBuffer<MeshVertex> *v4; // eax
  IVertexBuffer *v5; // eax

  kglSetPrimitiveType(0);
  v3 = this->graphics;
  if ( ishader )
  {
    GraphicsManager::setShader(v3, ishader);
  }
  else if ( this->useTexture )
  {
    GraphicsManager::setShader(v3, this->glShaderTex);
  }
  else
  {
    GraphicsManager::setShader(v3, this->glShader);
  }
  v4 = this->fullQuadVB;
  if ( v4 )
    v5 = &v4->IVertexBuffer;
  else
    v5 = 0;
  GraphicsManager::setVB(this->graphics, v5);
  GraphicsManager::setIB(this->graphics, this->fullQuadIB);
  GraphicsManager::commitShaderChanges(this->graphics);
  kglDrawIndexed(6u, 0, 0);
}
void __usercall GLRenderer::initFullScreenQuad(GLRenderer *this@<ecx>, int a2@<esi>)
{
  const MeshVertex *v3; // eax
  const MeshVertex *v4; // eax
  const MeshVertex *v5; // eax
  const MeshVertex *v6; // eax
  VertexBuffer<MeshVertex> *v7; // eax
  VertexBuffer<MeshVertex> *v8; // edi
  void *v9; // eax
  IndexBuffer *v10; // eax
  IndexBuffer *v11; // eax
  bool v12; // zf
  vec2f uv; // [esp+Ch] [ebp-70h] BYREF
  std::vector<unsigned short> indices; // [esp+14h] [ebp-68h] BYREF
  std::vector<MeshVertex> vertices; // [esp+20h] [ebp-5Ch] BYREF
  vec3f inor; // [esp+2Ch] [ebp-50h] BYREF
  vec3f ipos; // [esp+38h] [ebp-44h] BYREF
  MeshVertex v18; // [esp+44h] [ebp-38h] BYREF
  int v19; // [esp+78h] [ebp-4h]

  vertices._Myfirst = 0;
  vertices._Mylast = 0;
  vertices._Myend = 0;
  v19 = 0;
  uv.x = 0.0;
  uv.y = 1.0;
  inor.x = 0.0;
  inor.y = 1.0;
  inor.z = 0.0;
  ipos.x = -1.0;
  ipos.y = -1.0;
  ipos.z = 0.0;
  MeshVertex::MeshVertex(&v18, &ipos, &inor, &uv);
  std::vector<MeshVertex>::push_back(&vertices, v3);
  uv.x = 1.0;
  uv.y = 1.0;
  ipos.x = 0.0;
  ipos.y = 1.0;
  ipos.z = 0.0;
  inor.x = 1.0;
  inor.y = -1.0;
  inor.z = 0.0;
  MeshVertex::MeshVertex(&v18, &inor, &ipos, &uv);
  std::vector<MeshVertex>::push_back(&vertices, v4);
  uv.x = 1.0;
  uv.y = 0.0;
  ipos.x = 0.0;
  ipos.y = 1.0;
  ipos.z = 0.0;
  inor.x = 1.0;
  inor.y = 1.0;
  inor.z = 0.0;
  MeshVertex::MeshVertex(&v18, &inor, &ipos, &uv);
  std::vector<MeshVertex>::push_back(&vertices, v5);
  uv.x = 0.0;
  uv.y = 0.0;
  ipos.x = 0.0;
  ipos.y = 1.0;
  ipos.z = 0.0;
  inor.x = -1.0;
  inor.y = 1.0;
  inor.z = 0.0;
  MeshVertex::MeshVertex(&v18, &inor, &ipos, &uv);
  std::vector<MeshVertex>::push_back(&vertices, v6);
  v7 = (VertexBuffer<MeshVertex> *)operator new(8);
  v8 = v7;
  if ( v7 )
  {
    v7->kid = 0;
    v7->__vftable = (VertexBuffer<MeshVertex>_vtbl *)&VertexBuffer<MeshVertex>::`vftable';
    kglCreateVertexBuffer((int)v7, a2, 44 * (vertices._Mylast - vertices._Myfirst), 0x2Cu, vertices._Myfirst);
    v8->kid = v9;
  }
  else
  {
    v8 = 0;
  }
  this->fullQuadVB = v8;
  indices._Myfirst = 0;
  indices._Mylast = 0;
  indices._Myend = 0;
  LOBYTE(v19) = 1;
  uv.x = 0.0;
  std::vector<unsigned short>::push_back(&indices, (const unsigned __int16 *)&uv);
  LODWORD(uv.x) = 1;
  std::vector<unsigned short>::push_back(&indices, (const unsigned __int16 *)&uv);
  LODWORD(uv.x) = 2;
  std::vector<unsigned short>::push_back(&indices, (const unsigned __int16 *)&uv);
  uv.x = 0.0;
  std::vector<unsigned short>::push_back(&indices, (const unsigned __int16 *)&uv);
  LODWORD(uv.x) = 2;
  std::vector<unsigned short>::push_back(&indices, (const unsigned __int16 *)&uv);
  LODWORD(uv.x) = 3;
  std::vector<unsigned short>::push_back(&indices, (const unsigned __int16 *)&uv);
  v10 = (IndexBuffer *)operator new(8);
  LODWORD(uv.x) = v10;
  LOBYTE(v19) = 2;
  if ( v10 )
    IndexBuffer::IndexBuffer(v10, &indices);
  else
    v11 = 0;
  v12 = indices._Myfirst == 0;
  this->fullQuadIB = v11;
  LOBYTE(v19) = 0;
  if ( !v12 )
  {
    std::_Container_base0::_Orphan_all(&indices);
    operator delete(indices._Myfirst);
    indices._Myfirst = 0;
    indices._Mylast = 0;
    indices._Myend = 0;
  }
  v19 = -1;
  if ( vertices._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&vertices);
    operator delete(vertices._Myfirst);
  }
}
void GLRenderer::quad(GLRenderer *this, float x, float y, float width, float height, bool textured, Shader *shader)
{
  float xa; // [esp+18h] [ebp+4h]

  this->primitive = eQuads;
  this->currentIndex = 0;
  this->tempCounter = 0;
  this->useTexture = 0;
  this->shader = shader;
  if ( textured )
  {
    this->texCoord.x = 0.0;
    this->texCoord.y = 0.0;
    this->useTexture = 1;
  }
  GLRenderer::vertex3f(this, x, y, 0.0);
  if ( textured )
  {
    this->texCoord.x = 0.0;
    this->texCoord.y = 1.0;
    this->useTexture = 1;
  }
  GLRenderer::vertex3f(this, x, y + height, 0.0);
  if ( textured )
  {
    this->texCoord.x = 1.0;
    this->texCoord.y = 1.0;
    this->useTexture = 1;
  }
  xa = x + width;
  GLRenderer::vertex3f(this, xa, y + height, 0.0);
  if ( textured )
  {
    this->texCoord.x = 1.0;
    this->texCoord.y = 0.0;
    this->useTexture = 1;
  }
  GLRenderer::vertex3f(this, xa, y, 0.0);
  GLRenderer::end(this);
}
void GLRenderer::quadCentred(GLRenderer *this, float x, float y, float width, float height, bool textured, Shader *shader)
{
  float v7; // xmm2_4
  float v8; // xmm1_4
  float xa; // [esp+18h] [ebp+4h]
  float ya; // [esp+1Ch] [ebp+8h]
  float widtha; // [esp+20h] [ebp+Ch]
  float heighta; // [esp+24h] [ebp+10h]
  float shadera; // [esp+2Ch] [ebp+18h]

  v7 = width * 0.5;
  v8 = height * 0.5;
  widtha = width * 0.5;
  heighta = height * 0.5;
  this->primitive = eQuads;
  this->currentIndex = 0;
  this->tempCounter = 0;
  this->useTexture = 0;
  this->shader = shader;
  if ( textured )
  {
    this->texCoord.x = 0.0;
    this->texCoord.y = 0.0;
    this->useTexture = 1;
  }
  shadera = y - v8;
  GLRenderer::vertex3f(this, x - v7, y - v8, 0.0);
  if ( textured )
  {
    this->texCoord.x = 0.0;
    this->texCoord.y = 1.0;
    this->useTexture = 1;
  }
  ya = y + heighta;
  GLRenderer::vertex3f(this, x - v7, ya, 0.0);
  if ( textured )
  {
    this->texCoord.x = 1.0;
    this->texCoord.y = 1.0;
    this->useTexture = 1;
  }
  xa = x + widtha;
  GLRenderer::vertex3f(this, xa, ya, 0.0);
  if ( textured )
  {
    this->texCoord.x = 1.0;
    this->texCoord.y = 0.0;
    this->useTexture = 1;
  }
  GLRenderer::vertex3f(this, xa, shadera, 0.0);
  GLRenderer::end(this);
}
void __userpurge GLRenderer::quadCentredRotated(GLRenderer *this@<ecx>, int a2@<esi>, float x, float y, float width, float height, float rotationRAD, bool textured, Shader *shader)
{
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __int128 v12; // xmm3
  __m128 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm2
  __int128 v16; // xmm3
  __m128 v17; // xmm0
  GraphicsManager *v18; // ecx
  int v20; // [esp+10h] [ebp-18Ch]
  float v21; // [esp+14h] [ebp-188h]
  float v22; // [esp+18h] [ebp-184h]
  unsigned int v23; // [esp+1Ch] [ebp-180h] BYREF
  __m128 v24[3]; // [esp+20h] [ebp-17Ch] BYREF
  __int128 v25; // [esp+50h] [ebp-14Ch]
  mat44f v26; // [esp+60h] [ebp-13Ch] BYREF
  __m128 v27; // [esp+A0h] [ebp-FCh]
  __m128 v28; // [esp+B0h] [ebp-ECh]
  __m128 v29; // [esp+C0h] [ebp-DCh]
  __int128 v30; // [esp+D0h] [ebp-CCh]
  mat44f matrix_4; // [esp+E0h] [ebp-BCh] BYREF
  mat44f result_4; // [esp+120h] [ebp-7Ch] BYREF
  mat44f var3C; // [esp+160h] [ebp-3Ch] BYREF
  float widtha; // [esp+1ACh] [ebp+10h]
  float heighta; // [esp+1B0h] [ebp+14h]

  widtha = width * 0.5;
  heighta = height * 0.5;
  GraphicsManager::getWorldMatrix(this->graphics, (mat44f *)&matrix_4.M44);
  mat44f::createIdentity((mat44f *)&v23);
  v23 = __libm_sse2_cosf(a2, v20).m128_u32[0];
  v21 = __libm_sse2_sinf().m128_f32[0];
  v22 = 1.0 - *(float *)&v23;
  mat44f::mat44f(&v26);
  v26.M44 = 1.0;
  v26.M33 = v22 + *(float *)&v23;
  v26.M11 = (float)(v22 * 0.0) + *(float *)&v23;
  v26.M22 = v26.M11;
  v26.M12 = v21 + (float)(v22 * 0.0);
  v26.M21 = (float)(v22 * 0.0) - v21;
  v26.M13 = (float)(v22 * 0.0) - (float)(v21 * 0.0);
  v26.M31 = (float)(v21 * 0.0) + (float)(v22 * 0.0);
  v26.M23 = v26.M31;
  *(float *)&v25 = x;
  v26.M32 = v26.M13;
  *(_QWORD *)((char *)&v25 + 4) = LODWORD(y);
  mat44f::mat44f(&var3C);
  v10 = *(__m128 *)&v26.M21;
  v11 = *(__m128 *)&v26.M31;
  v12 = *(_OWORD *)&v26.M41;
  v13 = DirectX::XMMatrixMultiply(v24, *(__m128 *)&v26.M11);
  v30 = v12;
  v27 = v11;
  v29 = v10;
  v28 = v13;
  mat44f::mat44f(&matrix_4);
  v14 = *(_OWORD *)&result_4.M21;
  v15 = *(_OWORD *)&result_4.M31;
  v16 = *(_OWORD *)&result_4.M41;
  v24[0] = v28;
  v24[1] = v29;
  v24[2] = v27;
  v25 = v30;
  v17 = DirectX::XMMatrixMultiply(v24, *(__m128 *)&result_4.M11);
  v18 = this->graphics;
  *(__m128 *)&matrix_4.M11 = v17;
  *(_OWORD *)&matrix_4.M21 = v14;
  *(_OWORD *)&matrix_4.M31 = v15;
  *(_OWORD *)&matrix_4.M41 = v16;
  GraphicsManager::setWorldMatrix(v18, &matrix_4);
  this->primitive = eQuads;
  this->currentIndex = 0;
  this->tempCounter = 0;
  this->useTexture = 0;
  this->shader = shader;
  if ( textured )
  {
    this->texCoord.x = 0.0;
    this->texCoord.y = 0.0;
    this->useTexture = 1;
  }
  GLRenderer::vertex3f(this, COERCE_FLOAT(LODWORD(widtha) ^ _xmm), COERCE_FLOAT(LODWORD(heighta) ^ _xmm), 0.0);
  if ( textured )
  {
    this->texCoord.x = 0.0;
    this->texCoord.y = 1.0;
    this->useTexture = 1;
  }
  GLRenderer::vertex3f(this, COERCE_FLOAT(LODWORD(widtha) ^ _xmm), heighta, 0.0);
  if ( textured )
  {
    this->texCoord.x = 1.0;
    this->texCoord.y = 1.0;
    this->useTexture = 1;
  }
  GLRenderer::vertex3f(this, widtha, heighta, 0.0);
  if ( textured )
  {
    this->texCoord.x = 1.0;
    this->texCoord.y = 0.0;
    this->useTexture = 1;
  }
  GLRenderer::vertex3f(this, widtha, COERCE_FLOAT(LODWORD(heighta) ^ _xmm), 0.0);
  GLRenderer::end(this);
  GraphicsManager::setWorldMatrix(this->graphics, &result_4);
}
void GLRenderer::spline(GLRenderer *this, const Spline *spline)
{
  unsigned int v3; // edi
  unsigned int v4; // ebp
  unsigned int v5; // esi
  int v6; // edx
  std::pair<int,void *> *v7; // eax
  std::pair<int,void *> *v8; // ecx
  std::pair<int,void *> *v9; // edi
  std::pair<int,void *> *i; // esi
  GraphicsManager *v11; // ecx
  Shader *v12; // eax
  bool v13; // cf
  GraphicsManager *v14; // ecx
  Shader *v15; // eax
  bool v16; // cc
  unsigned int v17; // [esp+20h] [ebp-58h]
  void *vb; // [esp+24h] [ebp-54h]
  vec3f point; // [esp+2Ch] [ebp-4Ch] BYREF
  std::wstring v20; // [esp+38h] [ebp-40h] BYREF
  std::wstring name; // [esp+50h] [ebp-28h] BYREF
  int v22; // [esp+74h] [ebp-4h]

  if ( (unsigned int)Spline::pointsCount((Spline *)spline) > 2 )
  {
    v3 = Spline::pointsCount((Spline *)spline);
    v4 = 0;
    v17 = v3;
    if ( v3 )
    {
      while ( 2 )
      {
        v5 = 0;
        this->primitive = eLinesStrip;
        this->currentIndex = 0;
        this->tempCounter = 0;
        this->useTexture = 0;
        for ( this->shader = 0; v5 < this->maxVertices; ++v5 )
        {
          if ( v4 < v3 )
          {
            Spline::pointAt((Spline *)spline, &point, v4);
            GLRenderer::vertex3f(this, point.x, point.y, point.z);
            ++v4;
          }
        }
        v6 = this->currentIndex;
        if ( v6 > this->maxVertices )
          this->maxVertices = v6;
        v7 = this->buffers._Myfirst;
        v8 = this->buffers._Mylast;
        vb = 0;
        if ( v7 == v8 )
          goto LABEL_14;
        while ( v6 > v7->first )
        {
          if ( ++v7 == v8 )
            goto LABEL_14;
        }
        vb = v7->second;
        if ( !vb )
        {
LABEL_14:
          _printf(
            "ERROR: Could not find suitable buffer for %d vertices in %d buffers\n",
            v6,
            v8 - this->buffers._Myfirst);
          v9 = this->buffers._Mylast;
          for ( i = this->buffers._Myfirst; i != v9; ++i )
            _printf("BUFFER: %d v\n", i->first);
          v3 = v17;
        }
        kglVertexBufferMap(vb, this->tempBuffer, 44 * this->currentIndex);
        kglSetVertexBuffer(vb);
        if ( this->shader )
        {
          GraphicsManager::setShader(this->graphics, this->shader);
        }
        else if ( this->useTexture )
        {
          if ( !this->glShaderTex )
          {
            name._Myres = 7;
            name._Mysize = 0;
            name._Bx._Buf[0] = 0;
            std::wstring::assign(&name, L"GLTextured", 0xAu);
            v11 = this->graphics;
            v22 = 0;
            v12 = GraphicsManager::getShader(v11, (unsigned int)this, &name);
            v13 = name._Myres < 8;
            this->glShaderTex = v12;
            v22 = -1;
            if ( !v13 )
              operator delete(name._Bx._Ptr);
          }
          GraphicsManager::setShader(this->graphics, this->glShaderTex);
        }
        else
        {
          if ( !this->glShader )
          {
            v20._Myres = 7;
            v20._Mysize = 0;
            v20._Bx._Buf[0] = 0;
            std::wstring::assign(&v20, L"GL", 2u);
            v14 = this->graphics;
            v22 = 1;
            v15 = GraphicsManager::getShader(v14, (unsigned int)this, &v20);
            v13 = v20._Myres < 8;
            this->glShader = v15;
            v22 = -1;
            if ( !v13 )
              operator delete(v20._Bx._Ptr);
            v20._Myres = 7;
            v20._Mysize = 0;
            v20._Bx._Buf[0] = 0;
          }
          GraphicsManager::setShader(this->graphics, this->glShader);
        }
        GraphicsManager::commitShaderChanges(this->graphics);
        switch ( this->primitive )
        {
          case eLines:
            if ( this->currentIndex >= 1 )
            {
              kglSetPrimitiveType(1u);
              goto LABEL_38;
            }
            goto LABEL_39;
          case eLinesStrip:
            if ( this->currentIndex >= 1 )
            {
              kglSetPrimitiveType(2u);
              goto LABEL_38;
            }
            goto LABEL_39;
          case eTriangles:
            v16 = this->currentIndex < 3;
            goto LABEL_36;
          case eQuads:
            v16 = this->currentIndex < 4;
LABEL_36:
            if ( v16 )
              goto LABEL_39;
            kglSetPrimitiveType(0);
LABEL_38:
            kglDraw(this->currentIndex, 0);
            kglSetPrimitiveType(0);
LABEL_39:
            if ( v4 >= v3 )
              return;
            continue;
          default:
            goto LABEL_38;
        }
      }
    }
  }
}
void GLRenderer::texCoord2f(GLRenderer *this, float u, float v)
{
  this->texCoord.x = u;
  this->texCoord.y = v;
  this->useTexture = 1;
}
void GLRenderer::vertex3fv(GLRenderer *this, const float *v)
{
  GLRenderer::vertex3f(this, *v, v[1], v[2]);
}
void GLRenderer::vertex3f(GLRenderer *this, float x, float y, float z)
{
  unsigned int v5; // ecx
  eGLPrimitiveType v6; // eax
  unsigned int v7; // eax
  MeshVertex *v8; // ecx
  MeshVertex *v9; // ecx
  MeshVertex *v10; // ecx
  MeshVertex *v11; // ecx
  MeshVertex *v12; // ecx
  MeshVertex *v13; // ecx
  int v14; // edx
  MeshVertex *v15; // ecx
  float v16; // eax
  int v17; // edx
  MeshVertex *v18; // ecx
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  float v21; // eax
  unsigned int v22; // ecx
  MeshVertex *v23; // ecx
  int v24; // edx
  MeshVertex *v25; // ecx
  float v26; // eax
  int v27; // edx
  MeshVertex *v28; // ecx

  v5 = this->currentIndex;
  if ( v5 < this->maxVertices )
  {
    v6 = this->primitive;
    if ( v6 >= eLines )
    {
      if ( v6 <= eTriangles )
      {
        v23 = &this->tempBuffer[v5];
        *(_QWORD *)&v23->pos.x = _mm_unpacklo_ps((__m128)LODWORD(x), (__m128)LODWORD(y)).m128_u64[0];
        v23->pos.z = z;
        v24 = this->currentIndex;
        v25 = this->tempBuffer;
        v26 = this->color.z;
        *(_QWORD *)&v25[v24].normal.x = _mm_unpacklo_ps((__m128)LODWORD(this->color.x), (__m128)LODWORD(this->color.y)).m128_u64[0];
        v25[v24].normal.z = v26;
        v27 = this->currentIndex;
        v28 = this->tempBuffer;
        v28[v27].texCoord.x = this->texCoord.x;
        v28[v27].texCoord.y = this->texCoord.y;
        this->tempBuffer[this->currentIndex++].tangent.x = this->color.w;
      }
      else if ( v6 == eQuads )
      {
        v7 = this->tempCounter;
        if ( v7 == 3 )
        {
          v8 = &this->tempBuffer[v5];
          *(__m128i *)&v8->pos.x = _mm_loadu_si128((const __m128i *)this->tempVertices);
          *(__m128i *)&v8->normal.y = _mm_loadu_si128((const __m128i *)&this->tempVertices[0].normal.y);
          *(_QWORD *)&v8->tangent.x = *(_QWORD *)&this->tempVertices[0].tangent.x;
          v8->tangent.z = this->tempVertices[0].tangent.z;
          v9 = &this->tempBuffer[++this->currentIndex];
          *(__m128i *)&v9->pos.x = _mm_loadu_si128((const __m128i *)&this->tempVertices[1]);
          *(__m128i *)&v9->normal.y = _mm_loadu_si128((const __m128i *)&this->tempVertices[1].normal.y);
          *(_QWORD *)&v9->tangent.x = *(_QWORD *)&this->tempVertices[1].tangent.x;
          v9->tangent.z = this->tempVertices[1].tangent.z;
          v10 = &this->tempBuffer[++this->currentIndex];
          *(__m128i *)&v10->pos.x = _mm_loadu_si128((const __m128i *)&this->tempVertices[2]);
          *(__m128i *)&v10->normal.y = _mm_loadu_si128((const __m128i *)&this->tempVertices[2].normal.y);
          *(_QWORD *)&v10->tangent.x = *(_QWORD *)&this->tempVertices[2].tangent.x;
          v10->tangent.z = this->tempVertices[2].tangent.z;
          v11 = &this->tempBuffer[++this->currentIndex];
          *(__m128i *)&v11->pos.x = _mm_loadu_si128((const __m128i *)this->tempVertices);
          *(__m128i *)&v11->normal.y = _mm_loadu_si128((const __m128i *)&this->tempVertices[0].normal.y);
          *(_QWORD *)&v11->tangent.x = *(_QWORD *)&this->tempVertices[0].tangent.x;
          v11->tangent.z = this->tempVertices[0].tangent.z;
          v12 = &this->tempBuffer[++this->currentIndex];
          *(__m128i *)&v12->pos.x = _mm_loadu_si128((const __m128i *)&this->tempVertices[2]);
          *(__m128i *)&v12->normal.y = _mm_loadu_si128((const __m128i *)&this->tempVertices[2].normal.y);
          *(_QWORD *)&v12->tangent.x = *(_QWORD *)&this->tempVertices[2].tangent.x;
          v12->tangent.z = this->tempVertices[2].tangent.z;
          v13 = &this->tempBuffer[++this->currentIndex];
          *(_QWORD *)&v13->pos.x = _mm_unpacklo_ps((__m128)LODWORD(x), (__m128)LODWORD(y)).m128_u64[0];
          v13->pos.z = z;
          v14 = this->currentIndex;
          v15 = this->tempBuffer;
          v16 = this->color.z;
          *(_QWORD *)&v15[v14].normal.x = _mm_unpacklo_ps(
                                            (__m128)LODWORD(this->color.x),
                                            (__m128)LODWORD(this->color.y)).m128_u64[0];
          v15[v14].normal.z = v16;
          v17 = this->currentIndex;
          v18 = this->tempBuffer;
          v18[v17].texCoord.x = this->texCoord.x;
          v18[v17].texCoord.y = this->texCoord.y;
          this->tempBuffer[this->currentIndex++].tangent.x = this->color.w;
          this->tempCounter = 0;
        }
        else
        {
          v19 = v7;
          *(_QWORD *)&this->tempVertices[v19].pos.x = _mm_unpacklo_ps((__m128)LODWORD(x), (__m128)LODWORD(y)).m128_u64[0];
          this->tempVertices[v19].pos.z = z;
          v20 = this->tempCounter;
          v21 = this->color.z;
          *(_QWORD *)&this->tempVertices[v20].normal.x = _mm_unpacklo_ps(
                                                           (__m128)LODWORD(this->color.x),
                                                           (__m128)LODWORD(this->color.y)).m128_u64[0];
          this->tempVertices[v20].normal.z = v21;
          v22 = this->tempCounter;
          this->tempVertices[v22].texCoord.x = this->texCoord.x;
          this->tempVertices[v22].texCoord.y = this->texCoord.y;
          this->tempVertices[this->tempCounter++].tangent.x = this->color.w;
        }
      }
    }
  }
  else
  {
    _printf("ERROR! GLRenderer::vertex3f currentIndex> %u\n", this->maxVertices);
  }
}
