#pragma once

class SystemNotification
{
void SystemNotification(Sim *aSim);
void clearMessage();
void showNotification(const SystemNotificationMode type);
void update(float deltaT);

};