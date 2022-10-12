#include "jacobi.h"

#include "iterator.h"
#include "options_manager.h"
#include "vector_manager.h"
#include "ñalculator.h"

#include <iostream>

Jacobi::Jacobi(const string& file_name_approximation, const string& file_name_options)
{
   VectorManager::Read(initial_approximation_, file_name_approximation);
   OptionsManager::Read(relaxation_, eps_, max_iter_, file_name_options);
}

vector<double> Jacobi::Solve(DiagMatrix& diag_matrix, const vector<double>& F)
{
   auto current_x = vector<double>(initial_approximation_.size(), 0);
   auto next_x = vector<double>(initial_approximation_.size(), 0);
   cout << "Jacobi method start" << endl;

   auto residual = DBL_MAX;
   for (int i = 0; i <= max_iter_ && residual > eps_; i++)
   {
      Iterator::NextIteration(current_x, next_x, diag_matrix, F, relaxation_);
      residual = Calculator::CalcResidual(diag_matrix, next_x, F);
      current_x = next_x;
      Log(i, residual);
   }
   cout << "Jacobi method end" << endl;
   return current_x;
}

void Jacobi::Log(int i, double residual)
{
   cout << "Iteration number: " << i << " Residual: " << residual << endl;
}
