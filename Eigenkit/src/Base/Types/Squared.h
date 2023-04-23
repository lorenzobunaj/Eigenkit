namespace ek {
    template <typename T>
    class Squared : public Matrix<T>
    {
    private:
        void squaredCheck(Matrix<T> mtx)
        {
            if (mtx.rows() != mtx.cols()) {
                throw std::invalid_argument("Invalid Argument");
            }
        }

    protected:
        std::vector<std::vector<T>>& getMatrix()
        {
            return Matrix<T>::matrix;
        }

    public:
        Squared() : Matrix<T>(){};

        Squared(size_t r, size_t c)
        : Matrix<T>(r, c){squaredCheck(*this);};

        Squared(std::initializer_list<std::initializer_list<T>> arr)
        : Matrix<T>(arr){squaredCheck(*this);};

        Squared(std::vector<std::vector<T>> arr)
        : Matrix<T>(arr){squaredCheck(*this);};

        size_t dim()
        {
            return (*this).rows();
        }

        void newSize(size_t s)
        {
            Matrix<T>::newSize(s, s);
        };

        T& operator () (size_t ir, size_t ic)
        {
            if (ir >= (*this).dim() || ic >= (*this).dim()) {
                (*this).newSize(std::max(ir+1, ic+1));
            }

            return (*this).getMatrix()[ir][ic];
        }

        static Matrix<T> matrix (Squared<T>);
    };
}
