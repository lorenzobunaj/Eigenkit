namespace ek
{
    // return a (fr-ir)x(fc-ic) sub-matrix
    template <typename T>
    Matrix<T> Matrix<T>::sub(size_t ir, size_t ic, size_t fr, size_t fc)
    {
        // check if the coordinates are valid
        if (!(subBorderCheck(*this, ir, ic, fr, fc))) {
            throw std::invalid_argument("Invalid Argumenta");
        }

        Matrix<T> out(fr-ir+1, fc-ic+1);
        for (size_t i=0; i<out.rows(); i++) {
            for (size_t j=0; j<out.cols(); j++) {
                out(i,j) = (*this)(ir+i, ic+j);
            }
        }

        return out;
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
    // returns r-th row
    template <typename T>
    Matrix<T> Matrix<T>::row(size_t r)
    {
        return (*this).sub(r,0,r,(*this).cols()-1);
    }
    // returns c-th column
    template <typename T>
    Matrix<T> Matrix<T>::col(size_t c)
    {
        return (*this).sub(0,c,(*this).rows()-1,c);
    }
    // checks if the values are valid coordinates for 2 different elements in the matrix
    template <typename T>
    bool subBorderCheck(Matrix<T> mtx, size_t ir, size_t ic, size_t fr, size_t fc)
    {
        return ((ir >= 0) & (ir <= fr) & (fr < mtx.rows()) & (ic >= 0) & (ic <= fc) & (fc < mtx.cols()));
    }
}
