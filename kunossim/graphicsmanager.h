#pragma once

class GraphicsManager
{
// void __userpurge GraphicsManager::GraphicsManager(@<ecx>, __m128 a2@<xmm1>, const VideoSettings *ivideoSettings);
void GraphicsManager::~GraphicsManager();
GraphicsManager *GraphicsManager::`vector deleting destructor'(unsigned int a2);
void GraphicsManager::beginMainRenderPass();
void GraphicsManager::beginScene();
void GraphicsManager::clearRenderTarget(const vec4f *color);
void GraphicsManager::clearRenderTargetDepth(float value);
void GraphicsManager::clearTextureSlot(int slot);
void GraphicsManager::commitShaderChanges();
void GraphicsManager::compile(Node *root);
GLRenderer *GraphicsManager::createGLRenderer(unsigned int maxVertices);
void GraphicsManager::drawPrimitive(unsigned int indicesCount, unsigned int baseIndex, unsigned int baseVertex, unsigned int numVertices);
void GraphicsManager::endMainRenderPass();
void GraphicsManager::endScene();
SystemCBuffers *GraphicsManager::getCBuffer(const std::wstring *name);
std::vector<std::wstring> *GraphicsManager::getErrorStrings(std::vector<std::wstring> *result);
vec3f *GraphicsManager::getLDRColor(vec3f *result, const vec3f *c);
double GraphicsManager::getLDRScale(const vec3f *c);
mat44f *GraphicsManager::getProjectionMatrix(mat44f *result);
// Shader *__userpurge GraphicsManager::getShader@<eax>(@<ecx>, unsigned int a2@<ebx>, const std::wstring *name);
vec3f *GraphicsManager::getShadowMapBias(vec3f *result);
mat44f *GraphicsManager::getViewMatrix(mat44f *result);
mat44f *GraphicsManager::getWorldMatrix(mat44f *result);
void GraphicsManager::initCBuffers();
void GraphicsManager::initRenderFlags();
void GraphicsManager::initSamplerStates();
void GraphicsManager::loadLightingSettings(const std::wstring *filename);
void GraphicsManager::onResize(int width, int height);
void GraphicsManager::overrideSamplerState(SamplerState sampler);
void GraphicsManager::resetRenderStates();
void GraphicsManager::setBlendMode(BlendMode mode);
void GraphicsManager::setCullMode(CullMode mode);
void GraphicsManager::setCustomSunDirection(vec3f sunDirection);
void GraphicsManager::setDepthMode(DepthMode mode);
void GraphicsManager::setDepthTextureRT(unsigned int slot, RenderTarget *rt);
void GraphicsManager::setIB(IndexBuffer *ib);
void GraphicsManager::setProjectionMatrix(const mat44f *matrix);
void GraphicsManager::setRenderTarget(RenderTarget *rt);
void GraphicsManager::setSamplerState();
void GraphicsManager::setScreenRenderTargets();
void GraphicsManager::setScreenSpaceMode();
void GraphicsManager::setShader(Shader *sh);
void GraphicsManager::setShadowMapBias(float b0, float b1, float b2);
void GraphicsManager::setShadowMapMatrix(int level, const mat44f *matrix);
void GraphicsManager::setShadowMapTexture(int level, RenderTarget *rt);
void GraphicsManager::setTexture(int slot, const Texture *tex);
void GraphicsManager::setTextureRT(unsigned int slot, RenderTarget *rt);
void GraphicsManager::setVB(IVertexBuffer *vb);
void GraphicsManager::setViewMatrix(const mat44f *matrix, Camera *camera);
void GraphicsManager::setViewport(int left, int top, int width, int height);
void GraphicsManager::setWorldMatrix(const mat44f *matrix);
void GraphicsManager::updateLightingSetttings();

};