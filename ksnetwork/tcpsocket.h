#pragma once

class TCPSocket
{
void TCPSocket::TCPSocket();
void TCPSocket::~TCPSocket();
BOOL TCPSocket::connect(const IPAddress *target);
void TCPSocket::setBlockingMode(BOOL imode);
void TCPSocket::addListener(std::function<void __cdecl(UDPMessage const &)> listener);
std::vector<unsigned char> *TCPSocket::receivePacket(std::vector<unsigned char> *result);
int TCPSocket::receive(int maxPackets);

};