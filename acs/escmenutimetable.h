#pragma once

class EscMenuTimeTable
{
// void __userpurge EscMenuTimeTable::EscMenuTimeTable(@<ecx>, unsigned int a2@<ebx>, Sim *aSim);
void EscMenuTimeTable::~EscMenuTimeTable();
EscMenuTimeTable *EscMenuTimeTable::`vector deleting destructor'(unsigned int a2);
void EscMenuTimeTable::onVisibleChanged(BOOL newValue);
void EscMenuTimeTable::refreshPlayer();
void EscMenuTimeTable::refreshSession();
void EscMenuTimeTable::render(float dt);

};