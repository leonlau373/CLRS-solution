#include <iostream>
#include <array>

using namespace std;

template<typename T, size_t matrix_size>
array<array<T,matrix_size>,matrix_size> square_matrix_multiply(array<array<T,matrix_size>,matrix_size> A, array<array<T,matrix_size>,matrix_size> B)
{
    const int n = A.size();
    array<array<T,n>,n> C;

    for(int i = 0; i < n; i = i + 1)
    {
        for(int j = 0; j < n; j = j + 1)
        {
            C[i][j] = 0;
            for(int k = 0; k < n; k = k + 1)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    return C;
}


int main()
{
    array<array<int,3>,3> A { { {2,3,4}, {1,3,5}, {-2,1,4} } };
    array<array<int,3>,3> B { { {2,3,4}, {1,3,5}, {-2,1,4} } };

    array<array<int,3>,3> C = square_matrix_multiply(A,B);

    for(int i = 0; i < C.size(); i = i + 1)
    {
        for(int j = 0; j < C.size(); j = j + 1)
        {
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
