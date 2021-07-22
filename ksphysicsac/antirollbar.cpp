#include "antirollbar.h
void AntirollBar::AntirollBar(AntirollBar *this)
{
  this->carBody = 0;
  DynamicController::DynamicController(&this->ctrl);
  this->k = 0.0;
}
void AntirollBar::~AntirollBar(SteeringSystem *this)
{
  DynamicController::~DynamicController(&this->ctrl4ws);
}
void AntirollBar::init(AntirollBar *this, IRigidBody *cb, ISuspension **sus)
{
  this->carBody = cb;
  *(_QWORD *)this->hubs = *(_QWORD *)sus;
  this->k = 0.0;
}
void AntirollBar::step(AntirollBar *this, float dt)
{
  mat44f *v3; // eax
  ISuspension *v4; // ecx
  int v5; // xmm1_4
  int v6; // xmm2_4
  mat44f *v7; // eax
  IRigidBody *v8; // ecx
  int v9; // xmm1_4
  int v10; // xmm2_4
  IRigidBody *v11; // ecx
  IRigidBody_vtbl *v12; // eax
  int v13; // eax
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  ISuspension *v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm0_4
  IRigidBody *v21; // ecx
  ISuspension *v22; // ecx
  float v23; // xmm0_4
  float v24; // xmm0_4
  IRigidBody *v25; // ecx
  float v26; // [esp+48h] [ebp-8Ch] BYREF
  float v27; // [esp+4Ch] [ebp-88h]
  float v28; // [esp+50h] [ebp-84h]
  float v29; // [esp+54h] [ebp-80h]
  float v30; // [esp+58h] [ebp-7Ch]
  float v31; // [esp+5Ch] [ebp-78h]
  float v32; // [esp+60h] [ebp-74h]
  int v33[3]; // [esp+64h] [ebp-70h] BYREF
  int v34[3]; // [esp+70h] [ebp-64h] BYREF
  char v35; // [esp+7Ch] [ebp-58h] BYREF
  float v36; // [esp+80h] [ebp-54h]
  char v37; // [esp+88h] [ebp-4Ch] BYREF
  float v38; // [esp+8Ch] [ebp-48h]
  mat44f v39; // [esp+94h] [ebp-40h] BYREF

  if ( this->ctrl.ready )
    this->k = DynamicController::eval(&this->ctrl);
  if ( this->k > 0.0 )
  {
    v3 = this->hubs[0]->getHubWorldMatrix(this->hubs[0], &v39);
    v4 = this->hubs[1];
    v5 = LODWORD(v3->M42);
    v6 = LODWORD(v3->M43);
    v33[0] = LODWORD(v3->M41);
    v33[1] = v5;
    v33[2] = v6;
    v7 = v4->getHubWorldMatrix(v4, &v39);
    v8 = this->carBody;
    v9 = LODWORD(v7->M42);
    v10 = LODWORD(v7->M43);
    v34[0] = LODWORD(v7->M41);
    v34[1] = v9;
    v34[2] = v10;
    v8->worldToLocal(v8, (vec3f *)&v35, (const vec3f *)v33);
    this->carBody->worldToLocal(this->carBody, (vec3f *)&v37, (const vec3f *)v34);
    v11 = this->carBody;
    v12 = this->carBody->__vftable;
    v29 = v38 - v36;
    v13 = ((int (*)(IRigidBody *, mat44f *, _DWORD))v12->getWorldMatrix)(v11, &v39, 0);
    v15 = *(float *)(v13 + 20);
    v16 = *(float *)(v13 + 24);
    v32 = *(float *)(v13 + 16);
    v14 = v32;
    v30 = v15;
    v31 = v16;
    v17 = fsqrt((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v16 * v16));
    if ( v17 != 0.0 )
    {
      v14 = (float)(1.0 / v17) * v32;
      v15 = (float)(1.0 / v17) * v15;
      v32 = v14;
      v30 = v15;
      v16 = (float)(1.0 / v17) * v16;
      v31 = v16;
    }
    v18 = this->hubs[0];
    v19 = this->k;
    v26 = (float)(v14 * v29) * v19;
    v27 = (float)(v15 * v29) * v19;
    v28 = (float)(v16 * v29) * v19;
    v18->addForceAtPos(v18, (const vec3f *)&v26, (const vec3f *)v33, 0, 0);
    v20 = this->k;
    v21 = this->carBody;
    v26 = 0.0;
    v28 = 0.0;
    LODWORD(v27) = COERCE_UNSIGNED_INT(v20 * v29) ^ _xmm;
    v21->addLocalForceAtLocalPos(v21, (const vec3f *)&v26, (const vec3f *)&v35);
    v22 = this->hubs[1];
    v23 = this->k;
    v26 = (float)(v32 * COERCE_FLOAT(LODWORD(v29) ^ _xmm)) * v23;
    v27 = (float)(v30 * COERCE_FLOAT(LODWORD(v29) ^ _xmm)) * v23;
    v28 = (float)(v31 * COERCE_FLOAT(LODWORD(v29) ^ _xmm)) * v23;
    v22->addForceAtPos(v22, (const vec3f *)&v26, (const vec3f *)v34, 0, 0);
    v24 = this->k * v29;
    v25 = this->carBody;
    v26 = 0.0;
    v28 = 0.0;
    v27 = v24;
    v25->addLocalForceAtLocalPos(v25, (const vec3f *)&v26, (const vec3f *)&v37);
  }
}
