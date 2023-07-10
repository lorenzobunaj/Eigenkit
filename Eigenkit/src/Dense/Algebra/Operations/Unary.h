namespace ek
{
    // overloaded the minus unary operator
    template <typename T>
    Matrix<T> Matrix<T>::operator - ()
    {
        return *this *(-1);
    }
}
