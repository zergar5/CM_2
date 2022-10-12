#include "gauss-seidel.h"

#include "iterator.h"
#include "options_manager.h"
#include "vector_manager.h"
#include "ñalculator.h"

#include <iostream>

GaussSeidel::GaussSeidel(const string& file_name_approximation, const string& file_name_options)
{
   VectorManager::Read(initial_approximation_, file_name_approximation);
   OptionsManager::Read(relaxation_, eps_, max_iter_, file_name_options);
}

vector<double> GaussSeidel::Solve(DiagMatrix& diag_matrix, const vector<double>& F)
{
   
   auto current_x = vector<double>(initial_approximation_.size(), 0);
   cout << "Gauss-Seidel method start" << endl;

   auto residual = DBL_MAX;
   for (int i = 0; i <= max_iter_ && residual > eps_; i++)
   {
      Iterator::NextIteration(current_x, diag_matrix, F, relaxation_);
      residual = Calculator::CalcResidual(diag_matrix, current_x, F);
      Log(i, residual);
   }
   cout << "Gauss-Seidel method end" << endl;
   return current_x;
}

void GaussSeidel::Log(int i, double residual)
{
   cout << "Iteration number: " << i << " Residual: " << residual << endl;
}
