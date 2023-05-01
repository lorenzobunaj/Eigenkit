namespace ek
{
    template <typename T>
    T Matrix<T>::prod()
    {
        T s=1;
        for (auto it=(*this).begin(); it!=(*this).end(); it++) {
            s *= *it;
        }

        return s;
    }
}
