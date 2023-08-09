namespace ek
{
    template <typename T>
    class Bidiag
    {
    private:
        // creates the vector v used in the Householder reflection
        Vector<T> refVector(Matrix<T> M)
        {
            // initialize vectors used in Householder reflection
            Vector<T> v(0);
            Vector<T> a(0);
            Vector<T> e(M.rows(), 0);
            e(0) = 1;

            // prepare the vector v for the Householder transformation
            a = M.col(0);
            e.newSize(M.rows());
            v = a + (a(0) / std::abs(a(0))) * a.norm(2) * e;

            return v;
        }

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

        // Bidiagonalization with Golub-Kahan-Lanczos method
        void Lanczos(Vector<T> vec, T e=5);
    };
}

#include "./Lanczos.h"
