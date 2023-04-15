namespace ek {
    template <bool DR=1, bool DC=1>
    class Binary : public Matrix<int,DR,DC>
    {
    private:
        void binaryCheck(Matrix<int,DR,DC> mtx)
        {
            for (auto it : mtx)
            {
                if (it != 0 && it != 1) {
                    throw std::invalid_argument("Invalid Argument");
                }
            }
        }
        std::vector<std::vector<int>> app (int (*f)(int p), size_t rs, size_t cs)
        {
            std::vector<std::vector<int>> arr;

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

    public:
        Binary() : Matrix<int,DR,DC>(){};

        Binary(size_t r, size_t c) : Matrix<int,DR,DC>(r, c){};

        Binary(std::initializer_list<std::initializer_list<int>> arr)
        : Matrix<int,DR,DC>(arr){binaryCheck(*this);};

        Binary(std::vector<std::vector<int>> arr)
        : Matrix<int,DR,DC>(arr){binaryCheck(*this);};

        Binary(int (*f)(int p), size_t rs, size_t cs) : Matrix<int,DR,DC>(app((*f), rs, cs)){};

        static Matrix<int, DR, DC> matrix (Binary<DR, DC>);

    };
}
