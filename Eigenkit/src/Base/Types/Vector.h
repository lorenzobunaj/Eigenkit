namespace ek {
    template <typename T>
    class Vector : public Matrix<T>
    {
    protected:
        bool row = 1;

        std::vector<std::vector<T>>& getMatrix()
        {
            return Matrix<T>::matrix;
        }

        std::vector<std::vector<T>> vectorize(std::vector<T> vec)
        {
            std::vector<std::vector<T>> mtx = {vec};
            return mtx;
        }

    public:
        Vector() : Matrix<T>(){};
        Vector(std::initializer_list<T> arr) : Matrix<T>({arr}){};
        Vector(std::vector<T> vec) : Matrix<T>(vectorize(vec)){};

        void newSize(size_t s)
        {
            if (row) {
                Matrix<T>::newSize(1, s);
            } else {
                Matrix<T>::newSize(s, 1);
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

        static Matrix<T> matrix (Vector<T>);
    };
}
