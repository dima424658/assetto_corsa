#pragma once

class UDPPacket
{
void UDPPacket::UDPPacket();
void UDPPacket::UDPPacket(const std::vector<unsigned char> *idata);
void UDPPacket::~UDPPacket();
void UDPPacket::UDPPacket(const UDPMessage *msg);
void UDPPacket::UDPPacket(const UDPPacket *r);
UDPPacket *UDPPacket::operator=(const UDPPacket *r);
unsigned int UDPPacket::getSize();
void UDPPacket::send(UDPSocket *sok);
void UDPPacket::send(TCPSocket *sok);
void UDPPacket::writeStringANSI(const std::wstring *st);
void UDPPacket::writeString(const std::wstring *st);
void UDPPacket::writeString(const std::string *st);
std::wstring *UDPPacket::readStringW(std::wstring *result);
std::wstring *UDPPacket::readBigStringW(std::wstring *result);
std::string *UDPPacket::readString(std::string *result);
bool UDPPacket::isEOF();
unsigned __int8 UDPPacket::read<unsigned char>();
int UDPPacket::read<unsigned short>();
int UDPPacket::read<short>();
unsigned int UDPPacket::read<unsigned int>();
double UDPPacket::read<float>();
vec3f *UDPPacket::read<vec3f>(vec3f *result);
__int64 UDPPacket::read<__int64>();

};