#pragma once
#include "diag_matrix.h"

#include <vector>

using namespace std;

static class Iterator
{
public:
   static void NextIteration(const vector<double>& current_x, vector<double>& next_x,
      DiagMatrix& diag_matrix, const vector<double>& F, double& relaxation);
   static void NextIteration(vector<double>& current_x,
      DiagMatrix& diag_matrix, const vector<double>& F, double& relaxation);
};
