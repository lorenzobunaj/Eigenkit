namespace ek
{
    template <typename T>
    class PartialPivot
    {
    private:
        std::vector<Matrix<T>> operators;

        Matrix<T> indSwap (Matrix<T> mtx, size_t i, size_t j)
        {
            T temp = mtx(1,i);
            mtx(1,i) = mtx(1,j);
            mtx(1,j) = temp;

            return mtx;
        }

        std::vector<Matrix<T>> partialpivize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> Pt = id;
            Matrix<T> Li = id;
            Matrix<T> U = A;

            Matrix<T> ind(2, A.rows());
            for (size_t i=0; i<ind.cols(); i++) {
                ind(0,i) = i+1;
                ind(1,i) = i+1;
            }

            for (size_t j=0; j<U.cols()-1; j++) {
                Vector<T> c = U.sub(j, j, U.rows()-1, U.cols()-1).t().mtx()[0];
                for (size_t i=j; i<U.rows(); i++) {
                    if (U(i,j) == c.max()) {
                        Permutation<T> P(indSwap(ind,i,j));
                        Li = P*Li;
                        U = P*U;
                        Pt = P*Pt;
                        break;
                    }
                }

                Matrix<T> M = id;
                for (size_t i=j+1; i<U.cols();i++) {
                    M(i,j) = -U(i,j) * 1/U(j,j);
                }

                Li = M*Li;
                U = M*U;
            }

            return {Pt, Pt*(Li.inverse()), U};
        }
    public:
        Matrix<T> P;
        Matrix<T> A;
        Matrix<T> L;
        Matrix<T> U;

        PartialPivot(Matrix<T> mtx)
        {
            operators = partialpivize(mtx);
            P = operators[0];
            A = mtx;
            L = operators[1];
            U = operators[2];
        };
    };
}
