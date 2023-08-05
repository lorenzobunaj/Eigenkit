namespace ek
{
    template <typename T>
    Vector<T> forSub(Matrix<T> L, Vector<T> y)
    {
        size_t n = L.cols();
        Vector<T> x(n);


        for (size_t i=0; i < n; i++) {
            x(i) = y(i);
            for (size_t j=0; j<i; j++) {
                x(i) -= L(i,j)*x(j);
            };
            x(i) /= L(i,i);
        };

        return x;
    }
}
