#include "virtualdisplay.h"
void VirtualDisplay::VirtualDisplay(VirtualDisplay *this)
{
  vec2f v; // [esp+18h] [ebp-14h] BYREF
  int v3; // [esp+28h] [ebp-4h]

  this->visibleVertices._Myfirst = 0;
  this->visibleVertices._Mylast = 0;
  this->visibleVertices._Myend = 0;
  v3 = 0;
  this->displayVertices._Myfirst = 0;
  this->displayVertices._Mylast = 0;
  this->displayVertices._Myend = 0;
  this->backDisplayVertex._Myfirst = 0;
  this->backDisplayVertex._Mylast = 0;
  this->backDisplayVertex._Myend = 0;
  this->type._Myres = 7;
  this->type._Mysize = 0;
  this->type._Bx._Buf[0] = 0;
  LOBYTE(v3) = 3;
  this->displayCenter.x = 0.0;
  this->displayCenter.y = 0.0;
  this->margin = 0.0;
  this->screenWidth = 0.0;
  v.x = 0.0;
  v.y = 0.0;
  this->screenDepth = 12.0;
  std::vector<vec2f>::push_back(&this->visibleVertices, &v);
  std::vector<vec2f>::push_back(&this->visibleVertices, &v);
  std::vector<vec2f>::push_back(&this->visibleVertices, &v);
  std::vector<vec2f>::push_back(&this->visibleVertices, &v);
  std::vector<vec2f>::push_back(&this->displayVertices, &v);
  std::vector<vec2f>::push_back(&this->displayVertices, &v);
  std::vector<vec2f>::push_back(&this->displayVertices, &v);
  std::vector<vec2f>::push_back(&this->displayVertices, &v);
  std::vector<vec2f>::push_back(&this->backDisplayVertex, &v);
  std::vector<vec2f>::push_back(&this->backDisplayVertex, &v);
  std::vector<vec2f>::push_back(&this->backDisplayVertex, &v);
  std::vector<vec2f>::push_back(&this->backDisplayVertex, &v);
  std::wstring::assign(&this->type, L"CentralDisplay", 0xEu);
}
void __userpurge VirtualDisplay::updateData(VirtualDisplay *this@<ecx>, float a2@<xmm1>, float a3@<xmm2>, vec2f center)
{
  float v7; // xmm4_4
  vec2f *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  vec2f *v12; // ecx
  float v13; // xmm0_4
  vec2f *v14; // ecx
  float v15; // xmm0_4
  vec2f *v16; // ecx
  float v17; // xmm0_4
  vec2f *v18; // ecx
  float v19; // xmm0_4
  vec2f *v20; // ecx
  float v21; // xmm0_4
  vec2f *v22; // ecx
  float v23; // xmm0_4
  vec2f *v24; // ecx
  float v25; // xmm0_4
  vec2f *v26; // ecx
  float v27; // xmm0_4
  vec2f *v28; // ecx
  float v29; // xmm0_4
  vec2f *v30; // ecx
  float v31; // xmm0_4
  vec2f *v32; // ecx
  float v33; // xmm0_4
  float v34; // [esp+0h] [ebp-8h]

  v7 = this->screenDepth;
  v8 = this->visibleVertices._Myfirst;
  this->displayCenter.x = center.x;
  v9 = this->displayCenter.x - (float)(a3 * 0.5);
  v10 = v7 * 0.5;
  this->displayCenter.y = center.y;
  this->margin = a2;
  this->screenWidth = a3;
  v34 = v9;
  v11 = this->displayCenter.y - v10;
  v8->x = v34;
  v8->y = v11;
  v12 = this->visibleVertices._Myfirst;
  v13 = this->displayCenter.y - v10;
  v12[1].x = (float)(a3 * 0.5) + this->displayCenter.x;
  v12[1].y = v13;
  v14 = this->visibleVertices._Myfirst;
  v15 = this->displayCenter.y + v10;
  v14[2].x = (float)(a3 * 0.5) + this->displayCenter.x;
  v14[2].y = v15;
  v16 = this->visibleVertices._Myfirst;
  v17 = this->displayCenter.y + v10;
  v16[3].x = this->displayCenter.x - (float)(a3 * 0.5);
  v16[3].y = v17;
  v18 = this->displayVertices._Myfirst;
  v19 = this->displayCenter.y - v10;
  v18->x = (float)(this->displayCenter.x - (float)(a3 * 0.5)) - a2;
  v18->y = v19;
  v20 = this->displayVertices._Myfirst;
  v21 = this->displayCenter.y - v10;
  v20[1].x = (float)((float)(a3 * 0.5) + this->displayCenter.x) + a2;
  v20[1].y = v21;
  v22 = this->displayVertices._Myfirst;
  v23 = this->displayCenter.y + v10;
  v22[2].x = (float)((float)(a3 * 0.5) + this->displayCenter.x) + a2;
  v22[2].y = v23;
  v24 = this->displayVertices._Myfirst;
  v25 = this->displayCenter.y + v10;
  v24[3].x = (float)(this->displayCenter.x - (float)(a3 * 0.5)) - a2;
  v24[3].y = v25;
  v26 = this->backDisplayVertex._Myfirst;
  v27 = this->displayCenter.y - 5.0;
  v26->x = (float)((float)(this->displayCenter.x - (float)(a3 * 0.5)) + 5.0) - a2;
  v26->y = v27 - v10;
  v28 = this->backDisplayVertex._Myfirst;
  v29 = this->displayCenter.y - 5.0;
  v28[1].x = (float)((float)((float)(a3 * 0.5) + this->displayCenter.x) - 5.0) + a2;
  v28[1].y = v29 - v10;
  v30 = this->backDisplayVertex._Myfirst;
  v31 = this->displayCenter.y + v10;
  v30[2].x = (float)((float)(a3 * 0.5) + this->displayCenter.x) + a2;
  v30[2].y = v31;
  v32 = this->backDisplayVertex._Myfirst;
  v33 = this->displayCenter.y + v10;
  v32[3].x = (float)(this->displayCenter.x - (float)(a3 * 0.5)) - a2;
  v32[3].y = v33;
}
void VirtualDisplay::~VirtualDisplay(VirtualDisplay *this)
{
  this->visibleVertices._Mylast = this->visibleVertices._Myfirst;
  this->displayVertices._Mylast = this->displayVertices._Myfirst;
  this->backDisplayVertex._Mylast = this->backDisplayVertex._Myfirst;
  if ( this->type._Myres >= 8 )
    operator delete(this->type._Bx._Ptr);
  this->type._Myres = 7;
  this->type._Mysize = 0;
  this->type._Bx._Buf[0] = 0;
  if ( this->backDisplayVertex._Myfirst )
  {
    operator delete(this->backDisplayVertex._Myfirst);
    this->backDisplayVertex._Myfirst = 0;
    this->backDisplayVertex._Mylast = 0;
    this->backDisplayVertex._Myend = 0;
  }
  if ( this->displayVertices._Myfirst )
  {
    operator delete(this->displayVertices._Myfirst);
    this->displayVertices._Myfirst = 0;
    this->displayVertices._Mylast = 0;
    this->displayVertices._Myend = 0;
  }
  if ( this->visibleVertices._Myfirst )
  {
    operator delete(this->visibleVertices._Myfirst);
    this->visibleVertices._Myfirst = 0;
    this->visibleVertices._Mylast = 0;
    this->visibleVertices._Myend = 0;
  }
}
std::wstring *VirtualDisplay::getType(VirtualDisplay *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &this->type, 0, 0xFFFFFFFF);
  return result;
}
