#include "camerameshfilter.h
void CameraMeshFilter::CameraMeshFilter(CameraMeshFilter *this, Camera *icamera, RenderPassID passid, int amaxLayer)
{
  this->camera = icamera;
  this->passID = passid;
  this->maxLayer = amaxLayer;
  this->__vftable = (CameraMeshFilter_vtbl *)&CameraMeshFilter::`vftable';
}
void CameraMeshFilter::~CameraMeshFilter(CameraMeshFilter *this)
{
  this->__vftable = (CameraMeshFilter_vtbl *)&IMeshRenderFilter::`vftable';
}
IMeshRenderFilter *CameraMeshFilter::`scalar deleting destructor'(IMeshRenderFilter *this, unsigned int a2)
{
  this->__vftable = (IMeshRenderFilter_vtbl *)&IMeshRenderFilter::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
char CameraMeshFilter::isVisible(CameraMeshFilter *this, Renderable *mesh, const mat44f *currentMatrix)
{
  RenderPassID v4; // eax
  Camera *v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  sphere *v15; // eax
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  sphere trSphere; // [esp+8h] [ebp-10h] BYREF

  if ( mesh->layer > this->maxLayer )
    return 0;
  v4 = this->passID;
  if ( v4 == Shadowgen && !mesh->castShadows )
    return 0;
  if ( mesh->isTransparent )
  {
    if ( v4 != Transparent && v4 != Shadowgen )
      return 0;
  }
  else if ( v4 == Transparent )
  {
    return 0;
  }
  if ( v4 != Shadowgen && !mesh->isVisible )
    return 0;
  if ( !mesh->noCull )
  {
    v5 = this->camera;
    if ( v5 )
    {
      v6 = v5->fov * 0.0125;
      v7 = FLOAT_1_0;
      if ( v6 <= 1.0 )
      {
        if ( v6 >= 0.0 )
          v7 = v5->fov * 0.0125;
        else
          v7 = 0.0;
      }
      v8 = v5->lodMultiplier * v7;
      if ( mesh->isStatic )
      {
        v17 = mesh->lodIN;
        if ( v17 != 0.0 || mesh->lodOUT != 0.0 )
        {
          v18 = v5->matrix.M41 - mesh->boundingSphere.center.x;
          v19 = v5->matrix.M43 - mesh->boundingSphere.center.z;
          v20 = (float)((float)((float)(v5->matrix.M42 - mesh->boundingSphere.center.y)
                              * (float)(v5->matrix.M42 - mesh->boundingSphere.center.y))
                      + (float)(v18 * v18))
              + (float)(v19 * v19);
          v21 = mesh->lodOUT;
          v22 = (float)(v20 * v8) * v8;
          if ( v21 <= mesh->boundingSphere.radius )
            v21 = mesh->boundingSphere.radius;
          if ( (float)(v17 * v17) > v22 || v22 > (float)(v21 * v21) )
            return 0;
        }
        v15 = &mesh->boundingSphere;
      }
      else
      {
        sphere::transform(&mesh->boundingSphere, &trSphere, currentMatrix);
        v9 = mesh->lodIN;
        if ( v9 != 0.0 || mesh->lodOUT != 0.0 )
        {
          v10 = this->camera->matrix.M41 - trSphere.center.x;
          v11 = this->camera->matrix.M43 - trSphere.center.z;
          v12 = (float)((float)((float)(this->camera->matrix.M42 - trSphere.center.y)
                              * (float)(this->camera->matrix.M42 - trSphere.center.y))
                      + (float)(v10 * v10))
              + (float)(v11 * v11);
          v13 = mesh->lodOUT;
          v14 = (float)(v12 * v8) * v8;
          if ( v13 <= mesh->boundingSphere.radius )
            v13 = mesh->boundingSphere.radius;
          if ( (float)(v9 * v9) > v14 || v14 > (float)(v13 * v13) )
            return 0;
        }
        v5 = this->camera;
        v15 = &trSphere;
      }
      if ( !BoundingFrustum::intersect(&v5->frustum, v15) )
        return 0;
    }
  }
  return 1;
}
