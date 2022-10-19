#pragma once
#include "diag_matrix.h"

#include <vector>

using namespace std;

class Iterator
{
public:
   static void NextIteration(const vector<double>& current_x, vector<double>& next_x,
      DiagMatrix& diag_matrix, const vector<double>& F, const double& relaxation);
   static void NextIteration(vector<double>& current_x,
      DiagMatrix& diag_matrix, const vector<double>& F, const double& relaxation);
};