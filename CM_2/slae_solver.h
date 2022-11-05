#pragma once
#include "block_diag_matrix.h"

class SLAESolver
{
public:
   static void CalcZ(BlockDiagMatrix& block_diag_matrix, vector<double>& r,
      const int& k0, const int& k1);
   static void CalcY(BlockDiagMatrix& block_diag_matrix, vector<double>& z,
      const int& k0, const int& k1);
};