#pragma once

class TagDocumentReader
{
void TagDocumentReader(std::wstring inputFile);
void TagDocumentReader();
TagDocumentText *getText(TagDocumentText *result, std::wstring key);
void load(std::wstring inputFile);

};