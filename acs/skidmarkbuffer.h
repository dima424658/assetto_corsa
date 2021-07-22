#pragma once

class SkidMarkBuffer
{
void SkidMarkBuffer::SkidMarkBuffer(GraphicsManager *graphics, unsigned int isize);
void SkidMarkBuffer::~SkidMarkBuffer();
SkidMarkBuffer *SkidMarkBuffer::`vector deleting destructor'(unsigned int a2);
void SkidMarkBuffer::addSegment(const vec3f *v1, const vec3f *v2, const vec3f *normal, float alpha);
void SkidMarkBuffer::addVertex(const vec3f *pos, const vec3f *normal, const vec2f *texcoord, float alpha);
void SkidMarkBuffer::render(RenderContext *rc);
void SkidMarkBuffer::reset();
void SkidMarkBuffer::split();

};