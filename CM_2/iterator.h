#pragma once
#include "diag_matrix.h"
#include "block_diag_matrix.h"

#include <vector>

using namespace std;

class Iterator
{
public:
   static double NextIteration(DiagMatrix& diag_matrix, const vector<double>& current_x, vector<double>& next_x,
      const vector<double>& F, const double& relaxation);
   static double NextIteration(DiagMatrix& diag_matrix, vector<double>& current_x,
      const vector<double>& F, const double& relaxation);
   static double NextIteration(BlockDiagMatrix& block_diag_matrix, vector<double>& current_x,
      const vector<double>& F, const double& relaxation);
};