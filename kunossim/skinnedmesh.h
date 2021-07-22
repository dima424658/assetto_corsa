#pragma once

class SkinnedMesh
{
void SkinnedMesh::SkinnedMesh(const SkinnedMesh *mesh);
void SkinnedMesh::SkinnedMesh(std::wstring aname);
void SkinnedMesh::~SkinnedMesh();
SkinnedMesh *SkinnedMesh::`vector deleting destructor'(unsigned int a2);
void SkinnedMesh::addBone(Node *node, mat44f offsetMatrix);
// void __userpurge SkinnedMesh::compile(@<ecx>, __m128 a2@<xmm0>, CompileContext *cc);
void SkinnedMesh::initBonesBuffer(GraphicsManager *graphics);
void SkinnedMesh::render(RenderContext *rc);
void SkinnedMesh::updateBonesBuffer(RenderContext *rc);

};