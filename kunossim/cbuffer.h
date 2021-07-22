#pragma once

class CBuffer
{
void CBuffer::CBuffer(int islot, int isize);
void CBuffer::CBuffer();
void CBuffer::commit();
void CBuffer::get(float *value, int offset, int size);
void CBuffer::init(int islot, int isize);
void CBuffer::map(void *bdata, int bsize);
void CBuffer::release();
void CBuffer::set(float *value, int offset, int size);
void CBuffer::touch();

};