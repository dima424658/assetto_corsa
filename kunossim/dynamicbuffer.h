#pragma once

class DynamicBuffer
{
void DynamicBuffer(unsigned int isize);
void ~DynamicBuffer();
void commit(int numberOfVerticesToCommit);
void render(unsigned int startIndex, unsigned int vertexCount);

};