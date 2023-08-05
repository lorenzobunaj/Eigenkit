namespace ek
{
    // product between a matrix and a scalar (type-independent)
    template <typename T>
    Matrix<T> Matrix<T>::operator * (T scl)
    {
        Matrix<T> op = *this;

        Matrix<T> out(op.rows(), op.cols());

        auto it = op.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(it++) * scl;
        }

        return out;
    }
    // product between a scalar and a matrix
    template <typename T>
    Matrix<T> operator * (T scl, Matrix<T> mtx)
    {
        return (mtx * scl);
    }
    // matrices product
    template <typename T>
    Matrix<T> operator * (Matrix<T> op1, Matrix<T> op2)
    {
        if ((op1.cols() != op2.rows())) {
            throw std::invalid_argument("Invalid Operands in the Product");
            /*std::cout << op1 << std::endl;
            std::cout << "..." << std::endl;
            std::cout << op2 << std::endl;*/
        }

        Matrix<T> out(op1.rows(), op2.cols());

        for (size_t i=0;i<op1.rows();i++) {
            for(size_t j=0;j<op2.cols();j++) {
                out(i,j) = 0;
                for(size_t k=0;k<op1.cols();k++) {
                    out(i,j) += op1(i,k)*op2(k,j);
                }
            }
        }
        return out;
    }
    // division between a matrix and a scalar
    template <typename T>
    Matrix<T> Matrix<T>::operator / (T scl)
    {
        Matrix<T> op = *this;

        Matrix<T> out(op.rows(), op.cols());

        auto it = op.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(it++) / scl;
        }

        return out;
    }
    // product between a vector and a scalar
    template <typename T>
    Vector<T> Vector<T>::operator * (T scl)
    {
        Vector<T> op = *this;

        Vector<T> out(op.dim(), (*this).row);

        auto it = op.begin();
        for (auto e = out.begin(); e != out.end(); e++) {
            *e = *(it++) * scl;
        }

        return out;
    }
    // dot product
    template <typename T>
    T Vector<T>::dot (Vector<T> vec)
    {
        if ((*this).dim() != vec.dim()) {
            throw std::invalid_argument("Invalid Arguments");
        }

        T out = 0;
        auto it = (*this).begin();
        for (auto e=vec.begin(); e!=vec.end(); e++) {
            out += (*(it++))*(*e);
        }
        return out;
    }
    // cross product
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
    // outer product
    template <typename T>
    Matrix<T> Vector<T>::outer (Vector<T> vec)
    {
        Matrix<T> out((*this).dim(), vec.dim());

        for (size_t i=0; i<(*this).dim(); i++) {
            for (size_t j=0; j<vec.dim(); j++) {
                out(i,j) = (*this)(i) * vec(j);
            }
        }

        return out;
    }
}
