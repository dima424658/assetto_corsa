#include "raycaster.h"
void __userpurge RayCaster::RayCaster(RayCaster *this@<ecx>, int a2@<xmm2>, PhysicsCore *core)
{
  int (__cdecl *v5)(int); // eax
  dxGeom *v6; // eax
  dxGeom *v7; // esi

  this->core = core;
  v5 = dword_1872CAC;
  this->__vftable = (RayCaster_vtbl *)&RayCaster::`vftable';
  if ( v5 )
    v6 = (dxGeom *)v5(88);
  else
    v6 = (dxGeom *)_malloc(0x58u);
  v7 = v6;
  if ( v6 )
  {
    dxGeom::dxGeom(v6, 0, 1);
    *(_DWORD *)v7 = &dxRay::`vftable';
    *((_DWORD *)v7 + 1) = 5;
    *((_DWORD *)v7 + 21) = a2;
  }
  else
  {
    v7 = 0;
  }
  this->ray = v7;
  *((_DWORD *)v7 + 2) |= 0x10000u;
  *((_DWORD *)this->ray + 2) |= 0x20000u;
}
RayCaster *RayCaster::`scalar deleting destructor'(RayCaster *this, unsigned int a2)
{
  dxGeom *v3; // ecx

  v3 = this->ray;
  this->__vftable = (RayCaster_vtbl *)&RayCaster::`vftable';
  if ( v3 )
    (**(void (***)(dxGeom *, int))v3)(v3, 1);
  this->__vftable = (RayCaster_vtbl *)&IRayCaster::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
RayCastHit *RayCaster::rayCast(RayCaster *this, RayCastHit *result, const vec3f *pos, const vec3f *dir)
{
  PhysicsCore::rayCast(this->core, result, pos, dir, this->ray);
  return result;
}
void RayCaster::release(RayCaster *this)
{
  if ( this )
    ((void (*)(RayCaster *, int))this->~IRayCaster)(this, 1);
}
