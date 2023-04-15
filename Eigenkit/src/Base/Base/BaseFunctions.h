namespace ek
{
    template <typename T, bool DR, bool DC>
    bool Matrix<T, DR, DC>::drows()
    {
        return dr;
    }
    template <typename T, bool DR, bool DC>
    bool Matrix<T, DR, DC>::dcols()
    {
        return dc;
    }
    template <typename T, bool DR, bool DC>
    void Matrix<T, DR, DC>::setDynamic(bool drows, bool dcols)
    {
        dr = drows;
        dc = dcols;
    }

    template <typename T, bool DR, bool DC>
    size_t Matrix<T, DR, DC>::rows()
    {
        return nr;
    }
    template <typename T, bool DR, bool DC>
    size_t Matrix<T, DR, DC>::cols()
    {
        return nc;
    }
}
