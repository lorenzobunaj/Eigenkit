namespace ek
{
    template <typename T>
    Vector<T> QR<T>::solve(Vector<T> a)
    {
        Vector<T> b;
        Vector<T> x;
        Vector<T> out;

        Matrix<T> temp = a;
        b = Q.h()*temp;

        x = backSub(R,b).t();

        out = P*x;

        return out;
    }
}
