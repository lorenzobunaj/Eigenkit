namespace ek
{
    // find the value of the sum of each element
    template <typename T>
    T Matrix<T>::sum()
    {
        T s=0;
        for (auto it=(*this).begin(); it!=(*this).end(); it++) {
            s += *it;
        }

        return s;
    }
}
