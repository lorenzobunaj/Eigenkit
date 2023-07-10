namespace ek
{
    template <typename T>
    class FullPivotLU
    {
    private:
        std::vector<Matrix<T>> operators;
        // converts the constructor inputs to a vector of matrices
        std::vector<Matrix<T>> fullpivize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> Pt = id;
            Matrix<T> Qt = id;
            Matrix<T> Li = id;
            Matrix<T> U = A;
            // initialize matrix ind : ind(0,i) = ind(1,i) = i+1
            Matrix<T> ind(2, A.rows());
            for (size_t i=0; i<ind.cols(); i++) {
                ind(0,i) = i+1;
                ind(1,i) = i+1;
            }
            for (size_t j=0; j<U.cols()-1; j++) {
                // if the max element the j-th reduced matrix column is 0, stop
                if (U.sub(j,j,U.rows()-1,U.cols()-1).absMax() == 0) {
                    break;
                }
                // perform Full Pivoting on the (j,j)-th element
                FullPivot<T> FP(U, j, ind);
                U = FP.P*U*FP.Q;
                Li = FP.P*Li;
                Pt = FP.P*Pt;
                Qt = Qt*FP.Q;
                // perform Gaussian Elimination on the j-th column
                Elimination<T> M(U,j);
                Li = M*Li;
                U = M*U;
            }

            return {Pt, Qt, Pt*(Li.inverse()), U};
        }
    public:
        Matrix<T> P;
        Matrix<T> A;
        Matrix<T> Q;
        Matrix<T> L;
        Matrix<T> U;

        // special constructor
        FullPivotLU(Matrix<T> M)
        {
            operators = fullpivize(M);
            P = operators[0];
            A = M;
            Q = operators[1];
            L = operators[2];
            U = operators[3];
        };
    };
}
