#include "block_relaxation.h"
#include "iterator.h"
#include "slae_solver.h"

#include <iomanip>
#include <iostream>

void BlockRelaxation::Solve(BlockDiagMatrix& block_diag_matrix, const vector<double>& F, vector<double>& x, const double& relaxation, const double& eps, const int& max_iter)
{
   cout << "Block Relaxation method start" << endl;
   block_diag_matrix.LUDecomposition();
   auto residual = DBL_MAX;
   for (int i = 0; i <= max_iter && residual > eps; i++)
   {
      residual = Iterator::NextIteration(x, block_diag_matrix, F, relaxation);
      Log(i, residual);
   }
   auto cond = CalcCond(x, residual);
   cout << endl << "Cond: " << fixed << setprecision(16) << cond << endl;
   cout << "Block Relaxation method end" << endl;
}

void BlockRelaxation::Log(const int& i, const double& residual)
{
   cout << "Iteration number: " << i << " Residual: " << fixed << setprecision(16) << residual << "\r";
}

double BlockRelaxation::CalcCond(const vector<double>& x, double& residual)
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

void BlockRelaxation::CalcBlockPart(BlockDiagMatrix& block_diag_matrix, const vector<double>& F, vector<double>& x, vector<double>& r, const int& k0, const int& k1)
{
   auto& n = block_diag_matrix.getSize();
   auto& matrix = block_diag_matrix.getDiagMatrix();
   auto& indexes = block_diag_matrix.getIndexes();
   auto k = 0;
   for (int i = k0; i < k1; i++, k++)
   {
      auto sum = 0.0;
      for (int j = 3; j < 5; j++)
      {
         if (indexes[j] + i >= 0 && indexes[j] + i < n)
         {
            if (indexes[j] + i >= k0 && indexes[j] + i < k1)
            {
               if (j == 3)
               {
                  sum += 1.0 * x[indexes[j] + i];
               }
               else
               {
                  sum += matrix[j][i] * x[indexes[j] + i];
               }
            }
         }
      }
      r[k] = sum;
   }
   auto buf = r;
   k = 0;
   for (int i = k0; i < k1; i++, k++)
   {
      auto sum = 0.0;
      for (int j = 2; j < 4; j++)
      {
         if (indexes[j] + i >= 0 && indexes[j] + i < n)
         {
            if (indexes[j] + i >= k0 && indexes[j] + i < k1)
            {
               sum += matrix[j][i] * buf[indexes[j] + k];
            }
         }
      }
      r[k] = sum;
   }
}

void BlockRelaxation::SolveSLAE(BlockDiagMatrix& block_diag_matrix, vector<double>& y, const double& relaxation, const int& k0, const int& k1)
{
   SLAESolver::CalcZ(block_diag_matrix, y, k0, k1);
   SLAESolver::CalcY(block_diag_matrix, y, k0, k1);
}