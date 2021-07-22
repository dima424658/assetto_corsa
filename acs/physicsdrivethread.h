#pragma once

class PhysicsDriveThread
{
void PhysicsDriveThread::PhysicsDriveThread(PhysicsEngine *aphysicsEngine, Game *agame);
void PhysicsDriveThread::~PhysicsDriveThread();
void PhysicsDriveThread::pause();
void PhysicsDriveThread::run();
void PhysicsDriveThread::start();
void PhysicsDriveThread::step();
void PhysicsDriveThread::stop();

};