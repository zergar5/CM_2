#include "block_diag_matrix.h"

#include <iostream>

void BlockDiagMatrix::LUDecomposition()
{
   int n = n_ / block_size_;
   for (int i = 0; i < n; i++) //���� ������ ������� �� ������
   {
      int k0 = i * block_size_;
      int k1 = (i + 1) * block_size_;
      for (int j = k0 + 1; j < k1; j++) // ���� ������ ����� (� 1 ������ ��� ������ ii ������� ��� �� �����)
      {
         diag_matrix_[4][j - 1] /= diag_matrix_[3][j - 1];
         diag_matrix_[3][j] -= diag_matrix_[4][j - 1] * diag_matrix_[2][j];
      }
   }
}

void BlockDiagMatrix::setBlockSize(const int& block_size)
{
   if (block_size < 3 + m_ && n_ % block_size == 0)
   {
      this->block_size_ = block_size;
   }
   else
   {
      cout << "Wrong block size" << endl;
      exit(-1);
   }
}

int& BlockDiagMatrix::getBlockSize()
{
   return this->block_size_;
}