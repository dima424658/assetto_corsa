#include "collisions.h"
char __cdecl Collisions::rayMeshIntersect(const vec3f *rayOrg, const vec3f *rayDir, Mesh *m, float *t)
{
  int v4; // esi
  float v5; // xmm2_4
  float v6; // xmm5_4
  float v7; // xmm0_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm1_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v22; // [esp+14h] [ebp-74h]
  float v23; // [esp+18h] [ebp-70h]
  float v24; // [esp+1Ch] [ebp-6Ch]
  float v25; // [esp+20h] [ebp-68h]
  float v26; // [esp+24h] [ebp-64h]
  float v27; // [esp+28h] [ebp-60h]
  float v28; // [esp+2Ch] [ebp-5Ch]
  float v29; // [esp+30h] [ebp-58h]
  float v30; // [esp+34h] [ebp-54h]
  float v31; // [esp+38h] [ebp-50h]
  float v32; // [esp+3Ch] [ebp-4Ch]
  Triangle tr; // [esp+40h] [ebp-48h] BYREF
  int v34; // [esp+84h] [ebp-4h]

  v4 = 0;
  *t = 0.0;
  if ( !((m->indices._Mylast - m->indices._Myfirst) / 3u) )
    return 0;
  while ( 1 )
  {
    Mesh::getTriangle(m, &tr, v4);
    v5 = tr.points[2].y - tr.points[0].y;
    v6 = tr.points[2].x - tr.points[0].x;
    v22 = tr.points[1].z - tr.points[0].z;
    v7 = tr.points[2].z - tr.points[0].z;
    v8 = tr.points[1].x - tr.points[0].x;
    v9 = tr.points[1].y - tr.points[0].y;
    v23 = tr.points[2].z - tr.points[0].z;
    *t = 0.0;
    v25 = v5;
    v31 = rayDir->z;
    v24 = v6;
    v29 = rayDir->y;
    v26 = v8;
    v27 = v9;
    v28 = (float)(v29 * v7) - (float)(v31 * v5);
    v30 = (float)(v31 * v6) - (float)(rayDir->x * v23);
    v32 = (float)(rayDir->x * v5) - (float)(v29 * v6);
    v10 = (float)((float)(v28 * v8) + (float)(v30 * v9)) + (float)(v32 * v22);
    if ( v10 <= -0.0000099999997 || v10 >= 0.0000099999997 )
    {
      v11 = rayOrg->x - tr.points[0].x;
      v12 = rayOrg->y - tr.points[0].y;
      v13 = rayOrg->z - tr.points[0].z;
      v14 = 1.0 / v10;
      v15 = (float)((float)((float)(v11 * v28) + (float)(v12 * v30)) + (float)(v13 * v32)) * (float)(1.0 / v10);
      if ( v15 >= 0.0 && v15 <= 1.0 )
      {
        v16 = (float)(v12 * v22) - (float)(v13 * v27);
        v17 = (float)(v11 * v27) - (float)(v12 * v26);
        v18 = (float)(v13 * v26) - (float)((float)(rayOrg->x - tr.points[0].x) * v22);
        v19 = (float)((float)((float)(rayDir->x * v16) + (float)(v29 * v18)) + (float)(v31 * v17)) * v14;
        if ( v19 >= 0.0 && (float)(v19 + v15) <= 1.0 )
        {
          v20 = (float)((float)((float)(v16 * v24) + (float)(v18 * v25)) + (float)(v17 * v23)) * v14;
          *t = v20;
          if ( v20 > 0.0000099999997 )
            break;
        }
      }
    }
    v34 = -1;
    Triangle::~Triangle(&tr);
    if ( ++v4 >= (m->indices._Mylast - m->indices._Myfirst) / 3u )
      return 0;
  }
  v34 = -1;
  Triangle::~Triangle(&tr);
  return 1;
}
