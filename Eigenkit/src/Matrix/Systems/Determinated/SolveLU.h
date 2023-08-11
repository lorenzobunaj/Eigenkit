namespace ek
{
    template <typename T>
    Vector<T> LU<T>::solve(Vector<T> a)
    {
        Vector<T> b;
        Vector<T> z;
        Vector<T> y;
        Vector<T> x;

        Matrix<T> temp = a;
        b = P*temp;

        z = forSub(L,b);
        y = backSub(U,z);
        x = Q*y.t();

        return x;
    }
}
