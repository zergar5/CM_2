
#include "diag_matrix.h"
#include "gauss-seidel.h"
#include "jacobi.h"
#include "vector_manager.h"
using namespace std;

int main()
{
   DiagMatrix diag_matrix = DiagMatrix("matrix.txt");
   vector<double> F;
   VectorManager::Read(F, "vectorF.txt");
   Jacobi jacobi = Jacobi("start_vector.txt", "options.txt");
   auto jacobi_solution = jacobi.Solve(diag_matrix, F);
   VectorManager::Write(jacobi_solution, "jacobi_output.txt");
   GaussSeidel gauss_seidel = GaussSeidel("start_vector.txt", "options.txt");
   auto gauss_seidel_solution = gauss_seidel.Solve(diag_matrix, F);
   VectorManager::Write(gauss_seidel_solution, "gauss_seidel_output.txt");
}
