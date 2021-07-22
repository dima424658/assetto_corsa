#include "suspensionanimator.h
void SuspensionAnimator::SuspensionAnimator(SuspensionAnimator *this, CarAvatar *acar)
{
  Animation *v3; // edi
  Game *v4; // eax
  GraphicsManager *v5; // eax
  Event<OnReplayStatusChanged> *v6; // ecx
  CarAvatar *v7; // eax
  Sim *v8; // eax
  std::wstring *v9; // eax
  const std::wstring *v10; // esi
  int v11; // ebx
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  std::wstring v15; // [esp-1Ch] [ebp-E4h] BYREF
  Game *v16; // [esp-4h] [ebp-CCh]
  SuspensionAnimator *v17; // [esp+24h] [ebp-A4h]
  std::wstring v18; // [esp+28h] [ebp-A0h] BYREF
  std::wstring v19; // [esp+40h] [ebp-88h] BYREF
  std::wstring result; // [esp+58h] [ebp-70h] BYREF
  std::wstring v21; // [esp+70h] [ebp-58h] BYREF
  std::wstring fn; // [esp+88h] [ebp-40h] BYREF
  std::wstring folder; // [esp+A0h] [ebp-28h] BYREF
  int v24; // [esp+C4h] [ebp-4h]

  v17 = this;
  v16 = acar->game;
  v15._Myres = 7;
  v15._Mysize = 0;
  v15._Bx._Buf[0] = 0;
  std::wstring::assign(&v15, L"SUSPENSION_ANIMATOR", 0x13u);
  GameObject::GameObject(this, v15, v16);
  this->ISuspensionAvatar::__vftable = (ISuspensionAvatar_vtbl *)&ISuspensionAvatar::`vftable';
  v3 = this->animations;
  v16 = (Game *)std::vector<AnimationSet>::_Tidy;
  v15._Myres = (unsigned int)std::vector<MaterialVar *>::vector<MaterialVar *>;
  this->GameObject::__vftable = (SuspensionAnimator_vtbl *)&SuspensionAnimator::`vftable'{for `GameObject'};
  this->ISuspensionAvatar::__vftable = (ISuspensionAvatar_vtbl *)&SuspensionAnimator::`vftable'{for `ISuspensionAvatar'};
  v4 = acar->game;
  v15._Mysize = 4;
  *(_DWORD *)&v15._Bx._Alias[12] = 12;
  *(_DWORD *)&v15._Bx._Alias[8] = this->animations;
  v5 = v4->graphics;
  v24 = 0;
  this->graphics = v5;
  this->car = acar;
  `eh vector constructor iterator'(
    *(void **)&v15._Bx._Alias[8],
    *(unsigned int *)&v15._Bx._Alias[12],
    v15._Mysize,
    (void (*)(void *))v15._Myres,
    (void (*)(void *))v16);
  this->lods._Myfirst = 0;
  this->lods._Mylast = 0;
  this->lods._Myend = 0;
  v16 = (Game *)this;
  this->graphicsRadius[0] = 0.0;
  this->graphicsRadius[1] = 0.0;
  v15._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_19b8c5244cf5181909aab20284a9773e_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v15._Bx._Alias[4] = this;
  v15._Mysize = (unsigned int)&v15;
  v6 = &acar->sim->evOnReplayStatusChanged;
  LOBYTE(v24) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v6,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v15,
    v16);
  v16 = (Game *)this;
  v15._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_6e8b95ade28802dea316eb9f9a78de4c_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v15._Bx._Alias[4] = this;
  v15._Mysize = (unsigned int)&v15;
  v7 = this->car;
  LOBYTE(v24) = 2;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v7->sim->evOnPauseModeChanged,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v15,
    this);
  v16 = (Game *)this;
  v15._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_1a7359950317182ada4ef212cfe6e153_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
  *(_DWORD *)&v15._Bx._Alias[4] = this;
  v15._Mysize = (unsigned int)&v15;
  v8 = acar->sim;
  LOBYTE(v24) = 2;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&v8->game->evOnPostUpdate,
    (std::function<void __cdecl(SessionInfo const &)>)v15,
    this);
  v9 = std::operator+<wchar_t>(&result, L"content/cars/", &this->car->unixName);
  LOBYTE(v24) = 6;
  std::operator+<wchar_t>(&folder, v9, L"/animations");
  LOBYTE(v24) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  v10 = fnames;
  result._Bx._Buf[0] = 0;
  v11 = 4;
  do
  {
    v12 = std::operator+<wchar_t>(&v19, &folder, L"/");
    LOBYTE(v24) = 9;
    v13 = std::operator+<wchar_t>(&v21, v12, L"CAR_");
    LOBYTE(v24) = 10;
    v14 = std::operator+<wchar_t>(&v18, v13, v10);
    LOBYTE(v24) = 11;
    std::operator+<wchar_t>(&fn, v14, L".ksanim");
    if ( v18._Myres >= 8 )
      operator delete(v18._Bx._Ptr);
    v18._Myres = 7;
    v18._Mysize = 0;
    v18._Bx._Buf[0] = 0;
    if ( v21._Myres >= 8 )
      operator delete(v21._Bx._Ptr);
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    LOBYTE(v24) = 15;
    if ( v19._Myres >= 8 )
      operator delete(v19._Bx._Ptr);
    v19._Myres = 7;
    v19._Bx._Buf[0] = 0;
    v19._Mysize = 0;
    Animation::load(v3, &fn);
    LOBYTE(v24) = 8;
    if ( fn._Myres >= 8 )
      operator delete(fn._Bx._Ptr);
    ++v10;
    ++v3;
    --v11;
  }
  while ( v11 );
  if ( folder._Myres >= 8 )
    operator delete(folder._Bx._Ptr);
}
void SuspensionAnimator::~SuspensionAnimator(SuspensionAnimator *this)
{
  this->GameObject::__vftable = (SuspensionAnimator_vtbl *)&SuspensionAnimator::`vftable'{for `GameObject'};
  this->ISuspensionAvatar::__vftable = (ISuspensionAvatar_vtbl *)&SuspensionAnimator::`vftable'{for `ISuspensionAvatar'};
  if ( this->lods._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lods);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<SuspensionAnimatorLodDef>>>(
      this->lods._Myfirst,
      this->lods._Mylast);
    operator delete(this->lods._Myfirst);
    this->lods._Myfirst = 0;
    this->lods._Mylast = 0;
    this->lods._Myend = 0;
  }
  `eh vector destructor iterator'(
    this->animations,
    0xCu,
    4,
    (void (*)(void *))std::vector<AnimationSet>::_Tidy);
  GameObject::~GameObject(this);
}
SuspensionAnimator *SuspensionAnimator::`scalar deleting destructor'(SuspensionAnimator *this, unsigned int a2)
{
  SuspensionAnimator::~SuspensionAnimator(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SuspensionAnimator::addModel(SuspensionAnimator *this, Node *root)
{
  Node *v3; // ebp
  wchar_t *v4; // eax
  std::wstring *v5; // eax
  __m128i *v6; // edi
  Node **v7; // ebx
  int v8; // esi
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  AnimationPlayer *v12; // eax
  Node *v13; // eax
  const std::wstring *v14; // ebp
  Node_vtbl *v15; // eax
  int v16; // eax
  const std::wstring *v17; // ebp
  Node *v18; // eax
  const std::wstring *v19; // ebp
  Node *v20; // eax
  void (*v21)(const char *const, ...); // ebp
  Curve *v22; // ebx
  Node **v23; // edi
  int i; // esi
  float p; // xmm0_4
  Node *v26; // ecx
  float v27; // xmm0_4
  Node *v28; // ebx
  Node **v29; // edi
  Node **v30; // esi
  Node *v31; // ebp
  int v32; // ebx
  AnimationPlayer *v33; // ecx
  char v34; // al
  bool v35; // cl
  Node_vtbl *v36; // eax
  Node **v37; // edi
  Node **j; // esi
  Node *v39; // ebp
  int v40; // ebx
  AnimationPlayer *v41; // ecx
  char v42; // al
  bool v43; // cl
  float v44; // ebx
  float v45; // xmm0_4
  const wchar_t *p_4; // [esp+34h] [ebp-4ACh]
  float animation_8; // [esp+4Ch] [ebp-494h]
  char animation_8a; // [esp+4Ch] [ebp-494h]
  char animation_8b; // [esp+4Ch] [ebp-494h]
  Animation *animation_12; // [esp+50h] [ebp-490h]
  float animation_12a; // [esp+50h] [ebp-490h]
  std::vector<Node *> transmissionNodes; // [esp+58h] [ebp-488h] BYREF
  float v53; // [esp+64h] [ebp-47Ch]
  TransmissionObject to; // [esp+68h] [ebp-478h] BYREF
  SuspensionAnimatorLodDef lod; // [esp+B0h] [ebp-430h] BYREF
  vec3f lpos; // [esp+440h] [ebp-A0h] BYREF
  int v57; // [esp+450h] [ebp-90h]
  unsigned int v58; // [esp+454h] [ebp-8Ch]
  std::wstring v59; // [esp+458h] [ebp-88h] BYREF
  std::wstring folder; // [esp+470h] [ebp-70h] BYREF
  std::wstring v61; // [esp+488h] [ebp-58h] BYREF
  std::wstring result; // [esp+4A0h] [ebp-40h] BYREF
  std::wstring fn; // [esp+4B8h] [ebp-28h] BYREF
  int v64; // [esp+4DCh] [ebp-4h]

  v53 = *(float *)&this;
  v3 = root;
  SuspensionAnimatorLodDef::SuspensionAnimatorLodDef(&lod);
  v4 = this->name._Bx._Ptr;
  v64 = 0;
  lod.model = root;
  v5 = std::operator+<wchar_t>(&result, L"content/cars/", (const std::wstring *)(v4 + 88));
  LOBYTE(v64) = 1;
  std::operator+<wchar_t>(&folder, v5, L"/animations");
  LOBYTE(v64) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  v6 = (__m128i *)lod.orgWheelMatrix;
  result._Mysize = 0;
  v7 = lod.hubs;
  animation_12 = (Animation *)&this->name._Bx._Alias[4];
  v8 = 0;
  while ( 1 )
  {
    v9 = std::operator+<wchar_t>(&v61, &folder, L"/");
    LOBYTE(v64) = 4;
    v10 = std::operator+<wchar_t>(&v59, v9, L"CAR_");
    LOBYTE(v64) = 5;
    v11 = std::operator+<wchar_t>((std::wstring *)&lpos, v10, &fnames[v8]);
    LOBYTE(v64) = 6;
    std::operator+<wchar_t>(&fn, v11, L".ksanim");
    if ( v58 >= 8 )
      operator delete(LODWORD(lpos.x));
    v58 = 7;
    v57 = 0;
    LOWORD(lpos.x) = 0;
    if ( v59._Myres >= 8 )
      operator delete(v59._Bx._Ptr);
    v59._Myres = 7;
    v59._Mysize = 0;
    v59._Bx._Buf[0] = 0;
    LOBYTE(v64) = 10;
    if ( v61._Myres >= 8 )
      operator delete(v61._Bx._Ptr);
    v61._Myres = 7;
    v61._Mysize = 0;
    v61._Bx._Buf[0] = 0;
    v12 = (AnimationPlayer *)operator new(28);
    LOBYTE(v64) = 11;
    if ( v12 )
      AnimationPlayer::AnimationPlayer(v12, animation_12, v3, eOnlyAnimated);
    else
      v13 = 0;
    v14 = &hnames[v8];
    *(v7 - 4) = v13;
    v15 = root->__vftable;
    LOBYTE(v64) = 10;
    v16 = (int)v15->findChildByName(root, &hnames[v8], 1);
    *v7 = (Node *)v16;
    if ( v16 )
    {
      v6[-16] = _mm_loadu_si128((const __m128i *)(v16 + 4));
      v6[-15] = _mm_loadu_si128((const __m128i *)(v16 + 20));
      v6[-14] = _mm_loadu_si128((const __m128i *)(v16 + 36));
      v6[-13] = _mm_loadu_si128((const __m128i *)(v16 + 52));
    }
    else
    {
      if ( *(unsigned int *)((char *)&hnames[0]._Myres + v8 * 24) >= 8 )
        v14 = (const std::wstring *)v14->_Bx._Ptr;
      _printf("ERROR: SUSPENSION NOT FOUND: %S\n", v14->_Bx._Buf);
    }
    v17 = &wnames[v8];
    v18 = root->findChildByName(root, &wnames[v8], 1);
    v7[4] = v18;
    if ( v18 )
    {
      *v6 = _mm_loadu_si128((const __m128i *)&v18->matrix);
      v6[1] = _mm_loadu_si128((const __m128i *)&v18->matrix.M21);
      v6[2] = _mm_loadu_si128((const __m128i *)&v18->matrix.M31);
      v6[3] = _mm_loadu_si128((const __m128i *)&v18->matrix.M41);
    }
    else
    {
      if ( *(unsigned int *)((char *)&wnames[0]._Myres + v8 * 24) >= 8 )
        v17 = (const std::wstring *)v17->_Bx._Ptr;
      _printf("ERROR:, WHEEL %S NOT FOUND\n", v17->_Bx._Buf);
    }
    v19 = &discNames_0[v8];
    v7[140] = 0;
    v20 = root->findChildByName(root, &discNames_0[v8], 1);
    v7[8] = v20;
    if ( v20 )
    {
      v21 = (void (*)(const char *const, ...))_printf;
    }
    else
    {
      if ( *(unsigned int *)((char *)&discNames_0[0]._Myres + v8 * 24) >= 8 )
        v19 = (const std::wstring *)v19->_Bx._Ptr;
      p_4 = (const wchar_t *)v19;
      v21 = (void (*)(const char *const, ...))_printf;
      _printf("WARNING, DISC %S\n NOT FOUND\n", p_4);
    }
    LOBYTE(v64) = 3;
    if ( fn._Myres >= 8 )
      operator delete(fn._Bx._Ptr);
    ++animation_12;
    ++v8;
    v6 += 4;
    ++v7;
    if ( v8 >= 4 )
      break;
    v3 = root;
  }
  v22 = lod.heightCurves;
  animation_8 = 0.0;
  v23 = lod.wheels;
  for ( i = 0; i < 4; ++i )
  {
    p = 0.0;
    animation_12a = 0.0;
    do
    {
      AnimationPlayer::setCurrentPos((AnimationPlayer *)*(v23 - 8), p, COERCE_FLOAT(1));
      v26 = *v23;
      *(_QWORD *)v59._Bx._Buf = 0i64;
      *(_DWORD *)&v59._Bx._Alias[8] = 0;
      Node::localToWorld(v26, &lpos, (const vec3f *)&v59);
      Curve::addValue(v22, lpos.y, animation_12a);
      v27 = animation_12a;
      if ( animation_12a > 0.0 && animation_8 > lpos.y )
      {
        v21("ERROR: SUSPENSION ANIMATION %d IS UP DOWN, SHOULD BE DOWN UP\n", i);
        v27 = animation_12a;
      }
      p = v27 + 0.050000001;
      animation_8 = lpos.y;
      animation_12a = p;
    }
    while ( p <= 1.0 );
    ++v23;
    ++v22;
  }
  transmissionNodes._Myfirst = 0;
  transmissionNodes._Mylast = 0;
  transmissionNodes._Myend = 0;
  LOBYTE(v64) = 12;
  v58 = 7;
  v57 = 0;
  LOWORD(lpos.x) = 0;
  std::wstring::assign((std::wstring *)&lpos, L"TRANSMISSION_L_", 0xFu);
  v28 = root;
  LOBYTE(v64) = 13;
  root->findChildrenByPrefix(root, (const std::wstring *)&lpos, &transmissionNodes);
  LOBYTE(v64) = 12;
  if ( v58 >= 8 )
    operator delete(LODWORD(lpos.x));
  v29 = transmissionNodes._Mylast;
  v30 = transmissionNodes._Myfirst;
  if ( transmissionNodes._Myfirst != transmissionNodes._Mylast )
  {
    do
    {
      v31 = *v30;
      to.node = v31;
      v32 = 0;
      animation_8a = 1;
      *(_WORD *)&to.useOrgMatrix = 257;
      *(__m128i *)&to.orgMatrix.M11 = _mm_loadu_si128((const __m128i *)&v31->matrix);
      *(__m128i *)&to.orgMatrix.M21 = _mm_loadu_si128((const __m128i *)&v31->matrix.M21);
      *(__m128i *)&to.orgMatrix.M31 = _mm_loadu_si128((const __m128i *)&v31->matrix.M31);
      *(__m128i *)&to.orgMatrix.M41 = _mm_loadu_si128((const __m128i *)&v31->matrix.M41);
      do
      {
        v33 = lod.players[v32];
        if ( v33 )
        {
          v34 = AnimationPlayer::isAnimatingNode(v33, v31);
          v35 = animation_8a;
          if ( v34 )
            v35 = 0;
          animation_8a = v35;
          to.useOrgMatrix = v35;
        }
        ++v32;
      }
      while ( v32 < 4 );
      std::vector<TransmissionObject>::push_back(&lod.transmissionObjects, &to);
      ++v30;
    }
    while ( v30 != v29 );
    v28 = root;
  }
  std::_Container_base0::_Orphan_all(&transmissionNodes);
  transmissionNodes._Mylast = transmissionNodes._Myfirst;
  v58 = 7;
  v57 = 0;
  LOWORD(lpos.x) = 0;
  std::wstring::assign((std::wstring *)&lpos, L"TRANSMISSION_R_", 0xFu);
  v36 = v28->__vftable;
  LOBYTE(v64) = 14;
  v36->findChildrenByPrefix(v28, (const std::wstring *)&lpos, &transmissionNodes);
  LOBYTE(v64) = 12;
  if ( v58 >= 8 )
    operator delete(LODWORD(lpos.x));
  v37 = transmissionNodes._Mylast;
  for ( j = transmissionNodes._Myfirst; j != v37; ++j )
  {
    v39 = *j;
    to.node = v39;
    v40 = 0;
    animation_8b = 1;
    *(_WORD *)&to.useOrgMatrix = 1;
    *(__m128i *)&to.orgMatrix.M11 = _mm_loadu_si128((const __m128i *)&v39->matrix);
    *(__m128i *)&to.orgMatrix.M21 = _mm_loadu_si128((const __m128i *)&v39->matrix.M21);
    *(__m128i *)&to.orgMatrix.M31 = _mm_loadu_si128((const __m128i *)&v39->matrix.M31);
    *(__m128i *)&to.orgMatrix.M41 = _mm_loadu_si128((const __m128i *)&v39->matrix.M41);
    do
    {
      v41 = lod.players[v40];
      if ( v41 )
      {
        v42 = AnimationPlayer::isAnimatingNode(v41, v39);
        v43 = animation_8b;
        if ( v42 )
          v43 = 0;
        animation_8b = v43;
        to.useOrgMatrix = v43;
      }
      ++v40;
    }
    while ( v40 < 4 );
    std::vector<TransmissionObject>::push_back(&lod.transmissionObjects, &to);
  }
  v44 = v53;
  std::vector<SuspensionAnimatorLodDef>::push_back((std::vector<SuspensionAnimatorLodDef> *)(LODWORD(v53) + 60), &lod);
  if ( (*(_DWORD *)(LODWORD(v44) + 64) - *(_DWORD *)(LODWORD(v44) + 60)) / 912 == 1 )
  {
    *(float *)(LODWORD(v44) + 72) = get_node_radius((Node *)*(_DWORD *)(*(_DWORD *)(LODWORD(v44) + 60) + 32), 0.0);
    v53 = get_node_radius((Node *)*(_DWORD *)(*(_DWORD *)(LODWORD(v44) + 60) + 40), 0.0);
    v45 = v53;
    *(float *)(LODWORD(v44) + 76) = v53;
    _printf("GRAPHICS RADIUS: %f %f\n", *(float *)(LODWORD(v44) + 72), v45);
  }
  LOBYTE(v64) = 3;
  if ( transmissionNodes._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&transmissionNodes);
    operator delete(transmissionNodes._Myfirst);
    transmissionNodes._Myfirst = 0;
    transmissionNodes._Mylast = 0;
    transmissionNodes._Myend = 0;
  }
  if ( folder._Myres >= 8 )
    operator delete(folder._Bx._Ptr);
  folder._Myres = 7;
  folder._Mysize = 0;
  folder._Bx._Buf[0] = 0;
  v64 = 15;
  if ( lod.transmissionObjects._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&lod.transmissionObjects);
    operator delete(lod.transmissionObjects._Myfirst);
    lod.transmissionObjects._Myfirst = 0;
    lod.transmissionObjects._Mylast = 0;
    lod.transmissionObjects._Myend = 0;
  }
  v64 = -1;
  `eh vector destructor iterator'(lod.heightCurves, 0x4Cu, 4, (void (*)(void *))Curve::~Curve);
}
double SuspensionAnimator::getGraphicsRadius(SuspensionAnimator *this, int index)
{
  return *((float *)&this->animations[0].sets._Myend + index);
}
Node *SuspensionAnimator::getSusTransform(SuspensionAnimator *this, int index)
{
  return *(Node **)&this->car->name._Bx._Alias[4 * index + 8];
}
Node *SuspensionAnimator::getSusTransform(SuspensionAnimator *this, int lodIndex, int index)
{
  return this->lods._Myfirst[lodIndex].hubs[index];
}
Node *SuspensionAnimator::getWheelTransform(SuspensionAnimator *this, int index)
{
  return (Node *)*((_DWORD *)&this->car->isActive + index);
}
Node *SuspensionAnimator::getWheelTransform(SuspensionAnimator *this, int lodIndex, int index)
{
  return this->lods._Myfirst[lodIndex].wheels[index];
}
void SuspensionAnimator::suspensionAnimatorUpdate(SuspensionAnimator *this, float dt)
{
  SuspensionAnimator *v2; // edi
  float v3; // xmm0_4
  int v4; // esi
  int v5; // eax
  CarAvatar *v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm2_4
  char *v9; // esi
  SuspensionAnimatorLodDef *v10; // eax
  int v11; // ecx
  unsigned int v12; // eax
  int v13; // esi
  CarAvatar *v14; // ecx
  int v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  int v18; // ecx
  float v19; // xmm0_4
  int v20; // esi
  float v21; // xmm5_4
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  int v24; // esi
  int v25; // ecx
  int v26; // ecx
  float v27; // xmm0_4
  SuspensionAnimatorLodDef *v28; // ecx
  float v29; // xmm3_4
  __m128 *v30; // eax
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  SuspensionAnimatorLodDef *v34; // eax
  int v35; // ecx
  int v36; // eax
  SuspensionAnimatorLodDef *v37; // esi
  int v38; // edi
  TransmissionObject *v39; // esi
  int v40; // ecx
  float v41; // xmm0_4
  float v42; // xmm3_4
  DirectX::XMMATRIX *v43; // ecx
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm3
  float ref; // [esp+0h] [ebp-1B8h]
  int v48; // [esp+8h] [ebp-1B0h]
  int v49; // [esp+Ch] [ebp-1ACh]
  int v50; // [esp+1Ch] [ebp-19Ch]
  unsigned int v51; // [esp+1Ch] [ebp-19Ch]
  int v52; // [esp+1Ch] [ebp-19Ch]
  Node *v53; // [esp+1Ch] [ebp-19Ch]
  int v54; // [esp+20h] [ebp-198h]
  int v55; // [esp+20h] [ebp-198h]
  int v56; // [esp+20h] [ebp-198h]
  TransmissionObject *i; // [esp+20h] [ebp-198h]
  int v58; // [esp+24h] [ebp-194h]
  float v59; // [esp+24h] [ebp-194h]
  float v60; // [esp+24h] [ebp-194h]
  float v61; // [esp+28h] [ebp-190h]
  int v62; // [esp+28h] [ebp-190h]
  int v63; // [esp+28h] [ebp-190h]
  int v64; // [esp+2Ch] [ebp-18Ch]
  bool v65; // [esp+33h] [ebp-185h]
  int v66; // [esp+34h] [ebp-184h]
  unsigned int v67; // [esp+38h] [ebp-180h]
  __m128 v69; // [esp+40h] [ebp-178h]
  __m128 v70; // [esp+40h] [ebp-178h]
  __m128 v71; // [esp+40h] [ebp-178h]
  __int128 v72; // [esp+50h] [ebp-168h]
  __int128 v73; // [esp+50h] [ebp-168h]
  __int128 v74; // [esp+50h] [ebp-168h]
  _BYTE v75[32]; // [esp+60h] [ebp-158h]
  _BYTE v76[32]; // [esp+60h] [ebp-158h]
  _BYTE v77[32]; // [esp+60h] [ebp-158h]
  float v78; // [esp+80h] [ebp-138h]
  vec3f v79; // [esp+84h] [ebp-134h] BYREF
  TransmissionObject *v80; // [esp+90h] [ebp-128h]
  vec3f pos; // [esp+94h] [ebp-124h] BYREF
  vec3f v82; // [esp+A0h] [ebp-118h] BYREF
  vec3f result; // [esp+ACh] [ebp-10Ch] BYREF
  DirectX::XMMATRIX M2; // [esp+B8h] [ebp-100h] BYREF
  __int128 v85[4]; // [esp+F8h] [ebp-C0h] BYREF
  DirectX::XMMATRIX v86; // [esp+138h] [ebp-80h] BYREF
  DirectX::XMMATRIX v87; // [esp+178h] [ebp-40h] BYREF

  v2 = this;
  if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
    v3 = v2->car->sim->replayManager->timeMult * dt;
  else
    v3 = dt;
  v78 = v3;
  v67 = 0;
  if ( v2->lods._Mylast - v2->lods._Myfirst )
  {
    v4 = 0;
    v66 = 144;
    v64 = 0;
    do
    {
      v5 = 0;
      v50 = 0;
      v58 = 0;
      v54 = 0;
      do
      {
        v6 = v2->car;
        v7 = *(float *)((char *)&v6->physicsState.suspensionMatrix[0].M42 + v5);
        v8 = *(float *)((char *)&v6->physicsState.suspensionMatrix[0].M43 + v5);
        pos.x = *(float *)((char *)&v6->physicsState.suspensionMatrix[0].M41 + v5);
        pos.y = v7;
        pos.z = v8;
        Node::worldToLocal(v6->bodyTransform, &result, &pos);
        v9 = (char *)v2->lods._Myfirst + v4;
        ref = Curve::getValue((Curve *)&v9[v58 + 592], result.y);
        AnimationPlayer::setCurrentPos(*(AnimationPlayer **)&v9[v50], ref, COERCE_FLOAT(1));
        v58 += 76;
        v5 = v54 + 64;
        v50 += 4;
        v4 = v64 * 912;
        v54 = v5;
      }
      while ( v5 < 256 );
      v10 = v2->lods._Myfirst;
      v11 = v64 * 912;
      if ( v10[v64].hubs[0] && v10[v64].hubs[1] )
      {
        v12 = 0;
        v13 = v64 * 912 + 16;
        v51 = 0;
        v55 = v64 * 912 + 16;
        do
        {
          v14 = v2->car;
          v15 = *(_DWORD *)((char *)&v14->physicsState.suspensionMatrix[0].M31 + v12);
          LODWORD(v16) = *(_DWORD *)((char *)&v14->physicsState.suspensionMatrix[0].M33 + v12) ^ _xmm;
          LODWORD(v82.y) = *(_DWORD *)((char *)&v14->physicsState.suspensionMatrix[0].M32 + v12) ^ _xmm;
          v82.z = v16;
          LODWORD(v82.x) = v15 ^ _xmm;
          Node::worldToLocalNormal(v14->bodyTransform, &v79, &v82);
          v79.y = 0.0;
          v17 = fsqrt((float)(v79.z * v79.z) + (float)(v79.x * v79.x));
          if ( v17 != 0.0 )
          {
            v79.z = v79.z * (float)(1.0 / v17);
            v79.x = (float)(1.0 / v17) * v79.x;
            v79.y = (float)(1.0 / v17) * 0.0;
          }
          __libm_sse2_asinf();
          v61 = __libm_sse2_cosf(v48, v49).m128_f32[0];
          v19 = __libm_sse2_sinf(v18).m128_f32[0];
          v69.m128_i32[3] = 0;
          *(_OWORD *)&v75[12] = 0i64;
          v20 = *(int *)((char *)v2->lods._Myfirst->players + v13);
          *(_DWORD *)&v75[28] = 1065353216;
          v21 = (float)(1.0 - v61) * 0.0;
          v22 = *(__m128 *)(v20 + 52);
          *((float *)&v72 + 1) = (float)(1.0 - v61) + v61;
          *(float *)&v75[8] = v61 + v21;
          v69.m128_f32[0] = v61 + v21;
          M2.r[2] = *(__m128 *)(v20 + 36);
          M2.r[3] = v22;
          *(float *)&v72 = v21 - (float)(v19 * 0.0);
          v69.m128_f32[2] = v21 - v19;
          v69.m128_f32[1] = (float)(v19 * 0.0) + v21;
          *(float *)v75 = v19 + v21;
          v23 = *(__m128 *)(v20 + 20);
          *((_QWORD *)&v72 + 1) = v69.m128_u32[1];
          *(float *)&v75[4] = *(float *)&v72;
          M2.r[0] = *(__m128 *)(v20 + 4);
          M2.r[1] = v23;
          *(__m128 *)(v20 + 4) = DirectX::XMMatrixMultiply(M2.r, v69);
          v12 = v51 + 64;
          *(_OWORD *)(v20 + 20) = v72;
          v51 = v12;
          *(_OWORD *)(v20 + 36) = *(_OWORD *)v75;
          *(_OWORD *)(v20 + 52) = *(_OWORD *)&v75[16];
          v13 = v55 + 4;
          v55 += 4;
        }
        while ( v12 < 0x80 );
        v11 = v64 * 912;
      }
      v24 = v11 + 32;
      v52 = 320;
      v25 = 1020;
      v56 = 1020;
      do
      {
        *(float *)((char *)&v2->lods._Myfirst->orgWheelMatrix[3].M31 + v24) = (float)(*(float *)((char *)&v2->car->__vftable
                                                                                               + v25)
                                                                                    * v78)
                                                                            + *(float *)((char *)&v2->lods._Myfirst->orgWheelMatrix[3].M31
                                                                                       + v24);
        v59 = __libm_sse2_cosf(v48, v49).m128_f32[0];
        v27 = __libm_sse2_sinf(v26).m128_f32[0];
        v28 = v2->lods._Myfirst;
        *(_OWORD *)&v76[12] = 0i64;
        v70.m128_i32[3] = 0;
        *(_DWORD *)&v76[28] = 1065353216;
        v62 = *(int *)((char *)v28->players + v24);
        v70.m128_f32[0] = (float)(1.0 - v59) + v59;
        v29 = (float)(1.0 - v59) * 0.0;
        *((float *)&v73 + 1) = v59 + v29;
        *(float *)&v76[8] = v59 + v29;
        v70.m128_f32[1] = (float)(v27 * 0.0) + v29;
        *(float *)&v73 = v29 - (float)(v27 * 0.0);
        *(float *)v76 = v70.m128_f32[1];
        *((_QWORD *)&v73 + 1) = COERCE_UNSIGNED_INT(v27 + v29);
        *(float *)&v76[4] = v29 - v27;
        if ( v62 )
        {
          v30 = (__m128 *)((char *)&v28[v64] + v52);
          v31 = v30[1];
          v32 = v30[2];
          v33 = v30[3];
          v86.r[0] = *v30;
          v86.r[1] = v31;
          v86.r[2] = v32;
          v86.r[3] = v33;
          v70.m128_f32[2] = (float)((float)(1.0 - v59) * 0.0) - (float)(v27 * 0.0);
          *(__m128 *)(v62 + 4) = DirectX::XMMatrixMultiply(v86.r, v70);
          *(_OWORD *)(v62 + 20) = v73;
          *(_OWORD *)(v62 + 36) = *(_OWORD *)v76;
          *(_OWORD *)(v62 + 52) = *(_OWORD *)&v76[16];
        }
        v34 = v2->lods._Myfirst;
        v35 = *(int *)((char *)v34->hubs + v24);
        if ( v35 )
        {
          v36 = *(int *)((char *)v34->players + v24);
          *(__m128i *)(v35 + 4) = _mm_loadu_si128((const __m128i *)(v36 + 4));
          *(__m128i *)(v35 + 20) = _mm_loadu_si128((const __m128i *)(v36 + 20));
          *(__m128i *)(v35 + 36) = _mm_loadu_si128((const __m128i *)(v36 + 36));
          *(__m128i *)(v35 + 52) = _mm_loadu_si128((const __m128i *)(v36 + 52));
        }
        v24 += 4;
        v25 = v56 + 4;
        v52 += 64;
        v56 += 4;
      }
      while ( v52 < 576 );
      v37 = v2->lods._Myfirst;
      v38 = (int)v37[v64].transmissionObjects._Mylast;
      v39 = v37[v64].transmissionObjects._Myfirst;
      v80 = (TransmissionObject *)v38;
      for ( i = v39; v39 != v80; *(_OWORD *)&v53->matrix.M41 = *(_OWORD *)&v77[16] )
      {
        v40 = 2;
        v53 = v39->node;
        v65 = v39->useOrgMatrix;
        if ( !v39->isLeft )
          v40 = 3;
        v63 = v40;
        v60 = __libm_sse2_cosf(v48, v49).m128_f32[0];
        v41 = __libm_sse2_sinf(v63 + v66).m128_f32[0];
        v71.m128_i32[3] = 0;
        *(_OWORD *)&v77[12] = 0i64;
        *(_DWORD *)&v77[28] = 1065353216;
        v71.m128_f32[0] = v60 + (float)(1.0 - v60);
        v42 = (float)(1.0 - v60) * 0.0;
        *((float *)&v74 + 1) = v60 + v42;
        *(float *)&v77[8] = v60 + v42;
        v71.m128_f32[1] = (float)(v41 * 0.0) + v42;
        *(float *)&v74 = v42 - (float)(v41 * 0.0);
        *(float *)v77 = v71.m128_f32[1];
        *((_QWORD *)&v74 + 1) = COERCE_UNSIGNED_INT(v41 + v42);
        *(float *)&v77[4] = v42 - v41;
        if ( v65 )
        {
          v43 = (DirectX::XMMATRIX *)v85;
          v85[0] = (__int128)_mm_loadu_si128((const __m128i *)&i->orgMatrix);
          v85[1] = (__int128)_mm_loadu_si128((const __m128i *)&i->orgMatrix.M21);
          v85[2] = (__int128)_mm_loadu_si128((const __m128i *)&i->orgMatrix.M31);
          v85[3] = (__int128)_mm_loadu_si128((const __m128i *)&i->orgMatrix.M41);
        }
        else
        {
          v43 = &v87;
          v44 = *(__m128 *)&v53->matrix.M21;
          v45 = *(__m128 *)&v53->matrix.M31;
          v46 = *(__m128 *)&v53->matrix.M41;
          v87.r[0] = *(__m128 *)&v53->matrix.M11;
          v87.r[1] = v44;
          v87.r[2] = v45;
          v87.r[3] = v46;
        }
        v39 = i + 1;
        i = v39;
        v71.m128_f32[2] = (float)((float)(1.0 - v60) * 0.0) - (float)(v41 * 0.0);
        *(__m128 *)&v53->matrix.M11 = DirectX::XMMatrixMultiply(v43->r, v71);
        *(_OWORD *)&v53->matrix.M21 = v74;
        *(_OWORD *)&v53->matrix.M31 = *(_OWORD *)v77;
      }
      v2 = this;
      ++v67;
      v4 = v64 * 912 + 912;
      v66 += 228;
      ++v64;
    }
    while ( v67 < this->lods._Mylast - this->lods._Myfirst );
  }
}
