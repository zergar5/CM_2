#include <chrono>

#include "block_relaxation.h"
#include "diag_matrix.h"
#include "gauss-seidel.h"
#include "jacobi.h"
#include "options_manager.h"
#include "vector_manager.h"

using namespace std;
using namespace chrono;

int main()
{
   vector<double> x1;
   vector<double> x2;
   vector<double> x3;
   vector<double> F;
   double relaxation;
   double eps;
   int max_iter;
   int block_size;

   auto diag_matrix = DiagMatrix();
   diag_matrix.MemoryAllocated("matrix_block.txt");

   auto block_diag_matrix = BlockDiagMatrix();
   block_diag_matrix.MemoryAllocated("matrix_block.txt");

   VectorManager::Read(F, "vectorF_block.txt");
   VectorManager::Read(x1, "start_vector.txt");
   x2 = x1;
   x3 = x1;

   OptionsManager::Read(relaxation, eps, max_iter, block_size, "options.txt");
   block_diag_matrix.setBlockSize(block_size);

   /*Jacobi::Solve(diag_matrix, F, x1, relaxation, eps, max_iter);
   VectorManager::Write(x1, "jacobi_output.txt");*/

   GaussSeidel::Solve(diag_matrix, F, x2, relaxation, eps, max_iter);
   VectorManager::Write(x2, "gauss_seidel_output.txt");

   BlockRelaxation::Solve(block_diag_matrix, F, x3, relaxation, eps, max_iter);

   VectorManager::Write(x3, "block_relaxation_output.txt");
}