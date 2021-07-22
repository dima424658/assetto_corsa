#include "physicscarstateprovider.h
ICarPhysicsStateProvider *PhysicsCarStateProvider::`scalar deleting destructor'(ICarPhysicsStateProvider *this, unsigned int a2)
{
  this->__vftable = (ICarPhysicsStateProvider_vtbl *)&ICarPhysicsStateProvider::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PhysicsCarStateProvider::PhysicsCarStateProvider(PhysicsCarStateProvider *this, Car *car)
{
  this->car = car;
  this->__vftable = (PhysicsCarStateProvider_vtbl *)&PhysicsCarStateProvider::`vftable';
}
void PhysicsCarStateProvider::getPhysicsState(PhysicsCarStateProvider *this, CarPhysicsState *physicsState)
{
  Car::getPhysicsState(this->car, physicsState);
}
void PhysicsCarStateProvider::getWingState(PhysicsCarStateProvider *this, std::vector<WingState> *wingStatus)
{
  Car::getWingState(this->car, wingStatus);
}
