namespace ek
{
    template <typename T>
    Vector<T> backSub(Matrix<T> U, Vector<T> y)
    {
        size_t n = U.cols();
        Vector<T> x(n);


        for (size_t i=0; i < n; i++) {
            x(n-i-1) = y(n-i-1);
            for (size_t j=n-i; j<n; j++) {
                x(n-i-1) -= U(n-i-1,j)*x(j);
            };
            x(n-i-1) = x(n-i-1)/U(n-i-1,n-i-1);
        };

        return x;
    }
}
