#include "scenegraphcloner.h
void SceneGraphCloner::SceneGraphCloner(SceneGraphCloner *this)
{
  this->__vftable = (SceneGraphCloner_vtbl *)&SceneGraphCloner::`vftable';
}
void SceneGraphCloner::~SceneGraphCloner(SceneGraphCloner *this)
{
  this->__vftable = (SceneGraphCloner_vtbl *)&SceneGraphCloner::`vftable';
}
SceneGraphCloner *SceneGraphCloner::`vector deleting destructor'(SceneGraphCloner *this, unsigned int a2)
{
  this->__vftable = (SceneGraphCloner_vtbl *)&SceneGraphCloner::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
Node *SceneGraphCloner::cloneGraph(SceneGraphCloner *this, Node *n)
{
  Node *v2; // edi
  Node *v4; // eax
  Node *v5; // ebx
  SceneGraphCloner::cloneNode::__l3::<lambda_f092a279c4c78e614c7e7646e117040c> _Func; // [esp+Ch] [ebp-8h] BYREF

  v2 = n;
  SceneGraphCloner::getClonedNode(this, n);
  v5 = v4;
  _Func.__this = this;
  n = v4;
  _Func.dst = &n;
  std::_For_each<Node * *,_lambda_f092a279c4c78e614c7e7646e117040c_>(v2->nodes._Myfirst, v2->nodes._Mylast, &_Func);
  return v5;
}
void SceneGraphCloner::cloneNode(SceneGraphCloner *this, Node *src, Node *dst)
{
  SceneGraphCloner::cloneNode::__l3::<lambda_f092a279c4c78e614c7e7646e117040c> _Func; // [esp+0h] [ebp-8h] BYREF

  _Func.__this = this;
  _Func.dst = &dst;
  std::_For_each<Node * *,_lambda_f092a279c4c78e614c7e7646e117040c_>(src->nodes._Myfirst, src->nodes._Mylast, &_Func);
}
void SceneGraphCloner::getClonedNode(SceneGraphCloner *this, Node *src)
{
  const Mesh *v2; // edi
  Mesh *v3; // eax
  const SkinnedMesh *v4; // edi
  SkinnedMesh *v5; // eax
  Node *v6; // eax

  v2 = (const Mesh *)__RTDynamicCast(src, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
  if ( v2 )
  {
    v3 = (Mesh *)operator new(276);
    if ( v3 )
      Mesh::Mesh(v3, v2);
  }
  else
  {
    v4 = (const SkinnedMesh *)__RTDynamicCast(
                                src,
                                0,
                                &Node `RTTI Type Descriptor',
                                &SkinnedMesh `RTTI Type Descriptor',
                                0);
    if ( v4 )
    {
      v5 = (SkinnedMesh *)operator new(292);
      if ( v5 )
        SkinnedMesh::SkinnedMesh(v5, v4);
    }
    else
    {
      v6 = (Node *)operator new(188);
      if ( v6 )
        Node::Node(v6, src);
    }
  }
}
