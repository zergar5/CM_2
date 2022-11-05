#pragma once
#include "diag_matrix.h"

class BlockDiagMatrix : public DiagMatrix
{
   int block_size_;
public:
   void LUDecomposition();
   void setBlockSize(const int& block_size);
   int& getBlockSize();
};