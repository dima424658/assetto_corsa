#include "crashguard.h
void __userpurge CrashGuard::CrashGuard(CrashGuard *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *pdbName)
{
  this->__vftable = (CrashGuard_vtbl *)&CrashGuard::`vftable';
  if ( Path::fileExists(a2, pdbName, 0) )
  {
    _printf("Installing CrashGuard Fault Handler\n");
    InstallFaultHandler();
    CrashGuard::isTracking = 1;
  }
}
void CrashGuard::~CrashGuard(CrashGuard *this)
{
  this->__vftable = (CrashGuard_vtbl *)&CrashGuard::`vftable';
  _fflush(0);
}
CrashGuard *CrashGuard::`scalar deleting destructor'(CrashGuard *this, unsigned int a2)
{
  this->__vftable = (CrashGuard_vtbl *)&CrashGuard::`vftable';
  _fflush(0);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
