#pragma once

class FolderEncrypter
{
void FolderEncrypter(std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > *this);
void check(const std::wstring *dataFile, const std::wstring *filename, const std::wstring *real_file);
char checkKey(std::ifstream *file);
std::vector<char> *decryptFile(std::vector<char> *result, const std::wstring *dataFile, const std::wstring *filename);
// char __userpurge fileExists@<al>(@<ecx>, unsigned int a2@<ebx>, const std::wstring *dataFile, const std::wstring *filename);

};