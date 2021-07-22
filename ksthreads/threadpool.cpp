#include "threadpool.h
void ThreadPool::ThreadPool(ThreadPool *this, int inumThreads, std::function<void __cdecl(int)> initFun)
{
  std::deque<Task *> *v4; // esi
  std::_Container_proxy *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  char *v9; // ecx
  std::_Func_base<void,int>_vtbl *v10; // eax
  int v11; // eax
  int (__stdcall **v12)(std::function<void __cdecl(int)> *); // eax
  std::_Func_base<void,int> *v13; // eax
  std::thread *v14; // eax
  char v15[16]; // [esp+10h] [ebp-64h] BYREF
  char *v16; // [esp+20h] [ebp-54h]
  std::function<void __cdecl(int)> *v17; // [esp+28h] [ebp-4Ch]
  std::thread v18; // [esp+2Ch] [ebp-48h] BYREF
  char *v19; // [esp+34h] [ebp-40h]
  ThreadPool *v20; // [esp+38h] [ebp-3Ch]
  WorkerThread _Fx; // [esp+3Ch] [ebp-38h] BYREF
  int v22; // [esp+70h] [ebp-4h]

  v20 = this;
  v22 = 0;
  this->__vftable = (ThreadPool_vtbl *)&ThreadPool::`vftable';
  this->workers._Myfirst = 0;
  this->workers._Mylast = 0;
  this->workers._Myend = 0;
  LOBYTE(v22) = 1;
  v4 = &this->tasks;
  this->stop = 0;
  this->tasks._Myproxy = 0;
  this->tasks._Map = 0;
  this->tasks._Mapsize = 0;
  this->tasks._Myoff = 0;
  this->tasks._Mysize = 0;
  v5 = (std::_Container_proxy *)operator new(8u);
  if ( !v5 )
    std::_Xbad_alloc();
  v4->_Myproxy = v5;
  v5->_Mycont = 0;
  v5->_Myfirstiter = 0;
  v4->_Myproxy->_Mycont = v4;
  LOBYTE(v22) = 2;
  v6 = __Mtx_init(&this->queue_mutex._Mtx, 2);
  if ( v6 )
    std::_Throw_C_error(v6);
  LOBYTE(v22) = 3;
  v7 = __Cnd_init(&this->condition._Cnd);
  if ( v7 )
    std::_Throw_C_error(v7);
  v8 = 0;
  this->numThreads = inumThreads;
  if ( inumThreads > 0 )
  {
    v19 = v15;
    v17 = &_Fx.initFunction;
    do
    {
      v16 = 0;
      LOBYTE(v22) = 5;
      v9 = (char *)initFun._Impl;
      if ( initFun._Impl )
      {
        v10 = initFun._Impl->__vftable;
        if ( (std::function<void __cdecl(int)> *)initFun._Impl == &initFun )
          v11 = ((int (__stdcall *)(char *))v10->_Copy)(v15);
        else
          v11 = ((int (__stdcall *)(_DWORD))v10->_Copy)(0);
        v9 = (char *)v11;
      }
      v16 = v9;
      _Fx.pool = this;
      _Fx.initFunction._Impl = 0;
      LOBYTE(v22) = 7;
      if ( v9 )
      {
        v12 = *(int (__stdcall ***)(std::function<void __cdecl(int)> *))v9;
        if ( v9 == v15 )
          v13 = (std::_Func_base<void,int> *)(*v12)(&_Fx.initFunction);
        else
          v13 = (std::_Func_base<void,int> *)(*v12)(0);
        v9 = v16;
        _Fx.initFunction._Impl = v13;
      }
      else
      {
        _Fx.initFunction._Impl = 0;
      }
      _Fx.thread_id = v8;
      LOBYTE(v22) = 4;
      if ( v9 )
      {
        (*(void (__stdcall **)(bool))(*(_DWORD *)v9 + 16))(v9 != v15);
        v16 = 0;
      }
      LOBYTE(v22) = 8;
      std::thread::thread(&v18, &_Fx);
      LOBYTE(v22) = 9;
      std::vector<std::thread>::push_back(&this->workers, v14);
      LOBYTE(v22) = 8;
      if ( v18._Thr._Id )
        terminate();
      LOBYTE(v22) = 4;
      if ( _Fx.initFunction._Impl )
        ((void (__stdcall *)(bool))_Fx.initFunction._Impl->_Delete_this)(_Fx.initFunction._Impl != (std::_Func_base<void,int> *)&_Fx.initFunction);
      ++v8;
    }
    while ( v8 < this->numThreads );
  }
  v22 = -1;
  if ( initFun._Impl )
    ((void (__stdcall *)(bool))initFun._Impl->_Delete_this)(initFun._Impl != (std::_Func_base<void,int> *)&initFun);
}
ThreadPool *ThreadPool::`vector deleting destructor'(ThreadPool *this, unsigned int a2)
{
  ThreadPool::~ThreadPool(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ThreadPool::~ThreadPool(ThreadPool *this)
{
  std::condition_variable *v2; // ebp
  int v3; // eax
  std::thread *v4; // edi
  std::thread *i; // esi
  std::thread *v6; // edx
  std::thread *v7; // ecx
  std::thread *v8; // eax

  this->__vftable = (ThreadPool_vtbl *)&ThreadPool::`vftable';
  v2 = &this->condition;
  this->stop = 1;
  v3 = __Cnd_broadcast((_Cnd_t)&this->condition);
  if ( v3 )
    std::_Throw_C_error(v3);
  v4 = this->workers._Mylast;
  for ( i = this->workers._Myfirst; i != v4; ++i )
    std::thread::join(i);
  __Cnd_destroy((_Cnd_t)v2);
  __Mtx_destroy((_Mtx_t)&this->queue_mutex);
  std::deque<Task *>::_Tidy(&this->tasks);
  operator delete(this->tasks._Myproxy);
  this->tasks._Myproxy = 0;
  v6 = this->workers._Myfirst;
  if ( v6 )
  {
    v7 = this->workers._Mylast;
    v8 = this->workers._Myfirst;
    if ( v6 != v7 )
    {
      do
      {
        if ( v8->_Thr._Id )
          terminate();
        ++v8;
      }
      while ( v8 != v7 );
    }
    operator delete(this->workers._Myfirst);
    this->workers._Myfirst = 0;
    this->workers._Mylast = 0;
    this->workers._Myend = 0;
  }
}
void ThreadPool::addTask(ThreadPool *this, Task *task)
{
  std::mutex *v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v3 = &this->queue_mutex;
  v4 = __Mtx_lock((_Mtx_t)&this->queue_mutex);
  if ( v4 )
    std::_Throw_C_error(v4);
  std::deque<Task *>::push_back(&this->tasks, &task);
  v5 = __Mtx_unlock((_Mtx_t)v3);
  if ( v5 )
    std::_Throw_C_error(v5);
  v6 = __Cnd_signal((_Cnd_t)&this->condition);
  if ( v6 )
    std::_Throw_C_error(v6);
}
