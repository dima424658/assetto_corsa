#pragma once

class SharedMemoryWriter
{
// void __userpurge SharedMemoryWriter::SharedMemoryWriter(@<ecx>, unsigned int a2@<ebx>, Sim *aSim);
SharedMemoryWriter *SharedMemoryWriter::`vector deleting destructor'(unsigned int a2);
char SharedMemoryWriter::initSharedMemory(unsigned int memoryIndex, std::wstring memoryName);
void SharedMemoryWriter::shutdown();
void SharedMemoryWriter::update(float dt);
void SharedMemoryWriter::updatePhysics(const long double *dt);
void SharedMemoryWriter::writeStatic();

};