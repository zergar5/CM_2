#include "options_manager.h"

#include <fstream>

void OptionsManager::Read(double& relaxation, double& eps, int& max_iter, const string& file_name)
{
   try
   {
      auto options_in = ifstream(file_name);
      options_in >> relaxation;
      options_in >> eps;
      options_in >> max_iter;
   }
   catch (...)
   {
      throw "Error with Options file";
   }
}