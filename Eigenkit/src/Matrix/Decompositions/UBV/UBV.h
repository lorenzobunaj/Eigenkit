namespace ek
{
    template <typename T>
    class UBV
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

        // returns range where decompositions can be performed
        T range()
        {
            return std::min(A.rows(), A.cols());
        }

    public:
        Matrix<T> A;
        Matrix<T> U;
        Matrix<T> B;
        Matrix<T> V;

        // constructor
        UBV(Matrix<T> M)
        {
            A = M;
        };

        // Bidiagonalization with Golub-Kahan-Lanczos method
        void Lanczos(Vector<T> vec, T e=5);

        // Bidiagonalization with Householder method
        void Householder();
    };
}

#include "./LanczosUBV.h"
#include "./HouseholderUBV.h"
