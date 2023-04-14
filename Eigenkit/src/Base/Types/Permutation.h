namespace ek {
    template <bool D=1>
    class Permutation : public Squared<bool,D>
    {
    private:
        void permutationCheck (Matrix<int> mtx)
        {
            if (mtx.rows() > 2) {
                throw std::invalid_argument("Invalid Argument");
            }

            std::vector<int> indexes;
            for (size_t i=0; i<mtx.cols(); i++) {
                if ((mtx(0,i) != i+1) || (std::binary_search(indexes.begin(), indexes.end(), mtx(1,i)))) {
                    throw std::invalid_argument("Invalid Argument");
                }
                indexes.insert(indexes.cend(), mtx(1,i));
            }
        }

        std::vector<std::vector<bool>> Perm(Matrix<int> mtx)
        {
            std::vector<std::vector<bool>> arr;

            arr.resize(mtx.cols());
            int i=0;
            for (auto r = arr.begin(); r != arr.end(); r++) {
                (*r).resize(mtx.cols());
                if (mtx(0,i) == i+1) {
                    (*r)[mtx(1,i)] = 1;
                    i++;
                } else {
                    throw std::invalid_argument("Invalid Argument");
                }
            }

            return arr;
        }

    public:
        Permutation(Matrix<int> mtx) : Squared<bool,D>(Perm(mtx)){
            permutationCheck(mtx);
        };
    };
}
