#include "commandmanager.h
void __usercall CommandManager::CommandManager(CommandManager *this@<ecx>, unsigned int a2@<ebx>)
{
  std::_Tree_node<std::pair<std::wstring const ,CommandItem>,void *> *v3; // eax
  bool v4; // bl
  int v5; // esi
  bool v6; // bl
  int v7; // esi
  bool v8; // bl
  int v9; // esi
  bool v10; // bl
  int v11; // esi
  bool v12; // bl
  int v13; // esi
  bool v14; // bl
  int v15; // esi
  bool v16; // bl
  int v17; // esi
  bool v18; // bl
  int v19; // esi
  bool v20; // bl
  int v21; // esi
  bool v22; // bl
  int v23; // esi
  bool v24; // bl
  int v25; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v26; // ecx
  CommandItem *v27; // eax
  bool v28; // bl
  int v29; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v30; // ecx
  CommandItem *v31; // eax
  bool v32; // bl
  int v33; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v34; // ecx
  CommandItem *v35; // eax
  bool v36; // bl
  int v37; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v38; // ecx
  CommandItem *v39; // eax
  bool v40; // bl
  int v41; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v42; // ecx
  CommandItem *v43; // eax
  bool v44; // bl
  int v45; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v46; // ecx
  CommandItem *v47; // eax
  bool v48; // bl
  int v49; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v50; // ecx
  CommandItem *v51; // eax
  bool v52; // bl
  int v53; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v54; // ecx
  CommandItem *v55; // eax
  bool v56; // bl
  int v57; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v58; // ecx
  CommandItem *v59; // eax
  bool v60; // bl
  int v61; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v62; // ecx
  CommandItem *v63; // eax
  bool v64; // bl
  int v65; // esi
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v66; // ecx
  CommandItem *v67; // eax
  CommandItem *v68; // eax
  CommandItem *v69; // eax
  CommandItem *v70; // eax
  CommandItem *v71; // eax
  int *v72; // eax
  int *v73; // esi
  CommandItem *v74; // eax
  bool v75; // al
  bool v76; // bl
  CarAudioFMOD *v77; // eax
  int *v78; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v79; // ecx
  int *v80; // eax
  int *v81; // eax
  int *v82; // esi
  CommandItem *v83; // eax
  int *v84; // eax
  int *v85; // esi
  CommandItem *v86; // eax
  int *v87; // eax
  int *v88; // esi
  CommandItem *v89; // eax
  int *v90; // eax
  int *v91; // esi
  CommandItem *v92; // eax
  int *v93; // eax
  int *v94; // esi
  CommandItem *v95; // eax
  int *v96; // eax
  int *v97; // esi
  CommandItem *v98; // eax
  int *v99; // eax
  int *v100; // esi
  CommandItem *v101; // eax
  int *v102; // eax
  int *v103; // esi
  CommandItem *v104; // eax
  int *v105; // eax
  int *v106; // esi
  CommandItem *v107; // eax
  int *v108; // eax
  int *v109; // esi
  CommandItem *v110; // eax
  int *v111; // eax
  int *v112; // esi
  CommandItem *v113; // eax
  int *v114; // eax
  int *v115; // esi
  CommandItem *v116; // eax
  int *v117; // eax
  int *v118; // eax
  int *v119; // esi
  CommandItem *v120; // eax
  int *v121; // eax
  int *v122; // esi
  CommandItem *v123; // eax
  int *v124; // eax
  int *v125; // esi
  CommandItem *v126; // eax
  int *v127; // eax
  int *v128; // esi
  CommandItem *v129; // eax
  int *v130; // eax
  int *v131; // esi
  CommandItem *v132; // eax
  int *v133; // eax
  int *v134; // esi
  CommandItem *v135; // eax
  int *v136; // eax
  int *v137; // esi
  CommandItem *v138; // eax
  int *v139; // eax
  int *v140; // esi
  CommandItem *v141; // eax
  int *v142; // eax
  int *v143; // esi
  CommandItem *v144; // eax
  int *v145; // eax
  int *v146; // esi
  CommandItem *v147; // eax
  int *v148; // eax
  std::wstring v149; // [esp-1Ch] [ebp-2C8h] BYREF
  BOOL v150; // [esp-4h] [ebp-2B0h]
  CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> v151; // [esp+10h] [ebp-29Ch] BYREF
  CommandManager *v152; // [esp+14h] [ebp-298h]
  std::wstring key; // [esp+18h] [ebp-294h] BYREF
  std::wstring _Keyval; // [esp+30h] [ebp-27Ch] BYREF
  std::wstring section; // [esp+48h] [ebp-264h] BYREF
  INIReaderDocuments ini; // [esp+60h] [ebp-24Ch] BYREF
  std::wstring v157; // [esp+A4h] [ebp-208h] BYREF
  std::wstring v158; // [esp+BCh] [ebp-1F0h] BYREF
  std::wstring v159; // [esp+D4h] [ebp-1D8h] BYREF
  std::wstring v160; // [esp+ECh] [ebp-1C0h] BYREF
  std::wstring v161; // [esp+104h] [ebp-1A8h] BYREF
  std::wstring v162; // [esp+11Ch] [ebp-190h] BYREF
  std::wstring v163; // [esp+134h] [ebp-178h] BYREF
  std::wstring v164; // [esp+14Ch] [ebp-160h] BYREF
  std::wstring v165; // [esp+164h] [ebp-148h] BYREF
  std::wstring v166; // [esp+17Ch] [ebp-130h] BYREF
  std::wstring v167; // [esp+194h] [ebp-118h] BYREF
  std::wstring v168; // [esp+1ACh] [ebp-100h] BYREF
  std::wstring v169; // [esp+1C4h] [ebp-E8h] BYREF
  std::wstring v170; // [esp+1DCh] [ebp-D0h] BYREF
  std::wstring v171; // [esp+1F4h] [ebp-B8h] BYREF
  std::wstring v172; // [esp+20Ch] [ebp-A0h] BYREF
  std::wstring v173; // [esp+224h] [ebp-88h] BYREF
  std::wstring v174; // [esp+23Ch] [ebp-70h] BYREF
  std::wstring v175; // [esp+254h] [ebp-58h] BYREF
  std::wstring v176; // [esp+26Ch] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v177; // [esp+284h] [ebp-28h] BYREF
  int v178; // [esp+2A8h] [ebp-4h]

  v152 = this;
  this->commands._Myhead = 0;
  this->commands._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,int>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TyreCompoundStrategy>> > *)this);
  this->commands._Myhead = v3;
  v150 = 0;
  v178 = 0;
  v149._Myres = 7;
  v149._Mysize = 0;
  v149._Bx._Buf[0] = 0;
  std::wstring::assign(&v149, L"cfg/controls.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&ini, a2, v149, v150);
  LOBYTE(v178) = 1;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ABS", 3u);
    LOBYTE(v178) = 2;
    v4 = INIReader::hasSection(&ini, &section);
    LOBYTE(v178) = 1;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v4 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 3;
      std::wstring::wstring(&_Keyval, L"ABS");
      LOBYTE(v178) = 4;
      std::wstring::wstring(&section, L"ABS");
      LOBYTE(v178) = 5;
      v5 = INIReader::getHex(&ini, &_Keyval, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &section)->key = v5;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"ABS");
      LOBYTE(v178) = 6;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 65;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    _Keyval._Myres = 7;
    _Keyval._Mysize = 0;
    _Keyval._Bx._Buf[0] = 0;
    std::wstring::assign(&_Keyval, L"TRACTION_CONTROL", 0x10u);
    LOBYTE(v178) = 7;
    v6 = INIReader::hasSection(&ini, &_Keyval);
    LOBYTE(v178) = 1;
    if ( _Keyval._Myres >= 8 )
      operator delete(_Keyval._Bx._Ptr);
    if ( v6 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 8;
      std::wstring::wstring(&section, L"TRACTION_CONTROL");
      LOBYTE(v178) = 9;
      std::wstring::wstring(&_Keyval, L"Traction Control");
      LOBYTE(v178) = 10;
      v7 = INIReader::getHex(&ini, &section, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval)->key = v7;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"Traction Control");
      LOBYTE(v178) = 11;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 84;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    _Keyval._Myres = 7;
    _Keyval._Mysize = 0;
    _Keyval._Bx._Buf[0] = 0;
    std::wstring::assign(&_Keyval, L"ACTIVATE_AI", 0xBu);
    LOBYTE(v178) = 12;
    v8 = INIReader::hasSection(&ini, &_Keyval);
    LOBYTE(v178) = 1;
    if ( _Keyval._Myres >= 8 )
      operator delete(_Keyval._Bx._Ptr);
    if ( v8 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 13;
      std::wstring::wstring(&section, L"ACTIVATE_AI");
      LOBYTE(v178) = 14;
      std::wstring::wstring(&_Keyval, L"Activate AI");
      LOBYTE(v178) = 15;
      v9 = INIReader::getHex(&ini, &section, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval)->key = v9;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"Activate AI");
      LOBYTE(v178) = 16;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 67;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    _Keyval._Myres = 7;
    _Keyval._Mysize = 0;
    _Keyval._Bx._Buf[0] = 0;
    std::wstring::assign(&_Keyval, L"RESET_RACE", 0xAu);
    LOBYTE(v178) = 17;
    v10 = INIReader::hasSection(&ini, &_Keyval);
    LOBYTE(v178) = 1;
    if ( _Keyval._Myres >= 8 )
      operator delete(_Keyval._Bx._Ptr);
    if ( v10 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 18;
      std::wstring::wstring(&section, L"RESET_RACE");
      LOBYTE(v178) = 19;
      std::wstring::wstring(&_Keyval, L"Reset Race");
      LOBYTE(v178) = 20;
      v11 = INIReader::getHex(&ini, &section, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval)->key = v11;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"Reset Race");
      LOBYTE(v178) = 21;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 79;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    _Keyval._Myres = 7;
    _Keyval._Mysize = 0;
    _Keyval._Bx._Buf[0] = 0;
    std::wstring::assign(&_Keyval, L"AUTO_SHIFTER", 0xCu);
    LOBYTE(v178) = 22;
    v12 = INIReader::hasSection(&ini, &_Keyval);
    LOBYTE(v178) = 1;
    if ( _Keyval._Myres >= 8 )
      operator delete(_Keyval._Bx._Ptr);
    if ( v12 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 23;
      std::wstring::wstring(&section, L"AUTO_SHIFTER");
      LOBYTE(v178) = 24;
      std::wstring::wstring(&_Keyval, L"Auto Shifter");
      LOBYTE(v178) = 25;
      v13 = INIReader::getHex(&ini, &section, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval)->key = v13;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"Auto Shifter");
      LOBYTE(v178) = 26;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 71;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    _Keyval._Myres = 7;
    _Keyval._Mysize = 0;
    _Keyval._Bx._Buf[0] = 0;
    std::wstring::assign(&_Keyval, L"FFWD", 4u);
    LOBYTE(v178) = 27;
    v14 = INIReader::hasSection(&ini, &_Keyval);
    LOBYTE(v178) = 1;
    if ( _Keyval._Myres >= 8 )
      operator delete(_Keyval._Bx._Ptr);
    if ( v14 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 28;
      std::wstring::wstring(&section, L"FFWD");
      LOBYTE(v178) = 29;
      std::wstring::wstring(&_Keyval, L"FFWD");
      LOBYTE(v178) = 30;
      v15 = INIReader::getHex(&ini, &section, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval)->key = v15;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"FFWD");
      LOBYTE(v178) = 31;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 70;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"REV");
    LOBYTE(v178) = 32;
    v16 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v16 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 33;
      std::wstring::wstring(&section, L"REV");
      LOBYTE(v178) = 34;
      std::wstring::wstring(&_Keyval, L"REV");
      LOBYTE(v178) = 35;
      v17 = INIReader::getHex(&ini, &section, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval)->key = v17;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"REV");
      LOBYTE(v178) = 36;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 68;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"SLOWMO");
    LOBYTE(v178) = 37;
    v18 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v18 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 38;
      std::wstring::wstring(&section, L"SLOWMO");
      LOBYTE(v178) = 39;
      std::wstring::wstring(&_Keyval, L"SLOWMO");
      LOBYTE(v178) = 40;
      v19 = INIReader::getHex(&ini, &section, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval)->key = v19;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"SLOWMO");
      LOBYTE(v178) = 41;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 83;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"HIDE_APPS");
    LOBYTE(v178) = 42;
    v20 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v20 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 43;
      std::wstring::wstring(&section, L"HIDE_APPS");
      LOBYTE(v178) = 44;
      std::wstring::wstring(&_Keyval, L"Hide Show Apps");
      LOBYTE(v178) = 45;
      v21 = INIReader::getHex(&ini, &section, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval)->key = v21;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"Hide Show Apps");
      LOBYTE(v178) = 46;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 72;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"IDEAL_LINE");
    LOBYTE(v178) = 47;
    v22 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v22 )
    {
      std::wstring::wstring(&key, L"KEY");
      LOBYTE(v178) = 48;
      std::wstring::wstring(&section, L"IDEAL_LINE");
      LOBYTE(v178) = 49;
      std::wstring::wstring(&_Keyval, L"Ideal Line");
      LOBYTE(v178) = 50;
      v23 = INIReader::getHex(&ini, &section, &key);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval)->key = v23;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    else
    {
      std::wstring::wstring(&key, L"Ideal Line");
      LOBYTE(v178) = 51;
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = 73;
    }
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"SHOW_DAMAGE");
    LOBYTE(v178) = 52;
    v24 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v24 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 53;
      std::wstring::wstring(&_Keyval, L"SHOW_DAMAGE");
      LOBYTE(v178) = 54;
      std::wstring::wstring(&key, L"Show Damage");
      LOBYTE(v178) = 55;
      v25 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v25;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v26 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Show Damage");
      LOBYTE(v178) = 56;
      v27 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v26 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v27->key = 74;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v26);
    std::wstring::wstring(&key, L"PREVIOUS_LAP");
    LOBYTE(v178) = 57;
    v28 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v28 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 58;
      std::wstring::wstring(&_Keyval, L"PREVIOUS_LAP");
      LOBYTE(v178) = 59;
      std::wstring::wstring(&key, L"Previous Lap");
      LOBYTE(v178) = 60;
      v29 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v29;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v30 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Previous Lap");
      LOBYTE(v178) = 61;
      v31 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v30 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v31->key = 80;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v30);
    std::wstring::wstring(&key, L"NEXT_LAP");
    LOBYTE(v178) = 62;
    v32 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v32 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 63;
      std::wstring::wstring(&_Keyval, L"NEXT_LAP");
      LOBYTE(v178) = 64;
      std::wstring::wstring(&key, L"Next Lap");
      LOBYTE(v178) = 65;
      v33 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v33;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v34 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Next Lap");
      LOBYTE(v178) = 66;
      v35 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v34 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v35->key = 78;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v34);
    std::wstring::wstring(&key, L"PAUSE_REPLAY");
    LOBYTE(v178) = 67;
    v36 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v36 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 68;
      std::wstring::wstring(&_Keyval, L"PAUSE_REPLAY");
      LOBYTE(v178) = 69;
      std::wstring::wstring(&key, L"Pause Replay");
      LOBYTE(v178) = 70;
      v37 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v37;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v38 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Pause Replay");
      LOBYTE(v178) = 71;
      v39 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v38 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v39->key = 32;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v38);
    std::wstring::wstring(&key, L"DRIVER_NAMES");
    LOBYTE(v178) = 72;
    v40 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v40 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 73;
      std::wstring::wstring(&_Keyval, L"DRIVER_NAMES");
      LOBYTE(v178) = 74;
      std::wstring::wstring(&key, L"Driver Names");
      LOBYTE(v178) = 75;
      v41 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v41;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v42 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Driver Names");
      LOBYTE(v178) = 76;
      v43 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v42 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v43->key = 76;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v42);
    std::wstring::wstring(&key, L"NEXT_CAR");
    LOBYTE(v178) = 77;
    v44 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v44 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 78;
      std::wstring::wstring(&_Keyval, L"NEXT_CAR");
      LOBYTE(v178) = 79;
      std::wstring::wstring(&key, L"Next Car");
      LOBYTE(v178) = 80;
      v45 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v45;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v46 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Next Car");
      LOBYTE(v178) = 81;
      v47 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v46 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v47->key = 99;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v46);
    std::wstring::wstring(&key, L"PREVIOUS_CAR");
    LOBYTE(v178) = 82;
    v48 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v48 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 83;
      std::wstring::wstring(&_Keyval, L"PREVIOUS_CAR");
      LOBYTE(v178) = 84;
      std::wstring::wstring(&key, L"Previous Car");
      LOBYTE(v178) = 85;
      v49 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v49;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v50 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Previous Car");
      LOBYTE(v178) = 86;
      v51 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v50 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v51->key = 97;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v50);
    std::wstring::wstring(&key, L"PLAYER_CAR");
    LOBYTE(v178) = 87;
    v52 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v52 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 88;
      std::wstring::wstring(&_Keyval, L"PLAYER_CAR");
      LOBYTE(v178) = 89;
      std::wstring::wstring(&key, L"Player Car");
      LOBYTE(v178) = 90;
      v53 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v53;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v54 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Player Car");
      LOBYTE(v178) = 91;
      v55 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v54 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v55->key = 98;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v54);
    std::wstring::wstring(&key, L"START_REPLAY");
    LOBYTE(v178) = 92;
    v56 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v56 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 93;
      std::wstring::wstring(&_Keyval, L"START_REPLAY");
      LOBYTE(v178) = 94;
      std::wstring::wstring(&key, L"Start Replay");
      LOBYTE(v178) = 95;
      v57 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v57;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v58 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Start Replay");
      LOBYTE(v178) = 96;
      v59 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v58 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v59->key = 82;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v58);
    std::wstring::wstring(&key, L"MOUSE_STEERING");
    LOBYTE(v178) = 97;
    v60 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v60 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 98;
      std::wstring::wstring(&_Keyval, L"MOUSE_STEERING");
      LOBYTE(v178) = 99;
      std::wstring::wstring(&key, L"Mouse Steering");
      LOBYTE(v178) = 100;
      v61 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v61;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v62 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Mouse Steering");
      LOBYTE(v178) = 101;
      v63 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v62 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v63->key = 77;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v62);
    std::wstring::wstring(&key, L"HIDE_DAMAGE");
    LOBYTE(v178) = 102;
    v64 = INIReader::hasSection(&ini, &key);
    LOBYTE(v178) = 1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v64 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 103;
      std::wstring::wstring(&_Keyval, L"HIDE_DAMAGE");
      LOBYTE(v178) = 104;
      std::wstring::wstring(&key, L"Hide Damage");
      LOBYTE(v178) = 105;
      v65 = INIReader::getHex(&ini, &_Keyval, &section);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = v65;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v66 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Hide Damage");
      LOBYTE(v178) = 106;
      v67 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
      v66 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
      v67->key = 81;
    }
    LOBYTE(v178) = 1;
    std::wstring::~wstring(v66);
    std::wstring::wstring(&key, L"Mouse Force Hide");
    LOBYTE(v178) = 107;
    v68 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
    LOBYTE(v178) = 1;
    v68->key = 119;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"Engine Brake");
    LOBYTE(v178) = 108;
    v69 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
    LOBYTE(v178) = 1;
    v69->key = 52;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"MGU-H Mode");
    LOBYTE(v178) = 109;
    v70 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
    LOBYTE(v178) = 1;
    v70->key = 51;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"MGU-K Delivery");
    LOBYTE(v178) = 110;
    v71 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
    LOBYTE(v178) = 1;
    v71->key = 50;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"MGU-K Recovery");
    LOBYTE(v178) = 111;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x31);
    v73 = v72;
    v74 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
    LOBYTE(v178) = 1;
    v74->key = *v73;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    std::wstring::wstring(&_Keyval, L"CYCLE_DESKTOP");
    LOBYTE(v178) = 112;
    v75 = INIReader::hasSection(&ini, &_Keyval);
    LOBYTE(v178) = 1;
    v76 = v75;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
    if ( v76 )
    {
      std::wstring::wstring(&section, L"KEY");
      LOBYTE(v178) = 113;
      std::wstring::wstring(&_Keyval, L"CYCLE_DESKTOP");
      LOBYTE(v178) = 114;
      std::wstring::wstring(&key, L"Cycle Virtual Desktop");
      LOBYTE(v178) = 115;
      v77 = (CarAudioFMOD *)INIReader::getHex(&ini, &_Keyval, &section);
      CommandItem::CommandItem(&v151, v77);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = *v78;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      v79 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section;
    }
    else
    {
      std::wstring::wstring(&key, L"Cycle Virtual Desktop");
      LOBYTE(v178) = 116;
      CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x55);
      std::map<std::wstring,CommandItem>::operator[](&this->commands, &key)->key = *v80;
      v79 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key;
    }
  }
  else
  {
    std::wstring::wstring(&key, L"ABS");
    LOBYTE(v178) = 117;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x41);
    v82 = v81;
    v83 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &key);
    LOBYTE(v178) = 1;
    v83->key = *v82;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    std::wstring::wstring(&_Keyval, L"Traction Control");
    LOBYTE(v178) = 118;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x54);
    v85 = v84;
    v86 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &_Keyval);
    LOBYTE(v178) = 1;
    v86->key = *v85;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
    std::wstring::wstring(&section, L"Activate AI");
    LOBYTE(v178) = 119;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x43);
    v88 = v87;
    v89 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &section);
    LOBYTE(v178) = 1;
    v89->key = *v88;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    std::wstring::wstring(&v174, L"Reset Race");
    LOBYTE(v178) = 120;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x4F);
    v91 = v90;
    v92 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v174);
    LOBYTE(v178) = 1;
    v92->key = *v91;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v174);
    std::wstring::wstring(&v177.name, L"Auto Shifter");
    LOBYTE(v178) = 121;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x47);
    v94 = v93;
    v95 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v177.name);
    LOBYTE(v178) = 1;
    v95->key = *v94;
    std::wstring::~wstring(&v177);
    std::wstring::wstring(&v168, L"FFWD");
    LOBYTE(v178) = 122;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x46);
    v97 = v96;
    v98 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v168);
    LOBYTE(v178) = 1;
    v98->key = *v97;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v168);
    std::wstring::wstring(&v160, L"REV");
    LOBYTE(v178) = 123;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x44);
    v100 = v99;
    v101 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v160);
    LOBYTE(v178) = 1;
    v101->key = *v100;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v160);
    std::wstring::wstring(&v176, L"SLOWMO");
    LOBYTE(v178) = 124;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x53);
    v103 = v102;
    v104 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v176);
    LOBYTE(v178) = 1;
    v104->key = *v103;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v176);
    std::wstring::wstring(&v162, L"Hide Show Apps");
    LOBYTE(v178) = 125;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x48);
    v106 = v105;
    v107 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v162);
    LOBYTE(v178) = 1;
    v107->key = *v106;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v162);
    std::wstring::wstring(&v170, L"Ideal Line");
    LOBYTE(v178) = 126;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x49);
    v109 = v108;
    v110 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v170);
    LOBYTE(v178) = 1;
    v110->key = *v109;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v170);
    std::wstring::wstring(&v164, L"Show Damage");
    LOBYTE(v178) = 127;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x4A);
    v112 = v111;
    v113 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v164);
    LOBYTE(v178) = 1;
    v113->key = *v112;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v164);
    std::wstring::wstring(&v157, L"Previous Lap");
    LOBYTE(v178) = 0x80;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x50);
    v115 = v114;
    v116 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v157);
    LOBYTE(v178) = 1;
    v116->key = *v115;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v157);
    std::wstring::wstring(&v166, L"Next Lap");
    LOBYTE(v178) = -127;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x4E);
    std::map<std::wstring,CommandItem>::operator[](&this->commands, &v166)->key = *v117;
    LOBYTE(v178) = 1;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v166);
    std::wstring::wstring(&v172, L"Pause Replay");
    LOBYTE(v178) = -126;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x20);
    v119 = v118;
    v120 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v172);
    LOBYTE(v178) = 1;
    v120->key = *v119;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v172);
    std::wstring::wstring(&v158, L"Driver Names");
    LOBYTE(v178) = -125;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x4C);
    v122 = v121;
    v123 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v158);
    LOBYTE(v178) = 1;
    v123->key = *v122;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158);
    std::wstring::wstring(&v159, L"Next Car");
    LOBYTE(v178) = -124;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x63);
    v125 = v124;
    v126 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v159);
    LOBYTE(v178) = 1;
    v126->key = *v125;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v159);
    std::wstring::wstring(&v161, L"Previous Car");
    LOBYTE(v178) = -123;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x61);
    v128 = v127;
    v129 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v161);
    LOBYTE(v178) = 1;
    v129->key = *v128;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v161);
    std::wstring::wstring(&v163, L"Player Car");
    LOBYTE(v178) = -122;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x62);
    v131 = v130;
    v132 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v163);
    LOBYTE(v178) = 1;
    v132->key = *v131;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
    std::wstring::wstring(&v165, L"Start Replay");
    LOBYTE(v178) = -121;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x52);
    v134 = v133;
    v135 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v165);
    LOBYTE(v178) = 1;
    v135->key = *v134;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v165);
    std::wstring::wstring(&v167, L"Mouse Steering");
    LOBYTE(v178) = -120;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x4D);
    v137 = v136;
    v138 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v167);
    LOBYTE(v178) = 1;
    v138->key = *v137;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v167);
    std::wstring::wstring(&v169, L"Hide Damage");
    LOBYTE(v178) = -119;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x51);
    v140 = v139;
    v141 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v169);
    LOBYTE(v178) = 1;
    v141->key = *v140;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v169);
    std::wstring::wstring(&v171, L"Engine Brake");
    LOBYTE(v178) = -118;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x45);
    v143 = v142;
    v144 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v171);
    LOBYTE(v178) = 1;
    v144->key = *v143;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v171);
    std::wstring::wstring(&v173, L"Mouse Force Hide");
    LOBYTE(v178) = -117;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x77);
    v146 = v145;
    v147 = std::map<std::wstring,CommandItem>::operator[](&this->commands, &v173);
    LOBYTE(v178) = 1;
    v147->key = *v146;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v173);
    std::wstring::wstring(&v175, L"Cycle Virtual Desktop");
    LOBYTE(v178) = -116;
    CommandItem::CommandItem(&v151, (CarAudioFMOD *)0x55);
    std::map<std::wstring,CommandItem>::operator[](&this->commands, &v175)->key = *v148;
    v79 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v175;
  }
  std::wstring::~wstring(v79);
  LOBYTE(v178) = 0;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
int CommandManager::getCommand(CommandManager *this, const std::wstring *commandName)
{
  return std::map<std::wstring,CommandItem>::operator[](&this->commands, commandName)->key;
}
