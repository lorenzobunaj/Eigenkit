namespace ek
{
    template <typename T>
    T Matrix<T>::max()
    {
        T M=*((*this).begin());
        for (auto it=(*this).begin(); it!=(*this).end(); it++) {
            M = std::max(M, *it);
        }

        return M;
    }
    template <typename T>
    T Matrix<T>::min()
    {
        T m=*((*this).begin());
        for (auto it=(*this).begin(); it!=(*this).end(); it++) {
            m = std::min(m, *it);
        }

        return m;
    }
}
