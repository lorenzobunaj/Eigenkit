namespace ek
{
    template <typename T>
    Matrix<T> operator * (Matrix<T> op, T scl)
    {
        Matrix<T> out(op.rows(), op.cols());

        auto it = op.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(it++) * scl;
        }

        return out;
    }

    template <typename T>
    Matrix<T> operator * (T scl, Matrix<T> mtx)
    {
        return (mtx * scl);
    }

    template <typename T>
    Matrix<T> operator * (Matrix<T> op1, Matrix<T> op2)
    {
        if ((op1.cols() != op2.rows())) {
            throw std::invalid_argument("Invalid Arguments");
        }

        Matrix<T> out(op1.rows(), op2.cols());

        for (size_t i=0;i<op1.rows();i++) {
            for(size_t j=0;j<op2.cols();j++) {
                for(size_t k=0;k<op1.cols();k++) {
                    out(i,j) = 0;
                    out(i,j) += op1(i,k)*op2(k,j);
                }
            }
        }
        return out;
    }

    template <typename T>
    T Vector<T>::dot (Vector<T> vec)
    {
        return ((*this)*vec)(0,0);
    }

    template <typename T>
    Vector<T> Vector<T>::cross (Vector<T> vec)
    {
        if ((*this).dim() != 3 || vec.dim() != 3 || (*this).cols() != vec.cols()) {
            throw std::invalid_argument("Invalid Arguments");
        }

        Vector<T> out = {
            (*this)(2)*vec(3) - (*this)(3)*vec(2),
            - (*this)(1)*vec(3) + (*this)(3)*vec(1),
            (*this)(1)*vec(2) - (*this)(2)*vec(1)
        };

        return out;
    }

    template <typename T>
    Matrix<T> Vector<T>::outer (Vector<T> vec)
    {
        if ((*this).cols() != 1 || vec.cols() != 1) {
            throw std::invalid_argument("Invalid Arguments");
        }

        Matrix<T> out = *this * vec.t();

        return out;
    }
}
