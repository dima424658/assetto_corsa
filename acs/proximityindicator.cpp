#include "proximityindicator.h"
void ProximityIndicator::ProximityIndicator(ProximityIndicator *this, Sim *sim)
{
  int v3; // eax
  bool v4; // cf
  std::wstring v5; // [esp-1Ch] [ebp-CCh] BYREF
  unsigned int v6; // [esp-4h] [ebp-B4h]
  ProximityIndicator *v7; // [esp+Ch] [ebp-A4h]
  std::wstring ifilename; // [esp+14h] [ebp-9Ch] BYREF
  std::wstring section; // [esp+2Ch] [ebp-84h] BYREF
  std::wstring key; // [esp+44h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+5Ch] [ebp-54h] BYREF
  int v12; // [esp+ACh] [ebp-4h]

  v7 = this;
  v6 = (unsigned int)sim->game;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"PROXIMITY INDICATOR", 0x13u);
  GameObject::GameObject(this, v5, (Game *)v6);
  v6 = 34;
  v12 = 0;
  v5._Myres = (unsigned int)L"system/cfg/proximity_indicator.ini";
  this->__vftable = (ProximityIndicator_vtbl *)&ProximityIndicator::`vftable';
  this->sim = sim;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, (const wchar_t *)v5._Myres, v6);
  LOBYTE(v12) = 1;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v12) = 3;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"HIDE", 4u);
    LOBYTE(v12) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v12) = 5;
    v3 = INIReader::getInt(&ini, &section, &key);
    v4 = section._Myres < 8;
    this->isActive = v3 != 1;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  LOBYTE(v12) = 0;
  INIReader::~INIReader(&ini);
}
ProximityIndicator *ProximityIndicator::`vector deleting destructor'(ProximityIndicator *this, unsigned int a2)
{
  this->__vftable = (ProximityIndicator_vtbl *)&ProximityIndicator::`vftable';
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ProximityIndicator::renderHUD(ProximityIndicator *this, float deltaT)
{
  Sim *v3; // ecx
  Game *v4; // edx
  CameraMode v5; // eax
  unsigned int v6; // edi
  signed int v7; // esi
  int v8; // eax
  CarAvatar *v9; // eax
  CarAvatar *v10; // edi
  float *v11; // ecx
  float *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  vec3f *v15; // eax
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // [esp+1Ch] [ebp-74h]
  float v22; // [esp+20h] [ebp-70h]
  int v23; // [esp+24h] [ebp-6Ch]
  float v24; // [esp+28h] [ebp-68h]
  float v25; // [esp+2Ch] [ebp-64h]
  unsigned int v26; // [esp+30h] [ebp-60h]
  float v27; // [esp+34h] [ebp-5Ch]
  float v28; // [esp+38h] [ebp-58h]
  float v29; // [esp+3Ch] [ebp-54h]
  CarAvatar *v30; // [esp+40h] [ebp-50h]
  GLRenderer *v31; // [esp+44h] [ebp-4Ch]
  float v32; // [esp+48h] [ebp-48h]
  float v; // [esp+54h] [ebp-3Ch] BYREF
  float v34; // [esp+58h] [ebp-38h]
  float v35; // [esp+5Ch] [ebp-34h]
  vec3f pos; // [esp+60h] [ebp-30h] BYREF
  float v37[3]; // [esp+6Ch] [ebp-24h] BYREF
  float v38[3]; // [esp+78h] [ebp-18h] BYREF
  vec3f result; // [esp+84h] [ebp-Ch] BYREF

  v3 = this->sim;
  if ( !v3->escMenu->visible )
  {
    v4 = this->game;
    if ( v4->gui->isActive && !v3->pauseMenu->visible )
    {
      v5 = v3->cameraManager->mode;
      if ( v5 == eCockpit || v5 == eDrivable )
      {
        v31 = v4->graphics->gl;
        v6 = Sim::getFocusedCarIndex(v3);
        v26 = v6;
        v7 = 0;
        v30 = Sim::getCar(this->sim, v6);
        v27 = v30->physicsState.worldMatrix.M41;
        v28 = v30->physicsState.worldMatrix.M42;
        v23 = this->sim->cars._Mylast - this->sim->cars._Myfirst;
        v29 = v30->physicsState.worldMatrix.M43;
        v8 = v23;
        v32 = (float)((float)this->game->graphics->videoSettings.height * 0.0013020834) * 20.0;
        if ( v23 > 0 )
        {
          do
          {
            if ( v7 != v6 )
            {
              v9 = Sim::getCar(this->sim, v7);
              v10 = v9;
              v11 = (float *)v9->bodyTransform;
              if ( (float)((float)((float)((float)(v28 - v11[14]) * (float)(v28 - v11[14]))
                                 + (float)((float)(v27 - v11[13]) * (float)(v27 - v11[13])))
                         + (float)((float)(v29 - v11[15]) * (float)(v29 - v11[15]))) < 100.0
                && CarAvatar::isConnected(v9) )
              {
                v12 = (float *)v10->bodyTransform;
                v13 = v12[14];
                v14 = v12[15];
                pos.x = v12[13];
                pos.y = v13;
                pos.z = v14;
                v15 = Node::worldToLocal(v30->bodyTransform, &result, &pos);
                v16 = v15->x * -1.0;
                v17 = v15->z * -1.0;
                v21 = v16;
                v22 = v17;
                v18 = fsqrt((float)(v16 * v16) + (float)(v17 * v17));
                if ( v18 != 0.0 )
                {
                  v17 = v17 * (float)(1.0 / v18);
                  v22 = v17;
                  v16 = (float)(1.0 / v18) * v16;
                  v21 = v16;
                }
                v19 = (float)(v17 + 1.0) * (float)this->game->graphics->videoSettings.height;
                v20 = (float)this->game->graphics->videoSettings.width;
                v35 = 0.0;
                v = (float)((float)(v16 + 1.0) * v20) * 0.5;
                v34 = v19 * 0.5;
                GLRenderer::color4f(v31, 1.0, 0.0, 0.0, 0.60000002);
                GLRenderer::begin(v31, eTriangles, 0);
                GLRenderer::vertex3fv(v31, &v);
                v24 = COERCE_FLOAT(LODWORD(v16) ^ _xmm) * v32;
                v25 = (float)((float)(v16 * 0.0) - (float)(v17 * 0.0)) * v32;
                v37[0] = (float)(v22 * v32) + (float)(v - (float)(v21 * v32));
                v37[1] = v24 + (float)(v34 - (float)(v22 * v32));
                v37[2] = v25 + (float)(v35 - (float)(v32 * 0.0));
                GLRenderer::vertex3fv(v31, v37);
                v38[0] = (float)(v - (float)(v21 * v32)) - (float)(v22 * v32);
                v38[1] = (float)(v34 - (float)(v22 * v32)) - v24;
                v38[2] = (float)(v35 - (float)(v32 * 0.0)) - v25;
                GLRenderer::vertex3fv(v31, v38);
                GLRenderer::end(v31);
              }
              v8 = v23;
              v6 = v26;
            }
            ++v7;
          }
          while ( v7 < v8 );
        }
      }
    }
  }
}
