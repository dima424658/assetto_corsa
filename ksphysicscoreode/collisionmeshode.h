#pragma once

class CollisionMeshODE
{
void CollisionMeshODE::CollisionMeshODE(PhysicsCore *core, float *vertices, int numVertices, unsigned __int16 *indices, int indexCount, unsigned int group, unsigned int mask, unsigned int space_id);
void CollisionMeshODE::release(FSWinCmdUsbHid *this);
void CollisionMeshODE::setUserPointer(KeyboardManager *this, IKeyEventListener *l);
void *CollisionMeshODE::getUserPointer();
unsigned int CollisionMeshODE::getGroup();
unsigned int CollisionMeshODE::getMask();

};