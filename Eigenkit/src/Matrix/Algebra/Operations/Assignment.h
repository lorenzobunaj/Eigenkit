namespace ek
{
    // overloaded assignment operators
    template <typename T>
    void Matrix<T>::operator += (Matrix<T> mtx)
    {
        *this = *this + mtx;
    }
    template <typename T>
    void Matrix<T>::operator += (T scl)
    {
        *this = *this + scl;
    }
    template <typename T>
    void Matrix<T>::operator -= (Matrix<T> mtx)
    {
        *this += mtx*(-1);
    }
    template <typename T>
    void Matrix<T>::operator -= (T scl)
    {
        *this += -scl;
    }
    template <typename T>
    void Matrix<T>::operator *= (T scl)
    {
        *this = *this * scl;
    }
}
