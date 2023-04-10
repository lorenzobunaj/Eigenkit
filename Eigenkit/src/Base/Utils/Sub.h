namespace ek
{
    template <typename T, bool DR, bool DC>
    Matrix<T, DR, DC> Matrix<T, DR, DC>::sub(size_t ir, size_t ic, size_t fr, size_t fc)
    {
        if (!(subBorderCheck(*this, ir, ic, fr, fc))) {throw std::invalid_argument("Invalid Argument");}

        Matrix<T, DR, DC> mtx(fr-ir+1, fc-ic+1);

        for (size_t i=0; i<mtx.rows(); i++) {
            for (size_t j=0; j<mtx.cols(); j++) {
                mtx(i,j) = (*this)(ir+i, ic+j);
            }
        }

        return mtx;
    }

    template <typename T, bool DR, bool DC>
    bool subBorderCheck(Matrix<T, DR, DC> mtx, size_t ir, size_t ic, size_t fr, size_t fc)
    {
        return ((ir >= 0) & (ir <= fr) & (fr < mtx.rows()) & (ic >= 0) & (ic <= fc) & (fc < mtx.cols()));
    }
}
