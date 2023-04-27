namespace ek
{
    template <typename T>
    Matrix<T> Matrix<T>::operator + (T scl)
    {
        Matrix<T> op = *this;

        Matrix<T> out(op.rows(), op.cols());

        auto it = op.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(it++) + scl;
        }

        return out;
    }
    template <typename T>
    Matrix<T> Matrix<T>::operator - (T scl)
    {
        return (*this + (-scl));
    }

    template <typename T>
    Matrix<T> operator + (Matrix<T> op1, Matrix<T> op2)
    {
        if ((op1.rows() != op2.rows())||(op1.cols() != op2.cols())) {
            throw std::invalid_argument("Invalid Arguments");
        }

        Matrix<T> out(op1.rows(), op1.cols());

        auto it1 = op1.begin();
        auto it2 = op2.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(it1++) + *(it2++);
        }

        return out;
    }
    template <typename T>
    Matrix<T> operator - (Matrix<T> op1, Matrix<T> op2)
    {
        if ((op1.rows() != op2.rows())||(op1.cols() != op2.cols())) {
            throw std::invalid_argument("Invalid Arguments");
        }

        Matrix<T> out(op1.rows(), op1.cols());

        auto it1 = op1.begin();
        auto it2 = op2.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(it1++) - *(it2++);
        }

        return out;
    }

    template <typename T>
    Vector<T> Vector<T>::operator + (T scl)
    {
        Vector<T> op = *this;

        Vector<T> out(op.dim(), (*this).row);

        auto it = op.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(it++) + scl;
        }

        return out;
    }
    template <typename T>
    Vector<T> Vector<T>::operator - (T scl)
    {
        return (*this + (-scl));
    }

    template <typename T>
    Vector<T> operator + (Vector<T> op1, Vector<T> op2)
    {
        Vector<T> out;

        Matrix<T> mtx1 = op1;
        Matrix<T> mtx2 = op2;
        out = mtx1 + mtx2;

        return out;
    }
    template <typename T>
    Vector<T> operator + (Vector<T> op1, T scl)
    {
        Vector<T> out;

        Matrix<T> mtx1 = op1;
        out = mtx1 + scl;

        return out;
    }
    template <typename T>
    Vector<T> operator - (Vector<T> op1, Vector<T> op2)
    {
        Vector<T> out;

        Matrix<T> mtx1 = op1;
        Matrix<T> mtx2 = op2;
        out = mtx1 - mtx2;

        return out;
    }
    template <typename T>
    Vector<T> operator - (Vector<T> op1, T scl)
    {
        Vector<T> out;

        Matrix<T> mtx1 = op1;
        out = mtx1 - scl;

        return out;
    }
}
