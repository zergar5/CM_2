#pragma once
#include "file_manager.h"

using namespace std;

class VectorManager : FileManager
{
public:
   static void Read(vector<double>& vector, const string& file_name);
   static void Write(vector<double>& vector, const string& file_name);
};