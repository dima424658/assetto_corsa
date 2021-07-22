#include "achelp.h
void __userpurge ACHelp::ACHelp(ACHelp *this@<ecx>, unsigned int a2@<ebx>, ksgui::GUI *aGui)
{
  const std::wstring *v4; // eax
  ksgui::Control *v5; // ecx
  float v6; // xmm0_4
  ksgui::TextBox *v7; // esi
  int v8; // eax
  int v9; // esi
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  Font *v15; // eax
  Font *v16; // eax
  volatile signed __int32 *v17; // ebx
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  TagDocumentText *v20; // eax
  _BYTE v21[32]; // [esp-8h] [ebp-ACh] BYREF
  std::shared_ptr<Font> v22; // [esp+2Ch] [ebp-78h] BYREF
  int _Val[2]; // [esp+34h] [ebp-70h] BYREF
  TagDocumentReader tdr; // [esp+3Ch] [ebp-68h] BYREF
  ACHelp *v25; // [esp+44h] [ebp-60h]
  std::wstring text; // [esp+48h] [ebp-5Ch] BYREF
  std::wstring result; // [esp+60h] [ebp-44h] BYREF
  TagDocumentText v28; // [esp+78h] [ebp-2Ch] BYREF
  int v29; // [esp+A0h] [ebp-4h]

  *(_DWORD *)&v21[28] = 0;
  *(_DWORD *)&v21[24] = aGui;
  v25 = this;
  *(_DWORD *)&v21[20] = 7;
  *(_DWORD *)&v21[16] = 0;
  *(_WORD *)v21 = 0;
  std::wstring::assign((std::wstring *)v21, L"HELP", 4u);
  ksgui::Form::Form(this, a2, *(std::wstring *)v21, *(ksgui::GUI **)&v21[24], v21[28]);
  v29 = 0;
  *(_DWORD *)&v21[28] = 4;
  this->__vftable = (ACHelp_vtbl *)&ACHelp::`vftable';
  *(_DWORD *)&v21[24] = L"Help";
  this->pos.x = 0.0;
  this->pos.y = 0.0;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, *(const wchar_t **)&v21[24], *(unsigned int *)&v21[28]);
  LOBYTE(v29) = 1;
  v4 = acTranslate(&result, &text);
  LOBYTE(v29) = 2;
  this->formTitle->setText(this->formTitle, v4);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v29) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->devApp = 0;
  ksgui::Form::setSize(this, 450.0, 550.0);
  v5 = this->parent;
  v6 = this->rect.top + 50.0;
  if ( v5 )
  {
    *(float *)_Val = this->rect.left + 20.0;
    *(float *)&_Val[1] = v6;
    v5->localToWorld(v5, (vec2f *)&v22, (const vec2f *)_Val);
  }
  else
  {
    *(float *)&v22._Ptr = this->rect.left + 20.0;
    *(float *)&v22._Rep = v6;
  }
  LODWORD(this->pos.x) = v22._Ptr;
  *(_DWORD *)&v21[28] = 292;
  LODWORD(this->pos.y) = v22._Rep;
  v7 = (ksgui::TextBox *)operator new(*(unsigned int *)&v21[28]);
  _Val[0] = (int)v7;
  LOBYTE(v29) = 3;
  if ( v7 )
  {
    *(_DWORD *)&v21[28] = 0;
    *(_DWORD *)&v21[24] = this->gui;
    *(_DWORD *)&v21[20] = 7;
    *(_DWORD *)&v21[16] = 0;
    *(_WORD *)v21 = 0;
    std::wstring::assign((std::wstring *)v21, L"HELP_TEXTBOX", 0xCu);
    ksgui::TextBox::TextBox(v7, *(std::wstring *)v21, *(ksgui::GUI **)&v21[24], *(eFontType *)&v21[28]);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  LOBYTE(v29) = 0;
  (*(void (**)(int, _DWORD, _DWORD))(*(_DWORD *)v9 + 28))(
    v9,
    this->rect.right - this->rect.left,
    this->rect.bottom - this->rect.top);
  v10 = *(float *)(v9 + 264);
  v11 = *(float *)(v9 + 32) - *(float *)(v9 + 28);
  v12 = *(float *)(v9 + 40) - *(float *)(v9 + 36);
  *(_DWORD *)(v9 + 36) = 1106247680;
  *(_DWORD *)(v9 + 28) = 1101004800;
  v13 = v11 + 20.0;
  v14 = v12 + 30.0;
  *(float *)(v9 + 32) = v13;
  *(float *)(v9 + 40) = v14;
  if ( v10 == 0.0 && *(float *)(v9 + 272) == 0.0 )
  {
    *(_DWORD *)(v9 + 264) = 1101004800;
    *(_DWORD *)(v9 + 272) = 1106247680;
    *(float *)(v9 + 268) = v13;
    *(float *)(v9 + 276) = v14;
  }
  v15 = (Font *)operator new(0x18u);
  v22._Ptr = v15;
  LOBYTE(v29) = 4;
  if ( v15 )
    Font::Font(v15, eFontProportional, 18.0, 0, 0);
  else
    v16 = 0;
  LOBYTE(v29) = 0;
  v22 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v22, v16);
  v17 = *(volatile signed __int32 **)(v9 + 132);
  *(std::shared_ptr<Font> *)(v9 + 128) = v22;
  if ( v17 )
  {
    if ( !_InterlockedExchangeAdd(v17 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v17)(v17);
      if ( !_InterlockedExchangeAdd(v17 + 2, 0xFFFFFFFF) )
        (*(void (**)(volatile signed __int32 *))(*v17 + 4))(v17);
    }
  }
  **(_DWORD **)(v9 + 128) = 1097859072;
  v18 = acLocaleGetCurrentLocale(&text);
  LOBYTE(v29) = 5;
  v19 = std::operator+<wchar_t>(&result, L"system/locales/help/", v18);
  LOBYTE(v29) = 6;
  std::operator+<wchar_t>((std::wstring *)&v21[8], v19, L".tag");
  TagDocumentReader::TagDocumentReader(&tdr, *(std::wstring *)&v21[8]);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v29) = 9;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  *(_DWORD *)&v21[28] = 7;
  *(_DWORD *)&v21[24] = 0;
  *(_WORD *)&v21[8] = 0;
  std::wstring::assign((std::wstring *)&v21[8], L"HELP", 4u);
  v20 = TagDocumentReader::getText(&tdr, &v28, *(std::wstring *)&v21[8]);
  LOBYTE(v29) = 10;
  std::wstring::wstring((std::wstring *)&v21[8], &v20->text);
  ksgui::TextBox::setFormattedText((ksgui::TextBox *)v9, *(std::wstring *)&v21[8]);
  LOBYTE(v29) = 9;
  if ( v28.text._Myres >= 8 )
    operator delete(v28.text._Bx._Ptr);
  *(_WORD *)(v9 + 200) = 0;
  _Val[0] = v9;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, _Val);
  LOBYTE(v29) = 0;
  *(_DWORD *)(_Val[0] + 148) = this;
  std::map<std::wstring,TagDocumentText>::~map<std::wstring,TagDocumentText>(&tdr);
}
