#pragma once

class AnimationBlender
{
void addTargetNode(Node *n, bool recursive);
void blendAnimations(AnimationPlayer *a0, AnimationPlayer *a1, float blend);

};