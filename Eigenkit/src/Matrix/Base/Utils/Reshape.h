namespace ek
{
    // insert the nxm matrix's elements into an another rxt one : n*m = r*t
    template <typename T>
    void Matrix<T>::reshape(size_t r)
    {
        // check if n*m is divisible by r
        if ((*this).rows()*(*this).cols() % r != 0 ) {
            throw std::invalid_argument("Invalid Argument");
        }
        // initialize a new temporary matrix and change *this's dimensions
        Matrix<T> mtx = *this;
        (*this).newSize(r, (*this).rows()*(*this).cols() / r);
        // add the entries in the new positions
        auto e = mtx.begin();
        for (auto it = (*this).begin(); it != (*this).end(); it++) {
            *it = *(e++);
        }
    }
}
