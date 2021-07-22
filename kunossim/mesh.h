#pragma once

class Mesh
{
void Mesh::Mesh(const Mesh *mesh);
void Mesh::Mesh(std::wstring name);
void Mesh::~Mesh();
void Mesh::addChild(Node *n);
void Mesh::compile(CompileContext *cc);
Triangle *Mesh::getTriangle(Triangle *result, int index);
void Mesh::render(RenderContext *rc);

};