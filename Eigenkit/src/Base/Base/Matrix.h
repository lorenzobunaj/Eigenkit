namespace ek
{
    template <typename T>
    class Matrix
    {
    protected:
        std::vector<std::vector<T>> matrix;
        size_t nr;
        size_t nc;
        bool dr = 1;
        bool dc = 1;

    public:
        Matrix();
        Matrix(size_t, size_t);
        Matrix(std::initializer_list<std::initializer_list<T>>);
        Matrix(std::vector<std::vector<T>>);

        size_t rows();
        size_t cols();
        bool drows();
        bool dcols();
        void dynamic(bool, bool);
        std::vector<std::vector<T>> mtx();
        struct Iterator;
        Iterator begin() { return Iterator(&(matrix[0][0]), &matrix); }
        Iterator end()   { return Iterator(&(matrix[(*this).rows()-1][(*this).cols()]), &matrix); }

        void newSize(size_t, size_t);
        T& operator () (size_t, size_t);
        void reshape(size_t);
        Matrix<T> sub(size_t, size_t, size_t, size_t);
        Matrix<T> sub(size_t, size_t);
        Matrix<T> row(size_t);
        Matrix<T> col(size_t);

        Matrix<T> operator + (T);
        Matrix<T> operator - (T);
        Matrix<T> operator * (T);
        Matrix<T> operator / (T);
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
        Matrix<T> cofactors();
        Matrix<T> inverse();
        T sum();
        T prod();
        T mean();
        T max();
        T absMax();
        T min();
        std::vector<size_t> maxPos(std::vector<T> na={});
        std::vector<size_t> absMaxPos(std::vector<T> na={});
        std::vector<size_t> minPos();
    };
}
