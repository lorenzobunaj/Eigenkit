namespace ek
{
    template <typename T>
    class EliminationLU
    {
    private:
        std::vector<Matrix<T>> operators;

        std::vector<Matrix<T>> eliminize(Matrix<T> A)
        {
            Identity<T> id(A.rows());

            Matrix<T> U = A;
            Matrix<T> Li = id;

            for (size_t j=0; j<U.cols()-1; j++) {
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

        EliminationLU(Matrix<T> mtx)
        {
            operators = eliminize(mtx);
            A = mtx;
            L = operators[0];
            U = operators[1];
        };
    };
}
