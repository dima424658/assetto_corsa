#include "physicsobject.h
void PhysicsObject::PhysicsObject(PhysicsObject *this, PhysicsEngine *pe, PhysicsObjectDesc *desc, BufferedChannel<mat44f> *chOut)
{
  IPhysicsCore *v5; // eax
  IRigidBody *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  IRigidBody *v10; // eax
  IRigidBody_vtbl *v11; // esi
  Event<double> *v12; // ecx
  _DWORD v13[12]; // [esp+Ch] [ebp-7Ch] BYREF
  std::function<void __cdecl(SessionInfo const &)> v14; // [esp+3Ch] [ebp-4Ch] BYREF
  PhysicsObject *v15; // [esp+54h] [ebp-34h]
  int v16[6]; // [esp+70h] [ebp-18h] BYREF

  this->__vftable = (PhysicsObject_vtbl *)&PhysicsObject::`vftable';
  this->physicsEngine = pe;
  this->body = 0;
  this->chOut = chOut;
  v5 = PhysicsEngine::getCore(pe);
  v6 = v5->createRigidBody(v5);
  v7 = desc->worldMatrix.M41;
  v8 = desc->worldMatrix.M42;
  v9 = desc->worldMatrix.M43;
  this->body = v6;
  *(float *)v16 = v7;
  *(float *)&v16[1] = v8;
  *(float *)&v16[2] = v9;
  v6->setPosition(v6, (const vec3f *)v16);
  this->body->setRotation(this->body, &desc->worldMatrix);
  ((void (*)(IRigidBody *, _DWORD, int, int, int))this->body->setMassBox)(
    this->body,
    LODWORD(desc->mass),
    1065353216,
    1065353216,
    1065353216);
  v10 = this->body;
  v15 = 0;
  (&v14._Impl)[1] = (std::_Func_base<void,SessionInfo const &> *)31;
  v14._Impl = (std::_Func_base<void,SessionInfo const &> *)16;
  v11 = v10->__vftable;
  mat44f::createIdentity((mat44f *)v13);
  ((void (*)(IRigidBody *, float *, int, unsigned __int16 *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, void (__cdecl *)(), void (__cdecl *)(), void (__cdecl *)(), _DWORD, std::_Func_base<void,SessionInfo const &> *, std::_Func_base<void,SessionInfo const &> *, PhysicsObject *))v11->addMeshCollider)(
    this->body,
    desc->vertices,
    desc->vertexCount,
    desc->indices,
    desc->indexCount,
    v13[0],
    v13[1],
    v13[2],
    v13[3],
    v13[4],
    v13[5],
    v13[6],
    v13[7],
    v13[8],
    v13[9],
    v13[10],
    v13[11],
    v14._Space._Pfn[0],
    v14._Space._Pfn[1],
    v14._Space._Pfn[2],
    *(_DWORD *)&v14._Space._Alias[12],
    v14._Impl,
    (&v14._Impl)[1],
    v15);
  this->body->setAutoDisable(this->body, 1);
  this->body->setEnabled(this->body, 0);
  v15 = this;
  v14._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_d346950f61913737636a1cb1d10c31ee_,0>,std::allocator<std::_Func_class<void,double const &>>,void,double const &>::`vftable';
  *(_QWORD *)&v14._Space._Alias[4] = __PAIR64__((unsigned int)this, (unsigned int)chOut);
  v14._Impl = (std::_Func_base<void,SessionInfo const &> *)&v14;
  v12 = &this->physicsEngine->evOnStepCompleted;
  v16[5] = -1;
  Event<float>::addHandler((Event<SessionInfo> *)v12, v14, this);
}
PhysicsObject *PhysicsObject::`vector deleting destructor'(PhysicsObject *this, unsigned int a2)
{
  IRigidBody *v3; // ecx

  v3 = this->body;
  this->__vftable = (PhysicsObject_vtbl *)&PhysicsObject::`vftable';
  v3->release(v3);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
mat44f *PhysicsObject::getWorldMatrix(PhysicsObject *this, mat44f *result)
{
  ((void (*)(IRigidBody *, mat44f *, _DWORD))this->body->getWorldMatrix)(this->body, result, 0);
  return result;
}
void PhysicsObject::setWorldMatrix(PhysicsObject *this, const mat44f *worldMatrix)
{
  IRigidBody *v3; // ecx
  int v4[3]; // [esp+8h] [ebp-Ch] BYREF

  v3 = this->body;
  v4[0] = LODWORD(worldMatrix->M41);
  v4[1] = LODWORD(worldMatrix->M42);
  v4[2] = LODWORD(worldMatrix->M43);
  v3->setPosition(v3, (const vec3f *)v4);
  this->body->setRotation(this->body, worldMatrix);
}
