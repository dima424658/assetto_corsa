#pragma once

class CubeMap
{
void CubeMap::CubeMap(unsigned int size, unsigned int format, unsigned int mips);
CubeMap *CubeMap::`vector deleting destructor'(unsigned int a2);
void CubeMap::apply(int slot);
void CubeMap::beginFace(int index);
void CubeMap::endFace();
void CubeMap::generateMips(int face);

};