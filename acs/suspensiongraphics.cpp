#include "suspensiongraphics.h
void SuspensionGraphics::SuspensionGraphics(SuspensionGraphics *this, CarAvatar *acar, SuspensionGraphicsDesc *desc)
{
  CarAvatar *v4; // eax
  const vec3f *v5; // eax
  vec3f *v6; // eax
  const vec3f *v7; // eax
  Node *v8; // eax
  std::wstring v9; // [esp-1Ch] [ebp-5Ch] BYREF
  Game *v10; // [esp-4h] [ebp-44h]
  SuspensionGraphics *v11; // [esp+18h] [ebp-28h]
  vec3f result; // [esp+1Ch] [ebp-24h] BYREF
  vec3f v13; // [esp+28h] [ebp-18h] BYREF
  int v14; // [esp+3Ch] [ebp-4h]

  v11 = this;
  v10 = acar->game;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"SUSP_GRAPHICS", 0xDu);
  GameObject::GameObject(this, v9, v10);
  this->car = acar;
  this->__vftable = (SuspensionGraphics_vtbl *)&SuspensionGraphics::`vftable';
  this->dstPivot[0].x = 0.0;
  this->dstPivot[0].y = 0.0;
  this->dstPivot[0].z = 0.0;
  this->dstPivot[1].x = 0.0;
  this->dstPivot[1].y = 0.0;
  this->dstPivot[1].z = 0.0;
  v14 = 0;
  this->srcPivot[0].x = 0.0;
  this->srcPivot[0].y = 0.0;
  this->srcPivot[0].z = 0.0;
  this->srcPivot[1].x = 0.0;
  this->srcPivot[1].y = 0.0;
  this->srcPivot[1].z = 0.0;
  mat44f::mat44f(&this->originalMatrix);
  v10 = (Game *)this;
  this->stiffness = 0.1;
  v9._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_c6eaa5b1cf854b09a2018ac31defeaa8_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&v9._Bx._Alias[4] = this;
  v9._Mysize = (unsigned int)&v9;
  v4 = this->car;
  LOBYTE(v14) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v4->sim->renderFinishedNodeEvent->evOnRender,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v9,
    v10);
  v10 = (Game *)this->srcPivot;
  this->objectNode = desc->objectNode;
  this->srcNode = desc->srcNode;
  this->dstNode = desc->dstNode;
  this->srcPivot[0] = desc->pivotOnSrc;
  this->dstPivot[0] = desc->pivotOnDst;
  v5 = Node::localToWorld(this->srcNode, &result, (const vec3f *)v10);
  v6 = Node::worldToLocal(this->objectNode, &v13, v5);
  v10 = (Game *)this->dstPivot;
  this->srcPivot[1] = *v6;
  v7 = Node::localToWorld(this->dstNode, &v13, (const vec3f *)v10);
  this->dstPivot[1] = *Node::worldToLocal(this->objectNode, &result, v7);
  v8 = this->objectNode;
  *(__m128i *)&this->originalMatrix.M11 = _mm_loadu_si128((const __m128i *)&v8->matrix);
  *(__m128i *)&this->originalMatrix.M21 = _mm_loadu_si128((const __m128i *)&v8->matrix.M21);
  *(__m128i *)&this->originalMatrix.M31 = _mm_loadu_si128((const __m128i *)&v8->matrix.M31);
  *(__m128i *)&this->originalMatrix.M41 = _mm_loadu_si128((const __m128i *)&v8->matrix.M41);
}
SuspensionGraphics *SuspensionGraphics::`scalar deleting destructor'(SuspensionGraphics *this, unsigned int a2)
{
  this->__vftable = (SuspensionGraphics_vtbl *)&SuspensionGraphics::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SuspensionGraphics::update(SuspensionGraphics *this, float dt)
{
  Node *v3; // eax
  __int64 v4; // xmm0_8
  Node *v5; // ecx
  vec3f *v6; // eax
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  int v19; // ecx
  float v20; // xmm2_4
  float v21; // xmm4_4
  __int128 v22; // xmm1
  __int128 v23; // xmm2
  __int128 v24; // xmm3
  __m128 v25; // xmm0
  __int128 v26; // xmm1
  __int128 v27; // xmm2
  __int128 v28; // xmm3
  __int128 v29; // xmm1
  __int128 v30; // xmm2
  __int128 v31; // xmm3
  __m128 v32; // xmm0
  Node *v33; // esi
  __int128 v34; // xmm7
  __int128 v35; // xmm6
  __int128 v36; // xmm5
  __int128 v37; // xmm1
  __int128 v38; // xmm2
  __int128 v39; // xmm3
  int v40; // [esp+0h] [ebp-100h]
  int v41; // [esp+4h] [ebp-FCh]
  float v42; // [esp+8h] [ebp-F8h]
  float v43; // [esp+8h] [ebp-F8h]
  float v44; // [esp+Ch] [ebp-F4h]
  float v45; // [esp+Ch] [ebp-F4h]
  float v46; // [esp+10h] [ebp-F0h]
  float v47; // [esp+10h] [ebp-F0h]
  float v48; // [esp+14h] [ebp-ECh]
  float v49; // [esp+14h] [ebp-ECh]
  float v50; // [esp+18h] [ebp-E8h]
  float v51; // [esp+18h] [ebp-E8h]
  float v52; // [esp+1Ch] [ebp-E4h]
  float v53; // [esp+1Ch] [ebp-E4h]
  float v54; // [esp+20h] [ebp-E0h]
  vec3f result; // [esp+24h] [ebp-DCh] BYREF
  __int128 v56; // [esp+30h] [ebp-D0h]
  __int128 v57; // [esp+40h] [ebp-C0h]
  mat44f v58; // [esp+50h] [ebp-B0h] BYREF
  mat44f v59; // [esp+90h] [ebp-70h] BYREF
  __m128 v60; // [esp+D0h] [ebp-30h] BYREF
  __int128 v61; // [esp+E0h] [ebp-20h]
  __m128 pDeterminant; // [esp+F0h] [ebp-10h] BYREF

  v3 = this->objectNode;
  *(__m128i *)&v3->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->originalMatrix);
  *(__m128i *)&v3->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->originalMatrix.M21);
  *(__m128i *)&v3->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->originalMatrix.M31);
  *(__m128i *)&v3->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->originalMatrix.M41);
  mat44f::mat44f(&v58);
  mat44f::loadIdentity(&v58);
  Node::localToWorld(this->dstNode, &result, this->dstPivot);
  v4 = *(_QWORD *)&this->dstPivot[1].x;
  v5 = this->objectNode;
  DWORD2(v56) = LODWORD(this->dstPivot[1].z);
  DWORD2(v57) = LODWORD(this->srcPivot[1].z);
  *(_QWORD *)&v56 = v4;
  *(_QWORD *)&v57 = *(_QWORD *)&this->srcPivot[1].x;
  v6 = Node::worldToLocal(v5, (vec3f *)&v60, &result);
  v7 = *(float *)&v56 - *(float *)&v57;
  v8 = *((float *)&v56 + 1) - *((float *)&v57 + 1);
  v9 = *((float *)&v56 + 2) - *((float *)&v57 + 2);
  result = *v6;
  v50 = *(float *)&v56 - *(float *)&v57;
  v10 = result.x - *(float *)&v57;
  v11 = result.y - *((float *)&v57 + 1);
  v44 = *((float *)&v56 + 1) - *((float *)&v57 + 1);
  v12 = result.z - *((float *)&v57 + 2);
  v46 = *((float *)&v56 + 2) - *((float *)&v57 + 2);
  v52 = result.x - *(float *)&v57;
  v54 = result.y - *((float *)&v57 + 1);
  v48 = result.z - *((float *)&v57 + 2);
  v42 = fsqrt((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9));
  if ( v42 != 0.0 )
  {
    v7 = (float)(1.0 / v42) * v7;
    v8 = (float)(1.0 / v42) * v8;
    v50 = v7;
    v44 = v8;
    v9 = (float)(1.0 / v42) * v9;
    v46 = v9;
  }
  v43 = fsqrt((float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v12 * v12));
  if ( v43 != 0.0 )
  {
    v10 = (float)(1.0 / v43) * v10;
    v11 = (float)(1.0 / v43) * v11;
    v52 = v10;
    v54 = v11;
    v12 = (float)(1.0 / v43) * v12;
    v48 = v12;
  }
  v13 = (float)((float)(v8 * v11) + (float)(v7 * v10)) + (float)(v9 * v12);
  if ( v13 > -1.0 && v13 < 1.0 )
  {
    __libm_sse2_acosf();
    v7 = v50;
    v9 = v46;
    v8 = v44;
    v10 = v52;
    v11 = v54;
    v12 = v48;
  }
  v45 = (float)(v8 * v12) - (float)(v9 * v11);
  v14 = (float)(v9 * v10) - (float)(v7 * v12);
  v15 = (float)(v7 * v11) - (float)(v8 * v10);
  v47 = v14;
  v51 = v15;
  v16 = fsqrt((float)((float)(v14 * v14) + (float)(v45 * v45)) + (float)(v15 * v15));
  if ( v16 != 0.0 )
  {
    v45 = (float)(1.0 / v16) * v45;
    v47 = (float)(1.0 / v16) * v14;
    v51 = (float)(1.0 / v16) * v15;
  }
  v17 = this->srcPivot[1].y * -1.0;
  v18 = this->srcPivot[1].z * -1.0;
  v58.M41 = this->srcPivot[1].x * -1.0;
  v58.M42 = v17;
  v58.M43 = v18;
  mat44f::mat44f(&v59);
  v49 = __libm_sse2_cosf(v40, v41).m128_f32[0];
  v53 = __libm_sse2_sinf(v19).m128_f32[0];
  mat44f::mat44f(&v59);
  v59.M44 = 1.0;
  v59.M22 = (float)((float)(v47 * v47) * (float)(1.0 - v49)) + v49;
  v59.M11 = (float)((float)(v45 * v45) * (float)(1.0 - v49)) + v49;
  v59.M33 = (float)((float)(v51 * v51) * (float)(1.0 - v49)) + v49;
  v20 = (float)(v47 * v45) * (float)(1.0 - v49);
  v59.M12 = (float)(v51 * v53) + v20;
  v59.M21 = v20 - (float)(v51 * v53);
  v21 = (float)(v51 * v47) * (float)(1.0 - v49);
  v59.M13 = (float)((float)(v51 * v45) * (float)(1.0 - v49)) - (float)(v47 * v53);
  v59.M31 = (float)(v47 * v53) + (float)((float)(v51 * v45) * (float)(1.0 - v49));
  v59.M23 = (float)(v45 * v53) + v21;
  v59.M32 = v21 - (float)(v45 * v53);
  v22 = *(_OWORD *)&v58.M21;
  v23 = *(_OWORD *)&v58.M31;
  v24 = *(_OWORD *)&v58.M41;
  v25 = DirectX::XMMatrixMultiply((__m128 *)&v59, *(__m128 *)&v58.M11);
  v61 = v24;
  v57 = v23;
  v56 = v22;
  v60 = v25;
  mat44f::mat44f(&v59);
  v26 = *(_OWORD *)&v58.M21;
  v27 = *(_OWORD *)&v58.M31;
  v28 = *(_OWORD *)&v58.M41;
  *(__m128 *)&v58.M11 = DirectX::XMMatrixInverse(
                          &pDeterminant,
                          *(__m128 *)&v58.M11,
                          *(__m128 *)&v58.M21,
                          *(__m128 *)&v58.M31,
                          *(__m128 *)&v58.M41);
  *(_OWORD *)&v58.M21 = v26;
  v29 = v56;
  *(_OWORD *)&v58.M31 = v27;
  v30 = v57;
  *(_OWORD *)&v58.M41 = v28;
  v31 = v61;
  v32 = DirectX::XMMatrixMultiply((__m128 *)&v58, v60);
  v33 = this->objectNode;
  v34 = v31;
  v35 = v30;
  v36 = v29;
  v37 = *(_OWORD *)&v33->matrix.M21;
  v38 = *(_OWORD *)&v33->matrix.M31;
  v39 = *(_OWORD *)&v33->matrix.M41;
  *(_OWORD *)&v58.M11 = *(_OWORD *)&v33->matrix.M11;
  *(_OWORD *)&v58.M21 = v37;
  *(_OWORD *)&v58.M31 = v38;
  *(_OWORD *)&v58.M41 = v39;
  *(__m128 *)&v33->matrix.M11 = DirectX::XMMatrixMultiply((__m128 *)&v58, v32);
  *(_OWORD *)&v33->matrix.M21 = v36;
  *(_OWORD *)&v33->matrix.M31 = v35;
  *(_OWORD *)&v33->matrix.M41 = v34;
}
