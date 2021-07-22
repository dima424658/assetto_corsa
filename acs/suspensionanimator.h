#pragma once

class SuspensionAnimator
{
void SuspensionAnimator::SuspensionAnimator(CarAvatar *acar);
void SuspensionAnimator::~SuspensionAnimator();
void SuspensionAnimator::addModel(Node *root);
double SuspensionAnimator::getGraphicsRadius(int index);
Node *SuspensionAnimator::getSusTransform(int index);
Node *SuspensionAnimator::getSusTransform(int lodIndex, int index);
Node *SuspensionAnimator::getWheelTransform(int index);
Node *SuspensionAnimator::getWheelTransform(int lodIndex, int index);
void SuspensionAnimator::suspensionAnimatorUpdate(float dt);

};