#pragma once

class UDPSocket
{
void UDPSocket();
void ~UDPSocket();
void setBlockingMode(BOOL imode);
void addListener(std::function<void __cdecl(UDPMessage const &)> listener);

};