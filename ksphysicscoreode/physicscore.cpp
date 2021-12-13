#include "physicscore.h"
CoreCPUTimes *PhysicsCore::getCoreCPUTimes(PhysicsCore *this, CoreCPUTimes *result)
{
  CoreCPUTimes *v2; // eax

  v2 = result;
  *(__m128i *)&result->solverTime = _mm_loadu_si128((const __m128i *)&this->coreCPUTimes);
  *(_QWORD *)&result->contactPoints = *(_QWORD *)&this->coreCPUTimes.contactPoints;
  return v2;
}
void PhysicsCore::PhysicsCore(PhysicsCore *this)
{
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *v2; // eax
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<unsigned int const ,dxSpace *>> > *v3; // ecx
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *v4; // eax
  int (__cdecl *v5)(int); // esi
  dxWorld *v6; // eax
  dxWorld *v7; // eax
  dxJointGroup *v8; // eax
  dxJointGroup *v9; // eax
  dxSpace *v10; // eax
  int v11; // edx
  dxSpace *v12; // ebx
  dxSpace *v13; // eax
  int v14; // edx
  dxSpace *v15; // ebx
  dxGeom *v16; // eax
  dxGeom *v17; // esi
  dxWorld *v18; // eax

  this->__vftable = (PhysicsCore_vtbl *)&PhysicsCore::`vftable';
  *(_OWORD *)&this->coreCPUTimes.solverTime = 0i64;
  this->coreCPUTimes.contactPoints = 0;
  this->coreCPUTimes.narrowPhaseTests = 0;
  this->noCollisionCounter = 0;
  this->staticSubSpaces._Myhead = 0;
  this->staticSubSpaces._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<unsigned int const,dxSpace *>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<unsigned int const ,dxSpace *>> > *)this);
  this->staticSubSpaces._Myhead = v2;
  this->dynamicSubSpaces._Myhead = 0;
  this->dynamicSubSpaces._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<unsigned int const,dxSpace *>>>::_Buyheadnode(v3);
  this->dynamicSubSpaces._Myhead = v4;
  this->totRayTime = 0.0;
  this->currentFrame = 0;
  this->collisionCallback = 0;
  if ( sub_4E3650() && !sub_4E3860(0, (__m128)0i64) )
    sub_4E3760();
  sub_4E3860(-1, (__m128)0i64);
  _printf(
    "ODE BUILD FLAGS: %s\n",
    "ODE ODE_EXT_no_debug ODE_EXT_trimesh ODE_EXT_opcode ODE_OPC_16bit_indices ODE_OPC_new_collider ODE_EXT_mt_collisions"
    " ODE_EXT_threading ODE_single_precision");
  v5 = dword_1872CAC;
  if ( dword_1872CAC )
  {
    v6 = (dxWorld *)dword_1872CAC(128);
    v5 = dword_1872CAC;
  }
  else
  {
    v6 = (dxWorld *)_malloc(0x80u);
  }
  if ( v6 )
    v7 = dxWorld::dxWorld(v6);
  else
    v7 = 0;
  this->id = v7;
  *((_DWORD *)v7 + 8) = 0;
  *((_DWORD *)v7 + 9) = -1055070880;
  *((_DWORD *)v7 + 10) = 0;
  if ( v5 )
  {
    v8 = (dxJointGroup *)v5(20);
    v5 = dword_1872CAC;
  }
  else
  {
    v8 = (dxJointGroup *)_malloc(0x14u);
  }
  if ( v8 )
  {
    *(_DWORD *)v8 = 0;
    *((_DWORD *)v8 + 1) = 0;
    *((_DWORD *)v8 + 2) = 0;
    *((_DWORD *)v8 + 3) = 0;
    *((_DWORD *)v8 + 4) = 0;
  }
  else
  {
    v8 = 0;
  }
  this->contactGroup = v8;
  if ( v5 )
  {
    v9 = (dxJointGroup *)v5(20);
    v5 = dword_1872CAC;
  }
  else
  {
    v9 = (dxJointGroup *)_malloc(0x14u);
  }
  if ( v9 )
  {
    *(_DWORD *)v9 = 0;
    *((_DWORD *)v9 + 1) = 0;
    *((_DWORD *)v9 + 2) = 0;
    *((_DWORD *)v9 + 3) = 0;
    *((_DWORD *)v9 + 4) = 0;
  }
  else
  {
    v9 = 0;
  }
  this->contactGroupDynamic = v9;
  this->currentContactGroup = this->contactGroup;
  *((_DWORD *)this->id + 12) = 1050253722;
  *((_DWORD *)this->id + 13) = 869711765;
  *((_DWORD *)this->id + 24) = 1077936128;
  *((_DWORD *)this->id + 25) = 0;
  if ( v5 )
  {
    v10 = (dxSpace *)v5(116);
    v5 = dword_1872CAC;
  }
  else
  {
    v10 = (dxSpace *)_malloc(0x74u);
  }
  v12 = v10;
  if ( v10 )
  {
    dxSpace::dxSpace(v10, v11, 0);
    v5 = dword_1872CAC;
    *(_DWORD *)v12 = &dxSimpleSpace::`vftable';
    *((_DWORD *)v12 + 1) = 10;
  }
  else
  {
    v12 = 0;
  }
  this->spaceStatic = v12;
  if ( v5 )
  {
    v13 = (dxSpace *)v5(116);
    v5 = dword_1872CAC;
  }
  else
  {
    v13 = (dxSpace *)_malloc(0x74u);
  }
  v15 = v13;
  if ( v13 )
  {
    dxSpace::dxSpace(v13, v14, 0);
    v5 = dword_1872CAC;
    *(_DWORD *)v15 = &dxSimpleSpace::`vftable';
    *((_DWORD *)v15 + 1) = 10;
  }
  else
  {
    v15 = 0;
  }
  this->spaceDynamic = v15;
  if ( v5 )
    v16 = (dxGeom *)v5(88);
  else
    v16 = (dxGeom *)_malloc(0x58u);
  v17 = v16;
  if ( v16 )
  {
    dxGeom::dxGeom(v16, 0, 1);
    *(_DWORD *)v17 = &dxRay::`vftable';
    *((_DWORD *)v17 + 1) = 5;
    *((_DWORD *)v17 + 21) = 1120403456;
  }
  else
  {
    v17 = 0;
  }
  this->ray = v17;
  *((_DWORD *)v17 + 2) |= 0x10000u;
  *((_DWORD *)this->ray + 2) |= 0x20000u;
  v18 = this->id;
  *((_DWORD *)v18 + 19) &= 0xFFFFFF9F;
  *((_DWORD *)v18 + 26) = 0;
  *((_DWORD *)v18 + 27) = 0;
  *((_DWORD *)this->id + 22) = 48;
}
PhysicsCore *PhysicsCore::`scalar deleting destructor'(PhysicsCore *this, unsigned int a2)
{
  PhysicsCore::~PhysicsCore(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PhysicsCore::~PhysicsCore(PhysicsCore *this)
{
  dxGeom *v2; // ecx
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *v3; // edi
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *v4; // esi
  dxSpace *v5; // ecx
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *v6; // eax
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *j; // eax
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *i; // eax
  dxSpace *v9; // ecx
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *v10; // edi
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *v11; // esi
  dxSpace *v12; // ecx
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *v13; // eax
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *l; // eax
  std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *k; // eax
  dxSpace *v16; // ecx
  unsigned int *v17; // ebp
  _DWORD *v18; // eax
  _DWORD *v19; // edi
  std::_Tree<std::_Tmap_traits<unsigned int,dxSpace *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,dxSpace *> >,0> > *v20; // edi
  unsigned int *v21; // ebp
  unsigned int *v22; // eax
  void (__cdecl *v23)(unsigned int *, int); // esi
  unsigned int *v24; // edi
  _DWORD *v25; // ecx
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,dxSpace *> > > > result; // [esp+14h] [ebp-4h] BYREF

  result._Ptr = (std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *)this;
  v2 = this->ray;
  result._Ptr->_Left = (std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *)&PhysicsCore::`vftable';
  if ( v2 )
    (**(void (***)(dxGeom *, int))v2)(v2, 1);
  v3 = this->dynamicSubSpaces._Myhead;
  v4 = v3->_Left;
  while ( v4 != v3 )
  {
    v5 = v4->_Myval.second;
    if ( v5 )
      (**(void (***)(dxSpace *, int))v5)(v5, 1);
    if ( !v4->_Isnil )
    {
      v6 = v4->_Right;
      if ( v6->_Isnil )
      {
        for ( i = v4->_Parent; !i->_Isnil; i = i->_Parent )
        {
          if ( v4 != i->_Right )
            break;
          v4 = i;
        }
        v4 = i;
      }
      else
      {
        v4 = v4->_Right;
        for ( j = v6->_Left; !j->_Isnil; j = j->_Left )
          v4 = j;
      }
    }
  }
  v9 = this->spaceDynamic;
  if ( v9 )
    (**(void (***)(dxSpace *, int))v9)(v9, 1);
  v10 = this->staticSubSpaces._Myhead;
  v11 = v10->_Left;
  while ( v11 != v10 )
  {
    v12 = v11->_Myval.second;
    if ( v12 )
      (**(void (***)(dxSpace *, int))v12)(v12, 1);
    if ( !v11->_Isnil )
    {
      v13 = v11->_Right;
      if ( v13->_Isnil )
      {
        for ( k = v11->_Parent; !k->_Isnil; k = k->_Parent )
        {
          if ( v11 != k->_Right )
            break;
          v11 = k;
        }
        v11 = k;
      }
      else
      {
        v11 = v11->_Right;
        for ( l = v13->_Left; !l->_Isnil; l = l->_Left )
          v11 = l;
      }
    }
  }
  v16 = this->spaceStatic;
  if ( v16 )
    (**(void (***)(dxSpace *, int))v16)(v16, 1);
  v17 = (unsigned int *)this->contactGroup;
  dJointGroupEmpty(v17, (int)v11);
  if ( v17 )
  {
    v18 = (_DWORD *)v17[1];
    v11 = (std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *)dword_1872CA8;
    if ( v18 )
    {
      do
      {
        v19 = (_DWORD *)*v18;
        if ( v11 )
        {
          ((void (__cdecl *)(_DWORD *, int))v11)(v18, 0x4000);
          v11 = (std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *)dword_1872CA8;
        }
        else
        {
          _free(v18);
        }
        v18 = v19;
      }
      while ( v19 );
    }
    if ( v11 )
      ((void (__cdecl *)(unsigned int *, int))v11)(v17, 20);
    else
      _free(v17);
  }
  v20 = (std::_Tree<std::_Tmap_traits<unsigned int,dxSpace *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,dxSpace *> >,0> > *)result._Ptr;
  v21 = (unsigned int *)result._Ptr[1]._Myval.second;
  dJointGroupEmpty(v21, (int)v11);
  if ( v21 )
  {
    v22 = (unsigned int *)v21[1];
    v23 = (void (__cdecl *)(unsigned int *, int))dword_1872CA8;
    if ( v22 )
    {
      do
      {
        v24 = (unsigned int *)*v22;
        if ( v23 )
        {
          v23(v22, 0x4000);
          v23 = (void (__cdecl *)(unsigned int *, int))dword_1872CA8;
        }
        else
        {
          _free(v22);
        }
        v22 = v24;
      }
      while ( v24 );
      v20 = (std::_Tree<std::_Tmap_traits<unsigned int,dxSpace *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,dxSpace *> >,0> > *)result._Ptr;
    }
    if ( v23 )
      v23(v21, 20);
    else
      _free(v21);
  }
  v25 = (_DWORD *)v20->_Mysize;
  if ( v25 )
    dWorldDestroy(v25);
  sub_4E3760();
  std::_Tree<std::_Tmap_traits<unsigned int,dxSpace *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,dxSpace *>>,0>>::erase(
    v20 + 9,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,dxSpace *> > > >)v20[9]._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,dxSpace *> > > >)v20[9]._Myhead);
  operator delete(v20[9]._Myhead);
  std::_Tree<std::_Tmap_traits<unsigned int,dxSpace *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,dxSpace *>>,0>>::erase(
    v20 + 8,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,dxSpace *> > > >)v20[8]._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,dxSpace *> > > >)v20[8]._Myhead);
  operator delete(v20[8]._Myhead);
  v20->_Myhead = (std::_Tree_node<std::pair<unsigned int const ,dxSpace *>,void *> *)&IPhysicsCore::`vftable';
}
void __usercall PhysicsCore::initMultithreading(PhysicsCore *this@<ecx>, __m128 a2@<xmm0>)
{
  sub_4E3860(-1, a2);
}
void PhysicsCore::step(PhysicsCore *this, float dt)
{
  int v3; // eax
  dxWorld *v4; // esi
  unsigned int v5[4]; // [esp+4h] [ebp-10h] BYREF

  v3 = this->noCollisionCounter;
  if ( v3 )
    this->noCollisionCounter = v3 - 1;
  else
    PhysicsCore::collisionStep(this);
  v4 = this->id;
  if ( dxReallocateWorldProcessContext(v5, (int)v4, SLODWORD(dt)) )
    dxProcessIslands((int)v5, (int)v4, SLODWORD(dt));
  geomCollideTestCount = 0;
  rayCollideTestCount = 0;
}
void PhysicsCore::createRigidBody(PhysicsCore *this)
{
  RigidBodyODE *v2; // eax

  v2 = (RigidBodyODE *)operator new(0x24u);
  if ( v2 )
    RigidBodyODE::RigidBodyODE(v2, this);
}
void PhysicsCore::release(PhysicsCore *this)
{
  if ( this )
    ((void (*)(PhysicsCore *, int))this->~IPhysicsCore)(this, 1);
}
IJoint *PhysicsCore::createDistanceJoint(PhysicsCore *this, IRigidBody *rb1, IRigidBody *rb2, const vec3f *p1, const vec3f *p2)
{
  int v6; // edi
  int v7; // eax
  dxWorld *v8; // esi
  int v9; // ebx
  dxJointDBall *v10; // eax
  int v11; // edx
  int *v12; // esi
  dxJointDBall *v13; // ecx
  IJoint *result; // eax
  IJoint_vtbl *rb1a; // [esp+10h] [ebp+4h]

  v6 = __RTDynamicCast(rb1, 0, &IRigidBody `RTTI Type Descriptor', &RigidBodyODE `RTTI Type Descriptor', 0);
  v7 = __RTDynamicCast(rb2, 0, &IRigidBody `RTTI Type Descriptor', &RigidBodyODE `RTTI Type Descriptor', 0);
  v8 = this->id;
  v9 = v7;
  if ( dword_1872CAC )
    v10 = (dxJointDBall *)dword_1872CAC(124);
  else
    v10 = (dxJointDBall *)_malloc(0x7Cu);
  if ( v10 )
    v12 = (int *)dxJointDBall::dxJointDBall(v10, v11, v8);
  else
    v12 = 0;
  dJointAttach(*(_DWORD *)(v6 + 4), v12, *(_DWORD *)(v9 + 4));
  dJointSetDBallAnchor1((dxJointDBall *)v12, p1->x, p1->y, p1->z);
  dJointSetDBallAnchor2(v13, p2->x, p2->y, p2->z);
  rb1a = (IJoint_vtbl *)v12[30];
  result = (IJoint *)operator new(0xCu);
  if ( result )
  {
    result->__vftable = (IJoint_vtbl *)&DistanceJointODE::`vftable';
    result[1].__vftable = (IJoint_vtbl *)v12;
    result[2].__vftable = rb1a;
  }
  else
  {
    result = 0;
    MEMORY[4] = v12;
    MEMORY[8] = rb1a;
  }
  return result;
}
void PhysicsCore::reseatDistanceJointLocal(PhysicsCore *this, IJoint *joint, const vec3f *p1, const vec3f *p2)
{
  IJoint_vtbl *v4; // ecx
  float *v5; // esi
  float *v6; // edx
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // [esp+8h] [ebp-14h]
  float v12; // [esp+10h] [ebp-Ch]
  float v13; // [esp+18h] [ebp-4h]

  v4 = joint[1].__vftable;
  if ( ((int)v4[2].release & 2) != 0 )
    v5 = (float *)v4[3].~IJoint;
  else
    v5 = (float *)v4[2].~IJoint;
  if ( ((int)v4[2].release & 2) != 0 )
    v6 = (float *)v4[2].~IJoint;
  else
    v6 = (float *)v4[3].~IJoint;
  v7 = p1->y;
  v8 = p1->z;
  v9 = p2->z;
  v10 = p2->y;
  v13 = v6[39] + (float)((float)((float)(v6[44] * v10) + (float)(p2->x * v6[43])) + (float)(v6[45] * v9));
  v12 = v6[40] + (float)((float)((float)(v6[48] * v10) + (float)(v6[47] * p2->x)) + (float)(v6[49] * v9));
  v11 = v6[41] + (float)((float)((float)(v6[52] * v10) + (float)(v6[51] * p2->x)) + (float)(v6[53] * v9));
  dJointSetDBallAnchor1(
    (dxJointDBall *)v4,
    v5[39] + (float)((float)((float)(v5[44] * v7) + (float)(v5[43] * p1->x)) + (float)(v5[45] * v8)),
    v5[40] + (float)((float)((float)(v5[48] * v7) + (float)(v5[47] * p1->x)) + (float)(v5[49] * v8)),
    v5[41] + (float)((float)((float)(v5[52] * v7) + (float)(v5[51] * p1->x)) + (float)(v5[53] * v8)));
  dJointSetDBallAnchor2((dxJointDBall *)joint[1].__vftable, v13, v12, v11);
  joint[1].__vftable[10].release = (void (*)(IJoint *))joint[2].__vftable;
}
IJoint *PhysicsCore::createBumpJoint(PhysicsCore *this, IRigidBody *rb1, IRigidBody *rb2, const vec3f *p1, float rangeUp, float rangeDn)
{
  return 0;
}
IJoint *PhysicsCore::createFixedJoint(PhysicsCore *this, IRigidBody *rb1, IRigidBody *rb2)
{
  int v4; // edi
  int v5; // eax
  dxWorld *v6; // esi
  int v7; // ebx
  dxJointFixed *v8; // eax
  int v9; // edx
  int *v10; // esi
  IJoint *result; // eax

  v4 = __RTDynamicCast(rb1, 0, &IRigidBody `RTTI Type Descriptor', &RigidBodyODE `RTTI Type Descriptor', 0);
  v5 = __RTDynamicCast(rb2, 0, &IRigidBody `RTTI Type Descriptor', &RigidBodyODE `RTTI Type Descriptor', 0);
  v6 = this->id;
  v7 = v5;
  if ( dword_1872CAC )
    v8 = (dxJointFixed *)dword_1872CAC(120);
  else
    v8 = (dxJointFixed *)_malloc(0x78u);
  if ( v8 )
    v10 = (int *)dxJointFixed::dxJointFixed(v8, v9, v6);
  else
    v10 = 0;
  dJointAttach(*(_DWORD *)(v4 + 4), v10, *(_DWORD *)(v7 + 4));
  dJointSetFixed((int)v10);
  result = (IJoint *)operator new(8u);
  if ( result )
  {
    result->__vftable = (IJoint_vtbl *)&FixedJointODE::`vftable';
    result[1].__vftable = (IJoint_vtbl *)v10;
  }
  else
  {
    result = 0;
    MEMORY[4] = v10;
  }
  return result;
}
IJoint *PhysicsCore::createBallJoint(PhysicsCore *this, IRigidBody *rb1, IRigidBody *rb2, const vec3f *pos)
{
  int v5; // edi
  int v6; // eax
  dxWorld *v7; // esi
  int v8; // ebx
  dxJointBall *v9; // eax
  int v10; // edx
  int *v11; // esi
  IJoint *result; // eax

  v5 = __RTDynamicCast(rb1, 0, &IRigidBody `RTTI Type Descriptor', &RigidBodyODE `RTTI Type Descriptor', 0);
  v6 = __RTDynamicCast(rb2, 0, &IRigidBody `RTTI Type Descriptor', &RigidBodyODE `RTTI Type Descriptor', 0);
  v7 = this->id;
  v8 = v6;
  if ( dword_1872CAC )
    v9 = (dxJointBall *)dword_1872CAC(120);
  else
    v9 = (dxJointBall *)_malloc(0x78u);
  if ( v9 )
    v11 = (int *)dxJointBall::dxJointBall(v9, v10, v7);
  else
    v11 = 0;
  dJointAttach(*(_DWORD *)(v5 + 4), v11, *(_DWORD *)(v8 + 4));
  setAnchors((int)(v11 + 20), (int)v11, pos->x, pos->y, pos->z, (struct dxJoint *)(v11 + 24));
  result = (IJoint *)operator new(8u);
  if ( result )
  {
    result->__vftable = (IJoint_vtbl *)&BallJointODE::`vftable';
    result[1].__vftable = (IJoint_vtbl *)v11;
  }
  else
  {
    result = 0;
    MEMORY[4] = v11;
  }
  return result;
}
IJoint *PhysicsCore::createSliderJoint(PhysicsCore *this, IRigidBody *rb1, IRigidBody *rb2, const vec3f *axis)
{
  int v5; // edi
  int v6; // eax
  dxWorld *v7; // esi
  int v8; // ebx
  dxJointSlider *v9; // eax
  int v10; // edx
  int *v11; // esi
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  dxJointSlider *v16; // ecx
  IJoint *result; // eax

  v5 = __RTDynamicCast(rb1, 0, &IRigidBody `RTTI Type Descriptor', &RigidBodyODE `RTTI Type Descriptor', 0);
  v6 = __RTDynamicCast(rb2, 0, &IRigidBody `RTTI Type Descriptor', &RigidBodyODE `RTTI Type Descriptor', 0);
  v7 = this->id;
  v8 = v6;
  if ( dword_1872CAC )
    v9 = (dxJointSlider *)dword_1872CAC(172);
  else
    v9 = (dxJointSlider *)_malloc(0xACu);
  if ( v9 )
    v11 = (int *)dxJointSlider::dxJointSlider(v9, v10, v7);
  else
    v11 = 0;
  dJointAttach(*(_DWORD *)(v5 + 4), v11, *(_DWORD *)(v8 + 4));
  v12 = axis->x;
  v13 = axis->y;
  v14 = axis->z;
  v15 = fsqrt((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v14 * v14));
  if ( v15 != 0.0 )
  {
    v12 = (float)(1.0 / v15) * v12;
    v13 = (float)(1.0 / v15) * v13;
    v14 = (float)(1.0 / v15) * v14;
  }
  setAxes((int)v11, v12, v13, v14);
  dxJointSlider::computeOffset((dxJointSlider *)v11);
  dxJointSlider::computeInitialRelativeRotation(v16);
  result = (IJoint *)operator new(8u);
  if ( result )
  {
    result->__vftable = (IJoint_vtbl *)&SliderJointODE::`vftable';
    result[1].__vftable = (IJoint_vtbl *)v11;
  }
  else
  {
    result = 0;
    MEMORY[4] = v11;
  }
  return result;
}
void PhysicsCore::createCollisionMesh(PhysicsCore *this, float *vertices, unsigned int numVertices, unsigned __int16 *indices, int indexCount, const mat44f *worldMatrix, IRigidBody *body, unsigned int group, unsigned int mask, unsigned int space_id)
{
  CollisionMeshODE *v11; // eax

  v11 = (CollisionMeshODE *)operator new(0x18u);
  if ( v11 )
    CollisionMeshODE::CollisionMeshODE(v11, this, vertices, numVertices, indices, indexCount, group, mask, space_id);
}
RayCastHit *PhysicsCore::rayCast(PhysicsCore *this, RayCastHit *result, const vec3f *pos, const vec3f *dir, float length)
{
  dxGeom *v6; // ecx

  v6 = this->ray;
  *((float *)v6 + 21) = length;
  dGeomMoved(v6);
  PhysicsCore::rayCast(this, result, pos, dir, this->ray);
  return result;
}
RayCastHit *PhysicsCore::rayCast(PhysicsCore *this, RayCastHit *result, const vec3f *pos, const vec3f *dir, dxGeom *rayc)
{
  bool v5; // zf
  int v6; // xmm0_4
  int v7; // xmm1_4
  float v8; // xmm7_4
  float v9; // xmm2_4
  int v10; // xmm3_4
  int v11; // xmm4_4
  float *v12; // esi
  dxGeom *v13; // edx
  float v14; // xmm0_4
  __m128 v15; // xmm1
  float v16; // ecx
  dxGeom *v17; // ecx
  float v19; // [esp+Ch] [ebp-64h] BYREF
  int v20; // [esp+10h] [ebp-60h]
  float v21; // [esp+14h] [ebp-5Ch]
  int v22; // [esp+1Ch] [ebp-54h]
  int v23; // [esp+20h] [ebp-50h]
  PhysicsCore *v24; // [esp+24h] [ebp-4Ch]
  int v25; // [esp+28h] [ebp-48h]
  int v26; // [esp+2Ch] [ebp-44h]
  float v27; // [esp+30h] [ebp-40h]
  RayContactAccumulator accum; // [esp+34h] [ebp-3Ch] BYREF

  v24 = this;
  accum.depth = -1.0;
  result->pos.x = 0.0;
  result->pos.y = 0.0;
  result->pos.z = 0.0;
  result->normal.x = 0.0;
  result->normal.y = 0.0;
  result->normal.z = 0.0;
  result->hasContact = 0;
  result->collisionObject = 0;
  v5 = (*((_BYTE *)rayc + 8) & 2) == 0;
  v6 = LODWORD(pos->y);
  v7 = LODWORD(pos->z);
  v8 = pos->x;
  v25 = v6;
  v26 = v7;
  v9 = dir->x;
  v10 = LODWORD(dir->y);
  v11 = SLODWORD(dir->z);
  v27 = dir->x;
  v22 = v10;
  v23 = v11;
  if ( !v5 )
  {
    dxGeom::computePosr(rayc);
    *((_DWORD *)rayc + 2) &= 0xFFFFFFFD;
    v6 = v25;
    v7 = v26;
    v9 = v27;
    v10 = v22;
    v11 = v23;
  }
  v12 = (float *)*((_DWORD *)rayc + 6);
  v19 = v9;
  v20 = v10;
  v21 = *(float *)&v11;
  *v12 = v8;
  *((_DWORD *)v12 + 1) = v6;
  *((_DWORD *)v12 + 2) = v7;
  _dSafeNormalize3(&v19);
  v12[6] = v19;
  *((_DWORD *)v12 + 10) = v20;
  v12[14] = v21;
  dGeomMoved(rayc);
  rayCollideTestCount = 0;
  v13 = v24->spaceStatic;
  broadTestCount = 0;
  dSpaceCollide2(v13, rayc, (int)&accum, (int (__cdecl *)(int, int, int))rayNearCallback);
  if ( accum.depth >= 0.0 )
  {
    v14 = accum.contact.pos[2];
    v15 = (__m128)LODWORD(accum.contact.normal[1]);
    *(_QWORD *)&result->pos.x = _mm_unpacklo_ps(
                                  (__m128)LODWORD(accum.contact.pos[0]),
                                  (__m128)LODWORD(accum.contact.pos[1])).m128_u64[0];
    v21 = accum.contact.normal[2];
    v16 = accum.contact.normal[2];
    *(_QWORD *)&result->normal.x = _mm_unpacklo_ps((__m128)LODWORD(accum.contact.normal[0]), v15).m128_u64[0];
    result->normal.z = v16;
    v17 = accum.contact.g2;
    result->hasContact = 1;
    result->pos.z = v14;
    result->collisionObject = (ICollisionObject *)*((_DWORD *)v17 + 3);
  }
  return result;
}
void PhysicsCore::setCollisionCallback(PhysicsCore *this, ICollisionCallback *callback)
{
  this->collisionCallback = callback;
}
void PhysicsCore::collisionStep(PhysicsCore *this)
{
  bool v2; // zf
  dxGeom *v3; // edx
  dxGeom *v4; // ecx
  int v5; // eax
  dxSpace *v6; // ecx

  broadTestCount = 0;
  v2 = (this->currentFrame & 1) == 0;
  this->coreCPUTimes.contactPoints = 0;
  if ( v2 )
  {
    dJointGroupEmpty((unsigned int *)this->contactGroup, (int)this);
    v6 = this->spaceDynamic;
    this->currentContactGroup = this->contactGroup;
    (*(void (**)(dxSpace *, PhysicsCore *, void (__cdecl *)(void *, dxGeom *, dxGeom *)))(*(_DWORD *)v6 + 36))(
      v6,
      this,
      nearCallback);
  }
  else
  {
    dJointGroupEmpty((unsigned int *)this->contactGroupDynamic, (int)this);
    v3 = this->spaceStatic;
    v4 = this->spaceDynamic;
    this->currentContactGroup = this->contactGroupDynamic;
    dSpaceCollide2(v3, v4, (int)this, (int (__cdecl *)(int, int, int))nearCallback);
  }
  v5 = geomCollideTestCount;
  ++this->currentFrame;
  this->coreCPUTimes.narrowPhaseTests = v5;
}
void PhysicsCore::onCollision(PhysicsCore *this, dContactGeom *contacts, int numContacts, dxGeom *g0, dxGeom *g1)
{
  int v6; // ecx
  dxGeom *v7; // edi
  float *i; // ebx
  __m128i v9; // xmm0
  int v10; // eax
  float *v11; // eax
  char v12; // al
  int *v13; // eax
  ICollisionCallback *v14; // edx
  int v15; // ecx
  int v16; // eax
  unsigned __int64 v17; // [esp-Ch] [ebp-E0h]
  unsigned __int64 v18; // [esp+0h] [ebp-D4h]
  int v19; // [esp+24h] [ebp-B0h]
  int v20; // [esp+28h] [ebp-ACh]
  PhysicsCore *v21; // [esp+2Ch] [ebp-A8h]
  dContact c; // [esp+50h] [ebp-84h] BYREF

  v6 = numContacts;
  v7 = g1;
  v21 = this;
  this->coreCPUTimes.contactPoints += numContacts;
  if ( numContacts > 0 )
  {
    for ( i = &contacts->normal[2]; ; i += 13 )
    {
      v9 = _mm_loadu_si128((const __m128i *)(i - 6));
      c.geom.side2 = (int)i[6];
      v10 = *((_DWORD *)v7 + 1);
      c.surface.mode = 28692;
      c.surface.mu = 0.25;
      c.surface.bounce = 0.0099999998;
      c.surface.soft_cfm = 0.000099999997;
      *(__m128i *)c.geom.pos = v9;
      *(__m128i *)c.geom.normal = _mm_loadu_si128((const __m128i *)(i - 2));
      *(__m128i *)&c.geom.depth = _mm_loadu_si128((const __m128i *)(i + 2));
      if ( (v10 != 8 || *((_DWORD *)g0 + 1) != 1) && (*((_DWORD *)g0 + 1) != 8 || v10 != 1) )
      {
LABEL_12:
        v13 = (int *)createJoint<dxJointContact>(this->id, (_DWORD *)this->currentContactGroup);
        qmemcpy(v13 + 21, &c, 0x80u);
        v7 = g1;
        dJointAttach(*((_DWORD *)g0 + 4), v13, *((_DWORD *)g1 + 4));
        this = v21;
        v14 = v21->collisionCallback;
        if ( v14 )
        {
          v15 = *((_DWORD *)g0 + 4);
          v16 = *((_DWORD *)g1 + 4);
          v20 = 0;
          v19 = 0;
          if ( v15 )
            v20 = *(_DWORD *)(v15 + 20);
          if ( v16 )
            v19 = *(_DWORD *)(v16 + 20);
          v18 = _mm_unpacklo_ps((__m128)*((unsigned int *)i - 6), (__m128)*((unsigned int *)i - 5)).m128_u64[0];
          v17 = _mm_unpacklo_ps((__m128)*((unsigned int *)i - 2), (__m128)*((unsigned int *)i - 1)).m128_u64[0];
          ((void (*)(ICollisionCallback *, int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v14->onCollisionCallBack)(
            v14,
            v20,
            *((_DWORD *)g0 + 3),
            v19,
            *((_DWORD *)g1 + 3),
            v17,
            HIDWORD(v17),
            *(_DWORD *)i,
            v18,
            HIDWORD(v18),
            *((_DWORD *)i - 4),
            *((_DWORD *)i + 2));
          this = v21;
        }
        v6 = numContacts;
        goto LABEL_19;
      }
      v11 = (float *)*((_DWORD *)g0 + 4);
      if ( !v11 )
      {
        v11 = (float *)*((_DWORD *)v7 + 4);
        if ( !v11 )
          break;
      }
      if ( (float)((float)((float)(v11[48] * c.geom.normal[1]) + (float)(v11[44] * c.geom.normal[0]))
                 + (float)(v11[52] * c.geom.normal[2])) >= 0.89999998 )
        goto LABEL_10;
      v12 = 0;
LABEL_11:
      c.surface.mode = 28700;
      c.surface.soft_cfm = 0.00095238094;
      c.surface.soft_erp = 0.71428573;
      c.surface.mu = 0.1;
      c.surface.bounce = 0.0;
      if ( v12 )
        goto LABEL_12;
LABEL_19:
      numContacts = --v6;
      if ( !v6 )
        return;
    }
    _printf("Warning, box collision with no body attached");
    v6 = numContacts;
LABEL_10:
    v12 = 1;
    goto LABEL_11;
  }
}
void PhysicsCore::setSliderAxis(PhysicsCore *this, IJoint *joint, const vec3f *axis, const vec3f *anchor)
{
  IJoint_vtbl *v4; // esi
  dxJointSlider *v5; // ecx

  v4 = joint[1].__vftable;
  setAxes((int)v4, axis->x, axis->y, axis->z);
  dxJointSlider::computeOffset((dxJointSlider *)v4);
  dxJointSlider::computeInitialRelativeRotation(v5);
}
void PhysicsCore::createRayCaster(PhysicsCore *this, float length)
{
  RayCaster *v3; // eax

  v3 = (RayCaster *)operator new(0xCu);
  if ( v3 )
    RayCaster::RayCaster(v3, SLODWORD(length), this);
}
void PhysicsCore::setNoCollisionSteps(PhysicsCore *this, int steps)
{
  this->noCollisionCounter = steps;
}
dxSpace *PhysicsCore::getStaticSubSpace(PhysicsCore *this, unsigned int index)
{
  unsigned int v2; // edi
  std::map<unsigned int,dxSpace *> *v4; // ebx
  dxSpace *v5; // edi
  dxSpace *v6; // eax
  int v7; // edx
  dxSpace *v8; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,dxSpace *> > > > result; // [esp+8h] [ebp-4h] BYREF

  v2 = index;
  if ( !index )
    return this->spaceStatic;
  v4 = &this->staticSubSpaces;
  std::_Tree<std::_Tmap_traits<unsigned int,dxSpace *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,dxSpace *>>,0>>::find(
    &this->staticSubSpaces,
    &result,
    &index);
  if ( result._Ptr == v4->_Myhead )
  {
    _printf("CREATING STATIC SUBSPACE AT INDEX:%d\n", v2);
    v5 = this->spaceStatic;
    if ( dword_1872CAC )
      v6 = (dxSpace *)dword_1872CAC(116);
    else
      v6 = (dxSpace *)_malloc(0x74u);
    v8 = v6;
    if ( v6 )
    {
      dxSpace::dxSpace(v6, v7, v5);
      *(_DWORD *)v8 = &dxSimpleSpace::`vftable';
      *((_DWORD *)v8 + 1) = 10;
    }
    else
    {
      v8 = 0;
    }
    *std::map<unsigned int,dxSpace *>::operator[](v4, &index) = v8;
  }
  return *std::map<unsigned int,dxSpace *>::operator[](v4, &index);
}
dxSpace *PhysicsCore::getDynamicSubSpace(PhysicsCore *this, unsigned int index)
{
  unsigned int v2; // edi
  std::map<unsigned int,dxSpace *> *v4; // ebx
  dxSpace *v5; // edi
  dxSpace *v6; // eax
  int v7; // edx
  dxSpace *v8; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,dxSpace *> > > > result; // [esp+8h] [ebp-4h] BYREF

  v2 = index;
  if ( !index )
    return this->spaceDynamic;
  v4 = &this->dynamicSubSpaces;
  std::_Tree<std::_Tmap_traits<unsigned int,dxSpace *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,dxSpace *>>,0>>::find(
    &this->dynamicSubSpaces,
    &result,
    &index);
  if ( result._Ptr == v4->_Myhead )
  {
    _printf("CREATING DYNAMIC SUBSPACE AT INDEX:%d\n", v2);
    v5 = this->spaceDynamic;
    if ( dword_1872CAC )
      v6 = (dxSpace *)dword_1872CAC(116);
    else
      v6 = (dxSpace *)_malloc(0x74u);
    v8 = v6;
    if ( v6 )
    {
      dxSpace::dxSpace(v6, v7, v5);
      *(_DWORD *)v8 = &dxSimpleSpace::`vftable';
      *((_DWORD *)v8 + 1) = 10;
    }
    else
    {
      v8 = 0;
    }
    *std::map<unsigned int,dxSpace *>::operator[](v4, &index) = v8;
  }
  return *std::map<unsigned int,dxSpace *>::operator[](v4, &index);
}
void PhysicsCore::resetCollisions(PhysicsCore *this)
{
  dJointGroupEmpty((unsigned int *)this->contactGroupDynamic, (int)this);
  dJointGroupEmpty((unsigned int *)this->contactGroup, (int)this);
}
