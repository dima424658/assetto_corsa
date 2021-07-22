#include "curve.h
Curve *Curve::operator=(Curve *this, const Curve *__that)
{
  std::vector<float>::operator=(
    (std::vector<unsigned int> *)&this->references,
    (const std::vector<unsigned int> *)&__that->references);
  std::vector<float>::operator=(
    (std::vector<unsigned int> *)&this->values,
    (const std::vector<unsigned int> *)&__that->values);
  this->fastStep = __that->fastStep;
  this->cubicSplineReady = __that->cubicSplineReady;
  std::vector<CTData>::operator=(&this->cSpline.mElements, &__that->cSpline.mElements);
  if ( &this->filename != &__that->filename )
    std::wstring::assign(&this->filename, &__that->filename, 0, 0xFFFFFFFF);
  return this;
}
void Curve::Curve(Curve *this, const Curve *__that)
{
  this->__vftable = (Curve_vtbl *)&Curve::`vftable';
  std::vector<unsigned int>::vector<unsigned int>(
    (std::vector<unsigned int> *)&this->references,
    (const std::vector<unsigned int> *)&__that->references);
  std::vector<unsigned int>::vector<unsigned int>(
    (std::vector<unsigned int> *)&this->values,
    (const std::vector<unsigned int> *)&__that->values);
  this->fastStep = __that->fastStep;
  this->cubicSplineReady = __that->cubicSplineReady;
  this->cSpline.__vftable = (CubicSpline<float,float>_vtbl *)&CubicSpline<float,float>::`vftable';
  std::vector<CTData>::vector<CTData>(
    (std::vector<CTData> *)&this->cSpline.mElements,
    (const std::vector<CTData> *)&__that->cSpline.mElements);
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  std::wstring::assign(&this->filename, &__that->filename, 0, 0xFFFFFFFF);
}
Curve *Curve::`scalar deleting destructor'(Curve *this, unsigned int a2)
{
  Curve::~Curve(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Curve::Curve(Curve *this)
{
  this->__vftable = (Curve_vtbl *)&Curve::`vftable';
  this->references._Myfirst = 0;
  this->references._Mylast = 0;
  this->references._Myend = 0;
  this->values._Myfirst = 0;
  this->values._Mylast = 0;
  this->values._Myend = 0;
  this->cSpline.__vftable = (CubicSpline<float,float>_vtbl *)&CubicSpline<float,float>::`vftable';
  this->cSpline.mElements._Myfirst = 0;
  this->cSpline.mElements._Mylast = 0;
  this->cSpline.mElements._Myend = 0;
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  this->cubicSplineReady = 0;
  this->fastStep = 0.0;
}
void Curve::~Curve(Curve *this)
{
  this->__vftable = (Curve_vtbl *)&Curve::`vftable';
  if ( this->filename._Myres >= 8 )
    operator delete(this->filename._Bx._Ptr);
  this->filename._Myres = 7;
  this->filename._Mysize = 0;
  this->filename._Bx._Buf[0] = 0;
  this->cSpline.__vftable = (CubicSpline<float,float>_vtbl *)&CubicSpline<float,float>::`vftable';
  if ( this->cSpline.mElements._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->cSpline.mElements);
    operator delete(this->cSpline.mElements._Myfirst);
    this->cSpline.mElements._Myfirst = 0;
    this->cSpline.mElements._Mylast = 0;
    this->cSpline.mElements._Myend = 0;
  }
  if ( this->values._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->values);
    operator delete(this->values._Myfirst);
    this->values._Myfirst = 0;
    this->values._Mylast = 0;
    this->values._Myend = 0;
  }
  if ( this->references._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->references);
    operator delete(this->references._Myfirst);
    this->references._Myfirst = 0;
    this->references._Mylast = 0;
    this->references._Myend = 0;
  }
}
void Curve::addValue(Curve *this, float ref, float val)
{
  this->cubicSplineReady = 0;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->references, (int *)&ref);
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->values, (int *)&val);
}
int Curve::getCount(Curve *this)
{
  return this->values._Mylast - this->values._Myfirst;
}
double Curve::getCubicSplineValue(Curve *this, float ref)
{
  const CubicSpline<float,float>::Element *v4; // eax
  float v5; // xmm3_4
  CubicSpline<float,float>::Element *v6; // [esp-10h] [ebp-2Ch]
  CubicSpline<float,float>::Element _Val; // [esp+8h] [ebp-14h] BYREF

  if ( !this->cubicSplineReady )
  {
    CubicSpline<float,float>::computeCoefficients(&this->cSpline, &this->references, &this->values);
    this->cubicSplineReady = 1;
  }
  if ( this->cSpline.mElements._Myfirst == this->cSpline.mElements._Mylast )
    return 0.0;
  _Val.x = ref;
  v6 = this->cSpline.mElements._Mylast;
  *(_OWORD *)&_Val.a = 0i64;
  v4 = std::_Lower_bound<CubicSpline<float,float>::Element const *,CubicSpline<float,float>::Element,int,std::less<void>>(
         this->cSpline.mElements._Myfirst,
         v6,
         &_Val);
  if ( v4 != this->cSpline.mElements._Myfirst )
    --v4;
  v5 = ref - v4->x;
  return (float)((float)((float)((float)(v4->b * v5) + v4->a) + (float)(v4->c * (float)(v5 * v5)))
               + (float)((float)((float)(v5 * v5) * v5) * v4->d));
}
double Curve::getMaxReference(Curve *this)
{
  return *(this->references._Mylast - 1);
}
std::pair<float,float> *Curve::getPairAtIndex(Curve *this, std::pair<float,float> *result, int index)
{
  std::pair<float,float> *v3; // eax

  if ( index < 0
    || index >= (unsigned int)(this->values._Mylast - this->values._Myfirst)
    || index >= (unsigned int)(this->references._Mylast - this->references._Myfirst) )
  {
    v3 = result;
    result->first = 0.0;
    result->second = 0.0;
  }
  else
  {
    v3 = result;
    result->first = this->references._Myfirst[index];
    result->second = this->values._Myfirst[index];
  }
  return v3;
}
double Curve::getValue(Curve *this, float ref)
{
  float *v2; // eax
  std::wstring *v3; // ecx
  double result; // st7
  int v5; // edx
  float *v6; // esi
  float *v7; // eax

  v2 = this->references._Myfirst;
  if ( v2 == this->references._Mylast )
  {
    v3 = &this->filename;
    if ( v3->_Myres >= 8 )
      v3 = (std::wstring *)v3->_Bx._Ptr;
    _printf("EMPTY CURVE, RETURNING ZERO (%S)\n", v3->_Bx._Buf);
    result = 0.0;
  }
  else
  {
    v5 = 1;
    if ( *v2 < ref )
    {
      v6 = this->references._Mylast;
      v7 = v2 + 1;
      if ( v7 == v6 )
      {
LABEL_10:
        result = *(this->values._Mylast - 1);
      }
      else
      {
        while ( *v7 < ref )
        {
          ++v7;
          ++v5;
          if ( v7 == v6 )
            goto LABEL_10;
        }
        result = (float)((float)((float)((float)(ref - *(v7 - 1))
                                       * (float)(this->values._Myfirst[v5] - this->values._Myfirst[v5 - 1]))
                               / (float)(*v7 - *(v7 - 1)))
                       + this->values._Myfirst[v5 - 1]);
      }
    }
    else
    {
      result = *this->values._Myfirst;
    }
  }
  return result;
}
void Curve::load(Curve *this, const std::wstring *ifilename)
{
  std::wstring *v3; // ebx
  const wchar_t *v4; // eax
  void (*v5)(const char *const, ...); // ebp
  std::vector<unsigned int> *v6; // esi
  std::vector<unsigned int> *v7; // edi
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  const std::wstring *v10; // eax
  _DWORD *v11; // ecx
  int v12; // eax
  char *v13; // ecx
  wchar_t v14; // ax
  std::wstring *v15; // ebx
  float v16; // xmm0_4
  float v17; // xmm1_4
  unsigned int *v18; // eax
  int v19; // ebx
  unsigned int *v20; // ecx
  unsigned int *v21; // eax
  unsigned int *v22; // eax
  int v23; // ebx
  unsigned int *v24; // ecx
  float *v25; // eax
  std::vector<std::wstring> parts; // [esp+14h] [ebp-154h] BYREF
  Curve *v27; // [esp+20h] [ebp-148h]
  float v28; // [esp+24h] [ebp-144h] BYREF
  float v29; // [esp+2Ch] [ebp-13Ch] BYREF
  float v30; // [esp+30h] [ebp-138h]
  float v31; // [esp+34h] [ebp-134h]
  wchar_t *v32; // [esp+38h] [ebp-130h] BYREF
  wchar_t *EndPtr; // [esp+3Ch] [ebp-12Ch] BYREF
  std::wifstream file; // [esp+40h] [ebp-128h] BYREF
  std::wstring line; // [esp+F8h] [ebp-70h] BYREF
  std::wstring splitter; // [esp+110h] [ebp-58h] BYREF
  std::wstring result; // [esp+128h] [ebp-40h] BYREF
  std::wstring crfn; // [esp+140h] [ebp-28h] BYREF
  int v39; // [esp+164h] [ebp-4h]

  v27 = this;
  v3 = &this->filename;
  if ( &this->filename != ifilename )
    std::wstring::assign(&this->filename, ifilename, 0, 0xFFFFFFFF);
  if ( v3->_Myres < 8 )
    v4 = (const wchar_t *)v3;
  else
    v4 = v3->_Bx._Ptr;
  v5 = (void (*)(const char *const, ...))_printf;
  _printf("Loading lut %S\n", v4);
  v6 = (std::vector<unsigned int> *)&this->references;
  std::_Container_base0::_Orphan_all(&this->references);
  v7 = (std::vector<unsigned int> *)&this->values;
  v6->_Mylast = v6->_Myfirst;
  std::_Container_base0::_Orphan_all(v7);
  v7->_Mylast = v7->_Myfirst;
  v8 = Path::getPath(&line, v3);
  v39 = 0;
  std::operator+<wchar_t>(&crfn, v8, L".acd");
  LOBYTE(v39) = 2;
  if ( line._Myres >= 8 )
    operator delete(line._Bx._Ptr);
  line._Myres = 7;
  line._Bx._Buf[0] = 0;
  line._Mysize = 0;
  if ( Path::fileExists((unsigned int)v3, &crfn, 0) )
  {
    v9 = Path::getFileName(&result, v3);
    LOBYTE(v39) = 3;
    Curve::loadEncrypted(v27, v9, &crfn);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    goto LABEL_63;
  }
  std::vector<std::wstring>::push_back(&Curve::openedFiles, v3);
  v10 = Path::getPlatformSpecificPath(&result, v3);
  LOBYTE(v39) = 4;
  std::wifstream::wifstream(&file, v10, 1, 64, 1);
  LOBYTE(v39) = 6;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v11 = (_DWORD *)(*(_DWORD *)file.gap0 + 4);
  result._Bx._Buf[0] = 0;
  result._Myres = 7;
  result._Mysize = 0;
  v12 = *(_DWORD *)((char *)&file._Chcount + *(_DWORD *)(*(_DWORD *)file.gap0 + 4) + 4);
  if ( (v12 & 6) != 0 )
    goto $LN580;
  if ( (v12 & 1) != 0 )
  {
LABEL_53:
    if ( !std::wfilebuf::close((std::wfilebuf *)file.gap10) )
      std::wios::setstate((char *)&file + *(_DWORD *)(*(_DWORD *)file.gap0 + 4), 2, 0);
    goto LABEL_60;
  }
  v5 = (void (*)(const char *const, ...))__errno;
  while ( 1 )
  {
    line._Myres = 7;
    line._Mysize = 0;
    line._Bx._Buf[0] = 0;
    v13 = &file.gap0[*v11];
    LOBYTE(v39) = 7;
    v14 = std::wios::widen(v13, 10);
    std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&file, &line, v14);
    splitter._Myres = 7;
    splitter._Mysize = 0;
    splitter._Bx._Buf[0] = 0;
    std::wstring::assign(&splitter, L"|", 1u);
    LOBYTE(v39) = 8;
    ksSplitString(&parts, &line, &splitter);
    LOBYTE(v39) = 10;
    if ( splitter._Myres >= 8 )
      operator delete(splitter._Bx._Ptr);
    v15 = parts._Myfirst;
    splitter._Bx._Buf[0] = 0;
    splitter._Myres = 7;
    splitter._Mysize = 0;
    if ( parts._Mylast - parts._Myfirst != 2 )
      goto LABEL_48;
    v3 = parts._Myfirst + 1;
    if ( parts._Myfirst[1]._Myres >= 8 )
      v3 = (std::wstring *)v3->_Bx._Ptr;
    *__errno() = 0;
    v31 = _wcstod(v3->_Bx._Buf, &EndPtr);
    if ( v3 == (std::wstring *)EndPtr )
      goto $LN579;
    if ( *__errno() == 34 )
      break;
    v3 = parts._Myfirst;
    if ( parts._Myfirst->_Myres >= 8 )
      v3 = (std::wstring *)parts._Myfirst->_Bx._Ptr;
    *__errno() = 0;
    v30 = _wcstod(v3->_Bx._Buf, &v32);
    if ( v3 == (std::wstring *)v32 )
      goto $LN579;
    if ( *__errno() == 34 )
      break;
    v16 = v30;
    v17 = v31;
    v28 = v30;
    v27->cubicSplineReady = 0;
    v18 = v6->_Mylast;
    v29 = v17;
    if ( &v28 >= (float *)v18 || v6->_Myfirst > (unsigned int *)&v28 )
    {
      if ( v18 == v6->_Myend )
      {
        std::vector<unsigned int>::_Reserve(v6, 1u);
        v16 = v30;
      }
      v21 = v6->_Mylast;
      if ( v21 )
        *(float *)v21 = v16;
    }
    else
    {
      v19 = ((char *)&v28 - (char *)v6->_Myfirst) >> 2;
      if ( v18 == v6->_Myend )
        std::vector<unsigned int>::_Reserve(v6, 1u);
      v20 = v6->_Mylast;
      if ( v20 )
        *v20 = v6->_Myfirst[v19];
    }
    ++v6->_Mylast;
    v22 = v7->_Mylast;
    if ( &v29 >= (float *)v22 || v7->_Myfirst > (unsigned int *)&v29 )
    {
      if ( v22 == v7->_Myend )
        std::vector<unsigned int>::_Reserve(v7, 1u);
      v25 = (float *)v7->_Mylast;
      if ( v25 )
        *v25 = v31;
    }
    else
    {
      v23 = ((char *)&v29 - (char *)v7->_Myfirst) >> 2;
      if ( v22 == v7->_Myend )
        std::vector<unsigned int>::_Reserve(v7, 1u);
      v24 = v7->_Mylast;
      if ( v24 )
        *v24 = v7->_Myfirst[v23];
    }
    v15 = parts._Myfirst;
    ++v7->_Mylast;
LABEL_48:
    LOBYTE(v39) = 7;
    if ( v15 )
    {
      std::_Container_base0::_Orphan_all(&parts);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(parts._Myfirst, parts._Mylast);
      operator delete(parts._Myfirst);
      parts._Myfirst = 0;
      parts._Mylast = 0;
      parts._Myend = 0;
    }
    LOBYTE(v39) = 6;
    if ( line._Myres >= 8 )
      operator delete(line._Bx._Ptr);
    v11 = (_DWORD *)(*(_DWORD *)file.gap0 + 4);
    if ( (*((_BYTE *)&file._Chcount + *(_DWORD *)(*(_DWORD *)file.gap0 + 4) + 4) & 1) != 0 )
      goto LABEL_53;
  }
  std::_Xout_of_range("stof argument out of range");
$LN579:
  std::_Xinvalid_argument("invalid stof argument");
$LN580:
  if ( v3->_Myres >= 8 )
    v3 = (std::wstring *)v3->_Bx._Ptr;
  v5("ERROR: Lut file not found %S\n", v3->_Bx._Buf);
LABEL_60:
  if ( (unsigned int)(v6->_Mylast - v6->_Myfirst) > 1 )
    v27->fastStep = *((float *)v6->_Myfirst + 1) - *(float *)v6->_Myfirst;
  std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&file.gap64[12]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&file.gap64[12]);
LABEL_63:
  if ( crfn._Myres >= 8 )
    operator delete(crfn._Bx._Ptr);
}
void Curve::loadEncrypted(Curve *this, const std::wstring *ifilename, const std::wstring *dataFile)
{
  Curve *v3; // ebp
  std::wstring *v4; // esi
  const std::vector<char> *v5; // eax
  int v6; // edi
  int v7; // esi
  bool v8; // cf
  const wchar_t *v9; // eax
  wchar_t *v10; // edx
  unsigned int v11; // ecx
  const wchar_t *v12; // ebx
  wchar_t *v13; // edx
  unsigned int v14; // ecx
  const wchar_t *v15; // ebx
  TyreTester_vtbl *v16; // xmm0_4
  std::vector<unsigned int> *v17; // ebx
  int v18; // xmm1_4
  float *v19; // eax
  int v20; // ebp
  unsigned int *v21; // ecx
  _DWORD *v22; // eax
  float *v23; // eax
  std::vector<unsigned int> *v24; // ebx
  int v25; // ebp
  unsigned int *v26; // ecx
  float *v27; // eax
  _DWORD *v28; // edi
  _DWORD *v29; // esi
  TyreTester v30; // [esp+17h] [ebp-891h] BYREF
  int v31; // [esp+8A4h] [ebp-4h]

  v3 = this;
  *(_DWORD *)((char *)&v30.rodLength + 1) = this;
  v4 = &this->filename;
  if ( &this->filename != ifilename )
    std::wstring::assign(&this->filename, ifilename, 0, 0xFFFFFFFF);
  FolderEncrypter::FolderEncrypter((std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > *)&v30);
  v31 = 0;
  v5 = FolderEncrypter::decryptFile(
         (FolderEncrypter *)&v30,
         (std::vector<char> *)((char *)&v30.toeOUT_Linear + 1),
         dataFile,
         v4);
  LOBYTE(v31) = 1;
  ksDecodeUtf8((std::wstring *)((char *)&v30.surf.wavString[18] + 1), v5);
  LOBYTE(v31) = 3;
  if ( *(_DWORD *)((char *)&v30.toeOUT_Linear + 1) )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v30.toeOUT_Linear + 1);
    operator delete(*(_DWORD *)((char *)&v30.toeOUT_Linear + 1));
    *(_QWORD *)((char *)&v30.toeOUT_Linear + 1) = 0i64;
    *(float *)((char *)&v30.baseCFM + 1) = 0.0;
  }
  *(_QWORD *)((char *)&v30.surf.wavString[14] + 1) = 0x700000000i64;
  *(wchar_t *)((char *)&v30.surf.wavString[6] + 1) = 0;
  std::wstring::assign((std::wstring *)((char *)&v30.surf.wavString[6] + 1), L"\n", 1u);
  LOBYTE(v31) = 4;
  ksSplitString(
    (std::vector<std::wstring> *)((char *)&v30.progressiveK + 1),
    (const std::wstring *)((char *)&v30.surf.wavString[18] + 1),
    (const std::wstring *)((char *)&v30.surf.wavString[6] + 1));
  LOBYTE(v31) = 6;
  if ( *(_DWORD *)((char *)&v30.surf.wavString[16] + 1) >= 8u )
    operator delete(*(_DWORD *)((char *)&v30.surf.wavString[6] + 1));
  v6 = *(_DWORD *)((char *)&v30.bumpStopRate + 1);
  v7 = *(_DWORD *)((char *)&v30.progressiveK + 1);
  *(_QWORD *)((char *)&v30.surf.wavString[14] + 1) = 0x700000000i64;
  *(wchar_t *)((char *)&v30.surf.wavString[6] + 1) = 0;
  if ( *(_DWORD *)((char *)&v30.progressiveK + 1) != *(_DWORD *)((char *)&v30.bumpStopRate + 1) )
  {
    do
    {
      v8 = *(_DWORD *)(v7 + 20) < 8u;
      *(float *)((char *)&v30.bumpStopDn + 1) = 0.0;
      if ( v8 )
        v9 = (const wchar_t *)v7;
      else
        v9 = *(const wchar_t **)v7;
      _wcscpy_s((wchar_t *)((char *)&v30.surf.wavString[30] + 1), 0x400u, v9);
      if ( _wcsstr((const wchar_t *)((char *)&v30.surf.wavString[30] + 1), L"|") )
      {
        v10 = _wcstok_s(
                (wchar_t *)((char *)&v30.surf.wavString[30] + 1),
                L"|",
                (wchar_t **)((char *)&v30.bumpStopDn + 1));
        *(_QWORD *)((char *)&v30.surf.wavString[2] + 1) = 0x700000000i64;
        *(_WORD *)((char *)&v30.slipAngle + 1) = 0;
        if ( *v10 )
          v11 = wcslen(v10);
        else
          v11 = 0;
        std::wstring::assign((std::wstring *)((char *)&v30.slipAngle + 1), v10, v11);
        v12 = (const wchar_t *)((char *)&v30.slipAngle + 1);
        LOBYTE(v31) = 7;
        if ( *(_DWORD *)((char *)&v30.surf.wavString[4] + 1) >= 8u )
          v12 = *(const wchar_t **)((char *)&v30.slipAngle + 1);
        *__errno() = 0;
        *(float *)((char *)&v30.staticCamber + 1) = _wcstod(
                                                      v12,
                                                      (wchar_t **)((char *)&v30.IRayTrackCollisionProvider::__vftable + 1));
        if ( v12 == *(const wchar_t **)((char *)&v30.IRayTrackCollisionProvider::__vftable + 1) )
          goto $LN620;
        if ( *__errno() == 34 )
          goto LABEL_67;
        LOBYTE(v31) = 6;
        if ( *(_DWORD *)((char *)&v30.surf.wavString[4] + 1) >= 8u )
          operator delete(*(_DWORD *)((char *)&v30.slipAngle + 1));
        v13 = _wcstok_s(0, L"\n", (wchar_t **)((char *)&v30.bumpStopDn + 1));
        *(_QWORD *)((char *)&v30.surf.wavString[2] + 1) = 0x700000000i64;
        *(_WORD *)((char *)&v30.slipAngle + 1) = 0;
        if ( *v13 )
          v14 = wcslen(v13);
        else
          v14 = 0;
        std::wstring::assign((std::wstring *)((char *)&v30.slipAngle + 1), v13, v14);
        v15 = (const wchar_t *)((char *)&v30.slipAngle + 1);
        LOBYTE(v31) = 8;
        if ( *(_DWORD *)((char *)&v30.surf.wavString[4] + 1) >= 8u )
          v15 = *(const wchar_t **)((char *)&v30.slipAngle + 1);
        *__errno() = 0;
        *(float *)((char *)&v30.bumpStopUp + 1) = _wcstod(v15, (wchar_t **)((char *)&v30.tyre + 1));
        if ( v15 == *(const wchar_t **)((char *)&v30.tyre + 1) )
          goto $LN620;
        if ( *__errno() == 34 )
        {
LABEL_67:
          std::_Xout_of_range("stof argument out of range");
$LN620:
          std::_Xinvalid_argument("invalid stof argument");
          JUMPOUT(0x6ED323);
        }
        LOBYTE(v31) = 6;
        if ( *(_DWORD *)((char *)&v30.surf.wavString[4] + 1) >= 8u )
          operator delete(*(_DWORD *)((char *)&v30.slipAngle + 1));
        v16 = *(TyreTester_vtbl **)((char *)&v30.staticCamber + 1);
        v17 = (std::vector<unsigned int> *)&v3->references;
        v18 = *(_DWORD *)((char *)&v30.bumpStopUp + 1);
        v3->cubicSplineReady = 0;
        v19 = v3->references._Mylast;
        *(TyreTester_vtbl **)((char *)&v30.ISuspension::__vftable + 1) = v16;
        *(_DWORD *)((char *)&v30.k + 1) = v18;
        if ( (char *)&v30.ISuspension::__vftable + 1 >= (char *)v19
          || v17->_Myfirst > (unsigned int *)((char *)&v30.ISuspension::__vftable + 1) )
        {
          if ( v19 == v3->references._Myend )
          {
            std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&v3->references, 1u);
            v16 = *(TyreTester_vtbl **)((char *)&v30.staticCamber + 1);
          }
          v22 = v3->references._Mylast;
          if ( v22 )
            *v22 = v16;
        }
        else
        {
          v20 = ((char *)&v30.ISuspension::__vftable + 1 - (char *)v17->_Myfirst) >> 2;
          if ( v19 == (float *)v17->_Myend )
            std::vector<unsigned int>::_Reserve(v17, 1u);
          v21 = v17->_Mylast;
          if ( v21 )
            *v21 = v17->_Myfirst[v20];
          v3 = *(Curve **)((char *)&v30.rodLength + 1);
        }
        ++v17->_Mylast;
        v23 = v3->values._Mylast;
        v24 = (std::vector<unsigned int> *)&v3->values;
        if ( (char *)&v30.k + 1 >= (char *)v23 || v24->_Myfirst > (unsigned int *)((char *)&v30.k + 1) )
        {
          if ( v23 == v3->values._Myend )
            std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&v3->values, 1u);
          v27 = v3->values._Mylast;
          if ( v27 )
            *v27 = *(float *)((char *)&v30.bumpStopUp + 1);
        }
        else
        {
          v25 = ((char *)&v30.k + 1 - (char *)v24->_Myfirst) >> 2;
          if ( v23 == (float *)v24->_Myend )
            std::vector<unsigned int>::_Reserve(v24, 1u);
          v26 = v24->_Mylast;
          if ( v26 )
            *v26 = v24->_Myfirst[v25];
          v3 = *(Curve **)((char *)&v30.rodLength + 1);
        }
        ++v24->_Mylast;
      }
      v7 += 24;
    }
    while ( v7 != v6 );
    v7 = *(_DWORD *)((char *)&v30.progressiveK + 1);
  }
  if ( (unsigned int)(v3->references._Mylast - v3->references._Myfirst) > 1 )
    v3->fastStep = v3->references._Myfirst[1] - *v3->references._Myfirst;
  LOBYTE(v31) = 3;
  if ( v7 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v30.progressiveK + 1);
    v28 = *(_DWORD **)((char *)&v30.bumpStopRate + 1);
    v29 = *(_DWORD **)((char *)&v30.progressiveK + 1);
    if ( *(_DWORD *)((char *)&v30.progressiveK + 1) != *(_DWORD *)((char *)&v30.bumpStopRate + 1) )
    {
      do
      {
        if ( v29[5] >= 8u )
          operator delete(*v29);
        v29[5] = 7;
        v29[4] = 0;
        *(_WORD *)v29 = 0;
        v29 += 6;
      }
      while ( v29 != v28 );
      v29 = *(_DWORD **)((char *)&v30.progressiveK + 1);
    }
    operator delete(v29);
    *(_QWORD *)((char *)&v30.progressiveK + 1) = 0i64;
    *(float *)((char *)&v30.bumpStopProgressive + 1) = 0.0;
  }
  if ( *(_DWORD *)((char *)&v30.surf.wavString[28] + 1) >= 8u )
    operator delete(*(_DWORD *)((char *)&v30.surf.wavString[18] + 1));
  *(_QWORD *)((char *)&v30.surf.wavString[26] + 1) = 0x700000000i64;
  *(wchar_t *)((char *)&v30.surf.wavString[18] + 1) = 0;
  v31 = -1;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart(&v30);
}
void Curve::print(Curve *this)
{
  unsigned int i; // edi

  for ( i = 0; i < this->values._Mylast - this->values._Myfirst; ++i )
    _printf("%f : %f\n", this->references._Myfirst[i], this->values._Myfirst[i]);
}
void Curve::scale(Curve *this, float v)
{
  float *v2; // edx
  float *i; // eax

  v2 = this->values._Mylast;
  for ( i = this->values._Myfirst; i != v2; ++i )
    *i = *i * v;
}
