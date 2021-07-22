#include "shaperenderer.h
void ShapeRenderer::ShapeRenderer(ShapeRenderer *this, GLRenderer *agl)
{
  this->__vftable = (ShapeRenderer_vtbl *)&ShapeRenderer::`vftable';
  this->color.x = 0.0;
  this->color.y = 0.0;
  this->color.z = 0.0;
  this->color.w = 0.0;
  this->gl = agl;
  this->color = (vec4f)_xmm;
}
void ShapeRenderer::~ShapeRenderer(ShapeRenderer *this)
{
  this->__vftable = (ShapeRenderer_vtbl *)&ShapeRenderer::`vftable';
}
ShapeRenderer *ShapeRenderer::`vector deleting destructor'(ShapeRenderer *this, unsigned int a2)
{
  this->__vftable = (ShapeRenderer_vtbl *)&ShapeRenderer::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ShapeRenderer::renderBox(ShapeRenderer *this, const vec3f *centre, const vec3f *size)
{
  GLRenderer *v5; // ecx
  vec4f r; // xmm0
  GLRenderer *v7; // ecx
  GLRenderer *v8; // ecx
  GLRenderer *v9; // ecx
  GLRenderer *v10; // ecx
  GLRenderer *v11; // ecx
  GLRenderer *v12; // ecx
  GLRenderer *v13; // ecx
  GLRenderer *v14; // ecx
  GLRenderer *v15; // ecx
  GLRenderer *v16; // ecx
  GLRenderer *v17; // ecx
  GLRenderer *v18; // ecx
  GLRenderer *v19; // ecx
  GLRenderer *v20; // ecx
  GLRenderer *v21; // ecx
  GLRenderer *v22; // ecx
  GLRenderer *v23; // ecx
  GLRenderer *v24; // ecx
  GLRenderer *v25; // ecx
  GLRenderer *v26; // ecx
  GLRenderer *v27; // ecx
  GLRenderer *v28; // ecx
  GLRenderer *v29; // ecx
  float v; // [esp+18h] [ebp-1Ch] BYREF
  float v31; // [esp+1Ch] [ebp-18h]
  float v32; // [esp+20h] [ebp-14h]
  float v33; // [esp+24h] [ebp-10h]
  float v34; // [esp+28h] [ebp-Ch]
  float v35; // [esp+2Ch] [ebp-8h]
  float v36; // [esp+30h] [ebp-4h]
  float sizea; // [esp+3Ch] [ebp+8h]

  v5 = this->gl;
  v36 = size->x * 0.5;
  sizea = size->y * 0.5;
  r = this->color;
  v35 = size->z * 0.5;
  GLRenderer::color4f(v5, r.x, r.y, r.z, r.w);
  GLRenderer::begin(this->gl, eQuads, 0);
  r.x = centre->x + COERCE_FLOAT(LODWORD(v36) ^ _xmm);
  v7 = this->gl;
  LODWORD(v34) = LODWORD(v36) ^ _xmm;
  LODWORD(v33) = LODWORD(v35) ^ _xmm;
  v = r.x;
  v31 = centre->y + sizea;
  v32 = centre->z + COERCE_FLOAT(LODWORD(v35) ^ _xmm);
  GLRenderer::vertex3fv(v7, &v);
  v8 = this->gl;
  v = centre->x + v34;
  v31 = centre->y + sizea;
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v8, &v);
  v9 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + sizea;
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v9, &v);
  v10 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + sizea;
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v10, &v);
  v11 = this->gl;
  v = centre->x + v34;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v11, &v);
  v12 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v12, &v);
  v13 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v13, &v);
  v14 = this->gl;
  v = centre->x + v34;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v14, &v);
  GLRenderer::end(this->gl);
  GLRenderer::begin(this->gl, eQuads, 0);
  v15 = this->gl;
  v = centre->x + v34;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v15, &v);
  v = centre->x + v34;
  v31 = centre->y + sizea;
  v16 = this->gl;
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v16, &v);
  v17 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + sizea;
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v17, &v);
  v18 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v18, &v);
  v19 = this->gl;
  v = centre->x + v34;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v19, &v);
  v20 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v20, &v);
  v21 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + sizea;
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v21, &v);
  v = centre->x + v34;
  v31 = centre->y + sizea;
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(this->gl, &v);
  GLRenderer::end(this->gl);
  GLRenderer::begin(this->gl, eQuads, 0);
  v22 = this->gl;
  v = centre->x + v34;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v22, &v);
  v23 = this->gl;
  v = centre->x + v34;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v23, &v);
  v24 = this->gl;
  v = centre->x + v34;
  v31 = centre->y + sizea;
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v24, &v);
  v25 = this->gl;
  v = centre->x + v34;
  v31 = centre->y + sizea;
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v25, &v);
  v26 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v26, &v);
  v = centre->x + v36;
  v31 = centre->y + sizea;
  v27 = this->gl;
  v32 = centre->z + v33;
  GLRenderer::vertex3fv(v27, &v);
  v28 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + sizea;
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v28, &v);
  v29 = this->gl;
  v = centre->x + v36;
  v31 = centre->y + COERCE_FLOAT(LODWORD(sizea) ^ _xmm);
  v32 = centre->z + v35;
  GLRenderer::vertex3fv(v29, &v);
  GLRenderer::end(this->gl);
}
