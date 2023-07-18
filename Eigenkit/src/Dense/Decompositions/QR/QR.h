namespace ek
{
    template <typename T>
    class QR
    {
    private:
        std::string state = "";

        // returns range where decompositions can be performed
        T range()
        {
            return std::min(A.rows(), A.cols());
        }

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
            v = a + (a(0)/std::abs(a(0)))* a.norm(2)*e;

            return v;
        }

    public:
        Matrix<T> A;
        Matrix<T> P;
        Matrix<T> Q;
        Matrix<T> R;

        // constructor
        QR(Matrix<T> M)
        {
            A = M;
        };

        // QR Decomposition with Householder reflections
        void HR();

        // QR Decomposition with Column Pivoting
        void CP();

        // QR Decomposition with Givens rotations
        void GR();

        // QR Decomposition with Gram-Schmidt method
        void GS();

        Vector<T> solve(Vector<T>);
    };
}

#include "./HR.h"
#include "./CP.h"
#include "./GR.h"
#include "./GS.h"
