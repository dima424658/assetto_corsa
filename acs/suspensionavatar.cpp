#include "suspensionavatar.h
void SuspensionAvatar::SuspensionAvatar(SuspensionAvatar *this, CarAvatar *car)
{
  int v3; // ebx
  Node **v4; // esi
  Node *v5; // edi
  Node *v6; // eax
  Node *v7; // edi
  Node *v8; // eax
  Node *v9; // edi
  Node *v10; // eax
  std::wstring v11; // [esp-1Ch] [ebp-6Ch] BYREF
  Game *v12; // [esp-4h] [ebp-54h]
  int v13; // [esp+14h] [ebp-3Ch]
  int v14; // [esp+18h] [ebp-38h]
  Node *v15; // [esp+1Ch] [ebp-34h]
  SuspensionAvatar *v16; // [esp+20h] [ebp-30h]
  SuspensionAvatar *v17; // [esp+24h] [ebp-2Ch]
  std::wstring n; // [esp+28h] [ebp-28h] BYREF
  int v19; // [esp+4Ch] [ebp-4h]

  v16 = this;
  v3 = 0;
  v14 = 0;
  v17 = this;
  v12 = car->game;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, L"SUSPENSION_AVATAR", 0x11u);
  GameObject::GameObject(this, v11, v12);
  this->ISuspensionAvatar::__vftable = (ISuspensionAvatar_vtbl *)&ISuspensionAvatar::`vftable';
  this->GameObject::__vftable = (SuspensionAvatar_vtbl *)&SuspensionAvatar::`vftable'{for `GameObject'};
  this->ISuspensionAvatar::__vftable = (ISuspensionAvatar_vtbl *)&SuspensionAvatar::`vftable'{for `ISuspensionAvatar'};
  this->rearAxle = 0;
  this->isGraphicsRadiusInitialized = 0;
  this->car = car;
  this->graphicsRadius[0] = 0.0;
  this->graphicsRadius[1] = 0.0;
  v4 = this->susTransforms;
  v19 = 0;
  v13 = 4;
  do
  {
    v5 = (Node *)operator new(188);
    v15 = v5;
    v6 = 0;
    LOBYTE(v19) = 1;
    if ( v5 )
    {
      n._Myres = 7;
      n._Mysize = 0;
      n._Bx._Buf[0] = 0;
      std::wstring::assign(&n, L"WHEEL_TR", 8u);
      LOBYTE(v19) = 2;
      v3 |= 1u;
      v14 = v3;
      Node::Node(v5, &n);
    }
    *(v4 - 4) = v6;
    v19 = 0;
    if ( (v3 & 1) != 0 )
    {
      v3 &= 0xFFFFFFFE;
      if ( n._Myres >= 8 )
        operator delete(n._Bx._Ptr);
    }
    car->carNode->addChild(car->carNode, *(v4 - 4));
    v7 = (Node *)operator new(188);
    v15 = v7;
    v8 = 0;
    LOBYTE(v19) = 4;
    if ( v7 )
    {
      n._Myres = 7;
      n._Mysize = 0;
      n._Bx._Buf[0] = 0;
      std::wstring::assign(&n, L"SUS_TRANSFORM", 0xDu);
      LOBYTE(v19) = 5;
      v3 |= 2u;
      v14 = v3;
      Node::Node(v7, &n);
    }
    *v4 = v8;
    v19 = 0;
    if ( (v3 & 2) != 0 )
    {
      v3 &= 0xFFFFFFFD;
      if ( n._Myres >= 8 )
        operator delete(n._Bx._Ptr);
    }
    car->carNode->addChild(car->carNode, *v4);
    v9 = (Node *)operator new(188);
    v15 = v9;
    v10 = 0;
    LOBYTE(v19) = 7;
    if ( v9 )
    {
      n._Myres = 7;
      n._Mysize = 0;
      n._Bx._Buf[0] = 0;
      std::wstring::assign(&n, L"DISC_TRANSFORM", 0xEu);
      LOBYTE(v19) = 8;
      v3 |= 4u;
      v14 = v3;
      Node::Node(v9, &n);
    }
    v4[4] = v10;
    v19 = 0;
    if ( (v3 & 4) != 0 )
    {
      v3 &= 0xFFFFFFFB;
      if ( n._Myres >= 8 )
        operator delete(n._Bx._Ptr);
    }
    car->carNode->addChild(car->carNode, v4[4]);
    ++v4;
    --v13;
  }
  while ( v13 );
}
SuspensionAvatar *SuspensionAvatar::`vector deleting destructor'(SuspensionAvatar *this, unsigned int a2)
{
  this->GameObject::__vftable = (SuspensionAvatar_vtbl *)&SuspensionAvatar::`vftable'{for `GameObject'};
  this->ISuspensionAvatar::__vftable = (ISuspensionAvatar_vtbl *)&SuspensionAvatar::`vftable'{for `ISuspensionAvatar'};
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SuspensionAvatar::addModel(SuspensionAvatar *this, Node *root)
{
  SuspensionAvatar *v2; // ebp
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  CarAvatar *v5; // ecx
  char *v6; // ebp
  int i; // edi
  Node *v8; // esi
  double v9; // st7
  bool v10; // cf
  Node *v11; // esi
  double v12; // st7
  Node *v13; // esi
  double v14; // st7
  Node_vtbl *v15; // eax
  Node *v16; // esi
  SuspensionAvatar *v17; // ebx
  Node *v18; // edi
  ISuspensionAvatar_vtbl *v19; // eax
  float v21; // [esp+58h] [ebp-E0h]
  char v22; // [esp+5Ch] [ebp-DCh]
  unsigned int v23; // [esp+60h] [ebp-D8h]
  std::wstring section; // [esp+6Ch] [ebp-CCh] BYREF
  std::wstring v25; // [esp+84h] [ebp-B4h] BYREF
  std::wstring n; // [esp+9Ch] [ebp-9Ch] BYREF
  std::wstring v27; // [esp+B4h] [ebp-84h] BYREF
  std::wstring result; // [esp+CCh] [ebp-6Ch] BYREF
  INIReader sus_ini; // [esp+E4h] [ebp-54h] BYREF
  int v30; // [esp+134h] [ebp-4h]

  v2 = this;
  v22 = 0;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", (const std::wstring *)&this->wheelTransforms[0]->name._Mysize);
  v30 = 0;
  v4 = std::operator+<wchar_t>(&v27, v3, L"/data/suspensions.ini");
  v5 = (CarAvatar *)v2->wheelTransforms[0];
  LOBYTE(v30) = 1;
  CarAvatar::openINI(v5, &sus_ini, v4);
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  LOBYTE(v30) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  v6 = &v2->name._Bx._Alias[12];
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  for ( i = 0; i < 4; ++i )
  {
    v8 = root->findChildByName(root, &wheelNames_0[i], 1);
    if ( v8 )
    {
      v8->matrix.M11 = 1.0;
      v8->matrix.M12 = 0.0;
      v8->matrix.M13 = 0.0;
      v8->matrix.M14 = 0.0;
      v8->matrix.M21 = 0.0;
      v8->matrix.M22 = 1.0;
      v8->matrix.M23 = 0.0;
      v8->matrix.M24 = 0.0;
      v8->matrix.M31 = 0.0;
      v8->matrix.M32 = 0.0;
      v8->matrix.M33 = 1.0;
      v8->matrix.M34 = 0.0;
      v8->matrix.M41 = 0.0;
      v8->matrix.M42 = 0.0;
      v8->matrix.M43 = 0.0;
      v8->matrix.M44 = 1.0;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"GRAPHICS_OFFSETS", 0x10u);
      LOBYTE(v30) = 5;
      v9 = INIReader::getFloat(&sus_ini, &section, &wheelNames_0[i]);
      v10 = section._Myres < 8;
      *(float *)&v23 = v9;
      *(_QWORD *)&v8->matrix.M41 = v23;
      v8->matrix.M43 = 0.0;
      LOBYTE(v30) = 4;
      if ( !v10 )
        operator delete(section._Bx._Ptr);
      (*(void (**)(_DWORD, Node *))(**((_DWORD **)v6 - 4) + 4))(*((_DWORD *)v6 - 4), v8);
    }
    v11 = root->findChildByName(root, &susNames_0[i], 1);
    if ( v11 )
    {
      v11->matrix.M11 = 1.0;
      v11->matrix.M12 = 0.0;
      v11->matrix.M13 = 0.0;
      v11->matrix.M14 = 0.0;
      v11->matrix.M21 = 0.0;
      v11->matrix.M22 = 1.0;
      v11->matrix.M23 = 0.0;
      v11->matrix.M24 = 0.0;
      v11->matrix.M31 = 0.0;
      v11->matrix.M32 = 0.0;
      v11->matrix.M33 = 1.0;
      v11->matrix.M34 = 0.0;
      v11->matrix.M41 = 0.0;
      v11->matrix.M42 = 0.0;
      v11->matrix.M43 = 0.0;
      v11->matrix.M44 = 1.0;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"GRAPHICS_OFFSETS", 0x10u);
      LOBYTE(v30) = 6;
      v12 = INIReader::getFloat(&sus_ini, &section, &susNames_0[i]);
      v10 = section._Myres < 8;
      *(float *)&n._Bx._Ptr = v12;
      *(_QWORD *)&v11->matrix.M41 = (unsigned int)n._Bx._Ptr;
      v11->matrix.M43 = 0.0;
      LOBYTE(v30) = 4;
      if ( !v10 )
        operator delete(section._Bx._Ptr);
      (*(void (**)(_DWORD, Node *))(**(_DWORD **)v6 + 4))(*(_DWORD *)v6, v11);
    }
    v13 = root->findChildByName(root, &discNames_1[i], 1);
    if ( v13 )
    {
      v13->matrix.M11 = 1.0;
      v13->matrix.M12 = 0.0;
      v13->matrix.M13 = 0.0;
      v13->matrix.M14 = 0.0;
      v13->matrix.M21 = 0.0;
      v13->matrix.M22 = 1.0;
      v13->matrix.M23 = 0.0;
      v13->matrix.M24 = 0.0;
      v13->matrix.M31 = 0.0;
      v13->matrix.M32 = 0.0;
      v13->matrix.M33 = 1.0;
      v13->matrix.M34 = 0.0;
      v13->matrix.M41 = 0.0;
      v13->matrix.M42 = 0.0;
      v13->matrix.M43 = 0.0;
      v13->matrix.M44 = 1.0;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"GRAPHICS_OFFSETS", 0x10u);
      LOBYTE(v30) = 7;
      v14 = INIReader::getFloat(&sus_ini, &section, &wheelNames_0[i]);
      v10 = section._Myres < 8;
      *(float *)&v25._Bx._Ptr = v14;
      *(_QWORD *)&v13->matrix.M41 = (unsigned int)v25._Bx._Ptr;
      v13->matrix.M43 = 0.0;
      LOBYTE(v30) = 4;
      if ( !v10 )
        operator delete(section._Bx._Ptr);
      (*(void (**)(_DWORD, Node *))(**((_DWORD **)v6 + 4) + 4))(*((_DWORD *)v6 + 4), v13);
    }
    v6 += 4;
  }
  v25._Myres = 7;
  v25._Mysize = 0;
  v25._Bx._Buf[0] = 0;
  std::wstring::assign(&v25, L"REAR_AXLE", 9u);
  v15 = root->__vftable;
  LOBYTE(v30) = 8;
  v16 = v15->findChildByName(root, &v25, 1);
  LOBYTE(v30) = 4;
  if ( v25._Myres >= 8 )
    operator delete(v25._Bx._Ptr);
  v17 = this;
  v25._Myres = 7;
  v25._Mysize = 0;
  v25._Bx._Buf[0] = 0;
  if ( v16 )
  {
    if ( !this->ISuspensionAvatar::__vftable )
    {
      v18 = (Node *)operator new(188);
      v19 = 0;
      LOBYTE(v30) = 9;
      if ( v18 )
      {
        n._Myres = 7;
        n._Mysize = 0;
        n._Bx._Buf[0] = 0;
        std::wstring::assign(&n, L"REAR_AXLE_TRANSFORM", 0x13u);
        LOBYTE(v30) = 10;
        v22 = 1;
        Node::Node(v18, &n);
      }
      this->ISuspensionAvatar::__vftable = v19;
      v30 = 4;
      if ( (v22 & 1) != 0 )
      {
        if ( n._Myres >= 8 )
          operator delete(n._Bx._Ptr);
        n._Myres = 7;
        n._Mysize = 0;
        n._Bx._Buf[0] = 0;
      }
      (*(void (**)(wchar_t *, ISuspensionAvatar_vtbl *))(*(_DWORD *)this->wheelTransforms[0][1].name._Bx._Ptr
                                                                  + 4))(
        this->wheelTransforms[0][1].name._Bx._Ptr,
        this->ISuspensionAvatar::__vftable);
    }
    v16->matrix.M11 = 1.0;
    v16->matrix.M12 = 0.0;
    v16->matrix.M13 = 0.0;
    v16->matrix.M14 = 0.0;
    v16->matrix.M21 = 0.0;
    v16->matrix.M22 = 1.0;
    v16->matrix.M23 = 0.0;
    v16->matrix.M24 = 0.0;
    v16->matrix.M31 = 0.0;
    v16->matrix.M32 = 0.0;
    v16->matrix.M33 = 1.0;
    v16->matrix.M34 = 0.0;
    v16->matrix.M41 = 0.0;
    v16->matrix.M42 = 0.0;
    v16->matrix.M43 = 0.0;
    v16->matrix.M44 = 1.0;
    (*((void (**)(ISuspensionAvatar_vtbl *, Node *))this->addModel + 1))(
      this->ISuspensionAvatar::__vftable,
      v16);
  }
  if ( !LOBYTE(this->wheelTransforms[3]) )
  {
    *(float *)&this->wheelTransforms[1] = get_node_radius((Node *)this->game, 0.0);
    v21 = get_node_radius((Node *)*(_DWORD *)&this->name._Bx._Alias[4], 0.0);
    *(float *)&v17->wheelTransforms[2] = v21;
    _printf("GRAPHICS RADIUS: %f %f\n", *(float *)&v17->wheelTransforms[1], v21);
    LOBYTE(v17->wheelTransforms[3]) = 1;
  }
  v30 = -1;
  INIReader::~INIReader(&sus_ini);
}
double SuspensionAvatar::getGraphicsRadius(SuspensionAvatar *this, int index)
{
  return *(float *)&this->wheelTransforms[index + 1];
}
Node *SuspensionAvatar::getSusTransform(SuspensionAvatar *this, int index)
{
  return *(Node **)&this->name._Bx._Alias[4 * index + 12];
}
Node *SuspensionAvatar::getWheelTransform(SuspensionAvatar *this, int index)
{
  return (Node *)*((_DWORD *)&this->game + index);
}
void SuspensionAvatar::update(SuspensionAvatar *this, float dt)
{
  Node *v2; // edx
  CarAvatar *v3; // eax
  Node *v4; // edx
  CarAvatar *v5; // eax
  Node *v6; // edx
  CarAvatar *v7; // eax
  Node *v8; // edx
  CarAvatar *v9; // eax
  Node *v10; // edx
  CarAvatar *v11; // eax
  Node *v12; // edx
  CarAvatar *v13; // eax
  Node *v14; // edx
  CarAvatar *v15; // eax
  Node *v16; // edx
  CarAvatar *v17; // eax
  Node *v18; // edx
  CarAvatar *v19; // eax
  Node *v20; // edx
  CarAvatar *v21; // eax
  Node *v22; // edx
  CarAvatar *v23; // eax
  Node *v24; // edx
  CarAvatar *v25; // eax
  Node *v26; // edx
  CarAvatar *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  Node *v31; // eax

  v2 = this->wheelTransforms[0];
  if ( v2 )
  {
    v3 = this->car;
    *(__m128i *)&v2->matrix.M11 = _mm_loadu_si128((const __m128i *)v3->physicsState.tyreMatrix);
    *(__m128i *)&v2->matrix.M21 = _mm_loadu_si128((const __m128i *)&v3->physicsState.tyreMatrix[0].M21);
    *(__m128i *)&v2->matrix.M31 = _mm_loadu_si128((const __m128i *)&v3->physicsState.tyreMatrix[0].M31);
    *(__m128i *)&v2->matrix.M41 = _mm_loadu_si128((const __m128i *)&v3->physicsState.tyreMatrix[0].M41);
  }
  v4 = this->susTransforms[0];
  if ( v4 )
  {
    v5 = this->car;
    *(__m128i *)&v4->matrix.M11 = _mm_loadu_si128((const __m128i *)v5->physicsState.suspensionMatrix);
    *(__m128i *)&v4->matrix.M21 = _mm_loadu_si128((const __m128i *)&v5->physicsState.suspensionMatrix[0].M21);
    *(__m128i *)&v4->matrix.M31 = _mm_loadu_si128((const __m128i *)&v5->physicsState.suspensionMatrix[0].M31);
    *(__m128i *)&v4->matrix.M41 = _mm_loadu_si128((const __m128i *)&v5->physicsState.suspensionMatrix[0].M41);
  }
  v6 = this->discTransforms[0];
  if ( v6 )
  {
    v7 = this->car;
    *(__m128i *)&v6->matrix.M11 = _mm_loadu_si128((const __m128i *)v7->physicsState.tyreMatrix);
    *(__m128i *)&v6->matrix.M21 = _mm_loadu_si128((const __m128i *)&v7->physicsState.tyreMatrix[0].M21);
    *(__m128i *)&v6->matrix.M31 = _mm_loadu_si128((const __m128i *)&v7->physicsState.tyreMatrix[0].M31);
    *(__m128i *)&v6->matrix.M41 = _mm_loadu_si128((const __m128i *)&v7->physicsState.tyreMatrix[0].M41);
  }
  v8 = this->wheelTransforms[1];
  if ( v8 )
  {
    v9 = this->car;
    *(__m128i *)&v8->matrix.M11 = _mm_loadu_si128((const __m128i *)&v9->physicsState.tyreMatrix[1]);
    *(__m128i *)&v8->matrix.M21 = _mm_loadu_si128((const __m128i *)&v9->physicsState.tyreMatrix[1].M21);
    *(__m128i *)&v8->matrix.M31 = _mm_loadu_si128((const __m128i *)&v9->physicsState.tyreMatrix[1].M31);
    *(__m128i *)&v8->matrix.M41 = _mm_loadu_si128((const __m128i *)&v9->physicsState.tyreMatrix[1].M41);
  }
  v10 = this->susTransforms[1];
  if ( v10 )
  {
    v11 = this->car;
    *(__m128i *)&v10->matrix.M11 = _mm_loadu_si128((const __m128i *)&v11->physicsState.suspensionMatrix[1]);
    *(__m128i *)&v10->matrix.M21 = _mm_loadu_si128((const __m128i *)&v11->physicsState.suspensionMatrix[1].M21);
    *(__m128i *)&v10->matrix.M31 = _mm_loadu_si128((const __m128i *)&v11->physicsState.suspensionMatrix[1].M31);
    *(__m128i *)&v10->matrix.M41 = _mm_loadu_si128((const __m128i *)&v11->physicsState.suspensionMatrix[1].M41);
  }
  v12 = this->discTransforms[1];
  if ( v12 )
  {
    v13 = this->car;
    *(__m128i *)&v12->matrix.M11 = _mm_loadu_si128((const __m128i *)&v13->physicsState.tyreMatrix[1]);
    *(__m128i *)&v12->matrix.M21 = _mm_loadu_si128((const __m128i *)&v13->physicsState.tyreMatrix[1].M21);
    *(__m128i *)&v12->matrix.M31 = _mm_loadu_si128((const __m128i *)&v13->physicsState.tyreMatrix[1].M31);
    *(__m128i *)&v12->matrix.M41 = _mm_loadu_si128((const __m128i *)&v13->physicsState.tyreMatrix[1].M41);
  }
  v14 = this->wheelTransforms[2];
  if ( v14 )
  {
    v15 = this->car;
    *(__m128i *)&v14->matrix.M11 = _mm_loadu_si128((const __m128i *)&v15->physicsState.tyreMatrix[2]);
    *(__m128i *)&v14->matrix.M21 = _mm_loadu_si128((const __m128i *)&v15->physicsState.tyreMatrix[2].M21);
    *(__m128i *)&v14->matrix.M31 = _mm_loadu_si128((const __m128i *)&v15->physicsState.tyreMatrix[2].M31);
    *(__m128i *)&v14->matrix.M41 = _mm_loadu_si128((const __m128i *)&v15->physicsState.tyreMatrix[2].M41);
  }
  v16 = this->susTransforms[2];
  if ( v16 )
  {
    v17 = this->car;
    *(__m128i *)&v16->matrix.M11 = _mm_loadu_si128((const __m128i *)&v17->physicsState.suspensionMatrix[2]);
    *(__m128i *)&v16->matrix.M21 = _mm_loadu_si128((const __m128i *)&v17->physicsState.suspensionMatrix[2].M21);
    *(__m128i *)&v16->matrix.M31 = _mm_loadu_si128((const __m128i *)&v17->physicsState.suspensionMatrix[2].M31);
    *(__m128i *)&v16->matrix.M41 = _mm_loadu_si128((const __m128i *)&v17->physicsState.suspensionMatrix[2].M41);
  }
  v18 = this->discTransforms[2];
  if ( v18 )
  {
    v19 = this->car;
    *(__m128i *)&v18->matrix.M11 = _mm_loadu_si128((const __m128i *)&v19->physicsState.tyreMatrix[2]);
    *(__m128i *)&v18->matrix.M21 = _mm_loadu_si128((const __m128i *)&v19->physicsState.tyreMatrix[2].M21);
    *(__m128i *)&v18->matrix.M31 = _mm_loadu_si128((const __m128i *)&v19->physicsState.tyreMatrix[2].M31);
    *(__m128i *)&v18->matrix.M41 = _mm_loadu_si128((const __m128i *)&v19->physicsState.tyreMatrix[2].M41);
  }
  v20 = this->wheelTransforms[3];
  if ( v20 )
  {
    v21 = this->car;
    *(__m128i *)&v20->matrix.M11 = _mm_loadu_si128((const __m128i *)&v21->physicsState.tyreMatrix[3]);
    *(__m128i *)&v20->matrix.M21 = _mm_loadu_si128((const __m128i *)&v21->physicsState.tyreMatrix[3].M21);
    *(__m128i *)&v20->matrix.M31 = _mm_loadu_si128((const __m128i *)&v21->physicsState.tyreMatrix[3].M31);
    *(__m128i *)&v20->matrix.M41 = _mm_loadu_si128((const __m128i *)&v21->physicsState.tyreMatrix[3].M41);
  }
  v22 = this->susTransforms[3];
  if ( v22 )
  {
    v23 = this->car;
    *(__m128i *)&v22->matrix.M11 = _mm_loadu_si128((const __m128i *)&v23->physicsState.suspensionMatrix[3]);
    *(__m128i *)&v22->matrix.M21 = _mm_loadu_si128((const __m128i *)&v23->physicsState.suspensionMatrix[3].M21);
    *(__m128i *)&v22->matrix.M31 = _mm_loadu_si128((const __m128i *)&v23->physicsState.suspensionMatrix[3].M31);
    *(__m128i *)&v22->matrix.M41 = _mm_loadu_si128((const __m128i *)&v23->physicsState.suspensionMatrix[3].M41);
  }
  v24 = this->discTransforms[3];
  if ( v24 )
  {
    v25 = this->car;
    *(__m128i *)&v24->matrix.M11 = _mm_loadu_si128((const __m128i *)&v25->physicsState.tyreMatrix[3]);
    *(__m128i *)&v24->matrix.M21 = _mm_loadu_si128((const __m128i *)&v25->physicsState.tyreMatrix[3].M21);
    *(__m128i *)&v24->matrix.M31 = _mm_loadu_si128((const __m128i *)&v25->physicsState.tyreMatrix[3].M31);
    *(__m128i *)&v24->matrix.M41 = _mm_loadu_si128((const __m128i *)&v25->physicsState.tyreMatrix[3].M41);
  }
  v26 = this->rearAxle;
  if ( v26 )
  {
    v27 = this->car;
    v28 = (float)(v27->physicsState.suspensionMatrix[2].M41 + v27->physicsState.suspensionMatrix[3].M41) * 0.5;
    v29 = (float)(v27->physicsState.suspensionMatrix[2].M42 + v27->physicsState.suspensionMatrix[3].M42) * 0.5;
    v30 = (float)(v27->physicsState.suspensionMatrix[2].M43 + v27->physicsState.suspensionMatrix[3].M43) * 0.5;
    *(__m128i *)&v26->matrix.M11 = _mm_loadu_si128((const __m128i *)&v27->physicsState.suspensionMatrix[2]);
    *(__m128i *)&v26->matrix.M21 = _mm_loadu_si128((const __m128i *)&v27->physicsState.suspensionMatrix[2].M21);
    *(__m128i *)&v26->matrix.M31 = _mm_loadu_si128((const __m128i *)&v27->physicsState.suspensionMatrix[2].M31);
    *(__m128i *)&v26->matrix.M41 = _mm_loadu_si128((const __m128i *)&v27->physicsState.suspensionMatrix[2].M41);
    v31 = this->rearAxle;
    v31->matrix.M41 = v28;
    v31->matrix.M42 = v29;
    v31->matrix.M43 = v30;
  }
}
