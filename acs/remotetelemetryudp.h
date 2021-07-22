#pragma once

class RemoteTelemetryUDP
{
void RemoteTelemetryUDP::RemoteTelemetryUDP(Sim *aSim, CarAvatar *aCar);
void RemoteTelemetryUDP::listen();
void RemoteTelemetryUDP::onLapUpdateEvent(int carId);
void RemoteTelemetryUDP::sendMessage(sockaddr_in destination, unsigned int socket, const void *data, int size);
void RemoteTelemetryUDP::update(float dt);
void RemoteTelemetryUDP::updateListeners();
void RemoteTelemetryUDP::updateRTCarInfo();

};