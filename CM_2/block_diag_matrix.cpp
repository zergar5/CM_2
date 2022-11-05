#include "block_diag_matrix.h"

void BlockDiagMatrix::LUDecomposition()
{
   int n = n_ / block_size_;
   for (int i = 0; i < n; i++) //цикл обхода матрицы по блокам
   {
      int k0 = i * block_size_;
      int k1 = (i + 1) * block_size_;
      for (int j = k0 + 1; j < k1; j++) // цикл обхода блока (с 1 потому что первый ii элемент тот же самый)
      {
         diag_matrix_[4][j - 1] /= diag_matrix_[3][j - 1];
         diag_matrix_[3][j] -= diag_matrix_[4][j - 1] * diag_matrix_[2][j];
      }
   }
}

void BlockDiagMatrix::setBlockSize(const int& block_size)
{
   this->block_size_ = block_size;
}

int& BlockDiagMatrix::getBlockSize()
{
   return this->block_size_;
}