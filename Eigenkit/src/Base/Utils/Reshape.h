namespace ek
{
    template <typename T>
    void Matrix<T>::reshape(size_t r)
    {
        if ((*this).rows()*(*this).cols() % r != 0 ) {
            throw std::invalid_argument("Invalid Argument");
        }

        Matrix<T> mtx = *this;

        (*this).newSize(r, (*this).rows()*(*this).cols() / r);

        auto e = mtx.begin();
        for (auto it = (*this).begin(); it != (*this).end(); it++) {
            *it = *(e++);
        }
    }
}
