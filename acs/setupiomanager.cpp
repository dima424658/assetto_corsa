#include "setupiomanager.h
void SetupIOManager::SetupIOManager(SetupIOManager *this, Sim *aSim)
{
  unsigned int v3; // ebx
  ksgui::ListBox *v4; // esi
  ksgui::ListBox *v5; // eax
  std::wstring *v6; // eax
  const std::wstring *v7; // eax
  CarAvatar *v8; // eax
  std::wstring *v9; // ecx
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v10; // esi
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  const std::wstring *v14; // eax
  CarAvatar *v15; // eax
  std::wstring *v16; // ecx
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v17; // esi
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  const std::wstring *v22; // eax
  ksgui::ListBox *v23; // ecx
  const ksgui::ListBoxRowData *v24; // eax
  std::wstring *v25; // esi
  unsigned int v26; // ebp
  int v27; // ecx
  int v28; // ebx
  ksgui::ListBox *v29; // ecx
  const ksgui::ListBoxRowData *v30; // eax
  std::wstring *v31; // ecx
  std::wstring *v32; // edx
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v33; // eax
  Sim *v34; // ecx
  CarAvatar *v35; // eax
  std::wstring *v36; // ecx
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v37; // esi
  std::wstring *v38; // eax
  std::wstring *v39; // eax
  std::wstring *v40; // eax
  std::wstring *v41; // eax
  std::wstring *v42; // eax
  const std::wstring *v43; // eax
  ksgui::ListBox *v44; // eax
  ksgui::ListBox *v45; // eax
  std::wstring *v46; // eax
  ksgui::ListBox *v47; // ecx
  ksgui::ListBoxRow *v48; // ecx
  ksgui::ListBox *v49; // eax
  Font *v50; // esi
  ksgui::ActiveButton *v51; // eax
  ksgui::ActiveButton *v52; // ecx
  ksgui::ActiveButton *v53; // ecx
  float v54; // xmm1_4
  Font *v55; // esi
  ksgui::ActiveButton *v56; // eax
  Event<OnMouseWheelMovedEvent> *v57; // ecx
  ksgui::ActiveButton *v58; // ecx
  ksgui::ActiveButton *v59; // ecx
  float v60; // xmm0_4
  Font *v61; // esi
  ksgui::ActiveButton *v62; // eax
  ksgui::ActiveButton *v63; // ecx
  ksgui::ActiveButton *v64; // ecx
  float v65; // xmm0_4
  Event<OnMouseWheelMovedEvent> *v66; // ecx
  Font *v67; // esi
  ksgui::Control *v68; // eax
  ksgui::Control *v69; // eax
  ksgui::Control *v70; // ecx
  Event<OnMouseWheelMovedEvent> *v71; // ecx
  Font *v72; // esi
  ksgui::ActiveButton *v73; // eax
  ksgui::ActiveButton *v74; // ecx
  ksgui::ActiveButton *v75; // eax
  ksgui::ActiveButton *v76; // ecx
  float v77; // xmm0_4
  Font *v78; // esi
  ksgui::TextInput *v79; // eax
  Font *v80; // eax
  Font *v81; // eax
  std::_Ref_count_base *v82; // esi
  ksgui::ActiveButton *v83; // ecx
  ksgui::ActiveButton *v84; // eax
  Font *v85; // esi
  ksgui::ListBox *v86; // eax
  ksgui::ListBox *v87; // eax
  std::wstring *v88; // eax
  ksgui::ListBox *v89; // ecx
  ksgui::ListBoxRow *v90; // ecx
  ksgui::ListBox *v91; // eax
  ksgui::TextInput *v92; // ecx
  std::allocator<wchar_t> *v93; // eax
  SetupIOManager::{ctor}::__l23::<lambda_976c79855a6dadcae9f5d36ece314050> *v94; // eax
  SetupIOManager::{ctor}::__l24::<lambda_1fb02ca72f51846335925a618f490a43> *v95; // eax
  SetupIOManager::{ctor}::__l25::<lambda_d69f21d976d1d06b6fd05ef33606f75b> *v96; // eax
  SetupIOManager::{ctor}::__l26::<lambda_b2cfcc70492f792e61fd520a8d98558b> *v97; // eax
  SetupIOManager::{ctor}::__l27::<lambda_e1e3b15fa0bdd39136aa4fc3367e9e69> *v98; // eax
  SetupIOManager::{ctor}::__l28::<lambda_be89d894e85a1cb82d1d573b487ac16c> *v99; // eax
  _BYTE v100[40]; // [esp+30h] [ebp-220h] BYREF
  std::shared_ptr<Font> __formal; // [esp+78h] [ebp-1D8h] BYREF
  ksgui::ListBox *v102; // [esp+80h] [ebp-1D0h]
  int v103; // [esp+84h] [ebp-1CCh] BYREF
  unsigned int v104; // [esp+88h] [ebp-1C8h]
  std::vector<std::wstring> tracks; // [esp+8Ch] [ebp-1C4h] BYREF
  std::wstring v106; // [esp+98h] [ebp-1B8h] BYREF
  SetupIOManager *v107; // [esp+B0h] [ebp-1A0h]
  std::wstring text; // [esp+B4h] [ebp-19Ch] BYREF
  std::wstring iname; // [esp+CCh] [ebp-184h] BYREF
  std::wstring _Right; // [esp+E4h] [ebp-16Ch] BYREF
  std::wstring result; // [esp+FCh] [ebp-154h] BYREF
  std::wstring folder; // [esp+114h] [ebp-13Ch] BYREF
  std::wstring name; // [esp+12Ch] [ebp-124h] BYREF
  std::wstring v114; // [esp+144h] [ebp-10Ch] BYREF
  std::wstring v115; // [esp+15Ch] [ebp-F4h] BYREF
  ksgui::ListBoxRowData v116; // [esp+174h] [ebp-DCh] BYREF
  ksgui::ListBoxRowData titleRow; // [esp+1B8h] [ebp-98h] BYREF
  ksgui::ListBoxRowData setupTitleRow; // [esp+1FCh] [ebp-54h] BYREF
  int v119; // [esp+24Ch] [ebp-4h]

  v3 = 0;
  v104 = 0;
  *(_DWORD *)&v100[36] = this->sim;
  v107 = this;
  *(_DWORD *)&v100[32] = aSim->game->gui;
  *(_DWORD *)&v100[28] = 7;
  *(_DWORD *)&v100[24] = 0;
  *(_WORD *)&v100[8] = 0;
  std::wstring::assign((std::wstring *)&v100[8], L"Setup I/O", 9u);
  SetupTab::SetupTab(this, *(std::wstring *)&v100[8], *(ksgui::GUI **)&v100[32], *(Sim **)&v100[36]);
  this->__vftable = (SetupIOManager_vtbl *)&SetupIOManager::`vftable';
  this->activeSetup._Myres = 7;
  this->activeSetup._Mysize = 0;
  v119 = 0;
  this->activeSetup._Bx._Buf[0] = 0;
  this->activeTrack._Myres = 7;
  this->activeTrack._Mysize = 0;
  this->activeTrack._Bx._Buf[0] = 0;
  this->status._Myres = 7;
  this->status._Mysize = 0;
  this->status._Bx._Buf[0] = 0;
  LOBYTE(v119) = 3;
  ksgui::Control::setSize(this, 450.0, 600.0);
  *(_DWORD *)&v100[36] = 368;
  this->overrideSetup = 0;
  this->sim = aSim;
  v4 = (ksgui::ListBox *)operator new(*(_DWORD *)&v100[36]);
  v102 = v4;
  v5 = 0;
  LOBYTE(v119) = 4;
  if ( v4 )
  {
    *(_DWORD *)&v100[36] = 1;
    *(_DWORD *)&v100[32] = this->gui;
    *(_DWORD *)&v100[28] = 1;
    *(_DWORD *)&v100[24] = 15;
    *(_DWORD *)&v100[20] = 7;
    *(_DWORD *)&v100[16] = 0;
    *(_WORD *)v100 = 0;
    std::wstring::assign((std::wstring *)v100, L"TRACK_LISTBOX", 0xDu);
    ksgui::ListBox::ListBox(
      v4,
      *(std::wstring *)v100,
      *(unsigned int *)&v100[24],
      *(unsigned int *)&v100[28],
      *(ksgui::GUI **)&v100[32],
      v100[36]);
  }
  *(_DWORD *)&v100[36] = v5;
  LOBYTE(v119) = 3;
  this->trackListBox = v5;
  ksgui::Control::addControl(this, *(ksgui::Control **)&v100[36]);
  ksgui::Form::setPosition((ksgui::Form *)this->trackListBox, 15.0, 110.0);
  ((void (*)(ksgui::ListBox *, int, int))this->trackListBox->setSize)(
    this->trackListBox,
    1128923136,
    1133576192);
  this->trackListBox->allowDeselection = 0;
  v6 = Path::getDocumentPath(&result);
  LOBYTE(v119) = 5;
  v7 = std::operator+<wchar_t>(&text, v6, L"/Assetto Corsa/setups");
  LOBYTE(v119) = 6;
  Path::createFolder(v7);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  LOBYTE(v119) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v8 = Sim::getCar(this->sim, 0);
  if ( v8->unixName._Myres < 8 )
    v9 = &v8->unixName;
  else
    v9 = (std::wstring *)v8->unixName._Bx._Ptr;
  v10._Ptr = &v9->_Bx._Buf[v8->unixName._Mysize];
  v11 = &Sim::getCar(this->sim, 0)->unixName;
  if ( v11->_Myres >= 8 )
    v11 = (std::wstring *)v11->_Bx._Ptr;
  _Right._Myres = 7;
  _Right._Bx._Buf[0] = 0;
  _Right._Mysize = 0;
  std::wstring::_Construct<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>>(
    &_Right,
    (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v11,
    v10,
    (std::forward_iterator_tag)__formal._Ptr);
  LOBYTE(v119) = 7;
  v12 = Path::getDocumentPath(&name);
  LOBYTE(v119) = 8;
  v13 = std::operator+<wchar_t>(&folder, v12, L"/Assetto Corsa/setups/");
  LOBYTE(v119) = 9;
  v14 = std::operator+<wchar_t>(&text, v13, &_Right);
  LOBYTE(v119) = 10;
  Path::createFolder(v14);
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  if ( folder._Myres >= 8 )
    operator delete(folder._Bx._Ptr);
  folder._Myres = 7;
  folder._Mysize = 0;
  folder._Bx._Buf[0] = 0;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  LOBYTE(v119) = 3;
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
  v15 = Sim::getCar(this->sim, 0);
  if ( v15->unixName._Myres < 8 )
    v16 = &v15->unixName;
  else
    v16 = (std::wstring *)v15->unixName._Bx._Ptr;
  v17._Ptr = &v16->_Bx._Buf[v15->unixName._Mysize];
  v18 = &Sim::getCar(this->sim, 0)->unixName;
  if ( v18->_Myres >= 8 )
    v18 = (std::wstring *)v18->_Bx._Ptr;
  _Right._Myres = 7;
  _Right._Bx._Buf[0] = 0;
  _Right._Mysize = 0;
  std::wstring::_Construct<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>>(
    &_Right,
    (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v18,
    v17,
    (std::forward_iterator_tag)__formal._Ptr);
  LOBYTE(v119) = 11;
  v19 = Path::getDocumentPath(&v115);
  LOBYTE(v119) = 12;
  v20 = std::operator+<wchar_t>(&folder, v19, L"/Assetto Corsa/setups/");
  LOBYTE(v119) = 13;
  v21 = std::operator+<wchar_t>(&text, v20, &_Right);
  LOBYTE(v119) = 14;
  v22 = std::operator+<wchar_t>(&name, v21, L"/generic");
  LOBYTE(v119) = 15;
  Path::createFolder(v22);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  if ( folder._Myres >= 8 )
    operator delete(folder._Bx._Ptr);
  folder._Myres = 7;
  folder._Mysize = 0;
  folder._Bx._Buf[0] = 0;
  if ( v115._Myres >= 8 )
    operator delete(v115._Bx._Ptr);
  v115._Myres = 7;
  v115._Mysize = 0;
  v115._Bx._Buf[0] = 0;
  LOBYTE(v119) = 3;
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
  *(_DWORD *)&v100[36] = 7;
  *(_DWORD *)&v100[32] = 0;
  *(_WORD *)&v100[16] = 0;
  std::wstring::assign((std::wstring *)&v100[16], L"generic", 7u);
  ksgui::ListBoxRowData::ListBoxRowData(&v116, *(std::wstring *)&v100[16]);
  v23 = this->trackListBox;
  LOBYTE(v119) = 16;
  ksgui::ListBox::addItem(v23, v24);
  LOBYTE(v119) = 3;
  ksgui::ListBoxRowData::~ListBoxRowData(&v116);
  folder._Myres = 7;
  folder._Mysize = 0;
  folder._Bx._Buf[0] = 0;
  std::wstring::assign(&folder, L"content/tracks/*.*", 0x12u);
  LOBYTE(v119) = 17;
  Path::getFolders(&tracks, &folder);
  LOBYTE(v119) = 19;
  if ( folder._Myres >= 8 )
    operator delete(folder._Bx._Ptr);
  v25 = tracks._Myfirst;
  v26 = 0;
  folder._Bx._Buf[0] = 0;
  v27 = (char *)tracks._Mylast - (char *)tracks._Myfirst;
  folder._Myres = 7;
  folder._Mysize = 0;
  if ( tracks._Mylast - tracks._Myfirst )
  {
    v28 = 0;
    do
    {
      if ( std::wstring::compare(&v25[v28], 0, v25[v28]._Mysize, L"ai", 2u) )
      {
        *(_DWORD *)&v100[36] = 7;
        *(_DWORD *)&v100[32] = 0;
        *(_WORD *)&v100[16] = 0;
        std::wstring::assign((std::wstring *)&v100[16], &tracks._Myfirst[v28], 0, 0xFFFFFFFF);
        ksgui::ListBoxRowData::ListBoxRowData(&v116, *(std::wstring *)&v100[16]);
        v29 = this->trackListBox;
        LOBYTE(v119) = 20;
        ksgui::ListBox::addItem(v29, v30);
        LOBYTE(v119) = 19;
        ksgui::ListBoxRowData::~ListBoxRowData(&v116);
        v31 = &tracks._Myfirst[v28];
        if ( tracks._Myfirst[v28]._Myres < 8 )
          v32 = &tracks._Myfirst[v28];
        else
          v32 = (std::wstring *)v31->_Bx._Ptr;
        v33._Ptr = &v32->_Bx._Buf[v31->_Mysize];
        if ( v31->_Myres >= 8 )
          v31 = (std::wstring *)v31->_Bx._Ptr;
        text._Myres = 7;
        text._Mysize = 0;
        text._Bx._Buf[0] = 0;
        std::wstring::_Construct<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>>(
          &text,
          (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v31,
          v33,
          (std::forward_iterator_tag)__formal._Ptr);
        v34 = this->sim;
        LOBYTE(v119) = 21;
        v35 = Sim::getCar(v34, 0);
        if ( v35->unixName._Myres < 8 )
          v36 = &v35->unixName;
        else
          v36 = (std::wstring *)v35->unixName._Bx._Ptr;
        v37._Ptr = &v36->_Bx._Buf[v35->unixName._Mysize];
        v38 = &Sim::getCar(this->sim, 0)->unixName;
        if ( v38->_Myres >= 8 )
          v38 = (std::wstring *)v38->_Bx._Ptr;
        _Right._Myres = 7;
        _Right._Bx._Buf[0] = 0;
        _Right._Mysize = 0;
        std::wstring::_Construct<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>>(
          &_Right,
          (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v38,
          v37,
          (std::forward_iterator_tag)__formal._Ptr);
        LOBYTE(v119) = 22;
        v39 = Path::getDocumentPath(&result);
        LOBYTE(v119) = 23;
        v40 = std::operator+<wchar_t>(&iname, v39, L"/Assetto Corsa/setups/");
        LOBYTE(v119) = 24;
        v41 = std::operator+<wchar_t>(&v114, v40, &_Right);
        LOBYTE(v119) = 25;
        v42 = std::operator+<wchar_t>(&name, v41, L"/");
        LOBYTE(v119) = 26;
        v43 = std::operator+<wchar_t>(&v115, v42, &text);
        LOBYTE(v119) = 27;
        Path::createFolder(v43);
        if ( v115._Myres >= 8 )
          operator delete(v115._Bx._Ptr);
        v115._Myres = 7;
        v115._Mysize = 0;
        v115._Bx._Buf[0] = 0;
        if ( name._Myres >= 8 )
          operator delete(name._Bx._Ptr);
        name._Myres = 7;
        name._Mysize = 0;
        name._Bx._Buf[0] = 0;
        if ( v114._Myres >= 8 )
          operator delete(v114._Bx._Ptr);
        v114._Myres = 7;
        v114._Mysize = 0;
        v114._Bx._Buf[0] = 0;
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        if ( _Right._Myres >= 8 )
          operator delete(_Right._Bx._Ptr);
        _Right._Myres = 7;
        _Right._Mysize = 0;
        _Right._Bx._Buf[0] = 0;
        LOBYTE(v119) = 19;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
      }
      v25 = tracks._Myfirst;
      ++v26;
      v27 = (char *)tracks._Mylast - (char *)tracks._Myfirst;
      ++v28;
    }
    while ( v26 < tracks._Mylast - tracks._Myfirst );
    v3 = v104;
  }
  *(_DWORD *)&v100[36] = v27;
  ksgui::ListBox::setItemsFontSize(this->trackListBox, 15.0);
  ksgui::ListBox::scrollToTop(this->trackListBox);
  v44 = this->trackListBox;
  *(_DWORD *)&v100[36] = 5;
  *(_DWORD *)&v100[32] = L"Track";
  v44->backColor = (vec4f)_xmm;
  v45 = this->trackListBox;
  _Right._Myres = 7;
  _Right._Mysize = 0;
  v45->borderColor = (vec4f)_xmm;
  _Right._Bx._Buf[0] = 0;
  std::wstring::assign(&_Right, *(const wchar_t **)&v100[32], *(unsigned int *)&v100[36]);
  LOBYTE(v119) = 28;
  v46 = acTranslate(&result, &_Right);
  LOBYTE(v119) = 29;
  std::operator+<wchar_t>((std::wstring *)&v100[16], v46, L" : ");
  ksgui::ListBoxRowData::ListBoxRowData(&titleRow, *(std::wstring *)&v100[16]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v119) = 32;
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
  v47 = this->trackListBox;
  _Right._Bx._Buf[0] = 0;
  *(_DWORD *)&v100[36] = &titleRow;
  _Right._Myres = 7;
  v48 = v47->titleRow;
  _Right._Mysize = 0;
  ksgui::ListBoxRow::setRow(v48, &titleRow);
  ksgui::ListBoxRow::setFontAlignment(this->trackListBox->titleRow, eAlignCenter);
  v49 = this->trackListBox;
  *(_DWORD *)&v100[36] = 0;
  v49->titleRow->drawRowBackground = 0;
  ksgui::ListBox::drawCellsBackgrounds(this->trackListBox, v100[36]);
  v50 = (Font *)operator new(448);
  __formal._Ptr = v50;
  v51 = 0;
  LOBYTE(v119) = 33;
  if ( v50 )
  {
    *(_DWORD *)&v100[36] = this->gui;
    *(_DWORD *)&v100[32] = 7;
    *(_DWORD *)&v100[28] = 0;
    *(_WORD *)&v100[12] = 0;
    std::wstring::assign((std::wstring *)&v100[12], L"LOAD_BUTTON", 0xBu);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v50, *(std::wstring *)&v100[12], *(ksgui::GUI **)&v100[36]);
  }
  this->loadButton = v51;
  LOBYTE(v119) = 32;
  *(_DWORD *)&v100[36] = 7;
  *(_DWORD *)&v100[32] = 0;
  *(_WORD *)&v100[16] = 0;
  std::wstring::assign((std::wstring *)&v100[16], L"content/gui/setupIO/btn_load", 0x1Cu);
  ksgui::ActiveButton::setMultipleTexture(this->loadButton, v3, *(std::wstring *)&v100[16]);
  ksgui::Control::addControl(this, this->loadButton);
  ((void (*)(ksgui::ActiveButton *, int, int))this->loadButton->setSize)(
    this->loadButton,
    1112014848,
    1112014848);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->loadButton,
    this->trackListBox->rect.left,
    (float)((float)(this->trackListBox->rect.bottom - this->trackListBox->rect.top) + this->trackListBox->rect.top)
  + 10.0);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Load", 4u);
  LOBYTE(v119) = 34;
  *(_DWORD *)&v100[36] = acTranslate(&iname, &text);
  v52 = this->loadButton;
  LOBYTE(v119) = 35;
  v52->setText(v52, *(const std::wstring **)&v100[36]);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v119) = 32;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v53 = this->loadButton;
  __formal._Ptr = 0;
  *(_DWORD *)&v100[36] = 448;
  v54 = v53->rect.bottom - v53->rect.top;
  v53->textCoord.x = 0.0;
  *(float *)&__formal._Rep = v54;
  v53->textCoord.y = v54;
  v55 = (Font *)operator new(*(_DWORD *)&v100[36]);
  __formal._Ptr = v55;
  LOBYTE(v119) = 36;
  if ( v55 )
  {
    *(_DWORD *)&v100[36] = this->gui;
    std::wstring::wstring((std::wstring *)&v100[12], L"RESET_BUTTON");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v55, *(std::wstring *)&v100[12], *(ksgui::GUI **)&v100[36]);
  }
  else
  {
    v56 = 0;
  }
  this->resetButton = v56;
  LOBYTE(v119) = 32;
  *(_DWORD *)&v100[36] = 7;
  *(_DWORD *)&v100[32] = 0;
  *(_WORD *)&v100[16] = 0;
  std::wstring::assign((std::wstring *)&v100[16], L"content/gui/setupIO/reset_button", 0x20u);
  ksgui::ActiveButton::setMultipleTexture(this->resetButton, v3, *(std::wstring *)&v100[16]);
  ksgui::Control::addControl(this, this->resetButton);
  ((void (*)(ksgui::ActiveButton *, int, int))this->resetButton->setSize)(
    this->resetButton,
    1112014848,
    1112014848);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->resetButton,
    (float)((float)((float)(this->rect.right - this->rect.left) * 0.5)
          - (float)(this->resetButton->rect.right - this->resetButton->rect.left))
  - 45.0,
    this->loadButton->rect.top);
  *(_DWORD *)&v100[36] = this;
  *(_DWORD *)&v100[12] = &std::_Func_impl<std::_Callable_obj<_lambda_8759acc0ca6187b6bc4aa15f32484545_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v100[16] = this;
  *(_DWORD *)&v100[28] = &v100[12];
  v57 = (Event<OnMouseWheelMovedEvent> *)&this->resetButton->evClicked;
  LOBYTE(v119) = 32;
  Event<ksgui::OnControlClicked>::addHandler(
    v57,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v100[12],
    this);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Reset To Default", 0x10u);
  LOBYTE(v119) = 38;
  *(_DWORD *)&v100[36] = acTranslate(&iname, &text);
  v58 = this->resetButton;
  LOBYTE(v119) = 39;
  v58->setText(v58, *(const std::wstring **)&v100[36]);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v119) = 32;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v59 = this->resetButton;
  __formal._Ptr = 0;
  *(_DWORD *)&v100[36] = 448;
  v60 = v59->rect.bottom - v59->rect.top;
  v59->textCoord.x = 0.0;
  *(float *)&__formal._Rep = v60;
  v59->textCoord.y = v60;
  v61 = (Font *)operator new(*(_DWORD *)&v100[36]);
  __formal._Ptr = v61;
  LOBYTE(v119) = 40;
  if ( v61 )
  {
    *(_DWORD *)&v100[36] = this->gui;
    std::wstring::wstring((std::wstring *)&v100[12], L"REMOVE_BUTTON");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v61, *(std::wstring *)&v100[12], *(ksgui::GUI **)&v100[36]);
  }
  else
  {
    v62 = 0;
  }
  LOBYTE(v119) = 32;
  this->removeButton = v62;
  std::wstring::wstring((std::wstring *)&v100[16], L"content/gui/setupIO/btn_delete");
  ksgui::ActiveButton::setMultipleTexture(this->removeButton, v3, *(std::wstring *)&v100[16]);
  ksgui::Control::addControl(this, this->removeButton);
  ((void (*)(ksgui::ActiveButton *, int, int))this->removeButton->setSize)(
    this->removeButton,
    1112014848,
    1112014848);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->removeButton,
    (float)((float)(this->rect.right - this->rect.left) * 0.5) + 45.0,
    this->loadButton->rect.top);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Delete", 6u);
  LOBYTE(v119) = 41;
  *(_DWORD *)&v100[36] = acTranslate(&iname, &text);
  v63 = this->removeButton;
  LOBYTE(v119) = 42;
  v63->setText(v63, *(const std::wstring **)&v100[36]);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v64 = this->removeButton;
  __formal._Ptr = 0;
  *(_DWORD *)&v100[36] = this;
  v65 = v64->rect.bottom - v64->rect.top;
  v64->textCoord.x = 0.0;
  *(float *)&__formal._Rep = v65;
  v64->textCoord.y = v65;
  *(_DWORD *)&v100[12] = &std::_Func_impl<std::_Callable_obj<_lambda_d004a09e503e10e8c0550315956595df_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v100[16] = this;
  *(_DWORD *)&v100[28] = &v100[12];
  v66 = (Event<OnMouseWheelMovedEvent> *)&this->removeButton->evClicked;
  LOBYTE(v119) = 32;
  Event<ksgui::OnControlClicked>::addHandler(
    v66,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v100[12],
    *(void **)&v100[36]);
  v67 = (Font *)operator new(280);
  __formal._Ptr = v67;
  LOBYTE(v119) = 44;
  if ( v67 )
  {
    std::wstring::wstring(&iname, L"CONFIRM_BUTTON");
    *(_DWORD *)&v100[36] = this->gui;
    LOBYTE(v119) = 45;
    v3 = 1;
    v104 = 1;
    ksgui::Control::Control((ksgui::Control *)v67, &iname, *(ksgui::GUI **)&v100[36]);
  }
  else
  {
    v68 = 0;
  }
  this->confirmButton = v68;
  v119 = 32;
  if ( (v3 & 1) != 0 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  ksgui::Control::addControl(this, this->confirmButton);
  this->confirmButton->backColor = (vec4f)_mm_loadu_si128((const __m128i *)&colTitleBar_11);
  ((void (*)(ksgui::Control *, int, int))this->confirmButton->setSize)(
    this->confirmButton,
    1112014848,
    1098907648);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->confirmButton,
    (float)(this->rect.right - this->rect.left) - 60.0,
    570.0);
  v69 = this->confirmButton;
  *(_DWORD *)&v100[36] = L"DELETE";
  v69->fontScale = 0.69999999;
  std::wstring::wstring(&v114, *(const wchar_t **)&v100[36]);
  LOBYTE(v119) = 47;
  *(_DWORD *)&v100[36] = acTranslate(&iname, &v114);
  v70 = this->confirmButton;
  LOBYTE(v119) = 48;
  v70->setText(v70, *(const std::wstring **)&v100[36]);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  if ( v114._Myres >= 8 )
    operator delete(v114._Bx._Ptr);
  *(_DWORD *)&v100[36] = this;
  *(_DWORD *)&v100[12] = &std::_Func_impl<std::_Callable_obj<_lambda_b1dff931891abcb98a0593128298a719_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v100[16] = this;
  *(_DWORD *)&v100[28] = &v100[12];
  v71 = (Event<OnMouseWheelMovedEvent> *)&this->confirmButton->evClicked;
  LOBYTE(v119) = 32;
  Event<ksgui::OnControlClicked>::addHandler(
    v71,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v100[12],
    this);
  v72 = (Font *)operator new(448);
  __formal._Ptr = v72;
  LOBYTE(v119) = 50;
  if ( v72 )
  {
    *(_DWORD *)&v100[36] = this->gui;
    std::wstring::wstring((std::wstring *)&v100[12], L"SAVE_BUTTON");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v72, *(std::wstring *)&v100[12], *(ksgui::GUI **)&v100[36]);
  }
  else
  {
    v73 = 0;
  }
  LOBYTE(v119) = 32;
  this->saveButton = v73;
  std::wstring::wstring((std::wstring *)&v100[16], L"content/gui/setupIO/btn_save");
  ksgui::ActiveButton::setMultipleTexture(this->saveButton, v3, *(std::wstring *)&v100[16]);
  ((void (*)(ksgui::ActiveButton *, int, int))this->saveButton->setSize)(
    this->saveButton,
    1112014848,
    1112014848);
  ksgui::Form::setPosition(
    (ksgui::Form *)this->saveButton,
    (float)((float)(this->rect.right - this->rect.left)
          - (float)(this->saveButton->rect.right - this->saveButton->rect.left))
  - 15.0,
    this->loadButton->rect.top);
  std::wstring::wstring(&v114, L"Save");
  LOBYTE(v119) = 51;
  *(_DWORD *)&v100[36] = acTranslate(&iname, &v114);
  v74 = this->saveButton;
  LOBYTE(v119) = 52;
  v74->setText(v74, *(const std::wstring **)&v100[36]);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v119) = 32;
  if ( v114._Myres >= 8 )
    operator delete(v114._Bx._Ptr);
  v75 = this->loadButton;
  v76 = this->saveButton;
  __formal._Ptr = 0;
  *(_DWORD *)&v100[36] = 344;
  v77 = v75->rect.bottom - v75->rect.top;
  v76->textCoord.x = 0.0;
  *(float *)&__formal._Rep = v77;
  v76->textCoord.y = v77;
  v78 = (Font *)operator new(*(_DWORD *)&v100[36]);
  __formal._Ptr = v78;
  LOBYTE(v119) = 53;
  if ( v78 )
  {
    *(_DWORD *)&v100[36] = this->gui;
    std::wstring::wstring((std::wstring *)&v100[12], L"SAVE_SETUP_TEXT_INPUT");
    ksgui::TextInput::TextInput((ksgui::TextInput *)v78, *(std::wstring *)&v100[12], *(ksgui::GUI **)&v100[36]);
  }
  else
  {
    v79 = 0;
  }
  *(_DWORD *)&v100[36] = 1;
  LOBYTE(v119) = 32;
  this->textInput = v79;
  ksgui::Control::setVisible(v79, *(BOOL *)&v100[36]);
  this->textInput->backColor = (vec4f)_xmm;
  this->textInput->borderColor = (vec4f)_xmm;
  this->textInput->backColorUnfocus = (vec4f)_xmm;
  this->textInput->backColorFocus = (vec4f)_xmm;
  ksgui::Control::addControl(this, this->textInput);
  ksgui::Form::setPosition((ksgui::Form *)this->textInput, 15.0, 565.0);
  ((void (*)(ksgui::TextInput *, _DWORD, int))this->textInput->setSize)(
    this->textInput,
    (float)((float)(this->rect.right - this->rect.left) - 30.0)
  - (float)(this->saveButton->rect.right - this->saveButton->rect.left),
    1103626240);
  v80 = (Font *)operator new(24);
  __formal._Ptr = v80;
  LOBYTE(v119) = 54;
  if ( v80 )
    Font::Font(v80, eFontMonospaced, 17.0, 0, 0);
  else
    v81 = 0;
  LOBYTE(v119) = 32;
  __formal._Ptr = 0;
  __formal._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&__formal, v81);
  std::shared_ptr<Font>::operator=(&this->textInput->font, &__formal);
  v82 = __formal._Rep;
  if ( __formal._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&__formal._Rep->_Uses, 0xFFFFFFFF) )
    {
      v82->_Destroy(v82);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v82->_Weaks) )
        v82->_Delete_this(v82);
    }
  }
  std::wstring::wstring(&v114, L"Save");
  LOBYTE(v119) = 55;
  *(_DWORD *)&v100[36] = acTranslate(&iname, &v114);
  v83 = this->saveButton;
  LOBYTE(v119) = 56;
  v83->setText(v83, *(const std::wstring **)&v100[36]);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v119) = 32;
  if ( v114._Myres >= 8 )
    operator delete(v114._Bx._Ptr);
  ksgui::Control::setVisible(this->saveButton, 1);
  v84 = this->saveButton;
  *(_DWORD *)&v100[36] = 368;
  v84->backColor = (vec4f)_xmm;
  v85 = (Font *)operator new(*(_DWORD *)&v100[36]);
  __formal._Ptr = v85;
  LOBYTE(v119) = 57;
  if ( v85 )
  {
    *(_DWORD *)&v100[36] = 1;
    *(_DWORD *)&v100[32] = this->gui;
    *(_DWORD *)&v100[28] = 1;
    *(_DWORD *)&v100[24] = 15;
    std::wstring::wstring((std::wstring *)v100, L"SETUP_LIST_BOX");
    ksgui::ListBox::ListBox(
      (ksgui::ListBox *)v85,
      *(std::wstring *)v100,
      *(unsigned int *)&v100[24],
      *(unsigned int *)&v100[28],
      *(ksgui::GUI **)&v100[32],
      v100[36]);
  }
  else
  {
    v86 = 0;
  }
  *(_DWORD *)&v100[36] = v86;
  LOBYTE(v119) = 32;
  this->setupListBox = v86;
  ksgui::Control::addControl(this, *(ksgui::Control **)&v100[36]);
  ksgui::Form::setPosition((ksgui::Form *)this->setupListBox, 232.0, 110.0);
  ((void (*)(ksgui::ListBox *, int, int))this->setupListBox->setSize)(
    this->setupListBox,
    1128923136,
    1133576192);
  v87 = this->setupListBox;
  *(_DWORD *)&v100[36] = L"Setup";
  v87->allowDeselection = 0;
  this->setupListBox->backColor = (vec4f)_xmm;
  this->setupListBox->borderColor = (vec4f)_xmm;
  std::wstring::wstring(&text, *(const wchar_t **)&v100[36]);
  LOBYTE(v119) = 58;
  v88 = acTranslate(&iname, &text);
  LOBYTE(v119) = 59;
  std::operator+<wchar_t>((std::wstring *)&v100[16], v88, L" : ");
  ksgui::ListBoxRowData::ListBoxRowData(&setupTitleRow, *(std::wstring *)&v100[16]);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v119) = 62;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v89 = this->setupListBox;
  text._Bx._Buf[0] = 0;
  *(_DWORD *)&v100[36] = &setupTitleRow;
  text._Myres = 7;
  v90 = v89->titleRow;
  text._Mysize = 0;
  ksgui::ListBoxRow::setRow(v90, &setupTitleRow);
  ksgui::ListBoxRow::setFontAlignment(this->setupListBox->titleRow, eAlignCenter);
  v91 = this->setupListBox;
  *(_DWORD *)&v100[36] = 0;
  v91->titleRow->drawRowBackground = 0;
  ksgui::ListBox::drawCellsBackgrounds(this->setupListBox, v100[36]);
  std::wstring::assign(&this->activeTrack, L"generic", 7u);
  std::wstring::assign(&this->activeSetup, L"Default", 7u);
  std::wstring::wstring(&result, word_17BE9D8);
  v92 = this->textInput;
  LOBYTE(v119) = 63;
  v92->setText(v92, &result);
  LOBYTE(v119) = 62;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wstring::wstring(&result, L"Default loaded");
  LOBYTE(v119) = 64;
  acTranslate(&v106, &result);
  LOBYTE(v119) = 65;
  this->statusTimer = 4.0;
  if ( &this->status != &v106 )
    std::wstring::assign(&this->status, &v106, 0, 0xFFFFFFFF);
  if ( v106._Myres >= 8 )
  {
    *(_DWORD *)&v100[36] = v106._Myres + 1;
    *(_DWORD *)&v100[32] = v106._Bx._Ptr;
    v93 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                       (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&v106,
                                       (std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > *)&v103 + 3);
    std::allocator<wchar_t>::deallocate(v93, *(wchar_t **)&v100[32], *(unsigned int *)&v100[36]);
  }
  v106._Myres = 7;
  std::wstring::_Eos(&v106, 0);
  LOBYTE(v119) = 62;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
  *(_DWORD *)&v100[36] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&__formal,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v100[12],
    v94);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->loadButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v100[12],
    *(void **)&v100[36]);
  *(_DWORD *)&v100[36] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&__formal,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v100[12],
    v95);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->saveButton->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v100[12],
    *(void **)&v100[36]);
  *(_DWORD *)&v100[36] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&__formal,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v100[12],
    v96);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->textInput->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v100[12],
    *(void **)&v100[36]);
  *(_DWORD *)&v100[36] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&__formal,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (std::wstring const &)>::function<void __cdecl (std::wstring const &)>(
    (std::function<void __cdecl(std::wstring const &)> *)&v100[12],
    v97);
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->textInput->evValidate,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v100[12],
    *(void **)&v100[36]);
  *(_DWORD *)&v100[36] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&__formal,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnListBoxItemClickedEvent const &)>::function<void __cdecl (ksgui::OnListBoxItemClickedEvent const &)>(
    (std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v100[12],
    v98);
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(
    &this->setupListBox->evOnListBoxItemClicked,
    *(std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v100[12],
    *(void **)&v100[36]);
  *(_DWORD *)&v100[36] = this;
  CommandItem::CommandItem(
    (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&__formal,
    (CarAudioFMOD *)this);
  std::function<void __cdecl (ksgui::OnListBoxItemClickedEvent const &)>::function<void __cdecl (ksgui::OnListBoxItemClickedEvent const &)>(
    (std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v100[12],
    v99);
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(
    &this->trackListBox->evOnListBoxItemClicked,
    *(std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> *)&v100[12],
    *(void **)&v100[36]);
  ksgui::Control::addControl(this, this->saveButton);
  ksgui::ListBoxRowData::~ListBoxRowData(&setupTitleRow);
  ksgui::ListBoxRowData::~ListBoxRowData(&titleRow);
  std::vector<std::wstring>::_Tidy(&tracks);
}
void SetupIOManager::~SetupIOManager(SetupIOManager *this)
{
  this->__vftable = (SetupIOManager_vtbl *)&SetupIOManager::`vftable';
  if ( this->status._Myres >= 8 )
    operator delete(this->status._Bx._Ptr);
  this->status._Myres = 7;
  this->status._Mysize = 0;
  this->status._Bx._Buf[0] = 0;
  if ( this->activeTrack._Myres >= 8 )
    operator delete(this->activeTrack._Bx._Ptr);
  this->activeTrack._Myres = 7;
  this->activeTrack._Mysize = 0;
  this->activeTrack._Bx._Buf[0] = 0;
  if ( this->activeSetup._Myres >= 8 )
    operator delete(this->activeSetup._Bx._Ptr);
  this->activeSetup._Myres = 7;
  this->activeSetup._Mysize = 0;
  this->activeSetup._Bx._Buf[0] = 0;
  SetupTab::~SetupTab(this);
}
SetupIOManager *SetupIOManager::`scalar deleting destructor'(SetupIOManager *this, unsigned int a2)
{
  SetupIOManager::~SetupIOManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
std::wstring *SetupIOManager::getPathFromSetupName(SetupIOManager *this, std::wstring *result, const std::wstring *setupName, bool strategy)
{
  CarAvatar *v5; // eax
  const std::wstring *v6; // eax
  ksgui::ListBoxRowData *v7; // eax
  const std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  unsigned int v12; // [esp-Ch] [ebp-78h]
  std::wstring path; // [esp+14h] [ebp-58h] BYREF
  std::wstring v14; // [esp+2Ch] [ebp-40h] BYREF
  std::wstring v15; // [esp+44h] [ebp-28h] BYREF
  int v16; // [esp+68h] [ebp-4h]

  path._Myres = 7;
  path._Mysize = 0;
  path._Bx._Buf[0] = 0;
  std::wstring::assign(&path, word_17BE9D8, 0);
  v12 = setupName->_Mysize;
  v16 = 0;
  if ( std::wstring::compare((std::wstring *)setupName, 0, v12, word_17BE9D8, 0)
    && ksgui::ListBox::getSelectedItem(this->trackListBox) )
  {
    std::wstring::assign(&path, L"setups\\", 7u);
    v5 = Sim::getCar(this->sim, 0);
    v6 = std::operator+<wchar_t>(&v14, &v5->unixName, L"\\");
    LOBYTE(v16) = 1;
    std::wstring::append(&path, v6, 0, 0xFFFFFFFF);
    LOBYTE(v16) = 0;
    if ( v14._Myres >= 8 )
      operator delete(v14._Bx._Ptr);
    v7 = ksgui::ListBox::getSelectedItem(this->trackListBox);
    v8 = std::operator+<wchar_t>(&v14, &v7->name, L"\\");
    LOBYTE(v16) = 2;
    std::wstring::append(&path, v8, 0, 0xFFFFFFFF);
    LOBYTE(v16) = 0;
    if ( v14._Myres >= 8 )
      operator delete(v14._Bx._Ptr);
    std::wstring::append(&path, setupName, 0, 0xFFFFFFFF);
    if ( strategy )
      std::wstring::append(&path, L"_PS", 3u);
    std::wstring::append(&path, L".ini", 4u);
  }
  v9 = Path::getDocumentPath(&v14);
  LOBYTE(v16) = 3;
  v10 = std::operator+<wchar_t>(&v15, v9, L"\\Assetto Corsa\\");
  LOBYTE(v16) = 4;
  std::operator+<wchar_t>(result, v10, &path);
  if ( v15._Myres >= 8 )
    operator delete(v15._Bx._Ptr);
  v15._Myres = 7;
  v15._Mysize = 0;
  v15._Bx._Buf[0] = 0;
  if ( v14._Myres >= 8 )
    operator delete(v14._Bx._Ptr);
  v14._Myres = 7;
  v14._Mysize = 0;
  v14._Bx._Buf[0] = 0;
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  return result;
}
void SetupIOManager::onVisibleChanged(SetupIOManager *this, bool newValue)
{
  if ( newValue )
  {
    SetupIOManager::refreshStatus(this);
    SetupIOManager::resetUI(this);
  }
}
void SetupIOManager::refreshSetupListBox(SetupIOManager *this)
{
  std::wstring *v2; // eax
  std::wstring *v3; // esi
  Sim *v4; // ecx
  CarAvatar *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // esi
  ksgui::ListBox *v8; // ecx
  ksgui::ListBoxRowData *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // edi
  unsigned int v12; // esi
  int v13; // ebx
  int v14; // eax
  ksgui::ListBox *v15; // ecx
  std::wstring v16; // [esp-18h] [ebp-154h] BYREF
  std::vector<std::wstring> files; // [esp+14h] [ebp-128h] BYREF
  char v18; // [esp+23h] [ebp-119h] BYREF
  unsigned int v19; // [esp+24h] [ebp-118h]
  std::wstring file; // [esp+28h] [ebp-114h] BYREF
  std::wstring filename; // [esp+40h] [ebp-FCh] BYREF
  std::wstring v22; // [esp+58h] [ebp-E4h] BYREF
  std::wstring v23; // [esp+70h] [ebp-CCh] BYREF
  std::wstring result; // [esp+88h] [ebp-B4h] BYREF
  std::wstring v25; // [esp+A0h] [ebp-9Ch] BYREF
  std::wstring v26; // [esp+B8h] [ebp-84h] BYREF
  std::wstring setupFilesPath; // [esp+D0h] [ebp-6Ch] BYREF
  ksgui::ListBoxRowData row; // [esp+E8h] [ebp-54h] BYREF
  int v29; // [esp+138h] [ebp-4h]

  ksgui::ListBox::clear(this->setupListBox);
  if ( ksgui::ListBox::getSelectedItem(this->trackListBox) )
  {
    v2 = Path::getDocumentPath(&result);
    v29 = 0;
    v3 = std::operator+<wchar_t>(&v23, v2, L"\\Assetto Corsa\\setups\\");
    v4 = this->sim;
    LOBYTE(v29) = 1;
    v5 = Sim::getCar(v4, 0);
    v6 = std::operator+<wchar_t>(&v25, v3, &v5->unixName);
    LOBYTE(v29) = 2;
    v7 = std::operator+<wchar_t>(&v26, v6, L"\\");
    v8 = this->trackListBox;
    LOBYTE(v29) = 3;
    v9 = ksgui::ListBox::getSelectedItem(v8);
    v10 = std::operator+<wchar_t>(&v22, v7, &v9->name);
    LOBYTE(v29) = 4;
    std::operator+<wchar_t>(&setupFilesPath, v10, L"\\*.ini");
    if ( v22._Myres >= 8 )
      operator delete(v22._Bx._Ptr);
    v22._Myres = 7;
    v22._Mysize = 0;
    v22._Bx._Buf[0] = 0;
    if ( v26._Myres >= 8 )
      operator delete(v26._Bx._Ptr);
    v26._Myres = 7;
    v26._Mysize = 0;
    v26._Bx._Buf[0] = 0;
    if ( v25._Myres >= 8 )
      operator delete(v25._Bx._Ptr);
    v25._Myres = 7;
    v25._Mysize = 0;
    v25._Bx._Buf[0] = 0;
    if ( v23._Myres >= 8 )
      operator delete(v23._Bx._Ptr);
    v23._Myres = 7;
    v23._Mysize = 0;
    v23._Bx._Buf[0] = 0;
    LOBYTE(v29) = 10;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    Path::getFiles(&files, &setupFilesPath);
    v11 = files._Myfirst;
    v12 = 0;
    LOBYTE(v29) = 11;
    if ( files._Mylast - files._Myfirst )
    {
      v13 = 0;
      do
      {
        file._Myres = 7;
        file._Bx._Buf[0] = 0;
        file._Mysize = 0;
        std::wstring::assign(&file, &v11[v13], 0, 0xFFFFFFFF);
        LOBYTE(v29) = 12;
        v14 = std::wstring::find_last_of(&file, L".", 0xFFFFFFFF, 1u);
        std::wstring::substr(&file, &filename, 0, v14);
        LOBYTE(v29) = 13;
        v16._Myres = 7;
        v16._Mysize = 0;
        v16._Bx._Buf[0] = 0;
        std::wstring::assign(&v16, &filename, 0, 0xFFFFFFFF);
        ksgui::ListBoxRowData::ListBoxRowData(&row, v16);
        v15 = this->setupListBox;
        LOBYTE(v29) = 14;
        ksgui::ListBox::addItem(v15, &row);
        ksgui::ListBoxRowData::~ListBoxRowData(&row);
        if ( filename._Myres >= 8 )
          operator delete(filename._Bx._Ptr);
        filename._Myres = 7;
        filename._Mysize = 0;
        filename._Bx._Buf[0] = 0;
        LOBYTE(v29) = 11;
        if ( file._Myres >= 8 )
          operator delete(file._Bx._Ptr);
        v11 = files._Myfirst;
        ++v12;
        ++v13;
      }
      while ( v12 < files._Mylast - files._Myfirst );
    }
    ksgui::ListBox::scrollToTop(this->setupListBox);
    LOBYTE(v29) = 10;
    if ( files._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&files);
      v16._Myres = v19;
      v16._Mysize = (unsigned int)&v18;
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(files._Myfirst, files._Mylast);
      operator delete(files._Myfirst);
      files._Myfirst = 0;
      files._Mylast = 0;
      files._Myend = 0;
    }
    if ( setupFilesPath._Myres >= 8 )
      operator delete(setupFilesPath._Bx._Ptr);
  }
}
void SetupIOManager::refreshStatus(SetupIOManager *this)
{
  std::wstring *v2; // edi
  std::wstring *v3; // ecx
  std::wstring *v4; // esi
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // esi
  std::wstring *v8; // esi
  bool v9; // cf
  std::wstring v10; // [esp-1Ch] [ebp-D4h] BYREF
  unsigned int v11; // [esp-4h] [ebp-BCh]
  char v12; // [esp+13h] [ebp-A5h]
  std::wstring _Right; // [esp+14h] [ebp-A4h] BYREF
  std::wstring v14; // [esp+30h] [ebp-88h] BYREF
  std::wstring result; // [esp+48h] [ebp-70h] BYREF
  std::wstring text; // [esp+60h] [ebp-58h] BYREF
  std::wstring v17; // [esp+78h] [ebp-40h] BYREF
  std::wstring v18; // [esp+90h] [ebp-28h] BYREF
  int v19; // [esp+B4h] [ebp-4h]

  v2 = &this->activeSetup;
  if ( this->activeSetup._Myres < 8 )
    v3 = &this->activeSetup;
  else
    v3 = (std::wstring *)v2->_Bx._Ptr;
  v12 = v3->_Bx._Alias[2 * v2->_Mysize - 2];
  if ( SetupScreen::needToSave(this->sim->escMenu->setupScreen) )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Need to save current setup", 0x1Au);
    v11 = 23;
    v19 = 0;
    v10._Myres = 7;
    v10._Mysize = 0;
    v10._Bx._Buf[0] = 0;
    std::wstring::assign(&v10, v2, 0, 0xFFFFFFFF);
    v4 = cutStringIfExceeds(&result, v10, v11);
    LOBYTE(v19) = 1;
    v5 = acTranslate(&v18, &text);
    LOBYTE(v19) = 2;
    v6 = std::operator+<wchar_t>(&v17, v5, L" : ");
    LOBYTE(v19) = 3;
    std::operator+<wchar_t>(&_Right, v6, v4);
    LOBYTE(v19) = 4;
    this->statusTimer = 4.0;
    if ( &this->status != &_Right )
      std::wstring::assign(&this->status, &_Right, 0, 0xFFFFFFFF);
    if ( _Right._Myres >= 8 )
      operator delete(_Right._Bx._Ptr);
    _Right._Myres = 7;
    _Right._Mysize = 0;
    _Right._Bx._Buf[0] = 0;
    if ( v17._Myres >= 8 )
      operator delete(v17._Bx._Ptr);
    v17._Myres = 7;
    v17._Mysize = 0;
    v17._Bx._Buf[0] = 0;
    if ( v18._Myres >= 8 )
      operator delete(v18._Bx._Ptr);
    v18._Myres = 7;
    v18._Mysize = 0;
    v18._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    v19 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    if ( v12 != 42 )
    {
      v7 = std::operator+<wchar_t>(&result, v2, L"*");
      if ( v2 != v7 )
      {
        if ( v2->_Myres >= 8 )
          operator delete(v2->_Bx._Ptr);
        v2->_Myres = 7;
        v2->_Mysize = 0;
        v11 = (unsigned int)v7;
        v2->_Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(v2, (std::wstring *)v11);
      }
      if ( result._Myres >= 8 )
      {
        v11 = (unsigned int)result._Bx._Ptr;
LABEL_33:
        operator delete(v11);
        return;
      }
    }
  }
  else
  {
    if ( v12 == 42 )
    {
      v8 = std::wstring::substr(v2, &result, 0, this->activeSetup._Mysize - 1);
      if ( v2 != v8 )
      {
        if ( v2->_Myres >= 8 )
          operator delete(v2->_Bx._Ptr);
        v2->_Myres = 7;
        v2->_Mysize = 0;
        v11 = (unsigned int)v8;
        v2->_Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(v2, (std::wstring *)v11);
      }
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    v14._Myres = 7;
    v14._Mysize = 0;
    v14._Bx._Buf[0] = 0;
    std::wstring::assign(&v14, word_17BE9D8, 0);
    v9 = v14._Myres < 8;
    this->statusTimer = -1.0;
    if ( !v9 )
    {
      v11 = (unsigned int)v14._Bx._Ptr;
      goto LABEL_33;
    }
  }
}
void __userpurge SetupIOManager::render(SetupIOManager *this@<ecx>, __int64 a2@<esi:edi>, float dt)
{
  int v3; // eax
  int v4; // edx
  int v5; // ebx
  volatile signed __int32 *v6; // edi
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  float v13; // ecx
  Font *v14; // ecx
  int v15; // eax
  std::wstring *v16; // eax
  const std::wstring *v17; // eax
  float v18; // ecx
  Font *v19; // ecx
  std::wstring *v20; // eax
  const std::wstring *v21; // eax
  Font *v22; // ecx
  float v23; // ecx
  std::wstring v24; // [esp+0h] [ebp-B8h] BYREF
  float g; // [esp+18h] [ebp-A0h]
  float b; // [esp+1Ch] [ebp-9Ch]
  float a; // [esp+20h] [ebp-98h]
  ksgui::ksRect wrect; // [esp+34h] [ebp-84h] BYREF
  std::wstring result; // [esp+48h] [ebp-70h] BYREF
  std::wstring v30; // [esp+60h] [ebp-58h] BYREF
  std::wstring text; // [esp+78h] [ebp-40h] BYREF
  std::wstring currentSetupText; // [esp+90h] [ebp-28h] BYREF
  int v33; // [esp+B4h] [ebp-4h]

  HIDWORD(a2) = this;
  SetupTab::render(this, a2, dt);
  v3 = *(_DWORD *)(HIDWORD(a2) + 240);
  v4 = *(_DWORD *)(v3 + 16);
  v5 = *(_DWORD *)(v3 + 12);
  if ( v4 )
    _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 4), 1u);
  LODWORD(a2) = *(_DWORD *)(HIDWORD(a2) + 132);
  *(_DWORD *)(HIDWORD(a2) + 132) = v4;
  *(_DWORD *)(HIDWORD(a2) + 128) = v5;
  if ( (_DWORD)a2 )
  {
    if ( !_InterlockedExchangeAdd(v6 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v6)(v6);
      if ( !_InterlockedDecrement(v6 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v6 + 4))(v6);
    }
  }
  v7 = *(_DWORD **)(HIDWORD(a2) + 128);
  a = 1.0;
  b = 1.0;
  *v7 = 1097859072;
  Font::setColor(*(Font **)(HIDWORD(a2) + 128), 1.0, 1.0, b, a);
  v8 = *(_DWORD *)(HIDWORD(a2) + 320);
  wrect = (ksgui::ksRect)_mm_loadu_si128((const __m128i *)(v8 + 28));
  (*(void (**)(int, ksgui::ksRect *))(*(_DWORD *)v8 + 24))(v8, &wrect);
  v9 = *(_DWORD *)(HIDWORD(a2) + 324);
  wrect = (ksgui::ksRect)_mm_loadu_si128((const __m128i *)(v9 + 28));
  (*(void (**)(int, ksgui::ksRect *))(*(_DWORD *)v9 + 24))(v9, &wrect);
  v10 = *(_DWORD *)(HIDWORD(a2) + 348);
  wrect = (ksgui::ksRect)_mm_loadu_si128((const __m128i *)(v10 + 28));
  (*(void (**)(int, ksgui::ksRect *))(*(_DWORD *)v10 + 24))(v10, &wrect);
  if ( ksgui::ListBox::getSelectedItem(*(ksgui::ListBox **)(HIDWORD(a2) + 320)) )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Save current setup as", 0x15u);
    v33 = 0;
    v11 = acTranslate(&result, &text);
    LOBYTE(v33) = 1;
    v12 = std::operator+<wchar_t>(&v30, v11, L" : ");
    a = 0.0;
    b = v13;
    v14 = *(Font **)(HIDWORD(a2) + 128);
    LOBYTE(v33) = 2;
    Font::blitString(v14, wrect.left, wrect.top - 23.0, v12, 1.0, eAlignLeft);
    if ( v30._Myres >= 8 )
      operator delete(v30._Bx._Ptr);
    v30._Myres = 7;
    v30._Mysize = 0;
    v30._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    v33 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  v15 = *(_DWORD *)HIDWORD(a2);
  wrect = (ksgui::ksRect)_mm_loadu_si128((const __m128i *)(HIDWORD(a2) + 28));
  (*(void (**)(_DWORD, ksgui::ksRect *))(v15 + 24))(HIDWORD(a2), &wrect);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Current Setup", 0xDu);
  v33 = 3;
  v16 = acTranslate(&v30, &text);
  LOBYTE(v33) = 4;
  v17 = std::operator+<wchar_t>(&result, v16, L" : ");
  LODWORD(a) = 2;
  b = v18;
  v19 = *(Font **)(HIDWORD(a2) + 128);
  LOBYTE(v33) = 5;
  Font::blitString(
    v19,
    (float)((float)(wrect.right - wrect.left) * 0.5) + wrect.left,
    wrect.top + 35.0,
    v17,
    1.0,
    eAlignCenter);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( v30._Myres >= 8 )
    operator delete(v30._Bx._Ptr);
  v30._Myres = 7;
  v30._Mysize = 0;
  v30._Bx._Buf[0] = 0;
  v33 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v20 = std::operator+<wchar_t>(&result, (const std::wstring *)(HIDWORD(a2) + 376), L" - ");
  v33 = 6;
  std::operator+<wchar_t>(&currentSetupText, v20, (const std::wstring *)(HIDWORD(a2) + 352));
  LOBYTE(v33) = 8;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LODWORD(a) = 2;
  b = 1.0;
  LODWORD(g) = 35;
  result._Bx._Buf[0] = 0;
  result._Myres = 7;
  result._Mysize = 0;
  v24._Mysize = 0;
  v24._Myres = 7;
  v24._Bx._Buf[0] = 0;
  std::wstring::assign(&v24, &currentSetupText, 0, 0xFFFFFFFF);
  v21 = cutStringIfExceeds(&v30, v24, LODWORD(g));
  v22 = *(Font **)(HIDWORD(a2) + 128);
  LOBYTE(v33) = 9;
  Font::blitString(
    v22,
    (float)((float)(wrect.right - wrect.left) * 0.5) + wrect.left,
    wrect.top + 60.0,
    v21,
    b,
    SLODWORD(a));
  LOBYTE(v33) = 8;
  if ( v30._Myres >= 8 )
    operator delete(v30._Bx._Ptr);
  if ( *(float *)(HIDWORD(a2) + 424) > 0.0 )
  {
    Font::setColor(*(Font **)(HIDWORD(a2) + 128), 1.0, 1.0, 0.0, 1.0);
    LODWORD(a) = 2;
    b = v23;
    Font::blitString(
      *(Font **)(HIDWORD(a2) + 128),
      (float)((float)(wrect.right - wrect.left) * 0.5) + wrect.left,
      wrect.bottom - 90.0,
      (const std::wstring *)(HIDWORD(a2) + 400),
      1.0,
      eAlignCenter);
    *(float *)(HIDWORD(a2) + 424) = *(float *)(HIDWORD(a2) + 424) - dt;
  }
  if ( currentSetupText._Myres >= 8 )
    operator delete(currentSetupText._Bx._Ptr);
}
void SetupIOManager::resetUI(SetupIOManager *this)
{
  bool v2; // cf
  std::wstring *v3; // eax
  ksgui::ActiveButton *v4; // ecx
  ksgui::ActiveButton *v5; // eax
  std::wstring v6; // [esp+8h] [ebp-58h] BYREF
  std::wstring text; // [esp+20h] [ebp-40h] BYREF
  std::wstring result; // [esp+38h] [ebp-28h] BYREF
  int v9; // [esp+5Ch] [ebp-4h]

  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, word_17BE9D8, 0);
  v2 = v6._Myres < 8;
  this->statusTimer = -1.0;
  v9 = -1;
  if ( !v2 )
    operator delete(v6._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Save", 4u);
  v9 = 1;
  v3 = acTranslate(&result, &text);
  v4 = this->saveButton;
  LOBYTE(v9) = 2;
  v4->setText(v4, v3);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v9 = -1;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->overrideSetup = 0;
  text._Bx._Buf[0] = 0;
  v5 = this->saveButton;
  text._Myres = 7;
  text._Mysize = 0;
  v5->backColor = (vec4f)_xmm;
  ksgui::Control::setVisible(this->confirmButton, 0);
}
void __usercall SetupIOManager::sendSaveMessage(SetupIOManager *this@<ecx>, unsigned int a2@<ebx>)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  const std::wstring *v5; // eax
  const std::wstring *v6; // eax
  ksgui::TextInput *v7; // ecx
  const std::wstring *v8; // eax
  ksgui::ListBox *v9; // ecx
  const std::wstring *v10; // eax
  ksgui::ListBoxRowData *v11; // eax
  ksgui::ListBox *v12; // ecx
  ksgui::ListBoxRowData *v13; // eax
  std::wstring *v14; // esi
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  ksgui::ListBoxRowData *v17; // eax
  ksgui::TextInput *v18; // ecx
  _BYTE v19[28]; // [esp-1Ch] [ebp-12Ch] BYREF
  std::wstring _Right; // [esp+10h] [ebp-100h] BYREF
  std::wstring v21; // [esp+28h] [ebp-E8h] BYREF
  std::wstring v22; // [esp+40h] [ebp-D0h] BYREF
  std::wstring result; // [esp+58h] [ebp-B8h] BYREF
  std::wstring text; // [esp+70h] [ebp-A0h] BYREF
  std::wstring path; // [esp+88h] [ebp-88h] BYREF
  std::wstring setupName; // [esp+A0h] [ebp-70h] BYREF
  std::wstring v27; // [esp+B8h] [ebp-58h] BYREF
  std::wstring v28; // [esp+D0h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v29; // [esp+E8h] [ebp-28h] BYREF
  int v30; // [esp+10Ch] [ebp-4h]

  v3 = (std::wstring *)this->textInput->getText(this->textInput);
  if ( std::wstring::compare(v3, 0, v3->_Mysize, word_17BE9D8, 0) )
  {
    v4 = this->textInput->getText(this->textInput);
    if ( ksgui::ListBox::getItemIdFromName(this->setupListBox, v4) >= 0
      && (v5 = this->textInput->getText(this->textInput),
          this->setupListBox->items._Myfirst[ksgui::ListBox::getItemIdFromName(this->setupListBox, v5)].category == 2) )
    {
      std::wstring::wstring(&text, L"You can't overwrite default setup");
      v30 = 2;
      acTranslate(&_Right, &text);
      LOBYTE(v30) = 3;
      this->statusTimer = 4.0;
      if ( &this->status != &_Right )
        std::wstring::assign(&this->status, &_Right, 0, 0xFFFFFFFF);
      if ( _Right._Myres >= 8 )
        operator delete(_Right._Bx._Ptr);
      _Right._Myres = 7;
      _Right._Mysize = 0;
      _Right._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
      {
        *(_DWORD *)&v19[24] = text._Bx._Ptr;
        goto LABEL_46;
      }
    }
    else
    {
      v6 = this->textInput->getText(this->textInput);
      setupName._Myres = 7;
      setupName._Bx._Buf[0] = 0;
      setupName._Mysize = 0;
      std::wstring::assign(&setupName, v6, 0, 0xFFFFFFFF);
      v30 = 4;
      if ( Path::doesFilenameContainsIllegalChar(&setupName) )
      {
        _printf("ERROR: SetupIOManager::sendSaveMessage ILLEGAL CHAR IN setup name\n");
        std::wstring::wstring(&text, L"The name contains illegal characters");
        LOBYTE(v30) = 5;
        acTranslate(&v21, &text);
        LOBYTE(v30) = 6;
        this->statusTimer = 4.0;
        if ( &this->status != &v21 )
          std::wstring::assign(&this->status, &v21, 0, 0xFFFFFFFF);
        if ( v21._Myres >= 8 )
          operator delete(v21._Bx._Ptr);
        v21._Myres = 7;
        v21._Mysize = 0;
        v21._Bx._Buf[0] = 0;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
      }
      else
      {
        v7 = this->textInput;
        *(_DWORD *)&v19[24] = 0;
        v8 = v7->getText(v7);
        SetupIOManager::getPathFromSetupName(this, &path, v8, 0);
        v9 = this->trackListBox;
        LOBYTE(v30) = 7;
        if ( ksgui::ListBox::getSelectedItem(v9) )
        {
          if ( !Path::fileExists(a2, &path, 0) || this->overrideSetup )
          {
            SetupScreen::saveSetupAbsolutePath(this->sim->escMenu->setupScreen, &path);
            SetupIOManager::refreshSetupListBox(this);
            v10 = this->textInput->getText(this->textInput);
            ksgui::ListBox::selectItemByName(this->setupListBox, v10);
            SetupIOManager::resetUI(this);
            if ( ksgui::ListBox::getSelectedItem(this->setupListBox) )
            {
              v11 = ksgui::ListBox::getSelectedItem(this->setupListBox);
              if ( &this->activeSetup != (std::wstring *)v11 )
                std::wstring::assign(&this->activeSetup, &v11->name, 0, 0xFFFFFFFF);
              std::wstring::wstring(&text, L"Saved");
              v12 = this->setupListBox;
              *(_DWORD *)&v19[24] = 23;
              LOBYTE(v30) = 10;
              v13 = ksgui::ListBox::getSelectedItem(v12);
              std::wstring::wstring((std::wstring *)v19, &v13->name);
              v14 = cutStringIfExceeds(&v29.name, *(std::wstring *)v19, *(unsigned int *)&v19[24]);
              LOBYTE(v30) = 11;
              v15 = acTranslate(&v28, &text);
              LOBYTE(v30) = 12;
              v16 = std::operator+<wchar_t>(&v27, v15, L" : ");
              LOBYTE(v30) = 13;
              std::operator+<wchar_t>((std::wstring *)&v19[4], v16, v14);
              SetupIOManager::showStatus(this, 1, *(std::wstring *)&v19[4]);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v27);
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v28);
              std::wstring::~wstring(&v29);
              LOBYTE(v30) = 7;
              std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
            }
            if ( ksgui::ListBox::getSelectedItem(this->trackListBox) )
            {
              v17 = ksgui::ListBox::getSelectedItem(this->trackListBox);
              if ( &this->activeTrack != (std::wstring *)v17 )
                std::wstring::assign(&this->activeTrack, &v17->name, 0, 0xFFFFFFFF);
            }
            std::wstring::wstring(&text, word_17BE9D8);
            v18 = this->textInput;
            LOBYTE(v30) = 14;
            v18->setText(v18, &text);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          }
          else
          {
            SetupIOManager::setOverrideStatus(this, 1);
          }
        }
        else
        {
          std::wstring::wstring(&text, L"You must specify a Track first");
          LOBYTE(v30) = 8;
          acTranslate(&v22, &text);
          LOBYTE(v30) = 9;
          this->statusTimer = 4.0;
          if ( &this->status != &v22 )
            std::wstring::assign(&this->status, &v22, 0, 0xFFFFFFFF);
          if ( v22._Myres >= 8 )
            operator delete(v22._Bx._Ptr);
          v22._Myres = 7;
          v22._Mysize = 0;
          v22._Bx._Buf[0] = 0;
          if ( text._Myres >= 8 )
            operator delete(text._Bx._Ptr);
        }
        if ( path._Myres >= 8 )
          operator delete(path._Bx._Ptr);
        path._Myres = 7;
        path._Mysize = 0;
        path._Bx._Buf[0] = 0;
      }
      if ( setupName._Myres >= 8 )
      {
        *(_DWORD *)&v19[24] = setupName._Bx._Ptr;
        goto LABEL_46;
      }
    }
  }
  else
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"You must specify a name", 0x17u);
    v30 = 0;
    acTranslate(&result, &text);
    LOBYTE(v30) = 1;
    this->statusTimer = 4.0;
    if ( &this->status != &result )
      std::wstring::assign(&this->status, &result, 0, 0xFFFFFFFF);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
    {
      *(_DWORD *)&v19[24] = text._Bx._Ptr;
LABEL_46:
      operator delete(*(_DWORD *)&v19[24]);
      return;
    }
  }
}
void SetupIOManager::setOverrideStatus(SetupIOManager *this, bool overrideStatus)
{
  std::wstring *v3; // eax
  ksgui::ActiveButton *v4; // ecx
  ksgui::ActiveButton *v5; // eax
  std::wstring result; // [esp+8h] [ebp-70h] BYREF
  std::wstring text; // [esp+20h] [ebp-58h] BYREF
  std::wstring v8; // [esp+38h] [ebp-40h] BYREF
  std::wstring v9; // [esp+50h] [ebp-28h] BYREF
  int v10; // [esp+74h] [ebp-4h]

  SetupIOManager::resetUI(this);
  if ( overrideStatus )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Are you sure to override the setup ?", 0x24u);
    v10 = 0;
    acTranslate(&result, &text);
    LOBYTE(v10) = 1;
    this->statusTimer = 4.0;
    if ( &this->status != &result )
      std::wstring::assign(&this->status, &result, 0, 0xFFFFFFFF);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    v10 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v8._Myres = 7;
    v8._Mysize = 0;
    v8._Bx._Buf[0] = 0;
    std::wstring::assign(&v8, L"Override", 8u);
    v10 = 2;
    v3 = acTranslate(&v9, &v8);
    v4 = this->saveButton;
    LOBYTE(v10) = 3;
    v4->setText(v4, v3);
    if ( v9._Myres >= 8 )
      operator delete(v9._Bx._Ptr);
    v9._Myres = 7;
    v9._Mysize = 0;
    v9._Bx._Buf[0] = 0;
    if ( v8._Myres >= 8 )
      operator delete(v8._Bx._Ptr);
    v5 = this->saveButton;
    this->overrideSetup = 1;
    v5->backColor = (vec4f)_xmm;
  }
}
void SetupIOManager::setRemoveStatus(SetupIOManager *this, bool removeStatus)
{
  ksgui::Control *v3; // ecx
  std::wstring result; // [esp+8h] [ebp-40h] BYREF
  std::wstring text; // [esp+20h] [ebp-28h] BYREF
  int v6; // [esp+44h] [ebp-4h]

  SetupIOManager::resetUI(this);
  if ( removeStatus )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Are you sure to delete the setup ?", 0x22u);
    v6 = 0;
    acTranslate(&result, &text);
    LOBYTE(v6) = 1;
    this->statusTimer = 4.0;
    if ( &this->status != &result )
      std::wstring::assign(&this->status, &result, 0, 0xFFFFFFFF);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    v6 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    v3 = this->confirmButton;
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    ksgui::Control::setVisible(v3, 1);
  }
}
void SetupIOManager::setSelectedTrack(SetupIOManager *this, const std::wstring *track)
{
  ksgui::ListBox::selectItemByName(this->trackListBox, track);
}
void SetupIOManager::showStatus(SetupIOManager *this, bool show, std::wstring text)
{
  std::wstring *v3; // ecx

  if ( show )
  {
    this->statusTimer = 4.0;
    v3 = &this->status;
    if ( v3 != &text )
      std::wstring::assign(v3, &text, 0, 0xFFFFFFFF);
  }
  else
  {
    this->statusTimer = -1.0;
  }
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
}
