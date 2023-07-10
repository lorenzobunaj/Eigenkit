namespace ek
{
    // finds the conjugate matrix
    template <typename T>
    Matrix<T> Matrix<T>::c()
    {
        Matrix<T> out((*this).rows(), (*this).cols());

        auto e = (*this).begin();
        for (auto it=out.begin(); it!=out.end(); it++) {
            *it = std::conj(*(e++));
        }

        return out;
    }
    // finds the transposed and conjugate matrix
    template <typename T>
    Matrix<T> Matrix<T>::h()
    {
        return ((*this).t()).c();
    }
}

