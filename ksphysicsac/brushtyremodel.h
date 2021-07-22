#pragma once

class BrushTyreModel
{
void BrushTyreModel();
double getCFFromSlipAngle(float angle);
BrushOutput *solve(BrushOutput *result, float slip, float friction, float load, float cf1_mix, float asy);
BrushOutput *solveV5(BrushOutput *result, float slip, float load, float asy);

};