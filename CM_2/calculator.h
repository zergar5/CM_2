#pragma once
#include "diag_matrix.h"

#include <vector>

using namespace std;

class Calculator
{
public:
   static double CalcResidual(DiagMatrix& diag_matrix, const vector<double>& x, const vector<double>& F);
   static double CalcCond(DiagMatrix& diag_matrix, const vector<double>& next_x, const vector<double>& F);
   static double CalcNorm(const vector<double>& vec);
   static void Multiply(DiagMatrix& diag_matrix, const vector<double>& x, vector<double>& result);
   static void Subtract(const vector<double>& F, const vector<double>& Ax, vector<double>& result);
};