namespace ek
{
    template <typename T>
    class Cholesky
    {
    public:
        Matrix<T> A;
        Matrix<T> L;
        Matrix<T> D;

        // constructor
        Cholesky(Matrix<T> M)
        {
            // check if the matrix is Hermitian
            if (M != M.h())
            {
                throw std::invalid_argument("Invalid Matrix");
            };

            A = M;
        };

        // Normal Cholesky Decomposition
        void LL();

        // Cholesky Root Free Decomposition
        void LDL();

        Vector<T> solve(Vector<T>);
    };
}

#include "./LL.h"
#include "./LDL.h"
