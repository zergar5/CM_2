#pragma once
#include "diag_matrix.h"

#include <string>

static class FileManager
{
public:
   virtual void Read(DiagMatrix& diag_matrix, string& file_name) = 0;
   virtual void Read(vector<double>& vector, string& file_name) = 0;
   virtual void Read(double& relaxation, double& eps, string& file_name) = 0;
   virtual void Write(vector<double>& vector, string& file_name) = 0;
};