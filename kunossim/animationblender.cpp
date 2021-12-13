#include "animationblender.h"
void AnimationBlender::addTargetNode(AnimationBlender *this, Node *n, bool recursive)
{
  int v4; // edi
  Node **v5; // esi
  unsigned int v6; // ebx

  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)this, (ICollisionObject *const *)&n);
  if ( recursive )
  {
    v4 = 0;
    v5 = n->nodes._Myfirst;
    v6 = (unsigned int)((char *)n->nodes._Mylast - (char *)v5 + 3) >> 2;
    if ( v5 > n->nodes._Mylast )
      v6 = 0;
    if ( v6 )
    {
      do
      {
        AnimationBlender::addTargetNode(this, *v5, 1);
        ++v4;
        ++v5;
      }
      while ( v4 != v6 );
    }
  }
}
void AnimationBlender::blendAnimations(AnimationBlender *this, AnimationPlayer *a0, AnimationPlayer *a1, float blend)
{
  AnimationBlender::blendAnimations::__l8::<lambda_8d05f414990f2ed894ce6d17ef89418b> _Func; // [esp+0h] [ebp-Ch] BYREF

  _Func.a0 = &a0;
  _Func.a1 = &a1;
  _Func.blend = &blend;
  std::_For_each<Node * *,_lambda_8d05f414990f2ed894ce6d17ef89418b_>(
    this->targetNodes._Myfirst,
    this->targetNodes._Mylast,
    &_Func);
}
