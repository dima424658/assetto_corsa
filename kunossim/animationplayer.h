#pragma once

class AnimationPlayer
{
void AnimationPlayer::AnimationPlayer(Animation *animation, Node *nodeRoot, AnimationPlayer::AnimationAddingMode addmode);
void AnimationPlayer::activateNodes(Node *root);
void AnimationPlayer::activateNodesRec(Node *n);
double AnimationPlayer::getCurrentPos();
AnimationPlayerSet *AnimationPlayer::getSetByNode(Node *n);
char AnimationPlayer::isAnimatingNode(Node *node);
void AnimationPlayer::setCurrentPos(float p, float force);

};