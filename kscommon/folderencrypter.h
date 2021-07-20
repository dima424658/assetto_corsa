#pragma once

#include <vector>
#include <fstream>
#include <string_view>

class FolderEncrypter // derived from ?? std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const, std::map<std::wstring, INISection> >, void*> > >
{
public:
	FolderEncrypter();
	void check(std::wstring_view dataFile, std::wstring_view filename, std::wstring_view real_file);
	char checkKey(std::ifstream* file);
	std::vector<char> decryptFile(std::wstring_view dataFile, std::wstring_view filename);
	// char __userpurge FolderEncrypter::fileExists@<al>(FolderEncrypter *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *dataFile, const std::wstring *filename);

	static std::vector<unsigned int> keys; // idb
};