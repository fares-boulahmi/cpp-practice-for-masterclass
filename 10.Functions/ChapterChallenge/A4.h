#include <vector>
using namespace std;

int** createMatrix(int rows, int cols);
void fillMatrix(int** matrix, int rows, int cols, const int* values);
int** transposeMatrix(int** matrix, int rows, int cols);
void calculateRowSums(int** matrix, int rows, int cols, vector<int>& sums);
void deleteMatrix(int**& matrix, int rows);
