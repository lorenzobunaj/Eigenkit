namespace ek
{
    template <typename T>
    class SVD
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
        void GolubSVD();

        // SVD Decomposition with Divide and Conquer method
        void DCSVD();

        // SVD Decomposition with Jacobi method
        void JacobiSVD();
    };
}

#include "./GolubSVD.h"
#include "./DCSVD.h"
#include "./JacobiSVD.h"
