#pragma once

class Texture
{
void Texture::Texture();
Texture *Texture::operator=(const Texture *__that);
unsigned int Texture::height();
unsigned int Texture::width();
void Texture::Texture(const std::wstring *filename);
void Texture::Texture(const RenderTarget *rt);
void Texture::Texture(unsigned __int8 *buffer, unsigned int size);
void Texture::Texture(unsigned __int8 *buffer, unsigned int width, unsigned int height, PixelFormat aFormat);
void Texture::release();

};