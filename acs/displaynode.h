#pragma once

class DisplayNode
{
void DisplayNode::DisplayNode(std::wstring a_name);
void DisplayNode::DisplayNode(std::wstring a_name, DigitalItemType a_type);
DisplayNode *DisplayNode::`vector deleting destructor'(unsigned int a2);
void DisplayNode::drawBase(RenderContext *rc, GLRenderer *gl);
void DisplayNode::drawBaseInverted(RenderContext *rc, GLRenderer *gl);
void DisplayNode::drawTop(RenderContext *rc, GLRenderer *gl);
void DisplayNode::drawTopInverted(RenderContext *rc, GLRenderer *gl);
void DisplayNode::render(RenderContext *rc);

};