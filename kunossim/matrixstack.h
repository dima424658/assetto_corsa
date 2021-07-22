#pragma once

class MatrixStack
{
void MatrixStack::MatrixStack();
void MatrixStack::~MatrixStack();
mat44f *MatrixStack::getCurrentMatrix(mat44f *result);
void MatrixStack::multMatrix(mat44f *m);
void MatrixStack::popMatrix();
void MatrixStack::pushAndSetMatrix(mat44f *m);
void MatrixStack::reset();

};