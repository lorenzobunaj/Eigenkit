namespace ek
{
    template <typename T>
    Matrix<T> Matrix<T>::t()
    {
        Matrix<T> out((*this).rows(), (*this).cols());
        for (size_t i=0; i<(*this).rows(); i++) {
            for (size_t j=0; j<(*this).cols(); j++) {
                out(i,j) = (*this)(j,i);
            }
        }

        return out;
    }
}
