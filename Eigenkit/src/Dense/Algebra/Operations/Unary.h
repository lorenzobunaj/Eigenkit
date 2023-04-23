namespace ek
{
    template <typename T>
    Matrix<T> Matrix<T>::operator - ()
    {
        return *this *(-1);
    }
}
