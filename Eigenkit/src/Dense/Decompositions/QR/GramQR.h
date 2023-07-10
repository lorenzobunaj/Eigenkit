namespace ek
{
    template <typename T>
    class GramQR
    {
    private:
        std::vector<Matrix<T>> operators;
        // converts the constructor inputs to a vector of matrices
        std::vector<Matrix<T>> gramize(Matrix<T> A)
        {
            Matrix<T> Q(A.rows(), A.cols());
            Matrix<T> R(A.rows(), A.cols());
            Gram<T> G(A);

            for (size_t j=0; j<A.cols(); j++) {
                // find the L2 norm of matrix G's j-th column
                Vector<T> r = G.mtx()[j];
                T n = r.norm(2);
                // Q's j-th column = G's j-th row / n
                for (size_t i=0; i<A.rows(); i++) {
                    Q(i,j) = G(j,i)/n;
                }
            }

            // R(i,j) = 0 if i > j else A j-th column * Q i-th row
            Vector<T> op1;
            Vector<T> op2;
            for (size_t i=0; i<A.rows(); i++) {
                for (size_t j=i; j<A.cols(); j++) {
                    op1 = A.col(j).mtx();
                    op2 = Q.col(i).mtx();
                    R(i,j) = op1.dot(op2);
                }
            }

            return {Q, R};
        }
    public:
        Matrix<T> A;
        Matrix<T> Q;
        Matrix<T> R;

        // special constructor
        GramQR(Matrix<T> mtx)
        {
            operators = gramize(mtx);
            A = mtx;
            Q = operators[0];
            R = operators[1];
        };
    };
}

