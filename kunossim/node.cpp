#include "node.h
bool Node::getActive(Node *this)
{
  return this->isActive;
}
void Node::setActive(Node *this, bool a)
{
  this->isActive = a;
}
Mesh *Node::getNodeChild<Mesh>(Node *this, std::wstring name, bool recursive)
{
  Node **v4; // esi
  Node *v5; // ecx
  std::wstring *v6; // eax
  std::wstring *v7; // ecx
  Mesh *v8; // edi
  std::wstring v10; // [esp-1Ch] [ebp-3Ch] BYREF
  unsigned int v11; // [esp-4h] [ebp-24h]
  int v12; // [esp+1Ch] [ebp-4h]

  v4 = this->nodes._Myfirst;
  v12 = 0;
  if ( v4 == this->nodes._Mylast )
  {
LABEL_9:
    v8 = 0;
  }
  else
  {
    while ( 1 )
    {
      v5 = *v4;
      v6 = &name;
      v11 = name._Mysize;
      v7 = &v5->name;
      if ( name._Myres >= 8 )
        v6 = (std::wstring *)name._Bx._Ptr;
      if ( !std::wstring::compare(v7, 0, v7->_Mysize, v6->_Bx._Buf, v11) )
      {
        v8 = (Mesh *)__RTDynamicCast(*v4, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
        if ( v8 )
          break;
      }
      if ( recursive )
      {
        v11 = 1;
        v10._Myres = 7;
        v10._Mysize = 0;
        v10._Bx._Buf[0] = 0;
        std::wstring::assign(&v10, &name, 0, 0xFFFFFFFF);
        v8 = Node::getNodeChild<Mesh>(*v4, v10, v11);
        if ( v8 )
          break;
      }
      if ( ++v4 == this->nodes._Mylast )
        goto LABEL_9;
    }
  }
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  return v8;
}
void Node::Node(Node *this, const Node *node)
{
  this->__vftable = (Node_vtbl *)&Node::`vftable';
  mat44f::mat44f(&this->matrix);
  mat44f::mat44f(&this->matrixWS);
  this->nodes._Myfirst = 0;
  this->nodes._Mylast = 0;
  this->nodes._Myend = 0;
  this->parent = 0;
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  if ( &this->name != &node->name )
    std::wstring::assign(&this->name, &node->name, 0, 0xFFFFFFFF);
  this->isActive = node->isActive;
  this->parent = 0;
  *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&node->matrix);
  *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&node->matrix.M21);
  *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&node->matrix.M31);
  *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&node->matrix.M41);
  this->isWSIdentity = node->isWSIdentity;
  *(__m128i *)&this->matrixWS.M11 = _mm_loadu_si128((const __m128i *)&node->matrixWS);
  *(__m128i *)&this->matrixWS.M21 = _mm_loadu_si128((const __m128i *)&node->matrixWS.M21);
  *(__m128i *)&this->matrixWS.M31 = _mm_loadu_si128((const __m128i *)&node->matrixWS.M31);
  *(__m128i *)&this->matrixWS.M41 = _mm_loadu_si128((const __m128i *)&node->matrixWS.M41);
  this->priority = node->priority;
  this->needsMatrixWS = node->needsMatrixWS;
}
void Node::Node(Node *this, const std::wstring *n)
{
  this->__vftable = (Node_vtbl *)&Node::`vftable';
  mat44f::mat44f(&this->matrix);
  mat44f::mat44f(&this->matrixWS);
  this->nodes._Myfirst = 0;
  this->nodes._Mylast = 0;
  this->nodes._Myend = 0;
  this->parent = 0;
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  std::wstring::assign(&this->name, n, 0, 0xFFFFFFFF);
  this->parent = 0;
  this->isActive = 1;
  mat44f::loadIdentity(&this->matrix);
  mat44f::loadIdentity(&this->matrixWS);
  this->isWSIdentity = 0;
  this->priority = 0;
  this->needsMatrixWS = 1;
}
void Node::~Node(Node *this)
{
  std::vector<Node *> *v1; // ebp
  Node **v2; // esi
  unsigned int v3; // ebx
  int v4; // edi
  Node *v5; // [esp+14h] [ebp-10h]

  v5 = this;
  this->__vftable = (Node_vtbl *)&Node::`vftable';
  v1 = &this->nodes;
  v2 = this->nodes._Myfirst;
  v3 = (unsigned int)((char *)this->nodes._Mylast - (char *)v2 + 3) >> 2;
  v4 = 0;
  if ( v2 > this->nodes._Mylast )
    v3 = 0;
  if ( v3 )
  {
    do
    {
      if ( *v2 )
        ((void (*)(Node *, int))(*v2)->~Node)(*v2, 1);
      ++v4;
      ++v2;
    }
    while ( v4 != v3 );
    this = v5;
  }
  if ( this->name._Myres >= 8 )
  {
    operator delete(this->name._Bx._Ptr);
    this = v5;
  }
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
  if ( v1->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v1);
    operator delete(v1->_Myfirst);
    v1->_Myfirst = 0;
    v1->_Mylast = 0;
    v1->_Myend = 0;
  }
}
Node *Node::`scalar deleting destructor'(Node *this, unsigned int a2)
{
  Node::~Node(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Node::addChild(Node *this, Node *n)
{
  Node *v3; // ecx

  v3 = n->parent;
  if ( v3 )
    v3->removeChild(v3, n);
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->nodes, (ICollisionObject *const *)&n);
  n->parent = this;
}
void Node::compile(Node *this, CompileContext *cc)
{
  Node **v2; // esi
  unsigned int v3; // ebx
  int v4; // edi

  v2 = this->nodes._Myfirst;
  v3 = (unsigned int)((char *)this->nodes._Mylast - (char *)v2 + 3) >> 2;
  v4 = 0;
  if ( v2 > this->nodes._Mylast )
    v3 = 0;
  if ( v3 )
  {
    do
    {
      (*v2)->compile(*v2, cc);
      ++v4;
      ++v2;
    }
    while ( v4 != v3 );
  }
}
Node *Node::findChildByName(Node *this, const std::wstring *sname, bool recursive)
{
  Node **v4; // esi
  const std::wstring *v5; // eax
  Node *result; // eax

  v4 = this->nodes._Myfirst;
  if ( v4 == this->nodes._Mylast )
    return 0;
  while ( 1 )
  {
    v5 = sname->_Myres < 8 ? sname : sname->_Bx._Ptr;
    if ( !std::wstring::compare(&(*v4)->name, 0, (*v4)->name._Mysize, v5->_Bx._Buf, sname->_Mysize) )
      break;
    if ( recursive )
    {
      result = (*v4)->findChildByName(*v4, sname, 1);
      if ( result )
        return result;
    }
    if ( ++v4 == this->nodes._Mylast )
      return 0;
  }
  return *v4;
}
void Node::findChildrenByName(Node *this, const std::wstring *nname, std::vector<Node *> *result)
{
  const std::wstring *v3; // ebx
  std::wstring *v5; // ecx
  const std::wstring *v6; // eax
  int v7; // eax
  std::vector<Node *> *v8; // edx
  Node **v9; // eax
  Node **v10; // esi
  int v11; // edi
  unsigned int v12; // ebp

  v3 = nname;
  v5 = &this->name;
  if ( nname->_Myres < 8 )
    v6 = nname;
  else
    v6 = (const std::wstring *)nname->_Bx._Ptr;
  v7 = std::wstring::compare(v5, 0, v5->_Mysize, v6->_Bx._Buf, nname->_Mysize);
  v8 = result;
  if ( !v7 )
  {
    nname = (const std::wstring *)this;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)result, (ICollisionObject *const *)&nname);
    v8 = result;
  }
  v9 = this->nodes._Mylast;
  v10 = this->nodes._Myfirst;
  v11 = 0;
  v12 = (unsigned int)((char *)v9 - (char *)v10 + 3) >> 2;
  if ( v10 > v9 )
    v12 = 0;
  if ( v12 )
  {
    do
    {
      (*v10)->findChildrenByName(*v10, v3, v8);
      v8 = result;
      ++v10;
      ++v11;
    }
    while ( v11 != v12 );
  }
}
void Node::findChildrenByPrefix(Node *this, const std::wstring *prefix, std::vector<Node *> *result)
{
  const std::wstring *v3; // ebx
  const std::wstring *v5; // eax
  std::wstring *v6; // esi
  std::wstring *v7; // ecx
  wchar_t *v8; // eax
  std::vector<Node *> *v9; // edx
  Node **v10; // eax
  Node **v11; // esi
  int v12; // edi
  unsigned int v13; // ebp

  v3 = prefix;
  if ( prefix->_Myres < 8 )
    v5 = prefix;
  else
    v5 = (const std::wstring *)prefix->_Bx._Ptr;
  v6 = &this->name;
  if ( this->name._Myres < 8 )
    v7 = &this->name;
  else
    v7 = (std::wstring *)v6->_Bx._Ptr;
  if ( this->name._Myres >= 8 )
    v6 = (std::wstring *)v6->_Bx._Ptr;
  v8 = _wcsstr(v7->_Bx._Buf, v5->_Bx._Buf);
  v9 = result;
  if ( v8 == (wchar_t *)v6 )
  {
    prefix = (const std::wstring *)this;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)result, (ICollisionObject *const *)&prefix);
    v9 = result;
  }
  v10 = this->nodes._Mylast;
  v11 = this->nodes._Myfirst;
  v12 = 0;
  v13 = (unsigned int)((char *)v10 - (char *)v11 + 3) >> 2;
  if ( v11 > v10 )
    v13 = 0;
  if ( v13 )
  {
    do
    {
      (*v11)->findChildrenByPrefix(*v11, v3, v9);
      v9 = result;
      ++v11;
      ++v12;
    }
    while ( v12 != v13 );
  }
}
Node *Node::getParent(Node *this)
{
  return this->parent;
}
mat44f *Node::getWorldMatrix(Node *this, mat44f *result)
{
  Node *v2; // ecx
  int v3; // eax
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm2
  __int128 v10; // xmm3
  DirectX::XMMATRIX M2_4; // [esp+4h] [ebp-40h] BYREF

  *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&this->matrix);
  *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
  *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
  *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
  v2 = this->parent;
  if ( v2 )
  {
    v3 = (int)v2->getWorldMatrix(v2, (mat44f *)&M2_4);
    v4 = *(__m128 *)(v3 + 16);
    v5 = *(__m128 *)(v3 + 32);
    v6 = *(__m128 *)(v3 + 48);
    M2_4.r[0] = *(__m128 *)v3;
    v7 = *(__m128 *)&result->M11;
    M2_4.r[1] = v4;
    v8 = *(_OWORD *)&result->M21;
    M2_4.r[2] = v5;
    v9 = *(_OWORD *)&result->M31;
    M2_4.r[3] = v6;
    v10 = *(_OWORD *)&result->M41;
    *(__m128 *)&result->M11 = DirectX::XMMatrixMultiply(M2_4.r, v7);
    *(_OWORD *)&result->M21 = v8;
    *(_OWORD *)&result->M31 = v9;
    *(_OWORD *)&result->M41 = v10;
  }
  return result;
}
vec3f *Node::localToWorld(Node *this, vec3f *result, const vec3f *pos)
{
  mat44f *v3; // eax
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  vec3f *v9; // eax
  char v10[64]; // [esp+0h] [ebp-40h] BYREF

  v3 = this->getWorldMatrix(this, v10);
  v4 = pos->y;
  v5 = pos->z;
  v6 = (float)((float)((float)(v3->M21 * v4) + (float)(v3->M11 * pos->x)) + (float)(v3->M31 * v5)) + v3->M41;
  v7 = (float)((float)((float)(v3->M12 * pos->x) + (float)(v3->M22 * v4)) + (float)(v3->M32 * v5)) + v3->M42;
  v8 = (float)((float)((float)(v3->M13 * pos->x) + (float)(v3->M23 * v4)) + (float)(v3->M33 * v5)) + v3->M43;
  v9 = result;
  result->x = v6;
  result->y = v7;
  result->z = v8;
  return v9;
}
void Node::printTree(Node *this, int ident)
{
  int v3; // esi
  std::wstring *v4; // eax
  Node **v5; // esi
  Node **v6; // eax
  int v7; // edi
  unsigned int v8; // ebx
  int v9; // [esp+18h] [ebp-DCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v10; // [esp+1Ch] [ebp-D8h] BYREF
  std::wstring result; // [esp+CCh] [ebp-28h] BYREF
  int v12; // [esp+F0h] [ebp-4h]

  *(_DWORD *)v10.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v10.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  *(_DWORD *)v10.gap68 = std::wios::`vftable';
  v12 = 0;
  v9 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v10, &v10.gap10[8], 0);
  v12 = 1;
  *(_DWORD *)&v10.gap0[*(_DWORD *)(*(_DWORD *)v10.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v9 + *(_DWORD *)(*(_DWORD *)v10.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v10.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v10.gap10[8]);
  *(_DWORD *)&v10.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v10.gap10[64] = 0;
  *(_DWORD *)&v10.gap10[68] = 0;
  v12 = 3;
  if ( ident > 0 )
  {
    v3 = ident;
    do
    {
      std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v10.gap10, "\t");
      --v3;
    }
    while ( v3 );
  }
  std::operator<<<wchar_t>((std::wostream *)v10.gap10, &this->name);
  v4 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v10, &result);
  if ( v4->_Myres >= 8 )
    v4 = (std::wstring *)v4->_Bx._Ptr;
  _printf("%S\n", v4->_Bx._Buf);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v5 = this->nodes._Myfirst;
  result._Bx._Buf[0] = 0;
  v6 = this->nodes._Mylast;
  result._Myres = 7;
  result._Mysize = 0;
  v7 = 0;
  v8 = (unsigned int)((char *)v6 - (char *)v5 + 3) >> 2;
  if ( v5 > v6 )
    v8 = 0;
  if ( v8 )
  {
    do
    {
      (*v5)->printTree(*v5, ident + 1);
      ++v7;
      ++v5;
    }
    while ( v7 != v8 );
  }
  v12 = -1;
  *(_DWORD *)&v10.gap0[*(_DWORD *)(*(_DWORD *)v10.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v9 + *(_DWORD *)(*(_DWORD *)v10.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v10.gap0 + 4) - 104;
  *(_DWORD *)&v10.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v10.gap10[68] & 1) != 0 )
    operator delete(**(_DWORD **)&v10.gap10[20]);
  std::wstreambuf::setg(&v10.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v10.gap10[8], 0, 0);
  *(_DWORD *)&v10.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v10.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v10.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v10.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v10.gap68);
}
void Node::removeChild(Node *this, Node *n)
{
  Node **v3; // edx
  Node **i; // eax

  v3 = this->nodes._Mylast;
  for ( i = this->nodes._Myfirst; i != v3; ++i )
  {
    if ( *i == n )
      break;
  }
  _memmove(i, i + 1, ((char *)this->nodes._Mylast - (char *)(i + 1)) & 0xFFFFFFFC);
  --this->nodes._Mylast;
  n->parent = 0;
}
void Node::render(Node *this, RenderContext *rc)
{
  Node **v3; // eax
  Node **v4; // esi
  int v5; // edi
  unsigned int v6; // ebx

  GraphicsManager::setWorldMatrix(rc->graphics, &this->matrixWS);
  v3 = this->nodes._Mylast;
  v4 = this->nodes._Myfirst;
  v5 = 0;
  v6 = (unsigned int)((char *)v3 - (char *)v4 + 3) >> 2;
  if ( v4 > v3 )
    v6 = 0;
  if ( v6 )
  {
    do
    {
      if ( (*v4)->isActive )
        (*v4)->render(*v4, rc);
      ++v5;
      ++v4;
    }
    while ( v5 != v6 );
  }
}
void Node::renderAudio(Node *this)
{
  Node **v1; // esi
  unsigned int v2; // ebx
  int v3; // edi

  v1 = this->nodes._Myfirst;
  v2 = (unsigned int)((char *)this->nodes._Mylast - (char *)v1 + 3) >> 2;
  v3 = 0;
  if ( v1 > this->nodes._Mylast )
    v2 = 0;
  if ( v2 )
  {
    do
    {
      (*v1)->renderAudio(*v1);
      ++v3;
      ++v1;
    }
    while ( v3 != v2 );
  }
}
void Node::visit(Node *this, std::function<bool __cdecl(Node *)> onVisit, std::function<void __cdecl(Node *)> onPostVisit)
{
  std::_Func_base<bool,Node *> *v4; // ecx
  std::_Func_base<void,Node *> *v5; // ecx
  Node::visit::__l6::<lambda_055418ee63006fb40e78a095a2416dbb> _Func; // [esp+8h] [ebp-14h] BYREF
  int v7; // [esp+18h] [ebp-4h]

  v4 = onVisit._Impl;
  v7 = 1;
  _Func.onVisit = (std::function<bool __cdecl(Node *)> *)this;
  if ( !onVisit._Impl )
    std::_Xbad_function_call();
  if ( v4->_Do_call(v4, (Node **)&_Func) )
  {
    _Func.onVisit = &onVisit;
    _Func.onPostVisit = &onPostVisit;
    std::_For_each<Node * *,_lambda_055418ee63006fb40e78a095a2416dbb_>(
      this->nodes._Myfirst,
      this->nodes._Mylast,
      &_Func);
    v5 = onPostVisit._Impl;
    if ( !onPostVisit._Impl )
      goto LABEL_7;
    _Func.onVisit = (std::function<bool __cdecl(Node *)> *)this;
    onPostVisit._Impl->_Do_call(onPostVisit._Impl, (Node **)&_Func);
  }
  v5 = onPostVisit._Impl;
LABEL_7:
  LOBYTE(v7) = 0;
  if ( onVisit._Impl )
  {
    onVisit._Impl->_Delete_this(onVisit._Impl, onVisit._Impl != (std::_Func_base<bool,Node *> *)&onVisit);
    v5 = onPostVisit._Impl;
    onVisit._Impl = 0;
  }
  v7 = -1;
  if ( v5 )
    ((void (__stdcall *)(bool))v5->_Delete_this)(v5 != (std::_Func_base<void,Node *> *)&onPostVisit);
}
vec3f *Node::worldToLocal(Node *this, vec3f *result, const vec3f *pos)
{
  mat44f *v4; // eax
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm5
  float v9; // xmm4_4
  float v10; // xmm6_4
  vec3f *v11; // eax
  float v12; // xmm0_4
  float v13; // [esp+Ch] [ebp-74h]
  __m128 v14; // [esp+20h] [ebp-60h]
  __m128 pDeterminant_4; // [esp+30h] [ebp-50h] BYREF
  mat44f v16; // [esp+40h] [ebp-40h] BYREF

  mat44f::mat44f(&v16);
  v4 = this->getWorldMatrix(this, &v16);
  v5 = *(__m128 *)&v4->M21;
  v6 = *(__m128 *)&v4->M31;
  v7 = *(__m128 *)&v4->M41;
  v8 = DirectX::XMMatrixInverse(&pDeterminant_4, *(__m128 *)&v4->M11, v5, v6, v7);
  result->x = 0.0;
  result->y = 0.0;
  v14 = v7;
  result->z = 0.0;
  v7.m128_i32[0] = LODWORD(pos->y);
  v9 = pos->z;
  v10 = pos->x;
  v11 = result;
  v13 = pos->x;
  pDeterminant_4.m128_i32[2] = v8.m128_i32[2];
  result->x = (float)((float)((float)(v10 * v8.m128_f32[0]) + (float)(v7.m128_f32[0] * v5.m128_f32[0]))
                    + (float)(v9 * v6.m128_f32[0]))
            + v14.m128_f32[0];
  v12 = (float)(v13 * pDeterminant_4.m128_f32[2]) + (float)(v7.m128_f32[0] * _mm_shuffle_ps(v5, v5, 170).m128_f32[0]);
  result->y = (float)((float)((float)(v13 * _mm_shuffle_ps(v8, v8, 85).m128_f32[0])
                            + (float)(v7.m128_f32[0] * _mm_shuffle_ps(v5, v5, 85).m128_f32[0]))
                    + (float)(v9 * v6.m128_f32[1]))
            + _mm_shuffle_ps(v14, v14, 85).m128_f32[0];
  result->z = (float)(v12 + (float)(v9 * v6.m128_f32[2])) + v14.m128_f32[2];
  return v11;
}
vec3f *Node::worldToLocalNormal(Node *this, vec3f *result, const vec3f *pos)
{
  mat44f *v4; // eax
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  __m128 v8; // xmm6
  float v9; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  vec3f *v12; // eax
  __m128 pDeterminant; // [esp+2Ch] [ebp-54h] BYREF
  mat44f v14; // [esp+40h] [ebp-40h] BYREF

  mat44f::mat44f(&v14);
  v4 = this->getWorldMatrix(this, &v14);
  v5 = *(__m128 *)&v4->M21;
  v6 = *(__m128 *)&v4->M31;
  v7 = *(__m128 *)&v4->M41;
  v8 = DirectX::XMMatrixInverse((__m128 *)&pDeterminant.m128_f32[1], *(__m128 *)&v4->M11, v5, v6, v7);
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  v9 = pos->x;
  v10 = pos->z;
  v11 = pos->x;
  *(__m128 *)&v14.M41 = v7;
  v7.m128_i32[0] = LODWORD(pos->y);
  v12 = result;
  result->x = (float)((float)(v11 * v8.m128_f32[0]) + (float)(v7.m128_f32[0] * v5.m128_f32[0]))
            + (float)(v10 * v6.m128_f32[0]);
  result->z = (float)((float)(v9 * v8.m128_f32[2]) + (float)(v7.m128_f32[0] * v5.m128_f32[2]))
            + (float)(v10 * v6.m128_f32[2]);
  result->y = (float)((float)(v9 * _mm_shuffle_ps(v8, v8, 85).m128_f32[0]) + (float)(v7.m128_f32[0] * v5.m128_f32[1]))
            + (float)(v10 * _mm_shuffle_ps(v6, v6, 85).m128_f32[0]);
  return v12;
}
