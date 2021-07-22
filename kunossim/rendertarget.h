#pragma once

class RenderTarget
{
void RenderTarget(GraphicsManager *graphics, eRenderTargetFormat fmt, unsigned int iwidth, unsigned int iheight, bool hasColor, bool hasDepth, int mips);
void ~RenderTarget();
void clear();

};