#include "animationplayer.h"
void AnimationPlayer::AnimationPlayer(AnimationPlayer *this, Animation *animation, Node *nodeRoot, AnimationPlayer::AnimationAddingMode addmode)
{
  AnimationSet *v4; // edi
  AnimationSet *v5; // eax
  int v6; // eax
  int *v7; // esi
  int v8; // ecx
  std::vector<AnimationPlayerSet> *v9; // eax
  AnimationPlayerSet *v10; // ecx
  int v11; // ecx
  int v12; // edx
  const __m128i *v13; // eax
  __m128i *v14; // ecx
  char v15; // al
  int v16; // ecx
  int v17; // [esp+Ch] [ebp-84h] BYREF
  std::vector<quatpos> _Right; // [esp+10h] [ebp-80h] BYREF
  __m128i v19; // [esp+1Ch] [ebp-74h] BYREF
  __m128i v20; // [esp+2Ch] [ebp-64h] BYREF
  __m128i v21; // [esp+3Ch] [ebp-54h] BYREF
  __m128i v22; // [esp+4Ch] [ebp-44h] BYREF
  int v23; // [esp+5Ch] [ebp-34h]
  int *v24; // [esp+60h] [ebp-30h] BYREF
  Animation *v25; // [esp+64h] [ebp-2Ch]
  int v26; // [esp+68h] [ebp-28h]
  int v27; // [esp+6Ch] [ebp-24h]
  int v28; // [esp+70h] [ebp-20h]
  AnimationSet *v29; // [esp+74h] [ebp-1Ch]
  __m128i *v30; // [esp+78h] [ebp-18h]
  const __m128i *v31; // [esp+7Ch] [ebp-14h]
  std::vector<AnimationPlayerSet> *v32; // [esp+80h] [ebp-10h]
  int v33; // [esp+8Ch] [ebp-4h]
  Animation *animationa; // [esp+94h] [ebp+4h]

  v32 = &this->sets;
  this->sets._Myfirst = 0;
  this->sets._Mylast = 0;
  this->sets._Myend = 0;
  this->timeLength = 2.0;
  this->debug = 0;
  this->loopPosition = 0.0;
  this->currentPos = -1.0;
  v4 = animation->sets._Myfirst;
  v5 = animation->sets._Mylast;
  v33 = 0;
  v29 = v5;
  if ( v4 == v5 )
    return;
  do
  {
    v24 = 0;
    v25 = 0;
    v26 = 0;
    LOBYTE(v33) = 1;
    nodeRoot->findChildrenByName(nodeRoot, (const std::wstring *)v4, (std::vector<Node *> *)&v24);
    v6 = (int)v25;
    v7 = v24;
    animationa = v25;
    if ( v24 == (int *)v25 )
      goto LABEL_21;
    do
    {
      v8 = *v7;
      if ( !v4->isAnimated && addmode )
        goto LABEL_19;
      _Right._Myfirst = 0;
      _Right._Mylast = 0;
      _Right._Myend = 0;
      v17 = v8;
      LOBYTE(v33) = 2;
      v19 = 0i64;
      v20 = 0i64;
      v21 = 0i64;
      v22 = 0i64;
      std::vector<quatpos>::operator=(&_Right, &v4->frames);
      LOBYTE(v23) = 1;
      v9 = v32;
      LOBYTE(v33) = 3;
      v10 = v32->_Mylast;
      if ( &v17 >= (int *)v10 || (v10 = v32->_Mylast, v32->_Myfirst > (AnimationPlayerSet *)&v17) )
      {
        if ( v10 == v32->_Myend )
        {
          std::vector<AnimationPlayerSet>::_Reserve(v32, 1u);
          v9 = v32;
        }
        v16 = (int)v9->_Mylast;
        v30 = (__m128i *)v16;
        v27 = v16;
        v28 = v16;
        LOBYTE(v33) = 5;
        if ( !v16 )
          goto LABEL_16;
        *(_DWORD *)v16 = v17;
        std::vector<quatpos>::vector<quatpos>((std::vector<quatpos> *)(v16 + 4), &_Right);
        v14 = v30;
        v30[1] = _mm_loadu_si128(&v19);
        v14[2] = _mm_loadu_si128(&v20);
        v14[3] = _mm_loadu_si128(&v21);
        v14[4] = _mm_loadu_si128(&v22);
        v15 = v23;
      }
      else
      {
        v31 = (const __m128i *)(((char *)&v17 - (char *)v32->_Myfirst) / 84);
        v9 = v32;
        if ( v32->_Mylast == v32->_Myend )
        {
          std::vector<AnimationPlayerSet>::_Reserve(v32, 1u);
          v9 = v32;
        }
        v11 = (int)v9->_Mylast;
        v30 = (__m128i *)v11;
        v28 = v11;
        v27 = v11;
        v12 = (int)&v9->_Myfirst[(_DWORD)v31];
        v31 = (const __m128i *)v12;
        LOBYTE(v33) = 4;
        if ( !v11 )
          goto LABEL_16;
        *(_DWORD *)v11 = *(_DWORD *)v12;
        std::vector<quatpos>::vector<quatpos>(
          (std::vector<quatpos> *)(v11 + 4),
          (const std::vector<quatpos> *)(v12 + 4));
        v13 = v31;
        v14 = v30;
        v30[1] = _mm_loadu_si128(v31 + 1);
        v14[2] = _mm_loadu_si128(v13 + 2);
        v14[3] = _mm_loadu_si128(v13 + 3);
        v14[4] = _mm_loadu_si128(v13 + 4);
        v15 = v13[5].m128i_i8[0];
      }
      v14[5].m128i_i8[0] = v15;
      v9 = v32;
LABEL_16:
      ++v9->_Mylast;
      LOBYTE(v33) = 1;
      if ( _Right._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&_Right);
        operator delete(_Right._Myfirst);
      }
      v6 = (int)animationa;
LABEL_19:
      ++v7;
    }
    while ( v7 != (int *)v6 );
    v7 = v24;
LABEL_21:
    LOBYTE(v33) = 0;
    if ( v7 )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v24);
      operator delete(v24);
      v24 = 0;
      v25 = 0;
      v26 = 0;
    }
    ++v4;
  }
  while ( v4 != v29 );
}
void AnimationPlayer::activateNodes(AnimationPlayer *this, Node *root)
{
  AnimationPlayerSet *v3; // edx
  AnimationPlayerSet *i; // eax
  AnimationPlayerSet *v5; // ecx
  AnimationPlayerSet *j; // eax
  Node **v7; // esi
  int v8; // edi
  unsigned int v9; // ebp

  v3 = this->sets._Mylast;
  for ( i = this->sets._Myfirst; i != v3; ++i )
    i->isActive = 0;
  v5 = this->sets._Mylast;
  for ( j = this->sets._Myfirst; j != v5; ++j )
  {
    if ( j->target == root )
      j->isActive = 1;
  }
  v7 = root->nodes._Myfirst;
  v8 = 0;
  v9 = (unsigned int)((char *)root->nodes._Mylast - (char *)v7 + 3) >> 2;
  if ( v7 > root->nodes._Mylast )
    v9 = 0;
  if ( v9 )
  {
    do
    {
      AnimationPlayer::activateNodesRec(this, *v7);
      ++v8;
      ++v7;
    }
    while ( v8 != v9 );
  }
}
void AnimationPlayer::activateNodesRec(AnimationPlayer *this, Node *n)
{
  AnimationPlayerSet *v3; // edx
  AnimationPlayerSet *i; // eax
  int v5; // edi
  Node **v6; // esi
  unsigned int v7; // ebx

  v3 = this->sets._Mylast;
  for ( i = this->sets._Myfirst; i != v3; ++i )
  {
    if ( i->target == n )
      i->isActive = 1;
  }
  v5 = 0;
  v6 = n->nodes._Myfirst;
  v7 = (unsigned int)((char *)n->nodes._Mylast - (char *)v6 + 3) >> 2;
  if ( v6 > n->nodes._Mylast )
    v7 = 0;
  if ( v7 )
  {
    do
    {
      AnimationPlayer::activateNodesRec(this, *v6);
      ++v5;
      ++v6;
    }
    while ( v5 != v7 );
  }
}
double AnimationPlayer::getCurrentPos(AnimationPlayer *this)
{
  return this->currentPos;
}
AnimationPlayerSet *AnimationPlayer::getSetByNode(AnimationPlayer *this, Node *n)
{
  AnimationPlayerSet *v2; // eax
  AnimationPlayerSet *v3; // ecx
  AnimationPlayerSet *v5; // ecx

  v2 = this->sets._Myfirst;
  v3 = this->sets._Mylast;
  if ( v2 == v3 )
    return 0;
  while ( v2->target != n )
  {
    if ( ++v2 == v3 )
      return 0;
  }
  v5 = 0;
  if ( v2->isActive )
    v5 = v2;
  return v5;
}
char AnimationPlayer::isAnimatingNode(AnimationPlayer *this, Node *node)
{
  AnimationPlayerSet *v2; // eax
  AnimationPlayerSet *v3; // ecx

  v2 = this->sets._Myfirst;
  v3 = this->sets._Mylast;
  if ( v2 == v3 )
    return 0;
  while ( v2->target != node || !v2->isActive )
  {
    if ( ++v2 == v3 )
      return 0;
  }
  return 1;
}
void AnimationPlayer::setCurrentPos(AnimationPlayer *this, float p, float force)
{
  AnimationPlayerSet *v4; // ebx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  unsigned int v8; // edi
  int v9; // ebp
  float v10; // xmm4_4
  int v11; // ecx
  __int64 v12; // rax
  int frame; // [esp+28h] [ebp-14h] BYREF
  int frame2; // [esp+2Ch] [ebp-10h] BYREF
  AnimationPlayer::setCurrentPos::__l24::<lambda_72c7f015b21abe199def856aa3c8c7f8> _Func; // [esp+30h] [ebp-Ch] BYREF

  v4 = this->sets._Myfirst;
  if ( this->sets._Myfirst == this->sets._Mylast )
    return;
  v5 = FLOAT_1_0;
  v6 = p;
  if ( p > 1.0 )
  {
    v6 = FLOAT_1_0;
LABEL_6:
    p = v6;
    goto LABEL_7;
  }
  if ( p < 0.0 )
  {
    v6 = 0.0;
    goto LABEL_6;
  }
LABEL_7:
  if ( v6 != this->currentPos || LOBYTE(force) )
  {
    v7 = (float)(v4->frames._Mylast - v4->frames._Myfirst) * v6;
    v8 = (int)v7;
    frame = (int)v7;
    v9 = (int)v7 + 1;
    frame2 = v9;
    v10 = v7 - (float)(int)v7;
    if ( v10 <= 1.0 )
    {
      if ( v10 >= 0.0 )
        v5 = v10;
      else
        v5 = 0.0;
    }
    force = v5;
    v11 = (char *)v4->frames._Mylast - (char *)v4->frames._Myfirst;
    if ( v8 >= ((int)((unsigned __int64)(1717986919i64 * v11) >> 32) >> 4)
             + ((unsigned int)((unsigned __int64)(1717986919i64 * v11) >> 32) >> 31)
             - 1 )
    {
      v5 = 0.0;
      v8 = ((int)((unsigned __int64)(1717986919i64 * ((char *)v4->frames._Mylast - (char *)v4->frames._Myfirst)) >> 32) >> 4)
         - 1
         + ((unsigned int)((unsigned __int64)(1717986919i64 * ((char *)v4->frames._Mylast - (char *)v4->frames._Myfirst)) >> 32) >> 31);
      frame = v8;
      v12 = 1717986919i64 * ((char *)v4->frames._Mylast - (char *)v4->frames._Myfirst);
      force = 0.0;
      v9 = (SHIDWORD(v12) >> 4) + (HIDWORD(v12) >> 31) - 1;
      frame2 = v9;
    }
    if ( v6 <= 0.0 )
    {
      v8 = 0;
      v9 = 1;
      v5 = 0.0;
      frame = 0;
      frame2 = 1;
      force = 0.0;
    }
    if ( this->debug )
      _printf("pp:%f f0:%d f1:%d blend:%f\n", v6, v8, v9, v5);
    _Func.frame = &frame;
    _Func.frame2 = &frame2;
    _Func.blend = &force;
    std::_For_each<AnimationPlayerSet *,_lambda_72c7f015b21abe199def856aa3c8c7f8_>(
      (__m128i)0i64,
      this->sets._Myfirst,
      this->sets._Mylast,
      &_Func);
    this->currentPos = p;
  }
}
