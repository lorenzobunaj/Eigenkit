namespace ek
{
    template <typename T>
    class PartialPivotLU
    {
    private:
        std::vector<Matrix<T>> operators;
        // converts the constructor inputs to a vector of matrices
        std::vector<Matrix<T>> partialpivize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> U = A;
            Matrix<T> Li = id; // inverse matrix L
            Matrix<T> Pc = id; // complete matrix P
            // initialize matrix ind : ind(0,i) = ind(1,i) = i+1
            Matrix<T> ind(2, A.rows());
            for (size_t i=0; i<ind.cols(); i++) {
                ind(0,i) = i+1;
                ind(1,i) = i+1;
            }
            for (size_t j=0; j<U.cols()-1; j++) {
                // if the max element the j-th reduced column is 0, stop
                if (U.sub(j,j,U.rows()-1,j).absMax() == 0) {
                    break;
                }
                // perform Partial Pivoting on the j-th column
                PartialPivot<T> P(U.sub(j,j,U.rows()-1,U.cols()-1), j, ind);
                U = P*U;
                Pc = P*Pc;
                Li = P*Li;
                // perform Gaussian Elimination on the j-th column
                Elimination<T> M(U,j);
                U = M*U;
                Li = M*Li;
            }

            return {Pc, Pc*(Li.inverse()), U};
        }
    public:
        Matrix<T> P;
        Matrix<T> A;
        Matrix<T> L;
        Matrix<T> U;

        // special constructor
        PartialPivotLU(Matrix<T> M)
        {
            operators = partialpivize(M);
            P = operators[0];
            A = M;
            L = operators[1];
            U = operators[2];
        };
    };
}
