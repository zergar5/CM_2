#include "jacobi.h"
#include "iterator.h"

#include <iostream>
#include <iomanip>

void Jacobi::Solve(DiagMatrix& diag_matrix, const vector<double>& F,
   vector<double>& x, const double& relaxation, const double& eps, const int& max_iter)
{
   auto next_x = vector<double>(x.size(), 0);
   cout << "Jacobi method start" << endl;

   auto residual = DBL_MAX;
   for (int i = 1; i <= max_iter && residual > eps; i++)
   {
      residual = Iterator::NextIteration(diag_matrix, x, next_x, F, relaxation);
      x = next_x;
      Log(i, residual);
   }
   auto cond = CalcCond(x, residual);
   cout << endl << "Cond: " << fixed << setprecision(16) << cond << endl;
   cout << "Jacobi method end" << endl;
}

void Jacobi::Log(const int& i, const double& residual)
{
   cout << "Iteration number: " << i << " Residual: " << fixed << setprecision(16) << residual << "\r";
}

double Jacobi::CalcCond(const vector<double>& x, double& residual)
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