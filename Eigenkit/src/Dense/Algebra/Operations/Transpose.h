namespace ek
{
    // finds the transposed matrix
    template <typename T>
    Matrix<T> Matrix<T>::t()
    {
        Matrix<T> out((*this).cols(), (*this).rows());
        for (size_t i=0; i<(*this).rows(); i++) {
            for (size_t j=0; j<(*this).cols(); j++) {
                out(j,i) = (*this)(i,j);
            }
        }

        return out;
    }
}
