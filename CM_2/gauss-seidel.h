#pragma once
#include "diag_matrix.h"

#include <string>
#include <vector>

using namespace std;

class GaussSeidel
{
   double relaxation_;
   double eps_;
   int max_iter_;
   vector<double> initial_approximation_;
public:
   GaussSeidel(const string& file_name_approximation, const string& file_name_options);
   vector<double> Solve(DiagMatrix& diag_matrix, const vector<double>& F);
   void Log(int i, double residual);
};