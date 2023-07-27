namespace ek
{
    template <typename T>
    class SVD
    {
    private:

    public:
        Matrix<T> A;
        Matrix<T> U;
        Matrix<T> S;
        Matrix<T> V;

        // constructor
        SVD(Matrix<T> M)
        {
            A = M;
        };

        // SVD Decomposition with Golub-Reinsch method
        void Golub();

        // SVD Decomposition with Divide and Conquer method
        void DC();

        // SVD Decomposition with Jacobi method
        void Jacobi();
    };
}

#include "./Golub.h"
#include "./DC.h"
#include "./Jacobi.h"
