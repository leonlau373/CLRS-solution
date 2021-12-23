#include <iostream>
#include <array>

using namespace std;

template <typename T, size_t m_size>
array<array<T,m_size>,m_size> matrix_add(array<array<T,m_size>,m_size> A, array<array<T,m_size>,m_size> B)
{
    const size_t n = A.size();
    array<array<T,n>,n> C;

    for(int i = 0; i < n; i = i + 1)
    {
        for(int j = 0; j < n; j = j + 1)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

template <typename T, size_t m_size>
array<array<T,m_size>,m_size> square_matrix_multiply_recursive(array<array<T,m_size>,m_size> A, array<array<T,m_size>,m_size> B)
{
    const int n = A.size();
    array<array<T,n>,n> C;

    if(n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        array<array<T,n/2>,n/2> A_11;
        array<array<T,n/2>,n/2> A_12;
        array<array<T,n/2>,n/2> A_21;
        array<array<T,n/2>,n/2> A_22;
        array<array<T,n/2>,n/2> B_11;
        array<array<T,n/2>,n/2> B_12;
        array<array<T,n/2>,n/2> B_21;
        array<array<T,n/2>,n/2> B_22;

        for(int i = 0; i < n/2; i = i + 1)
        {
            for(int j = 0; j < n/2; j = j + 1)
            {
                A_11[i][j] = A[i][j];
                B_11[i][j] = B[i][j];
            }
        }

        for(int i = 0; i < n/2; i = i + 1)
        {
            for(int j = n/2; j < n; j = j + 1)
            {
                A_12[i][j-n/2] = A[i][j];
                B_12[i][j-n/2] = B[i][j];
            }
        }

        for(int i = n/2; i < n; i = i + 1)
        {
            for(int j = 0; j < n/2; j = j + 1)
            {
                A_21[i-n/2][j] = A[i][j];
                B_21[i-n/2][j] = B[i][j];
            }
        }

        for(int i = n/2; i < n; i = i + 1)
        {
            for(int j = n/2; j < n; j = j + 1)
            {
                A_22[i-n/2][j-n/2] = A[i][j];
                B_22[i-n/2][j-n/2] = B[i][j];
                cout<<A[i][j] << ' ';
            }
        }

        array<array<T,n/2>,n/2> D_11;
        array<array<T,n/2>,n/2> D_12;
        array<array<T,n/2>,n/2> D_21;
        array<array<T,n/2>,n/2> D_22;
        array<array<T,n/2>,n/2> E_11;
        array<array<T,n/2>,n/2> E_12;
        array<array<T,n/2>,n/2> E_21;
        array<array<T,n/2>,n/2> E_22;

        D_11 = square_matrix_multiply_recursive(A_11,B_11);
        E_11 = square_matrix_multiply_recursive(A_12,B_21);
        D_12 = square_matrix_multiply_recursive(A_11,B_12);
        E_12 = square_matrix_multiply_recursive(A_12,B_22);
        D_21 = square_matrix_multiply_recursive(A_21,B_11);
        E_21 = square_matrix_multiply_recursive(A_22,B_21);
        D_22 = square_matrix_multiply_recursive(A_21,B_12);
        E_22 = square_matrix_multiply_recursive(A_22,B_22);

        for(int i = 0; i < n/2; i = i + 1)
        {
            for(int j = 0; j < n/2; j = j + 1)
            {
                C[i][j] = D_11[i][j] + E_11[i][j];
            }
        }

        for(int i = 0; i < n/2; i = i + 1)
        {
            for(int j = n/2; j < n; j = j + 1)
            {
                C[i][j] = D_12[i][j-n/2] + E_12[i][j-n/2];
            }
        }

        for(int i = n/2; i < n; i = i + 1)
        {
            for(int j = 0; j < n/2; j = j + 1)
            {
                C[i][j] = D_21[i-n/2][j] + E_21[i-n/2][j];
            }
        }

        for(int i = n/2; i < n; i = i + 1)
        {
            for(int j = n/2; j < n; j = j + 1)
            {
                C[i][j] = D_22[i-n/2][j-n/2] + E_22[i-n/2][j-n/2];
            }
        }

    }


    return C;
}

int main()
{
    array<array<int,2>,2> A{ { {1,2},{2,3} } };
    array<array<int,2>,2> B{ { {1,2},{2,3} } };

    array<array<int,2>,2> C = square_matrix_multiply_recursive(A,B);
    return 0;
}
