#pragma once
#include "diag_matrix.h"

#include <vector>

class GaussSeidel
{
public:
   static void Solve(DiagMatrix& diag_matrix, const vector<double>& F,
      vector<double>& x, const double& relaxation, const double& eps, const int& max_iter);
   static void Log(const int& i, const double& residual);
   static double CalcCond(const vector<double>& x, double& residual);
};