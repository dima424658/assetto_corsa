#include "raypicker.h
void RayPicker::RayPicker(RayPicker *this, float sW, float sH)
{
  this->__vftable = (RayPicker_vtbl *)&RayPicker::`vftable';
  this->pickedPoint.x = 0.0;
  this->pickedPoint.y = 0.0;
  this->pickedPoint.z = 0.0;
  this->srcRay.x = 0.0;
  this->srcRay.y = 0.0;
  this->srcRay.z = 0.0;
  this->orgRayWS.x = 0.0;
  this->orgRayWS.y = 0.0;
  this->orgRayWS.z = 0.0;
  this->dirRayWS.x = 0.0;
  this->dirRayWS.y = 0.0;
  this->dirRayWS.z = 0.0;
  this->screenW = sW;
  this->screenH = sH;
  this->pickedDistance = 0.0;
}
void RayPicker::~RayPicker(RayPicker *this)
{
  this->__vftable = (RayPicker_vtbl *)&RayPicker::`vftable';
}
RayPicker *RayPicker::`scalar deleting destructor'(RayPicker *this, unsigned int a2)
{
  this->__vftable = (RayPicker_vtbl *)&RayPicker::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
Mesh *__userpurge RayPicker::pick@<eax>(RayPicker *this@<ecx>, __m128 a2@<xmm0>, int px, int py, Camera *cam, Node *startNode)
{
  float v7; // xmm1_4
  float aspectRatio; // xmm0_4
  __m128 v9; // xmm7
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128i v12; // xmm0
  float v13; // eax
  __int128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm2
  __m128 v17; // xmm7
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  float v22; // eax
  Mesh *v23; // esi
  float v24; // xmm0_4
  std::function<bool __cdecl(Node *)> v26; // [esp-20h] [ebp-710h] BYREF
  std::function<void __cdecl(Node *)> nearPlaneDistance; // [esp-8h] [ebp-6F8h] BYREF
  mat44f result; // [esp+24h] [ebp-6CCh] BYREF
  __m128 v29; // [esp+64h] [ebp-68Ch]
  __m128i v30; // [esp+74h] [ebp-67Ch] BYREF
  __m128i v31; // [esp+84h] [ebp-66Ch]
  float v32; // [esp+9Ch] [ebp-654h]
  Node *v33; // [esp+A0h] [ebp-650h]
  float v34; // [esp+A4h] [ebp-64Ch]
  RayPickerTraverser v35; // [esp+A8h] [ebp-648h] BYREF
  int v36; // [esp+6ECh] [ebp-4h]

  a2.m128_f32[0] = 0.0;
  v7 = 1.0 / this->screenH;
  v33 = startNode;
  v32 = 0.0;
  *(_QWORD *)&this->srcRay.x = _mm_unpacklo_ps(a2, (__m128)0i64).m128_u64[0];
  this->srcRay.z = 0.0;
  (&nearPlaneDistance._Impl)[1] = (std::_Func_base<void,Node *> *)LODWORD(cam->farPlane);
  nearPlaneDistance._Impl = (std::_Func_base<void,Node *> *)LODWORD(cam->nearPlane);
  aspectRatio = this->screenW * v7;
  v34 = v7;
  mat44f::createPerspective(
    &result,
    cam->fov * 0.017453,
    aspectRatio,
    *(float *)&nearPlaneDistance._Impl,
    *(float *)&(&nearPlaneDistance._Impl)[1]);
  this->srcRay.z = -1.0;
  this->srcRay.x = (float)((float)((float)((float)px * 2.0) / this->screenW) - 1.0) / result.M11;
  LODWORD(this->srcRay.y) = COERCE_UNSIGNED_INT((float)((float)((float)((float)py * 2.0) * v34) - 1.0) / result.M22) ^ _xmm;
  v9 = (__m128)_mm_loadu_si128((const __m128i *)&cam->matrix);
  v10 = (__m128)LODWORD(cam->matrix.M42);
  v11 = (__m128)LODWORD(cam->matrix.M41);
  v31 = _mm_loadu_si128((const __m128i *)&cam->matrix.M21);
  v30 = _mm_loadu_si128((const __m128i *)&cam->matrix.M31);
  v12 = _mm_loadu_si128((const __m128i *)&cam->matrix.M41);
  v29 = v9;
  *(__m128i *)&result.M41 = v12;
  v32 = cam->matrix.M43;
  v13 = v32;
  *(_QWORD *)&this->orgRayWS.x = _mm_unpacklo_ps(v11, v10).m128_u64[0];
  this->orgRayWS.z = v13;
  v14 = LODWORD(this->srcRay.x);
  v15 = (__m128)v14;
  v16 = (__m128)v14;
  v15.m128_f32[0] = (float)((float)(*(float *)&v14 * v9.m128_f32[0]) + (float)(this->srcRay.y * *(float *)v31.m128i_i32))
                  + (float)(this->srcRay.z * *(float *)v30.m128i_i32);
  *(float *)v12.m128i_i32 = _mm_shuffle_ps(v9, v9, 85).m128_f32[0];
  v17 = (__m128)_mm_loadu_si128(&v30);
  v10.m128_i32[0] = LODWORD(this->srcRay.z);
  v16.m128_f32[0] = (float)((float)(*(float *)&v14 * *(float *)v12.m128i_i32)
                          + (float)(this->srcRay.y * *(float *)&v31.m128i_i32[1]))
                  + (float)(v10.m128_f32[0] * _mm_shuffle_ps(v17, v17, 85).m128_f32[0]);
  *(float *)&v14 = (float)((float)(*(float *)&v14 * v29.m128_f32[2])
                         + (float)(this->srcRay.y * *(float *)&v31.m128i_i32[2]))
                 + (float)(v10.m128_f32[0] * *(float *)&v30.m128i_i32[2]);
  *(_QWORD *)&this->dirRayWS.x = _mm_unpacklo_ps(v15, v16).m128_u64[0];
  v32 = *(float *)&v14;
  LODWORD(this->dirRayWS.z) = v14;
  v18 = this->dirRayWS.y;
  v19 = this->dirRayWS.x;
  v20 = this->dirRayWS.z;
  v21 = fsqrt((float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v20 * v20));
  if ( v21 != 0.0 )
  {
    this->dirRayWS.x = (float)(1.0 / v21) * v19;
    this->dirRayWS.y = (float)(1.0 / v21) * v18;
    this->dirRayWS.z = (float)(1.0 / v21) * v20;
  }
  RayPickerTraverser::RayPickerTraverser(&v35, &this->orgRayWS, &this->dirRayWS);
  v36 = 0;
  v34 = COERCE_FLOAT(&nearPlaneDistance);
  nearPlaneDistance._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_79aed8583d974a0b4e89939487f0dfeb_,0>,std::allocator<std::_Func_class<void,Node *>>,void,Node *>::`vftable';
  nearPlaneDistance._Space._Pfn[1] = (void (__cdecl *)())&v35;
  nearPlaneDistance._Impl = (std::_Func_base<void,Node *> *)&nearPlaneDistance;
  v26._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_d9b93fd7105a45e42093d57c28a75eb1_,0>,std::allocator<std::_Func_class<bool,Node *>>,bool,Node *>::`vftable';
  v26._Space._Pfn[1] = (void (__cdecl *)())&v35;
  v26._Impl = (std::_Func_base<bool,Node *> *)&v26;
  Node::visit(v33, v26, nearPlaneDistance);
  v22 = v35.pickedPoint.z;
  v23 = v35.pickedMesh;
  *(_QWORD *)&this->pickedPoint.x = *(_QWORD *)&v35.pickedPoint.x;
  v24 = v35.pickedDistance;
  this->pickedPoint.z = v22;
  this->pickedDistance = v24;
  v36 = -1;
  MatrixStack::~MatrixStack(&v35.stack);
  return v23;
}
