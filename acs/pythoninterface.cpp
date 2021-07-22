#include "pythoninterface.h"
void PythonInterface::PythonInterface(PythonInterface *this, Sim *sim)
{
  Game *v3; // eax
  std::wofstream *v4; // esi
  int *v5; // edi
  std::wstring *v6; // eax
  const std::wstring *v7; // eax
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  bool v12; // zf
  int v13; // eax
  int v14; // ecx
  void (*v15)(const char *const, ...); // ebp
  PyInterpreter *v16; // eax
  PyInterpreter *v17; // eax
  PyInterpreter *v18; // esi
  PyInterpreter *v19; // ebp
  std::wstring *v20; // eax
  const INIReader *v21; // eax
  std::wstring *v22; // ebp
  std::wstring *v23; // ebx
  std::wstring *v24; // ecx
  std::wstring *v25; // edi
  wchar_t *v26; // eax
  std::wstring *v27; // ecx
  std::wstring *v28; // esi
  std::wstring *v29; // edi
  std::wstring *v30; // eax
  std::wstring *v31; // ecx
  wchar_t *v32; // eax
  std::wstring *v33; // ebp
  std::wstring *v34; // eax
  std::wstring *v35; // eax
  std::wstring *v36; // eax
  std::wstring *v37; // eax
  int v38; // eax
  std::wstring *v39; // eax
  std::wstring *v40; // eax
  std::string *v41; // eax
  PyModule *v42; // eax
  PyModule *v43; // eax
  PyPlugin *v44; // eax
  int v45; // eax
  int v46; // edi
  PythonInterface *v47; // edx
  GameObject **v48; // ecx
  std::vector<GameObject *> *v49; // esi
  GameObject **v50; // ecx
  int *v51; // eax
  std::vector<ICollisionObject *> *v52; // esi
  PyPlugin **v53; // eax
  int v54; // edi
  ICollisionObject **v55; // ecx
  _DWORD *v56; // eax
  std::wstring *v57; // eax
  Console *v58; // eax
  Console *v59; // eax
  Console *v60; // eax
  std::_Ref_count_base *v61; // esi
  std::wstring *v62; // eax
  Console *v63; // eax
  Console *v64; // eax
  Console *v65; // eax
  Console *v66; // eax
  std::wstring v67; // [esp-60h] [ebp-2C4h] BYREF
  std::wstring v68; // [esp-48h] [ebp-2ACh] BYREF
  _BYTE v69[48]; // [esp-30h] [ebp-294h] BYREF
  PyEnvironment env; // [esp+14h] [ebp-250h] BYREF
  int v71; // [esp+24h] [ebp-240h]
  unsigned int v72; // [esp+28h] [ebp-23Ch]
  std::wstring *i; // [esp+2Ch] [ebp-238h] BYREF
  PythonInterface *v74; // [esp+30h] [ebp-234h]
  unsigned int v75; // [esp+34h] [ebp-230h]
  int v76; // [esp+38h] [ebp-22Ch] BYREF
  int v77; // [esp+3Ch] [ebp-228h] BYREF
  Sim *v78; // [esp+40h] [ebp-224h]
  std::shared_ptr<PyModule> module; // [esp+44h] [ebp-220h] BYREF
  std::vector<std::wstring> sections; // [esp+4Ch] [ebp-218h] BYREF
  std::vector<std::wstring> pythonFolders; // [esp+58h] [ebp-20Ch] BYREF
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v82; // [esp+64h] [ebp-200h] BYREF
  std::wstring *v83; // [esp+68h] [ebp-1FCh]
  _BYTE *v84; // [esp+6Ch] [ebp-1F8h]
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v85; // [esp+70h] [ebp-1F4h] BYREF
  PythonInterface *v86; // [esp+74h] [ebp-1F0h]
  std::wstring *v87; // [esp+78h] [ebp-1ECh]
  std::wstring path_cmd; // [esp+7Ch] [ebp-1E8h] BYREF
  std::wstring appName; // [esp+94h] [ebp-1D0h] BYREF
  std::wstring pythonPath; // [esp+ACh] [ebp-1B8h] BYREF
  std::wstring main_file; // [esp+C4h] [ebp-1A0h] BYREF
  std::wstring path; // [esp+DCh] [ebp-188h] BYREF
  std::wstring v93; // [esp+F4h] [ebp-170h] BYREF
  std::wstring v94; // [esp+10Ch] [ebp-158h] BYREF
  std::wstring section; // [esp+124h] [ebp-140h] BYREF
  std::wstring filename; // [esp+13Ch] [ebp-128h] BYREF
  std::wstring folder; // [esp+154h] [ebp-110h] BYREF
  std::wstring v98; // [esp+16Ch] [ebp-F8h] BYREF
  std::wstring result; // [esp+184h] [ebp-E0h] BYREF
  std::wstring v100; // [esp+19Ch] [ebp-C8h] BYREF
  std::wstring appPath; // [esp+1B4h] [ebp-B0h] BYREF
  INIReaderDocuments pythonIni; // [esp+1CCh] [ebp-98h] BYREF
  INIReaderDocuments v103; // [esp+210h] [ebp-54h] BYREF
  int v104; // [esp+260h] [ebp-4h]

  v74 = this;
  v72 = 0;
  v86 = this;
  v78 = sim;
  *(_DWORD *)&v69[44] = sim->game;
  v75 = 0;
  *(_DWORD *)&v69[40] = 7;
  *(_DWORD *)&v69[36] = 0;
  *(_WORD *)&v69[20] = 0;
  std::wstring::assign((std::wstring *)&v69[20], L"PYTHON_INTERFACE", 0x10u);
  GameObject::GameObject(this, *(std::wstring *)&v69[20], *(Game **)&v69[44]);
  this->__vftable = (PythonInterface_vtbl *)&PythonInterface::`vftable';
  v3 = sim->game;
  v104 = 0;
  this->gl = v3->graphics->gl;
  this->evOnSetupAppCreated.handlers._Myfirst = 0;
  this->evOnSetupAppCreated.handlers._Mylast = 0;
  this->evOnSetupAppCreated.handlers._Myend = 0;
  v4 = &this->log;
  LOBYTE(v104) = 1;
  std::wofstream::wofstream(&this->log, 1);
  v5 = (int *)&this->py;
  this->py._Myptr = 0;
  this->plugins._Myfirst = 0;
  this->plugins._Mylast = 0;
  this->plugins._Myend = 0;
  this->controls._Myfirst = 0;
  this->controls._Mylast = 0;
  this->controls._Myend = 0;
  this->textures._Myfirst = 0;
  this->textures._Mylast = 0;
  this->textures._Myend = 0;
  LOBYTE(v104) = 6;
  v6 = Path::getDocumentPath(&path);
  LOBYTE(v104) = 7;
  v7 = std::operator+<wchar_t>(&pythonPath, v6, L"/Assetto Corsa");
  LOBYTE(v104) = 8;
  Path::createFolder(v7);
  if ( pythonPath._Myres >= 8 )
    operator delete(pythonPath._Bx._Ptr);
  pythonPath._Myres = 7;
  pythonPath._Mysize = 0;
  pythonPath._Bx._Buf[0] = 0;
  LOBYTE(v104) = 6;
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  v8 = Path::getDocumentPath(&path);
  LOBYTE(v104) = 9;
  v9 = std::operator+<wchar_t>(&pythonPath, v8, L"/Assetto Corsa/logs");
  LOBYTE(v104) = 10;
  Path::createFolder(v9);
  if ( pythonPath._Myres >= 8 )
    operator delete(pythonPath._Bx._Ptr);
  pythonPath._Myres = 7;
  pythonPath._Mysize = 0;
  pythonPath._Bx._Buf[0] = 0;
  LOBYTE(v104) = 6;
  if ( path._Myres >= 8 )
    operator delete(path._Bx._Ptr);
  v10 = Path::getDocumentPath(&result);
  LOBYTE(v104) = 11;
  std::operator+<wchar_t>(&filename, v10, L"/Assetto Corsa/logs/py_log.txt");
  LOBYTE(v104) = 13;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  v11 = &filename;
  if ( filename._Myres >= 8 )
    v11 = (std::wstring *)filename._Bx._Ptr;
  result._Mysize = 0;
  v12 = std::wfilebuf::open((std::wfilebuf *)&this->log.gap0[4], v11->_Bx._Buf, 2, 64) == 0;
  v13 = *(_DWORD *)v4->gap0;
  *(_DWORD *)&v69[44] = 0;
  v14 = *(_DWORD *)(v13 + 4);
  if ( v12 )
    std::wios::setstate((char *)v4 + v14, 2, *(_DWORD *)&v69[44]);
  else
    std::wios::clear((char *)v4 + v14, 0, *(_DWORD *)&v69[44]);
  v15 = (void (*)(const char *const, ...))_printf;
  pyi = this;
  _printf("Initialising Python Interface\n");
  this->sim = v78;
  PyEnvironment::PyEnvironment(&env, "ac");
  LOBYTE(v104) = 14;
  PyEnvironment::addFunc(&env, "log", ac_log);
  PyEnvironment::addFunc(&env, "console", ac_console);
  PyEnvironment::addFunc(&env, "newApp", (_object *(__cdecl *)(_object *, _object *))ac_newApp);
  PyEnvironment::addFunc(&env, "setTitle", ac_setAppTitle);
  PyEnvironment::addFunc(&env, "setPosition", ac_setPosition);
  PyEnvironment::addFunc(&env, "setIconPosition", ac_setIconPosition);
  PyEnvironment::addFunc(&env, "setTitlePosition", ac_setTitlePosition);
  PyEnvironment::addFunc(&env, "setText", ac_setText);
  PyEnvironment::addFunc(&env, "getText", ac_getText);
  PyEnvironment::addFunc(&env, "getPosition", ac_getPosition);
  PyEnvironment::addFunc(&env, "setSize", ac_setSize);
  PyEnvironment::addFunc(&env, "getSize", ac_getSize);
  PyEnvironment::addFunc(&env, "setVisible", ac_setVisible);
  PyEnvironment::addFunc(&env, "setBackgroundColor", ac_setBackgroundColor);
  PyEnvironment::addFunc(&env, "setBackgroundOpacity", ac_setBackgroundOpacity);
  PyEnvironment::addFunc(&env, "drawBackground", ac_drawBackground);
  PyEnvironment::addFunc(&env, "drawBorder", ac_drawBorder);
  PyEnvironment::addFunc(
    &env,
    "setBackgroundTexture",
    (_object *(__cdecl *)(_object *, _object *))ac_setBackgroundTexture);
  PyEnvironment::addFunc(&env, "setFontAlignment", ac_setFontAlignment);
  PyEnvironment::addFunc(&env, "addRenderCallback", ac_addRenderCallback);
  PyEnvironment::addFunc(&env, "addOnClickedListener", ac_addOnClickedListener);
  PyEnvironment::addFunc(&env, "addOnValidateListener", ac_addOnValidateListener);
  PyEnvironment::addFunc(&env, "addOnValueChangeListener", ac_addOnValueChangeListener);
  PyEnvironment::addFunc(&env, "addOnCheckBoxChanged", ac_addOnCheckBoxChanged);
  PyEnvironment::addFunc(&env, "addOnListBoxSelectionListener", ac_addOnListBoxSelectionListener);
  PyEnvironment::addFunc(&env, "addOnListBoxDeselectionListener", ac_addOnListBoxDeselectionListener);
  PyEnvironment::addFunc(&env, "addOnAppActivatedListener", ac_addOnAppActivatedListener);
  PyEnvironment::addFunc(&env, "addOnAppDismissedListener", ac_addOnAppDismissedListener);
  PyEnvironment::addFunc(&env, "sendChatMessage", ac_sendChatMessage);
  PyEnvironment::addFunc(&env, "addOnChatMessageListener", ac_addOnChatMessageListener);
  PyEnvironment::addFunc(&env, "initFont", ac_initFont);
  PyEnvironment::addFunc(&env, "setFont", (_object *(__cdecl *)(_object *, _object *))ac_setFont);
  PyEnvironment::addFunc(&env, "setFontColor", ac_setFontColor);
  PyEnvironment::addFunc(&env, "setFontSize", ac_setFontSize);
  PyEnvironment::addFunc(&env, "setCustomFont", ac_setCustomFont);
  PyEnvironment::addFunc(&env, "addLabel", ac_addLabel);
  PyEnvironment::addFunc(&env, "addButton", ac_addButton);
  PyEnvironment::addFunc(&env, "addCheckBox", ac_addCheckBox);
  PyEnvironment::addFunc(&env, "addGraph", ac_addGraph);
  PyEnvironment::addFunc(&env, "addSerieToGraph", ac_addSerieToGraph);
  PyEnvironment::addFunc(&env, "addValueToGraph", ac_addValueToGraph);
  PyEnvironment::addFunc(&env, "addListBox", ac_addListBox);
  PyEnvironment::addFunc(&env, "addItem", ac_addItem);
  PyEnvironment::addFunc(&env, "removeItem", ac_higlightListBoxElement);
  PyEnvironment::addFunc(&env, "getItemCount", ac_getItemCount);
  PyEnvironment::addFunc(&env, "setItemNumberPerPage", ac_higlightListBoxElement);
  PyEnvironment::addFunc(&env, "highlightListBoxItem", ac_higlightListBoxElement);
  PyEnvironment::addFunc(&env, "setAllowDeselection", ac_setAllowDeselectionOnListBox);
  PyEnvironment::addFunc(&env, "setAllowMultiSelection", ac_higlightListBoxElement);
  PyEnvironment::addFunc(&env, "getSelectedItems", ac_getItemCount);
  PyEnvironment::addFunc(&env, "addTextBox", ac_addTextBox);
  PyEnvironment::addFunc(&env, "addSpinner", ac_addSpinner);
  PyEnvironment::addFunc(&env, "setStep", ac_setStep);
  PyEnvironment::addFunc(&env, "addProgressBar", ac_addProgressBar);
  PyEnvironment::addFunc(&env, "setRange", ac_setRange);
  PyEnvironment::addFunc(&env, "setValue", ac_setValue);
  PyEnvironment::addFunc(&env, "getValue", ac_getValue);
  PyEnvironment::addFunc(&env, "addTextInput", ac_addTextInput);
  PyEnvironment::addFunc(&env, "setFocus", ac_setFocus);
  PyEnvironment::addFunc(&env, "glBegin", ac_glBegin);
  PyEnvironment::addFunc(&env, "glEnd", (_object *(__cdecl *)(_object *, _object *))ac_glEnd);
  PyEnvironment::addFunc(&env, "glVertex2f", ac_glVertex2f);
  PyEnvironment::addFunc(&env, "glColor3f", ac_glColor3f);
  PyEnvironment::addFunc(&env, "glColor4f", ac_glColor4f);
  PyEnvironment::addFunc(&env, "glQuad", ac_glQuad);
  PyEnvironment::addFunc(&env, "glQuadTextured", ac_glQuadTextured);
  PyEnvironment::addFunc(&env, "newTexture", (_object *(__cdecl *)(_object *, _object *))ac_newTexture);
  PyEnvironment::addFunc(&env, "getCarState", ac_getCarState);
  PyEnvironment::addFunc(&env, "getCarMinHeight", ac_getCarMinHeight);
  PyEnvironment::addFunc(&env, "isCarInPitline", ac_isCarInPitlane);
  PyEnvironment::addFunc(&env, "isCarInPitlane", ac_isCarInPitlane);
  PyEnvironment::addFunc(&env, "isCarInPit", ac_isCarInPit);
  PyEnvironment::addFunc(&env, "isConnected", ac_isConnected);
  PyEnvironment::addFunc(&env, "getCarBallast", ac_getCarBallast);
  PyEnvironment::addFunc(&env, "getCarRestrictor", ac_getCarRestrictor);
  PyEnvironment::addFunc(&env, "getCarTyreCompound", ac_getCarTyreCompound);
  PyEnvironment::addFunc(&env, "isAIControlled", ac_isAIControlled);
  PyEnvironment::addFunc(&env, "getCarEngineBrakeCount", ac_getCarEngineBrakeCount);
  PyEnvironment::addFunc(&env, "getCarPowerControllerCount", ac_getCarPowerControllerCount);
  PyEnvironment::addFunc(&env, "getCarFFB", (_object *(__cdecl *)(_object *, _object *))ac_getCarFFB);
  PyEnvironment::addFunc(&env, "setCarFFB", ac_setCarFFB);
  PyEnvironment::addFunc(&env, "getCarsCount", (_object *(__cdecl *)(_object *, _object *))ac_getCarsCount);
  PyEnvironment::addFunc(&env, "getCarLeaderboardPosition", ac_getCarLeaderboardPosition);
  PyEnvironment::addFunc(&env, "getCarRealTimeLeaderboardPosition", ac_getCarRealTimeLeaderboardPosition);
  PyEnvironment::addFunc(&env, "setCameraMode", ac_setCameraMode);
  PyEnvironment::addFunc(&env, "getCameraMode", (_object *(__cdecl *)(_object *, _object *))ac_getCameraMode);
  PyEnvironment::addFunc(&env, "isCameraOnBoard", ac_isCameraOnBoard);
  PyEnvironment::addFunc(&env, "getCameraCarCount", ac_getCameraCarCount);
  PyEnvironment::addFunc(&env, "setCameraCar", ac_setCameraCar);
  PyEnvironment::addFunc(&env, "focusCar", ac_focusCar);
  PyEnvironment::addFunc(&env, "getFocusedCar", (_object *(__cdecl *)(_object *, _object *))ac_getFocusedCar);
  PyEnvironment::addFunc(&env, "freeCameraSetClearColor", ac_freeCameraSetClearColor);
  PyEnvironment::addFunc(&env, "freeCameraMoveForward", ac_freeCameraMoveForward);
  PyEnvironment::addFunc(&env, "freeCameraMoveRight", ac_freeCameraMoveRight);
  PyEnvironment::addFunc(&env, "freeCameraMoveUpWorld", ac_freeCameraMoveUpWorld);
  PyEnvironment::addFunc(
    &env,
    "freeCameraRotatePitch",
    (_object *(__cdecl *)(_object *, _object *))ac_freeCameraRotatePitch);
  PyEnvironment::addFunc(
    &env,
    "freeCameraRotateHeading",
    (_object *(__cdecl *)(_object *, _object *))ac_freeCameraRotateHeading);
  PyEnvironment::addFunc(
    &env,
    "freeCameraRotateRoll",
    (_object *(__cdecl *)(_object *, _object *))ac_freeCameraRotateRoll);
  PyEnvironment::addFunc(&env, "getDriverName", ac_getDriverName);
  PyEnvironment::addFunc(&env, "getDriverNationCode", ac_getDriverNationCode);
  PyEnvironment::addFunc(&env, "getTrackName", ac_getTrackName);
  PyEnvironment::addFunc(&env, "getTrackConfiguration", ac_getTrackConfiguration);
  PyEnvironment::addFunc(&env, "getTrackLength", (_object *(__cdecl *)(_object *, _object *))ac_getTrackLength);
  PyEnvironment::addFunc(&env, "getCarName", ac_getCarName);
  PyEnvironment::addFunc(&env, "getCarSkin", ac_getCarSkin);
  PyEnvironment::addFunc(&env, "getLastSplits", ac_getLastSplits);
  PyEnvironment::addFunc(&env, "getCurrentSplits", ac_getCurrentSplits);
  PyEnvironment::addFunc(&env, "isAcLive", (_object *(__cdecl *)(_object *, _object *))ac_isAcLive);
  PyEnvironment::addFunc(&env, "getWindSpeed", (_object *(__cdecl *)(_object *, _object *))ac_getWindSpeed);
  PyEnvironment::addFunc(&env, "getWindDirection", (_object *(__cdecl *)(_object *, _object *))ac_getWindDirection);
  PyEnvironment::addFunc(&env, "shutdown", (_object *(__cdecl *)(_object *, _object *))ac_shutdown);
  PyEnvironment::addFunc(&env, "restart", (_object *(__cdecl *)(_object *, _object *))ac_restart);
  PyEnvironment::addFunc(&env, "getServerName", (_object *(__cdecl *)(_object *, _object *))ac_getServerName);
  PyEnvironment::addFunc(&env, "getServerIP", (_object *(__cdecl *)(_object *, _object *))ac_getServerIP);
  PyEnvironment::addFunc(&env, "getServerHttpPort", (_object *(__cdecl *)(_object *, _object *))ac_getServerHttpPort);
  PyEnvironment::addFunc(
    &env,
    "getServerSlotsCount",
    (_object *(__cdecl *)(_object *, _object *))ac_getServerSlotsCount);
  PyEnvironment::addTerminator(&env);
  *(_DWORD *)&v69[44] = 7;
  *(_DWORD *)&v69[40] = 0;
  *(_WORD *)&v69[24] = 0;
  std::wstring::assign((std::wstring *)&v69[24], L"apps/python/system/", 0x13u);
  clearPythonCache(*(std::wstring *)&v69[24]);
  v16 = (PyInterpreter *)operator new(20);
  i = (std::wstring *)v16;
  LOBYTE(v104) = 15;
  if ( v16 )
  {
    PyInterpreter::PyInterpreter(v16, &env);
    v18 = v17;
  }
  else
  {
    v18 = 0;
  }
  LOBYTE(v104) = 14;
  if ( v5 == (int *)&i )
  {
    if ( v18 )
    {
      PyInterpreter::~PyInterpreter(v18);
      operator delete(v18);
    }
  }
  else
  {
    v19 = (PyInterpreter *)*v5;
    *v5 = (int)v18;
    if ( v19 )
    {
      PyInterpreter::~PyInterpreter(v19);
      operator delete(v19);
    }
    v15 = (void (*)(const char *const, ...))_printf;
  }
  if ( *(_BYTE *)*v5 )
  {
    if ( _PyRun_SimpleStringFlags("import sys", 0) == -1 )
    {
      v15("ERROR: PythonInterface :: [ERROR] Python components are not working properly\n");
    }
    else
    {
      _PyRun_SimpleStringFlags("sys.dont_write_bytecode = 1", 0);
      _PyRun_SimpleStringFlags("sys.path.append('apps/python/system')", 0);
      v20 = Path::getDocumentPath(&v100);
      LOBYTE(v104) = 16;
      std::operator+<wchar_t>(&path, v20, L"/Assetto Corsa/cfg/python.ini");
      LOBYTE(v104) = 18;
      if ( v100._Myres >= 8 )
        operator delete(v100._Bx._Ptr);
      v100._Myres = 7;
      *(_DWORD *)&v69[44] = 0;
      v100._Bx._Buf[0] = 0;
      v100._Mysize = 0;
      *(_DWORD *)&v69[36] = 0;
      *(_DWORD *)&v69[40] = 7;
      *(_WORD *)&v69[20] = 0;
      std::wstring::assign((std::wstring *)&v69[20], &path, 0, 0xFFFFFFFF);
      INIReaderDocuments::INIReaderDocuments(&v103, (unsigned int)this, *(std::wstring *)&v69[20], v69[44]);
      LOBYTE(v104) = 19;
      INIReader::INIReader(&pythonIni, v21);
      pythonIni.__vftable = (INIReaderDocuments_vtbl *)&INIReaderDocuments::`vftable';
      LOBYTE(v104) = 21;
      INIReaderDocuments::~INIReaderDocuments(&v103);
      sections._Myfirst = 0;
      sections._Mylast = 0;
      sections._Myend = 0;
      LOBYTE(v104) = 22;
      INIReader::getSections(&pythonIni, &sections);
      std::wstring::wstring(&pythonPath, L"apps/python/*.*");
      LOBYTE(v104) = 23;
      Path::getFolders(&pythonFolders, &pythonPath);
      LOBYTE(v104) = 24;
      v15("LOADING %d PY APPS\n", pythonFolders._Mylast - pythonFolders._Myfirst);
      v22 = sections._Mylast;
      v23 = sections._Myfirst;
      for ( i = sections._Mylast; v23 != v22; ++v23 )
      {
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        std::wstring::assign(&section, v23, 0, 0xFFFFFFFF);
        LOBYTE(v104) = 25;
        appName._Bx._Buf[0] = 0;
        appName._Myres = 7;
        appName._Mysize = 0;
        std::wstring::assign(&appName, &section, 0, 0xFFFFFFFF);
        v24 = &appName;
        v25 = &appName;
        LOBYTE(v104) = 26;
        if ( appName._Myres >= 8 )
          v24 = (std::wstring *)appName._Bx._Ptr;
        if ( appName._Myres >= 8 )
          v25 = (std::wstring *)appName._Bx._Ptr;
        v26 = &v24->_Bx._Buf[appName._Mysize];
        v27 = &appName;
        if ( appName._Myres >= 8 )
          v27 = (std::wstring *)appName._Bx._Ptr;
        if ( v27 == (std::wstring *)v26 )
          v82._Ptr = (const wchar_t *)v25;
        else
          std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
            &v82,
            v27->_Bx._Buf,
            v26,
            (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v25,
            _tolower);
        v28 = pythonFolders._Myfirst;
        v29 = pythonFolders._Mylast;
        if ( pythonFolders._Myfirst != pythonFolders._Mylast )
        {
          do
          {
            folder._Myres = 7;
            folder._Mysize = 0;
            folder._Bx._Buf[0] = 0;
            std::wstring::assign(&folder, v28, 0, 0xFFFFFFFF);
            LOBYTE(v104) = 27;
            path_cmd._Bx._Buf[0] = 0;
            path_cmd._Myres = 7;
            path_cmd._Mysize = 0;
            std::wstring::assign(&path_cmd, &folder, 0, 0xFFFFFFFF);
            v30 = &path_cmd;
            v31 = &path_cmd;
            if ( path_cmd._Myres >= 8 )
              v30 = (std::wstring *)path_cmd._Bx._Ptr;
            if ( path_cmd._Myres >= 8 )
              v31 = (std::wstring *)path_cmd._Bx._Ptr;
            LOBYTE(v104) = 28;
            v32 = &v30->_Bx._Buf[path_cmd._Mysize];
            v33 = &path_cmd;
            if ( path_cmd._Myres >= 8 )
              v33 = (std::wstring *)path_cmd._Bx._Ptr;
            if ( v33 == (std::wstring *)v32 )
              v85._Ptr = (const wchar_t *)v31;
            else
              std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
                &v85,
                v33->_Bx._Buf,
                v32,
                (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v31,
                _tolower);
            v34 = &appName;
            *(_DWORD *)&v69[44] = appName._Mysize;
            if ( appName._Myres >= 8 )
              v34 = (std::wstring *)appName._Bx._Ptr;
            if ( !std::wstring::compare(&path_cmd, 0, path_cmd._Mysize, v34->_Bx._Buf, *(unsigned int *)&v69[44]) )
              std::wstring::assign(&appName, &folder, 0, 0xFFFFFFFF);
            if ( path_cmd._Myres >= 8 )
              operator delete(path_cmd._Bx._Ptr);
            LOBYTE(v104) = 26;
            if ( folder._Myres >= 8 )
              operator delete(folder._Bx._Ptr);
            ++v28;
          }
          while ( v28 != v29 );
          v22 = i;
        }
        v35 = std::operator+<wchar_t>(&v93, L"apps/python/", &appName);
        LOBYTE(v104) = 29;
        v36 = std::operator+<wchar_t>(&appPath, v35, L"/");
        LOBYTE(v104) = 30;
        v37 = std::operator+<wchar_t>(&v98, v36, &appName);
        LOBYTE(v104) = 31;
        std::operator+<wchar_t>(&main_file, v37, L".py");
        if ( v98._Myres >= 8 )
          operator delete(v98._Bx._Ptr);
        v98._Myres = 7;
        v98._Mysize = 0;
        v98._Bx._Buf[0] = 0;
        if ( appPath._Myres >= 8 )
          operator delete(appPath._Bx._Ptr);
        appPath._Myres = 7;
        appPath._Mysize = 0;
        appPath._Bx._Buf[0] = 0;
        LOBYTE(v104) = 35;
        if ( v93._Myres >= 8 )
          operator delete(v93._Bx._Ptr);
        v93._Myres = 7;
        v93._Bx._Buf[0] = 0;
        v93._Mysize = 0;
        if ( !Path::fileExists((unsigned int)v23, &main_file, 0) )
          goto LABEL_69;
        path_cmd._Myres = 7;
        path_cmd._Mysize = 0;
        path_cmd._Bx._Buf[0] = 0;
        std::wstring::assign(&path_cmd, L"ACTIVE", 6u);
        LOBYTE(v104) = 36;
        v75 |= 1u;
        v72 = v75;
        v38 = INIReader::getInt(&pythonIni, &section, &path_cmd);
        HIBYTE(v71) = 1;
        if ( !v38 )
LABEL_69:
          HIBYTE(v71) = 0;
        v104 = 35;
        if ( (v75 & 1) != 0 )
        {
          v75 &= 0xFFFFFFFE;
          if ( path_cmd._Myres >= 8 )
            operator delete(path_cmd._Bx._Ptr);
        }
        if ( HIBYTE(v71) )
        {
          v39 = std::operator+<wchar_t>(&v94, L"apps/python/", &appName);
          LOBYTE(v104) = 37;
          std::operator+<wchar_t>((std::wstring *)&v69[24], v39, L"/");
          clearPythonCache(*(std::wstring *)&v69[24]);
          LOBYTE(v104) = 35;
          if ( v94._Myres >= 8 )
            operator delete(v94._Bx._Ptr);
          v40 = std::operator+<wchar_t>(&v94, L"sys.path.append('apps/python/", &appName);
          LOBYTE(v104) = 38;
          std::operator+<wchar_t>(&path_cmd, v40, L"')");
          LOBYTE(v104) = 40;
          if ( v94._Myres >= 8 )
            operator delete(v94._Bx._Ptr);
          v94._Myres = 7;
          v94._Bx._Buf[0] = 0;
          v94._Mysize = 0;
          v41 = wstring2string((std::string *)&v93, &path_cmd);
          if ( v41->_Myres >= 0x10 )
            v41 = (std::string *)v41->_Bx._Ptr;
          _PyRun_SimpleStringFlags(v41, 0);
          if ( v93._Myres >= 0x10 )
            operator delete(v93._Bx._Ptr);
          v42 = (PyModule *)operator new(32);
          v72 = (unsigned int)v42;
          LOBYTE(v104) = 41;
          if ( v42 )
            PyModule::PyModule(v42, &appName);
          else
            v43 = 0;
          LOBYTE(v104) = 40;
          module._Ptr = 0;
          module._Rep = 0;
          std::shared_ptr<PyModule>::_Resetp<PyModule>(&module, v43);
          LOBYTE(v104) = 42;
          if ( module._Ptr->hasErrors )
          {
            v57 = &path_cmd;
            if ( path_cmd._Myres >= 8 )
              v57 = (std::wstring *)path_cmd._Bx._Ptr;
            _printf("ERROR: Python ERROR LOADING MODULE :%S\n", v57->_Bx._Buf);
            if ( std::wstring::compare(&appName, 0, appName._Mysize, L"system", 6u) )
            {
              v72 = (unsigned int)&v69[24];
              *(_DWORD *)&v69[44] = 7;
              *(_DWORD *)&v69[40] = 0;
              *(_WORD *)&v69[24] = 0;
              std::wstring::assign((std::wstring *)&v69[24], L"\n", 1u);
              LOBYTE(v104) = 44;
              v84 = v69;
              *(_DWORD *)&v69[20] = 7;
              *(_DWORD *)&v69[16] = 0;
              *(_WORD *)v69 = 0;
              std::wstring::assign((std::wstring *)v69, &path_cmd, 0, 0xFFFFFFFF);
              LOBYTE(v104) = 45;
              v83 = &v68;
              v68._Myres = 7;
              v68._Mysize = 0;
              v68._Bx._Buf[0] = 0;
              std::wstring::assign(&v68, L"Python [ERROR] ERROR LOADING MODULE : ", 0x26u);
              LOBYTE(v104) = 46;
              v58 = Console::singleton();
              LOBYTE(v104) = 45;
              v59 = Console::operator<<(v58, v68);
              LOBYTE(v104) = 44;
              v60 = Console::operator<<(v59, *(std::wstring *)v69);
              LOBYTE(v104) = 42;
              Console::operator<<(v60, *(std::wstring *)&v69[24]);
            }
          }
          else
          {
            v44 = (PyPlugin *)operator new(72);
            v72 = (unsigned int)v44;
            LOBYTE(v104) = 43;
            if ( v44 )
            {
              PyPlugin::PyPlugin(v44, &module, v78);
              v46 = v45;
            }
            else
            {
              v46 = 0;
            }
            v47 = v74;
            v48 = v74->gameObjects._Mylast;
            v49 = &v74->gameObjects;
            LOBYTE(v104) = 42;
            v76 = v46;
            if ( &v76 >= (int *)v48 || v49->_Myfirst > (GameObject **)&v76 )
            {
              if ( v48 == v74->gameObjects._Myend )
              {
                std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v74->gameObjects, 1u);
                v47 = v74;
              }
              v51 = (int *)v49->_Mylast;
              if ( v51 )
                *v51 = v46;
            }
            else
            {
              v72 = ((char *)&v76 - (char *)v49->_Myfirst) >> 2;
              if ( v48 == v74->gameObjects._Myend )
              {
                std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v74->gameObjects, 1u);
                v47 = v74;
              }
              v50 = v49->_Mylast;
              if ( v50 )
                *v50 = v49->_Myfirst[v72];
            }
            ++v49->_Mylast;
            v52 = (std::vector<ICollisionObject *> *)&v47->plugins;
            *(_DWORD *)(v46 + 36) = v47;
            v53 = v47->plugins._Mylast;
            v77 = v46;
            if ( &v77 >= (int *)v53 || v52->_Myfirst > (ICollisionObject **)&v77 )
            {
              if ( v53 == v47->plugins._Myend )
                std::vector<SVar *>::_Reserve(v52, 1u);
              v56 = v52->_Mylast;
              if ( v56 )
                *v56 = v46;
              ++v52->_Mylast;
            }
            else
            {
              v54 = ((char *)&v77 - (char *)v52->_Myfirst) >> 2;
              if ( v53 == v47->plugins._Myend )
                std::vector<SVar *>::_Reserve(v52, 1u);
              v55 = v52->_Mylast;
              if ( v55 )
                *v55 = v52->_Myfirst[v54];
              ++v52->_Mylast;
            }
          }
          v61 = module._Rep;
          LOBYTE(v104) = 40;
          if ( module._Rep )
          {
            if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&module._Rep->_Uses, 0xFFFFFFFF) )
            {
              v61->_Destroy(v61);
              if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v61->_Weaks, 0xFFFFFFFF) )
                v61->_Delete_this(v61);
            }
          }
          if ( path_cmd._Myres >= 8 )
            operator delete(path_cmd._Bx._Ptr);
        }
        else
        {
          v62 = &main_file;
          if ( main_file._Myres >= 8 )
            v62 = (std::wstring *)main_file._Bx._Ptr;
          _printf("ERROR: Python [ERROR] File %S not found\n", v62->_Bx._Buf);
          if ( std::wstring::compare(&appName, 0, appName._Mysize, L"system", 6u) )
          {
            v83 = (std::wstring *)&v69[24];
            std::wstring::wstring((std::wstring *)&v69[24], L"\n");
            LOBYTE(v104) = 47;
            v84 = v69;
            std::wstring::wstring((std::wstring *)v69, L" not found in folder");
            LOBYTE(v104) = 48;
            v72 = (unsigned int)&v68;
            v68._Myres = 7;
            v68._Mysize = 0;
            v68._Bx._Buf[0] = 0;
            std::wstring::assign(&v68, &main_file, 0, 0xFFFFFFFF);
            LOBYTE(v104) = 49;
            v87 = &v67;
            std::wstring::wstring(&v67, L"Python [ERROR] File ");
            LOBYTE(v104) = 50;
            v63 = Console::singleton();
            LOBYTE(v104) = 49;
            v64 = Console::operator<<(v63, v67);
            LOBYTE(v104) = 48;
            v65 = Console::operator<<(v64, v68);
            LOBYTE(v104) = 47;
            v66 = Console::operator<<(v65, *(std::wstring *)v69);
            LOBYTE(v104) = 35;
            Console::operator<<(v66, *(std::wstring *)&v69[24]);
          }
        }
        if ( main_file._Myres >= 8 )
          operator delete(main_file._Bx._Ptr);
        main_file._Myres = 7;
        main_file._Mysize = 0;
        main_file._Bx._Buf[0] = 0;
        if ( appName._Myres >= 8 )
          operator delete(appName._Bx._Ptr);
        LOBYTE(v104) = 24;
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
      }
      std::vector<std::wstring>::_Tidy(&pythonFolders);
      if ( pythonPath._Myres >= 8 )
        operator delete(pythonPath._Bx._Ptr);
      pythonPath._Myres = 7;
      pythonPath._Mysize = 0;
      pythonPath._Bx._Buf[0] = 0;
      std::vector<std::wstring>::_Tidy(&sections);
      LOBYTE(v104) = 18;
      INIReaderDocuments::~INIReaderDocuments(&pythonIni);
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
    }
  }
  else
  {
    v15("ERROR: PYTHON FATAL ERRROR :: INTERPRETER HAS NOT BEEN INITIALIZED CORRECTLY\n");
  }
  LOBYTE(v104) = 13;
  std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&env);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void PythonInterface::~PythonInterface(PythonInterface *this)
{
  PythonInterface *v1; // ebp
  std::wofstream *v2; // ebx
  PythonForm **v3; // ecx
  std::vector<ksgui::Control *> *v4; // edi
  unsigned int v5; // ebx
  int v6; // eax
  PythonForm *v7; // eax
  PythonForm *v8; // esi
  PythonForm **v9; // ecx
  int v10; // esi
  unsigned int i; // esi
  PythonForm *v12; // edx
  bool v13; // zf
  std::vector<Texture> *v14; // ebx
  Texture *v15; // ebp
  Texture *j; // esi
  std::vector<PyPlugin *> *v17; // esi
  PyInterpreter *v18; // esi
  int v19; // eax
  _BYTE *v20; // edi
  Event<OnSetupAppCreated> *v21; // ebx
  std::pair<void *,std::function<void __cdecl(OnSetupAppCreated const &)> > *v22; // ebp
  std::pair<void *,std::function<void __cdecl(OnSetupAppCreated const &)> > *v23; // edi
  std::_Func_base<void,OnSetupAppCreated const &> **v24; // esi
  PythonForm *d; // [esp+18h] [ebp-20h] BYREF
  PythonInterface *v26; // [esp+1Ch] [ebp-1Ch]
  std::vector<PythonForm *> pyFormsToDelete; // [esp+20h] [ebp-18h] BYREF
  int v28; // [esp+34h] [ebp-4h]

  v1 = this;
  v26 = this;
  this->__vftable = (PythonInterface_vtbl *)&PythonInterface::`vftable';
  v2 = &this->log;
  v28 = 6;
  if ( !std::wfilebuf::close((std::wfilebuf *)&this->log.gap0[4]) )
    std::wios::setstate((char *)v2 + *(_DWORD *)(*(_DWORD *)v2->gap0 + 4), 2, 0);
  v3 = 0;
  pyFormsToDelete._Myfirst = 0;
  pyFormsToDelete._Mylast = 0;
  pyFormsToDelete._Myend = 0;
  v4 = &v1->controls;
  v5 = 0;
  v6 = v1->controls._Mylast - v1->controls._Myfirst;
  LOBYTE(v28) = 7;
  if ( v6 )
  {
    do
    {
      v7 = (PythonForm *)__RTDynamicCast(
                           v4->_Myfirst[v5],
                           0,
                           &ksgui::Control `RTTI Type Descriptor',
                           &PythonForm `RTTI Type Descriptor',
                           0);
      v8 = v7;
      d = v7;
      if ( v7 && v7->category )
      {
        v9 = pyFormsToDelete._Mylast;
        if ( &d >= pyFormsToDelete._Mylast || pyFormsToDelete._Myfirst > &d )
        {
          if ( pyFormsToDelete._Mylast == pyFormsToDelete._Myend )
          {
            std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&pyFormsToDelete, 1u);
            v9 = pyFormsToDelete._Mylast;
          }
          if ( v9 )
          {
            *v9 = v8;
            v9 = pyFormsToDelete._Mylast;
          }
          v3 = v9 + 1;
          pyFormsToDelete._Mylast = v3;
        }
        else
        {
          v10 = &d - pyFormsToDelete._Myfirst;
          if ( pyFormsToDelete._Mylast == pyFormsToDelete._Myend )
          {
            std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&pyFormsToDelete, 1u);
            v9 = pyFormsToDelete._Mylast;
          }
          if ( v9 )
          {
            *v9 = pyFormsToDelete._Myfirst[v10];
            v9 = pyFormsToDelete._Mylast;
          }
          v3 = v9 + 1;
          pyFormsToDelete._Mylast = v3;
        }
      }
      else
      {
        v3 = pyFormsToDelete._Mylast;
      }
      ++v5;
    }
    while ( v5 < v1->controls._Mylast - v1->controls._Myfirst );
  }
  for ( i = 0; i < v3 - pyFormsToDelete._Myfirst; ++i )
  {
    v12 = pyFormsToDelete._Myfirst[i];
    if ( v12 )
    {
      ((void (*)(PythonForm *, int))v12->~Control)(pyFormsToDelete._Myfirst[i], 1);
      v3 = pyFormsToDelete._Mylast;
    }
  }
  LOBYTE(v28) = 6;
  if ( pyFormsToDelete._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&pyFormsToDelete);
    operator delete(pyFormsToDelete._Myfirst);
    pyFormsToDelete._Myfirst = 0;
    pyFormsToDelete._Mylast = 0;
    pyFormsToDelete._Myend = 0;
  }
  v13 = v1->textures._Myfirst == 0;
  v14 = &v1->textures;
  LOBYTE(v28) = 5;
  if ( !v13 )
  {
    std::_Container_base0::_Orphan_all(&v1->textures);
    v15 = v1->textures._Mylast;
    for ( j = v14->_Myfirst; j != v15; ++j )
      OnSetupAppCreated::~OnSetupAppCreated(j);
    operator delete(v14->_Myfirst);
    v1 = v26;
    v14->_Myfirst = 0;
    v14->_Mylast = 0;
    v14->_Myend = 0;
  }
  v13 = v4->_Myfirst == 0;
  LOBYTE(v28) = 4;
  if ( !v13 )
  {
    std::_Container_base0::_Orphan_all(v4);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    v4->_Mylast = 0;
    v4->_Myend = 0;
  }
  v13 = v1->plugins._Myfirst == 0;
  v17 = &v1->plugins;
  LOBYTE(v28) = 3;
  if ( !v13 )
  {
    std::_Container_base0::_Orphan_all(&v1->plugins);
    operator delete(v17->_Myfirst);
    v17->_Myfirst = 0;
    v1->plugins._Mylast = 0;
    v1->plugins._Myend = 0;
  }
  v18 = v1->py._Myptr;
  LOBYTE(v28) = 2;
  if ( v18 )
  {
    PyInterpreter::~PyInterpreter(v18);
    operator delete(v18);
  }
  v19 = *(_DWORD *)v1->log.gap0;
  v20 = &v1->log.gap58[8];
  LOBYTE(v28) = 1;
  *(_DWORD *)&v20[*(_DWORD *)(v19 + 4) - 96] = &std::wofstream::`vftable';
  *(_DWORD *)&v20[*(_DWORD *)(*(_DWORD *)v1->log.gap0 + 4) - 100] = *(_DWORD *)(*(_DWORD *)v1->log.gap0 + 4) - 96;
  v13 = *(_DWORD *)&v1->log._Filebuffer[4] == 0;
  *(_DWORD *)&v1->log.gap0[4] = &std::wfilebuf::`vftable';
  if ( !v13 && (_BYTE *)std::wstreambuf::eback(&v1->log.gap0[4]) == &v1->log.gap0[72] )
    std::wstreambuf::setg(
      &v1->log.gap0[4],
      *(_DWORD *)&v1->log.gap0[60],
      *(_DWORD *)&v1->log.gap0[60],
      *(_DWORD *)&v1->log.gap0[64]);
  if ( v1->log._Filebuffer[0] )
  {
    if ( *(_DWORD *)&v1->log._Filebuffer[4] )
    {
      std::wfilebuf::_Endwrite((std::wfilebuf *)&v1->log.gap0[4]);
      _fclose(*(FILE **)&v1->log._Filebuffer[4]);
    }
    v1->log._Filebuffer[0] = 0;
    v1->log.gap0[74] = 0;
    std::wstreambuf::_Init(&v1->log.gap0[4]);
    *(_DWORD *)&v1->log._Filebuffer[4] = 0;
    *(_DWORD *)&v1->log.gap0[76] = `std::wfilebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&v1->log.gap0[68] = 0;
  }
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v1->log.gap0[4]);
  std::wostream::~wostream<wchar_t,std::char_traits<wchar_t>>(&v1->log.gap0[8]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&v1->log.gap58[8]);
  v13 = v1->evOnSetupAppCreated.handlers._Myfirst == 0;
  v21 = &v1->evOnSetupAppCreated;
  LOBYTE(v28) = 0;
  if ( !v13 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v1->evOnSetupAppCreated);
    v22 = v1->evOnSetupAppCreated.handlers._Mylast;
    v23 = v21->handlers._Myfirst;
    if ( v21->handlers._Myfirst != v22 )
    {
      v24 = &v23->second._Impl;
      do
      {
        if ( *v24 )
        {
          ((void (__stdcall *)(bool))(*v24)->_Delete_this)(*v24 != (std::_Func_base<void,OnSetupAppCreated const &> *)(v24 - 4));
          *v24 = 0;
        }
        ++v23;
        v24 += 8;
      }
      while ( v23 != v22 );
    }
    operator delete(v21->handlers._Myfirst);
    v1 = v26;
    v21->handlers._Myfirst = 0;
    v21->handlers._Mylast = 0;
    v21->handlers._Myend = 0;
  }
  v28 = -1;
  GameObject::~GameObject(v1);
}
PythonInterface *PythonInterface::`scalar deleting destructor'(PythonInterface *this, unsigned int a2)
{
  PythonInterface::~PythonInterface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
int PythonInterface::addFormToTaskBar(PythonInterface *this, ksgui::Control *c)
{
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, (int *)&c);
  if ( __RTDynamicCast(c, 0, &ksgui::Control `RTTI Type Descriptor', &ksgui::Form `RTTI Type Descriptor', 0) )
    this->sim->gameScreen->addControl(this->sim->gameScreen, c, 1);
  return this->controls._Mylast - this->controls._Myfirst;
}
int PythonInterface::addPythonListBoxDeselectionElementListener(PythonInterface *this, int index, _object *ob)
{
  ksgui::Control *v4; // eax
  Event<ksgui::OnListBoxItemClickedEvent> *v5; // eax
  std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> v7; // [esp-1Ch] [ebp-34h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  if ( index && index <= (unsigned int)(this->controls._Mylast - this->controls._Myfirst) )
  {
    v4 = this->controls._Myfirst[index - 1];
  }
  else
  {
    _printf("ERROR: [PYI ERROR]: Control index %d out of range\n", index);
    v4 = 0;
  }
  v5 = (Event<ksgui::OnListBoxItemClickedEvent> *)__RTDynamicCast(
                                                    v4,
                                                    0,
                                                    &ksgui::Control `RTTI Type Descriptor',
                                                    &ksgui::ListBox `RTTI Type Descriptor',
                                                    0);
  if ( !v5 )
    return 0;
  v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_2e66fc190c6ffff5422e44aa2062ac48_,0>,std::allocator<std::_Func_class<void,ksgui::OnListBoxItemClickedEvent const &>>,void,ksgui::OnListBoxItemClickedEvent const &>::`vftable';
  v7._Impl = (std::_Func_base<void,ksgui::OnListBoxItemClickedEvent const &> *)&v7;
  v8 = -1;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(v5 + 25, v7, this);
  return 1;
}
int PythonInterface::addPythonListBoxElementListener(PythonInterface *this, int index, _object *ob)
{
  ksgui::Control *v4; // eax
  Event<ksgui::OnListBoxItemClickedEvent> *v5; // eax
  std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> v7; // [esp-1Ch] [ebp-34h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  if ( index && index <= (unsigned int)(this->controls._Mylast - this->controls._Myfirst) )
  {
    v4 = this->controls._Myfirst[index - 1];
  }
  else
  {
    _printf("ERROR: [PYI ERROR]: Control index %d out of range\n", index);
    v4 = 0;
  }
  v5 = (Event<ksgui::OnListBoxItemClickedEvent> *)__RTDynamicCast(
                                                    v4,
                                                    0,
                                                    &ksgui::Control `RTTI Type Descriptor',
                                                    &ksgui::ListBox `RTTI Type Descriptor',
                                                    0);
  if ( !v5 )
    return 0;
  v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_d59c1b0b8505012419449fc7aa472c96_,0>,std::allocator<std::_Func_class<void,ksgui::OnListBoxItemClickedEvent const &>>,void,ksgui::OnListBoxItemClickedEvent const &>::`vftable';
  v7._Impl = (std::_Func_base<void,ksgui::OnListBoxItemClickedEvent const &> *)&v7;
  v8 = -1;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler(v5 + 24, v7, this);
  return 1;
}
int PythonInterface::addPythonOnAppActivatedListener(PythonInterface *this, int index, _object *ob)
{
  ksgui::Control *v4; // eax
  ksgui::Form *v5; // eax
  std::function<void __cdecl(OnMouseWheelMovedEvent const &)> v7; // [esp-1Ch] [ebp-30h] BYREF
  PythonInterface *v8; // [esp-4h] [ebp-18h]
  PythonInterface::addPythonOnAppActivatedListener::__l9::<lambda_c9ea1a271e816ef3b99dbad5e0c17716> _Func; // [esp+8h] [ebp-Ch] BYREF

  if ( index && index <= (unsigned int)(this->controls._Mylast - this->controls._Myfirst) )
  {
    v4 = this->controls._Myfirst[index - 1];
  }
  else
  {
    _printf("ERROR: [PYI ERROR]: Control index %d out of range\n", index);
    v4 = 0;
  }
  v5 = (ksgui::Form *)__RTDynamicCast(
                        v4,
                        0,
                        &ksgui::Control `RTTI Type Descriptor',
                        &ksgui::Form `RTTI Type Descriptor',
                        0);
  if ( !v5 )
    return 0;
  v8 = this;
  _Func.c = v5;
  _Func.ob = ob;
  _Func.index = index;
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v7,
    &_Func);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->sim->game->gui->taskbar->evAppOpened,
    v7,
    v8);
  return 1;
}
int PythonInterface::addPythonOnAppDismissedListener(PythonInterface *this, int index, _object *ob)
{
  ksgui::Control *v4; // eax
  ksgui::Form *v5; // eax
  std::function<void __cdecl(OnMouseWheelMovedEvent const &)> v7; // [esp-1Ch] [ebp-30h] BYREF
  PythonInterface *v8; // [esp-4h] [ebp-18h]
  PythonInterface::addPythonOnAppDismissedListener::__l9::<lambda_51fb2bdb3a92d1d62a0bbd8b197acfe4> _Func; // [esp+8h] [ebp-Ch] BYREF

  if ( index && index <= (unsigned int)(this->controls._Mylast - this->controls._Myfirst) )
  {
    v4 = this->controls._Myfirst[index - 1];
  }
  else
  {
    _printf("ERROR: [PYI ERROR]: Control index %d out of range\n", index);
    v4 = 0;
  }
  v5 = (ksgui::Form *)__RTDynamicCast(
                        v4,
                        0,
                        &ksgui::Control `RTTI Type Descriptor',
                        &ksgui::Form `RTTI Type Descriptor',
                        0);
  if ( !v5 )
    return 0;
  v8 = this;
  _Func.c = v5;
  _Func.ob = ob;
  _Func.index = index;
  std::function<void __cdecl (ksgui::OnControlClicked const &)>::function<void __cdecl (ksgui::OnControlClicked const &)>(
    (std::function<void __cdecl(ksgui::OnControlClicked const &)> *)&v7,
    &_Func);
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->sim->game->gui->taskbar->evAppDismiss,
    v7,
    v8);
  return 1;
}
int PythonInterface::addPythonOnCheckBoxChanged(PythonInterface *this, int index, _object *ob)
{
  ksgui::Control *v4; // eax
  int v5; // edx
  std::function<void __cdecl(ksgui::OnListBoxItemClickedEvent const &)> v7; // [esp-1Ch] [ebp-34h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  if ( index && index <= (unsigned int)(this->controls._Mylast - this->controls._Myfirst) )
  {
    v4 = this->controls._Myfirst[index - 1];
  }
  else
  {
    _printf("ERROR: [PYI ERROR]: Control index %d out of range\n", index);
    v4 = 0;
  }
  v5 = __RTDynamicCast(v4, 0, &ksgui::Control `RTTI Type Descriptor', &ksgui::CheckBox `RTTI Type Descriptor', 0);
  if ( !v5 )
    return 0;
  v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_b6af65a366bc45ff390e092ba6c9c936_,0>,std::allocator<std::_Func_class<void,ksgui::OnCheckBoxChanged const &>>,void,ksgui::OnCheckBoxChanged const &>::`vftable';
  v7._Space._Pfn[1] = (void (__cdecl *)())ob;
  v7._Impl = (std::_Func_base<void,ksgui::OnListBoxItemClickedEvent const &> *)&v7;
  v8 = -1;
  Event<ksgui::OnListBoxItemClickedEvent>::addHandler((Event<ksgui::OnListBoxItemClickedEvent> *)(v5 + 280), v7, this);
  return 1;
}
int PythonInterface::addPythonOnClickedListener(PythonInterface *this, int index, _object *ob)
{
  Event<OnMouseWheelMovedEvent> *v3; // edx
  std::function<void __cdecl(OnMouseWheelMovedEvent const &)> v5; // [esp-1Ch] [ebp-30h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  if ( index && index <= (unsigned int)(this->controls._Mylast - this->controls._Myfirst) )
  {
    v3 = (Event<OnMouseWheelMovedEvent> *)this->controls._Myfirst[index - 1];
    if ( v3 )
    {
      v5._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_92e6a6a1c5acd91b0a061260eca2c5b7_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
      v5._Space._Pfn[1] = (void (__cdecl *)())ob;
      v5._Impl = (std::_Func_base<void,OnMouseWheelMovedEvent const &> *)&v5;
      v6 = -1;
      Event<ksgui::OnControlClicked>::addHandler(v3 + 13, v5, this);
      return 1;
    }
  }
  else
  {
    _printf("ERROR: [PYI ERROR]: Control index %d out of range\n", index);
  }
  return 0;
}
int PythonInterface::addPythonOnValidatedListener(PythonInterface *this, int index, _object *ob)
{
  ksgui::Control *v4; // eax
  Event<OnPhysicsStepCompleted> *v5; // eax
  std::function<void __cdecl(OnPhysicsStepCompleted const &)> v7; // [esp-1Ch] [ebp-34h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  if ( index && index <= (unsigned int)(this->controls._Mylast - this->controls._Myfirst) )
  {
    v4 = this->controls._Myfirst[index - 1];
  }
  else
  {
    _printf("ERROR: [PYI ERROR]: Control index %d out of range\n", index);
    v4 = 0;
  }
  v5 = (Event<OnPhysicsStepCompleted> *)__RTDynamicCast(
                                          v4,
                                          0,
                                          &ksgui::Control `RTTI Type Descriptor',
                                          &ksgui::TextInput `RTTI Type Descriptor',
                                          0);
  if ( !v5 )
    return 0;
  v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_6532acc743d418472b2894fb03637669_,0>,std::allocator<std::_Func_class<void,std::wstring const &>>,void,std::wstring const &>::`vftable';
  *(_QWORD *)&v7._Space._Alias[4] = __PAIR64__((unsigned int)v5, (unsigned int)ob);
  v7._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v7;
  v8 = -1;
  Event<std::wstring>::addHandler(v5 + 26, v7, this);
  return 1;
}
int PythonInterface::addPythonOnValueChangedListener(PythonInterface *this, int index, _object *ob)
{
  ksgui::Control *v4; // eax
  Event<OnPhysicsStepCompleted> *v5; // edx
  std::function<void __cdecl(OnPhysicsStepCompleted const &)> v7; // [esp-1Ch] [ebp-34h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  if ( index && index <= (unsigned int)(this->controls._Mylast - this->controls._Myfirst) )
  {
    v4 = this->controls._Myfirst[index - 1];
  }
  else
  {
    _printf("ERROR: [PYI ERROR]: Control index %d out of range\n", index);
    v4 = 0;
  }
  v5 = (Event<OnPhysicsStepCompleted> *)__RTDynamicCast(
                                          v4,
                                          0,
                                          &ksgui::Control `RTTI Type Descriptor',
                                          &ksgui::Spinner `RTTI Type Descriptor',
                                          0);
  if ( !v5 )
    return 0;
  v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_44b5ac47c068dd6558d7c817ed79d7b9_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  v7._Space._Pfn[1] = (void (__cdecl *)())ob;
  v7._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v7;
  v8 = -1;
  Event<std::wstring>::addHandler(v5 + 25, v7, this);
  return 1;
}
ksgui::Control *PythonInterface::getControl(PythonInterface *this, unsigned int index)
{
  if ( index && index <= this->controls._Mylast - this->controls._Myfirst )
    return this->controls._Myfirst[index - 1];
  _printf("ERROR: [PYI ERROR]: Control index %d out of range\n", index);
  return 0;
}
int __userpurge PythonInterface::getTexture@<eax>(PythonInterface *this@<ecx>, unsigned int a2@<ebx>, std::wstring t)
{
  __int64 v4; // rax
  int v5; // esi
  Texture nt; // [esp+8h] [ebp-2Ch] BYREF
  int v8; // [esp+30h] [ebp-4h]

  v8 = 0;
  if ( Path::fileExists(a2, &t, 0) )
  {
    ResourceStore::getTexture(this->game->graphics->resourceStore._Myptr, &nt, &t, 0);
    LOBYTE(v8) = 1;
    std::vector<Texture>::push_back(&this->textures, &nt);
    v4 = 2454267027i64 * ((char *)this->textures._Mylast - (char *)this->textures._Myfirst);
    LOBYTE(v8) = 0;
    v5 = (SHIDWORD(v4) >> 4) + (HIDWORD(v4) >> 31);
    OnSetupAppCreated::~OnSetupAppCreated(&nt);
  }
  else
  {
    v5 = 0;
  }
  if ( t._Myres >= 8 )
    operator delete(t._Bx._Ptr);
  return v5;
}
Texture *PythonInterface::getTextureByIndex(PythonInterface *this, Texture *result, unsigned int index)
{
  Texture *v3; // edx
  Texture *v4; // eax

  if ( index && index <= this->textures._Mylast - this->textures._Myfirst )
  {
    v3 = &this->textures._Myfirst[index];
    result->kid = v3[-1].kid;
    result->fileName._Myres = 7;
    result->fileName._Mysize = 0;
    result->fileName._Bx._Buf[0] = 0;
    std::wstring::assign(&result->fileName, &v3[-1].fileName, 0, 0xFFFFFFFF);
    v4 = result;
  }
  else
  {
    _printf("ERROR: [PYI ERROR]: Texture index %d out of range\n", index);
    v4 = result;
    result->kid = 0;
    result->fileName._Myres = 7;
    result->fileName._Mysize = 0;
    result->fileName._Bx._Buf[0] = 0;
  }
  return v4;
}
