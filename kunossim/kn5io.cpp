#include "kn5io.h
void KN5IO::KN5IO(KN5IO *this, GraphicsManager *graphics)
{
  this->__vftable = (KN5IO_vtbl *)&KN5IO::`vftable';
  MaterialList::MaterialList(&this->materialList);
  this->skinOverridePath._Myfirst = 0;
  this->skinOverridePath._Mylast = 0;
  this->skinOverridePath._Myend = 0;
  this->graphics = graphics;
  this->loadSuccess = 1;
  this->loadingFilename._Myres = 7;
  this->loadingFilename._Mysize = 0;
  this->loadingFilename._Bx._Buf[0] = 0;
  this->bonesToSolve._Myfirst = 0;
  this->bonesToSolve._Mylast = 0;
  this->bonesToSolve._Myend = 0;
  this->loadingVersion = 0;
  this->root = 0;
  this->isBinary = 1;
  this->currentVersion = 6;
  this->savingVersion = 6;
}
void KN5IO::~KN5IO(KN5IO *this)
{
  this->__vftable = (KN5IO_vtbl *)&KN5IO::`vftable';
  if ( this->bonesToSolve._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->bonesToSolve);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<BoneSolvePair>>>(
      this->bonesToSolve._Myfirst,
      this->bonesToSolve._Mylast);
    operator delete(this->bonesToSolve._Myfirst);
    this->bonesToSolve._Myfirst = 0;
    this->bonesToSolve._Mylast = 0;
    this->bonesToSolve._Myend = 0;
  }
  if ( this->loadingFilename._Myres >= 8 )
    operator delete(this->loadingFilename._Bx._Ptr);
  this->loadingFilename._Myres = 7;
  this->loadingFilename._Mysize = 0;
  this->loadingFilename._Bx._Buf[0] = 0;
  if ( this->skinOverridePath._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->skinOverridePath);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(
      this->skinOverridePath._Myfirst,
      this->skinOverridePath._Mylast);
    operator delete(this->skinOverridePath._Myfirst);
    this->skinOverridePath._Myfirst = 0;
    this->skinOverridePath._Mylast = 0;
    this->skinOverridePath._Myend = 0;
  }
  MaterialList::~MaterialList(&this->materialList);
}
KN5IO *KN5IO::`scalar deleting destructor'(KN5IO *this, unsigned int a2)
{
  KN5IO::~KN5IO(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __cdecl KN5IO::addDLCKey(unsigned int key)
{
  unsigned int *v1; // ecx
  unsigned int *v2; // eax
  int v3; // esi

  v1 = KN5IO::dlc_keys._Mylast;
  if ( &key >= KN5IO::dlc_keys._Mylast || (v2 = KN5IO::dlc_keys._Myfirst, KN5IO::dlc_keys._Myfirst > &key) )
  {
    if ( KN5IO::dlc_keys._Mylast == KN5IO::dlc_keys._Myend )
    {
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&KN5IO::dlc_keys, 1u);
      v1 = KN5IO::dlc_keys._Mylast;
    }
    if ( v1 )
    {
      *v1 = key;
      v1 = KN5IO::dlc_keys._Mylast;
    }
    KN5IO::dlc_keys._Mylast = v1 + 1;
  }
  else
  {
    v3 = &key - KN5IO::dlc_keys._Myfirst;
    if ( KN5IO::dlc_keys._Mylast == KN5IO::dlc_keys._Myend )
    {
      std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&KN5IO::dlc_keys, 1u);
      v1 = KN5IO::dlc_keys._Mylast;
      v2 = KN5IO::dlc_keys._Myfirst;
    }
    if ( v1 )
    {
      *v1 = v2[v3];
      v1 = KN5IO::dlc_keys._Mylast;
    }
    KN5IO::dlc_keys._Mylast = v1 + 1;
  }
}
void KN5IO::addTextureFolder(KN5IO *this, const std::wstring *folder)
{
  std::vector<std::wstring>::push_back(&this->skinOverridePath, folder);
}
std::wstring *KN5IO::getSkinOverridenTexturePath(KN5IO *this, std::wstring *result, std::wstring tname)
{
  std::wstring *v3; // esi
  std::wstring *v4; // edi
  std::wstring *v5; // eax
  std::wstring *v7; // eax
  unsigned int v8; // ecx
  bool v9; // cf
  std::wstring tp; // [esp+14h] [ebp-58h] BYREF
  std::wstring s; // [esp+2Ch] [ebp-40h] BYREF
  std::wstring v12; // [esp+44h] [ebp-28h] BYREF
  int v13; // [esp+68h] [ebp-4h]

  v3 = this->skinOverridePath._Myfirst;
  v4 = this->skinOverridePath._Mylast;
  v13 = 0;
  if ( v3 == v4 )
  {
LABEL_10:
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, word_17BE9D8, 0);
  }
  else
  {
    while ( 1 )
    {
      s._Myres = 7;
      s._Mysize = 0;
      s._Bx._Buf[0] = 0;
      std::wstring::assign(&s, v3, 0, 0xFFFFFFFF);
      LOBYTE(v13) = 1;
      v5 = std::operator+<wchar_t>(&v12, &s, L"/");
      LOBYTE(v13) = 2;
      std::operator+<wchar_t>(&tp, v5, &tname);
      LOBYTE(v13) = 4;
      if ( v12._Myres >= 8 )
        operator delete(v12._Bx._Ptr);
      v12._Myres = 7;
      v12._Bx._Buf[0] = 0;
      v12._Mysize = 0;
      if ( Path::fileExists((unsigned int)result, &tp, 0) )
        break;
      if ( tp._Myres >= 8 )
        operator delete(tp._Bx._Ptr);
      LOBYTE(v13) = 0;
      if ( s._Myres >= 8 )
        operator delete(s._Bx._Ptr);
      if ( ++v3 == v4 )
        goto LABEL_10;
    }
    v7 = &tp;
    if ( tp._Myres >= 8 )
      v7 = (std::wstring *)tp._Bx._Ptr;
    _printf("SKINNED TEXTURE %S FOUND, OVERRIDING\n", v7->_Bx._Buf);
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    v8 = tp._Myres;
    if ( tp._Myres >= 8 )
    {
      result->_Bx._Ptr = tp._Bx._Ptr;
      tp._Bx._Ptr = 0;
    }
    else if ( tp._Mysize != -1 )
    {
      _memmove(result, &tp, 2 * (tp._Mysize + 1));
      v8 = tp._Myres;
    }
    result->_Mysize = tp._Mysize;
    v9 = s._Myres < 8;
    result->_Myres = v8;
    tp._Myres = 7;
    tp._Mysize = 0;
    tp._Bx._Buf[0] = 0;
    if ( !v9 )
      operator delete(s._Bx._Ptr);
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
  }
  if ( tname._Myres >= 8 )
    operator delete(tname._Bx._Ptr);
  return result;
}
Node *KN5IO::load(KN5IO *this, const std::wstring *filename)
{
  char v3; // bl
  int v4; // eax
  int v5; // esi
  std::wstring *v6; // eax
  Node **v7; // ebp
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  Node *v10; // eax
  const std::wstring *v11; // eax
  unsigned int *v12; // eax
  Node *v13; // eax
  int v14; // eax
  Node *v15; // esi
  Node *v16; // edi
  std::wstring v17; // [esp-8h] [ebp-148h] BYREF
  Node *tr; // [esp+24h] [ebp-11Ch] BYREF
  unsigned int dlc_key; // [esp+28h] [ebp-118h] BYREF
  int version; // [esp+2Ch] [ebp-114h] BYREF
  int v21; // [esp+30h] [ebp-110h]
  KN5IO::load::__l27::<lambda_ddee55b666c9fe7033ec247e5d5719bd> _Func; // [esp+34h] [ebp-10Ch] BYREF
  std::ifstream in; // [esp+3Ch] [ebp-104h] BYREF
  std::wstring result; // [esp+F4h] [ebp-4Ch] BYREF
  MaterialList v25; // [esp+10Ch] [ebp-34h] BYREF
  char magic[7]; // [esp+128h] [ebp-18h] BYREF
  int v27; // [esp+13Ch] [ebp-4h]

  v3 = 0;
  dlc_key = (unsigned int)filename;
  v21 = 0;
  this->loadSuccess = 1;
  MaterialList::MaterialList(&v25);
  v5 = v4;
  v27 = 0;
  std::vector<std::shared_ptr<Material>>::operator=(
    &this->materialList.materials,
    (const std::vector<std::shared_ptr<Material>> *)(v4 + 4));
  std::vector<Texture>::operator=(&this->materialList.textures, (const std::vector<Texture> *)(v5 + 16));
  v27 = -1;
  MaterialList::~MaterialList(&v25);
  if ( &this->loadingFilename != filename )
    std::wstring::assign(&this->loadingFilename, filename, 0, 0xFFFFFFFF);
  if ( this->loadingFilename._Myres < 8 )
    v6 = &this->loadingFilename;
  else
    v6 = (std::wstring *)this->loadingFilename._Bx._Ptr;
  _printf("LOADING MODEL %S\n", v6->_Bx._Buf);
  v7 = (Node **)operator new(188);
  _Func.tr = v7;
  v27 = 1;
  if ( v7 )
  {
    v8 = Path::getFileName((std::wstring *)&v25, (const std::wstring *)dlc_key);
    LOBYTE(v27) = 2;
    v9 = std::operator+<wchar_t>(&result, L"KN5: ", v8);
    v3 = 3;
    v27 = 3;
    v21 = 3;
    Node::Node((Node *)v7, v9);
  }
  else
  {
    v10 = 0;
  }
  tr = v10;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v27 = -1;
  if ( (v3 & 1) != 0 && v25.textures._Mylast >= (Texture *)8 )
    operator delete(v25.__vftable);
  v17._Myres = dlc_key;
  this->root = tr;
  v11 = Path::getPlatformSpecificPath(&result, (const std::wstring *)v17._Myres);
  v27 = 6;
  std::ifstream::ifstream(&in, v11, 33, 64, 1);
  LOBYTE(v27) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  std::istream::read(&in, magic);
  magic[6] = 0;
  version = 1;
  std::istream::read(&in, &version);
  v17._Myres = version;
  v17._Mysize = (unsigned int)"VERSION=%d\n";
  this->loadingVersion = version;
  _printf((const char *const)v17._Mysize, v17._Myres);
  if ( version > this->currentVersion )
    _printf("ERROR: KN5IO trying to load version v%d on KN5 v%d system\n", this->loadingVersion, this->currentVersion);
  if ( this->loadingVersion >= 6 )
  {
    v17._Myres = 0;
    v17._Mysize = 4;
    std::istream::read(&in, &dlc_key);
    if ( dlc_key )
    {
      v12 = KN5IO::dlc_keys._Myfirst;
      if ( KN5IO::dlc_keys._Myfirst == KN5IO::dlc_keys._Mylast )
      {
LABEL_25:
        std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&in.gap64[12]);
        std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
        return 0;
      }
      while ( *v12 != dlc_key )
      {
        if ( ++v12 == KN5IO::dlc_keys._Mylast )
          goto LABEL_25;
      }
    }
  }
  v17._Myres = 7;
  v17._Mysize = 0;
  v17._Bx._Buf[0] = 0;
  std::wstring::assign(&v17, &this->loadingFilename, 0, 0xFFFFFFFF);
  KN5IO::loadMaterialsBinary(this, (unsigned int)_printf, &in, v17);
  v14 = this->loadingVersion;
  v17._Myres = (unsigned int)tr;
  v17._Mysize = (unsigned int)&in;
  if ( v14 == 1 )
    KN5IO::loadBinaryV1(this, (std::ifstream *)v17._Mysize, (Node *)v17._Myres);
  else
    KN5IO::loadBinaryV2(this, (std::ifstream *)v17._Mysize, (Node *)v17._Myres);
  if ( !std::filebuf::close((std::filebuf *)in.gap10) )
    std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
  _Func.__this = this;
  _Func.tr = &tr;
  std::_For_each<BoneSolvePair *,_lambda_ddee55b666c9fe7033ec247e5d5719bd_>(
    this->bonesToSolve._Myfirst,
    this->bonesToSolve._Mylast,
    &_Func);
  v15 = tr;
  if ( (((char *)tr->nodes._Mylast - (char *)tr->nodes._Myfirst) & 0xFFFFFFFC) != 0 )
  {
    v16 = *tr->nodes._Myfirst;
    tr->removeChild(tr, v16);
    if ( tr )
      ((void (*)(Node *, int))tr->~Node)(tr, 1);
    std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&in.gap64[12]);
    std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
    v13 = v16;
  }
  else
  {
    std::ifstream::~ifstream<char,std::char_traits<char>>((std::ifstream *)&in.gap64[12]);
    std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
    v13 = v15;
  }
  return v13;
}
void KN5IO::loadBinaryV1(KN5IO *this, std::ifstream *in, Node *n)
{
  KN5IO *v3; // ebx
  std::ifstream *v4; // ebp
  int v5; // esi
  int v6; // esi
  Mesh *v7; // esi
  int v8; // eax
  unsigned int v9; // edi
  unsigned int *v10; // esi
  unsigned int v11; // ecx
  int v12; // ebx
  unsigned int v13; // ebp
  std::vector<unsigned short> *v14; // edi
  Node *v15; // eax
  unsigned int v16; // eax
  Node *v17; // eax
  unsigned int v18; // eax
  int i; // esi
  int v20; // eax
  std::wstring v21; // [esp+48h] [ebp-90h] BYREF
  bool active; // [esp+77h] [ebp-61h] BYREF
  unsigned __int16 _Val[2]; // [esp+78h] [ebp-60h] BYREF
  int nodes; // [esp+7Ch] [ebp-5Ch] BYREF
  int vc; // [esp+80h] [ebp-58h] BYREF
  int ic; // [esp+84h] [ebp-54h] BYREF
  std::ifstream *v27; // [esp+88h] [ebp-50h]
  std::vector<unsigned int> tempv; // [esp+8Ch] [ebp-4Ch] BYREF
  int matid; // [esp+98h] [ebp-40h] BYREF
  int icid; // [esp+9Ch] [ebp-3Ch] BYREF
  int v31; // [esp+A4h] [ebp-34h]
  Node *v32; // [esp+A8h] [ebp-30h]
  KN5IO *v33; // [esp+ACh] [ebp-2Ch]
  std::wstring name; // [esp+B0h] [ebp-28h] BYREF
  int v35; // [esp+D4h] [ebp-4h]

  v3 = this;
  v33 = this;
  v4 = in;
  v32 = n;
  v27 = in;
  icid = 0;
  std::istream::read(in, &icid);
  v5 = icid;
  KN5IO::loadString(v3, &name, in);
  v35 = 0;
  nodes = 0;
  std::istream::read(in, &nodes);
  v21._Myres = 0;
  v21._Mysize = 1;
  active = 0;
  std::istream::read(in, &active);
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 != 1 )
        goto LABEL_36;
      v7 = (Mesh *)operator new(276);
      *(_DWORD *)_Val = v7;
      LOBYTE(v35) = 3;
      if ( v7 )
      {
        v21._Myres = 7;
        v21._Mysize = 0;
        v21._Bx._Buf[0] = 0;
        std::wstring::assign(&v21, &name, 0, 0xFFFFFFFF);
        Mesh::Mesh(v7, v21);
        v9 = v8;
        v31 = v8;
      }
      else
      {
        v9 = 0;
        v31 = 0;
      }
      v21._Myres = 0;
      *(_BYTE *)(v9 + 184) = active;
      v21._Mysize = 1;
      LOBYTE(v35) = 0;
      std::istream::read(in, v9 + 188);
      v21._Myres = 0;
      v21._Mysize = 1;
      std::istream::read(in, v9 + 189);
      v21._Myres = 0;
      v21._Mysize = 1;
      std::istream::read(in, v9 + 190);
      v21._Myres = 0;
      v21._Mysize = 4;
      vc = 0;
      std::istream::read(in, &vc);
      if ( vc )
      {
        std::vector<MeshVertex>::resize((std::vector<MeshVertex> *)(v9 + 224), vc);
        v21._Myres = 0;
        v21._Mysize = 44 * vc;
        std::istream::read(in, *(_DWORD *)(v9 + 224));
      }
      v21._Myres = 0;
      v21._Mysize = 4;
      ic = 0;
      std::istream::read(in, &ic);
      if ( ic )
      {
        tempv._Myfirst = 0;
        tempv._Mylast = 0;
        tempv._Myend = 0;
        LOBYTE(v35) = 4;
        std::vector<RenderTarget *>::resize((std::vector<RenderTarget *> *)&tempv, ic);
        v21._Myres = 0;
        v21._Mysize = 4 * ic;
        std::istream::read(in, tempv._Myfirst);
        v10 = tempv._Myfirst;
        v11 = (unsigned int)((char *)tempv._Mylast - (char *)tempv._Myfirst + 3) >> 2;
        if ( tempv._Myfirst > tempv._Mylast )
          v11 = 0;
        if ( v11 )
        {
          v12 = 0;
          *(_DWORD *)_Val = v9 + 236;
          v13 = v11;
          v14 = (std::vector<unsigned short> *)(v9 + 236);
          do
          {
            *(_DWORD *)_Val = (unsigned __int16)*v10;
            std::vector<unsigned short>::push_back(v14, _Val);
            ++v12;
            ++v10;
          }
          while ( v12 != v13 );
          v10 = tempv._Myfirst;
          v9 = v31;
          v3 = v33;
          v4 = v27;
        }
        LOBYTE(v35) = 0;
        if ( v10 )
        {
          std::_Container_base0::_Orphan_all(&tempv);
          operator delete(tempv._Myfirst);
        }
      }
      v21._Myres = 0;
      v21._Mysize = 4;
      matid = 0;
      std::istream::read(v4, &matid);
      if ( matid < 0 || matid >= v3->materialList.materials._Mylast - v3->materialList.materials._Myfirst )
        v3->loadSuccess = 0;
      else
        std::shared_ptr<Material>::operator=(
          (std::shared_ptr<Material> *)(v9 + 248),
          &v3->materialList.materials._Myfirst[matid]);
    }
    else
    {
      v15 = (Node *)operator new(188);
      v27 = (std::ifstream *)v15;
      LOBYTE(v35) = 2;
      if ( v15 )
      {
        Node::Node(v15, &name);
        v9 = v16;
      }
      else
      {
        v9 = 0;
      }
      v21._Myres = 0;
      v21._Mysize = 64;
      *(_DWORD *)&v21._Bx._Alias[12] = v9 + 4;
      LOBYTE(v35) = 0;
      *(_BYTE *)(v9 + 184) = active;
      std::istream::read(in, *(_DWORD *)&v21._Bx._Alias[12]);
      mat44f::print((mat44f *)(v9 + 4));
    }
  }
  else
  {
    v17 = (Node *)operator new(188);
    v27 = (std::ifstream *)v17;
    LOBYTE(v35) = 1;
    if ( v17 )
    {
      Node::Node(v17, &name);
      v9 = v18;
    }
    else
    {
      v9 = 0;
    }
    LOBYTE(v35) = 0;
    *(_BYTE *)(v9 + 184) = active;
  }
  if ( v9 )
  {
    v32->addChild(v32, (Node *)v9);
    for ( i = 0; i < nodes; ++i )
    {
      v20 = v3->loadingVersion;
      v21._Myres = v9;
      v21._Mysize = (unsigned int)v4;
      if ( v20 == 1 )
        KN5IO::loadBinaryV1(v3, (std::ifstream *)v21._Mysize, (Node *)v21._Myres);
      else
        KN5IO::loadBinaryV2(v3, (std::ifstream *)v21._Mysize, (Node *)v21._Myres);
    }
  }
LABEL_36:
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void KN5IO::loadBinaryV2(KN5IO *this, std::ifstream *in, Node *n)
{
  float v4; // edi
  int v5; // esi
  Node *v6; // eax
  float v7; // eax
  Node *v8; // eax
  float v9; // eax
  int v10; // eax
  SkinnedMesh *v11; // esi
  float v12; // eax
  int i; // esi
  Node *v14; // ecx
  __m128i v15; // xmm0
  Mesh *v16; // esi
  float v17; // eax
  int j; // esi
  int v19; // eax
  mat44f v20; // [esp+68h] [ebp-15Ch] BYREF
  bool active; // [esp+BFh] [ebp-105h] BYREF
  Node *node; // [esp+C0h] [ebp-104h] BYREF
  int ic; // [esp+C4h] [ebp-100h] BYREF
  unsigned int v24; // [esp+C8h] [ebp-FCh] BYREF
  unsigned int _Newsize; // [esp+CCh] [ebp-F8h] BYREF
  int nodes; // [esp+D0h] [ebp-F4h] BYREF
  int vc; // [esp+D4h] [ebp-F0h] BYREF
  int bc; // [esp+D8h] [ebp-ECh] BYREF
  int matid; // [esp+DCh] [ebp-E8h] BYREF
  int icid; // [esp+E0h] [ebp-E4h] BYREF
  Node *v31; // [esp+E4h] [ebp-E0h]
  mat44f mat; // [esp+E8h] [ebp-DCh] BYREF
  BoneSolvePair bsp; // [esp+128h] [ebp-9Ch] BYREF
  std::wstring name; // [esp+184h] [ebp-40h] BYREF
  std::wstring bonename; // [esp+19Ch] [ebp-28h] BYREF
  int v36; // [esp+1C0h] [ebp-4h]

  v4 = 0.0;
  v31 = n;
  icid = 0;
  std::istream::read(in, &icid);
  v5 = icid;
  KN5IO::loadString(this, &name, in);
  v36 = 0;
  nodes = 0;
  std::istream::read(in, &nodes);
  v20.M44 = 0.0;
  LODWORD(v20.M43) = 1;
  active = 0;
  std::istream::read(in, &active);
  switch ( v5 )
  {
    case 0:
      v6 = (Node *)operator new(188);
      node = v6;
      LOBYTE(v36) = 1;
      if ( v6 )
      {
        Node::Node(v6, &name);
        v4 = v7;
        LOBYTE(v36) = 0;
        *(_BYTE *)(LODWORD(v7) + 184) = active;
      }
      else
      {
        v4 = 0.0;
        LOBYTE(v36) = 0;
        MEMORY[0xB8] = active;
      }
      goto LABEL_46;
    case 1:
      v8 = (Node *)operator new(188);
      node = v8;
      LOBYTE(v36) = 2;
      if ( v8 )
      {
        Node::Node(v8, &name);
        v4 = v9;
      }
      else
      {
        v4 = 0.0;
      }
      v20.M44 = 0.0;
      *(_BYTE *)(LODWORD(v4) + 184) = active;
      v10 = LODWORD(v4) + 4;
      LOBYTE(v36) = 0;
      LODWORD(v20.M43) = 64;
      break;
    case 2:
      v16 = (Mesh *)operator new(276);
      matid = (int)v16;
      LOBYTE(v36) = 6;
      if ( v16 )
      {
        std::wstring::wstring((std::wstring *)&v20.M33, &name);
        Mesh::Mesh(v16, *(std::wstring *)&v20.M33);
        v4 = v17;
      }
      else
      {
        v4 = 0.0;
      }
      v20.M44 = 0.0;
      *(_BYTE *)(LODWORD(v4) + 184) = active;
      LODWORD(v20.M43) = 1;
      LOBYTE(v36) = 0;
      std::istream::read(in, LODWORD(v4) + 188);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 1;
      std::istream::read(in, LODWORD(v4) + 189);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 1;
      std::istream::read(in, LODWORD(v4) + 190);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      _Newsize = 0;
      std::istream::read(in, &_Newsize);
      if ( _Newsize )
      {
        std::vector<MeshVertex>::resize((std::vector<MeshVertex> *)(LODWORD(v4) + 224), _Newsize);
        v20.M44 = 0.0;
        LODWORD(v20.M43) = 44 * _Newsize;
        std::istream::read(in, *(_DWORD *)(LODWORD(v4) + 224));
      }
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      v24 = 0;
      std::istream::read(in, &v24);
      if ( v24 )
      {
        std::vector<unsigned short>::resize((std::vector<unsigned short> *)(LODWORD(v4) + 236), v24);
        v20.M44 = 0.0;
        LODWORD(v20.M43) = 2 * v24;
        std::istream::read(in, *(_DWORD *)(LODWORD(v4) + 236));
      }
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      node = 0;
      std::istream::read(in, &node);
      if ( (int)node < 0 || (int)node >= this->materialList.materials._Mylast - this->materialList.materials._Myfirst )
      {
        _printf("ERROR: matid=%d\n", node);
        this->loadSuccess = 0;
      }
      else
      {
        std::shared_ptr<Material>::operator=(
          (std::shared_ptr<Material> *)(LODWORD(v4) + 248),
          &this->materialList.materials._Myfirst[(_DWORD)node]);
      }
      if ( this->loadingVersion >= 3 )
      {
        v20.M44 = 0.0;
        LODWORD(v20.M43) = 4;
        std::istream::read(in, LODWORD(v4) + 208);
        v20.M44 = 0.0;
        LODWORD(v20.M43) = 4;
        std::istream::read(in, LODWORD(v4) + 212);
        v20.M44 = 0.0;
        LODWORD(v20.M43) = 4;
        std::istream::read(in, LODWORD(v4) + 216);
      }
      if ( this->loadingVersion < 4 )
        goto LABEL_46;
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 12;
      std::istream::read(in, LODWORD(v4) + 192);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      std::istream::read(in, LODWORD(v4) + 204);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 1;
      v10 = LODWORD(v4) + 256;
      break;
    case 3:
      v11 = (SkinnedMesh *)operator new(292);
      node = v11;
      LOBYTE(v36) = 3;
      if ( v11 )
      {
        std::wstring::wstring((std::wstring *)&v20.M33, &name);
        SkinnedMesh::SkinnedMesh(v11, *(std::wstring *)&v20.M33);
        v4 = v12;
      }
      else
      {
        v4 = 0.0;
      }
      v20.M44 = 0.0;
      *(_BYTE *)(LODWORD(v4) + 184) = active;
      LODWORD(v20.M43) = 1;
      LOBYTE(v36) = 0;
      std::istream::read(in, LODWORD(v4) + 188);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 1;
      std::istream::read(in, LODWORD(v4) + 189);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 1;
      std::istream::read(in, LODWORD(v4) + 190);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      bc = 0;
      std::istream::read(in, &bc);
      for ( i = 0; i < bc; ++i )
      {
        KN5IO::loadString(this, &bonename, in);
        v14 = this->root;
        LOBYTE(v36) = 4;
        node = v14->findChildByName(v14, &bonename, 1);
        mat44f::mat44f(&mat);
        v20.M44 = 0.0;
        LODWORD(v20.M43) = 64;
        std::istream::read(in, &mat);
        if ( node )
        {
          *(__m128i *)&v20.M11 = _mm_loadu_si128((const __m128i *)&mat);
          *(__m128i *)&v20.M21 = _mm_loadu_si128((const __m128i *)&mat.M21);
          *(__m128i *)&v20.M31 = _mm_loadu_si128((const __m128i *)&mat.M31);
          *(__m128i *)&v20.M41 = _mm_loadu_si128((const __m128i *)&mat.M41);
          SkinnedMesh::addBone((SkinnedMesh *)LODWORD(v4), node, v20);
        }
        else
        {
          bsp.boneName._Myres = 7;
          bsp.boneName._Mysize = 0;
          bsp.boneName._Bx._Buf[0] = 0;
          mat44f::mat44f(&bsp.matrix);
          LOBYTE(v36) = 5;
          std::wstring::assign(&bsp.boneName, &bonename, 0, 0xFFFFFFFF);
          v15 = _mm_loadu_si128((const __m128i *)&mat);
          *(float *)&bsp.skinnedMesh = v4;
          LODWORD(v20.M44) = &bsp;
          *(__m128i *)&bsp.matrix.M11 = v15;
          *(__m128i *)&bsp.matrix.M21 = _mm_loadu_si128((const __m128i *)&mat.M21);
          *(__m128i *)&bsp.matrix.M31 = _mm_loadu_si128((const __m128i *)&mat.M31);
          *(__m128i *)&bsp.matrix.M41 = _mm_loadu_si128((const __m128i *)&mat.M41);
          std::vector<BoneSolvePair>::push_back(&this->bonesToSolve, &bsp);
          if ( bsp.boneName._Myres >= 8 )
            operator delete(bsp.boneName._Bx._Ptr);
        }
        LOBYTE(v36) = 0;
        if ( bonename._Myres >= 8 )
          operator delete(bonename._Bx._Ptr);
      }
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      vc = 0;
      std::istream::read(in, &vc);
      if ( vc )
      {
        std::vector<SkinnedMeshVertex>::resize((std::vector<SkinnedMeshVertex> *)(LODWORD(v4) + 224), vc);
        v20.M44 = 0.0;
        LODWORD(v20.M43) = 76 * vc;
        std::istream::read(in, *(_DWORD *)(LODWORD(v4) + 224));
      }
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      ic = 0;
      std::istream::read(in, &ic);
      if ( ic )
      {
        std::vector<unsigned short>::resize((std::vector<unsigned short> *)(LODWORD(v4) + 236), ic);
        v20.M44 = 0.0;
        LODWORD(v20.M43) = 2 * ic;
        std::istream::read(in, *(_DWORD *)(LODWORD(v4) + 236));
      }
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      matid = 0;
      std::istream::read(in, &matid);
      if ( matid < 0 || matid >= this->materialList.materials._Mylast - this->materialList.materials._Myfirst )
        _printf("ERROR: matid=%d\n", matid);
      else
        std::shared_ptr<Material>::operator=(
          (std::shared_ptr<Material> *)(LODWORD(v4) + 248),
          &this->materialList.materials._Myfirst[matid]);
      if ( this->loadingVersion < 3 )
        goto LABEL_46;
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      std::istream::read(in, LODWORD(v4) + 208);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      std::istream::read(in, LODWORD(v4) + 212);
      v20.M44 = 0.0;
      LODWORD(v20.M43) = 4;
      v10 = LODWORD(v4) + 216;
      break;
    default:
      goto LABEL_47;
  }
  std::istream::read(in, v10);
LABEL_46:
  if ( v4 == 0.0 )
LABEL_47:
    _printf("ERROR newNode IS NULL\n");
  ((void (*)(Node *, float))v31->addChild)(v31, COERCE_FLOAT(LODWORD(v4)));
  for ( j = 0; j < nodes; ++j )
  {
    v19 = this->loadingVersion;
    v20.M44 = v4;
    LODWORD(v20.M43) = in;
    if ( v19 == 1 )
      KN5IO::loadBinaryV1(this, (std::ifstream *)LODWORD(v20.M43), (Node *)LODWORD(v20.M44));
    else
      KN5IO::loadBinaryV2(this, (std::ifstream *)LODWORD(v20.M43), (Node *)LODWORD(v20.M44));
  }
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
void __userpurge KN5IO::loadMaterialsBinary(KN5IO *this@<ecx>, unsigned int a2@<ebx>, std::ifstream *in, std::wstring filename)
{
  std::ifstream *v4; // edi
  int i; // esi
  GraphicsManager **v6; // ecx
  Material *v7; // eax
  Material *v8; // edi
  Material *v9; // esi
  KN5IO *v10; // esi
  Material *v11; // eax
  const std::wstring *v12; // eax
  MaterialVar *v13; // esi
  ShaderVariable *v14; // ecx
  float *v15; // edi
  unsigned int v16; // eax
  unsigned int v17; // edx
  ShaderVariable *v18; // ecx
  eVariableType v19; // eax
  unsigned int v20; // eax
  ShaderVariable *v21; // ecx
  unsigned int v22; // eax
  __m128i v23; // xmm0
  ShaderVariable *v24; // ecx
  unsigned int v25; // eax
  ShaderVariable *v26; // ecx
  const std::wstring *v27; // eax
  int v28; // esi
  std::wstring *v29; // eax
  unsigned int v30; // edx
  std::wstring *v31; // ecx
  int v32; // edi
  unsigned int v33; // esi
  const wchar_t *v34; // edx
  unsigned int v35; // eax
  bool v36; // zf
  int v37; // eax
  bool v38; // cf
  int v39; // ecx
  std::wstring *v40; // esi
  std::wstring *v41; // esi
  Texture *v42; // eax
  MaterialResource *v43; // esi
  void *v44; // ecx
  const std::wstring *v45; // eax
  std::wstring *v46; // ecx
  Texture *v47; // eax
  std::wstring *v48; // ecx
  int v49; // eax
  void *v50; // ecx
  const std::wstring *v51; // eax
  std::wstring *v52; // ecx
  Material *v53; // edx
  unsigned int *v54; // esi
  unsigned int v55; // edi
  std::wstring *v56; // ecx
  std::wstring *v57; // eax
  std::wostream *v58; // eax
  std::wostream *v59; // eax
  std::wostream *v60; // eax
  std::wostream *v61; // eax
  std::wostream *v62; // eax
  std::wostream *v63; // eax
  std::wostream *v64; // eax
  std::wstring *v65; // eax
  HWND v66; // eax
  std::_Ref_count_base *v67; // esi
  std::wstring v68; // [esp+74h] [ebp-238h] BYREF
  int v69; // [esp+98h] [ebp-214h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v70; // [esp+9Ch] [ebp-210h] BYREF
  __m128i v71; // [esp+14Ch] [ebp-160h] BYREF
  __int64 v72; // [esp+15Ch] [ebp-150h] BYREF
  float v73; // [esp+164h] [ebp-148h]
  unsigned int v74; // [esp+168h] [ebp-144h]
  int v75; // [esp+16Ch] [ebp-140h] BYREF
  int v76; // [esp+170h] [ebp-13Ch] BYREF
  std::vector<std::shared_ptr<Material>> *v77; // [esp+174h] [ebp-138h]
  float v78; // [esp+178h] [ebp-134h] BYREF
  float v79; // [esp+17Ch] [ebp-130h]
  int v80; // [esp+180h] [ebp-12Ch]
  int v81; // [esp+184h] [ebp-128h]
  float v82; // [esp+188h] [ebp-124h] BYREF
  int v83; // [esp+18Ch] [ebp-120h] BYREF
  MaterialResource *v84; // [esp+190h] [ebp-11Ch] BYREF
  GraphicsManager **v85; // [esp+194h] [ebp-118h]
  int v86; // [esp+198h] [ebp-114h] BYREF
  int v87; // [esp+19Ch] [ebp-110h] BYREF
  unsigned int v88; // [esp+1A0h] [ebp-10Ch]
  Material *v89; // [esp+1A4h] [ebp-108h]
  MaterialResource *j; // [esp+1A8h] [ebp-104h]
  int v91; // [esp+1ACh] [ebp-100h] BYREF
  std::shared_ptr<Material> result; // [esp+1B0h] [ebp-FCh] BYREF
  std::ifstream *v93; // [esp+1B8h] [ebp-F4h]
  KN5IO *v94; // [esp+1BCh] [ebp-F0h]
  std::wstring v95; // [esp+1C0h] [ebp-ECh] BYREF
  std::wstring name; // [esp+1D8h] [ebp-D4h] BYREF
  std::wstring _Left; // [esp+1F0h] [ebp-BCh] BYREF
  std::wstring v98; // [esp+208h] [ebp-A4h] BYREF
  Texture v99; // [esp+220h] [ebp-8Ch] BYREF
  std::wstring _Right; // [esp+23Ch] [ebp-70h] BYREF
  std::wstring s; // [esp+254h] [ebp-58h] BYREF
  std::wstring v102; // [esp+26Ch] [ebp-40h] BYREF
  std::wstring tname; // [esp+284h] [ebp-28h] BYREF
  int v104; // [esp+2A8h] [ebp-4h]

  v94 = this;
  v4 = in;
  v93 = in;
  v81 = 0;
  v104 = 0;
  v87 = 0;
  std::istream::read(in, &v87);
  _printf("Loading %d textures\n", v87);
  for ( i = 0; i < v87; ++i )
    KN5IO::loadTexture(v94, in);
  v68._Myres = 0;
  v68._Mysize = 4;
  v86 = 0;
  std::istream::read(in, &v86);
  v80 = 0;
  if ( v86 > 0 )
  {
    v6 = &v94->graphics;
    v85 = &v94->graphics;
    v77 = &v94->materialList.materials;
    do
    {
      std::make_shared<Material,wchar_t const (&)[19],GraphicsManager * &>(
        &result,
        (const wchar_t (*)[16])word_17BE9D8,
        v6);
      LOBYTE(v104) = 1;
      v7 = (Material *)KN5IO::loadString(v94, &v98, v4);
      v8 = result._Ptr;
      v9 = v7;
      if ( result._Ptr != v7 )
      {
        if ( result._Ptr->name._Myres >= 8 )
          operator delete(result._Ptr->name._Bx._Ptr);
        v8->name._Myres = 7;
        v8->name._Mysize = 0;
        v8->name._Bx._Buf[0] = 0;
        if ( v9->name._Myres >= 8 )
        {
          v8->name._Bx._Ptr = v9->name._Bx._Ptr;
          v9->name._Bx._Ptr = 0;
        }
        else if ( v9->name._Mysize != -1 )
        {
          _memmove(v8, v9, 2 * (v9->name._Mysize + 1));
        }
        v8->name._Mysize = v9->name._Mysize;
        v8->name._Myres = v9->name._Myres;
        v9->name._Myres = 7;
        v9->name._Mysize = 0;
        v9->name._Bx._Buf[0] = 0;
      }
      if ( v98._Myres >= 8 )
        operator delete(v98._Bx._Ptr);
      v4 = v93;
      v10 = v94;
      KN5IO::loadString(v94, &name, v93);
      LOBYTE(v104) = 2;
      Material::setShader(result._Ptr, a2, &name);
      v68._Myres = 0;
      v68._Mysize = 1;
      std::istream::read(v4, (char *)&v91 + 3);
      v68._Myres = 0;
      v68._Mysize = 1;
      std::istream::read(v4, (char *)&v91 + 2);
      if ( HIBYTE(v91) )
        result._Ptr->blendMode = eAlphaBlend;
      if ( BYTE2(v91) )
        result._Ptr->blendMode = eAlphaToCoverage;
      if ( v10->loadingVersion >= 5 )
      {
        v68._Myres = 0;
        v68._Mysize = 4;
        std::istream::read(v4, &v75);
        if ( v75 )
        {
          if ( v75 == 1 )
          {
            result._Ptr->depthMode = eDepthNoWrite;
            goto LABEL_27;
          }
          v11 = result._Ptr;
          if ( v75 == 2 )
          {
            result._Ptr->depthMode = eDepthOff;
            goto LABEL_27;
          }
        }
        else
        {
          v11 = result._Ptr;
        }
        v11->depthMode = eDepthNormal;
      }
LABEL_27:
      v68._Myres = 0;
      v68._Mysize = 4;
      v84 = 0;
      std::istream::read(v4, &v84);
      for ( j = 0; (int)j < (int)v84; j = (MaterialResource *)((char *)j + 1) )
      {
        v12 = KN5IO::loadString(v10, &tname, v4);
        LOBYTE(v104) = 3;
        v13 = Material::getVar(result._Ptr, v12);
        LOBYTE(v104) = 2;
        if ( tname._Myres >= 8 )
          operator delete(tname._Bx._Ptr);
        tname._Myres = 7;
        v68._Myres = 0;
        tname._Bx._Buf[0] = 0;
        v82 = 0.0;
        v78 = 0.0;
        v79 = 0.0;
        v72 = 0i64;
        v73 = 0.0;
        v68._Mysize = 4;
        tname._Mysize = 0;
        v71 = 0i64;
        std::istream::read(v4, &v82);
        v68._Myres = 0;
        v68._Mysize = 8;
        std::istream::read(v4, &v78);
        v68._Myres = 0;
        v68._Mysize = 12;
        std::istream::read(v4, &v72);
        v68._Myres = 0;
        v68._Mysize = 16;
        std::istream::read(v4, &v71);
        if ( v13 )
        {
          v14 = v13->var;
          v15 = &v13->fValue;
          v13->fValue = v82;
          switch ( v14->type )
          {
            case 0:
              v68._Myres = (unsigned int)&v13->fValue;
              goto LABEL_38;
            case 1:
              v16 = (unsigned int)&v13->fValue2;
              goto LABEL_37;
            case 2:
              v16 = (unsigned int)&v13->fValue3;
              goto LABEL_37;
            case 3:
              v16 = (unsigned int)&v13->fValue4;
              goto LABEL_37;
            case 4:
              v16 = (unsigned int)&v13->mValue;
LABEL_37:
              v68._Myres = v16;
LABEL_38:
              ShaderVariable::set(v14, (float *)v68._Myres);
              break;
            default:
              break;
          }
          v17 = (unsigned int)&v13->fValue2;
          v18 = v13->var;
          v13->fValue2.x = v78;
          v13->fValue2.y = v79;
          v19 = v18->type;
          v88 = (unsigned int)&v13->fValue2;
          switch ( v19 )
          {
            case 0:
              v68._Myres = (unsigned int)&v13->fValue;
              goto LABEL_46;
            case 1:
              v68._Myres = (unsigned int)&v13->fValue2;
              goto LABEL_46;
            case 2:
              v20 = (unsigned int)&v13->fValue3;
              goto LABEL_45;
            case 3:
              v20 = (unsigned int)&v13->fValue4;
              goto LABEL_45;
            case 4:
              v20 = (unsigned int)&v13->mValue;
LABEL_45:
              v68._Myres = v20;
LABEL_46:
              ShaderVariable::set(v18, (float *)v68._Myres);
              v17 = (unsigned int)&v13->fValue2;
              break;
            default:
              break;
          }
          *(_QWORD *)&v13->fValue3.x = v72;
          v13->fValue3.z = v73;
          v74 = (unsigned int)&v13->fValue3;
          v21 = v13->var;
          switch ( v21->type )
          {
            case 0:
              v68._Myres = (unsigned int)&v13->fValue;
              goto LABEL_54;
            case 1:
              v68._Myres = v17;
              goto LABEL_54;
            case 2:
              v22 = (unsigned int)&v13->fValue3;
              goto LABEL_53;
            case 3:
              v22 = (unsigned int)&v13->fValue4;
              goto LABEL_53;
            case 4:
              v22 = (unsigned int)&v13->mValue;
LABEL_53:
              v68._Myres = v22;
LABEL_54:
              ShaderVariable::set(v21, (float *)v68._Myres);
              break;
            default:
              break;
          }
          v23 = _mm_loadu_si128(&v71);
          v24 = v13->var;
          v89 = (Material *)&v13->fValue4;
          v13->fValue4 = (vec4f)v23;
          switch ( v24->type )
          {
            case 0:
              v68._Myres = (unsigned int)&v13->fValue;
              goto LABEL_62;
            case 1:
              v25 = (unsigned int)&v13->fValue2;
              goto LABEL_61;
            case 2:
              v25 = (unsigned int)&v13->fValue3;
              goto LABEL_61;
            case 3:
              v68._Myres = (unsigned int)&v13->fValue4;
              goto LABEL_62;
            case 4:
              v25 = (unsigned int)&v13->mValue;
LABEL_61:
              v68._Myres = v25;
LABEL_62:
              ShaderVariable::set(v24, (float *)v68._Myres);
              break;
            default:
              break;
          }
          if ( !std::wstring::compare(&v13->name, 0, v13->name._Mysize, L"ksSpecularEXP", 0xDu) && *v15 < 1.0 )
          {
            v26 = v13->var;
            *v15 = 1.0;
            switch ( v26->type )
            {
              case 0:
                v68._Myres = (unsigned int)&v13->fValue;
                goto LABEL_71;
              case 1:
                v68._Myres = v88;
                goto LABEL_71;
              case 2:
                v68._Myres = v74;
                goto LABEL_71;
              case 3:
                v68._Myres = (unsigned int)v89;
                goto LABEL_71;
              case 4:
                v68._Myres = (unsigned int)&v13->mValue;
LABEL_71:
                ShaderVariable::set(v26, (float *)v68._Myres);
                break;
              default:
                break;
            }
          }
          v4 = v93;
        }
        v10 = v94;
      }
      v68._Myres = 0;
      v68._Mysize = 4;
      v83 = 0;
      std::istream::read(v4, &v83);
      Path::getPath(&_Left, &v10->loadingFilename);
      LOBYTE(v104) = 4;
      v88 = 0;
      if ( v83 > 0 )
      {
        while ( 1 )
        {
          v27 = KN5IO::loadString(v10, &v95, v4);
          LOBYTE(v104) = 5;
          v28 = Material::getResourceIndex(result._Ptr, v27);
          LOBYTE(v104) = 4;
          if ( v95._Myres >= 8 )
            operator delete(v95._Bx._Ptr);
          v95._Myres = 7;
          v68._Myres = 0;
          v95._Bx._Buf[0] = 0;
          v76 = 0;
          v68._Mysize = 4;
          v95._Mysize = 0;
          std::istream::read(v4, &v76);
          KN5IO::loadString(v94, &_Right, v4);
          LOBYTE(v104) = 6;
          v29 = std::operator+<wchar_t>(&v98, &_Left, L"::");
          LOBYTE(v104) = 7;
          std::operator+<wchar_t>(&tname, v29, &_Right);
          LOBYTE(v104) = 9;
          if ( v98._Myres >= 8 )
            operator delete(v98._Bx._Ptr);
          v98._Myres = 7;
          v98._Mysize = 0;
          v98._Bx._Buf[0] = 0;
          if ( v28 == -1 )
            goto LABEL_155;
          v30 = tname._Mysize;
          v31 = &tname;
          v32 = v28;
          v89 = result._Ptr;
          v33 = 4;
          if ( tname._Myres >= 8 )
            v31 = (std::wstring *)tname._Bx._Ptr;
          if ( tname._Mysize < 4 )
            v33 = tname._Mysize;
          j = result._Ptr->resources._Myfirst;
          if ( v33 )
          {
            v34 = L"NULL";
            while ( v31->_Bx._Buf[0] == *v34 )
            {
              v31 = (std::wstring *)((char *)v31 + 2);
              ++v34;
              if ( !--v33 )
              {
                v30 = tname._Mysize;
                goto LABEL_89;
              }
            }
            v38 = v31->_Bx._Buf[0] < *v34;
            v30 = tname._Mysize;
            v35 = v38 ? -1 : 1;
          }
          else
          {
LABEL_89:
            v35 = 0;
          }
          v36 = v35 == 0;
          if ( !v35 )
          {
            if ( v30 >= 4 )
              v37 = v30 != 4;
            else
              v37 = -1;
            v36 = v37 == 0;
          }
          if ( !v36 )
            break;
          v53 = v89;
LABEL_139:
          if ( !j[v32].texture.kid )
          {
            v54 = (unsigned int *)&j[v32].name._Bx._Ptr;
            if ( v54[5] < 8 )
              v55 = (unsigned int)&j[v32].name;
            else
              v55 = *v54;
            if ( v53->name._Myres >= 8 )
              v53 = (Material *)v53->name._Bx._Ptr;
            v56 = &_Right;
            v68._Myres = v55;
            if ( _Right._Myres >= 8 )
              v56 = (std::wstring *)_Right._Bx._Ptr;
            v57 = &filename;
            v68._Mysize = (unsigned int)v53;
            if ( filename._Myres >= 8 )
              v57 = (std::wstring *)filename._Bx._Ptr;
            _printf(
              "ERROR [%S] couldn't set texture %S for mat: %S res:%S\n",
              v57->_Bx._Buf,
              v56->_Bx._Buf,
              (const wchar_t *)v68._Mysize,
              (const wchar_t *)v68._Myres);
            *(_DWORD *)v70.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
            *(_DWORD *)v70.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
            std::wios::wios(v70.gap68);
            v81 |= 1u;
            LOBYTE(v104) = 15;
            std::wiostream::basic_iostream<wchar_t>(&v70, &v70.gap10[8], 0);
            v104 = 16;
            *(_DWORD *)&v70.gap0[*(_DWORD *)(*(_DWORD *)v70.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(int *)((char *)&v69 + *(_DWORD *)(*(_DWORD *)v70.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v70.gap0 + 4) - 104;
            std::wstreambuf::wstreambuf(&v70.gap10[8]);
            *(_DWORD *)&v70.gap10[8] = &std::wstringbuf::`vftable';
            *(_DWORD *)&v70.gap10[64] = 0;
            *(_DWORD *)&v70.gap10[68] = 0;
            v68._Myres = (unsigned int)v54;
            v68._Mysize = (unsigned int)" for slot :  ";
            *(_DWORD *)&v68._Bx._Alias[12] = result._Ptr;
            LOBYTE(v104) = 18;
            *(_DWORD *)&v68._Bx._Alias[8] = "  for material : ";
            *(_DWORD *)&v68._Bx._Alias[4] = &_Right;
            v68._Bx._Ptr = (wchar_t *)"]  couldn't set texture : ";
            v58 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v70.gap10, "ERROR [");
            v59 = std::operator<<<wchar_t>(v58, &filename);
            v60 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v59, (const char *)v68._Bx._Ptr);
            v61 = std::operator<<<wchar_t>(v60, *(const std::wstring **)&v68._Bx._Alias[4]);
            v62 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v61, *(const char **)&v68._Bx._Alias[8]);
            v63 = std::operator<<<wchar_t>(v62, *(const std::wstring **)&v68._Bx._Alias[12]);
            v64 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v63, (const char *)v68._Mysize);
            std::operator<<<wchar_t>(v64, (const std::wstring *)v68._Myres);
            v65 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                    &v70,
                    &v99.fileName);
            if ( v65->_Myres >= 8 )
              v65 = (std::wstring *)v65->_Bx._Ptr;
            v68._Myres = 0;
            v68._Mysize = (unsigned int)L"OK";
            *(_DWORD *)&v68._Bx._Alias[12] = v65;
            v66 = GetActiveWindow();
            MessageBoxW(v66, *(LPCWSTR *)&v68._Bx._Alias[12], (LPCWSTR)v68._Mysize, v68._Myres);
            if ( v99.fileName._Myres >= 8 )
              operator delete(v99.fileName._Bx._Ptr);
            v10 = v94;
            v94->loadSuccess = 0;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v70);
            v4 = v93;
            goto LABEL_156;
          }
          v4 = v93;
LABEL_155:
          v10 = v94;
LABEL_156:
          if ( tname._Myres >= 8 )
            operator delete(tname._Bx._Ptr);
          tname._Myres = 7;
          tname._Mysize = 0;
          tname._Bx._Buf[0] = 0;
          LOBYTE(v104) = 4;
          if ( _Right._Myres >= 8 )
            operator delete(_Right._Bx._Ptr);
          if ( (int)++v88 >= v83 )
            goto LABEL_161;
        }
        v68._Myres = 7;
        v68._Mysize = 0;
        v68._Bx._Buf[0] = 0;
        std::wstring::assign(&v68, &_Right, 0, 0xFFFFFFFF);
        KN5IO::getSkinOverridenTexturePath(v94, &v102, v68);
        LOBYTE(v104) = 10;
        if ( !v102._Mysize )
        {
          v39 = std::wstring::find_last_of(&_Right, L"::", 0xFFFFFFFF, 2u);
          s._Myres = 7;
          s._Mysize = 0;
          s._Bx._Buf[0] = 0;
          LOBYTE(v104) = 11;
          if ( v39 == -1 )
          {
            std::wstring::assign(&s, &_Right, 0, 0xFFFFFFFF);
          }
          else
          {
            v40 = std::wstring::substr(&_Right, &v99.fileName, v39 + 1, _Right._Mysize - v39 - 1);
            if ( &s != v40 )
            {
              if ( s._Myres >= 8 )
                operator delete(s._Bx._Ptr);
              s._Myres = 7;
              s._Mysize = 0;
              s._Bx._Buf[0] = 0;
              if ( v40->_Myres >= 8 )
              {
                s._Bx._Ptr = v40->_Bx._Ptr;
                v40->_Bx._Ptr = 0;
              }
              else if ( v40->_Mysize != -1 )
              {
                _memmove(&s, v40, 2 * (v40->_Mysize + 1));
              }
              s._Mysize = v40->_Mysize;
              s._Myres = v40->_Myres;
              v40->_Myres = 7;
              v40->_Mysize = 0;
              v40->_Bx._Buf[0] = 0;
            }
            if ( v99.fileName._Myres >= 8 )
              operator delete(v99.fileName._Bx._Ptr);
          }
          Path::getFileName(&v68, &s);
          v41 = KN5IO::getSkinOverridenTexturePath(v94, &v99.fileName, v68);
          if ( &v102 != v41 )
          {
            if ( v102._Myres >= 8 )
              operator delete(v102._Bx._Ptr);
            v102._Myres = 7;
            v102._Mysize = 0;
            v102._Bx._Buf[0] = 0;
            if ( v41->_Myres >= 8 )
            {
              v102._Bx._Ptr = v41->_Bx._Ptr;
              v41->_Bx._Ptr = 0;
            }
            else if ( v41->_Mysize != -1 )
            {
              _memmove(&v102, v41, 2 * (v41->_Mysize + 1));
            }
            v102._Mysize = v41->_Mysize;
            v102._Myres = v41->_Myres;
            v41->_Myres = 7;
            v41->_Mysize = 0;
            v41->_Bx._Buf[0] = 0;
          }
          if ( v99.fileName._Myres >= 8 )
            operator delete(v99.fileName._Bx._Ptr);
          LOBYTE(v104) = 10;
          if ( s._Myres >= 8 )
            operator delete(s._Bx._Ptr);
        }
        if ( v102._Mysize )
        {
          v43 = j;
          v48 = &v102;
          if ( v102._Myres >= 8 )
            v48 = (std::wstring *)v102._Bx._Ptr;
          v49 = (int)&j[v32].name;
          if ( *(_DWORD *)(v49 + 20) >= 8u )
            v49 = *(_DWORD *)v49;
          _printf(
            "Assign texture override for textureless kn5. RES: %S  FILENAME:%S\n",
            (const wchar_t *)v49,
            v48->_Bx._Buf);
          v47 = ResourceStore::getTexture((*v85)->resourceStore._Myptr, &v99, &v102, 0);
          LOBYTE(v104) = 14;
LABEL_132:
          v50 = v47->kid;
          v51 = &v47->fileName;
          v43[v32].texture.kid = v50;
          v52 = &v43[v32].texture.fileName;
          if ( v52 != v51 )
            std::wstring::assign(v52, v51, 0, 0xFFFFFFFF);
          LOBYTE(v104) = 10;
          OnSetupAppCreated::~OnSetupAppCreated(&v99);
        }
        else
        {
          v42 = MaterialList::getTextureFromName(&v94->materialList, &v99, &tname);
          v43 = j;
          v44 = v42->kid;
          v45 = &v42->fileName;
          LOBYTE(v104) = 12;
          j[v32].texture.kid = v44;
          v46 = &v43[v32].texture.fileName;
          if ( v46 != v45 )
            std::wstring::assign(v46, v45, 0, 0xFFFFFFFF);
          LOBYTE(v104) = 10;
          OnSetupAppCreated::~OnSetupAppCreated(&v99);
          if ( !v43[v32].texture.kid )
          {
            v47 = ResourceStore::getTexture((*v85)->resourceStore._Myptr, &v99, &tname, 0);
            LOBYTE(v104) = 13;
            goto LABEL_132;
          }
        }
        LOBYTE(v104) = 9;
        if ( v102._Myres >= 8 )
          operator delete(v102._Bx._Ptr);
        v53 = result._Ptr;
        goto LABEL_139;
      }
LABEL_161:
      std::vector<std::shared_ptr<Material>>::push_back(v77, &result);
      if ( _Left._Myres >= 8 )
        operator delete(_Left._Bx._Ptr);
      _Left._Myres = 7;
      _Left._Mysize = 0;
      _Left._Bx._Buf[0] = 0;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      v67 = result._Rep;
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      LOBYTE(v104) = 0;
      if ( result._Rep )
      {
        if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&result._Rep->_Uses, 0xFFFFFFFF) )
        {
          v67->_Destroy(v67);
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v67->_Weaks, 0xFFFFFFFF) )
            v67->_Delete_this(v67);
        }
      }
      v6 = v85;
      ++v80;
    }
    while ( v80 < v86 );
  }
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
std::wstring *KN5IO::loadString(KN5IO *this, std::wstring *result, std::ifstream *in)
{
  int s[2]; // [esp+10h] [ebp-20h] BYREF
  std::vector<char> binary; // [esp+18h] [ebp-18h] BYREF
  int v6; // [esp+2Ch] [ebp-4h]

  s[1] = 0;
  s[0] = 0;
  std::istream::read(in, s);
  binary._Myfirst = 0;
  binary._Mylast = 0;
  binary._Myend = 0;
  v6 = 0;
  std::vector<char>::resize(&binary, s[0]);
  std::istream::read(in, binary._Myfirst);
  ksDecodeUtf8(result, &binary);
  v6 = -1;
  if ( binary._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&binary);
    operator delete(binary._Myfirst);
  }
  return result;
}
void KN5IO::loadTexture(KN5IO *this, std::ifstream *in)
{
  int v3; // ecx
  std::wstring *v4; // eax
  std::wstring *v5; // esi
  std::wstring *v6; // eax
  GraphicsManager *v7; // eax
  unsigned __int8 *v8; // esi
  Texture *v9; // ecx
  std::wstring v10; // [esp-4h] [ebp-108h] BYREF
  int size[2]; // [esp+24h] [ebp-E0h] BYREF
  std::wstring tp; // [esp+2Ch] [ebp-D8h] BYREF
  std::wstring result; // [esp+44h] [ebp-C0h] BYREF
  std::wstring name; // [esp+5Ch] [ebp-A8h] BYREF
  std::wstring tname; // [esp+74h] [ebp-90h] BYREF
  std::wstring s; // [esp+8Ch] [ebp-78h] BYREF
  Texture tx; // [esp+A4h] [ebp-60h] BYREF
  std::wstring path; // [esp+C0h] [ebp-44h] BYREF
  Texture _Val; // [esp+D8h] [ebp-2Ch] BYREF
  int v20; // [esp+100h] [ebp-4h]

  Path::getPath(&path, &this->loadingFilename);
  v10._Myres = 0;
  v10._Mysize = 4;
  v20 = 0;
  size[0] = 0;
  std::istream::read(in, size);
  if ( size[0] )
  {
    KN5IO::loadString(this, &tname, in);
    v10._Myres = 0;
    v10._Mysize = 4;
    LOBYTE(v20) = 1;
    std::istream::read(in, size);
    Path::getFileName(&v10, &tname);
    KN5IO::getSkinOverridenTexturePath(this, &tp, v10);
    LOBYTE(v20) = 2;
    if ( !tp._Mysize )
    {
      v3 = std::wstring::find_last_of(&tname, L"::", 0xFFFFFFFF, 2u);
      s._Myres = 7;
      s._Mysize = 0;
      s._Bx._Buf[0] = 0;
      LOBYTE(v20) = 3;
      if ( v3 == -1 )
      {
        std::wstring::assign(&s, &tname, 0, 0xFFFFFFFF);
      }
      else
      {
        v4 = std::wstring::substr(&tname, &result, v3 + 1, tname._Mysize - v3 - 1);
        std::wstring::operator=(&s, v4);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
      }
      Path::getFileName(&v10, &s);
      v5 = KN5IO::getSkinOverridenTexturePath(this, &result, v10);
      if ( &tp != v5 )
      {
        if ( tp._Myres >= 8 )
          operator delete(tp._Bx._Ptr);
        tp._Myres = 7;
        tp._Mysize = 0;
        tp._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&tp, v5);
      }
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      LOBYTE(v20) = 2;
      if ( s._Myres >= 8 )
        operator delete(s._Bx._Ptr);
    }
    v6 = std::operator+<wchar_t>(&result, &path, L"::");
    LOBYTE(v20) = 4;
    std::operator+<wchar_t>(&name, v6, &tname);
    LOBYTE(v20) = 6;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( size[0] )
    {
      v7 = this->graphics;
      if ( tp._Mysize )
      {
        ResourceStore::getTexture(v7->resourceStore._Myptr, &_Val, &tp, 0);
        LOBYTE(v20) = 9;
        std::wstring::assign(&_Val.fileName, &name, 0, 0xFFFFFFFF);
        std::vector<Texture>::push_back(&this->materialList.textures, &_Val);
        std::istream::seekg(in, size[0], size[0] >> 31, 1);
        v9 = &_Val;
      }
      else
      {
        if ( ResourceStore::hasTexture(v7->resourceStore._Myptr, &name) )
        {
          ResourceStore::getTextureFromBuffer(this->graphics->resourceStore._Myptr, &tx, &name, 0, 0);
          LOBYTE(v20) = 8;
          std::vector<Texture>::push_back(&this->materialList.textures, &tx);
          std::istream::seekg(in, size[0], size[0] >> 31, 1);
        }
        else
        {
          v8 = (unsigned __int8 *)operator new[](size[0]);
          *(_QWORD *)&v10._Mysize = size[0];
          std::istream::read(in, v8);
          ResourceStore::getTextureFromBuffer(this->graphics->resourceStore._Myptr, &tx, &name, v8, size[0]);
          LOBYTE(v20) = 7;
          std::vector<Texture>::push_back(&this->materialList.textures, &tx);
          operator delete[](v8);
        }
        v9 = &tx;
      }
      LOBYTE(v20) = 6;
      OnSetupAppCreated::~OnSetupAppCreated(v9);
    }
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    if ( tp._Myres >= 8 )
      operator delete(tp._Bx._Ptr);
    tp._Myres = 7;
    tp._Mysize = 0;
    tp._Bx._Buf[0] = 0;
    if ( tname._Myres >= 8 )
      operator delete(tname._Bx._Ptr);
  }
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
}
