namespace ek
{
    template <typename T>
    void LU<T>::GE()
    {
        init();

        for (size_t j=0; j<range()-1; j++) {
            // perform Gaussian Elimination on the j-th column
            Elimination<T> E(U,j);
            U = E*U;
            Li = E*Li;
        }

        // calculate matrix L
        L = Li.inverse();
        state = "ge";
    }
}
