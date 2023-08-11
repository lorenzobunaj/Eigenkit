namespace ek
{
    // squared -> matrix
    template <typename T>
    void Squared<T>::operator = (Matrix<T> mtx)
    {
        squaredCheck(mtx);

        (*this).newSize(mtx.rows());
        (*this).dynamic(mtx.drows());

        auto it=mtx.begin();
        for (auto e=(*this).begin(); e != (*this).end(); e++) {
            *e = *(it++);
        }
    }
    // diagonal -> matrix
    template <typename T>
    void Diagonal<T>::operator = (Matrix<T> mtx)
    {
        diagonalCheck(mtx);

        (*this).newSize(mtx.rows());
        (*this).dynamic(mtx.drows());

        for (size_t i=0; i<(*this).dim(); i++) {
            (*this)(i,i) = mtx(i,i);
        }
    }
    // binary -> matrix
    template <typename T>
    void Binary<T>::operator = (Matrix<T> mtx)
    {
        binaryCheck(mtx);

        (*this).newSize(mtx.rows(),mtx.cols());
        (*this).dynamic(mtx.drows(),mtx.dcols());

        auto it=mtx.begin();
        for (auto e=(*this).begin(); e != (*this).end(); e++) {
            *e = *(it++);
        }
    }
    // vector -> matrix
    template <typename T>
    void Vector<T>::operator = (Matrix<T> mtx)
    {
        if ((std::min(mtx.rows(), mtx.cols()) != 1) && mtx.rows() != 0) {
            throw std::invalid_argument("Invalid Argument");
        }

        row = mtx.rows() >= mtx.cols() ? 0 : 1;

        (*this).newSize(std::max(mtx.rows(), mtx.cols()));
        (*this).dynamic(mtx.drows(),mtx.dcols());

        auto it=mtx.begin();
        for (auto e=(*this).begin(); e != (*this).end(); e++) {
            *e = *(it++);
        }
    }
}
