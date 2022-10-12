#pragma once
#include "diag_matrix.h"

#include <vector>

using namespace std;

static class Calculator
{
public:
   static double CalcResidual(DiagMatrix& diag_matrix, const vector<double>& next_x, const vector<double>& F);
   static double CalcNorm(const vector<double>& vec);
   static vector<double> Multiply(DiagMatrix& diag_matrix, const vector<double>& next_x);
   static vector<double> Subtract(const vector<double>& F, const vector<double>& Ax);
};
