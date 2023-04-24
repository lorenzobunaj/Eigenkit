namespace ek
{
    // dynamic indicators
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
    // update dynamic indicators
    template <typename T>
    void Matrix<T>::dynamic(bool drows, bool dcols)
    {
        dr = drows;
        dc = dcols;
    }
    // matrix dimensions
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
