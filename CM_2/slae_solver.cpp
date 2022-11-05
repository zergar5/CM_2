#include "slae_solver.h"

void SLAESolver::CalcZ(BlockDiagMatrix& block_diag_matrix, vector<double>& r,
   const int& k0, const int& k1)
{
   auto& matrix = block_diag_matrix.getDiagMatrix();

   int j = 0;
   auto& z = r;
   z[j] = r[j] / matrix[3][k0];
   j++;
   for (int i = k0 + 1; i < k1; i++, j++)
   {
      z[j] = (r[j] - matrix[2][i] * z[j - 1]) / matrix[3][i];
   }
}

void SLAESolver::CalcY(BlockDiagMatrix& block_diag_matrix, vector<double>& z,
   const int& k0, const int& k1)
{
   auto& matrix = block_diag_matrix.getDiagMatrix();
   auto& block_size = block_diag_matrix.getBlockSize();

   auto j = block_size;
   auto& y = z;
   y[j - 1] = z[j - 1];
   j -= 2;
   for (int i = k1 - 2; i >= k0; i--, j--)
   {
      y[j] -= matrix[4][i] * y[j + 1];
   }
}