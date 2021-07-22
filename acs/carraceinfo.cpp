#include "carraceinfo.h"
void CarRaceInfo::CarRaceInfo(CarRaceInfo *this)
{
  std::_Tree_node<std::pair<std::wstring const ,int>,void *> *v2; // eax

  this->__vftable = (CarRaceInfo_vtbl *)&CarRaceInfo::`vftable';
  this->car = 0;
  this->spawnPositionIndex._Myhead = 0;
  this->spawnPositionIndex._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,int>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TyreCompoundStrategy>> > *)&this->spawnPositionIndex);
  this->spawnPositionIndex._Myhead = v2;
  this->raceManager = 0;
}
void CarRaceInfo::~CarRaceInfo(CarRaceInfo *this)
{
  std::map<std::wstring,int> *v1; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > result; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (CarRaceInfo_vtbl *)&CarRaceInfo::`vftable';
  v1 = &this->spawnPositionIndex;
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->spawnPositionIndex,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->spawnPositionIndex._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->spawnPositionIndex._Myhead);
  operator delete(v1->_Myhead);
}
CarRaceInfo *CarRaceInfo::`scalar deleting destructor'(CarRaceInfo *this, unsigned int a2)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > result; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (CarRaceInfo_vtbl *)&CarRaceInfo::`vftable';
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->spawnPositionIndex,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->spawnPositionIndex._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)this->spawnPositionIndex._Myhead);
  operator delete(this->spawnPositionIndex._Myhead);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
unsigned int CarRaceInfo::getSpawnPositionIndex(CarRaceInfo *this, const std::wstring *setName)
{
  return *std::map<std::wstring,int>::operator[](&this->spawnPositionIndex, setName);
}
void CarRaceInfo::init(CarRaceInfo *this, CarAvatar *acar)
{
  unsigned int *v3; // eax
  unsigned int *v4; // eax
  Sim *v5; // edi
  GameObject **v6; // esi
  RaceManager *v7; // eax
  CarAvatar *v8; // eax
  std::function<void __cdecl(SessionInfo const &)> v9; // [esp-1Ch] [ebp-5Ch] BYREF
  CarRaceInfo *v10; // [esp-4h] [ebp-44h]
  std::wstring _Keyval; // [esp+18h] [ebp-28h] BYREF
  int v12; // [esp+3Ch] [ebp-4h]

  this->car = acar;
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"START", 5u);
  v12 = 0;
  v3 = std::map<std::wstring,int>::operator[](&this->spawnPositionIndex, &_Keyval);
  v12 = -1;
  *v3 = -1;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"PIT", 3u);
  v12 = 1;
  v4 = std::map<std::wstring,int>::operator[](&this->spawnPositionIndex, &_Keyval);
  v12 = -1;
  *v4 = 0;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  v5 = this->car->sim;
  v6 = v5->gameObjects._Myfirst;
  if ( v6 == v5->gameObjects._Mylast )
  {
LABEL_8:
    v7 = 0;
  }
  else
  {
    while ( 1 )
    {
      v7 = (RaceManager *)__RTDynamicCast(
                            *v6,
                            0,
                            &GameObject `RTTI Type Descriptor',
                            &RaceManager `RTTI Type Descriptor',
                            0);
      if ( v7 )
        break;
      if ( ++v6 == v5->gameObjects._Mylast )
        goto LABEL_8;
    }
  }
  v10 = this;
  this->raceManager = v7;
  v9._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_d6cdba19fa34fd58a768285fc49557c4_,0>,std::allocator<std::_Func_class<void,OnSessionEndEvent const &>>,void,OnSessionEndEvent const &>::`vftable';
  v9._Space._Pfn[1] = (void (__cdecl *)())this;
  v9._Impl = (std::_Func_base<void,SessionInfo const &> *)&v9;
  v8 = this->car;
  v12 = -1;
  Event<float>::addHandler((Event<SessionInfo> *)&v8->sim->raceManager->evOnSessionEnd, v9, v10);
}
void CarRaceInfo::setSpawnPositionIndex(CarRaceInfo *this, const std::wstring *setName, int gp)
{
  *std::map<std::wstring,int>::operator[](&this->spawnPositionIndex, setName) = gp;
}
