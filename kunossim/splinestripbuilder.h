#pragma once

class SplineStripBuilder
{
void SplineStripBuilder(GraphicsManager *graphics);
void ~SplineStripBuilder();
void addPoint(const vec3f *p, const vec3f *normal, const vec3f *color, float alpha);
void addVertex(const vec3f *v1, const vec3f *normal, const vec2f *tex, float alpha);
Mesh *buildMesh();

};