#include "cubemap.h"
void CubeMap::CubeMap(CubeMap *this, unsigned int size, unsigned int format, unsigned int mips)
{
  void *v5; // eax

  this->__vftable = (CubeMap_vtbl *)&CubeMap::`vftable';
  kglCreateCubeMap(size, format, mips);
  this->kid = v5;
}
CubeMap *CubeMap::`vector deleting destructor'(CubeMap *this, unsigned int a2)
{
  void *v4; // [esp-4h] [ebp-8h]

  v4 = this->kid;
  this->__vftable = (CubeMap_vtbl *)&CubeMap::`vftable';
  kglDestroyCubeMap(v4);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CubeMap::apply(CubeMap *this, int slot)
{
  kglSetTextureCubeMap(this->kid, slot);
}
void CubeMap::beginFace(CubeMap *this, int index)
{
  kglCubeMapBeginFace(this->kid, index);
}
void CubeMap::endFace(CubeMap *this)
{
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)this);
}
void CubeMap::generateMips(CubeMap *this, int face)
{
  kglCubeMapGenerateMips(this->kid, face);
}
