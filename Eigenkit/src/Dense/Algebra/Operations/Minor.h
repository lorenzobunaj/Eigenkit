namespace ek
{
    template <typename T>
    T Matrix<T>::minor(size_t ir, size_t ic)
    {
        return (*this).sub(ir,ic).det();
    }
}
