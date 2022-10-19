#include "vector_manager.h"

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void VectorManager::Read(vector<double>& vector, const string& file_name)
{
   try
   {
      auto vec_in = ifstream(file_name);
      int n = 0;
      vec_in >> n;
      vector.resize(n);
      for (int i = 0; i < n; i++)
      {
         vec_in >> vector[i];
      }
   }
   catch (...)
   {
      throw "Error with Vector file";
   }
}

void VectorManager::Write(vector<double>& vector, const string& file_name)
{
   try
   {
      auto vec_out = ofstream(file_name);
      vec_out << fixed << setprecision(16);
      for (auto element : vector)
      {
         vec_out << element << endl;
      }
      cout << "Successful output" << std::endl;
   }
   catch (...)
   {
      throw "Error with output Vector file";
   }
   
}