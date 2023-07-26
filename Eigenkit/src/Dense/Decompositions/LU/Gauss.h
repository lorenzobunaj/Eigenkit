namespace ek
{
    template <typename T>
    void LU<T>::Gauss()
    {
        init();

        for (size_t j = 0; j < range() - 1; j++)
        {
            // perform Gaussian Elimination on the j-th column
            GaussT<T> E(U, j);
            U = E * U;
            Li = E * Li;
        }

        // calculate matrix L
        L = Li.inverse();
        state = 1;
    }
}
