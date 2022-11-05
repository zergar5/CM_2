#include "options_manager.h"

#include <fstream>

void OptionsManager::Read(double& relaxation, double& eps, int& max_iter, int& block_size, const string& file_name)
{
   try
   {
      auto options_in = ifstream(file_name);
      options_in >> relaxation;
      options_in >> eps;
      options_in >> max_iter;
      options_in >> block_size;
   }
   catch (...)
   {
      throw "Error with Options file";
   }
}