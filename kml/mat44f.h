#pragma once

class mat44f
{
void mat44f::mat44f();
void mat44f::loadIdentity();
void mat44f::setTranslation(const vec3f *value);
vec3f *mat44f::getTranslation(vec3f *result);
vec3f *mat44f::toEuler(vec3f *result);
void mat44f::print();
bool mat44f::isIdentity();
bool mat44f::isFinite();
// void __userpurge mat44f::setScale(@<ecx>, __m128 a2@<xmm0>, const vec3f *s);

};