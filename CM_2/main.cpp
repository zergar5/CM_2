#include "diag_matrix.h"
#include "gauss-seidel.h"
#include "jacobi.h"
#include "options_manager.h"
#include "vector_manager.h"
using namespace std;

int main()
{
   vector<double> x1;
   vector<double> x2;
   vector<double> F;
   double relaxation;
   double eps;
   int max_iter;
   DiagMatrix diag_matrix = DiagMatrix();
   diag_matrix.MemoryAllocated("matrix.txt");
   VectorManager::Read(F, "vectorF.txt");
   VectorManager::Read(x1, "start_vector.txt");
   x2 = x1;
   OptionsManager::Read(relaxation, eps, max_iter, "options.txt");
   Jacobi::Solve(diag_matrix, F, x1, relaxation, eps, max_iter);
   VectorManager::Write(x1, "jacobi_output.txt");
   GaussSeidel::Solve(diag_matrix, F, x2, relaxation, eps, max_iter);
   VectorManager::Write(x2, "gauss_seidel_output.txt");
}