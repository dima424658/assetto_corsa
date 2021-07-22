#include "debugvisualizer.h"
void DebugVisualizer::DebugVisualizer(DebugVisualizer *this, Sim *aSim)
{
  Game *v3; // eax
  std::_Tree_node<std::pair<int const ,DebugString>,void *> *v4; // eax
  Event<OnNodeRenderEvent> *v5; // ecx
  std::wstring v6; // [esp-1Ch] [ebp-64h] BYREF
  unsigned int v7; // [esp-4h] [ebp-4Ch]
  DebugVisualizer *v8; // [esp+1Ch] [ebp-2Ch]
  std::wstring name; // [esp+20h] [ebp-28h] BYREF
  int v10; // [esp+44h] [ebp-4h]

  v8 = this;
  v7 = (unsigned int)aSim->game;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, L"DEBUG_VISUALIZER", 0x10u);
  GameObject::GameObject(this, v6, (Game *)v7);
  v10 = 0;
  this->IDebugVisualizer::__vftable = (IDebugVisualizer_vtbl *)&IDebugVisualizer::`vftable';
  v7 = 7;
  LOBYTE(v10) = 1;
  v6._Myres = (unsigned int)L"led_big";
  this->GameObject::__vftable = (DebugVisualizer_vtbl *)&DebugVisualizer::`vftable'{for `GameObject'};
  this->IDebugVisualizer::__vftable = (IDebugVisualizer_vtbl *)&DebugVisualizer::`vftable'{for `IDebugVisualizer'};
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, (const wchar_t *)v6._Myres, v7);
  v3 = aSim->game;
  LOBYTE(v10) = 2;
  StringBlitter3D::StringBlitter3D(&this->sb, &name, v3->graphics);
  LOBYTE(v10) = 4;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  Concurrency::details::_Concurrent_queue_base_v4::_Concurrent_queue_base_v4(&this->linesQueue, 0x2Cu);
  this->linesQueue.__vftable = (Concurrency::concurrent_queue<DebugLine,std::allocator<DebugLine> >_vtbl *)&Concurrency::concurrent_queue<DebugLine,std::allocator<DebugLine>>::`vftable';
  LOBYTE(v10) = 5;
  Concurrency::details::_Concurrent_queue_base_v4::_Concurrent_queue_base_v4(&this->stringQueue, 0x40u);
  this->stringQueue.__vftable = (Concurrency::concurrent_queue<DebugString,std::allocator<DebugString> >_vtbl *)&Concurrency::concurrent_queue<DebugString,std::allocator<DebugString>>::`vftable';
  this->sim = aSim;
  LOBYTE(v10) = 6;
  this->stringMap._Myhead = 0;
  this->stringMap._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<int const,DebugString>>>::_Buyheadnode(&this->stringMap);
  this->stringMap._Myhead = v4;
  this->drawingLinesQueue._Myfirst = 0;
  this->drawingLinesQueue._Mylast = 0;
  this->drawingLinesQueue._Myend = 0;
  this->drawingStringsQueue._Myfirst = 0;
  this->drawingStringsQueue._Mylast = 0;
  this->drawingStringsQueue._Myend = 0;
  v7 = (unsigned int)this;
  v6._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_1ef22c60bcb012d06e71d8f6b23781ef_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&v6._Bx._Alias[4] = this;
  v6._Mysize = (unsigned int)&v6;
  v5 = &aSim->renderFinishedNodeEvent->evOnRender;
  LOBYTE(v10) = 9;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v5,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v6,
    this);
  aSim->physicsAvatar->engine.debugVisualizer = &this->IDebugVisualizer;
  this->currentLayer = 0;
}
void DebugVisualizer::~DebugVisualizer(DebugVisualizer *this)
{
  bool v2; // zf
  std::vector<DebugString> *v3; // esi
  std::vector<DebugLine> *v4; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const ,DebugString> > > > result; // [esp+14h] [ebp-10h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  this->GameObject::__vftable = (DebugVisualizer_vtbl *)&DebugVisualizer::`vftable'{for `GameObject'};
  this->IDebugVisualizer::__vftable = (IDebugVisualizer_vtbl *)&DebugVisualizer::`vftable'{for `IDebugVisualizer'};
  v2 = this->drawingStringsQueue._Myfirst == 0;
  v3 = &this->drawingStringsQueue;
  v6 = 3;
  if ( !v2 )
  {
    std::_Container_base0::_Orphan_all(&this->drawingStringsQueue);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<DebugString>>>(v3->_Myfirst, v3->_Mylast);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  v4 = &this->drawingLinesQueue;
  if ( this->drawingLinesQueue._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->drawingLinesQueue);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->drawingLinesQueue._Mylast = 0;
    this->drawingLinesQueue._Myend = 0;
  }
  std::_Tree<std::_Tmap_traits<int,DebugString,std::less<int>,std::allocator<std::pair<int const,DebugString>>,0>>::erase(
    &this->stringMap,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const ,DebugString> > > >)this->stringMap._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const ,DebugString> > > >)this->stringMap._Myhead);
  operator delete(this->stringMap._Myhead);
  Concurrency::concurrent_queue<DebugString,std::allocator<DebugString>>::~concurrent_queue<DebugString,std::allocator<DebugString>>(&this->stringQueue);
  LOBYTE(v6) = 2;
  Concurrency::concurrent_queue<DebugLine,std::allocator<DebugLine>>::~concurrent_queue<DebugLine,std::allocator<DebugLine>>(&this->linesQueue);
  LOBYTE(v6) = 1;
  StringBlitter3D::~StringBlitter3D(&this->sb);
  this->IDebugVisualizer::__vftable = (IDebugVisualizer_vtbl *)&IDebugVisualizer::`vftable';
  v6 = -1;
  GameObject::~GameObject(this);
}
DebugVisualizer *DebugVisualizer::`vector deleting destructor'(char *this, unsigned int a2)
{
  return DebugVisualizer::`vector deleting destructor'((DebugVisualizer *)(this - 52), a2);
}
DebugVisualizer *DebugVisualizer::`vector deleting destructor'(DebugVisualizer *this, unsigned int a2)
{
  DebugVisualizer::~DebugVisualizer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DebugVisualizer::addLine(DebugVisualizer *this, const DebugLine *line, int layer)
{
  if ( LODWORD(this->sb.monospace_size) == layer )
  {
    if ( LOBYTE(this[-1].drawingLinesQueue._Mylast) )
      Concurrency::details::_Concurrent_queue_base_v4::_Internal_push(
        (Concurrency::details::_Concurrent_queue_base_v4 *)&this->sb.texture.fileName._Bx._Alias[12],
        line);
  }
}
void DebugVisualizer::addString(DebugVisualizer *this, DebugString *aString, int layer)
{
  if ( LODWORD(this->sb.monospace_size) == layer )
  {
    if ( LOBYTE(this[-1].drawingLinesQueue._Mylast) )
      Concurrency::details::_Concurrent_queue_base_v4::_Internal_push(
        (Concurrency::details::_Concurrent_queue_base_v4 *)&this->sb.offsets._Myend,
        aString);
  }
}
void DebugVisualizer::renderDebugInfo(DebugVisualizer *this, const OnNodeRenderEvent *message)
{
  char *v2; // edi
  std::_Tree_node<std::pair<unsigned int const ,bool>,void *> *v3; // eax
  Concurrency::details::_Concurrent_queue_base_v4 *v4; // edi
  bool v5; // zf
  GraphicsManager *v6; // esi
  const mat44f *v7; // eax
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DebugLine> > > v8; // esi
  float v9; // xmm0_4
  std::map<int,DebugString> *v10; // eax
  DebugString *v11; // esi
  Concurrency::details::_Concurrent_queue_base_v4 *v12; // ecx
  const mat44f *v13; // eax
  std::_Tree_node<std::pair<unsigned int const ,bool>,void *> **v14; // eax
  std::_Tree_node<std::pair<unsigned int const ,bool>,void *> *v15; // esi
  GLRenderer *v16; // ecx
  CameraForward *v17; // eax
  float v18; // xmm1_4
  float v19; // xmm0_4
  CameraForward *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  CameraForward *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  mat44f v27; // [esp-30h] [ebp-164h]
  DebugLine _Val; // [esp+30h] [ebp-104h] BYREF
  mat44f result; // [esp+5Ch] [ebp-D8h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const ,DebugString> > > > v30; // [esp+9Ch] [ebp-98h] BYREF
  vec3f cameraUpVector; // [esp+A4h] [ebp-90h] BYREF
  vec3f cameraForwardVector; // [esp+B0h] [ebp-84h] BYREF
  vec3f offset; // [esp+BCh] [ebp-78h] BYREF
  vec3f v34; // [esp+C8h] [ebp-6Ch]
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > >,std::_Iterator_base0> v35; // [esp+D4h] [ebp-60h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DebugLine> > > v36[2]; // [esp+D8h] [ebp-5Ch] BYREF
  GLRenderer *v37; // [esp+E0h] [ebp-54h]
  __int64 v38; // [esp+E4h] [ebp-50h] BYREF
  float v39; // [esp+ECh] [ebp-48h]
  std::wstring _Right; // [esp+F0h] [ebp-44h] BYREF
  __m128i v41; // [esp+108h] [ebp-2Ch] BYREF
  float v42; // [esp+118h] [ebp-1Ch]
  int v43; // [esp+11Ch] [ebp-18h]
  int _Keyval[5]; // [esp+120h] [ebp-14h] BYREF

  v2 = (char *)this;
  v36[1]._Ptr = (DebugLine *)this;
  if ( this->isActive && message->renderContext->meshFilter->passID == Transparent )
  {
    DebugLine::DebugLine(&_Val);
    v36[0]._Ptr = (DebugLine *)(v2 + 140);
    if ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(
           (Concurrency::details::_Concurrent_queue_base_v4 *)(v2 + 140),
           &_Val) )
    {
      v3 = (std::_Tree_node<std::pair<unsigned int const ,bool>,void *> *)(v2 + 196);
      v4 = (Concurrency::details::_Concurrent_queue_base_v4 *)v36[0]._Ptr;
      v35._Ptr = v3;
      do
      {
        std::vector<DebugLine>::push_back((std::vector<DebugLine> *)v3, &_Val);
        v5 = !Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(v4, &_Val);
        v3 = v35._Ptr;
      }
      while ( !v5 );
      v2 = (char *)v36[1]._Ptr;
    }
    v6 = *(GraphicsManager **)(*((_DWORD *)v2 + 1) + 192);
    v37 = v6->gl;
    v7 = mat44f::createIdentity(&result);
    GraphicsManager::setWorldMatrix(v6, v7);
    GraphicsManager::setDepthMode(*(GraphicsManager **)(*((_DWORD *)v2 + 1) + 192), eDepthOff);
    v8._Ptr = (DebugLine *)*((_DWORD *)v2 + 49);
    while ( v8._Ptr != (DebugLine *)*((_DWORD *)v2 + 50) )
    {
      GLRenderer::color4f(v37, &v8._Ptr->color);
      GLRenderer::begin(v37, eLines, 0);
      GLRenderer::vertex3fv(v37, &v8._Ptr->p0.x);
      GLRenderer::vertex3fv(v37, &v8._Ptr->p1.x);
      GLRenderer::end(v37);
      v9 = v8._Ptr->seconds - *(float *)(*((_DWORD *)v2 + 1) + 32);
      v8._Ptr->seconds = v9;
      if ( v9 > 0.0 )
        ++v8._Ptr;
      else
        std::vector<DebugLine>::erase((std::vector<DebugLine> *)(v2 + 196), v36, v8);
    }
    v38 = 0i64;
    v39 = 0.0;
    _Right._Myres = 7;
    _Right._Mysize = 0;
    _Right._Bx._Buf[0] = 0;
    v41 = 0i64;
    v42 = 0.0;
    v43 = 1065353216;
    _Keyval[0] = 0;
    _Keyval[4] = 0;
    v36[0]._Ptr = (DebugLine *)(v2 + 160);
    if ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(
           (Concurrency::details::_Concurrent_queue_base_v4 *)v2 + 10,
           &v38) )
    {
      v10 = (std::map<int,DebugString> *)(v2 + 188);
      v35._Ptr = (std::_Tree_node<std::pair<unsigned int const ,bool>,void *> *)(v2 + 188);
      do
      {
        v11 = std::map<int,DebugString>::operator[](v10, _Keyval);
        *(_QWORD *)&v11->p.x = v38;
        v11->p.z = v39;
        if ( &v11->text != &_Right )
          std::wstring::assign(&v11->text, &_Right, 0, 0xFFFFFFFF);
        v12 = (Concurrency::details::_Concurrent_queue_base_v4 *)v36[0]._Ptr;
        v11->color = (vec4f)_mm_loadu_si128(&v41);
        v11->seconds = v42;
        LODWORD(v11->scale) = v43;
        v11->stringId = _Keyval[0];
        v5 = !Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(v12, &v38);
        v10 = (std::map<int,DebugString> *)v35._Ptr;
      }
      while ( !v5 );
      v2 = (char *)v36[1]._Ptr;
    }
    v13 = mat44f::createIdentity(&result);
    GraphicsManager::setWorldMatrix(*(GraphicsManager **)(*((_DWORD *)v2 + 1) + 192), v13);
    GraphicsManager::setCullMode(*(GraphicsManager **)(*((_DWORD *)v2 + 1) + 192), eCullNone);
    v36[0]._Ptr = (DebugLine *)(v2 + 188);
    v14 = (std::_Tree_node<std::pair<unsigned int const ,bool>,void *> **)*((_DWORD *)v2 + 47);
    v15 = *v14;
    v35._Ptr = v15;
    if ( v15 != (std::_Tree_node<std::pair<unsigned int const ,bool>,void *> *)v14 )
    {
      v16 = (GLRenderer *)(v2 + 56);
      *(_QWORD *)&v34.x = 0i64;
      v34.z = 0.0;
      v37 = (GLRenderer *)(v2 + 56);
      do
      {
        StringBlitter3D::setColor((StringBlitter3D *)v16, (const vec4f *)&v15[2]._Right);
        v37->__vftable = (GLRenderer_vtbl *)v15[3]._Parent;
        v17 = Sim::getSceneCamera((Sim *)LODWORD(v36[1]._Ptr[4].p0.y));
        LODWORD(v18) = LODWORD(v17->matrix.M32) ^ _xmm;
        LODWORD(v19) = LODWORD(v17->matrix.M33) ^ _xmm;
        LODWORD(cameraForwardVector.x) = LODWORD(v17->matrix.M31) ^ _xmm;
        cameraForwardVector.y = v18;
        cameraForwardVector.z = v19;
        v20 = Sim::getSceneCamera((Sim *)LODWORD(v36[1]._Ptr[4].p0.y));
        v21 = v20->matrix.M22;
        v22 = v20->matrix.M23;
        cameraUpVector.x = v20->matrix.M21;
        cameraUpVector.y = v21;
        cameraUpVector.z = v22;
        v23 = Sim::getSceneCamera((Sim *)LODWORD(v36[1]._Ptr[4].p0.y));
        v24 = v23->matrix.M42;
        v25 = v23->matrix.M43;
        offset.x = v23->matrix.M41;
        offset.y = v24;
        offset.z = v25;
        mat44f::createBillboard(
          &result,
          (const vec3f *)&v15->_Myval.second,
          &offset,
          &cameraUpVector,
          &cameraForwardVector);
        *(__m128i *)&v27.M11 = _mm_loadu_si128((const __m128i *)&result);
        *(__m128i *)&v27.M21 = _mm_loadu_si128((const __m128i *)&result.M21);
        *(__m128i *)&v27.M31 = _mm_loadu_si128((const __m128i *)&result.M31);
        *(__m128i *)&v27.M41 = _mm_loadu_si128((const __m128i *)&result.M41);
        StringBlitter3D::blitString(
          (StringBlitter3D *)v37,
          (const std::wstring *)&v15[1]._Right,
          v27,
          *(float *)&v37->__vftable,
          eAlignCenter,
          v34);
        v26 = *(float *)&v15[3]._Left - *(float *)(LODWORD(v36[1]._Ptr->p0.y) + 32);
        *(float *)&v15[3]._Left = v26;
        if ( v26 > 0.0 )
        {
          std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const,std::vector<AudioEvent *>>>>,std::_Iterator_base0>::operator++(&v35);
          v15 = v35._Ptr;
        }
        else
        {
          std::_Tree<std::_Tmap_traits<int,DebugString,std::less<int>,std::allocator<std::pair<int const,DebugString>>,0>>::erase(
            (std::_Tree<std::_Tmap_traits<int,DebugString,std::less<int>,std::allocator<std::pair<int const ,DebugString> >,0> > *)v36[0]._Ptr,
            &v30,
            (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int const ,DebugString> > > >)v15);
        }
        v16 = v37;
      }
      while ( v15 != (std::_Tree_node<std::pair<unsigned int const ,bool>,void *> *)LODWORD(v36[0]._Ptr->p0.x) );
      v2 = (char *)v36[1]._Ptr;
    }
    GraphicsManager::setDepthMode(*(GraphicsManager **)(*((_DWORD *)v2 + 1) + 192), eDepthNormal);
    if ( _Right._Myres >= 8 )
      operator delete(_Right._Bx._Ptr);
  }
}
void DebugVisualizer::previousLayer(DebugVisualizer *this)
{
  unsigned int v1; // eax

  v1 = this->currentLayer;
  if ( v1 )
    this->currentLayer = v1 % 0x14 - 1;
}
