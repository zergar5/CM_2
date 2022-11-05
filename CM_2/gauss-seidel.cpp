#include "gauss-seidel.h"
#include "iterator.h"

#include <iostream>
#include <iomanip>

void GaussSeidel::Solve(DiagMatrix& diag_matrix, const vector<double>& F,
   vector<double>& x, const double& relaxation, const double& eps, const int& max_iter)
{
   cout << "Gauss-Seidel method start" << endl;

   auto residual = DBL_MAX;
   for (int i = 0; i <= max_iter && residual > eps; i++)
   {
      residual = Iterator::NextIteration(x, diag_matrix, F, relaxation);
      Log(i, residual);
   }
   auto cond = CalcCond(x, residual);
   cout << endl << "Cond: " << fixed << setprecision(16) << cond << endl;
   cout << "Gauss-Seidel method end" << endl;
}

void GaussSeidel::Log(const int& i, const double& residual)
{
   cout << "Iteration number: " << i << " Residual: " << fixed << setprecision(16) << residual << "\r";
}

double GaussSeidel::CalcCond(const vector<double>& x, double& residual)
{
   double x_star_norm = 0.0;
   double x_sub_x_star_norm = 0.0;
   for (int i = 0; i < x.size(); i++)
   {
      x_star_norm += static_cast<double>(i + 1) * static_cast<double>(i + 1);
      x_sub_x_star_norm += (x[i] - static_cast<double>(i + 1)) * (x[i] - static_cast<double>(i + 1));
   }
   x_star_norm = sqrt(x_star_norm);
   x_sub_x_star_norm = sqrt(x_sub_x_star_norm);
   auto error = x_sub_x_star_norm / x_star_norm;
   return error / residual;
}