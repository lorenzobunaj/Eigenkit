namespace ek {
    template <typename T>
    class Ones : public Vector<T>
    {
    private:
        void onesCheck(Vector<T> vec)
        {
            for (auto it=vec.begin(); it != vec.end(); it++) {
                if (*it != 1) {
                    throw std::invalid_argument("Invalid Argument");
                }
            }
        }

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
        bool row = Vector<T>::row;

        std::vector<std::vector<T>>& getMatrix()
        {
            return Vector<T>::getMatrix();
        }

    public:
        Ones() : Vector<T>(){};
        Ones(size_t s) : Vector<T>(onesize(s)){};
        Ones(std::initializer_list<T> arr) : Vector<T>({arr}){
            onesCheck(*this);
        };

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

        T& operator () (size_t i)
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
