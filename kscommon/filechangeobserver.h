#pragma once

class FileChangeObserver
{
void FileChangeObserver(const std::wstring *a_filename);
char hasChanged();
void observe(const std::wstring *a_filename);
void reset();

};