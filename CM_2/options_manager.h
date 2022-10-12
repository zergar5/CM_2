#pragma once
#include "file_manager.h"

#include <string>

using namespace std;

static class OptionsManager : FileManager
{
public:
   static void Read(double& relaxation, double& eps, int& max_iter, const string& file_name);
};
