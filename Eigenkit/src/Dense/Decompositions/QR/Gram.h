namespace ek
{
    template <typename T>
    void QR<T>::Gram()
    {
        // initialize class matrices
        // letter "t" near the matrix name means "temporary"
        Identity<T> idr(A.cols());
        Matrix<T> Qt(A.rows(), A.cols());
        Matrix<T> Rt(A.cols(), A.cols());
        P = idr;
        Q = Qt;
        R = Rt;
        GramT<T> G(A);

        for (size_t j = 0; j < A.cols(); j++)
        {
            // check if the L2 norm will be 0
            if (G.row(j).absMax() == 0)
            {
                throw std::invalid_argument("Invalid Decomposition");
            }

            // find the L2 norm of matrix G's j-th column
            Vector<T> r;
            r = G.row(j);
            T n = r.norm(2);

            // Q[:][j] = G[j][:] / n
            for (size_t i = 0; i < A.rows(); i++)
            {
                Q(i, j) = G(j, i) / n;
            }
        }

        Vector<T> op1;
        Vector<T> op2;
        // R(i,j) = 0 if i > j else A[:][j] * Q[:][i]
        for (size_t i = 0; i < A.rows(); i++)
        {
            for (size_t j = i; j < A.cols(); j++)
            {
                op1 = A.col(j);
                op2 = Q.col(i);
                R(i, j) = op1.dot(op2);
            }
        }
    }
}
