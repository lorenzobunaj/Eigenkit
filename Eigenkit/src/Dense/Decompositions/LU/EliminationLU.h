namespace ek
{
    template <typename T>
    class EliminationLU
    {
    private:
        std::vector<Matrix<T>> operators;
        // converts the constructor inputs to a vector of matrices
        std::vector<Matrix<T>> eliminize(Matrix<T> A)
        {
            // range where algorithm can be performed
            T range = std::min(A.rows(), A.cols());

            Identity<T> id(A.rows());
            Matrix<T> U = A;
            Matrix<T> Li = id;

            for (size_t j=0; j<range-1; j++) {
                // perform Gaussian Elimination on the j-th column
                Elimination<T> M(U,j);
                U = M*U;
                Li = M*Li;
            }

            return {Li.inverse(), U};
        }
    public:
        Matrix<T> A;
        Matrix<T> L;
        Matrix<T> U;

        // special constructor
        EliminationLU(Matrix<T> M)
        {
            operators = eliminize(M);
            A = M;
            L = operators[0];
            U = operators[1];
        };
    };
}
