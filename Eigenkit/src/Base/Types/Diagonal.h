namespace ek {
    template <typename T, bool D=1>
    class Diagonal : public Squared<T,D>
    {
    private:
        void diagonalCheck (Squared<T,D> mtx)
        {
            for (size_t i=0;i<mtx.rows();i++) {
                for (size_t j=0;j<mtx.cols();j++) {
                    if ((i != j) &&  (mtx(i,j) != 0)) {
                        throw std::invalid_argument("Invalid Argument");
                    }
                }
            }
        }
        std::vector<std::vector<T>> diagonalize (std::vector<T> arr) {
            std::vector<std::vector<T>> diag;

            diag.resize(arr.size());
            size_t i=0;
            for (auto r=diag.begin(); r != diag.end(); r++) {
                (*r).resize(arr.size());
                (*r)[i] = arr[i];
                i++;
            }

            return diag;
        }

    public:
        Diagonal() : Squared<T,D>(){};
        Diagonal(std::initializer_list<std::initializer_list<T>> arr) : Squared<T,D>(arr){
            diagonalCheck(*this);
        };
        Diagonal(std::vector<T> arr) : Squared<T,D>(diagonalize(arr)) {};
    };
}
