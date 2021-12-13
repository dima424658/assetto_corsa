#include "collisionmeshode.h"
void CollisionMeshODE::CollisionMeshODE(CollisionMeshODE *this, PhysicsCore *core, float *vertices, int numVertices, unsigned __int16 *indices, int indexCount, unsigned int group, unsigned int mask, unsigned int space_id)
{
  int (__cdecl *v10)(int); // eax
  dxTriMeshData *v11; // eax
  dxTriMeshData *v12; // eax
  int v13; // edi
  int v14; // edx
  int v15; // ecx
  dxTriMeshData *v16; // edi
  dxSpace *v17; // ebx
  dxTriMesh *v18; // eax
  dxTriMesh *v19; // eax
  int v20; // [esp-Ch] [ebp-2Ch]
  const void *v21; // [esp-8h] [ebp-28h]
  bool v22; // [esp-4h] [ebp-24h]

  v10 = dword_1872CAC;
  this->__vftable = (CollisionMeshODE_vtbl *)&CollisionMeshODE::`vftable';
  if ( v10 )
    v11 = (dxTriMeshData *)v10(92);
  else
    v11 = (dxTriMeshData *)_malloc(0x5Cu);
  if ( v11 )
    v12 = dxTriMeshData::dxTriMeshData(v11);
  else
    v12 = 0;
  this->trimeshData = v12;
  v13 = numVertices;
  this->lindices = (unsigned __int16 *)operator new[](2 * indexCount);
  this->lvertices = (float *)operator new[](12 * numVertices);
  v14 = 0;
  if ( indexCount > 0 )
  {
    do
    {
      this->lindices[v14] = indices[v14];
      ++v14;
    }
    while ( v14 < indexCount );
    v13 = numVertices;
  }
  memcpy(this->lvertices, vertices, 12 * v13);
  dxTriMeshData::Build(this->trimeshData, (char *)this->lvertices, v15, v13, this->lindices, indexCount, v20, v21, v22);
  v16 = this->trimeshData;
  v17 = PhysicsCore::getStaticSubSpace(core, space_id);
  if ( dword_1872CAC )
    v18 = (dxTriMesh *)dword_1872CAC(212);
  else
    v18 = (dxTriMesh *)_malloc(0xD4u);
  if ( v18 )
    v19 = dxTriMesh::dxTriMesh(v18, v17, v16);
  else
    v19 = 0;
  *((_DWORD *)v19 + 21) = 0;
  *((_DWORD *)v19 + 22) = 0;
  *((_DWORD *)v19 + 23) = 0;
  this->trimesh = v19;
  *((_DWORD *)v19 + 3) = this;
  *((_DWORD *)this->trimesh + 19) = group;
  *((_DWORD *)this->trimesh + 20) = mask;
  this->userPointer = 0;
}
CollisionMeshODE *CollisionMeshODE::`scalar deleting destructor'(CollisionMeshODE *this, unsigned int a2)
{
  float *v4; // [esp-4h] [ebp-8h]

  v4 = this->lvertices;
  this->__vftable = (CollisionMeshODE_vtbl *)&CollisionMeshODE::`vftable';
  operator delete[](v4);
  operator delete[](this->lindices);
  this->__vftable = (CollisionMeshODE_vtbl *)&ICollisionObject::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CollisionMeshODE::release(FSWinCmdUsbHid *this)
{
  if ( this )
    ((void (*)(FSWinCmdUsbHid *, int))this->~FSWinCmdUsbHid)(this, 1);
}
void CollisionMeshODE::setUserPointer(KeyboardManager *this, IKeyEventListener *l)
{
  this->focusListener = l;
}
void *CollisionMeshODE::getUserPointer(CollisionMeshODE *this)
{
  return this->userPointer;
}
unsigned int CollisionMeshODE::getGroup(CollisionMeshODE *this)
{
  return *((_DWORD *)this->trimesh + 19);
}
unsigned int CollisionMeshODE::getMask(CollisionMeshODE *this)
{
  return *((_DWORD *)this->trimesh + 20);
}
