namespace ek
{
    template <typename T>
    class Cholesky
    {
    private:
        bool posDefCheck (T el)
        {
            // Diagonal entries need to be real
            // Argument is not positive definite
            return ((std::imag(el) == 0) && (std::real(el) > 0));
        }

        T colSum(Matrix<T> L, size_t i, size_t j, size_t e)
        {
            T out = 0;
            for (size_t k=0; k<e; k++) {
                out += L(i,k)*std::conj(L(j,k));
            }

            return out;
        }

        Matrix<T> choleskize(Matrix<T> A)
        {
            Matrix<T> L(A.rows(), A.cols());

            for (size_t j=0; j<A.cols(); j++) {
                T cs = colSum(L,j,j,j);
                if (!posDefCheck(A(j,j)-cs)) {
                    throw std::invalid_argument("Invalid Argument");
                }
                L(j,j) = std::sqrt(A(j,j) - cs);

                for (size_t k=j+1; k<A.rows(); k++) {
                    cs = colSum(L,k,j,j);
                    L(k,j) = ((T)1)/L(j,j) * (A(k,j) - cs);
                }
            }

            return L;
        }
    public:
        Matrix<T> A;
        Matrix<T> L;

        Cholesky(Matrix<T> mtx)
        {
            A = mtx;
            L = choleskize(mtx);
        };
    };
}
