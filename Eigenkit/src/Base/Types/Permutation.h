namespace ek {
    class Permutation : public Squared<int,0>
    {
    private:
        void permutationCheck (Matrix<int> mtx)
        {
            if (mtx.rows() > 2) {
                throw std::invalid_argument("Invalid Argument");
            }

            std::vector<int> indexes;
            for (size_t i=0; i<mtx.cols(); i++) {
                if (((size_t)mtx(0,i) != i+1) || (std::binary_search(indexes.begin(), indexes.end(), mtx(1,i)))) {
                    throw std::invalid_argument("Invalid Argument");
                }
                indexes.insert(indexes.cend(), mtx(1,i));
            }
        }

        std::vector<std::vector<int>> Perm(Matrix<int> mtx)
        {
            std::vector<std::vector<int>> arr;

            arr.resize(mtx.cols());
            int i=0;
            for (auto r = arr.begin(); r != arr.end(); r++) {
                (*r).resize(mtx.cols());
                if (mtx(0,i) == i+1) {
                    (*r)[mtx(1,i)-1] = 1;
                    i++;
                } else {
                    throw std::invalid_argument("Invalid Argument");
                }
            }

            return arr;
        }

    public:
        Permutation(Matrix<int> mtx) : Squared<int,0>(Perm(mtx)){
            permutationCheck(mtx);
        };

        void newSize(size_t s)
        {
            throw std::invalid_argument("Invalid Method");
        };

        int operator () (size_t ir, size_t ic)
        {
            if (ir >= (*this).rows() || ic >= (*this).cols()) {
                throw std::invalid_argument("Invalid Index");
            }

            return Squared<int,0>::getMatrix()[ir][ic];
        }
    };
}
