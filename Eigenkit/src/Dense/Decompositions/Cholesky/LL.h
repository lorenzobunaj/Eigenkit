namespace ek
{
    // checks if the argument is real positive definite
    template <typename T>
    bool diagCheck (T el)
    {
        // diagonal entries need to be real and positive
        return ((std::imag(el) == 0) && (std::real(el) > 0));
    }

    // sums the products e*conj(e) over a column
    template <typename T>
    T colSum(Matrix<T> A, size_t i, size_t j, size_t e)
    {
        // sum elements over a column
        T out = 0;
        for (size_t k=0; k<e; k++) {
            out += A(i,k)*std::conj(A(j,k));
        }

        return out;
    }

    // performs normal Cholesky Decomposition
    template <typename T>
    void Cholesky<T>::LL()
    {
        // initialize output matrices
        Matrix<T> temp(A.rows(), A.cols());
        L = temp;
        Identity<T> id(A.rows());
        D = id;

        for (size_t j=0; j<A.cols(); j++) {
            // sums the products e*conj(e) over j-th column (before j-th element)
            T cs = colSum(L,j,j,j);

            // L(j,j) = sqrt(A(j,j) - cs) if they're > 0, else raise error
            if (!diagCheck(A(j,j)-cs)) {
                throw std::invalid_argument("Invalid Argument");
            }
            L(j,j) = std::sqrt(A(j,j) - cs);

            // find the other column elements
            for (size_t k=j+1; k<A.rows(); k++) {
                cs = colSum(L,k,j,j);
                L(k,j) = ((T)1)/L(j,j) * (A(k,j) - cs);
            }
        }
    }
}
