namespace ek
{
    template <typename T, bool DR, bool DC>
    void Matrix<T, DR, DC>::reshape(size_t r)
    {
        if ((*this).rows()*(*this).cols() % r != 0 ) {
            throw std::invalid_argument("Invalid Argument");
        }

        std::vector<T> mtx;
        mtx.resize((*this).rows()*(*this).cols());
        for (size_t i=0; i<(*this).rows(); i++) {
            for (size_t j=0; j<(*this).cols(); j++) {
                mtx[i*(*this).cols() + j] = (*this)(i,j);
            }
        }

        (*this).newSize(r, (*this).rows()*(*this).cols() / r);

        for (size_t i=0; i<(*this).rows(); i++) {
            for (size_t j=0; j<(*this).cols(); j++) {
                (*this)(i,j) = mtx[i*(*this).cols() + j];
            }
        }
    }
}
