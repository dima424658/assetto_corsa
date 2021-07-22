#include "ghostcar.h"
void GhostCar::GhostCar(GhostCar *this, CarAvatar *a_car, GhostCarRecorder *gcr)
{
  std::wstring v4; // [esp-1Ch] [ebp-44h] BYREF
  Game *v5; // [esp-4h] [ebp-2Ch]
  GhostCar *v6; // [esp+Ch] [ebp-1Ch]
  int v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  v6 = this;
  v5 = a_car->game;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"GHOST_CAR", 9u);
  GameObject::GameObject(this, v4, v5);
  this->__vftable = (GhostCar_vtbl *)&GhostCar::`vftable';
  v8 = 0;
  this->material._Ptr = 0;
  this->material._Rep = 0;
  LOBYTE(v8) = 1;
  this->gcColor.x = 0.0;
  this->gcColor.y = 0.0;
  this->gcColor.z = 0.0;
  mat44f::mat44f(&this->lastBodyMatrix);
  this->lastWheelMatrix[0].M11 = 0.0;
  this->lastWheelMatrix[0].M12 = 0.0;
  this->lastWheelMatrix[0].M13 = 0.0;
  this->lastWheelMatrix[0].M14 = 0.0;
  this->lastWheelMatrix[0].M21 = 0.0;
  this->lastWheelMatrix[0].M22 = 0.0;
  this->lastWheelMatrix[0].M23 = 0.0;
  this->lastWheelMatrix[0].M24 = 0.0;
  this->lastWheelMatrix[0].M31 = 0.0;
  this->lastWheelMatrix[0].M32 = 0.0;
  this->lastWheelMatrix[0].M33 = 0.0;
  this->lastWheelMatrix[0].M34 = 0.0;
  this->lastWheelMatrix[0].M41 = 0.0;
  this->lastWheelMatrix[0].M42 = 0.0;
  this->lastWheelMatrix[0].M43 = 0.0;
  this->lastWheelMatrix[0].M44 = 0.0;
  this->lastWheelMatrix[1].M11 = 0.0;
  this->lastWheelMatrix[1].M12 = 0.0;
  this->lastWheelMatrix[1].M13 = 0.0;
  this->lastWheelMatrix[1].M14 = 0.0;
  this->lastWheelMatrix[1].M21 = 0.0;
  this->lastWheelMatrix[1].M22 = 0.0;
  this->lastWheelMatrix[1].M23 = 0.0;
  this->lastWheelMatrix[1].M24 = 0.0;
  this->lastWheelMatrix[1].M31 = 0.0;
  this->lastWheelMatrix[1].M32 = 0.0;
  this->lastWheelMatrix[1].M33 = 0.0;
  this->lastWheelMatrix[1].M34 = 0.0;
  this->lastWheelMatrix[1].M41 = 0.0;
  this->lastWheelMatrix[1].M42 = 0.0;
  this->lastWheelMatrix[1].M43 = 0.0;
  this->lastWheelMatrix[1].M44 = 0.0;
  this->lastWheelMatrix[2].M11 = 0.0;
  this->lastWheelMatrix[2].M12 = 0.0;
  this->lastWheelMatrix[2].M13 = 0.0;
  this->lastWheelMatrix[2].M14 = 0.0;
  this->lastWheelMatrix[2].M21 = 0.0;
  this->lastWheelMatrix[2].M22 = 0.0;
  this->lastWheelMatrix[2].M23 = 0.0;
  this->lastWheelMatrix[2].M24 = 0.0;
  this->lastWheelMatrix[2].M31 = 0.0;
  this->lastWheelMatrix[2].M32 = 0.0;
  this->lastWheelMatrix[2].M33 = 0.0;
  this->lastWheelMatrix[2].M34 = 0.0;
  this->lastWheelMatrix[2].M41 = 0.0;
  this->lastWheelMatrix[2].M42 = 0.0;
  this->lastWheelMatrix[2].M43 = 0.0;
  this->lastWheelMatrix[2].M44 = 0.0;
  this->lastWheelMatrix[3].M11 = 0.0;
  this->lastWheelMatrix[3].M12 = 0.0;
  this->lastWheelMatrix[3].M13 = 0.0;
  this->lastWheelMatrix[3].M14 = 0.0;
  this->lastWheelMatrix[3].M21 = 0.0;
  this->lastWheelMatrix[3].M22 = 0.0;
  this->lastWheelMatrix[3].M23 = 0.0;
  this->lastWheelMatrix[3].M24 = 0.0;
  this->lastWheelMatrix[3].M31 = 0.0;
  this->lastWheelMatrix[3].M32 = 0.0;
  this->lastWheelMatrix[3].M33 = 0.0;
  this->lastWheelMatrix[3].M34 = 0.0;
  this->lastWheelMatrix[3].M41 = 0.0;
  this->lastWheelMatrix[3].M42 = 0.0;
  this->lastWheelMatrix[3].M43 = 0.0;
  this->lastWheelMatrix[3].M44 = 0.0;
  this->lastSuspMatrix[0].M11 = 0.0;
  this->lastSuspMatrix[0].M12 = 0.0;
  this->lastSuspMatrix[0].M13 = 0.0;
  this->lastSuspMatrix[0].M14 = 0.0;
  this->lastSuspMatrix[0].M21 = 0.0;
  this->lastSuspMatrix[0].M22 = 0.0;
  this->lastSuspMatrix[0].M23 = 0.0;
  this->lastSuspMatrix[0].M24 = 0.0;
  this->lastSuspMatrix[0].M31 = 0.0;
  this->lastSuspMatrix[0].M32 = 0.0;
  this->lastSuspMatrix[0].M33 = 0.0;
  this->lastSuspMatrix[0].M34 = 0.0;
  this->lastSuspMatrix[0].M41 = 0.0;
  this->lastSuspMatrix[0].M42 = 0.0;
  this->lastSuspMatrix[0].M43 = 0.0;
  this->lastSuspMatrix[0].M44 = 0.0;
  this->lastSuspMatrix[1].M11 = 0.0;
  this->lastSuspMatrix[1].M12 = 0.0;
  this->lastSuspMatrix[1].M13 = 0.0;
  this->lastSuspMatrix[1].M14 = 0.0;
  this->lastSuspMatrix[1].M21 = 0.0;
  this->lastSuspMatrix[1].M22 = 0.0;
  this->lastSuspMatrix[1].M23 = 0.0;
  this->lastSuspMatrix[1].M24 = 0.0;
  this->lastSuspMatrix[1].M31 = 0.0;
  this->lastSuspMatrix[1].M32 = 0.0;
  this->lastSuspMatrix[1].M33 = 0.0;
  this->lastSuspMatrix[1].M34 = 0.0;
  this->lastSuspMatrix[1].M41 = 0.0;
  this->lastSuspMatrix[1].M42 = 0.0;
  this->lastSuspMatrix[1].M43 = 0.0;
  this->lastSuspMatrix[1].M44 = 0.0;
  this->lastSuspMatrix[2].M11 = 0.0;
  this->lastSuspMatrix[2].M12 = 0.0;
  this->lastSuspMatrix[2].M13 = 0.0;
  this->lastSuspMatrix[2].M14 = 0.0;
  this->lastSuspMatrix[2].M21 = 0.0;
  this->lastSuspMatrix[2].M22 = 0.0;
  this->lastSuspMatrix[2].M23 = 0.0;
  this->lastSuspMatrix[2].M24 = 0.0;
  this->lastSuspMatrix[2].M31 = 0.0;
  this->lastSuspMatrix[2].M32 = 0.0;
  this->lastSuspMatrix[2].M33 = 0.0;
  this->lastSuspMatrix[2].M34 = 0.0;
  this->lastSuspMatrix[2].M41 = 0.0;
  this->lastSuspMatrix[2].M42 = 0.0;
  this->lastSuspMatrix[2].M43 = 0.0;
  this->lastSuspMatrix[2].M44 = 0.0;
  this->lastSuspMatrix[3].M11 = 0.0;
  this->lastSuspMatrix[3].M12 = 0.0;
  this->lastSuspMatrix[3].M13 = 0.0;
  this->lastSuspMatrix[3].M14 = 0.0;
  this->lastSuspMatrix[3].M21 = 0.0;
  this->lastSuspMatrix[3].M22 = 0.0;
  this->lastSuspMatrix[3].M23 = 0.0;
  this->lastSuspMatrix[3].M24 = 0.0;
  this->lastSuspMatrix[3].M31 = 0.0;
  this->lastSuspMatrix[3].M32 = 0.0;
  this->lastSuspMatrix[3].M33 = 0.0;
  this->lastSuspMatrix[3].M34 = 0.0;
  this->lastSuspMatrix[3].M41 = 0.0;
  this->lastSuspMatrix[3].M42 = 0.0;
  this->lastSuspMatrix[3].M43 = 0.0;
  this->lastSuspMatrix[3].M44 = 0.0;
  this->car = a_car;
  this->gcRecorder = gcr;
  this->wheelTransforms[0] = 0;
  this->susTransforms[0] = 0;
  this->wheelTransforms[1] = 0;
  this->susTransforms[1] = 0;
  this->wheelTransforms[2] = 0;
  this->susTransforms[2] = 0;
  this->wheelTransforms[3] = 0;
  this->susTransforms[3] = 0;
  *(_QWORD *)&this->gcColor.x = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_1_0), (__m128)LODWORD(FLOAT_1_0)).m128_u64[0];
  v7 = 1065353216;
  this->minDistance = 1.0;
  this->maxDistance = 100.0;
  this->gcColor.z = 1.0;
  this->maxOpacity = 0.60000002;
  this->playCounter = 0.0;
  GhostCar::loadGhostCarParameters(this);
  GhostCar::init3D(this);
}
GhostCar *GhostCar::`scalar deleting destructor'(GhostCar *this, unsigned int a2)
{
  std::_Ref_count_base *v3; // edi

  this->__vftable = (GhostCar_vtbl *)&GhostCar::`vftable';
  v3 = this->material._Rep;
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 0xFFFFFFFF) )
    {
      v3->_Destroy(v3);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v3->_Weaks) )
        v3->_Delete_this(v3);
    }
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void GhostCar::assignGhostMaterial(GhostCar *this, Node *node)
{
  Node *v2; // ebx
  int v4; // esi
  std::_Ref_count_base *v5; // edx
  Material *v6; // eax
  volatile signed __int32 *v7; // edi
  std::shared_ptr<Material> *v8; // eax
  Node **v9; // esi
  Node **v10; // eax
  int v11; // edi
  unsigned int v12; // ebx

  v2 = node;
  v4 = __RTDynamicCast(node, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
  if ( v4 )
  {
    v5 = this->material._Rep;
    v6 = this->material._Ptr;
    if ( v5 )
      _InterlockedExchangeAdd((volatile signed __int32 *)&v5->_Uses, 1u);
    v7 = *(volatile signed __int32 **)(v4 + 252);
    *(_DWORD *)(v4 + 252) = v5;
    *(_DWORD *)(v4 + 248) = v6;
    if ( v7 )
    {
      if ( !_InterlockedExchangeAdd(v7 + 1, 0xFFFFFFFF) )
      {
        (**(void (***)(volatile signed __int32 *))v7)(v7);
        if ( !_InterlockedDecrement(v7 + 2) )
          (*(void (**)(volatile signed __int32 *))(*v7 + 4))(v7);
      }
      v2 = node;
    }
  }
  else
  {
    v8 = (std::shared_ptr<Material> *)__RTDynamicCast(
                                        node,
                                        0,
                                        &Node `RTTI Type Descriptor',
                                        &SkinnedMesh `RTTI Type Descriptor',
                                        0);
    v4 = (int)v8;
    if ( !v8 )
      goto LABEL_12;
    std::shared_ptr<Material>::operator=(v8 + 31, &this->material);
  }
  *(_BYTE *)(v4 + 188) = 0;
  *(_BYTE *)(v4 + 190) = 1;
LABEL_12:
  v9 = v2->nodes._Myfirst;
  v10 = v2->nodes._Mylast;
  v11 = 0;
  v12 = (unsigned int)((char *)v10 - (char *)v9 + 3) >> 2;
  if ( v9 > v10 )
    v12 = 0;
  if ( v12 )
  {
    do
    {
      GhostCar::assignGhostMaterial(this, *v9);
      ++v11;
      ++v9;
    }
    while ( v11 != v12 );
  }
}
void GhostCar::init3D(GhostCar *this)
{
  unsigned int v2; // ebx
  Material *v3; // esi
  NodeBoundingSphere *v4; // eax
  Material *v5; // esi
  Node *v6; // eax
  std::wstring *v7; // eax
  const std::wstring *v8; // eax
  CarAvatar *v9; // ecx
  std::wstring *v10; // esi
  CarAvatar *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  Game *v14; // eax
  Node *v15; // eax
  Game *v16; // ecx
  CarAvatar *v17; // eax
  std::wstring *v18; // eax
  const std::wstring *v19; // eax
  CarAvatar *v20; // ecx
  int v21; // esi
  Node **v22; // ebp
  Node *v23; // eax
  Node *v24; // ecx
  Node *v25; // esi
  const wchar_t *v26; // eax
  double v27; // st7
  bool v28; // cf
  float *v29; // esi
  Node *v30; // ecx
  Node_vtbl *v31; // eax
  int v32; // esi
  Node *v33; // eax
  __m128i v34; // xmm0
  Node *v35; // eax
  double v36; // st7
  int v37; // esi
  const wchar_t *v38; // eax
  NodeBoundingSphere *v39; // ecx
  Node *v40; // eax
  Material *v41; // esi
  Material *v42; // eax
  Game *v43; // eax
  std::_Ref_count_base *v44; // esi
  Material *v45; // ecx
  std::wstring v46; // [esp+18h] [ebp-268h] BYREF
  float radius; // [esp+30h] [ebp-250h]
  Node *v48; // [esp+48h] [ebp-238h]
  unsigned int v49; // [esp+4Ch] [ebp-234h]
  int v50; // [esp+50h] [ebp-230h]
  std::shared_ptr<Material> v51; // [esp+54h] [ebp-22Ch] BYREF
  unsigned int v52; // [esp+5Ch] [ebp-224h]
  float v53; // [esp+68h] [ebp-218h]
  std::wstring result; // [esp+74h] [ebp-20Ch] BYREF
  std::wstring n; // [esp+8Ch] [ebp-1F4h] BYREF
  std::wstring _Left; // [esp+A4h] [ebp-1DCh] BYREF
  std::wstring section; // [esp+BCh] [ebp-1C4h] BYREF
  std::wstring key; // [esp+D4h] [ebp-1ACh] BYREF
  std::wstring filename; // [esp+ECh] [ebp-194h] BYREF
  std::wstring v60; // [esp+104h] [ebp-17Ch] BYREF
  std::wstring v61; // [esp+11Ch] [ebp-164h] BYREF
  std::wstring v62; // [esp+134h] [ebp-14Ch] BYREF
  std::wstring v63; // [esp+14Ch] [ebp-134h] BYREF
  std::wstring v64; // [esp+164h] [ebp-11Ch] BYREF
  INIReader sus_ini; // [esp+17Ch] [ebp-104h] BYREF
  INIReader lodIni; // [esp+1C0h] [ebp-C0h] BYREF
  KN5IO kn; // [esp+204h] [ebp-7Ch] BYREF
  int v68; // [esp+27Ch] [ebp-4h]

  v2 = 0;
  v49 = 0;
  v3 = (Material *)operator new(228);
  v51._Ptr = v3;
  v4 = 0;
  v68 = 0;
  if ( v3 )
  {
    radius = 4.0;
    v46._Myres = 7;
    v46._Mysize = 0;
    v46._Bx._Buf[0] = 0;
    std::wstring::assign(&v46, L"CARNODE", 7u);
    NodeBoundingSphere::NodeBoundingSphere((NodeBoundingSphere *)v3, v46, radius);
  }
  LODWORD(radius) = 188;
  v68 = -1;
  this->carNode = v4;
  v5 = (Material *)operator new(LODWORD(radius));
  v51._Ptr = v5;
  v6 = 0;
  v68 = 1;
  if ( v5 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"BODYTR", 6u);
    LOBYTE(v68) = 2;
    v2 = 1;
    v49 = 1;
    Node::Node((Node *)v5, &n);
  }
  this->bodyTransform = v6;
  v68 = -1;
  if ( (v2 & 1) != 0 )
  {
    v2 &= 0xFFFFFFFE;
    v49 = v2;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
  }
  v7 = std::operator+<wchar_t>(&n, L"content/cars/", &this->car->unixName);
  v68 = 4;
  v8 = std::operator+<wchar_t>(&result, v7, L"/data/lods.ini");
  v9 = this->car;
  LOBYTE(v68) = 5;
  CarAvatar::openINI(v9, &lodIni, v8);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v68) = 8;
  if ( n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"FILE", 4u);
  LOBYTE(v68) = 9;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"LOD_0", 5u);
  LOBYTE(v68) = 10;
  v10 = INIReader::getString(&lodIni, &v64, &section, &key);
  LOBYTE(v68) = 11;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v11 = this->car;
  LOBYTE(v68) = 12;
  v12 = std::operator+<wchar_t>(&v60, &_Left, &v11->unixName);
  LOBYTE(v68) = 13;
  v13 = std::operator+<wchar_t>(&v62, v12, L"/");
  LOBYTE(v68) = 14;
  std::operator+<wchar_t>(&filename, v13, v10);
  if ( v62._Myres >= 8 )
    operator delete(v62._Bx._Ptr);
  v62._Myres = 7;
  v62._Mysize = 0;
  v62._Bx._Buf[0] = 0;
  if ( v60._Myres >= 8 )
    operator delete(v60._Bx._Ptr);
  v60._Myres = 7;
  v60._Mysize = 0;
  v60._Bx._Buf[0] = 0;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  if ( v64._Myres >= 8 )
    operator delete(v64._Bx._Ptr);
  v64._Myres = 7;
  v64._Mysize = 0;
  v64._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v68) = 21;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Bx._Buf[0] = 0;
  v14 = this->game;
  key._Mysize = 0;
  KN5IO::KN5IO(&kn, v14->graphics);
  LOBYTE(v68) = 22;
  v15 = KN5IO::load(&kn, &filename);
  v16 = this->game;
  this->modelLink = v15;
  GraphicsManager::compile(v16->graphics, v15);
  this->carNode->addChild(this->carNode, this->bodyTransform);
  this->bodyTransform->addChild(this->bodyTransform, this->modelLink);
  n._Myres = 7;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  std::wstring::assign(&n, L"content/cars/", 0xDu);
  v17 = this->car;
  LOBYTE(v68) = 23;
  v18 = std::operator+<wchar_t>(&v61, &n, &v17->unixName);
  LOBYTE(v68) = 24;
  v19 = std::operator+<wchar_t>(&v63, v18, L"/data/suspensions.ini");
  v20 = this->car;
  LOBYTE(v68) = 25;
  CarAvatar::openINI(v20, &sus_ini, v19);
  if ( v63._Myres >= 8 )
    operator delete(v63._Bx._Ptr);
  v63._Myres = 7;
  v63._Mysize = 0;
  v63._Bx._Buf[0] = 0;
  if ( v61._Myres >= 8 )
    operator delete(v61._Bx._Ptr);
  v61._Myres = 7;
  v61._Mysize = 0;
  v61._Bx._Buf[0] = 0;
  LOBYTE(v68) = 29;
  if ( n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  n._Myres = 7;
  v21 = 0;
  n._Mysize = 0;
  n._Bx._Buf[0] = 0;
  v22 = this->susTransforms;
  v50 = 0;
  do
  {
    v48 = (Node *)operator new(188);
    LOBYTE(v68) = 30;
    if ( v48 )
    {
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, L"WHEEL_TRANSFORM", 0xFu);
      v2 |= 2u;
      LOBYTE(v68) = 31;
      v49 = v2;
      Node::Node(v48, &result);
    }
    else
    {
      v23 = 0;
    }
    *(v22 - 4) = v23;
    v68 = 29;
    if ( (v2 & 2) != 0 )
    {
      v2 &= 0xFFFFFFFD;
      v49 = v2;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    v24 = this->bodyTransform;
    v48 = (Node *)((char *)_wheelNames + v21);
    v25 = v24->findChildByName(v24, (std::wstring *)((char *)_wheelNames + v21), 1);
    if ( !v25 )
    {
      v26 = (const wchar_t *)v48;
      if ( *(unsigned int *)((char *)&_wheelNames[0]._Myres + v50) >= 8 )
        v26 = (const wchar_t *)v48->__vftable;
      _printf("ERROR, CANNOT LOCATE %S\n FOR GHOSTCAR", v26);
    }
    LODWORD(radius) = 16;
    v25->matrix.M11 = 1.0;
    v46._Myres = (unsigned int)L"GRAPHICS_OFFSETS";
    v25->matrix.M12 = 0.0;
    v25->matrix.M13 = 0.0;
    v25->matrix.M14 = 0.0;
    v25->matrix.M21 = 0.0;
    v25->matrix.M22 = 1.0;
    v25->matrix.M23 = 0.0;
    v25->matrix.M24 = 0.0;
    v25->matrix.M31 = 0.0;
    v25->matrix.M32 = 0.0;
    v25->matrix.M33 = 1.0;
    v25->matrix.M34 = 0.0;
    v25->matrix.M41 = 0.0;
    v25->matrix.M42 = 0.0;
    v25->matrix.M43 = 0.0;
    v25->matrix.M44 = 1.0;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, (const wchar_t *)v46._Myres, LODWORD(radius));
    LOBYTE(v68) = 33;
    v27 = INIReader::getFloat(&sus_ini, &result, (const std::wstring *)v48);
    v28 = result._Myres < 8;
    v53 = v27;
    *(_QWORD *)&v25->matrix.M41 = LODWORD(v53);
    v25->matrix.M43 = 0.0;
    LOBYTE(v68) = 29;
    if ( !v28 )
      operator delete(result._Bx._Ptr);
    (*(v22 - 4))->addChild(*(v22 - 4), v25);
    v29 = (float *)*(v22 - 4);
    _printf("|%f %f %f %f|\n", v29[1], v29[5], v29[9], v29[13]);
    _printf("|%f %f %f %f|\n", v29[2], v29[6], v29[10], v29[14]);
    _printf("|%f %f %f %f|\n", v29[3], v29[7], v29[11], v29[15]);
    _printf("|%f %f %f %f|\n", v29[4], v29[8], v29[12], v29[16]);
    this->carNode->addChild(this->carNode, *(v22 - 4));
    v30 = this->bodyTransform;
    LODWORD(radius) = 1;
    v31 = v30->__vftable;
    v46._Myres = (unsigned int)_susNames + v50;
    v48 = (Node *)((char *)_susNames + v50);
    v32 = (int)v31->findChildByName(v30, (std::wstring *)((char *)_susNames + v50), 1);
    if ( v32 )
    {
      v51._Ptr = (Material *)operator new(188);
      LOBYTE(v68) = 34;
      if ( v51._Ptr )
      {
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"SUS_NODE", 8u);
        v2 |= 4u;
        LOBYTE(v68) = 35;
        v49 = v2;
        Node::Node((Node *)v51._Ptr, &result);
      }
      else
      {
        v33 = 0;
      }
      *v22 = v33;
      v68 = 29;
      if ( (v2 & 4) != 0 )
      {
        v2 &= 0xFFFFFFFB;
        v49 = v2;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
      }
      (*v22)->addChild(*v22, (Node *)v32);
      v34 = _mm_loadu_si128((const __m128i *)(v32 + 4));
      v35 = *v22;
      LODWORD(radius) = 16;
      v46._Myres = (unsigned int)L"GRAPHICS_OFFSETS";
      result._Myres = 7;
      *(__m128i *)&v35->matrix.M11 = v34;
      result._Mysize = 0;
      *(__m128i *)&v35->matrix.M21 = _mm_loadu_si128((const __m128i *)(v32 + 20));
      *(__m128i *)&v35->matrix.M31 = _mm_loadu_si128((const __m128i *)(v32 + 36));
      *(__m128i *)&v35->matrix.M41 = _mm_loadu_si128((const __m128i *)(v32 + 52));
      *(_DWORD *)(v32 + 4) = 1065353216;
      *(_DWORD *)(v32 + 8) = 0;
      *(_DWORD *)(v32 + 12) = 0;
      *(_DWORD *)(v32 + 16) = 0;
      *(_DWORD *)(v32 + 20) = 0;
      *(_DWORD *)(v32 + 24) = 1065353216;
      *(_DWORD *)(v32 + 28) = 0;
      *(_DWORD *)(v32 + 32) = 0;
      *(_DWORD *)(v32 + 36) = 0;
      *(_DWORD *)(v32 + 40) = 0;
      *(_DWORD *)(v32 + 44) = 1065353216;
      *(_DWORD *)(v32 + 48) = 0;
      *(_DWORD *)(v32 + 52) = 0;
      *(_DWORD *)(v32 + 56) = 0;
      *(_DWORD *)(v32 + 60) = 0;
      *(_DWORD *)(v32 + 64) = 1065353216;
      result._Bx._Buf[0] = 0;
      std::wstring::assign(&result, (const wchar_t *)v46._Myres, LODWORD(radius));
      LOBYTE(v68) = 37;
      v36 = INIReader::getFloat(&sus_ini, &result, (const std::wstring *)v48);
      v28 = result._Myres < 8;
      *(float *)&v52 = v36;
      *(_QWORD *)(v32 + 52) = v52;
      *(_DWORD *)(v32 + 60) = 0;
      LOBYTE(v68) = 29;
      if ( !v28 )
        operator delete(result._Bx._Ptr);
      this->carNode->addChild(this->carNode, *v22);
      v37 = v50;
    }
    else
    {
      v37 = v50;
      v38 = (const wchar_t *)v48;
      if ( *(unsigned int *)((char *)&_susNames[0]._Myres + v50) >= 8 )
        v38 = (const wchar_t *)v48->__vftable;
      _printf("ERROR, CANNOT LOCATE %S\n", v38);
      _fflush(0);
    }
    v21 = v37 + 24;
    ++v22;
    v50 = v21;
  }
  while ( v21 < 96 );
  v39 = this->carNode;
  v40 = this->bodyTransform;
  radius = 0.0;
  v39->delegateNode = v40;
  NodeBoundingSphere::applyNoCull(this->carNode, (Node *)LODWORD(radius));
  this->car->sim->beforeCarsNode->addChild(this->car->sim->beforeCarsNode, this->carNode);
  v41 = (Material *)operator new(104);
  v51._Ptr = v41;
  v42 = 0;
  LOBYTE(v68) = 38;
  if ( v41 )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"GHOST_MATERIAL", 0xEu);
    v43 = this->game;
    v2 |= 8u;
    LOBYTE(v68) = 39;
    v49 = v2;
    Material::Material(v41, &result, v43->graphics);
  }
  v68 = 40;
  v51 = 0i64;
  std::shared_ptr<Material>::_Resetp<Material>(&v51, v42);
  v44 = this->material._Rep;
  this->material = v51;
  if ( v44 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v44->_Uses, 0xFFFFFFFF) )
    {
      v44->_Destroy(v44);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v44->_Weaks) )
        v44->_Delete_this(v44);
    }
  }
  v68 = 29;
  if ( (v2 & 8) != 0 && result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, L"ksColourShader", 0xEu);
  v45 = this->material._Ptr;
  LOBYTE(v68) = 41;
  Material::setShader(v45, v2, &result);
  LOBYTE(v68) = 29;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  this->material._Ptr->blendMode = eAlphaBlend;
  this->material._Ptr->doubleFace = 0;
  GhostCar::assignGhostMaterial(this, this->carNode);
  LOBYTE(v68) = 22;
  INIReader::~INIReader(&sus_ini);
  LOBYTE(v68) = 21;
  KN5IO::~KN5IO(&kn);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  v68 = -1;
  INIReader::~INIReader(&lodIni);
}
void GhostCar::loadGhostCarParameters(GhostCar *this)
{
  CarAvatar *v2; // ecx
  double v3; // st7
  bool v4; // cf
  double v5; // st7
  double v6; // st7
  vec3f *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  std::wstring key; // [esp+8h] [ebp-B4h] BYREF
  std::wstring section; // [esp+20h] [ebp-9Ch] BYREF
  std::wstring v16; // [esp+38h] [ebp-84h] BYREF
  std::wstring filename; // [esp+50h] [ebp-6Ch] BYREF
  INIReader r; // [esp+68h] [ebp-54h] BYREF
  int v19; // [esp+B8h] [ebp-4h]

  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"system/cfg/ghost_car.ini", 0x18u);
  v2 = this->car;
  v19 = 0;
  CarAvatar::openINI(v2, &r, &filename);
  LOBYTE(v19) = 2;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_DISTANCE", 0xCu);
    LOBYTE(v19) = 3;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GHOST_CAR", 9u);
    LOBYTE(v19) = 4;
    v3 = INIReader::getFloat(&r, &section, &key);
    v4 = section._Myres < 8;
    this->minDistance = v3;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v19) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_DISTANCE", 0xCu);
    LOBYTE(v19) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GHOST_CAR", 9u);
    LOBYTE(v19) = 6;
    v5 = INIReader::getFloat(&r, &section, &key);
    v4 = section._Myres < 8;
    this->maxDistance = v5;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v19) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_OPACITY", 0xBu);
    LOBYTE(v19) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"GHOST_CAR", 9u);
    LOBYTE(v19) = 8;
    v6 = INIReader::getFloat(&r, &section, &key);
    v4 = section._Myres < 8;
    this->maxOpacity = v6;
    if ( !v4 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v19) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"COLOR", 5u);
    LOBYTE(v19) = 9;
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    std::wstring::assign(&v16, L"GHOST_CAR", 9u);
    LOBYTE(v19) = 10;
    v7 = INIReader::getFloat3(&r, (vec3f *)&section, &v16, &key);
    v4 = v16._Myres < 8;
    this->gcColor = *v7;
    if ( !v4 )
      operator delete(v16._Bx._Ptr);
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v8 = this->gcColor.x * 0.0039215689;
    key._Bx._Buf[0] = 0;
    key._Myres = 7;
    key._Mysize = 0;
    this->gcColor.x = v8;
    this->gcColor.y = this->gcColor.y * 0.0039215689;
    v9 = this->gcColor.z * 0.0039215689;
    this->gcColor.z = v9;
    v10 = v9;
    v11 = this->gcColor.y;
    v12 = this->gcColor.x;
    v13 = fsqrt((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v9 * v9));
    if ( v13 != 0.0 )
    {
      this->gcColor.x = (float)(1.0 / v13) * v12;
      this->gcColor.y = (float)(1.0 / v13) * v11;
      this->gcColor.z = (float)(1.0 / v13) * v10;
    }
  }
  v19 = -1;
  INIReader::~INIReader(&r);
}
void __userpurge GhostCar::update(GhostCar *this@<ecx>, int a2@<edi>, float dt)
{
  GhostCarRecorder *v4; // ecx
  GhostCarRecorder *v5; // ecx
  long double v6; // xmm3_8
  GhostCarRecorder *v7; // ecx
  const mat44f *v8; // eax
  const __m128i *v9; // eax
  Node *v10; // ecx
  int v11; // edi
  Node **v12; // ebx
  GhostCarRecorder *v13; // ecx
  const __m128i *v14; // eax
  int v15; // ecx
  const __m128i *v16; // eax
  Node *v17; // ecx
  ReplayManager *v18; // ecx
  bool v19; // bl
  CarAvatar *v20; // eax
  float v21; // xmm3_4
  Node *v22; // ecx
  float *v23; // eax
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float *v27; // eax
  float v28; // xmm1_4
  bool v29; // cc
  Material *v30; // ecx
  mat44f *v31; // [esp-4h] [ebp-90h]
  float v32; // [esp+10h] [ebp-7Ch] BYREF
  vec4f value; // [esp+14h] [ebp-78h] BYREF
  mat44f result; // [esp+24h] [ebp-68h] BYREF
  std::wstring name; // [esp+64h] [ebp-28h] BYREF
  int v36; // [esp+88h] [ebp-4h]

  v4 = this->gcRecorder;
  this->playCounter = 0.0;
  if ( GhostCarRecorder::shouldDisplayGhostCar(v4) )
  {
    v5 = this->gcRecorder;
    v6 = (double)this->car->physicsState.lapTime + v5->advantageTimeMS;
    v5->blend = (v6 - (double)(int)(1.0 / 129.0 * v6) * 129.0) * (1.0 / 129.0);
    GhostCarRecorder::setCurrentFrame(this->gcRecorder, (int)(1.0 / 129.0 * v6));
    v7 = this->gcRecorder;
    if ( v7->version < 4 )
    {
      v9 = (const __m128i *)GhostCarRecorder::getBodyMatrix(v7, &result);
      v10 = this->bodyTransform;
      *(__m128i *)&v10->matrix.M11 = _mm_loadu_si128(v9);
      *(__m128i *)&v10->matrix.M21 = _mm_loadu_si128(v9 + 1);
      *(__m128i *)&v10->matrix.M31 = _mm_loadu_si128(v9 + 2);
      *(__m128i *)&v10->matrix.M41 = _mm_loadu_si128(v9 + 3);
    }
    else
    {
      v31 = &this->bodyTransform->matrix;
      v8 = GhostCarRecorder::getBodyMatrix(v7, &result);
      CarAvatar::makeBodyMatrix(this->car, a2, (int)this, v8, v31);
    }
    v11 = 0;
    v12 = this->susTransforms;
    do
    {
      v13 = this->gcRecorder;
      if ( v13->suspensionWheelsEnabled )
      {
        v14 = (const __m128i *)GhostCarRecorder::getTyreMatrix(v13, &result, v11);
        v15 = (int)*(v12 - 4);
        *(__m128i *)(v15 + 4) = _mm_loadu_si128(v14);
        *(__m128i *)(v15 + 20) = _mm_loadu_si128(v14 + 1);
        *(__m128i *)(v15 + 36) = _mm_loadu_si128(v14 + 2);
        *(__m128i *)(v15 + 52) = _mm_loadu_si128(v14 + 3);
        if ( *v12 )
        {
          v16 = (const __m128i *)GhostCarRecorder::getSuspensionMatrix(this->gcRecorder, &result, v11);
          v17 = *v12;
          *(__m128i *)&v17->matrix.M11 = _mm_loadu_si128(v16);
          *(__m128i *)&v17->matrix.M21 = _mm_loadu_si128(v16 + 1);
          *(__m128i *)&v17->matrix.M31 = _mm_loadu_si128(v16 + 2);
          *(__m128i *)&v17->matrix.M41 = _mm_loadu_si128(v16 + 3);
        }
      }
      ++v11;
      ++v12;
    }
    while ( v11 < 4 );
  }
  v19 = 0;
  if ( GhostCarRecorder::shouldDisplayGhostCar(this->gcRecorder) )
  {
    v18 = this->car->sim->replayManager;
    if ( !v18->isActive && !ReplayManager::isInReplaymode(v18) )
      v19 = 1;
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"colour", 6u);
  v20 = this->car;
  v21 = 0.0;
  v22 = this->bodyTransform;
  v36 = 0;
  v23 = (float *)v20->bodyTransform;
  v24 = (float)((float)((float)(v22->matrix.M42 - v23[14]) * (float)(v22->matrix.M42 - v23[14]))
              + (float)((float)(v22->matrix.M41 - v23[13]) * (float)(v22->matrix.M41 - v23[13])))
      + (float)((float)(v22->matrix.M43 - v23[15]) * (float)(v22->matrix.M43 - v23[15]));
  if ( v24 == 0.0 )
    v25 = 0.0;
  else
    v25 = fsqrt(v24);
  v26 = this->minDistance;
  if ( v25 > v26 )
  {
    v27 = &v32;
    v28 = (float)((float)(v25 - v26) / (float)(this->maxDistance - v26)) * this->maxOpacity;
    v29 = v28 <= this->maxOpacity;
    v32 = v28;
    if ( !v29 )
      v27 = &this->maxOpacity;
    v21 = *v27;
  }
  v30 = this->material._Ptr;
  value.x = this->gcColor.x;
  value.y = this->gcColor.y;
  value.z = this->gcColor.z;
  value.w = v21;
  Material::setVar(v30, &name, &value);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  this->carNode->isActive = v19;
}
