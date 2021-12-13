#include "ksphysicscoreodefactory.h"
void __cdecl ksPhysicsCoreODEFactory::create()
{
  PhysicsCore *v0; // eax

  v0 = (PhysicsCore *)operator new(0x68u);
  if ( v0 )
    PhysicsCore::PhysicsCore(v0);
}
