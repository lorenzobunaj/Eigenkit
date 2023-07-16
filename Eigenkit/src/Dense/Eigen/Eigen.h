namespace ek
{
    template <typename T>
    class Eigen
    {
    private:
        // finds the Rayleigh quotient
        T Rayleigh(Matrix<T> A, Matrix<T> x)
        {
            // initialize the operators
            Vector<T> op1;
            Vector<T> op2;
            op1 = A*x;
            op2 = x;

            return (op1.dot(op2))/(op2.dot(op2));
        }

        // finds if the Jacobi or QR method converged
        bool jqrConv(Matrix<T> A, T e)
        {
            // initialize the norms
            T frobNorm = 0;
            T diagNorm = 0;

            // find the values of the 2 norms (over the diagonal and Frobenius's
            for (size_t i=0; i<A.rows(); i++) {
                for (size_t j=0; j<A.cols(); j++) {
                    frobNorm += std::pow(A(i,j),2);
                    diagNorm += i==j ? A(i,j) : 0;
                }
            }

            return (std::abs(frobNorm-diagNorm)/A.rows() <= e);
        }

    public:
        Matrix<T> A;

        // constructor
        Eigen(Matrix<T> M)
        {
            A = M;
        };

        // finds the dominant eigenvalue with Power method
        T Dominant(size_t, T);

        // finds the eigenvalues with Jacobi method
        std::vector<T> Jacobi(size_t, T);

        // finds the eigenvalues with QR method
        std::vector<T> QRE(std::string, size_t, T);
    };
}

#include "./Dominant.h"
#include "./Jacobi.h"
#include "./QR.h"
