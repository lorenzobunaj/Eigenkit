namespace ek
{
    // finds the (i,j)-th cofactor
    template <typename T>
    T Matrix<T>::cof(size_t ir, size_t ic)
    {
        return std::pow(-1, ir+ic)*(*this).minor(ir,ic);
    }
    // finds the cofactors matrix
    template <typename T>
    Matrix<T> Matrix<T>::cofactors()
    {
        Matrix<T> out((*this).rows(), (*this).cols());

        for (size_t i=0; i<(*this).rows(); i++) {
            for (size_t j=0; j<(*this).cols(); j++) {
                out(i,j) = (*this).cof(i,j);
            }
        }

        return out;
    }
}
