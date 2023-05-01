namespace ek
{
    template <typename T>
    T Matrix<T>::mean()
    {
        return ((*this).sum() /((*this).rows() * (*this).cols()));
    }
}

