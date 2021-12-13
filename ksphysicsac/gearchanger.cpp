#include "gearchanger.h"
void GearChanger::init(GearChanger *this, Car *car)
{
  this->car = car;
  *(_WORD *)&this->lastGearUp = 0;
}
void GearChanger::step(GearChanger *this, float dt)
{
  Car *v3; // ecx
  int v4; // eax
  Car *v5; // ecx
  Car *v6; // ecx

  v3 = this->car;
  *(_WORD *)&this->wasGearUpTriggered = 0;
  v4 = v3->controls.requestedGearIndex;
  if ( v4 == -1 )
  {
    if ( v3->controls.gearUp && !this->lastGearUp )
      this->wasGearUpTriggered = Drivetrain::gearUp(&v3->drivetrain);
    v5 = this->car;
    if ( v5->controls.gearDn && !this->lastGearDn )
      this->wasGearDnTriggered = Drivetrain::gearDown(&v5->drivetrain);
    v6 = this->car;
    this->lastGearUp = v6->controls.gearUp;
    this->lastGearDn = v6->controls.gearDn;
  }
  else
  {
    Drivetrain::setCurrentGear(&v3->drivetrain, v4, 0);
  }
}
