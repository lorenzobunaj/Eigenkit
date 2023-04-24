namespace ek
{
    template <typename T>
    class Matrix
    {
    protected:
        std::vector<std::vector<T>> matrix;
        std::size_t nr;
        std::size_t nc;
        bool dr = 1;
        bool dc = 1;

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
        struct Iterator;
        Iterator begin() { return Iterator(&(matrix[0][0]), &matrix); }
        Iterator end()   { return Iterator(&(matrix[(*this).rows()-1][(*this).cols()]), &matrix); }

        void newSize(size_t, size_t);
        T& operator () (size_t, size_t);
        void reshape(size_t);
        Matrix<T> sub(size_t, size_t, size_t, size_t);
        Matrix<T> sub(size_t, size_t);

        Matrix<T> operator + (Matrix<T>);
        Matrix<T> operator + (T);
        Matrix<T> operator - (Matrix<T>);
        Matrix<T> operator - (T);
        Matrix<T> operator * (T);
        void operator += (Matrix<T>);
        void operator += (T);
        void operator -= (Matrix<T>);
        void operator -= (T);
        void operator *= (T);
        bool operator == (Matrix<T>);
        bool operator != (Matrix<T>);
        Matrix<T> operator - ();
        Matrix<T> t();
        Matrix<T> c();
        Matrix<T> h();
        T det();
        T minor(size_t, size_t);
        T cof(size_t, size_t);
        Matrix<T> cofMatrix();
        Matrix<T> inverse();
    };
}
