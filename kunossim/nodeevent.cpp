#include "nodeevent.h"
void NodeEvent::NodeEvent(NodeEvent *this, std::wstring n)
{
  bool v3; // cf

  Node::Node(this, &n);
  v3 = n._Myres < 8;
  this->__vftable = (NodeEvent_vtbl *)&NodeEvent::`vftable';
  this->evOnRender.handlers._Myfirst = 0;
  this->evOnRender.handlers._Mylast = 0;
  this->evOnRender.handlers._Myend = 0;
  if ( !v3 )
    operator delete(n._Bx._Ptr);
}
NodeEvent *NodeEvent::`vector deleting destructor'(NodeEvent *this, unsigned int a2)
{
  std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *v3; // edi

  this->__vftable = (NodeEvent_vtbl *)&NodeEvent::`vftable';
  v3 = (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnRender;
  if ( this->evOnRender.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnRender);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      v3,
      v3->_Myfirst,
      v3->_Mylast);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  Node::~Node(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void NodeEvent::render(NodeEvent *this, RenderContext *rc)
{
  OnNodeRenderEvent ev; // [esp+8h] [ebp-8h] BYREF

  if ( this->isActive )
  {
    ev.node = this;
    ev.renderContext = rc;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnRender, (const OnGearRequestEvent *)&ev);
  }
  Node::render(this, rc);
}
