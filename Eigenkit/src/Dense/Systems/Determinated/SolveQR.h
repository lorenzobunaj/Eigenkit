namespace ek
{
    template <typename T>
    Vector<T> QR<T>::solve(Vector<T> a)
    {
        Vector<T> b;
        Vector<T> x;

        Matrix<T> temp = a;
        b = Q.h()*temp;

        x = backSub(R,b).t();
        return x;
    }
}
