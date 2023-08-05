namespace ek
{
    template <typename T>
    class Bidiag
    {
    private:
        void init()
        {
            Matrix<T> null;
            U = null;
            L = null;
            V = null;
        }

    public:
        Matrix<T> A;
        Matrix<T> U;
        Matrix<T> L;
        Matrix<T> V;

        // constructor
        Bidiag(Matrix<T> M)
        {
            A = M;
        };

        // Bidiagonalization with Golub-Kahan method
        void GolubKahan(T e=5);
    };
}

#include "./GolubKahan.h"
