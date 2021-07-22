#pragma once

class CameraOnBoard
{
// void __userpurge CameraOnBoard::CameraOnBoard(@<ecx>, char a2@<bl>, __m128 a3@<xmm0>, Game *igame, CameraForward *cam, Sim *aSim);
void CameraOnBoard::~CameraOnBoard();
CameraOnBoard *CameraOnBoard::`vector deleting destructor'(unsigned int a2);
void CameraOnBoard::lookBack();
void CameraOnBoard::lookLeftRight(float dt);
void CameraOnBoard::update(float deltaT);

};