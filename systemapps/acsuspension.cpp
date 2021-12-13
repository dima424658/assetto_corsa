#include "acsuspension.h"
void ACSuspension::ACSuspension(ACSuspension *this, CarAvatar *icar)
{
  char v3; // bl
  const std::wstring *v4; // eax
  ksgui::Control *v5; // esi
  ksgui::Control *v6; // eax
  ksgui::Control *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  ksgui::Control **v13; // eax
  std::vector<ksgui::Control *> *v14; // esi
  ksgui::Control *v15; // ebp
  int v16; // ebx
  ksgui::Control **v17; // ecx
  ksgui::Control **v18; // eax
  ksgui::ProgressBar **v19; // ebp
  ksgui::ProgressBar *v20; // ebx
  int v21; // eax
  int v22; // ebx
  ksgui::Control **v23; // ecx
  ksgui::Control **v24; // ebp
  ksgui::Control **v25; // edx
  int v26; // ecx
  unsigned int v27; // edx
  unsigned int v28; // edx
  ksgui::Control **v29; // ecx
  ksgui::Control **v30; // edx
  int v31; // ecx
  unsigned int v32; // edx
  unsigned int v33; // edx
  ksgui::Control **v34; // eax
  ksgui::ProgressBar **v35; // ebp
  ksgui::ProgressBar *v36; // eax
  ksgui::ProgressBar *v37; // eax
  ksgui::ProgressBar *v38; // ecx
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  ksgui::ProgressBar *v44; // ecx
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  ksgui::ProgressBar *v50; // ecx
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  ksgui::ProgressBar *v56; // ecx
  float v57; // xmm0_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm2_4
  ksgui::GUI *v62; // eax
  std::_Ref_count_base *v63; // edx
  Font *v64; // ebx
  std::_Ref_count_base *v65; // esi
  std::wstring *v66; // eax
  const std::wstring *v67; // eax
  vec3f *v68; // eax
  bool v69; // cf
  float *v70; // ecx
  int v71; // edx
  unsigned int v72; // esi
  _BYTE v73[28]; // [esp-8h] [ebp-118h] BYREF
  float h; // [esp+14h] [ebp-FCh]
  unsigned int _Count; // [esp+34h] [ebp-DCh]
  ksgui::ProgressBar **v76; // [esp+38h] [ebp-D8h]
  int v77; // [esp+3Ch] [ebp-D4h]
  int v78; // [esp+40h] [ebp-D0h] BYREF
  ksgui::Control *v79; // [esp+44h] [ebp-CCh] BYREF
  int v80; // [esp+48h] [ebp-C8h]
  ACSuspension *v81; // [esp+4Ch] [ebp-C4h]
  vec3f v82; // [esp+50h] [ebp-C0h] BYREF
  std::wstring text; // [esp+5Ch] [ebp-B4h] BYREF
  std::wstring result; // [esp+74h] [ebp-9Ch] BYREF
  std::wstring v85; // [esp+8Ch] [ebp-84h] BYREF
  std::wstring v86; // [esp+A4h] [ebp-6Ch] BYREF
  INIReader carINI; // [esp+BCh] [ebp-54h] BYREF
  int v88; // [esp+10Ch] [ebp-4h]

  v3 = 0;
  v76 = 0;
  h = 0.0;
  v81 = this;
  *(_DWORD *)&v73[24] = icar->sim->game->gui;
  *(_DWORD *)&v73[20] = 7;
  *(_DWORD *)&v73[16] = 0;
  *(_WORD *)v73 = 0;
  std::wstring::assign((std::wstring *)v73, L"ACSuspension", 0xCu);
  ksgui::Form::Form(this, 0, *(std::wstring *)v73, *(ksgui::GUI **)&v73[24], SLOBYTE(h));
  LODWORD(h) = dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart;
  *(_DWORD *)&v73[24] = Trigger::Trigger;
  *(_DWORD *)&v73[20] = 4;
  *(_DWORD *)&v73[16] = 12;
  v88 = 0;
  *(_DWORD *)&v73[12] = this->renderWheelsTrigger;
  this->__vftable = (ACSuspension_vtbl *)&ACSuspension::`vftable';
  this->renderFuelTankPosition = 1;
  `eh vector constructor iterator'(
    *(void **)&v73[12],
    *(unsigned int *)&v73[16],
    *(int *)&v73[20],
    *(void (**)(void *))&v73[24],
    (void (*)(void *))LODWORD(h));
  LOBYTE(v88) = 1;
  Trigger::Trigger(&this->renderSuspensionsTrigger);
  LOBYTE(v88) = 2;
  Trigger::Trigger(&this->renderFuelTankPositionTrigger);
  LOBYTE(v88) = 3;
  LODWORD(h) = 400;
  this->fuelTankPosition.x = 0.0;
  this->fuelTankPosition.y = 0.0;
  this->fuelTankPosition.z = 0.0;
  std::vector<float>::vector<float>(&this->rearBumpSteer, LODWORD(h));
  LOBYTE(v88) = 4;
  this->isRecordingTempRun = 0;
  if ( !susGL )
    susGL = GraphicsManager::createGLRenderer(icar->game->graphics, 0x200u);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Suspensions", 0xBu);
  LOBYTE(v88) = 5;
  v4 = acTranslate(&result, &text);
  LOBYTE(v88) = 6;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  LODWORD(h) = this;
  *(_DWORD *)this->renderWheels = 0;
  this->renderSuspensions = 1;
  this->car = icar;
  *(_DWORD *)&v73[4] = &std::_Func_impl<std::_Callable_obj<_lambda_ccf398edd801b4dbe719b812bb0fca8e_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&v73[8] = this;
  *(_DWORD *)&v73[20] = &v73[4];
  LOBYTE(v88) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->car->sim->renderFinishedNodeEvent->evOnRender,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v73[4],
    (void *)LODWORD(h));
  ksgui::Form::setSize(this, 500.0, 700.0);
  v5 = (ksgui::Control *)operator new(0x118u);
  _Count = (unsigned int)v5;
  v6 = 0;
  LOBYTE(v88) = 8;
  if ( v5 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"TEMP_RUN", 8u);
    LOBYTE(v88) = 9;
    h = *(float *)&this->gui;
    v3 = 1;
    v76 = (ksgui::ProgressBar **)1;
    ksgui::Control::Control(v5, &text, (ksgui::GUI *)LODWORD(h));
  }
  this->butStartTempRun = v6;
  v88 = 4;
  if ( (v3 & 1) != 0 && text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  ((void (*)(ksgui::Control *, int, int))this->butStartTempRun->setSize)(
    this->butStartTempRun,
    1128792064,
    1101004800);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Start TempRun", 0xDu);
  LOBYTE(v88) = 11;
  this->butStartTempRun->setText(this->butStartTempRun, &text);
  LOBYTE(v88) = 4;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v7 = this->butStartTempRun;
  v8 = v7->rectBase.left;
  v9 = v7->rect.right - v7->rect.left;
  v10 = v7->rect.bottom - v7->rect.top;
  v7->rect.top = 680.0;
  v7->rect.left = 10.0;
  v11 = v9 + 10.0;
  v12 = v10 + 680.0;
  v7->rect.right = v11;
  v7->rect.bottom = v12;
  if ( v8 == 0.0 && v7->rectBase.top == 0.0 )
  {
    v7->rectBase.left = 10.0;
    v7->rectBase.top = 680.0;
    v7->rectBase.right = v11;
    v7->rectBase.bottom = v12;
  }
  v13 = this->controls._Mylast;
  v14 = &this->controls;
  v15 = this->butStartTempRun;
  v79 = v15;
  if ( &v79 >= v13 || v14->_Myfirst > &v79 )
  {
    if ( v13 == this->controls._Myend )
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
    v18 = this->controls._Mylast;
    if ( v18 )
      *v18 = v15;
  }
  else
  {
    v16 = &v79 - v14->_Myfirst;
    if ( v13 == this->controls._Myend )
      std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)&this->controls, 1u);
    v17 = this->controls._Mylast;
    if ( v17 )
      *v17 = v14->_Myfirst[v16];
  }
  ++this->controls._Mylast;
  LODWORD(h) = this;
  v15->parent = this;
  *(_DWORD *)&v73[4] = &std::_Func_impl<std::_Callable_obj<_lambda_9efbbb5595438b541c9fda0e3a65385b_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v73[8] = this;
  *(_DWORD *)&v73[20] = &v73[4];
  LOBYTE(v88) = 4;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)&this->butStartTempRun->evClicked,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v73[4],
    (void *)LODWORD(h));
  v80 = 0;
  v19 = this->prgSlipFactor;
  v76 = this->prgSlipFactor;
  do
  {
    v20 = (ksgui::ProgressBar *)operator new(0x128u);
    _Count = (unsigned int)v20;
    LOBYTE(v88) = 13;
    if ( v20 )
    {
      h = *(float *)&this->gui;
      *(_DWORD *)&v73[24] = 7;
      *(_DWORD *)&v73[20] = 0;
      *(_WORD *)&v73[4] = 0;
      std::wstring::assign((std::wstring *)&v73[4], L"PRG1", 4u);
      ksgui::ProgressBar::ProgressBar(v20, *(std::wstring *)&v73[4], (ksgui::GUI *)LODWORD(h));
      v22 = v21;
      v77 = v21;
    }
    else
    {
      v22 = 0;
      v77 = 0;
    }
    LOBYTE(v88) = 4;
    *v19 = (ksgui::ProgressBar *)v22;
    v23 = this->controls._Mylast;
    v78 = v22;
    if ( &v78 >= (int *)v23 || (v24 = v14->_Myfirst, v14->_Myfirst > (ksgui::Control **)&v78) )
    {
      v30 = this->controls._Myend;
      if ( v23 == v30 && !(v30 - v23) )
      {
        v31 = v23 - v14->_Myfirst;
        if ( v31 == 0x3FFFFFFF )
LABEL_89:
          std::_Xlength_error("vector<T> too long");
        v32 = v30 - v14->_Myfirst;
        _Count = v31 + 1;
        if ( 0x3FFFFFFF - (v32 >> 1) >= v32 )
          v33 = (v32 >> 1) + v32;
        else
          v33 = 0;
        if ( v33 < _Count )
          v33 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&this->controls, v33);
      }
      v34 = this->controls._Mylast;
      if ( v34 )
        *v34 = (ksgui::Control *)v22;
    }
    else
    {
      v25 = this->controls._Myend;
      if ( v23 == v25 && !(v25 - v23) )
      {
        v26 = v23 - v24;
        if ( v26 == 0x3FFFFFFF )
          goto LABEL_89;
        v27 = v25 - v24;
        _Count = v26 + 1;
        if ( 0x3FFFFFFF - (v27 >> 1) >= v27 )
          v28 = (v27 >> 1) + v27;
        else
          v28 = 0;
        if ( v28 < _Count )
          v28 = _Count;
        std::vector<ksgui::CustomSpinner *>::_Reallocate((std::vector<ksgui::CustomSpinner *> *)&this->controls, v28);
      }
      v29 = this->controls._Mylast;
      if ( v29 )
        *v29 = v14->_Myfirst[((char *)&v78 - (char *)v24) >> 2];
      v22 = v77;
    }
    ++this->controls._Mylast;
    v35 = v76;
    *(_DWORD *)(v22 + 148) = this;
    h = 10.0;
    v36 = *v35;
    *(_DWORD *)&v73[24] = 1114636288;
    v36->minValue = 0.0;
    (*v35)->maxValue = 1.0;
    ((void (*)(ksgui::ProgressBar *, _DWORD, _DWORD))(*v35)->setSize)(*v35, *(_DWORD *)&v73[24], LODWORD(h));
    v37 = *v35;
    v19 = v35 + 1;
    v76 = v19;
    v37->isVertical = 0;
    ++v80;
  }
  while ( v80 < 4 );
  v38 = this->prgSlipFactor[0];
  v39 = v38->rectBase.left;
  v40 = v38->rect.right - v38->rect.left;
  v41 = v38->rect.bottom - v38->rect.top;
  v38->rect.top = 240.0;
  v38->rect.left = 20.0;
  v42 = v40 + 20.0;
  v43 = v41 + 240.0;
  v38->rect.right = v42;
  v38->rect.bottom = v43;
  if ( v39 == 0.0 && v38->rectBase.top == 0.0 )
  {
    v38->rectBase.left = 20.0;
    v38->rectBase.top = 240.0;
    v38->rectBase.right = v42;
    v38->rectBase.bottom = v43;
  }
  v44 = this->prgSlipFactor[1];
  v45 = v44->rectBase.left;
  v46 = v44->rect.right - v44->rect.left;
  v47 = v44->rect.bottom - v44->rect.top;
  v44->rect.top = 240.0;
  v44->rect.left = 420.0;
  v48 = v46 + 420.0;
  v49 = v47 + 240.0;
  v44->rect.right = v48;
  v44->rect.bottom = v49;
  if ( v45 == 0.0 && v44->rectBase.top == 0.0 )
  {
    v44->rectBase.left = 420.0;
    v44->rectBase.top = 240.0;
    v44->rectBase.right = v48;
    v44->rectBase.bottom = v49;
  }
  v50 = this->prgSlipFactor[2];
  v51 = v50->rectBase.left;
  v52 = v50->rect.right - v50->rect.left;
  v53 = v50->rect.bottom - v50->rect.top;
  v50->rect.top = 260.0;
  v50->rect.left = 20.0;
  v54 = v52 + 20.0;
  v55 = v53 + 260.0;
  v50->rect.right = v54;
  v50->rect.bottom = v55;
  if ( v51 == 0.0 && v50->rectBase.top == 0.0 )
  {
    v50->rectBase.left = 20.0;
    v50->rectBase.top = 260.0;
    v50->rectBase.right = v54;
    v50->rectBase.bottom = v55;
  }
  v56 = this->prgSlipFactor[3];
  v57 = v56->rectBase.left;
  v58 = v56->rect.right - v56->rect.left;
  v59 = v56->rect.bottom - v56->rect.top;
  v56->rect.top = 260.0;
  v56->rect.left = 420.0;
  v60 = v58 + 420.0;
  v61 = v59 + 260.0;
  v56->rect.right = v60;
  v56->rect.bottom = v61;
  if ( v57 == 0.0 && v56->rectBase.top == 0.0 )
  {
    v56->rectBase.left = 420.0;
    v56->rectBase.top = 260.0;
    v56->rectBase.right = v60;
    v56->rectBase.bottom = v61;
  }
  v62 = this->gui;
  v63 = v62->font._Rep;
  v64 = v62->font._Ptr;
  if ( v63 )
    _InterlockedExchangeAdd((volatile signed __int32 *)&v63->_Uses, 1u);
  v65 = this->font._Rep;
  this->font._Rep = v63;
  this->font._Ptr = v64;
  if ( v65 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v65->_Uses, 0xFFFFFFFF) )
    {
      v65->_Destroy(v65);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v65->_Weaks) )
        v65->_Delete_this(v65);
    }
  }
  v66 = std::operator+<wchar_t>(&v85, L"content/cars/", &this->car->unixName);
  LOBYTE(v88) = 14;
  v67 = std::operator+<wchar_t>(&v86, v66, L"/data/car.ini");
  LOBYTE(v88) = 15;
  CarAvatar::openINI(this->car, &carINI, v67);
  if ( v86._Myres >= 8 )
    operator delete(v86._Bx._Ptr);
  v86._Myres = 7;
  v86._Mysize = 0;
  v86._Bx._Buf[0] = 0;
  LOBYTE(v88) = 18;
  if ( v85._Myres >= 8 )
    operator delete(v85._Bx._Ptr);
  v85._Myres = 7;
  v85._Mysize = 0;
  v85._Bx._Buf[0] = 0;
  if ( carINI.ready )
  {
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, L"POSITION", 8u);
    LOBYTE(v88) = 19;
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"FUELTANK", 8u);
    LOBYTE(v88) = 20;
    v68 = INIReader::getFloat3(&carINI, &v82, &text, &result);
    v69 = text._Myres < 8;
    this->fuelTankPosition = *v68;
    if ( !v69 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  v70 = this->rearBumpSteer._Myfirst;
  v71 = 0;
  v72 = (unsigned int)((char *)this->rearBumpSteer._Mylast - (char *)v70 + 3) >> 2;
  if ( v70 > this->rearBumpSteer._Mylast )
    v72 = 0;
  if ( v72 )
  {
    do
    {
      ++v71;
      *v70++ = 0.0;
    }
    while ( v71 != v72 );
  }
  LOBYTE(v88) = 4;
  INIReader::~INIReader(&carINI);
}
ACSuspension *ACSuspension::`vector deleting destructor'(ACSuspension *this, unsigned int a2)
{
  ACSuspension::~ACSuspension(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACSuspension::~ACSuspension(ACSuspension *this)
{
  this->__vftable = (ACSuspension_vtbl *)&ACSuspension::`vftable';
  if ( this->rearBumpSteer._Myfirst )
  {
    operator delete(this->rearBumpSteer._Myfirst);
    this->rearBumpSteer._Myfirst = 0;
    this->rearBumpSteer._Mylast = 0;
    this->rearBumpSteer._Myend = 0;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->renderFuelTankPositionTrigger);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->renderSuspensionsTrigger);
  `eh vector destructor iterator'(
    this->renderWheelsTrigger,
    0xCu,
    4,
    (void (*)(void *))dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart);
  this->__vftable = (ACSuspension_vtbl *)&ksgui::Form::`vftable';
  ksgui::Control::~Control(this);
}
void __userpurge ACSuspension::render(ACSuspension *this@<ecx>, int a2@<esi>, float dt)
{
  ACSuspension *v3; // edi
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  GLRenderer *v6; // esi
  __m128 v7; // xmm0
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  int v10; // eax
  const std::wstring *v11; // eax
  CarAvatar *v12; // ecx
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  int v15; // eax
  std::wostream *v16; // eax
  std::wostream *v17; // eax
  std::wostream *v18; // eax
  std::wostream *v19; // eax
  std::wostream *v20; // eax
  std::wostream *v21; // eax
  std::wostream *v22; // eax
  const std::wstring *v23; // eax
  ACSuspension *v24; // ecx
  Node *v25; // esi
  Node *v26; // edi
  Node *v27; // ebx
  Node_vtbl *v28; // edx
  int v29; // xmm0_4
  CarAvatar *v30; // eax
  float v31; // xmm0_4
  Node_vtbl *v32; // eax
  int v33; // xmm0_4
  CarAvatar *v34; // eax
  int v35; // xmm0_4
  Node_vtbl *v36; // eax
  CarAvatar *v37; // eax
  float *v38; // eax
  float v39; // xmm0_4
  float v40; // xmm2_4
  std::wostream *v41; // eax
  std::wostream *v42; // eax
  std::wostream *v43; // eax
  std::wostream *v44; // eax
  std::wostream *v45; // eax
  std::wostream *v46; // eax
  std::wostream *v47; // eax
  std::wostream *v48; // eax
  const std::wstring *v49; // eax
  std::wstring *v50; // eax
  Node *v51; // esi
  Node *v52; // edi
  Node *v53; // ebx
  Node_vtbl *v54; // edx
  CarAvatar *v55; // eax
  float *v56; // eax
  float v57; // xmm2_4
  float v58; // xmm1_4
  std::wostream *v59; // eax
  std::wostream *v60; // eax
  std::wostream *v61; // eax
  std::wostream *v62; // eax
  std::wostream *v63; // eax
  std::wostream *v64; // eax
  std::wostream *v65; // eax
  std::wostream *v66; // eax
  const std::wstring *v67; // eax
  std::wstring *v68; // eax
  Node *v69; // esi
  Node *v70; // edi
  Node *v71; // ebx
  Node_vtbl *v72; // edx
  CarAvatar *v73; // eax
  float v74; // xmm0_4
  int v75; // eax
  float *v76; // eax
  float v77; // xmm2_4
  float v78; // xmm1_4
  std::wostream *v79; // eax
  std::wostream *v80; // eax
  std::wostream *v81; // eax
  std::wostream *v82; // eax
  std::wostream *v83; // eax
  std::wostream *v84; // eax
  std::wostream *v85; // eax
  std::wostream *v86; // eax
  const std::wstring *v87; // eax
  std::wstring *v88; // eax
  Node *v89; // esi
  Node *v90; // edi
  Node *v91; // ebx
  Node_vtbl *v92; // edx
  CarAvatar *v93; // eax
  float v94; // xmm0_4
  int v95; // eax
  float *v96; // eax
  float v97; // xmm0_4
  float v98; // xmm2_4
  std::wostream *v99; // eax
  std::wostream *v100; // eax
  std::wostream *v101; // eax
  std::wostream *v102; // eax
  std::wostream *v103; // eax
  std::wostream *v104; // eax
  std::wostream *v105; // eax
  std::wostream *v106; // eax
  const std::wstring *v107; // eax
  std::wstring *v108; // eax
  char *v109; // [esp+D8h] [ebp-32Ch]
  char *v110; // [esp+D8h] [ebp-32Ch]
  char *v111; // [esp+D8h] [ebp-32Ch]
  char *v112; // [esp+D8h] [ebp-32Ch]
  vec3f _Val; // [esp+E8h] [ebp-31Ch]
  vec3f _Vala; // [esp+E8h] [ebp-31Ch]
  vec3f _Valb; // [esp+E8h] [ebp-31Ch]
  vec3f _Valc; // [esp+E8h] [ebp-31Ch]
  char *_Vald; // [esp+E8h] [ebp-31Ch]
  char *_Vale; // [esp+E8h] [ebp-31Ch]
  const char *g; // [esp+ECh] [ebp-318h]
  int b; // [esp+F0h] [ebp-314h]
  const char *bd; // [esp+F0h] [ebp-314h]
  int ba; // [esp+F0h] [ebp-314h]
  const char *be; // [esp+F0h] [ebp-314h]
  int bb; // [esp+F0h] [ebp-314h]
  const char *bf; // [esp+F0h] [ebp-314h]
  int bc; // [esp+F0h] [ebp-314h]
  const char *bg; // [esp+F0h] [ebp-314h]
  float v128; // [esp+F4h] [ebp-310h]
  char *v129; // [esp+F4h] [ebp-310h]
  __int64 v130; // [esp+F8h] [ebp-30Ch]
  int v131; // [esp+F8h] [ebp-30Ch]
  int v132; // [esp+F8h] [ebp-30Ch]
  int v133; // [esp+F8h] [ebp-30Ch]
  float v134; // [esp+100h] [ebp-304h]
  float v135; // [esp+110h] [ebp-2F4h]
  std::wstring *_Str; // [esp+118h] [ebp-2ECh]
  unsigned int _Strd; // [esp+118h] [ebp-2ECh]
  float _Stre; // [esp+118h] [ebp-2ECh]
  std::wstring *_Stra; // [esp+118h] [ebp-2ECh]
  std::wstring *_Strb; // [esp+118h] [ebp-2ECh]
  std::wstring *_Strc; // [esp+118h] [ebp-2ECh]
  float v143; // [esp+11Ch] [ebp-2E8h]
  unsigned int v144; // [esp+11Ch] [ebp-2E8h]
  float v145; // [esp+11Ch] [ebp-2E8h]
  float v146; // [esp+120h] [ebp-2E4h]
  Node *v147; // [esp+120h] [ebp-2E4h]
  __m128i basepos; // [esp+124h] [ebp-2E0h] BYREF
  float v149; // [esp+138h] [ebp-2CCh]
  float v150; // [esp+13Ch] [ebp-2C8h]
  float v151; // [esp+140h] [ebp-2C4h]
  float v152; // [esp+144h] [ebp-2C0h]
  float v153; // [esp+148h] [ebp-2BCh]
  __m128i v154; // [esp+14Ch] [ebp-2B8h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > graphicOffset; // [esp+15Ch] [ebp-2A8h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v156; // [esp+20Ch] [ebp-1F8h] BYREF
  mat44f v157; // [esp+2BCh] [ebp-148h] BYREF
  mat44f v158; // [esp+2FCh] [ebp-108h] BYREF
  mat44f v159; // [esp+33Ch] [ebp-C8h] BYREF
  mat44f v160; // [esp+37Ch] [ebp-88h] BYREF
  std::wstring text; // [esp+3BCh] [ebp-48h] BYREF
  std::wstring result; // [esp+3D8h] [ebp-2Ch] BYREF
  int v163; // [esp+400h] [ebp-4h]

  v3 = this;
  ksgui::Control::render(this, (int)this, a2, dt, v130, v134);
  v4 = (__m128)LODWORD(v3->rect.left);
  v5 = (__m128)LODWORD(v3->rect.top);
  v6 = susGL;
  v143 = v4.m128_f32[0];
  v4.m128_f32[0] = v4.m128_f32[0] + 50.0;
  _Str = (std::wstring *)v5.m128_i32[0];
  v5.m128_f32[0] = v5.m128_f32[0] + 150.0;
  v154.m128i_i32[2] = 0;
  basepos.m128i_i64[0] = v4.m128_u64[0];
  *(_QWORD *)&_Val.x = _mm_unpacklo_ps(v4, v5).m128_u64[0];
  _Val.z = 0.0;
  ACSuspension::renderCamber(v3, susGL, _Val, 0);
  v7 = (__m128)LODWORD(v143);
  v7.m128_f32[0] = v143 + 450.0;
  *(_DWORD *)&text._Bx._Alias[8] = 0;
  v154.m128i_i64[0] = v7.m128_u64[0];
  *(_QWORD *)&_Vala.x = _mm_unpacklo_ps(v7, (__m128)v5.m128_u32[0]).m128_u64[0];
  _Vala.z = 0.0;
  ACSuspension::renderCamber(v3, v6, _Vala, 1);
  v8 = (__m128)(unsigned int)_Str;
  v8.m128_f32[0] = *(float *)&_Str + 550.0;
  v9 = (__m128)_mm_loadl_epi64(&basepos);
  *(_DWORD *)&text._Bx._Alias[8] = 0;
  *(_QWORD *)&_Valb.x = _mm_unpacklo_ps(v9, v8).m128_u64[0];
  _Valb.z = 0.0;
  ACSuspension::renderCamber(v3, v6, _Valb, 2);
  v9.m128_u64[0] = _mm_unpacklo_ps((__m128)_mm_loadl_epi64(&v154), (__m128)COERCE_UNSIGNED_INT(*(float *)&_Str + 550.0)).m128_u64[0];
  *(_DWORD *)&text._Bx._Alias[8] = 0;
  *(_QWORD *)&_Valc.x = v9.m128_u64[0];
  _Valc.z = 0.0;
  ACSuspension::renderCamber(v3, v6, _Valc, 3);
  *(_DWORD *)v156.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v156.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v156.gap68);
  basepos.m128i_i32[0] = 1;
  std::wiostream::basic_iostream<wchar_t>(&v156.gap10[4], &v156.gap10[28], 0);
  *(_DWORD *)&v156.gap10[*(_DWORD *)(*(_DWORD *)&v156.gap10[4] + 4) + 4] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v156.gap10[*(_DWORD *)(*(_DWORD *)&v156.gap10[4] + 4)] = *(_DWORD *)(*(_DWORD *)&v156.gap10[4] + 4) - 104;
  std::wstreambuf::wstreambuf(&v156.gap10[28]);
  *(_DWORD *)&v156.gap10[28] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v156.gap60[4] = 0;
  *(_DWORD *)v156.gap68 = 0;
  *(_DWORD *)&v156.gap10[*(_DWORD *)(*(_DWORD *)&v156.gap10[4] + 4) + 24] = *(_DWORD *)&v156.gap10[*(_DWORD *)(*(_DWORD *)&v156.gap10[4] + 4)
                                                                                                 + 24] & 0xFFFFEFFF | 0x2000;
  v10 = std::setprecision(&text._Myres, 1, 0);
  (*(void (__cdecl **)(_BYTE *, _DWORD, _DWORD))v10)(
    &v156.gap10[*(_DWORD *)(*(_DWORD *)&v156.gap10[20] + 4) + 20],
    *(_DWORD *)(v10 + 8),
    *(_DWORD *)(v10 + 12));
  *(_QWORD *)&result._Bx._Alias[8] = 0x700000000i64;
  LOWORD(text._Myres) = 0;
  std::wstring::assign((std::wstring *)&text._Myres, L"CASTER", 6u);
  v11 = acTranslate((std::wstring *)&result._Myres, (const std::wstring *)&text._Myres);
  v12 = v3->car;
  v128 = v12->physicsInfo.kpi.angleRAD * 57.29578;
  _Vald = (char *)LODWORD(v12->physicsInfo.caster);
  v13 = std::operator<<<wchar_t>((std::wostream *)&v156.gap10[20], v11);
  v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, L": ");
  v15 = std::wostream::operator<<(v14, _Vald);
  v16 = (std::wostream *)std::wostream::operator<<(v15);
  v17 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v16, _Vale);
  v18 = (std::wostream *)std::wostream::operator<<(v17, std::endl<wchar_t,std::char_traits<wchar_t>>);
  v19 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v18, g);
  v20 = (std::wostream *)std::wostream::operator<<(v19);
  v21 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v20, "KPI:");
  v22 = (std::wostream *)std::wostream::operator<<(v21, LODWORD(v128));
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v22, v129);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v163) = 3;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  Font::setColor(v3->font._Ptr, 1.0, 1.0, 1.0, 1.0);
  v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v156, &result);
  LOBYTE(v163) = 6;
  Font::blitString(v3->font._Ptr, v143 + 250.0, *(float *)&_Str + 200.0, v23, 1.0, eAlignCenter);
  LOBYTE(v163) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  *(float *)basepos.m128i_i32 = v143 + 250.0;
  *(float *)&basepos.m128i_i32[1] = *(float *)&_Str + 310.0;
  basepos.m128i_i32[2] = 0;
  ACSuspension::drawBumpGraph(v24, v6, (const vec3f *)&basepos, &v3->rearBumpSteer);
  basepos.m128i_i32[2] = 0;
  v146 = v143 + 40.0;
  *(float *)basepos.m128i_i32 = v143 + 40.0;
  *(float *)&basepos.m128i_i32[1] = *(float *)&_Str + 290.0;
  ACSuspension::renderTyreTemp(v3, (const vec3f *)&basepos, 0);
  basepos.m128i_i32[2] = 0;
  *(float *)&v144 = v143 + 320.0;
  basepos.m128i_i32[0] = v144;
  *(float *)&basepos.m128i_i32[1] = *(float *)&_Str + 290.0;
  ACSuspension::renderTyreTemp(v3, (const vec3f *)&basepos, 1);
  *(float *)basepos.m128i_i32 = v146;
  *(float *)&_Strd = *(float *)&_Str + 350.0;
  *(__int64 *)((char *)basepos.m128i_i64 + 4) = _Strd;
  ACSuspension::renderTyreTemp(v3, (const vec3f *)&basepos, 2);
  basepos.m128i_i64[0] = __PAIR64__(_Strd, v144);
  basepos.m128i_i32[2] = 0;
  ACSuspension::renderTyreTemp(v3, (const vec3f *)&basepos, 3);
  Font::setColor(v3->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  *(_DWORD *)graphicOffset.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)graphicOffset.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(graphicOffset.gap68);
  LOBYTE(v163) = 7;
  std::wiostream::basic_iostream<wchar_t>(&graphicOffset, &graphicOffset.gap10[8], 0);
  v163 = 8;
  *(_DWORD *)&graphicOffset.gap0[*(_DWORD *)(*(_DWORD *)graphicOffset.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v154.m128i_i32[3] + *(_DWORD *)(*(_DWORD *)graphicOffset.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)graphicOffset.gap0 + 4)
                                                                                        - 104;
  std::wstreambuf::wstreambuf(&graphicOffset.gap10[8]);
  *(_DWORD *)&graphicOffset.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&graphicOffset.gap10[64] = 0;
  *(_DWORD *)&graphicOffset.gap10[68] = 0;
  LOBYTE(v163) = 10;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Tyre off", 8u);
  LOBYTE(v163) = 11;
  v25 = v3->car->suspensionAvatar->getWheelTransform(v3->car->suspensionAvatar, 0);
  v26 = v3->car->suspensionAvatar->getWheelTransform(v3->car->suspensionAvatar, 0);
  v27 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 0);
  v147 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 0);
  basepos.m128i_i32[0] = (int)acTranslate(&result, &text);
  LOBYTE(v163) = 12;
  v28 = v25->__vftable;
  v152 = this->car->physicsState.tyreMatrix[0].M43;
  v29 = SLODWORD(v28->getWorldMatrix(v25, &v159)->M43);
  v30 = this->car;
  v150 = *(float *)&v29;
  v31 = v30->physicsState.tyreMatrix[0].M42;
  v32 = v26->__vftable;
  v153 = v31;
  v33 = LODWORD(v32->getWorldMatrix(v26, &v157)->M42);
  v34 = this->car;
  v151 = *(float *)&v33;
  v35 = LODWORD(v34->physicsState.tyreMatrix[0].M41);
  v36 = v27->__vftable;
  v154.m128i_i32[0] = v35;
  v149 = v36->getWorldMatrix(v27, &v158)->M41;
  v37 = this->car;
  v135 = v37->physicsState.tyreMatrix[0].M41;
  v145 = v37->physicsState.tyreMatrix[0].M42;
  _Stre = v37->physicsState.tyreMatrix[0].M43;
  v38 = (float *)v147->getWorldMatrix(v147, &v160);
  v39 = 0.0;
  v40 = (float)((float)((float)(v38[12] - v135) * (float)(v38[12] - v135))
              + (float)((float)(v38[13] - v145) * (float)(v38[13] - v145)))
      + (float)((float)(v38[14] - _Stre) * (float)(v38[14] - _Stre));
  if ( v40 != 0.0 )
    v39 = fsqrt(v40);
  v41 = std::operator<<<wchar_t>((std::wostream *)graphicOffset.gap10, (const std::wstring *)basepos.m128i_i32[0]);
  v42 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v41, L"  FL ");
  v43 = (std::wostream *)std::wostream::operator<<(v42, LODWORD(v39));
  v44 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v43, v109);
  v45 = (std::wostream *)std::wostream::operator<<(v44, " : x=");
  v46 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v45, " | z=");
  v47 = (std::wostream *)std::wostream::operator<<(v46, b);
  v48 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v47, bd);
  std::wostream::operator<<(v48, "deg");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v163) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v49 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&graphicOffset, &result);
  LOBYTE(v163) = 13;
  Font::blitString(this->font._Ptr, 10.0, 10.0, v49, 1.0, eAlignLeft);
  LOBYTE(v163) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v163) = 14;
  std::wstringbuf::_Tidy((std::wstringbuf *)&graphicOffset.gap10[8]);
  v50 = &text;
  if ( text._Myres >= 8 )
    v50 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init(
    (std::wstringbuf *)&graphicOffset.gap10[8],
    v50->_Bx._Buf,
    text._Mysize,
    *(int *)&graphicOffset.gap10[68]);
  LOBYTE(v163) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Tyre off", 8u);
  LOBYTE(v163) = 15;
  v51 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 1);
  v52 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 1);
  v53 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 1);
  basepos.m128i_i32[0] = (int)this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 1);
  _Stra = acTranslate(&result, &text);
  LOBYTE(v163) = 16;
  v54 = v51->__vftable;
  v152 = this->car->physicsState.tyreMatrix[1].M43;
  v151 = v54->getWorldMatrix(v51, &v160)->M43;
  v150 = v52->getWorldMatrix(v52, &v158)->M42;
  v53->getWorldMatrix(v53, &v157);
  v55 = this->car;
  v154.m128i_i32[0] = LODWORD(v55->physicsState.tyreMatrix[1].M41);
  v149 = v55->physicsState.tyreMatrix[1].M42;
  v153 = v55->physicsState.tyreMatrix[1].M43;
  v56 = (float *)(*(int (**)(int, mat44f *))(*(_DWORD *)basepos.m128i_i32[0] + 32))(
                   basepos.m128i_i32[0],
                   &v159);
  v57 = (float)((float)((float)(v56[12] - *(float *)v154.m128i_i32) * (float)(v56[12] - *(float *)v154.m128i_i32))
              + (float)((float)(v56[13] - v149) * (float)(v56[13] - v149)))
      + (float)((float)(v56[14] - v153) * (float)(v56[14] - v153));
  if ( v57 == 0.0 )
    v58 = 0.0;
  else
    v58 = fsqrt(v57);
  v59 = std::operator<<<wchar_t>((std::wostream *)graphicOffset.gap10, _Stra);
  v60 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v59, L"  FR ");
  v61 = (std::wostream *)std::wostream::operator<<(v60, LODWORD(v58));
  v62 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v61, v110);
  v63 = (std::wostream *)std::wostream::operator<<(v62, " : x=");
  v64 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v63, " | z=");
  v65 = (std::wostream *)std::wostream::operator<<(v64, ba);
  v66 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v65, be);
  std::wostream::operator<<(v66, v131);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v163) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v67 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&graphicOffset, &result);
  LOBYTE(v163) = 17;
  Font::blitString(this->font._Ptr, 10.0, 30.0, v67, 1.0, eAlignLeft);
  LOBYTE(v163) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v163) = 18;
  std::wstringbuf::_Tidy((std::wstringbuf *)&graphicOffset.gap10[8]);
  v68 = &text;
  if ( text._Myres >= 8 )
    v68 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init(
    (std::wstringbuf *)&graphicOffset.gap10[8],
    v68->_Bx._Buf,
    text._Mysize,
    *(int *)&graphicOffset.gap10[68]);
  LOBYTE(v163) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Tyre off", 8u);
  LOBYTE(v163) = 19;
  v69 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 2);
  v70 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 2);
  v71 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 2);
  basepos.m128i_i32[0] = (int)this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 2);
  _Strb = acTranslate(&result, &text);
  LOBYTE(v163) = 20;
  v72 = v69->__vftable;
  v152 = this->car->physicsState.tyreMatrix[2].M43;
  v151 = v72->getWorldMatrix(v69, &v160)->M43;
  v150 = v70->getWorldMatrix(v70, &v158)->M42;
  v71->getWorldMatrix(v71, &v157);
  v73 = this->car;
  v154.m128i_i32[0] = LODWORD(v73->physicsState.tyreMatrix[2].M41);
  v149 = v73->physicsState.tyreMatrix[2].M42;
  v74 = v73->physicsState.tyreMatrix[2].M43;
  v75 = *(_DWORD *)basepos.m128i_i32[0];
  v153 = v74;
  v76 = (float *)(*(int (**)(int, mat44f *))(v75 + 32))(basepos.m128i_i32[0], &v159);
  v77 = (float)((float)((float)(v76[12] - *(float *)v154.m128i_i32) * (float)(v76[12] - *(float *)v154.m128i_i32))
              + (float)((float)(v76[13] - v149) * (float)(v76[13] - v149)))
      + (float)((float)(v76[14] - v153) * (float)(v76[14] - v153));
  if ( v77 == 0.0 )
    v78 = 0.0;
  else
    v78 = fsqrt(v77);
  v79 = std::operator<<<wchar_t>((std::wostream *)graphicOffset.gap10, _Strb);
  v80 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v79, L"  RL ");
  v81 = (std::wostream *)std::wostream::operator<<(v80, LODWORD(v78));
  v82 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v81, v111);
  v83 = (std::wostream *)std::wostream::operator<<(v82, " : x=");
  v84 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v83, " | z=");
  v85 = (std::wostream *)std::wostream::operator<<(v84, bb);
  v86 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v85, bf);
  std::wostream::operator<<(v86, v132);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v163) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v87 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&graphicOffset, &result);
  LOBYTE(v163) = 21;
  Font::blitString(this->font._Ptr, 10.0, 50.0, v87, 1.0, eAlignLeft);
  LOBYTE(v163) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, word_17BE9D8, 0);
  LOBYTE(v163) = 22;
  std::wstringbuf::_Tidy((std::wstringbuf *)&graphicOffset.gap10[8]);
  v88 = &text;
  if ( text._Myres >= 8 )
    v88 = (std::wstring *)text._Bx._Ptr;
  std::wstringbuf::_Init(
    (std::wstringbuf *)&graphicOffset.gap10[8],
    v88->_Bx._Buf,
    text._Mysize,
    *(int *)&graphicOffset.gap10[68]);
  LOBYTE(v163) = 10;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Tyre off", 8u);
  LOBYTE(v163) = 23;
  v89 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 3);
  v90 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 3);
  v91 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 3);
  basepos.m128i_i32[0] = (int)this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 3);
  _Strc = acTranslate(&result, &text);
  LOBYTE(v163) = 24;
  v92 = v89->__vftable;
  v152 = this->car->physicsState.tyreMatrix[3].M43;
  v151 = v92->getWorldMatrix(v89, &v160)->M43;
  v150 = v90->getWorldMatrix(v90, &v158)->M42;
  v91->getWorldMatrix(v91, &v157);
  v93 = this->car;
  v154.m128i_i32[0] = LODWORD(v93->physicsState.tyreMatrix[3].M41);
  v149 = v93->physicsState.tyreMatrix[3].M42;
  v94 = v93->physicsState.tyreMatrix[3].M43;
  v95 = *(_DWORD *)basepos.m128i_i32[0];
  v153 = v94;
  v96 = (float *)(*(int (**)(int, mat44f *))(v95 + 32))(basepos.m128i_i32[0], &v159);
  v97 = 0.0;
  v98 = (float)((float)((float)(v96[12] - *(float *)v154.m128i_i32) * (float)(v96[12] - *(float *)v154.m128i_i32))
              + (float)((float)(v96[13] - v149) * (float)(v96[13] - v149)))
      + (float)((float)(v96[14] - v153) * (float)(v96[14] - v153));
  if ( v98 != 0.0 )
    v97 = fsqrt(v98);
  v99 = std::operator<<<wchar_t>((std::wostream *)graphicOffset.gap10, _Strc);
  v100 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v99, L"  RR ");
  v101 = (std::wostream *)std::wostream::operator<<(v100, LODWORD(v97));
  v102 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v101, v112);
  v103 = (std::wostream *)std::wostream::operator<<(v102, " : x=");
  v104 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v103, " | z=");
  v105 = (std::wostream *)std::wostream::operator<<(v104, bc);
  v106 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v105, bg);
  std::wostream::operator<<(v106, v133);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v163) = 10;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  v107 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
           &graphicOffset,
           &result);
  LOBYTE(v163) = 25;
  Font::blitString(this->font._Ptr, 10.0, 70.0, v107, 1.0, eAlignLeft);
  LOBYTE(v163) = 10;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::wstring::wstring(&result, word_17BE9D8);
  LOBYTE(v163) = 26;
  std::wstringbuf::_Tidy((std::wstringbuf *)&graphicOffset.gap10[8]);
  v108 = &result;
  if ( result._Myres >= 8 )
    v108 = (std::wstring *)result._Bx._Ptr;
  std::wstringbuf::_Init(
    (std::wstringbuf *)&graphicOffset.gap10[8],
    v108->_Bx._Buf,
    result._Mysize,
    *(int *)&graphicOffset.gap10[68]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&graphicOffset);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v156);
}
void ACSuspension::renderWireframe(ACSuspension *this)
{
  ACSuspension *v1; // esi
  const mat44f *v2; // eax
  GLRenderer *v3; // ebx
  SHORT (__stdcall *v4)(int); // edi
  SHORT v5; // ax
  SHORT v6; // ax
  int v7; // eax
  DebugLine *v8; // edi
  DebugLine *v9; // esi
  CarAvatar *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  CarAvatar *v13; // eax
  DebugLine *v14; // xmm2_4
  float v15; // xmm0_4
  CarAvatar *v16; // eax
  DebugLine *v17; // xmm2_4
  float v18; // xmm0_4
  CarAvatar *v19; // eax
  float v20; // xmm0_4
  DebugLine *v21; // xmm2_4
  CarAvatar *v22; // eax
  DebugLine *v23; // xmm2_4
  float v24; // xmm0_4
  SHORT v25; // ax
  SHORT v26; // ax
  SHORT v27; // ax
  SHORT v28; // ax
  int v29; // ecx
  int v30; // edi
  int v31; // edx
  unsigned int v32; // eax
  Car *v33; // eax
  float v34; // xmm0_4
  CarAvatar *v35; // eax
  float v36; // xmm1_4
  bool v37; // cc
  ksgui::GUI *v38; // ecx
  int v39; // eax
  int v40; // eax
  float v41; // xmm1_4
  float v42; // xmm2_4
  CarAvatar *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm2_4
  ksgui::GUI *v46; // ecx
  float v47; // [esp+28h] [ebp-17Ch]
  float v48; // [esp+28h] [ebp-17Ch]
  GLRenderer *v49; // [esp+2Ch] [ebp-178h]
  float v50; // [esp+2Ch] [ebp-178h]
  float v51; // [esp+2Ch] [ebp-178h]
  std::vector<DebugLine> v52; // [esp+30h] [ebp-174h] BYREF
  float v53; // [esp+3Ch] [ebp-168h]
  float v54; // [esp+40h] [ebp-164h] BYREF
  float v55; // [esp+44h] [ebp-160h]
  float v56; // [esp+48h] [ebp-15Ch]
  int v57; // [esp+4Ch] [ebp-158h]
  unsigned int v58; // [esp+50h] [ebp-154h]
  int v59; // [esp+54h] [ebp-150h]
  float v60; // [esp+58h] [ebp-14Ch]
  float v61[3]; // [esp+5Ch] [ebp-148h] BYREF
  float v62[3]; // [esp+68h] [ebp-13Ch] BYREF
  float v63[3]; // [esp+74h] [ebp-130h] BYREF
  float v64[3]; // [esp+80h] [ebp-124h] BYREF
  float v65[3]; // [esp+8Ch] [ebp-118h] BYREF
  float v66[3]; // [esp+98h] [ebp-10Ch] BYREF
  float v67[3]; // [esp+A4h] [ebp-100h] BYREF
  float v[3]; // [esp+B0h] [ebp-F4h] BYREF
  float v69[3]; // [esp+BCh] [ebp-E8h] BYREF
  float v70[3]; // [esp+C8h] [ebp-DCh] BYREF
  mat44f matrix; // [esp+D4h] [ebp-D0h] BYREF
  mat44f v72; // [esp+114h] [ebp-90h] BYREF
  mat44f result; // [esp+154h] [ebp-50h] BYREF
  int v74; // [esp+1A0h] [ebp-4h]

  v1 = this;
  v58 = (unsigned int)this;
  v2 = mat44f::createIdentity(&result);
  GraphicsManager::setWorldMatrix(v1->gui->graphics, v2);
  v3 = susGL;
  v49 = susGL;
  GraphicsManager::setDepthMode(v1->gui->graphics, eDepthOff);
  v4 = GetAsyncKeyState;
  v5 = GetAsyncKeyState(8);
  if ( Trigger::ignoreSubsequentTrue(&v1->renderSuspensionsTrigger, v5 != 0) )
    v1->renderSuspensions = !v1->renderSuspensions;
  v6 = GetAsyncKeyState(17);
  if ( Trigger::ignoreSubsequentTrue(&v1->renderFuelTankPositionTrigger, v6 != 0) )
    v1->renderFuelTankPosition = !v1->renderFuelTankPosition;
  if ( v1->renderSuspensions )
  {
    GLRenderer::begin(v3, eLines, 0);
    v7 = 0;
    v57 = 0;
    do
    {
      CarAvatar::getSuspensionDebugLines(v1->car, &v52, v7);
      v74 = 0;
      v8 = v52._Mylast;
      v9 = v52._Myfirst;
      if ( v52._Myfirst != v52._Mylast )
      {
        do
        {
          GLRenderer::color4f(v49, &v9->color);
          GLRenderer::vertex3fv(v49, &v9->p0.x);
          v3 = v49;
          GLRenderer::vertex3fv(v49, &v9->p1.x);
          ++v9;
        }
        while ( v9 != v8 );
        v9 = v52._Myfirst;
      }
      v74 = -1;
      if ( v9 )
      {
        operator delete(v9);
        v52._Myfirst = 0;
        v52._Mylast = 0;
        v52._Myend = 0;
      }
      v1 = (ACSuspension *)v58;
      v7 = v57 + 1;
      v57 = v7;
    }
    while ( v7 < 4 );
    GLRenderer::color3f(v3, 0.0, 1.0, 1.0);
    v10 = v1->car;
    v11 = v10->physicsState.worldMatrix.M42;
    v12 = v10->physicsState.worldMatrix.M43;
    v53 = v10->physicsState.worldMatrix.M41;
    *(float *)&v52._Myfirst = v53;
    *(float *)&v52._Myend = v12;
    *(float *)&v52._Mylast = v11 + 0.5;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    *(float *)&v52._Myfirst = v53;
    *(float *)&v52._Mylast = v11 - 0.5;
    *(float *)&v52._Myend = v12;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    *(float *)&v52._Myfirst = v53 + 0.5;
    *(float *)&v52._Mylast = v11;
    *(float *)&v52._Myend = v12;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    *(float *)&v52._Myfirst = v53 - 0.5;
    *(float *)&v52._Mylast = v11;
    *(float *)&v52._Myend = v12;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    *(float *)&v52._Myfirst = v53;
    *(float *)&v52._Mylast = v11;
    *(float *)&v52._Myend = v12 + 0.5;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    *(float *)&v52._Myfirst = v53;
    *(float *)&v52._Mylast = v11;
    *(float *)&v52._Myend = v12 - 0.5;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    GLRenderer::end(v3);
    GraphicsManager::setWorldMatrix(v1->gui->graphics, &v1->car->physicsState.worldMatrix);
    GLRenderer::begin(v3, eLines, 0);
    GLRenderer::color3f(v3, 1.0, 0.0, 1.0);
    GLRenderer::vertex3fv(v3, (const float *)v1->car->physicsInfo.ridePickupPoint);
    GLRenderer::vertex3fv(v3, &v1->car->physicsInfo.ridePickupPoint[1].x);
    GLRenderer::end(v3);
    GraphicsManager::setDepthMode(v1->gui->graphics, eDepthNormal);
    GraphicsManager::setWorldMatrix(v1->gui->graphics, &v1->car->physicsState.worldMatrix);
    GraphicsManager::setCullMode(v1->gui->graphics, eCullNone);
    GLRenderer::color3f(v3, 0.0, 1.0, 1.0);
    GLRenderer::begin(v3, eQuads, 0);
    v13 = v1->car;
    v14 = (DebugLine *)LODWORD(v13->physicsInfo.ridePickupPoint[0].z);
    v15 = v13->physicsInfo.ridePickupPoint[0].x - 0.2;
    v52._Mylast = (DebugLine *)LODWORD(v13->physicsInfo.ridePickupPoint[0].y);
    v52._Myend = v14;
    *(float *)&v52._Myfirst = v15;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    v16 = v1->car;
    v17 = (DebugLine *)LODWORD(v16->physicsInfo.ridePickupPoint[1].z);
    v18 = v16->physicsInfo.ridePickupPoint[1].x - 0.2;
    v52._Mylast = (DebugLine *)LODWORD(v16->physicsInfo.ridePickupPoint[1].y);
    v52._Myend = v17;
    *(float *)&v52._Myfirst = v18;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    v19 = v1->car;
    v20 = v19->physicsInfo.ridePickupPoint[1].x + 0.2;
    v21 = (DebugLine *)LODWORD(v19->physicsInfo.ridePickupPoint[1].z);
    v52._Mylast = (DebugLine *)LODWORD(v19->physicsInfo.ridePickupPoint[1].y);
    *(float *)&v52._Myfirst = v20;
    v52._Myend = v21;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    v22 = v1->car;
    v23 = (DebugLine *)LODWORD(v22->physicsInfo.ridePickupPoint[0].z);
    v24 = v22->physicsInfo.ridePickupPoint[0].x + 0.2;
    v52._Mylast = (DebugLine *)LODWORD(v22->physicsInfo.ridePickupPoint[0].y);
    v52._Myend = v23;
    *(float *)&v52._Myfirst = v24;
    GLRenderer::vertex3fv(v3, (const float *)&v52);
    GLRenderer::end(v3);
    v4 = GetAsyncKeyState;
  }
  v25 = v4(97);
  if ( Trigger::ignoreSubsequentTrue(v1->renderWheelsTrigger, v25 != 0) )
    v1->renderWheels[0] = !v1->renderWheels[0];
  v26 = v4(98);
  if ( Trigger::ignoreSubsequentTrue(&v1->renderWheelsTrigger[1], v26 != 0) )
    v1->renderWheels[1] = !v1->renderWheels[1];
  v27 = v4(99);
  if ( Trigger::ignoreSubsequentTrue(&v1->renderWheelsTrigger[2], v27 != 0) )
    v1->renderWheels[2] = !v1->renderWheels[2];
  v28 = v4(100);
  if ( Trigger::ignoreSubsequentTrue(&v1->renderWheelsTrigger[3], v28 != 0) )
    v1->renderWheels[3] = !v1->renderWheels[3];
  GraphicsManager::setDepthMode(v1->gui->graphics, eDepthOff);
  if ( v1 != (ACSuspension *)-356 )
  {
    v29 = 0;
    v30 = 0;
    v31 = 0;
    v59 = 0;
    v32 = 3412;
    v57 = 0;
    v58 = 3412;
    do
    {
      if ( v1->renderWheels[v29] )
      {
        GraphicsManager::setWorldMatrix(v1->gui->graphics, &v1->car->physicsState.tyreMatrix[v30]);
        GLRenderer::color3f(v3, 0.0, 3.0, 0.0);
        v33 = RaceEngineer::getCar(v1->car->raceEngineer._Myptr);
        v34 = *(float *)((char *)&v33->tyres[0].data.radius + v57);
        v35 = v1->car;
        v53 = v34;
        v47 = *(float *)((char *)&v35->__vftable + v58) * 0.5;
        GLRenderer::begin(v3, eLinesStrip, 0);
        v50 = 0.0;
        do
        {
          *(float *)&v52._Myfirst = v47;
          *(float *)&v52._Mylast = __libm_sse2_cosf().m128_f32[0] * v53;
          *(float *)&v52._Myend = __libm_sse2_sinf().m128_f32[0] * v53;
          GLRenderer::vertex3fv(v3, (const float *)&v52);
          v50 = v50 + 0.062831804;
        }
        while ( v50 < 6.2831802 );
        GLRenderer::end(v3);
        GLRenderer::begin(v3, eLines, 0);
        v[0] = v47;
        v[1] = v53;
        v[2] = 0.0;
        GLRenderer::vertex3fv(v3, v);
        v67[0] = v47;
        LODWORD(v60) = LODWORD(v53) ^ _xmm;
        LODWORD(v67[1]) = LODWORD(v53) ^ _xmm;
        v67[2] = 0.0;
        GLRenderer::vertex3fv(v3, v67);
        GLRenderer::end(v3);
        GLRenderer::begin(v3, eLines, 0);
        v61[0] = v47;
        v61[1] = 0.0;
        v61[2] = v53;
        GLRenderer::vertex3fv(v3, v61);
        v64[0] = v47;
        v64[1] = 0.0;
        v64[2] = v60;
        GLRenderer::vertex3fv(v3, v64);
        GLRenderer::end(v3);
        GLRenderer::begin(v3, eLinesStrip, 0);
        LODWORD(v36) = LODWORD(v47) ^ _xmm;
        v51 = 0.0;
        LODWORD(v48) = LODWORD(v47) ^ _xmm;
        do
        {
          v70[0] = v36;
          v70[1] = __libm_sse2_cosf().m128_f32[0] * v53;
          v70[2] = __libm_sse2_sinf().m128_f32[0] * v53;
          GLRenderer::vertex3fv(v3, v70);
          v37 = (float)(v51 + 0.062831804) >= 6.2831802;
          v36 = v48;
          v51 = v51 + 0.062831804;
        }
        while ( !v37 );
        GLRenderer::end(v3);
        GLRenderer::begin(v3, eLines, 0);
        v66[0] = v48;
        v66[1] = v53;
        v66[2] = 0.0;
        GLRenderer::vertex3fv(v3, v66);
        v69[0] = v48;
        v69[1] = v60;
        v69[2] = 0.0;
        GLRenderer::vertex3fv(v3, v69);
        GLRenderer::end(v3);
        GLRenderer::begin(v3, eLines, 0);
        v62[0] = v48;
        v62[1] = 0.0;
        v62[2] = v53;
        GLRenderer::vertex3fv(v3, v62);
        v63[0] = v48;
        v63[1] = 0.0;
        v63[2] = v60;
        GLRenderer::vertex3fv(v3, v63);
        GLRenderer::end(v3);
        v38 = v1->gui;
        *(_OWORD *)&matrix.M11 = _xmm;
        *(_OWORD *)&matrix.M21 = _xmm;
        *(_OWORD *)&matrix.M31 = _xmm;
        *(_OWORD *)&matrix.M41 = _xmm;
        GraphicsManager::setWorldMatrix(v38->graphics, &matrix);
        GLRenderer::color4f(v3, 1.0, 1.0, 1.0, 1.0);
        GLRenderer::begin(v3, eLines, 0);
        v39 = (int)v1->car->suspensionAvatar->getWheelTransform(v1->car->suspensionAvatar, v59);
        v40 = (*(int (**)(int, mat44f *))(*(_DWORD *)v39 + 32))(v39, &matrix);
        v41 = *(float *)(v40 + 52);
        v42 = *(float *)(v40 + 56);
        v65[0] = *(float *)(v40 + 48);
        v65[1] = v41;
        v65[2] = v42;
        GLRenderer::vertex3fv(v3, v65);
        v43 = v1->car;
        v44 = v43->physicsState.tyreMatrix[v30].M42;
        v45 = v43->physicsState.tyreMatrix[v30].M43;
        v54 = v43->physicsState.tyreMatrix[v30].M41;
        v55 = v44;
        v56 = v45;
        GLRenderer::vertex3fv(v3, &v54);
        GLRenderer::end(v3);
        v32 = v58;
        v29 = v59;
        v31 = v57;
      }
      v32 += 4;
      ++v29;
      v31 += 1632;
      v59 = v29;
      ++v30;
      v58 = v32;
      v57 = v31;
    }
    while ( v32 < 0xD64 );
  }
  if ( v1->renderFuelTankPosition )
  {
    GLRenderer::color4f(v3, 3.0, 0.0, 0.0, 1.0);
    GraphicsManager::setWorldMatrix(v1->gui->graphics, &v1->car->physicsState.worldMatrix);
    GLRenderer::begin(v3, eLines, 0);
    v54 = v1->fuelTankPosition.x;
    v55 = v1->fuelTankPosition.y - 0.5;
    v56 = v1->fuelTankPosition.z;
    GLRenderer::vertex3fv(v3, &v54);
    v54 = v1->fuelTankPosition.x;
    v55 = v1->fuelTankPosition.y + 0.5;
    v56 = v1->fuelTankPosition.z;
    GLRenderer::vertex3fv(v3, &v54);
    v54 = v1->fuelTankPosition.x - 0.5;
    v55 = v1->fuelTankPosition.y;
    v56 = v1->fuelTankPosition.z;
    GLRenderer::vertex3fv(v3, &v54);
    v54 = v1->fuelTankPosition.x + 0.5;
    v55 = v1->fuelTankPosition.y;
    v56 = v1->fuelTankPosition.z;
    GLRenderer::vertex3fv(v3, &v54);
    v54 = v1->fuelTankPosition.x;
    v55 = v1->fuelTankPosition.y;
    v56 = v1->fuelTankPosition.z - 0.5;
    GLRenderer::vertex3fv(v3, &v54);
    v54 = v1->fuelTankPosition.x;
    v55 = v1->fuelTankPosition.y;
    v56 = v1->fuelTankPosition.z + 0.5;
    GLRenderer::vertex3fv(v3, &v54);
    GLRenderer::end(v3);
  }
  GraphicsManager::setCullMode(v1->gui->graphics, eCullFront);
  v46 = v1->gui;
  *(_OWORD *)&v72.M11 = _xmm;
  *(_OWORD *)&v72.M21 = _xmm;
  *(_OWORD *)&v72.M31 = _xmm;
  *(_OWORD *)&v72.M41 = _xmm;
  GraphicsManager::setWorldMatrix(v46->graphics, &v72);
  GraphicsManager::setDepthMode(v1->gui->graphics, eDepthNormal);
}
void ACSuspension::renderCamber(ACSuspension *this, GLRenderer *gl, vec3f pos, int index)
{
  int v5; // edi
  ksgui::ProgressBar *v6; // eax
  __int128 v7; // xmm0
  float v8; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  int v12; // eax
  std::wostream *v13; // eax
  const std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::wostream *v16; // eax
  const std::wstring *v17; // eax
  CarAvatar *v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  CarAvatar *v23; // ecx
  unsigned int v24; // xmm1_4
  unsigned int v25; // xmm2_4
  int v26; // ecx
  std::wstring *v27; // eax
  CarAvatar *v28; // eax
  std::wostream *v29; // eax
  std::wostream *v30; // eax
  std::wostream *v31; // eax
  std::wostream *v32; // eax
  std::wostream *v33; // eax
  const std::wstring *v34; // eax
  float y; // [esp+20h] [ebp-184h]
  const char *ya; // [esp+20h] [ebp-184h]
  int g; // [esp+28h] [ebp-17Ch]
  float b; // [esp+2Ch] [ebp-178h]
  float a; // [esp+30h] [ebp-174h]
  GLRenderer *v40; // [esp+40h] [ebp-164h]
  float v41; // [esp+44h] [ebp-160h]
  float v42; // [esp+44h] [ebp-160h]
  GLRenderer *v43; // [esp+44h] [ebp-160h]
  float v44; // [esp+44h] [ebp-160h]
  float v45; // [esp+4Ch] [ebp-158h]
  float v46; // [esp+4Ch] [ebp-158h]
  vec3f v47; // [esp+50h] [ebp-154h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v48; // [esp+5Ch] [ebp-148h] BYREF
  vec3f result; // [esp+110h] [ebp-94h] BYREF
  mat44f v50; // [esp+11Ch] [ebp-88h] BYREF
  std::wstring v; // [esp+15Ch] [ebp-48h] BYREF
  std::wstring v52; // [esp+178h] [ebp-2Ch] BYREF
  int v53; // [esp+198h] [ebp-Ch]
  int v54; // [esp+1A0h] [ebp-4h]

  v5 = index;
  this->prgSlipFactor[index]->value = this->car->physicsState.ndSlip[index];
  v6 = this->prgSlipFactor[v5];
  if ( v6->value < 1.0 )
    v7 = _xmm;
  else
    v7 = _xmm;
  v6->foreColor = (vec4f)v7;
  GLRenderer::begin(gl, eLines, 0);
  GLRenderer::color3f(gl, 1.0, 1.0, 1.0);
  *(float *)&v._Bx._Ptr = pos.x - 50.0;
  *(_QWORD *)&v._Bx._Alias[4] = *(_QWORD *)&pos.y;
  GLRenderer::vertex3fv(gl, (const float *)&v._Bx._Ptr);
  *(float *)&v._Bx._Ptr = pos.x + 50.0;
  *(_QWORD *)&v._Bx._Alias[4] = *(_QWORD *)&pos.y;
  GLRenderer::vertex3fv(gl, (const float *)&v._Bx._Ptr);
  GLRenderer::color3f(gl, 1.0, 0.0, 1.0);
  v45 = __libm_sse2_cosf().m128_f32[0];
  v41 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f(&v50);
  v8 = v41 + (float)((float)(1.0 - v45) * 0.0);
  v9 = (float)(v41 * 0.0) + (float)((float)(1.0 - v45) * 0.0);
  v10 = (float)((float)((float)(1.0 - v45) * 0.0) - (float)(v41 * 0.0)) * 0.0;
  v42 = (float)((float)((float)((float)((float)((float)(1.0 - v45) * 0.0) + v45) * 0.0)
                      + (float)((float)((float)(1.0 - v45) * 0.0) - v41))
              + (float)(v9 * 0.0))
      + v50.M41;
  v11 = (float)((float)(v10 + v9) + (float)((float)((float)(1.0 - v45) + v45) * 0.0)) + v50.M43;
  v46 = (float)((float)((float)(v8 * 0.0) + (float)((float)((float)(1.0 - v45) * 0.0) + v45)) + v10) + v50.M42;
  GLRenderer::vertex3fv(gl, &pos.x);
  *(float *)&v._Bx._Ptr = pos.x - (float)(v42 * 100.0);
  *(float *)&v._Bx._Alias[4] = pos.y - (float)(v46 * 100.0);
  *(float *)&v._Bx._Alias[8] = pos.z - (float)(v11 * 100.0);
  GLRenderer::vertex3fv(gl, (const float *)&v._Bx._Ptr);
  *(_DWORD *)v48.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v48.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v48.gap68);
  v54 = 0;
  std::wiostream::basic_iostream<wchar_t>(&v48, &v48.gap10[8], 0);
  v53 = 1;
  *(_DWORD *)((char *)&v47.y + *(_DWORD *)(LODWORD(v47.y) + 4)) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v47.x + *(_DWORD *)(LODWORD(v47.y) + 4)) = *(_DWORD *)(LODWORD(v47.y) + 4) - 104;
  std::wstreambuf::wstreambuf(v48.gap10);
  *(_DWORD *)v48.gap10 = &std::wstringbuf::`vftable';
  *(_DWORD *)&v48.gap10[56] = 0;
  *(_DWORD *)&v48.gap10[60] = 0;
  v53 = 3;
  *(_DWORD *)((char *)&v48._Chcount + *(_DWORD *)(LODWORD(v47.y) + 4) + 4) = *(_DWORD *)((_BYTE *)&v48._Chcount
                                                                                       + *(_DWORD *)(LODWORD(v47.y) + 4)
                                                                                       + 4) & 0xFFFFEFFF | 0x2000;
  GLRenderer::end((GLRenderer *)LODWORD(v11));
  v12 = std::setprecision(&v50.M43, 1, 0);
  (*(void (__stdcall **)(char *, _DWORD, _DWORD))v12)(
    (char *)&v48._Chcount + *(_DWORD *)(LODWORD(v48._Chcount) + 4),
    *(_DWORD *)(v12 + 8),
    *(_DWORD *)(v12 + 12));
  Font::setColor(this->font._Ptr, 1.0, 0.0, 1.0, 1.0);
  a = this->car->physicsState.slipAngle[v5];
  v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v48.gap10[4], "SA: ");
  std::wostream::operator<<(v13, LODWORD(a));
  v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v48, &v);
  LOBYTE(v54) = 4;
  Font::blitString(this->font._Ptr, pos.x, pos.y + 20.0, v14, 1.0, eAlignCenter);
  LOBYTE(v54) = 3;
  if ( v._Myres >= 8 )
    operator delete(v._Bx._Ptr);
  Font::setColor(this->font._Ptr, 0.0, 1.0, 0.0, 1.0);
  v._Myres = 7;
  v._Mysize = 0;
  v._Bx._Buf[0] = 0;
  std::wstring::assign(&v, word_17BE9D8, 0);
  LOBYTE(v54) = 5;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v48.gap10[8]);
  v15 = &v;
  if ( v._Myres >= 8 )
    v15 = (std::wstring *)v._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v48.gap10[8], v15->_Bx._Buf, v._Mysize, *(int *)&v48.gap10[68]);
  LOBYTE(v54) = 3;
  if ( v._Myres >= 8 )
    operator delete(v._Bx._Ptr);
  b = this->car->physicsState.slipRatio[v5] * 100.0;
  v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v48.gap10, "SR: ");
  std::wostream::operator<<(v16, LODWORD(b));
  v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v48, &v);
  LOBYTE(v54) = 6;
  Font::blitString(this->font._Ptr, pos.x, pos.y + 40.0, v17, 1.0, eAlignCenter);
  LOBYTE(v54) = 3;
  if ( v._Myres >= 8 )
    operator delete(v._Bx._Ptr);
  v18 = this->car;
  v43 = (GLRenderer *)(v5 << 6);
  v19 = v18->physicsState.suspensionMatrix[v5].M33;
  LODWORD(v20) = LODWORD(v18->physicsState.suspensionMatrix[v5].M32) ^ _xmm;
  LODWORD(v47.x) = LODWORD(v18->physicsState.suspensionMatrix[v5].M31) ^ _xmm;
  v47.y = v20;
  LODWORD(v47.z) = LODWORD(v19) ^ _xmm;
  v47 = *Node::worldToLocalNormal(v18->bodyTransform, (vec3f *)&v, &v47);
  v47.y = 0.0;
  v21 = fsqrt((float)(v47.z * v47.z) + (float)(v47.x * v47.x));
  if ( v21 != 0.0 )
  {
    v47.x = v47.x * (float)(1.0 / v21);
    v47.y = (float)(1.0 / v21) * 0.0;
    v47.z = v47.z * (float)(1.0 / v21);
  }
  v22 = __libm_sse2_asinf().m128_f32[0] * 57.29578;
  *(float *)&v40 = v22;
  if ( v5 % 2 )
    v40 = (GLRenderer *)(LODWORD(v22) ^ _xmm);
  v23 = this->car;
  v24 = *(_DWORD *)((char *)&v43[2].tempVertices[0].tangent.x + (_DWORD)v23);
  v25 = *(_DWORD *)((char *)&v43[2].tempVertices[0].tangent.y + (_DWORD)v23);
  v._Bx._Ptr = *(wchar_t **)((char *)&v43[2].tempVertices[0].texCoord.y + (_DWORD)v23);
  *(_QWORD *)&v._Bx._Alias[4] = __PAIR64__(v25, v24);
  Node::worldToLocal(v23->bodyTransform, &result, (const vec3f *)&v);
  if ( v5 == 2 )
  {
    v26 = (int)(float)((float)((double)((unsigned int)(this->rearBumpSteer._Mylast - this->rearBumpSteer._Myfirst) >> 1)
                             + 0.0)
                     + (float)((float)(result.y - this->car->physicsInfo.susBasePos[2].y) * 300.0));
    if ( v26 >= 0 && v26 < (unsigned int)(this->rearBumpSteer._Mylast - this->rearBumpSteer._Myfirst) )
      this->rearBumpSteer._Myfirst[v26] = *(float *)&v40;
  }
  v._Myres = 7;
  v._Mysize = 0;
  v._Bx._Buf[0] = 0;
  std::wstring::assign(&v, word_17BE9D8, 0);
  LOBYTE(v54) = 7;
  std::wstringbuf::_Tidy((std::wstringbuf *)&v48.gap10[8]);
  v27 = &v;
  if ( v._Myres >= 8 )
    v27 = (std::wstring *)v._Bx._Ptr;
  std::wstringbuf::_Init((std::wstringbuf *)&v48.gap10[8], v27->_Bx._Buf, v._Mysize, *(int *)&v48.gap10[68]);
  LOBYTE(v54) = 3;
  if ( v._Myres >= 8 )
    operator delete(v._Bx._Ptr);
  Font::setColor(this->font._Ptr, 0.0, 1.0, 1.0, 1.0);
  v28 = this->car;
  v44 = v28->physicsState.steer / *(float *)&v40;
  y = v28->physicsState.camberRAD[v5] * 57.29578;
  v29 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v48.gap10, "C: ");
  v30 = (std::wostream *)std::wostream::operator<<(v29, LODWORD(y));
  v31 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v30, ya);
  std::wostream::operator<<(v31, g);
  if ( v5 < 2 )
  {
    v32 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v48.gap10, " [STR:");
    v33 = (std::wostream *)std::wostream::operator<<(v32, LODWORD(v44));
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v33, "]");
  }
  v34 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v48, &v52);
  LOBYTE(v54) = 8;
  Font::blitString(this->font._Ptr, pos.x, pos.y + 60.0, v34, 1.0, eAlignCenter);
  if ( v52._Myres >= 8 )
    operator delete(v52._Bx._Ptr);
  *(_DWORD *)&v48.gap0[*(_DWORD *)(*(_DWORD *)v48.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v47.z + *(_DWORD *)(*(_DWORD *)v48.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v48.gap0 + 4) - 104;
  *(_DWORD *)&v48.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v48.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v48.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v48.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v48.gap68);
}
void ACSuspension::renderTyreTemp(ACSuspension *this, const vec3f *basePos, int index)
{
  GLRenderer *v3; // ebp
  int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // ebx
  float v8; // xmm1_4
  int v9; // ebx
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wostream *v12; // eax
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  std::wostream *v16; // eax
  std::wostream *v17; // eax
  std::wostream *v18; // eax
  std::wostream *v19; // eax
  std::wostream *v20; // eax
  const std::wstring *v21; // eax
  int x; // [esp+1Ch] [ebp-12Ch]
  const char *xa; // [esp+1Ch] [ebp-12Ch]
  const char *y; // [esp+20h] [ebp-128h]
  const char *width; // [esp+24h] [ebp-124h]
  const char *r; // [esp+28h] [ebp-120h]
  const char *g; // [esp+2Ch] [ebp-11Ch]
  int v28; // [esp+34h] [ebp-114h]
  int v30; // [esp+58h] [ebp-F0h]
  int v31; // [esp+5Ch] [ebp-ECh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v32; // [esp+60h] [ebp-E8h] BYREF
  std::wstring result; // [esp+114h] [ebp-34h] BYREF
  float avg[3]; // [esp+12Ch] [ebp-1Ch]
  float v35; // [esp+144h] [ebp-4h]
  float retaddr; // [esp+148h] [ebp+0h]

  v3 = susGL;
  avg[0] = 0.0;
  avg[1] = 0.0;
  avg[2] = 0.0;
  GLRenderer::begin(susGL, eQuads, 0);
  v4 = 0;
  v31 = 192 * index;
  v5 = 192 * index + 2452;
  v30 = v5;
  do
  {
    v6 = 0;
    v7 = v5;
    do
    {
      v8 = *(float *)((char *)&this->car->__vftable + v7);
      avg[v4] = avg[v4] + v8;
      GLRenderer::color3f(v3, (float)(v8 - 26.0) * 0.0099999998, 0.0, 1.0 - (float)((float)(v8 - 26.0) * 0.0099999998));
      GLRenderer::quad(
        v3,
        (float)((float)v6++ * 10.0) + basePos->x,
        (float)((float)v4 * 10.0) + basePos->y,
        10.0,
        10.0,
        0,
        0);
      v7 += 12;
    }
    while ( v6 < 12 );
    ++v4;
    v5 = v30 + 4;
    v30 += 4;
  }
  while ( v4 < 3 );
  GLRenderer::end(v3);
  *(_DWORD *)v32.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v32.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v32.gap68);
  *(_DWORD *)&v32.gap0[4] = 1;
  std::wiostream::basic_iostream<wchar_t>(&v32.gap10[8], &v32.gap10[32], 0);
  *(_DWORD *)&v32.gap10[*(_DWORD *)(*(_DWORD *)&v32.gap10[8] + 4) + 8] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v32.gap10[*(_DWORD *)(*(_DWORD *)&v32.gap10[8] + 4) + 4] = *(_DWORD *)(*(_DWORD *)&v32.gap10[8] + 4) - 104;
  std::wstreambuf::wstreambuf(&v32.gap10[32]);
  *(_DWORD *)&v32.gap10[32] = &std::wstringbuf::`vftable';
  *(_DWORD *)v32.gap68 = 0;
  *(_DWORD *)&v32.gap68[4] = 0;
  v9 = HIDWORD(v32._Chcount);
  v28 = (int)*(float *)(*(_DWORD *)&v32.gap10[4] + *(_DWORD *)(HIDWORD(v32._Chcount) + 336) + 2600);
  x = (int)(float)(v35 * 0.083333336);
  v10 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v32.gap10[24], "IMO ");
  v11 = (std::wostream *)std::wostream::operator<<(v10, x);
  v12 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v11, xa);
  v13 = (std::wostream *)std::wostream::operator<<(v12, " ");
  v14 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v13, y);
  v15 = (std::wostream *)std::wostream::operator<<(v14, (int)(float)(retaddr * 0.083333336));
  v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v15, width);
  v17 = (std::wostream *)std::wostream::operator<<(v16, " ");
  v18 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v17, r);
  v19 = (std::wostream *)std::wostream::operator<<(v18, (int)(float)(*(float *)&basePos * 0.083333336));
  v20 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v19, g);
  std::wostream::operator<<(v20, v28);
  v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v32, &result);
  LOBYTE(v35) = 4;
  Font::blitString(*(Font **)(v9 + 128), basePos->x, basePos->y + 35.0, v21, 1.0, eAlignLeft);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v35 = NAN;
  result._Bx._Buf[0] = 0;
  result._Myres = 7;
  result._Mysize = 0;
  *(_DWORD *)&v32.gap0[*(_DWORD *)(*(_DWORD *)v32.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(int *)((char *)&v31 + *(_DWORD *)(*(_DWORD *)v32.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v32.gap0 + 4) - 104;
  *(_DWORD *)&v32.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v32.gap10[68] & 1) != 0 )
    operator delete(**(void ***)&v32.gap10[20]);
  std::wstreambuf::setg(&v32.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v32.gap10[8], 0, 0);
  *(_DWORD *)&v32.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v32.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v32.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v32.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v32.gap68);
}
void ACSuspension::drawBumpGraph(ACSuspension *this, GLRenderer *gl, const vec3f *basepos, std::vector<float> *data)
{
  GLRenderer *v4; // esi
  float *v5; // edx
  float *v6; // ecx
  ACSuspension::drawBumpGraph::__l3::<lambda_bccb89b370b3b805e2b051ec9329db20> _Func; // [esp+10h] [ebp-Ch] BYREF

  v4 = gl;
  GLRenderer::color3f(gl, 1.0, 1.0, 1.0);
  GLRenderer::begin(v4, eLinesStrip, 0);
  *(_QWORD *)&_Func.basepos = __PAIR64__(&gl, (unsigned int)basepos);
  v5 = data->_Mylast;
  v6 = data->_Myfirst;
  gl = 0;
  _Func.gl = v4;
  std::_For_each<float *,_lambda_bccb89b370b3b805e2b051ec9329db20_>(v6, v5, &_Func);
  GLRenderer::end(v4);
}
