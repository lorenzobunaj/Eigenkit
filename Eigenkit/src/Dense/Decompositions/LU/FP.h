namespace ek
{
    template <typename T>
    void LU<T>::FP()
    {
        init();

        // initialize index matrices
        Index<T> indr(A.rows());
        Index<T> indc(A.cols());

        for (size_t j = 0; j < range() - 1; j++)
        {
            // if the element with the max module of the j-th sub-matrix is 0, stop
            Matrix<T> Uj = U.sub(j, j, U.rows() - 1, U.cols() - 1);
            if (Uj.absMax() == 0)
            {
                break;
            }

            // perform Full Pivoting on the (j,j)-th element
            FPT<T> FP(U, indr, indc, j);
            U = FP.P * U * FP.Q;
            Li = FP.P * Li;
            P = FP.P * P;
            Q = Q * FP.Q;

            // perform Gaussian Elimination on the j-th column
            GaussT<T> E(U, j);
            Li = E * Li;
            U = E * U;
        }

        L = P * (Li.inverse());
        state = "fp";
    }
}
