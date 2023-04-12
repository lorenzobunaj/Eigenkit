namespace ek
{
    template <typename T, bool DR, bool DC>
    void Matrix<T, DR, DC>::reshape(size_t r)
    {
        if ((*this).rows()*(*this).cols() % r != 0 ) {
            throw std::invalid_argument("Invalid Argument");
        }

        Matrix<T, DR, DC> mtx = *this;

        (*this).newSize(r, (*this).rows()*(*this).cols() / r);

        auto it = mtx.begin();
        for (size_t i=0; i<(*this).rows(); i++) {
            for (size_t j=0; j<(*this).cols(); j++) {
                (*this)(i,j) = *(it++);
            }
        }
    }
}
