#include "carnodesorter.h"
void CarNodeSorter::CarNodeSorter(CarNodeSorter *this, const std::wstring *name, Sim *sim)
{
  std::_Tree_node<std::pair<Node * const,CarAvatar *>,void *> *v4; // eax

  Node::Node(this, name);
  this->__vftable = (CarNodeSorter_vtbl *)&CarNodeSorter::`vftable';
  this->cars._Myhead = 0;
  this->cars._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<ID3D11View * const,PPFX::IGPUSurface *>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<unsigned int const ,bool>> > *)&this->cars);
  this->cars._Myhead = v4;
  this->sim = sim;
}
CarNodeSorter *CarNodeSorter::`vector deleting destructor'(CarNodeSorter *this, unsigned int a2)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > > result; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (CarNodeSorter_vtbl *)&CarNodeSorter::`vftable';
  std::_Tree<std::_Tmap_traits<unsigned int,bool,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,bool>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<unsigned int,bool,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,bool> >,0> > *)&this->cars,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > >)this->cars._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > >)this->cars._Myhead);
  operator delete(this->cars._Myhead);
  Node::~Node(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CarNodeSorter::addCar(CarNodeSorter *this, Node *node, CarAvatar *avatar)
{
  Node **v4; // eax

  this->addChild(this, node);
  v4 = (Node **)std::map<Node *,CarAvatar *>::operator[](&this->cars, &node);
  *v4 = (Node *)avatar;
}
void CarNodeSorter::sort(CarNodeSorter *this)
{
  CarNodeSorter *v1; // ebx
  Sim *v2; // eax
  int v3; // ebp
  Node **v4; // esi
  unsigned int v5; // edi
  std::map<Node *,CarAvatar *> *v6; // ebx
  CarAvatar **v7; // eax
  int v8; // eax
  int v9; // ecx
  Node *n; // [esp+10h] [ebp-Ch] BYREF
  int v11; // [esp+14h] [ebp-8h]
  CarNodeSorter *v12; // [esp+18h] [ebp-4h]

  v1 = this;
  v2 = this->sim;
  v3 = 0;
  v4 = this->nodes._Myfirst;
  v12 = this;
  v11 = v2->cameraManager->currentGlobalCameraIndex;
  v5 = (unsigned int)((char *)this->nodes._Mylast - (char *)v4 + 3) >> 2;
  if ( v4 > this->nodes._Mylast )
    v5 = 0;
  if ( v5 )
  {
    v6 = &this->cars;
    do
    {
      n = *v4;
      v7 = (CarAvatar **)std::map<Node *,CarAvatar *>::operator[](v6, &n);
      v8 = CarAvatar::getGuid(*v7);
      v9 = 0;
      ++v4;
      if ( v8 == v11 )
        v9 = 10;
      ++v3;
      n->priority = v9;
    }
    while ( v3 != v5 );
    v1 = v12;
  }
  std::_Sort<Node * *,int,_lambda_34d661537c28432bb0babb0208ff3da7_>(
    v1->nodes._Myfirst,
    v1->nodes._Mylast,
    v1->nodes._Mylast - v1->nodes._Myfirst,
    (CarNodeSorter::sort::__l12::<lambda_34d661537c28432bb0babb0208ff3da7>)v12);
}
