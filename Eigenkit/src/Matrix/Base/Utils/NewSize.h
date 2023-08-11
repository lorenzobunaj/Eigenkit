namespace ek
{
    // resize the matrix (if it's dynamic)
    template <typename T>
    void Matrix<T>::newSize(size_t r, size_t c)
    {
        if (r != (*this).rows()) {
            if ((*this).drows()) {nr = r;}
            else {throw std::invalid_argument("Invalid Argument");}
        }
        if (c != (*this).cols()) {
            if ((*this).dcols()) {nc = c;}
            else {throw std::invalid_argument("Invalid Argument");}
        }

        matrix.resize(nr);
        for (auto r = matrix.begin(); r != matrix.end(); r++) {
            (*r).resize(nc);
        }
    }
    // find the (i,j)-th element
    template <typename T>
    T& Matrix<T>::operator () (size_t ir, size_t ic)
    {
        if (ir >= (*this).rows() || ic >= (*this).cols()) {
            (*this).newSize(std::max((*this).rows(),ir+1), std::max((*this).cols(),ic+1));
        }

        return matrix[ir][ic];
    }
}
