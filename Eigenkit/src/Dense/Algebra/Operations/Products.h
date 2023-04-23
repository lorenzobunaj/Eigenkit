namespace ek
{
    template <typename T>
    Matrix<T> Matrix<T>::operator * (T scl)
    {
        Matrix<T> out((*this).rows(), (*this).cols());

        auto op = (*this).begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(op++) * scl;
        }

        return out;
    }

    template <typename T>
    Matrix<T> operator * (T scl, Matrix<T> mtx)
    {
        return (mtx * scl);
    }
}
