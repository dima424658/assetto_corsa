#pragma once

#include <vector>
#include <string>
#include <string_view>

typedef struct FILETIME
{
	unsigned long dwLowDateTime;
	unsigned long dwHighDateTime;
};

class Path
{
private:
	Path();

public:
	static void createFolder(const std::wstring_view folder);
	static void deleteFile(const std::wstring_view path);
	static char doesFilenameContainsIllegalChar(const std::wstring_view filenameToCheck);

	static bool fileExists(const std::wstring_view path, bool only_real_file = false); // = true ?
	static bool folderExists(const std::wstring_view folder);

	static std::wstring getDocumentPath();
	static std::wstring getFileName(const std::wstring_view s);
	static std::wstring getFileNameWithoutExtension(const std::wstring_view path);

	static std::vector<std::wstring> getFiles(const std::wstring_view filter);
	static std::vector<std::wstring> getFolders(const std::wstring_view folder);

	static FILETIME getLastModificationTime(const std::wstring_view path);
	static std::wstring getPath(const std::wstring_view s);
	static std::wstring getPlatformSpecificPath(const std::wstring_view path);
	static std::wstring readAllText(const std::wstring_view filename);
};