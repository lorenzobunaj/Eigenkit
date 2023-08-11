namespace ek
{
    // overloaded equality operators
    template <typename T>
    bool Matrix<T>::operator == (Matrix<T> mtx)
    {
        if (((*this).rows() != mtx.rows())||((*this).cols() != mtx.cols())) {
            return 0;
        }

        auto op1 = (*this).begin();
        for (auto op2 = mtx.begin(); op2 != mtx.end(); op2++) {
            if (*(op1++) != *op2) {return 0;}
        }

        return 1;
    }
    template <typename T>
    bool Matrix<T>::operator != (Matrix<T> mtx)
    {
        return !(*this == mtx);
    }
}
