namespace ek
{
    template <typename T>
    class LU
    {
    private:
        std::string state = "";
        bool ld = 0;
        bool du = 0;

        Matrix<T> Li;

        // initializes class matrices
        void init()
        {
            Identity<T> idl(A.rows());
            Identity<T> idr(A.cols());
            P = idl;
            Q = idr;
            D = idl;
            Li = idl;
            U = A;
        };

        // returns range where decompositions can be performed
        T range()
        {
            return std::min(A.rows(), A.cols());
        }

    public:
        Matrix<T> P;
        Matrix<T> A;
        Matrix<T> Q;
        Matrix<T> L;
        Matrix<T> D;
        Matrix<T> U;

        // constructor
        LU(Matrix<T> M)
        {
            A = M;
        };

        // LU Decomposition with Gaussian Elimination
        void GE();

        // LU Decomposition with Partial Pivoting
        void PP();

        // LU Decomposition with Full Pivoting
        void FP();

        // L'U -> LDU
        void LD();

        // LU' -> LDU
        void DU();
    };
}

#include "./GE.h"
#include "./PP.h"
#include "./FP.h"
#include "./LD.h"
#include "./DU.h"
