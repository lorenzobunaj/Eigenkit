namespace ek {
    template <typename T>
    class Diagonal : public Squared<T>
    {
    private:
        // check whether a(i,j) = 0 if i != j
        void diagonalCheck (Matrix<T> mtx)
        {
            for (size_t i=0;i<mtx.rows();i++) {
                for (size_t j=0;j<mtx.cols();j++) {
                    if ((i != j) &&  (mtx(i,j) != 0)) {
                        throw std::invalid_argument("Invalid Argument");
                    }
                }
            }
        }
        // input:= vector
        // output:= std::vector array where a(i,j) = vector[i] if i = j  else 0
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
        // get original matrix
        std::vector<std::vector<T>>& getMatrix()
        {
            return Squared<T>::getMatrix();
        }
    public:
        // default constructors
        Diagonal() : Squared<T>(){};
        Diagonal(std::initializer_list<std::initializer_list<T>> arr)
        : Squared<T>(arr){diagonalCheck(*this);};
        // special constructor
        Diagonal(std::vector<T> arr) : Squared<T>(diagonalize(arr)) {};
        // overloaded () operator
        // can modify only elements on the diagonal
        T& operator () (size_t ir, size_t ic)
        {

            if (ir >= (*this).dim() || ic >= (*this).dim()) {
                if (ir != ic) {
                    throw std::invalid_argument("Invalid Index");
                }
                (*this).newSize(std::max(ir+1, ic+1));
            }

            if (ir != ic) {return (*this).mtx()[ir][ic];}

            return (*this).getMatrix()[ir][ic];
        }

        void operator = (Matrix<T>);
    };
}
