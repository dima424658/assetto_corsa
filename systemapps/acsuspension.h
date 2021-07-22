#pragma once

class ACSuspension
{
void ACSuspension::ACSuspension(CarAvatar *icar);
ACSuspension *ACSuspension::`vector deleting destructor'(unsigned int a2);
void ACSuspension::~ACSuspension();
// void __userpurge ACSuspension::render(@<ecx>, int a2@<esi>, float dt);
void ACSuspension::renderWireframe();
void ACSuspension::renderCamber(GLRenderer *gl, vec3f pos, int index);
void ACSuspension::renderTyreTemp(const vec3f *basePos, int index);
void ACSuspension::drawBumpGraph(GLRenderer *gl, const vec3f *basepos, std::vector<float> *data);

};