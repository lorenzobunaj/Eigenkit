#include <vector>
#include <complex>
#include <typeinfo>
#include <algorithm>
#include <iostream>

namespace ek
{
    template <typename T, bool DR=1, bool DC=1>
    class Matrix
    {
    protected:
        std::vector<std::vector<T>> matrix;
        std::size_t nr;
        std::size_t nc;
        bool dr = DR;
        bool dc = DC;

        void setDynamic(bool, bool);

    public:
        Matrix();
        Matrix(size_t, size_t);
        Matrix(std::initializer_list<std::initializer_list<T>>);
        Matrix(std::vector<std::vector<T>>);

        size_t rows();
        size_t cols();
        bool drows();
        bool dcols();
        T& operator () (size_t, size_t);
        void newSize(size_t, size_t);
        void reshape(size_t);
        Matrix<T, DR, DC> sub(size_t, size_t, size_t, size_t);
    };
}
