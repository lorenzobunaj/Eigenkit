namespace ek
{
    template <typename T>
    class DU
    {
    private:
        std::vector<Matrix<T>> operators;
        // converts the constructor inputs to a vector of matrices
        std::vector<Matrix<T>> duize(Matrix<T> A)
        {
            Matrix<T> U = A;
            Matrix<T> D(A.rows(), A.cols());

            for (size_t i=0; i<A.cols(); i++) {
                // insert A's diagonal elements in D's diagonal
                D(i,i) = A(i,i);
                // divide A's elements by the diagonal ones
                for (size_t j=i; j<A.rows(); j++) {
                    U(i,j) =A(i,j)/D(i,i);
                }
            }

            return {D, U};
        }
    public:
        Matrix<T> D;
        Matrix<T> U;

        // special constructor
        DU(Matrix<T> M)
        {
            operators = duize(M);
            D = operators[0];
            U = operators[1];
        };
    };
}
