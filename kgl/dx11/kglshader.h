#pragma once

class KGLShader
{
public:
    KGLShader(const std::wstring* filename, ID3D11Device* device);
    ~KGLShader();

    ID3D10Blob* readBlob(const std::wstring* filename);

    void loadShaderBinary(const std::wstring* filename);
    void createVertexShader(ID3D10Blob* blob);
    void reflectVars(ID3D10Blob* blob, bool isPS);

    void addCBuffer(const std::wstring* name, unsigned int size, unsigned int slot);
    void clearInputLayouts();
};