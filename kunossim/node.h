#pragma once

class Node
{
bool Node::getActive();
void Node::setActive(bool a);
Mesh *Node::getNodeChild<Mesh>(std::wstring name, bool recursive);
void Node::Node(const Node *node);
void Node::Node(const std::wstring *n);
void Node::~Node();
void Node::addChild(Node *n);
void Node::compile(CompileContext *cc);
Node *Node::findChildByName(const std::wstring *sname, bool recursive);
void Node::findChildrenByName(const std::wstring *nname, std::vector<Node *> *result);
void Node::findChildrenByPrefix(const std::wstring *prefix, std::vector<Node *> *result);
Node *Node::getParent();
mat44f *Node::getWorldMatrix(mat44f *result);
vec3f *Node::localToWorld(vec3f *result, const vec3f *pos);
void Node::printTree(int ident);
void Node::removeChild(Node *n);
void Node::render(RenderContext *rc);
void Node::renderAudio();
void Node::visit(std::function<bool __cdecl(Node *)> onVisit, std::function<void __cdecl(Node *)> onPostVisit);
vec3f *Node::worldToLocal(vec3f *result, const vec3f *pos);
vec3f *Node::worldToLocalNormal(vec3f *result, const vec3f *pos);

};