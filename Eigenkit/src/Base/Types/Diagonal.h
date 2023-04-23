namespace ek {
    template <typename T>
    class Diagonal : public Squared<T>
    {
    private:
        void diagonalCheck (Squared<T> mtx)
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

    protected:
        std::vector<std::vector<T>>& getMatrix()
        {
            return Squared<T>::getMatrix();
        }

    public:
        Diagonal() : Squared<T>(){};

        Diagonal(std::initializer_list<std::initializer_list<T>> arr)
        : Squared<T>(arr){diagonalCheck(*this);};

        Diagonal(std::vector<T> arr) : Squared<T>(diagonalize(arr)) {};

        T& operator () (size_t ir, size_t ic)
        {
            std::vector<std::vector<T>> matrix = (*this).getMatrix();

            if (ir >= (*this).dim() || ic >= (*this).dim()) {
                if (ir != ic) {
                    throw std::invalid_argument("Invalid Index");
                }
                (*this).newSize(std::max(ir+1, ic+1));
            }

            if (ir != ic) {return matrix[ir][ic];}

            return (*this).getMatrix()[ir][ic];
        }
    };
}
