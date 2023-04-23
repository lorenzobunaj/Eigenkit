namespace ek {
    template <typename T>
    class Binary : public Matrix<T>
    {
    private:
        void binaryCheck(Matrix<T> mtx)
        {
            for (auto it : mtx)
            {
                if (it != 0 && it != 1) {
                    throw std::invalid_argument("Invalid Argument");
                }
            }
        }
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
        std::vector<std::vector<T>>& getMatrix()
        {
            return Matrix<T>::matrix;
        }

    public:
        Binary() : Matrix<T>(){};

        Binary(size_t r, size_t c) : Matrix<T>(r, c){};

        Binary(std::initializer_list<std::initializer_list<T>> arr)
        : Matrix<T>(arr){binaryCheck(*this);};

        Binary(std::vector<std::vector<T>> arr)
        : Matrix<T>(arr){binaryCheck(*this);};

        Binary(int (*f)(int p), size_t rs, size_t cs) : Matrix<T>(app((*f), rs, cs)){};

        static Matrix<T> matrix (Binary<T>);

        T operator () (size_t ir, size_t ic)
        {
            if (ir >= (*this).rows() || ic >= (*this).cols()) {
                throw std::invalid_argument("Invalid Index");
            }

            return (*this).getMatrix()[ir][ic];
        };

        void bnot (size_t ir, size_t ic)
        {
            if (ir >= (*this).rows() || ic >= (*this).cols()) {
                throw std::invalid_argument("Invalid Index");
            }

            (*this).getMatrix()[ir][ic] = !((*this).getMatrix()[ir][ic]);
        }

    };
}
