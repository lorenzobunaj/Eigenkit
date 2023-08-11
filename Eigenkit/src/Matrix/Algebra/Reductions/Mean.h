namespace ek
{
    // find the mean element
    template <typename T>
    T Matrix<T>::mean()
    {
        return ((*this).sum() /((*this).rows() * (*this).cols()));
    }
}

