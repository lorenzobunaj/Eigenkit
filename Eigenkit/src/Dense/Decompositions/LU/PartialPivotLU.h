namespace ek
{
    template <typename T>
    class PartialPivotLU
    {
    private:
        std::vector<Matrix<T>> operators;

        std::vector<Matrix<T>> partialpivize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> U = A;
            Matrix<T> Li = id;
            Matrix<T> Pt = id;

            Matrix<T> ind(2, A.rows());
            for (size_t i=0; i<ind.cols(); i++) {
                ind(0,i) = i+1;
                ind(1,i) = i+1;
            }

            for (size_t j=0; j<U.cols()-1; j++) {
                if (U.sub(j,j,U.rows()-1,j).absMax() == 0) {
                    break;
                }

                PartialPivot<T> P(U.sub(j,j,U.rows()-1,U.cols()-1), j, ind);
                U = P*U;
                Pt = P*Pt;
                Li = P*Li;

                Elimination<T> M(U,j);
                U = M*U;
                Li = M*Li;
            }

            return {Pt, Pt*(Li.inverse()), U};
        }
    public:
        Matrix<T> P;
        Matrix<T> A;
        Matrix<T> L;
        Matrix<T> U;

        PartialPivotLU(Matrix<T> mtx)
        {
            operators = partialpivize(mtx);
            P = operators[0];
            A = mtx;
            L = operators[1];
            U = operators[2];
        };
    };
}
