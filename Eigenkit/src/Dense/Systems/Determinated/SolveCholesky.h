namespace ek
{
    template <typename T>
    Vector<T> Cholesky<T>::solve(Vector<T> a)
    {
        Vector<T> y;
        Vector<T> x;

        y = forSub(L*D, a);
        x = backSub(L.h(), y);

        return x;
    }
}
