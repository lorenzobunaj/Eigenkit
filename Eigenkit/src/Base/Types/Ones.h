namespace ek {
    template <typename T>
    class Ones : public Vector<T>
    {
    private:
        // check whether the vector contains only 1s
        void onesCheck(Vector<T> vec)
        {
            for (auto it=vec.begin(); it != vec.end(); it++) {
                if (*it != 1) {
                    throw std::invalid_argument("Invalid Argument");
                }
            }
        }
        // input:= size
        // output:= std::vector so that a(i) = 1 for all i
        std::vector<T> onesize(size_t s)
        {
            std::vector<T> vec;
            vec.resize(s);
            for (auto it = vec.begin(); it != vec.end(); it++) {
                *it = 1;
            }

            return vec;
        }

    protected:
        // inheritance row parameter
        bool row = Vector<T>::row;
        // get original matrix
        std::vector<std::vector<T>>& getMatrix()
        {
            return Vector<T>::getMatrix();
        }

    public:
        // default constructors
        Ones() : Vector<T>(){};
        Ones(std::initializer_list<T> arr) : Vector<T>(arr){
            onesCheck(*this);
        };
        // special constructor
        Ones(size_t s) : Vector<T>(onesize(s)){};
        // overload newSize function
        // normal newSize but new elements are 1s (not 0s)
        void newSize(size_t s)
        {
            if (row) {
                size_t srt = (*this).cols()-1;
                Vector<T>::newSize(1, s);

                for (size_t i=srt; i<(*this).cols(); i++) {
                    getMatrix()[0][i] = 1;
                }
            } else {
                size_t srt = (*this).rows()-1;
                Vector<T>::newSize(s, 1);

                for (size_t i=srt; i<(*this).rows(); i++) {
                    getMatrix()[i][0] = 1;
                }
            }
        }
        // overload () operator
        // can't modify elements
        T operator () (size_t i)
        {
            if (row) {
                if (i >= (*this).cols()) {
                    (*this).newSize(i+1);
                    (*this)(i) = 1;
                }
                return getMatrix()[0][i];
            } else {
                if (i >= (*this).rows()) {
                    (*this).newSize(i+1);
                    (*this)(i) = 1;
                }
                return getMatrix()[i][0];
            }
        }
    };
}
