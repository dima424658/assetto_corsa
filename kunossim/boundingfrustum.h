#pragma once

class BoundingFrustum
{
void BoundingFrustum::BoundingFrustum(const mat44f *iviewProj);
void BoundingFrustum::~BoundingFrustum();
BoundingFrustum *BoundingFrustum::`vector deleting destructor'(unsigned int a2);
void BoundingFrustum::getCorners(std::vector<vec3f> *corners);
char BoundingFrustum::intersect(const sphere *s);
void BoundingFrustum::setMatrix(const mat44f *value);

};