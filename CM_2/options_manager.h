#pragma once
#include "file_manager.h"

#include <string>

using namespace std;

class OptionsManager : FileManager
{
public:
   static void Read(double& relaxation, double& eps, int& max_iter, int& block_size, const string& file_name);
};