#pragma once

class EndSessionDisplayer
{
// void __userpurge EndSessionDisplayer::EndSessionDisplayer(@<ecx>, unsigned int a2@<ebx>, Sim *aSim);
void EndSessionDisplayer::~EndSessionDisplayer();
void EndSessionDisplayer::displayResults();
void EndSessionDisplayer::hide();
void EndSessionDisplayer::renderHUD(float dt);
void EndSessionDisplayer::update(float dt);

};