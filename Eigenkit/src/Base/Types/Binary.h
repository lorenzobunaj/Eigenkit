namespace ek {
    template <bool DR=1, bool DC=1>
    class Binary : public Matrix<bool,DR,DC>
    {
    public:
        Binary(int (*f)(int p), size_t rs, size_t cs) : Matrix<bool,DR,DC>(App((*f), rs, cs)){};

        std::vector<std::vector<int>> App (int (*f)(int p), size_t rs, size_t cs)
        {
            std::vector<std::vector<bool>> arr;

            arr.resize(rs);
            int i = 0;
            for (auto r=arr.begin(); r != arr.end(); r++) {
                (*r).resize(cs);
                if ((*f)(i) < cs) {
                    (*r)[(*f)(i)] = 1;
                } else {
                    throw std::invalid_argument("Invalid Argument");
                }
                i++;
            }

            return arr;
        }

    };
}
