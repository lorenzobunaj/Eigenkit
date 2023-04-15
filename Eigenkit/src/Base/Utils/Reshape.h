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

        auto e = mtx.begin();
        for (auto it = (*this).begin(); it != (*this).end(); it++) {
            *it = *(e++);
        }
    }
}
