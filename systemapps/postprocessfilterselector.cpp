#include "postprocessfilterselector.h"
void __userpurge PostProcessFilterSelector::PostProcessFilterSelector(PostProcessFilterSelector *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  ksgui::Form *v3; // ebp
  void (__cdecl *v4)(void *); // ebx
  ksgui::Spinner *v5; // esi
  ksgui::Form_vtbl *v6; // eax
  bool v7; // zf
  std::wstring *v8; // eax
  std::wstring *v9; // esi
  std::wstring *i; // edi
  ksgui::Form_vtbl *v11; // ebp
  int v12; // ecx
  std::vector<std::wstring> *v13; // esi
  wchar_t *v14; // esi
  wchar_t *v15; // edi
  std::wstring *v16; // esi
  std::wstring *j; // edi
  ksgui::Form_vtbl *v18; // ebp
  int v19; // ecx
  char *v20; // ebx
  int v21; // ebp
  int *v22; // esi
  unsigned int v23; // edx
  int v24; // edi
  int v25; // ecx
  int v26; // edx
  unsigned int v27; // edx
  unsigned int v28; // ecx
  unsigned int v29; // ecx
  _DWORD *v30; // ecx
  int v31; // ecx
  int v32; // edx
  unsigned int v33; // edx
  unsigned int v34; // ecx
  unsigned int v35; // ecx
  int *v36; // eax
  int v37; // eax
  GameObject **v38; // esi
  int v39; // eax
  unsigned int v40; // esi
  int v41; // ecx
  std::wstring *v42; // ecx
  const wchar_t *v43; // eax
  int v44; // eax
  char v45; // al
  std::wstring *v46; // ebp
  std::wstring *v47; // esi
  _BYTE v48[28]; // [esp-Ch] [ebp-E4h] BYREF
  float y; // [esp+10h] [ebp-C8h]
  int v50; // [esp+2Ch] [ebp-ACh] BYREF
  std::vector<std::wstring> files; // [esp+30h] [ebp-A8h] BYREF
  int v52; // [esp+3Ch] [ebp-9Ch]
  void *owner; // [esp+40h] [ebp-98h]
  float v54; // [esp+44h] [ebp-94h]
  int v55[2]; // [esp+48h] [ebp-90h] BYREF
  std::wstring iname; // [esp+50h] [ebp-88h] BYREF
  std::wstring f; // [esp+68h] [ebp-70h] BYREF
  std::wstring filename; // [esp+80h] [ebp-58h] BYREF
  std::wstring path; // [esp+98h] [ebp-40h] BYREF
  std::wstring result; // [esp+B0h] [ebp-28h] BYREF
  int v61; // [esp+D4h] [ebp-4h]

  v3 = this;
  owner = this;
  v52 = 0;
  LODWORD(y) = 1;
  v55[1] = (int)this;
  *(_DWORD *)&v48[24] = aSim->game->gui;
  *(_DWORD *)&v48[20] = 7;
  *(_DWORD *)&v48[16] = 0;
  *(_WORD *)v48 = 0;
  std::wstring::assign((std::wstring *)v48, L"POST_PROCESS_FILTER_SELECTOR", 0x1Cu);
  ksgui::Form::Form(v3, a2, *(std::wstring *)v48, *(ksgui::GUI **)&v48[24], SLOBYTE(y));
  v61 = 0;
  LODWORD(y) = 19;
  v3->__vftable = (ksgui::Form_vtbl *)&PostProcessFilterSelector::`vftable';
  *(_DWORD *)&v48[24] = L"Post Process Filter";
  v3[1].__vftable = 0;
  v3[1].name._Bx._Ptr = 0;
  v3->devApp = 0;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, *(const wchar_t **)&v48[24], LODWORD(y));
  LOBYTE(v61) = 1;
  v3->formTitle->setText(v3->formTitle, &iname);
  LOBYTE(v61) = 0;
  v4 = operator delete;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v5 = (ksgui::Spinner *)operator new(0x1BCu);
  v54 = *(float *)&v5;
  v6 = 0;
  LOBYTE(v61) = 2;
  if ( v5 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"Filters", 7u);
    LOBYTE(v61) = 3;
    v52 = 1;
    ksgui::Spinner::Spinner(v5, &iname, v3->gui, 1, 0);
  }
  v61 = 0;
  v7 = (v52 & 1) == 0;
  v3[1].__vftable = v6;
  if ( !v7 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  v8 = Path::getDocumentPath(&result);
  LOBYTE(v61) = 5;
  std::operator+<wchar_t>(&path, v8, L"\\Assetto Corsa\\cfg\\ppfilters\\*.ini");
  LOBYTE(v61) = 7;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  Path::getFiles(&files, &path);
  LOBYTE(v61) = 8;
  v9 = files._Myfirst;
  for ( i = files._Mylast; v9 != i; ++v9 )
  {
    f._Myres = 7;
    f._Mysize = 0;
    f._Bx._Buf[0] = 0;
    std::wstring::assign(&f, v9, 0, 0xFFFFFFFF);
    LOBYTE(v61) = 9;
    Path::getFileNameWithoutExtension(&filename, &f);
    LOBYTE(v61) = 10;
    iname._Bx._Buf[0] = 0;
    iname._Myres = 7;
    iname._Mysize = 0;
    std::wstring::assign(&iname, &filename, 0, 0xFFFFFFFF);
    v11 = v3[1].__vftable;
    LOBYTE(v61) = 11;
    std::vector<std::wstring>::push_back((std::vector<std::wstring> *)&v11[4].onKeyChar, &iname);
    v4 = operator delete;
    v11[3].render = 0;
    v12 = (char *)v11[4].onKeyDown - (char *)v11[4].onKeyChar;
    v11[3].localToWorld = (vec2f *(*)(ksgui::Control *, vec2f *, const vec2f *))(((int)((unsigned __int64)(715827883i64 * v12) >> 32) >> 2)
                                                                                          + ((unsigned int)((unsigned __int64)(715827883i64 * v12) >> 32) >> 31)
                                                                                          - 1);
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    LOBYTE(v61) = 8;
    if ( f._Myres >= 8 )
      operator delete(f._Bx._Ptr);
    v3 = (ksgui::Form *)owner;
  }
  std::wstring::assign(&path, L"system/cfg/ppfilters/*.ini", 0x1Au);
  v13 = Path::getFiles((std::vector<std::wstring> *)&iname, &path);
  if ( &files != v13 )
  {
    if ( files._Myfirst )
    {
      y = v54;
      *(_DWORD *)&v48[24] = (char *)&v50 + 3;
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(files._Myfirst, files._Mylast);
      v4(files._Myfirst);
      files._Myfirst = 0;
      files._Mylast = 0;
      files._Myend = 0;
    }
    files = *v13;
    v13->_Myfirst = 0;
    v13->_Mylast = 0;
    v13->_Myend = 0;
  }
  LOBYTE(v61) = 8;
  v14 = iname._Bx._Ptr;
  if ( iname._Bx._Ptr )
  {
    v15 = *(wchar_t **)&iname._Bx._Alias[4];
    if ( iname._Bx._Ptr != *(wchar_t **)&iname._Bx._Alias[4] )
    {
      do
      {
        if ( *((_DWORD *)v14 + 5) >= 8u )
          v4(*(void **)v14);
        *((_DWORD *)v14 + 5) = 7;
        *((_DWORD *)v14 + 4) = 0;
        *v14 = 0;
        v14 += 12;
      }
      while ( v14 != v15 );
      v14 = iname._Bx._Ptr;
    }
    v4(v14);
  }
  v16 = files._Myfirst;
  for ( j = files._Mylast; v16 != j; ++v16 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, v16, 0, 0xFFFFFFFF);
    LOBYTE(v61) = 13;
    Path::getFileNameWithoutExtension(&filename, &iname);
    LOBYTE(v61) = 14;
    f._Bx._Buf[0] = 0;
    f._Myres = 7;
    f._Mysize = 0;
    std::wstring::assign(&f, &filename, 0, 0xFFFFFFFF);
    v18 = v3[1].__vftable;
    LOBYTE(v61) = 15;
    std::vector<std::wstring>::push_back((std::vector<std::wstring> *)&v18[4].onKeyChar, &f);
    v18[3].render = 0;
    v19 = (char *)v18[4].onKeyDown - (char *)v18[4].onKeyChar;
    v18[3].localToWorld = (vec2f *(*)(ksgui::Control *, vec2f *, const vec2f *))(((int)((unsigned __int64)(715827883i64 * v19) >> 32) >> 2)
                                                                                          + ((unsigned int)((unsigned __int64)(715827883i64 * v19) >> 32) >> 31)
                                                                                          - 1);
    if ( f._Myres >= 8 )
      operator delete(f._Bx._Ptr);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    LOBYTE(v61) = 8;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    v3 = (ksgui::Form *)owner;
  }
  v20 = (char *)owner;
  LODWORD(y) = owner;
  *(_DWORD *)&v48[4] = &std::_Func_impl<std::_Callable_obj<_lambda_aa987d133df4fd7fd6aa7686a5c7b0ae_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  *(_DWORD *)&v48[8] = owner;
  *(_DWORD *)&v48[20] = &v48[4];
  LOBYTE(v61) = 8;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)(*((_DWORD *)owner + 80) + 300),
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v48[4],
    owner);
  (*(void (**)(_DWORD, int, int))(**((_DWORD **)v20 + 80) + 28))(
    *((_DWORD *)v20 + 80),
    1128792064,
    1106247680);
  ksgui::Spinner::setPosition(*((ksgui::Spinner **)v20 + 80), 58.0, 70.0);
  v21 = *((_DWORD *)v20 + 80);
  v22 = (int *)(v20 + 136);
  v23 = *((_DWORD *)v20 + 35);
  v52 = v21;
  v55[0] = v21;
  if ( (unsigned int)v55 >= v23 || (v24 = *v22, *v22 > (unsigned int)v55) )
  {
    v31 = *((_DWORD *)v20 + 36);
    if ( v23 == v31 && !((int)(v31 - v23) >> 2) )
    {
      v32 = (int)(v23 - *v22) >> 2;
      if ( v32 == 0x3FFFFFFF )
        std::_Xlength_error("vector<T> too long");
      v33 = v32 + 1;
      v34 = (v31 - *v22) >> 2;
      if ( 0x3FFFFFFF - (v34 >> 1) >= v34 )
        v35 = (v34 >> 1) + v34;
      else
        v35 = 0;
      if ( v35 < v33 )
        v35 = v33;
      std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)(v20 + 136), v35);
      v21 = v52;
    }
    v36 = (int *)*((_DWORD *)v20 + 35);
    if ( v36 )
      *v36 = v21;
  }
  else
  {
    v25 = *((_DWORD *)v20 + 36);
    if ( v23 == v25 && !((int)(v25 - v23) >> 2) )
    {
      v26 = (int)(v23 - v24) >> 2;
      if ( v26 == 0x3FFFFFFF )
        std::_Xlength_error("vector<T> too long");
      v27 = v26 + 1;
      v28 = (v25 - *v22) >> 2;
      if ( 0x3FFFFFFF - (v28 >> 1) >= v28 )
        v29 = (v28 >> 1) + v28;
      else
        v29 = 0;
      if ( v29 < v27 )
        v29 = v27;
      std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)(v20 + 136), v29);
    }
    v30 = (_DWORD *)*((_DWORD *)v20 + 35);
    if ( v30 )
      *v30 = *(_DWORD *)(*v22 + 4 * (((int)v55 - v24) >> 2));
  }
  v37 = v52;
  *((_DWORD *)v20 + 35) += 4;
  *(_DWORD *)(v37 + 148) = v20;
  v38 = aSim->gameObjects._Myfirst;
  if ( v38 == aSim->gameObjects._Mylast )
  {
LABEL_66:
    v39 = 0;
  }
  else
  {
    while ( 1 )
    {
      v39 = __RTDynamicCast(
              *v38,
              0,
              &GameObject `RTTI Type Descriptor',
              &PostProcessEffectsUpdater `RTTI Type Descriptor',
              0);
      if ( v39 )
        break;
      if ( ++v38 == aSim->gameObjects._Mylast )
        goto LABEL_66;
    }
  }
  v40 = 0;
  v41 = (char *)files._Mylast - (char *)files._Myfirst;
  *((_DWORD *)v20 + 81) = v39;
  if ( v41 / 24 )
  {
    do
    {
      v42 = ksgui::Spinner::getItemAt(*((ksgui::Spinner **)v20 + 80), &filename, v40);
      LOBYTE(v61) = 17;
      v43 = (const wchar_t *)(*((_DWORD *)v20 + 81) + 52);
      if ( *(_DWORD *)(*((_DWORD *)v20 + 81) + 72) >= 8u )
        v43 = *(const wchar_t **)v43;
      v44 = std::wstring::compare(v42, 0, v42->_Mysize, v43, *(_DWORD *)(*((_DWORD *)v20 + 81) + 68));
      LOBYTE(v61) = 8;
      v45 = v44 == 0;
      HIBYTE(v50) = v45;
      if ( filename._Myres >= 8 )
      {
        operator delete(filename._Bx._Ptr);
        v45 = HIBYTE(v50);
      }
      if ( v45 )
        ksgui::Spinner::setValue(*((ksgui::Spinner **)v20 + 80), v40);
      ++v40;
    }
    while ( v40 < files._Mylast - files._Myfirst );
  }
  ksgui::Form::setSize((ksgui::Form *)v20, 300.0, 110.0);
  (*(void (**)(char *, _DWORD))(*(_DWORD *)v20 + 76))(v20, *((_DWORD *)v20 + 64));
  LOBYTE(v61) = 7;
  if ( files._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&files);
    v46 = files._Mylast;
    v47 = files._Myfirst;
    if ( files._Myfirst != files._Mylast )
    {
      do
      {
        if ( v47->_Myres >= 8 )
          operator delete(v47->_Bx._Ptr);
        v47->_Myres = 7;
        v47->_Mysize = 0;
        v47->_Bx._Buf[0] = 0;
        ++v47;
      }
      while ( v47 != v46 );
      v47 = files._Myfirst;
    }
    operator delete(v47);
    files._Myfirst = 0;
    files._Mylast = 0;
    files._Myend = 0;
  }
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
}
PostProcessFilterSelector *PostProcessFilterSelector::`scalar deleting destructor'(PostProcessFilterSelector *this, unsigned int a2)
{
  PostProcessFilterSelector::~PostProcessFilterSelector(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PostProcessFilterSelector::~PostProcessFilterSelector(PostProcessFilterSelector *this)
{
  std::wstring *v2; // eax
  ksgui::Spinner *v3; // ecx
  std::wstring *v4; // eax
  std::wstring *v5; // ecx
  std::wstring path; // [esp+10h] [ebp-58h] BYREF
  std::wstring result; // [esp+28h] [ebp-40h] BYREF
  std::wstring v8; // [esp+40h] [ebp-28h] BYREF
  int v9; // [esp+64h] [ebp-4h]

  this->__vftable = (PostProcessFilterSelector_vtbl *)&PostProcessFilterSelector::`vftable';
  v9 = 0;
  v2 = Path::getDocumentPath(&result);
  LOBYTE(v9) = 1;
  std::operator+<wchar_t>(&path, v2, L"\\Assetto Corsa\\cfg\\video.ini");
  LOBYTE(v9) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v3 = this->spinner;
  result._Bx._Buf[0] = 0;
  result._Myres = 7;
  result._Mysize = 0;
  v4 = ksgui::Spinner::getCurrentItem(v3, &v8);
  v5 = &path;
  if ( path._Myres >= 8 )
    v5 = (std::wstring *)path._Bx._Ptr;
  if ( v4->_Myres >= 8 )
    v4 = (std::wstring *)v4->_Bx._Ptr;
  WritePrivateProfileStringW(L"POST_PROCESS", L"FILTER", v4->_Bx._Buf, v5->_Bx._Buf);
  if ( v8._Myres >= 8 )
    operator delete(v8._Bx._Ptr);
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  v9 = -1;
  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  this->__vftable = (PostProcessFilterSelector_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
