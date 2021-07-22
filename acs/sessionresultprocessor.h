#pragma once

class SessionResultProcessor
{
void fetchBasicResults();
SessionResult *getCompleteAIResults(SessionResult *result);
void processDragResults();
void processQualifyResults();
void processRaceResults();

};