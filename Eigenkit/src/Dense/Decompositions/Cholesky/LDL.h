namespace ek
{
    template <typename T>
    void Cholesky<T>::LDL()
    {
        // initialize output matrices
        Identity<T> id(A.rows());
        L = id;
        D = A;

        for (size_t j=0; j<A.cols()-1; j++) {
            // save D's information in matrix L
            for (size_t i=j+1; i<D.rows(); i++) {
                L(i,j) = D(i,j) / D(j,j);
            }

            // perform Gaussian Elimination on D's j-th row and column
            // it's the same elimination matrix, since D is Hermitian
            Elimination<T> E(D,j);
            D = E*D;
            D = D*(E.t());
        }
    }
}
