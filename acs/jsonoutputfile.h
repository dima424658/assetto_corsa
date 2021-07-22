#pragma once

class JsonOutputFile
{
void JsonOutputFile::JsonOutputFile(Sim *aSim);
void JsonOutputFile::~JsonOutputFile();
JsonOutputFile *JsonOutputFile::`vector deleting destructor'(unsigned int a2);
void JsonOutputFile::addExtraSessionInfo();
void JsonOutputFile::endSession(const OnSessionEndEvent *message);
void JsonOutputFile::offlineEndSession(jsonwriter::Object *currentSession, const OnSessionEndEvent *message);
void JsonOutputFile::onlineEndSession(jsonwriter::Object *currentSession, const OnSessionEndEvent *message);
void JsonOutputFile::writeOutputFile();
void JsonOutputFile::writePlayers();

};