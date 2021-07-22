#pragma once

class TyreBlur
{
void TyreBlur(CarAvatar *acar);
void initTyreMaterials();
void processNode(Node *node, int tyreIndex);
void update(float deltaT);

};