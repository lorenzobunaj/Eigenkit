namespace ek
{
    template <typename T, bool DR, bool DC>
    bool Matrix<T, DR, DC>::drows()
    {
        return this->dr;
    }
    template <typename T, bool DR, bool DC>
    bool Matrix<T, DR, DC>::dcols()
    {
        return this->dc;
    }
    template <typename T, bool DR, bool DC>
    void Matrix<T, DR, DC>::setDynamic(bool drows, bool dcols)
    {
        this->dr = drows;
        this->dc = dcols;
    }

    template <typename T, bool DR, bool DC>
    size_t Matrix<T, DR, DC>::rows()
    {
        return this->nr;
    }
    template <typename T, bool DR, bool DC>
    size_t Matrix<T, DR, DC>::cols()
    {
        return this->nc;
    }
    template <typename T, bool DR, bool DC>
    void Matrix<T, DR, DC>::newSize(size_t r, size_t c)
    {
        if (r != (*this).rows()) {
            if ((*this).drows()) {nr = r;}
            else {throw std::invalid_argument("Invalid Argument");}
        }
        if (c != (*this).cols()) {
            if ((*this).dcols()) {nc = c;}
            else {throw std::invalid_argument("Invalid Argument");}
        }

        (this->matrix).resize(nr);
        for (auto r=matrix.begin(); r != (this->matrix).end(); r++) {
            (*r).resize(nc);
        }
    }

    template <typename T, bool DR, bool DC>
    T& Matrix<T, DR, DC>::operator () (size_t ir, size_t ic)
    {
        if (!(((*this).rows() > ir) && ((*this).cols() > ic))) {
            throw std::invalid_argument("Invalid Index");
        }

        if (!((*this).rows() > ir)) {(*this).newSize(ir, (*this).cols());}
        if (!((*this).cols() > ic)) {(*this).newSize((*this).rows(), ic);}

        return this->matrix[ir][ic];
    }
}
