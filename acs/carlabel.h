#pragma once

class CarLabel
{
void CarLabel(int id, float maxDist, eLabelType type, Sim *aSim);
void ~CarLabel();
CarLabel *`vector deleting destructor'(unsigned int a2);
void resetRects(int width);
void updatePilotData(const CarData *carData, float scale);

};