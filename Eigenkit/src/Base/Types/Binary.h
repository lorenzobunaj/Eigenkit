namespace ek {
    template <typename T>
    class Binary : public Matrix<T>
    {
    private:
        // check whether the matrix contains only 1s and 0s
        void binaryCheck(Matrix<T> mtx)
        {
            for (auto it : mtx)
            {
                if (it != 0 && it != 1) {
                    throw std::invalid_argument("Invalid Argument");
                }
            }
        }
        // let f : Z -> Z, output:= matrix so that a(i,j) = 1 if j = f(i) else 0
        std::vector<std::vector<T>> app (int (*f)(int p), size_t rs, size_t cs)
        {
            std::vector<std::vector<T>> arr;

            arr.resize(rs);
            int i = 0;
            for (auto r=arr.begin(); r != arr.end(); r++) {
                (*r).resize(cs);
                if ((size_t)(*f)(i) < cs) {
                    (*r)[(*f)(i)] = 1;
                } else {
                    throw std::invalid_argument("Invalid Size");
                }
                i++;
            }

            return arr;
        }
    protected:
        // get original matrix
        std::vector<std::vector<T>>& getMatrix()
        {
            return Matrix<T>::matrix;
        }
    public:
        // default constructors
        Binary() : Matrix<T>(){};
        Binary(size_t r, size_t c) : Matrix<T>(r, c){};
        Binary(std::initializer_list<std::initializer_list<T>> arr)
        : Matrix<T>(arr){binaryCheck(*this);};
        Binary(std::vector<std::vector<T>> arr)
        : Matrix<T>(arr){binaryCheck(*this);};
        // special constructor
        Binary(int (*f)(int p), size_t rs, size_t cs) : Matrix<T>(app((*f), rs, cs)){};
        // overloaded () operator
        // can't modify elements
        T operator () (size_t ir, size_t ic)
        {
            if (ir >= (*this).rows() || ic >= (*this).cols()) {
                throw std::invalid_argument("Invalid Index");
            }

            return (*this).getMatrix()[ir][ic];
        };
        // a(i,j) = !a(i,j)
        void bnot (size_t ir, size_t ic)
        {
            if (ir >= (*this).rows() || ic >= (*this).cols()) {
                throw std::invalid_argument("Invalid Index");
            }

            (*this).getMatrix()[ir][ic] = !((*this).getMatrix()[ir][ic]);
        }

    };
}
