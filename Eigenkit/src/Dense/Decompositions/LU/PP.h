namespace ek
{
    template <typename T>
    void LU<T>::PP()
    {
        init();

        // initialize index matrix
        Index<T> ind(A.rows());

        for (size_t j = 0; j < range() - 1; j++)
        {
            // if the element with the max module of the j-th reduced column is 0, stop
            Matrix<T> cj = U.sub(j, j, U.rows() - 1, j);
            if (cj.absMax() == 0)
            {
                break;
            }

            // perform Partial Pivoting on the j-th column
            // letter "j" near the matrix name means "j-th"
            Matrix<T> Uj = U.sub(j, j, U.rows() - 1, U.cols() - 1);
            PPT<T> Pj(Uj, ind, j);
            U = Pj * U;
            P = Pj * P;
            Li = Pj * Li;

            // perform Gaussian Elimination on the j-th column
            GaussT<T> E(U, j);
            U = E * U;
            Li = E * Li;
        }

        // calculate matrix L
        L = P * Li.inverse();
        state = 2;
    }
}
