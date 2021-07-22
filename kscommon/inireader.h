#pragma once

class INIReader
{
void INIReader::INIReader(const INIReader *__that);
INIReader *INIReader::operator=(const INIReader *__that);
std::wstring *INIReader::getFileName(std::wstring *result);
void INIReader::INIReader();
void INIReader::INIReader(const std::wstring *ifilename);
void INIReader::INIReader(const std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *stream);
void INIReader::~INIReader();
void INIReader::errorReport(std::wstring message);
Curve *INIReader::getCurve(Curve *result, const std::wstring *section, const std::wstring *key);
vec2f *INIReader::getFloat2(vec2f *result, const std::wstring *section, const std::wstring *key);
vec3f *INIReader::getFloat3(vec3f *result, const std::wstring *section, const std::wstring *key);
vec4f *INIReader::getFloat4(vec4f *result, const std::wstring *section, const std::wstring *key);
double INIReader::getFloat(const std::wstring *section, const std::wstring *key);
int INIReader::getHex(const std::wstring *section, const std::wstring *key);
int INIReader::getInt(const std::wstring *section, const std::wstring *key);
void INIReader::getKeyes(std::wstring section, std::vector<std::wstring> *keyes);
void INIReader::getSections(std::vector<std::wstring> *outSections);
std::wstring *INIReader::getString(std::wstring *result, const std::wstring *section, const std::wstring *key);
void INIReader::getVector2(const std::wstring *section, const std::wstring *key, float *x, float *y);
void INIReader::getVector3(const std::wstring *section, const std::wstring *key, float *x, float *y, float *z);
bool INIReader::getVector4(const std::wstring *section, const std::wstring *key, float *x, float *y, float *z, float *w);
char INIReader::hasKey(const std::wstring *section, const std::wstring *key);
BOOL INIReader::hasSection(const std::wstring *section);
void INIReader::load(const std::wstring *filename);
void INIReader::loadEncrypt(const std::wstring *filename, const std::wstring *dataFile);
void INIReader::parse();
void INIReader::printCode();
void INIReader::setVerboseMode(bool mode);

};