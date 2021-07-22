#include "animation.h
void Animation::load(Animation *this, const std::wstring *filename)
{
  const std::wstring *v3; // eax
  const std::wstring *v4; // eax
  const char *v5; // esi
  std::vector<AnimationSet> *v6; // esi
  int v7; // ebp
  int v8; // edi
  int v9; // ebx
  quatpos *v10; // esi
  int v11; // eax
  int v12; // ebx
  AnimationSet *v13; // eax
  _DWORD *v14; // ecx
  _DWORD *v15; // ebp
  _DWORD *v16; // edx
  _DWORD *v17; // esi
  unsigned int v18; // edi
  bool v19; // cf
  _BYTE *v20; // esi
  int v21; // ecx
  int fc; // [esp+48h] [ebp-15Ch] BYREF
  int sl; // [esp+4Ch] [ebp-158h] BYREF
  int version; // [esp+50h] [ebp-154h] BYREF
  std::vector<AnimationSet> *v25; // [esp+54h] [ebp-150h]
  int setc; // [esp+58h] [ebp-14Ch] BYREF
  int i; // [esp+5Ch] [ebp-148h]
  std::vector<mat44f> mv; // [esp+60h] [ebp-144h] BYREF
  std::wstring _Right; // [esp+6Ch] [ebp-138h] BYREF
  std::ifstream in; // [esp+84h] [ebp-120h] BYREF
  quatpos v31; // [esp+13Ch] [ebp-68h] BYREF
  std::string sName; // [esp+164h] [ebp-40h] BYREF
  std::wstring result; // [esp+17Ch] [ebp-28h] BYREF
  int v34; // [esp+1A0h] [ebp-4h]

  v25 = &this->sets;
  if ( filename->_Myres < 8 )
    v3 = filename;
  else
    v3 = (const std::wstring *)filename->_Bx._Ptr;
  _printf("LOADING ANIMATION: %S\n", v3->_Bx._Buf);
  v4 = Path::getPlatformSpecificPath(&result, filename);
  v34 = 0;
  std::ifstream::ifstream(&in, v4, 32, 64, 1);
  LOBYTE(v34) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  version = 1;
  std::istream::read(&in, &version);
  _printf("VERSION: %d\n", version);
  setc = this->sets._Mylast - this->sets._Myfirst;
  std::istream::read(&in, &setc);
  for ( i = 0; i < setc; ++i )
  {
    sl = 0;
    std::istream::read(&in, &sl);
    v5 = (const char *)operator new[](sl + 1);
    std::istream::read(&in, v5);
    v5[sl] = 0;
    sName._Myres = 15;
    sName._Mysize = 0;
    sName._Bx._Buf[0] = 0;
    std::string::assign(&sName, v5, sl);
    LOBYTE(v34) = 3;
    string2wstring(&_Right, &sName);
    LOBYTE(v34) = 4;
    LOWORD(v31.quat.x) = 0;
    LODWORD(v31.pos.y) = 7;
    v31.pos.x = 0.0;
    std::wstring::assign((std::wstring *)&v31, &_Right, 0, 0xFFFFFFFF);
    v31.pos.z = 0.0;
    v31.scale.x = 0.0;
    v31.scale.y = 0.0;
    LOBYTE(v31.scale.z) = 0;
    if ( _Right._Myres >= 8 )
      operator delete(_Right._Bx._Ptr);
    _Right._Myres = 7;
    _Right._Mysize = 0;
    _Right._Bx._Buf[0] = 0;
    v6 = v25;
    LOBYTE(v34) = 5;
    std::vector<AnimationSet>::push_back(v25, (AnimationSet *)&v31);
    LOBYTE(v34) = 3;
    if ( LODWORD(v31.pos.z) )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v31.pos.z);
      operator delete(LODWORD(v31.pos.z));
      v31.pos.z = 0.0;
      v31.scale.x = 0.0;
      v31.scale.y = 0.0;
    }
    if ( LODWORD(v31.pos.y) >= 8 )
      operator delete(LODWORD(v31.quat.x));
    std::istream::read(&in, &fc);
    std::vector<quatpos>::resize(&v6->_Mylast[-1].frames, fc);
    if ( version >= 2 )
    {
      std::istream::read(&in, v6->_Mylast[-1].frames._Myfirst);
    }
    else
    {
      std::vector<mat44f>::vector<mat44f>(&mv, fc);
      LOBYTE(v34) = 6;
      std::istream::read(&in, mv._Myfirst);
      v7 = 0;
      if ( fc > 0 )
      {
        v8 = 0;
        v9 = 0;
        do
        {
          v10 = &v6->_Mylast[-1].frames._Myfirst[v8];
          quatpos::quatpos(&v31, &mv._Myfirst[v9]);
          ++v7;
          ++v9;
          ++v8;
          v10->quat.x = *(float *)v11;
          v10->quat.y = *(float *)(v11 + 4);
          v10->quat.z = *(float *)(v11 + 8);
          v10->quat.w = *(float *)(v11 + 12);
          *(_QWORD *)&v10->pos.x = *(_QWORD *)(v11 + 16);
          v10->pos.z = *(float *)(v11 + 24);
          *(_QWORD *)&v10->scale.x = *(_QWORD *)(v11 + 28);
          v10->scale.z = *(float *)(v11 + 36);
          v6 = v25;
        }
        while ( v7 < fc );
      }
      LOBYTE(v34) = 3;
      if ( mv._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&mv);
        operator delete(mv._Myfirst);
        mv._Myfirst = 0;
        mv._Mylast = 0;
        mv._Myend = 0;
      }
    }
    v12 = 0;
    if ( fc > 0 )
    {
      v13 = v6->_Mylast;
      v14 = (_DWORD *)&v13[-1].frames._Myfirst->quat.x;
      v15 = v14;
      while ( 2 )
      {
        v16 = v15;
        v17 = v14;
        v18 = 36;
        do
        {
          if ( *v16 != *v17 )
          {
            v13[-1].isAnimated = 1;
            goto LABEL_28;
          }
          ++v16;
          ++v17;
          v19 = v18 < 4;
          v18 -= 4;
        }
        while ( !v19 );
        v14 = (_DWORD *)&v13[-1].frames._Myfirst->quat.x;
        ++v12;
        v15 += 10;
        if ( v12 < fc )
          continue;
        break;
      }
    }
LABEL_28:
    LOBYTE(v34) = 2;
    if ( sName._Myres >= 0x10 )
      operator delete(sName._Bx._Ptr);
  }
  v20 = in.gap10;
  if ( *(_DWORD *)in._Filebuffer )
  {
    if ( !std::filebuf::_Endwrite((std::filebuf *)in.gap10) )
      v20 = 0;
    if ( _fclose(*(FILE **)in._Filebuffer) )
      v20 = 0;
  }
  else
  {
    v20 = 0;
  }
  in.gap10[76] = 0;
  in.gap10[69] = 0;
  std::streambuf::_Init(in.gap10);
  *(_DWORD *)in._Filebuffer = 0;
  *(_DWORD *)&in.gap10[72] = `std::filebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)&in.gap10[64] = 0;
  if ( !v20 )
    std::ios::setstate((char *)&in + *(_DWORD *)(*(_DWORD *)in.gap0 + 4), 2, 0);
  v34 = -1;
  *(_DWORD *)&in.gap0[*(_DWORD *)(*(_DWORD *)in.gap0 + 4)] = &std::ifstream::`vftable';
  *(unsigned int *)((char *)&_Right._Myres + *(_DWORD *)(*(_DWORD *)in.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)in.gap0 + 4)
                                                                                  - 112;
  v21 = *(_DWORD *)in._Filebuffer;
  *(_DWORD *)in.gap10 = &std::filebuf::`vftable';
  if ( *(_DWORD *)in._Filebuffer && **(std::ifstream ***)&in.gap10[12] == (std::ifstream *)&in.gap10[68] )
  {
    std::streambuf::setg(in.gap10, *(_DWORD *)&in.gap10[56], *(_DWORD *)&in.gap10[56], *(_DWORD *)&in.gap10[60]);
    v21 = *(_DWORD *)in._Filebuffer;
  }
  if ( in.gap10[76] )
  {
    if ( v21 )
    {
      std::filebuf::_Endwrite((std::filebuf *)in.gap10);
      _fclose(*(FILE **)in._Filebuffer);
    }
    in.gap10[76] = 0;
    in.gap10[69] = 0;
    std::streambuf::_Init(in.gap10);
    *(_DWORD *)in._Filebuffer = 0;
    *(_DWORD *)&in.gap10[72] = `std::filebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&in.gap10[64] = 0;
  }
  std::streambuf::~streambuf<char,std::char_traits<char>>(in.gap10);
  std::istream::~istream<char,std::char_traits<char>>(&in.gap10[8]);
  std::ios::~ios<char,std::char_traits<char>>(&in.gap64[12]);
}
