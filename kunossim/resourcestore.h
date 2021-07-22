#pragma once

class ResourceStore
{
void ResourceStore(GraphicsManager *rm);
void ~ResourceStore();
Texture *getTexture(Texture *result, const std::wstring *filename, bool onlyExisting);
Texture *getTextureFromBuffer(Texture *result, const std::wstring *name, unsigned __int8 *buffer, int size);
BOOL hasTexture(const std::wstring *name);

};