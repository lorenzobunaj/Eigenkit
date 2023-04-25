namespace ek
{
    template <typename T>
    Matrix<T> HouseholderReflection(Vector<T> vec)
    {
        Identity<T> id(vec.dim());

        return (id - (T)2*vec.outer(vec.c()));
    }
}
