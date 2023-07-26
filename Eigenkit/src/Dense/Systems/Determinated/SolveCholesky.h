namespace ek
{
    template <typename T>
    Vector<T> Cholesky<T>::solve(Vector<T> a)
    {
        Vector<T> y;
        Vector<T> x;

        y = forSub(L, a);
        x = backSub(L.t(), y);

        std::cout << a << std::endl;
        std::cout << "..." << std::endl;
        std::cout << L << std::endl;
        std::cout << "..." << std::endl;
        std::cout << L.h() << std::endl;
        std::cout << "..." << std::endl;
        std::cout << y << std::endl;
        std::cout << "..." << std::endl;

        return x;
    }
}