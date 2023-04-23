namespace ek
{
    template <typename T>
    bool Matrix<T>::drows()
    {
        return dr;
    }

    template <typename T>
    bool Matrix<T>::dcols()
    {
        return dc;
    }

    template <typename T>
    void Matrix<T>::setDynamic(bool drows, bool dcols)
    {
        dr = drows;
        dc = dcols;
    }

    template <typename T>
    size_t Matrix<T>::rows()
    {
        return nr;
    }

    template <typename T>
    size_t Matrix<T>::cols()
    {
        return nc;
    }
}
