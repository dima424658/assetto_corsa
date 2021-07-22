#pragma once

class RayCaster
{
// void __userpurge RayCaster(@<ecx>, int a2@<xmm2>, PhysicsCore *core);
RayCastHit *rayCast(RayCastHit *result, const vec3f *pos, const vec3f *dir);
void release();

};