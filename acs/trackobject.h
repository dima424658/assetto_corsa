#pragma once

class TrackObject
{
void TrackObject(std::wstring iname, Sim *isim, Node *iroot);
void resetOrgMatrix();
void setMatrix(mat44f matrix);
void update(float deltaT);

};