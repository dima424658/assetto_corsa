#include "materialfilter.h"
void MaterialFilter::MaterialFilter(MaterialFilter *this)
{
  this->__vftable = (MaterialFilter_vtbl *)&MaterialFilter::`vftable';
  this->lastMaterial = 0;
}
void MaterialFilter::~MaterialFilter(MaterialFilter *this)
{
  this->__vftable = (MaterialFilter_vtbl *)&MaterialFilter::`vftable';
}
MaterialFilter *MaterialFilter::`scalar deleting destructor'(MaterialFilter *this, unsigned int a2)
{
  this->__vftable = (MaterialFilter_vtbl *)&MaterialFilter::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void MaterialFilter::apply(MaterialFilter *this, const std::shared_ptr<Material> *material, RenderContext *rc)
{
  if ( material->_Ptr != this->lastMaterial )
  {
    Material::apply(material->_Ptr, rc);
    this->lastMaterial = material->_Ptr;
  }
}
void MaterialFilter::resetMaterialCache(Turbo *this)
{
  this->rotation = 0.0;
}
