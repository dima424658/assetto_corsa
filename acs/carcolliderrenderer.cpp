#include "carcolliderrenderer.h"
void CarColliderRenderer::CarColliderRenderer(CarColliderRenderer *this, CarAvatar *acar)
{
  CarAvatar *v3; // eax
  std::wstring v4; // [esp-1Ch] [ebp-3Ch] BYREF
  Game *v5; // [esp-4h] [ebp-24h]
  CarColliderRenderer *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  v5 = acar->game;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"CAR_COLLIDER_RENDERER", 0x15u);
  GameObject::GameObject(this, v4, v5);
  v5 = (Game *)this;
  v7 = 0;
  this->__vftable = (CarColliderRenderer_vtbl *)&CarColliderRenderer::`vftable';
  this->car = acar;
  v4._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_442a64015e55ca5338aa063647e1d4e3_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&v4._Bx._Alias[4] = this;
  v4._Mysize = (unsigned int)&v4;
  v3 = this->car;
  LOBYTE(v7) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v3->sim->renderFinishedNodeEvent->evOnRender,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v4,
    v5);
}
CarColliderRenderer *CarColliderRenderer::`scalar deleting destructor'(CarColliderRenderer *this, unsigned int a2)
{
  this->__vftable = (CarColliderRenderer_vtbl *)&CarColliderRenderer::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge CarColliderRenderer::renderWireframe(CarColliderRenderer *this@<ecx>, __m128 a2@<xmm0>, RenderContext *rc)
{
  CarColliderManager *v4; // ebx
  GLRenderer *v5; // esi
  int v6; // edi
  int v7; // esi
  GLRenderer *v8; // [esp+24h] [ebp-44h]
  ShapeRenderer shaperRenderer; // [esp+28h] [ebp-40h] BYREF
  CarCollisionBox box; // [esp+40h] [ebp-28h] BYREF
  int i; // [esp+64h] [ebp-4h]

  v4 = CarAvatar::getColliderManager(this->car);
  if ( v4 )
  {
    v5 = this->game->graphics->gl;
    v8 = v5;
    v6 = v4->boxes._Mylast - v4->boxes._Myfirst;
    GraphicsManager::setWorldMatrix(rc->graphics, &this->car->physicsState.worldMatrix);
    ShapeRenderer::ShapeRenderer(&shaperRenderer, v5);
    v7 = 0;
    for ( i = 0; v7 < v6; ++v7 )
    {
      CarColliderManager::getBox(v4, a2, &box, v7);
      ShapeRenderer::renderBox(&shaperRenderer, &box.centre, &box.size);
    }
    GraphicsManager::setWorldMatrix(rc->graphics, &this->car->bodyMatrix);
    GraphicsManager::setCullMode(rc->graphics, eCullNone);
    GLRenderer::color4f(v8, 3.0, 0.0, 0.0, 1.0);
    GLRenderer::begin(v8, eQuads, 0);
    GLRenderer::vertex3f(
      v8,
      this->car->modelBoundaries.left,
      this->car->modelBoundaries.top,
      this->car->modelBoundaries.front);
    GLRenderer::vertex3f(
      v8,
      this->car->modelBoundaries.right,
      this->car->modelBoundaries.top,
      this->car->modelBoundaries.front);
    GLRenderer::vertex3f(
      v8,
      this->car->modelBoundaries.right,
      this->car->modelBoundaries.top,
      this->car->modelBoundaries.rear);
    GLRenderer::vertex3f(
      v8,
      this->car->modelBoundaries.left,
      this->car->modelBoundaries.top,
      this->car->modelBoundaries.rear);
    GLRenderer::end(v8);
    i = -1;
    ShapeRenderer::~ShapeRenderer(&shaperRenderer);
  }
}
