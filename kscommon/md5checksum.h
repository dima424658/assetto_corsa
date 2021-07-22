#pragma once

class MD5CheckSum
{
MD5CheckSum *finalize();
std::wstring *hexdigest(std::wstring *result);
void transform(const unsigned __int8 *block);
void update(const unsigned __int8 *buf, unsigned int size);

};