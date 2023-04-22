namespace ek {
    template <typename T, bool D=1>
    class Vector : public Matrix<T,0,D>
    {
    protected:
        bool row = 1;

        std::vector<std::vector<T>>& getMatrix()
        {
            return Matrix<T,0,D>::matrix;
        }

        std::vector<std::vector<T>> vectorize(std::vector<T> vec)
        {
            std::vector<std::vector<T>> mtx = {vec};
            return mtx;
        }

    public:
        Vector() : Matrix<T,0,D>(){};
        Vector(std::initializer_list<T> arr) : Matrix<T,0,D>({arr}){};
        Vector(std::vector<T> vec) : Matrix<T,0,D>(vectorize(vec)){};

        void newSize(size_t s)
        {
            if (row) {
                Matrix<T,0,D>::newSize(1, s);
            } else {
                Matrix<T,0,D>::newSize(s, 1);
            }
        }

        T& operator () (size_t i)
        {
            if (row) {
                if (i >= (*this).cols()) {
                    (*this).newSize(i+1);
                }
                return getMatrix()[0][i];
            } else {
                if (i >= (*this).rows()) {
                    (*this).newSize(i+1);
                }
                return getMatrix()[i][0];
            }
        }

        size_t dim()
        {
            return std::max((*this).rows(), (*this).cols());
        }

        static Matrix<T, D, D> matrix (Vector<T, D>);
    };
}
