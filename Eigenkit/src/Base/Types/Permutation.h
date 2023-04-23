namespace ek
{
    template <typename T>
    class Permutation : public Squared<T>
    {
    private:
        void permutationCheck (Matrix<T> mtx)
        {
            if (mtx.rows() > 2) {
                throw std::invalid_argument("Invalid Argument");
            }

            std::vector<T> indexes;
            for (size_t i=0; i<mtx.cols(); i++) {
                if (((size_t)mtx(0,i) != i+1) || (std::binary_search(indexes.begin(), indexes.end(), mtx(1,i)))) {
                    throw std::invalid_argument("Invalid Argument");
                }
                indexes.insert(indexes.cend(), mtx(1,i));
            }
        }

        std::vector<std::vector<T>> Perm(Matrix<T> mtx)
        {
            std::vector<std::vector<T>> arr;

            arr.resize(mtx.cols());
            size_t i=0;
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
        Permutation(Matrix<T> mtx) : Squared<T>(Perm(mtx)){
            permutationCheck(mtx);
        };

        void newSize(size_t s)
        {
            throw std::invalid_argument("Invalid Method");
        };

        T operator () (size_t ir, size_t ic)
        {
            if (ir >= (*this).rows() || ic >= (*this).cols()) {
                throw std::invalid_argument("Invalid Index");
            }

            return Squared<T>::getMatrix()[ir][ic];
        }
    };
}
