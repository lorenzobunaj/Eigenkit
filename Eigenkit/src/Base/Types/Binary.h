namespace ek {
    template <bool DR=1, bool DC=1>
    class Binary : public Matrix<int,DR,DC>
    {
    private:
        std::vector<std::vector<int>> App (int (*f)(int p), size_t rs, size_t cs)
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
        Binary(int (*f)(int p), size_t rs, size_t cs) : Matrix<int,DR,DC>(App((*f), rs, cs)){};

        static Matrix<int, DR, DC> matrix (Binary<DR, DC>);

    };
}
