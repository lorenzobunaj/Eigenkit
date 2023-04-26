namespace ek {
    template <typename T>
    class Squared : public Matrix<T>
    {
    private:
        // check whether rows = cols
        void squaredCheck(Matrix<T> mtx)
        {
            if (mtx.rows() != mtx.cols()) {
                throw std::invalid_argument("Invalid Argument");
            }
        }
    protected:
        // get original matrix
        std::vector<std::vector<T>>& getMatrix()
        {
            return Matrix<T>::matrix;
        }
    public:
        // default constructors
        Squared() : Matrix<T>(){};
        Squared(size_t r, size_t c)
        : Matrix<T>(r, c){squaredCheck(*this);};
        Squared(std::initializer_list<std::initializer_list<T>> arr)
        : Matrix<T>(arr){squaredCheck(*this);};
        Squared(std::vector<std::vector<T>> arr)
        : Matrix<T>(arr){squaredCheck(*this);};

        void dynamic(bool ddim)
        {
            Matrix<T>::dynamic(ddim, ddim);
        }
        // return dim, since rows = cols
        size_t dim()
        {
            return (*this).rows();
        }
        // overload newSize operator
        // take only one argument
        void newSize(size_t s)
        {
            Matrix<T>::newSize(s, s);
        };
        // overload () operator
        // when it has to resize, use the maximum between the indices
        T& operator () (size_t ir, size_t ic)
        {
            if (ir >= (*this).dim() || ic >= (*this).dim()) {
                (*this).newSize(std::max(ir+1, ic+1));
            }

            return (*this).getMatrix()[ir][ic];
        }

        void operator = (Matrix<T>);
    };
}
