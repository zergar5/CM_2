#pragma once
#include "file_manager.h"

class MatrixManager : FileManager
{
public:
   static void Read(DiagMatrix& diag_matrix, const string& file_name);
};
