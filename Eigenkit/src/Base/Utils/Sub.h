namespace ek
{

    template <typename T>
    Matrix<T> Matrix<T>::sub(size_t ir, size_t ic, size_t fr, size_t fc)
    {
        if (!(subBorderCheck(*this, ir, ic, fr, fc))) {throw std::invalid_argument("Invalid Argument");}

        Matrix<T> mtx(fr-ir+1, fc-ic+1);

        for (size_t i=0; i<mtx.rows(); i++) {
            for (size_t j=0; j<mtx.cols(); j++) {
                mtx(i,j) = (*this)(ir+i, ic+j);
            }
        }

        return mtx;
    }
    template <typename T>
    Matrix<T> Matrix<T>::sub(size_t ir, size_t ic)
    {
        if ((ir >= (*this).rows()) || (ic >= (*this).cols())) {
            throw std::invalid_argument("Invalid Index");
        }

        Matrix<T> out((*this).rows()-1, (*this).cols()-1);

        auto it = out.begin();
        for (size_t i=0; i<(*this).rows(); i++) {
            for (size_t j=0; j<(*this).cols(); j++) {
                if ((i==ir) || (j==ic)) {continue;}
                *(it++) = (*this)(i,j);
            }
        }

        return out;
    }
    template <typename T>
    Matrix<T> Matrix<T>::row(size_t r)
    {
        return (*this).sub(r,0,r,(*this).cols()-1);
    }
    template <typename T>
    Matrix<T> Matrix<T>::col(size_t c)
    {
        return (*this).sub(0,c,(*this).rows()-1,c);
    }

    template <typename T>
    bool subBorderCheck(Matrix<T> mtx, size_t ir, size_t ic, size_t fr, size_t fc)
    {
        return ((ir >= 0) & (ir <= fr) & (fr < mtx.rows()) & (ic >= 0) & (ic <= fc) & (fc < mtx.cols()));
    }
}
