namespace ek
{
    template <typename T>
    Matrix<T> Matrix<T>::operator + (Matrix<T> mtx)
    {
        if (((*this).rows() != mtx.rows())||((*this).cols() != mtx.cols())) {
            throw std::invalid_argument("Invalid Arguments");
        }

        Matrix<T> out((*this).rows(), (*this).cols());

        auto op1 = (*this).begin();
        auto op2 = mtx.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(op1++) + *(op2++);
        }

        return out;
    }
    template <typename T>
    Matrix<T> Matrix<T>::operator + (T scl)
    {
        Matrix<T> out((*this).rows(), (*this).cols());

        auto op = (*this).begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(op++) + scl;
        }

        return out;
    }
    template <typename T>
    Matrix<T> operator + (T scl, Matrix<T> mtx)
    {
        return (mtx + scl);
    }

    template <typename T>
    Matrix<T> Matrix<T>::operator - (Matrix<T> mtx)
    {
        if (((*this).rows() != mtx.rows())||((*this).cols() != mtx.cols())) {
            throw std::invalid_argument("Invalid Arguments");
        }

        Matrix<T> out((*this).rows(), (*this).cols());

        auto op1 = (*this).begin();
        auto op2 = mtx.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(op1++) - *(op2++);
        }

        return out;
    }
    template <typename T>
    Matrix<T> Matrix<T>::operator - (T scl)
    {
        return ((*this) + (-scl));
    }
    template <typename T>
    Matrix<T> operator - (T scl, Matrix<T> mtx)
    {
        Matrix<T> temp(mtx.rows(), mtx.cols());
        return (scl + (temp - mtx));
    }
}
