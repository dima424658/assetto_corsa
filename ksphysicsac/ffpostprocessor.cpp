#include "ffpostprocessor.h"
void __usercall FFPostProcessor::FFPostProcessor(FFPostProcessor *this@<ecx>, unsigned int a2@<ebx>)
{
  int v3; // eax
  bool v4; // cf
  std::wstring *v5; // eax
  double v6; // st7
  double v7; // xmm0_8
  const Curve *v8; // eax
  _BYTE v9[28]; // [esp-14h] [ebp-14Ch] BYREF
  FFPostProcessor *v10; // [esp+18h] [ebp-120h]
  std::wstring itype; // [esp+20h] [ebp-118h] BYREF
  std::wstring section; // [esp+38h] [ebp-100h] BYREF
  std::wstring key; // [esp+50h] [ebp-E8h] BYREF
  std::wstring v14; // [esp+68h] [ebp-D0h] BYREF
  std::wstring v15; // [esp+80h] [ebp-B8h] BYREF
  INIReaderDocuments ini; // [esp+98h] [ebp-A0h] BYREF
  Curve result; // [esp+DCh] [ebp-5Ch] BYREF
  int v18; // [esp+134h] [ebp-4h]

  v10 = this;
  this->enabled = 0;
  this->gamma = 1.0;
  Curve::Curve(&this->lut);
  v18 = 0;
  *(_QWORD *)&v9[20] = 7i64;
  *(_DWORD *)&v9[16] = 0;
  *(_WORD *)v9 = 0;
  std::wstring::assign((std::wstring *)v9, L"cfg/ff_post_process.ini", 0x17u);
  INIReaderDocuments::INIReaderDocuments(&ini, a2, *(std::wstring *)v9, v9[24]);
  LOBYTE(v18) = 1;
  INIReader::setVerboseMode(&ini, 1);
  _printf("ff_post_process.ini\n");
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ENABLED", 7u);
    LOBYTE(v18) = 2;
    itype._Myres = 7;
    itype._Mysize = 0;
    itype._Bx._Buf[0] = 0;
    std::wstring::assign(&itype, L"HEADER", 6u);
    LOBYTE(v18) = 3;
    v3 = INIReader::getInt(&ini, &itype, &key);
    v4 = itype._Myres < 8;
    this->enabled = v3 != 0;
    if ( !v4 )
      operator delete(itype._Bx._Ptr);
    itype._Myres = 7;
    itype._Mysize = 0;
    itype._Bx._Buf[0] = 0;
    LOBYTE(v18) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( this->enabled )
    {
      _printf("Loading FF Post Processing parameters\n");
      std::wstring::wstring(&v15, L"TYPE");
      LOBYTE(v18) = 4;
      std::wstring::wstring(&key, L"HEADER");
      LOBYTE(v18) = 5;
      INIReader::getString(&ini, &itype, &key, &v15);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v18) = 8;
      if ( v15._Myres >= 8 )
        operator delete(v15._Bx._Ptr);
      v15._Myres = 7;
      v15._Bx._Buf[0] = 0;
      v5 = &itype;
      if ( itype._Myres >= 8 )
        v5 = (std::wstring *)itype._Bx._Ptr;
      v15._Mysize = 0;
      _printf("Type: %S\n", v5->_Bx._Buf);
      if ( !std::wstring::compare(&itype, 0, itype._Mysize, L"GAMMA", 5u) )
      {
        std::wstring::wstring(&v14, L"VALUE");
        LOBYTE(v18) = 9;
        std::wstring::wstring(&section, L"GAMMA");
        LOBYTE(v18) = 10;
        v6 = INIReader::getFloat(&ini, &section, &v14);
        v4 = section._Myres < 8;
        this->gamma = v6;
        if ( !v4 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        LOBYTE(v18) = 8;
        if ( v14._Myres >= 8 )
          operator delete(v14._Bx._Ptr);
        v7 = this->gamma;
        this->type = Gamma;
        _printf("Gamma value: %f\n", v7);
      }
      if ( !std::wstring::compare(&itype, 0, itype._Mysize, L"LUT", 3u) )
      {
        std::wstring::wstring(&v14, L"CURVE");
        LOBYTE(v18) = 11;
        std::wstring::wstring(&section, L"LUT");
        LOBYTE(v18) = 12;
        v8 = INIReader::getCurve(&ini, &result, &section, &v14);
        LOBYTE(v18) = 13;
        Curve::operator=(&this->lut, v8);
        LOBYTE(v18) = 12;
        Curve::~Curve(&result);
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        LOBYTE(v18) = 8;
        if ( v14._Myres >= 8 )
          operator delete(v14._Bx._Ptr);
        _printf("USING FF LUT\n");
        Curve::print(&this->lut);
        this->type = Lut;
      }
      if ( itype._Myres >= 8 )
        operator delete(itype._Bx._Ptr);
    }
  }
  LOBYTE(v18) = 0;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
void FFPostProcessor::~FFPostProcessor(FFPostProcessor *this)
{
  Curve::~Curve(&this->lut);
}
double FFPostProcessor::getProcessedFF(FFPostProcessor *this, float v)
{
  FFPostProcessType v2; // eax
  float v3; // xmm0_4
  float ref; // xmm1_4
  float v7; // [esp+4h] [ebp-4h]
  float va; // [esp+Ch] [ebp+4h]
  float vb; // [esp+Ch] [ebp+4h]

  if ( !this->enabled )
    return v;
  v2 = this->type;
  if ( v2 )
  {
    if ( v2 == Lut )
    {
      v3 = v;
      LODWORD(ref) = LODWORD(v) & _xmm;
      if ( v <= 0.0 )
      {
        va = -1.0;
        if ( v3 >= 0.0 )
          va = 0.0;
      }
      else
      {
        va = 1.0;
      }
      return Curve::getValue(&this->lut, ref) * va;
    }
    return v;
  }
  LODWORD(v7) = __libm_sse2_powf(this).m128_u32[0];
  if ( v > 0.0 )
    return 1.0 * v7;
  vb = -1.0;
  if ( v >= 0.0 )
    vb = 0.0;
  return vb * v7;
}
