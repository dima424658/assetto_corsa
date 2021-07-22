#include "pyinterpreter.h
void PyInterpreter::PyInterpreter(PyInterpreter *this, PyEnvironment *ienv)
{
  PyEnvironment *v3; // edi

  v3 = &this->env;
  this->correctlyInitialized = 0;
  this->env.methods._Myfirst = 0;
  this->env.methods._Mylast = 0;
  this->env.methods._Myend = 0;
  std::vector<PyMethodDef>::operator=(&this->env.methods, &ienv->methods);
  v3->name = ienv->name;
  if ( v3->methods._Myfirst != v3->methods._Mylast )
  {
    EmbModule.m_name = this->env.name;
    EmbModule.m_methods = v3->methods._Myfirst;
    if ( _PyImport_AppendInittab(this->env.name, PyInit_emb) == -1 )
      _printf("ERROR DURING PyImport_AppendInittab\n");
  }
  _Py_Initialize();
  this->correctlyInitialized = _Py_IsInitialized() != 0;
}
void PyInterpreter::~PyInterpreter(PyInterpreter *this)
{
  _Py_Finalize();
  if ( this->env.methods._Myfirst )
  {
    operator delete(this->env.methods._Myfirst);
    this->env.methods._Myfirst = 0;
    this->env.methods._Mylast = 0;
    this->env.methods._Myend = 0;
  }
}
