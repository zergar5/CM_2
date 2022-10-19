#include "gauss-seidel.h"

#include "iterator.h"
#include "calculator.h"

#include <iostream>
#include <iomanip>

void GaussSeidel::Solve(DiagMatrix& diag_matrix, const vector<double>& F,
   vector<double>& x, const double& relaxation, const double& eps, const int& max_iter)
{
   cout << "Gauss-Seidel method start" << endl;

   auto residual = DBL_MAX;
   for (int i = 0; i <= max_iter && residual > eps; i++)
   {
      Iterator::NextIteration(x, diag_matrix, F, relaxation);
      residual = Calculator::CalcResidual(diag_matrix, x, F);
      Log(i, residual);
   }
   auto cond = Calculator::CalcCond(diag_matrix, x, F);
   cout << endl << "Cond: " << fixed << setprecision(16) << cond << endl;
   cout << "Gauss-Seidel method end" << endl;
}

void GaussSeidel::Log(const int& i, const double& residual)
{
   cout << "Iteration number: " << i << " Residual: " << fixed << setprecision(16) << residual << "\r";
}