#pragma once
#include <vector>

#include "block_diag_matrix.h"

class BlockRelaxation
{
public:
   static void Solve(BlockDiagMatrix& diag_matrix, const vector<double>& F,
      vector<double>& x, const double& relaxation, const double& eps, const int& max_iter);
   static void Log(const int& i, const double& residual);
   static double CalcCond(const vector<double>& x, double& residual);
   static void CalcBlockPart(BlockDiagMatrix& diag_matrix, const vector<double>& F, vector<double>& x, vector<double>& r, const int& k0, const int& k1);
   static void SolveSLAE(BlockDiagMatrix& diag_matrix, vector<double>& r, const double& relaxation, const int& k0, const int& k1);
};