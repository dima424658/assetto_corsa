#pragma once

class BrushSlipProvider
{
BrushSlipProvider *BrushSlipProvider::operator=(const BrushSlipProvider *__that);
void BrushSlipProvider::BrushSlipProvider(float maxAngle, float xu, float flex);
void BrushSlipProvider::BrushSlipProvider();
void BrushSlipProvider::~BrushSlipProvider();
void BrushSlipProvider::calcMaximum(float load, float *maximum, float *max_slip);
const TyreSlipInput *BrushSlipProvider::getSlipForce(const TyreSlipInput *input, const TyreSlipInput *useasy, bool useasya);
void BrushSlipProvider::recomputeMaximum();

};