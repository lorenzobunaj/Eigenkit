namespace ek
{
    template <typename T>
    Matrix<T> Matrix<T>::complement(size_t ir, size_t ic)
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
}
