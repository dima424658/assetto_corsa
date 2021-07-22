#pragma once

class DebugVisualizer
{
void DebugVisualizer::DebugVisualizer(Sim *aSim);
void DebugVisualizer::~DebugVisualizer();
DebugVisualizer *DebugVisualizer::`vector deleting destructor'(char *this, unsigned int a2);
DebugVisualizer *DebugVisualizer::`vector deleting destructor'(unsigned int a2);
void DebugVisualizer::addLine(const DebugLine *line, int layer);
void DebugVisualizer::addString(DebugString *aString, int layer);
void DebugVisualizer::renderDebugInfo(const OnNodeRenderEvent *message);
void DebugVisualizer::previousLayer();

};