#include "dynamiccontroller.h"
bool DynamicController::isReady(DynamicController *this)
{
  return this->ready;
}
DynamicController *DynamicController::operator=(DynamicController *this, const DynamicController *__that)
{
  this->car = __that->car;
  std::vector<DynamicControllerStage>::operator=(&this->stages, &__that->stages);
  this->ready = __that->ready;
  return this;
}
void DynamicController::DynamicController(DynamicController *this, Car *car, const std::wstring *filename)
{
  DynamicController *v3; // esi
  const std::wstring *v4; // edi
  std::_Tree_node<std::pair<std::wstring const ,enum DynamicControllerInput>,void *> *v5; // eax
  DynamicControllerInput *v6; // eax
  DynamicControllerInput *v7; // eax
  DynamicControllerInput *v8; // eax
  DynamicControllerInput *v9; // eax
  DynamicControllerInput *v10; // eax
  DynamicControllerInput *v11; // eax
  DynamicControllerInput *v12; // eax
  DynamicControllerInput *v13; // eax
  DynamicControllerInput *v14; // eax
  DynamicControllerInput *v15; // eax
  DynamicControllerInput *v16; // eax
  DynamicControllerInput *v17; // eax
  DynamicControllerInput *v18; // eax
  DynamicControllerInput *v19; // eax
  DynamicControllerInput *v20; // eax
  DynamicControllerInput *v21; // eax
  DynamicControllerInput *v22; // eax
  DynamicControllerInput *v23; // eax
  DynamicControllerInput *v24; // eax
  DynamicControllerInput *v25; // eax
  DynamicControllerInput *v26; // eax
  DynamicControllerInput *v27; // eax
  DynamicControllerInput *v28; // eax
  DynamicControllerInput *v29; // eax
  std::_Tree_node<std::pair<std::wstring const ,enum DynamicControllerInput>,void *> *v30; // esi
  std::_Tree_node<std::pair<std::wstring const ,enum DynamicControllerInput>,void *> *v31; // eax
  std::pair<std::wstring const ,enum DynamicControllerInput> *v32; // edi
  std::pair<std::wstring const ,enum DynamicControllerInput> *v33; // eax
  std::_Tree_node<std::pair<std::wstring const ,enum DynamicControllerInput>,void *> *i; // eax
  std::wstring *v35; // eax
  std::_Tree_node<std::pair<std::wstring const ,enum DynamicControllerInput>,void *> *v36; // esi
  DynamicControllerInput v37; // eax
  std::wstring *v38; // edi
  std::wstring *v39; // esi
  std::wstring *v40; // eax
  std::wstring *v41; // eax
  std::wstring *v42; // esi
  int v43; // eax
  DynamicControllerCombinatorMode v44; // ecx
  std::wstring *v45; // edi
  std::wstring *v46; // esi
  std::wstring *v47; // eax
  std::wstring *v48; // eax
  const Curve *v49; // eax
  std::wstring *v50; // eax
  std::wstring *v51; // eax
  std::wstring *v52; // eax
  bool v53; // cf
  std::_Tree_node<std::pair<std::wstring const ,enum DynamicControllerInput>,void *> *v54; // esi
  std::map<std::wstring,enum DynamicControllerInput> inputmap; // [esp+14h] [ebp-218h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,enum DynamicControllerInput> > > > _S2; // [esp+1Ch] [ebp-210h] BYREF
  std::wstring *_Right; // [esp+20h] [ebp-20Ch]
  DynamicController *v58; // [esp+24h] [ebp-208h]
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,enum DynamicControllerInput> > >,std::_Iterator_base0> v59; // [esp+28h] [ebp-204h] BYREF
  Car *v60; // [esp+2Ch] [ebp-200h]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,enum DynamicControllerInput> > > > v61; // [esp+30h] [ebp-1FCh] BYREF
  DynamicController *v62; // [esp+34h] [ebp-1F8h]
  std::wstring _Keyval; // [esp+38h] [ebp-1F4h] BYREF
  std::wstring data_path; // [esp+50h] [ebp-1DCh] BYREF
  std::wstring v65; // [esp+68h] [ebp-1C4h] BYREF
  std::wstring inp; // [esp+80h] [ebp-1ACh] BYREF
  std::wstring section; // [esp+98h] [ebp-194h] BYREF
  std::wstring key; // [esp+B0h] [ebp-17Ch] BYREF
  std::wstring v69; // [esp+C8h] [ebp-164h] BYREF
  std::pair<std::wstring const ,enum DynamicControllerInput> p; // [esp+E0h] [ebp-14Ch] BYREF
  std::wstring result; // [esp+FCh] [ebp-130h] BYREF
  DynamicControllerStage stage; // [esp+114h] [ebp-118h] BYREF
  INIReader ini; // [esp+17Ch] [ebp-B0h] BYREF
  Curve v74; // [esp+1C4h] [ebp-68h] BYREF
  int v75; // [esp+228h] [ebp-4h]

  v3 = this;
  v58 = this;
  v4 = filename;
  this->car = car;
  v62 = this;
  v60 = car;
  _Right = (std::wstring *)filename;
  this->stages._Myfirst = 0;
  this->stages._Mylast = 0;
  this->stages._Myend = 0;
  v75 = 0;
  this->ready = 0;
  inputmap._Myhead = 0;
  inputmap._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,int>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TyreCompoundStrategy>> > *)&inputmap);
  inputmap._Myhead = v5;
  LOBYTE(v75) = 1;
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"BRAKE", 5u);
  LOBYTE(v75) = 2;
  v6 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v6 = eBrake;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"GAS", 3u);
  LOBYTE(v75) = 3;
  v7 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v7 = eGas;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"STEER", 5u);
  LOBYTE(v75) = 4;
  v8 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v8 = eSteer;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"LATG", 4u);
  LOBYTE(v75) = 5;
  v9 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v9 = eLatG;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"LONG", 4u);
  LOBYTE(v75) = 6;
  v10 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v10 = eLonG;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"SPEED_KMH", 9u);
  LOBYTE(v75) = 7;
  v11 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v11 = eSpeed;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"GEAR", 4u);
  LOBYTE(v75) = 8;
  v12 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v12 = SusTravelLR;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"SLIPRATIO_MAX", 0xDu);
  LOBYTE(v75) = 9;
  v13 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v13 = SusTravelRR;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"SLIPRATIO_AVG", 0xDu);
  LOBYTE(v75) = 10;
  v14 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v14 = SusTravelRR|eBrake;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"SLIPANGLE_FRONT_AVG", 0x13u);
  LOBYTE(v75) = 11;
  v15 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v15 = SusTravelRR|eGas;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"SLIPANGLE_FRONT_MAX", 0x13u);
  LOBYTE(v75) = 12;
  v16 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v16 = SusTravelRR|eLonG;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"SLIPANGLE_REAR_AVG", 0x12u);
  LOBYTE(v75) = 13;
  v17 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v17 = SusTravelRR|eLatG;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"SLIPANGLE_REAR_MAX", 0x12u);
  LOBYTE(v75) = 14;
  v18 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v18 = SusTravelRR|eSteer;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"OVERSTEER_FACTOR", 0x10u);
  LOBYTE(v75) = 15;
  v19 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v19 = SusTravelRR|eSpeed;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"REAR_SPEED_RATIO", 0x10u);
  LOBYTE(v75) = 16;
  v20 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v20 = SusTravelRR|SusTravelLR;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"STEER_DEG", 9u);
  LOBYTE(v75) = 17;
  v21 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v21 = 16;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"CONST", 5u);
  LOBYTE(v75) = 18;
  v22 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v22 = 17;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"RPMS", 4u);
  LOBYTE(v75) = 19;
  v23 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &_Keyval);
  LOBYTE(v75) = 1;
  *v23 = 18;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  std::wstring::wstring(&data_path, L"WHEEL_STEER_DEG");
  LOBYTE(v75) = 20;
  v24 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &data_path);
  LOBYTE(v75) = 1;
  *v24 = eLatG|0x10;
  if ( data_path._Myres >= 8 )
    operator delete(data_path._Bx._Ptr);
  std::wstring::wstring(&data_path, L"LOAD_SPREAD_LF");
  LOBYTE(v75) = 21;
  v25 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &data_path);
  LOBYTE(v75) = 1;
  *v25 = 20;
  if ( data_path._Myres >= 8 )
    operator delete(data_path._Bx._Ptr);
  std::wstring::wstring(&data_path, L"LOAD_SPREAD_RF");
  LOBYTE(v75) = 22;
  v26 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &data_path);
  LOBYTE(v75) = 1;
  *v26 = eSteer|0x10;
  if ( data_path._Myres >= 8 )
    operator delete(data_path._Bx._Ptr);
  std::wstring::wstring(&data_path, L"AVG_TRAVEL_REAR");
  LOBYTE(v75) = 23;
  v27 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &data_path);
  LOBYTE(v75) = 1;
  *v27 = eSpeed|0x10;
  if ( data_path._Myres >= 8 )
    operator delete(data_path._Bx._Ptr);
  std::wstring::wstring(&data_path, L"SUS_TRAVEL_LR");
  LOBYTE(v75) = 24;
  v28 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &data_path);
  LOBYTE(v75) = 1;
  *v28 = SusTravelLR|0x10;
  if ( data_path._Myres >= 8 )
    operator delete(data_path._Bx._Ptr);
  std::wstring::wstring(&data_path, L"SUS_TRAVEL_RR");
  LOBYTE(v75) = 25;
  v29 = std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &data_path);
  LOBYTE(v75) = 1;
  *v29 = 24;
  if ( data_path._Myres >= 8 )
    operator delete(data_path._Bx._Ptr);
  if ( !has_printed_input_list )
  {
    _printf("DYNAMIC CONTROLLER INPUT LIST:\n");
    v30 = inputmap._Myhead;
    v31 = inputmap._Myhead->_Left;
    _S2._Ptr = v31;
    if ( v31 != inputmap._Myhead )
    {
      do
      {
        v32 = &v31->_Myval;
        p.first._Myres = 7;
        p.first._Mysize = 0;
        p.first._Bx._Buf[0] = 0;
        std::wstring::assign((std::wstring *)&p.first, &v31->_Myval.first, 0, 0xFFFFFFFF);
        p.second = v32->second;
        v33 = &p;
        if ( p.first._Myres >= 8 )
          v33 = (std::pair<std::wstring const ,enum DynamicControllerInput> *)p.first._Bx._Ptr;
        _printf("- %S\n", v33->first._Bx._Buf);
        if ( p.first._Myres >= 8 )
          operator delete(p.first._Bx._Ptr);
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const,std::vector<AudioEvent *>>>>,std::_Iterator_base0>::operator++((std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > >,std::_Iterator_base0> *)&_S2);
        v31 = _S2._Ptr;
      }
      while ( _S2._Ptr != v30 );
      v4 = _Right;
    }
    has_printed_input_list = 1;
    _printf("\n\n");
    v3 = v58;
  }
  INIReader::INIReader(&ini, v4);
  LOBYTE(v75) = 26;
  if ( ini.ready )
  {
    for ( i = 0;
          ;
          i = (std::_Tree_node<std::pair<std::wstring const ,enum DynamicControllerInput>,void *> *)((char *)&_S2._Ptr->_Left + 1) )
    {
      _S2._Ptr = i;
      v35 = std::to_wstring(&result, (int)i);
      LOBYTE(v75) = 27;
      std::operator+<wchar_t>(&section, L"CONTROLLER_", v35);
      LOBYTE(v75) = 29;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Bx._Buf[0] = 0;
      result._Mysize = 0;
      if ( !INIReader::hasSection(&ini, &section) )
        break;
      stage.inputVar = eUndefined;
      stage.combinatorMode = eUndefinedMode;
      Curve::Curve(&stage.lut);
      stage.constValue = 0.0;
      *(_OWORD *)&stage.filter = 0i64;
      LOBYTE(v75) = 30;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"INPUT", 5u);
      LOBYTE(v75) = 31;
      INIReader::getString(&ini, &inp, &section, &key);
      LOBYTE(v75) = 33;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v36 = inputmap._Myhead;
      key._Myres = 7;
      key._Bx._Buf[0] = 0;
      key._Mysize = 0;
      if ( std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::find(
             &inputmap,
             &v61,
             &inp)->_Ptr == v36 )
      {
        v37 = stage.inputVar;
      }
      else
      {
        v37 = *std::map<std::wstring,enum DynamicControllerInput>::operator[](&inputmap, &inp);
        stage.inputVar = v37;
      }
      if ( v37 == eUndefined )
      {
        v38 = &section;
        v39 = &inp;
        if ( section._Myres >= 8 )
          v38 = (std::wstring *)section._Bx._Ptr;
        if ( inp._Myres >= 8 )
          v39 = (std::wstring *)inp._Bx._Ptr;
        v40 = std::wstring::c_str(_Right);
        _printf(
          "ERROR: INPUT UNDEFINED (%S) FOR DYNAMIC CONTROLLER STAGE %S FILE:%S\n",
          v39->_Bx._Buf,
          v38->_Bx._Buf,
          v40->_Bx._Buf);
        if ( INIReader::crashAtError )
        {
          std::wstring::wstring(&_Keyval, L"CONTROLLER INPUT UNDEFINED");
          v41 = &_Keyval;
          LOBYTE(v75) = 34;
          if ( _Keyval._Myres >= 8 )
            v41 = (std::wstring *)_Keyval._Bx._Ptr;
          _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v41->_Bx._Buf);
          ksGenerateCrash();
          LOBYTE(v75) = 33;
          if ( _Keyval._Myres >= 8 )
            operator delete(_Keyval._Bx._Ptr);
        }
      }
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      std::wstring::assign(&_Keyval, L"COMBINATOR", 0xAu);
      LOBYTE(v75) = 35;
      v42 = INIReader::getString(&ini, &v69, &section, &_Keyval);
      if ( &inp != v42 )
      {
        if ( inp._Myres >= 8 )
          operator delete(inp._Bx._Ptr);
        inp._Myres = 7;
        inp._Mysize = 0;
        inp._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&inp, v42);
      }
      if ( v69._Myres >= 8 )
        operator delete(v69._Bx._Ptr);
      v69._Myres = 7;
      v69._Mysize = 0;
      v69._Bx._Buf[0] = 0;
      LOBYTE(v75) = 33;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      stage.combinatorMode = eUndefinedMode;
      v43 = std::wstring::compare(&inp, 0, inp._Mysize, L"ADD", 3u);
      v44 = stage.combinatorMode;
      if ( !v43 )
        v44 = eAdd;
      stage.combinatorMode = v44;
      if ( std::wstring::compare(&inp, 0, inp._Mysize, L"MULT", 4u) )
      {
        if ( stage.combinatorMode == eUndefinedMode )
        {
          v45 = &section;
          v46 = &inp;
          if ( section._Myres >= 8 )
            v45 = (std::wstring *)section._Bx._Ptr;
          if ( inp._Myres >= 8 )
            v46 = (std::wstring *)inp._Bx._Ptr;
          v47 = std::wstring::c_str(_Right);
          _printf(
            "ERROR: COMBINATOR MODE UNDEFINED (%S) FOR DYNAMIC CONTROLLER STAGE %S FILE:%S\n",
            v46->_Bx._Buf,
            v45->_Bx._Buf,
            v47->_Bx._Buf);
        }
      }
      else
      {
        stage.combinatorMode = eMult;
      }
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      std::wstring::assign(&_Keyval, L"content/cars/", 0xDu);
      LOBYTE(v75) = 36;
      v48 = std::operator+<wchar_t>(&v69, &_Keyval, &v60->unixName);
      LOBYTE(v75) = 37;
      std::operator+<wchar_t>(&data_path, v48, L"/data/");
      if ( v69._Myres >= 8 )
        operator delete(v69._Bx._Ptr);
      v69._Myres = 7;
      v69._Mysize = 0;
      v69._Bx._Buf[0] = 0;
      LOBYTE(v75) = 40;
      if ( _Keyval._Myres >= 8 )
        operator delete(_Keyval._Bx._Ptr);
      _Keyval._Myres = 7;
      _Keyval._Mysize = 0;
      _Keyval._Bx._Buf[0] = 0;
      if ( stage.inputVar == 17 )
      {
        std::wstring::wstring(&v65, L"CONST_VALUE");
        LOBYTE(v75) = 46;
        stage.constValue = INIReader::getFloat(&ini, &section, &v65);
        LOBYTE(v75) = 40;
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
      }
      else
      {
        std::wstring::wstring(&v65, L"LUT");
        LOBYTE(v75) = 41;
        v49 = INIReader::getCurve(&ini, &v74, &section, &v65);
        LOBYTE(v75) = 42;
        Curve::operator=(&stage.lut, v49);
        LOBYTE(v75) = 41;
        Curve::~Curve(&v74);
        LOBYTE(v75) = 40;
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
        if ( Curve::getCount(&stage.lut) <= 0 && INIReader::crashAtError )
        {
          v50 = std::operator+<wchar_t>(
                  (std::wstring *)&p.first,
                  L"ERROR: Could not load LUT for Dynamic Controller ",
                  _Right);
          LOBYTE(v75) = 43;
          v51 = std::operator+<wchar_t>(&v65, v50, L" section: ");
          LOBYTE(v75) = 44;
          v52 = std::operator+<wchar_t>(&key, v51, &section);
          v53 = v52->_Myres < 8;
          LOBYTE(v75) = 45;
          if ( !v53 )
            v52 = (std::wstring *)v52->_Bx._Ptr;
          _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v52->_Bx._Buf);
          ksGenerateCrash();
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          if ( v65._Myres >= 8 )
            operator delete(v65._Bx._Ptr);
          v65._Myres = 7;
          v65._Mysize = 0;
          v65._Bx._Buf[0] = 0;
          LOBYTE(v75) = 40;
          if ( p.first._Myres >= 8 )
            operator delete(p.first._Bx._Ptr);
        }
      }
      std::wstring::wstring(&v65, L"FILTER");
      LOBYTE(v75) = 47;
      *(float *)&v59._Ptr = INIReader::getFloat(&ini, &section, &v65);
      LOBYTE(v75) = 40;
      stage.filter = (float)((float)(1.0 - *(float *)&v59._Ptr) * 1.3333334) * 333.33334;
      if ( v65._Myres >= 8 )
        operator delete(v65._Bx._Ptr);
      std::wstring::wstring(&v65, L"UP_LIMIT");
      LOBYTE(v75) = 48;
      stage.upLimit = INIReader::getFloat(&ini, &section, &v65);
      LOBYTE(v75) = 40;
      if ( v65._Myres >= 8 )
        operator delete(v65._Bx._Ptr);
      std::wstring::wstring(&v65, L"DOWN_LIMIT");
      LOBYTE(v75) = 49;
      stage.downLimit = INIReader::getFloat(&ini, &section, &v65);
      LOBYTE(v75) = 40;
      if ( v65._Myres >= 8 )
        operator delete(v65._Bx._Ptr);
      v3 = v58;
      std::vector<DynamicControllerStage>::push_back(&v58->stages, &stage);
      if ( data_path._Myres >= 8 )
        operator delete(data_path._Bx._Ptr);
      data_path._Myres = 7;
      data_path._Mysize = 0;
      data_path._Bx._Buf[0] = 0;
      if ( inp._Myres >= 8 )
        operator delete(inp._Bx._Ptr);
      inp._Myres = 7;
      inp._Mysize = 0;
      inp._Bx._Buf[0] = 0;
      LOBYTE(v75) = 29;
      Curve::~Curve(&stage.lut);
      LOBYTE(v75) = 26;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    _printf("Controller is ready\n");
    v3->ready = 1;
  }
  else
  {
    if ( v4->_Myres >= 8 )
      v4 = (const std::wstring *)v4->_Bx._Ptr;
    _printf("Error: could not find ini input for dynamic controller: %S\n", v4->_Bx._Buf);
  }
  LOBYTE(v75) = 1;
  INIReader::~INIReader(&ini);
  v54 = inputmap._Myhead;
  LOBYTE(v75) = 0;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const,enum DynamicControllerInput>>>,std::_Iterator_base0>::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const,enum DynamicControllerInput>>>,std::_Iterator_base0>(
    &v59,
    inputmap._Myhead->_Left,
    &inputmap);
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&inputmap,
    (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > *)&v61,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)v59._Ptr,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)v54);
  std::_Tree_comp<0,std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>::~_Tree_comp<0,std::_Tmap_traits<std::wstring,INISection,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,INISection>>,0>>(&inputmap);
}
void DynamicController::DynamicController(DynamicController *this)
{
  this->car = 0;
  this->stages._Myfirst = 0;
  this->stages._Mylast = 0;
  this->stages._Myend = 0;
  this->ready = 0;
}
void DynamicController::~DynamicController(DynamicController *this)
{
  std::vector<DynamicControllerStage>::_Tidy(&this->stages);
}
double DynamicController::eval(DynamicController *this)
{
  float v2; // xmm1_4
  DynamicControllerStage *v3; // esi
  DynamicControllerStage *v4; // edi
  float v5; // xmm5_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  DynamicControllerCombinatorMode v9; // eax
  __int32 v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v14; // [esp+10h] [ebp-8h]
  float ref; // [esp+14h] [ebp-4h]
  float v16; // [esp+14h] [ebp-4h]

  v2 = 0.0;
  v3 = this->stages._Myfirst;
  v4 = this->stages._Mylast;
  v14 = 0.0;
  if ( v3 != v4 )
  {
    v5 = FLOAT_1_0;
    while ( 1 )
    {
      if ( v3->inputVar == 17 )
      {
        v6 = v3->constValue;
      }
      else
      {
        ref = DynamicController::getInput(this, v3->inputVar);
        v2 = v14;
        v5 = FLOAT_1_0;
        v16 = Curve::getValue(&v3->lut, ref);
        v6 = v16;
      }
      v7 = v3->currentValue;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v6 - v7) & _xmm) >= 0.001 )
      {
        v8 = v3->filter * 0.003;
        if ( v8 <= v5 )
        {
          if ( v8 < 0.0 )
            v8 = 0.0;
        }
        else
        {
          v8 = v5;
        }
        v6 = (float)((float)(v6 - v7) * v8) + v7;
      }
      v9 = v3->combinatorMode;
      v3->currentValue = v6;
      if ( v9 )
      {
        v10 = v9 - 1;
        if ( v10 )
        {
          if ( v10 == 1 )
          {
            v11 = v2 * v6;
            v14 = v11;
          }
          else
          {
            v11 = v14;
          }
        }
        else
        {
          v11 = v2 + v3->currentValue;
          v14 = v11;
        }
      }
      else
      {
        v11 = 0.0;
        v14 = 0.0;
      }
      v12 = v3->downLimit;
      if ( v12 == 0.0 && v3->upLimit == 0.0 )
        break;
      if ( v11 <= v3->upLimit )
      {
        if ( v12 <= v11 )
          break;
        v2 = v3->downLimit;
        v14 = v2;
      }
      else
      {
        v2 = v3->upLimit;
        v14 = v2;
      }
LABEL_26:
      if ( ++v3 == v4 )
        return v14;
    }
    v2 = v14;
    goto LABEL_26;
  }
  return v14;
}
double DynamicController::getInput(DynamicController *this, DynamicControllerInput input)
{
  ISuspension **v2; // eax
  ISuspension *v3; // edi
  float *v4; // esi
  double result; // st7
  int v6; // ecx
  int v7; // ecx
  DynamicControllerInput *v8; // eax
  TractionType v9; // ecx
  __int32 v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float *v21; // eax
  TractionType v22; // ecx
  __int32 v23; // ecx
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v29; // [esp+0h] [ebp-4h]

  switch ( input )
  {
    case 1:
      result = this->car->controls.brake;
      break;
    case 2:
      result = this->car->controls.gas;
      break;
    case 3:
      result = this->car->accG.x;
      break;
    case 4:
      result = this->car->accG.z;
      break;
    case 5:
      result = this->car->controls.steer;
      break;
    case 6:
      v29 = Car::getSpeed(this->car, (Speed *)&input)->value * 3.5999999;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&input);
      result = v29;
      break;
    case 7:
      result = (double)(this->car->drivetrain.currentGear - 1);
      break;
    case 8:
      v8 = (DynamicControllerInput *)this->car;
      v9 = this->car->drivetrain.tractionType;
      if ( v9 )
      {
        v10 = v9 - 1;
        if ( v10 )
        {
          if ( v10 != 1 )
            goto LABEL_55;
          v11 = *((float *)v8 + 1462);
          v12 = *((float *)v8 + 1870);
          if ( v11 <= v12 )
            v13 = *((float *)v8 + 1870);
          else
            v13 = *((float *)v8 + 1462);
          v14 = *((float *)v8 + 646);
          v15 = *((float *)v8 + 1054);
          if ( v14 <= v15 )
            v16 = *((float *)v8 + 1054);
          else
            v16 = *((float *)v8 + 646);
          if ( v13 <= v16 )
          {
            if ( v14 <= v15 )
            {
              input = *((_DWORD *)v8 + 1054);
              result = v15;
            }
            else
            {
              input = *((_DWORD *)v8 + 646);
              result = v14;
            }
          }
          else if ( v11 <= v12 )
          {
            input = *((_DWORD *)v8 + 1870);
            result = v12;
          }
          else
          {
            input = *((_DWORD *)v8 + 1462);
            result = v11;
          }
        }
        else
        {
          v17 = *((float *)v8 + 646);
          v18 = *((float *)v8 + 1054);
          if ( v17 <= v18 )
          {
            input = *((_DWORD *)v8 + 1054);
            result = v18;
          }
          else
          {
            input = *((_DWORD *)v8 + 646);
            result = v17;
          }
        }
      }
      else
      {
        v19 = *((float *)v8 + 1462);
        v20 = *((float *)v8 + 1870);
        if ( v19 <= v20 )
        {
          input = *((_DWORD *)v8 + 1870);
          result = v20;
        }
        else
        {
          input = *((_DWORD *)v8 + 1462);
          result = v19;
        }
      }
      break;
    case 9:
      v21 = (float *)this->car;
      v22 = this->car->drivetrain.tractionType;
      if ( v22 )
      {
        v23 = v22 - 1;
        if ( v23 )
        {
          if ( v23 != 1 )
            goto LABEL_55;
          result = (float)((float)((float)((float)(v21[1054] + v21[646]) + v21[1462]) + v21[1870]) * 0.25);
        }
        else
        {
          result = (v21[1054] + v21[646]) * 0.5;
        }
      }
      else
      {
        result = (v21[1462] + v21[1870]) * 0.5;
      }
      break;
    case 10:
      result = (this->car->tyres[1].status.slipAngleRAD + this->car->tyres[0].status.slipAngleRAD) * 57.29578 * 0.5;
      break;
    case 11:
      result = (this->car->tyres[3].status.slipAngleRAD + this->car->tyres[2].status.slipAngleRAD) * 57.29578 * 0.5;
      break;
    case 12:
      LODWORD(v24) = LODWORD(this->car->tyres[0].status.slipAngleRAD) & _xmm;
      LODWORD(v25) = LODWORD(this->car->tyres[1].status.slipAngleRAD) & _xmm;
      if ( v24 <= v25 )
      {
        input = LODWORD(this->car->tyres[1].status.slipAngleRAD) & _xmm;
        result = v25 * 57.29578;
      }
      else
      {
        input = LODWORD(this->car->tyres[0].status.slipAngleRAD) & _xmm;
        result = v24 * 57.29578;
      }
      break;
    case 13:
      LODWORD(v26) = LODWORD(this->car->tyres[2].status.slipAngleRAD) & _xmm;
      LODWORD(v27) = LODWORD(this->car->tyres[3].status.slipAngleRAD) & _xmm;
      if ( v26 <= v27 )
      {
        input = LODWORD(this->car->tyres[3].status.slipAngleRAD) & _xmm;
        result = v27 * 57.29578;
      }
      else
      {
        input = LODWORD(this->car->tyres[2].status.slipAngleRAD) & _xmm;
        result = v26 * 57.29578;
      }
      break;
    case 14:
      result = DynamicController::getOversteerFactor(this->car);
      break;
    case 15:
      result = DynamicController::getRearSpeedRatio(this->car);
      break;
    case 16:
      result = this->car->steerLock * this->car->controls.steer;
      break;
    case 18:
      result = Drivetrain::getEngineRPM(&this->car->drivetrain);
      break;
    case 19:
      result = this->car->finalSteerAngleSignal;
      break;
    case 20:
      result = this->car->tyres[0].status.load / (this->car->tyres[1].status.load + this->car->tyres[0].status.load);
      break;
    case 21:
      result = this->car->tyres[1].status.load / (this->car->tyres[0].status.load + this->car->tyres[1].status.load);
      break;
    case 22:
      v2 = this->car->suspensions._Myfirst;
      v3 = v2[2];
      v4 = (float *)v2[3]->getStatus(v2[3]);
      result = (*v4 + v3->getStatus(v3)->travel) * 0.5 * 1000.0;
      break;
    case 23:
      v6 = *((_DWORD *)this->car->suspensions._Myfirst + 2);
      result = *(float *)(*(int (**)(int, DynamicController *))(*(_DWORD *)v6 + 36))(v6, this) * 1000.0;
      break;
    case 24:
      v7 = *((_DWORD *)this->car->suspensions._Myfirst + 3);
      result = *(float *)(*(int (**)(int, DynamicController *))(*(_DWORD *)v7 + 36))(v7, this) * 1000.0;
      break;
    default:
LABEL_55:
      result = 0.0;
      break;
  }
  return result;
}
double __cdecl DynamicController::getOversteerFactor(Car *car)
{
  return (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(car->tyres[3].status.slipAngleRAD) & _xmm)
                                       + COERCE_FLOAT(LODWORD(car->tyres[2].status.slipAngleRAD) & _xmm))
                               * 0.5)
                       - (float)((float)(COERCE_FLOAT(LODWORD(car->tyres[0].status.slipAngleRAD) & _xmm)
                                       + COERCE_FLOAT(LODWORD(car->tyres[1].status.slipAngleRAD) & _xmm))
                               * 0.5))
               * 57.29578);
}
double __cdecl DynamicController::getRearSpeedRatio(Car *car)
{
  double result; // st7
  float front; // [esp+4h] [ebp+4h]

  front = (float)(car->tyres[1].status.angularVelocity + car->tyres[0].status.angularVelocity) * 0.5;
  if ( front == 0.0 )
    result = 0.0;
  else
    result = (car->tyres[3].status.angularVelocity + car->tyres[2].status.angularVelocity) * 0.5 / front;
  return result;
}
