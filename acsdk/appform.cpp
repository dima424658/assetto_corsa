#include "appform.h"
void __userpurge AppForm::AppForm(AppForm *this@<ecx>, unsigned int a2@<ebx>, ACOperatingSystem *iacos, std::wstring form_name)
{
  bool v5; // cf
  std::wstring v6; // [esp-20h] [ebp-3Ch] BYREF
  ksgui::GUI *v7; // [esp-8h] [ebp-24h]
  BOOL v8; // [esp-4h] [ebp-20h]
  int v9; // [esp+18h] [ebp-4h]

  v8 = 0;
  v7 = iacos->gui;
  v9 = 0;
  v6._Myres = 7;
  v6._Mysize = 0;
  v6._Bx._Buf[0] = 0;
  std::wstring::assign(&v6, &form_name, 0, 0xFFFFFFFF);
  ksgui::Form::Form(this, a2, v6, v7, v8);
  v5 = form_name._Myres < 8;
  this->IACForm::__vftable = (IACForm_vtbl *)&IACForm::`vftable';
  this->ksgui::Form::ksgui::Control::__vftable = (AppForm_vtbl *)&AppForm::`vftable'{for `ksgui::Form'};
  this->IACForm::__vftable = (IACForm_vtbl *)&AppForm::`vftable'{for `IACForm'};
  this->acOS = iacos;
  this->listeners._Myfirst = 0;
  this->listeners._Mylast = 0;
  this->listeners._Myend = 0;
  if ( !v5 )
    operator delete(form_name._Bx._Ptr);
}
AppForm *AppForm::`vector deleting destructor'(AppForm *this, unsigned int a2)
{
  std::vector<IACFormEventListener *> *v3; // edi

  this->ksgui::Form::ksgui::Control::__vftable = (AppForm_vtbl *)&AppForm::`vftable'{for `ksgui::Form'};
  this->IACForm::__vftable = (IACForm_vtbl *)&AppForm::`vftable'{for `IACForm'};
  v3 = &this->listeners;
  if ( this->listeners._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->listeners);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  ksgui::Form::~Form(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
IACControl *AppForm::addControl(AppForm *this)
{
  ACControl *v2; // eax
  int v3; // eax
  int v4; // edi
  ksgui::Control *v5; // esi
  IACControl *result; // eax
  std::function<void __cdecl(OnMouseWheelMovedEvent const &)> v7; // [esp-1Ch] [ebp-3Ch] BYREF
  ACControl *v8; // [esp+10h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-4h]

  v2 = (ACControl *)operator new(284);
  v8 = v2;
  v9 = 0;
  if ( v2 )
  {
    ACControl::ACControl(v2, (ksgui::GUI *)this[-1].controlGLR);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  v5 = (AppForm *)((char *)this - 320);
  ksgui::Control::addControl(v5, (ksgui::Control *)v4);
  v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_41a459656b9f09f7668adf8c74d4228e_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  v7._Space._Pfn[1] = (void (__cdecl *)())v5;
  v7._Impl = (std::_Func_base<void,OnMouseWheelMovedEvent const &> *)&v7;
  v9 = -1;
  Event<ksgui::OnControlClicked>::addHandler((Event<OnMouseWheelMovedEvent> *)(v4 + 156), v7, v5);
  if ( v4 )
    result = (IACControl *)(v4 + 280);
  else
    result = 0;
  return result;
}
void AppForm::addEventListener(KeyboardManager *this, IKeyEventListener *l)
{
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->listeners,
    (ICollisionObject *const *)&l);
}
void AppForm::render(AppForm *this, float dt)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  ACGL *v5; // ecx
  float v6; // xmm0_4
  IACFormEventListener **v7; // eax
  IACFormEventListener **v8; // esi
  int v9; // edi
  unsigned int v10; // ebx
  Font *v11; // [esp-4h] [ebp-50h]
  vec2f off; // [esp+14h] [ebp-38h] BYREF
  vec2f v13; // [esp+1Ch] [ebp-30h] BYREF
  AppRenderContext rc; // [esp+24h] [ebp-28h] BYREF
  ACFont acfont; // [esp+30h] [ebp-1Ch] BYREF
  int v16; // [esp+48h] [ebp-4h]

  FormOpenVR::render((CarLabel *)this, dt);
  v3 = this->rect.top;
  v11 = this->font._Ptr;
  off.x = this->rect.left;
  off.y = v3;
  ACFont::ACFont(&acfont, v11, &off);
  v4 = this->rect.top;
  v5 = &this->acOS->gl;
  rc.font = &acfont;
  rc.deltaT = dt;
  v6 = this->rect.left;
  v16 = 0;
  rc.gl = v5;
  v13.x = v6;
  v13.y = v4;
  ACGL::setOffset(v5, &v13);
  v7 = this->listeners._Mylast;
  v8 = this->listeners._Myfirst;
  v9 = 0;
  v10 = (unsigned int)((char *)v7 - (char *)v8 + 3) >> 2;
  if ( v8 > v7 )
    v10 = 0;
  if ( v10 )
  {
    do
    {
      (*v8)->onRenderGUI(*v8, &rc);
      ++v9;
      ++v8;
    }
    while ( v9 != v10 );
  }
  v16 = -1;
  ACFont::~ACFont(&acfont);
}
void AppForm::setAutoHideMode(AppForm *this, bool mode)
{
  BYTE1(this[-1].zoomInIcon) = mode;
}
void __userpurge AppForm::setIcon(AppForm *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *filename)
{
  std::wstring v4; // [esp-18h] [ebp-20h] BYREF

  if ( Path::fileExists(a2, filename, 0) )
  {
    v4._Myres = 7;
    v4._Mysize = 0;
    v4._Bx._Buf[0] = 0;
    std::wstring::assign(&v4, filename, 0, 0xFFFFFFFF);
    ksgui::Form::setIcon((AppForm *)((char *)this - 320), a2, v4);
  }
}
void AppForm::setWindowSize(AppForm *this, int width, int height)
{
  (*(void (**)(unsigned int *, float, float))(this[-1].name._Mysize + 28))(
    &this[-1].name._Mysize,
    (float)width,
    (float)height);
}
