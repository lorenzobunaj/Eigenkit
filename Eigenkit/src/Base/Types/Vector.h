namespace ek {
    template <typename T>
    class Vector : public Matrix<T>
    {
    protected:
        // indicate whether the vector is a row one or a column one
        bool row;
        // get original matrix
        std::vector<std::vector<T>>& getMatrix()
        {
            return Matrix<T>::matrix;
        }
        // input:= std::vector vector
        // output:= std::vector array
        std::vector<std::vector<T>> vectorize(std::vector<T> vec)
        {
            std::vector<std::vector<T>> mtx = {vec};
            return mtx;
        }

    public:
        // default constructors
        Vector(bool r) : Matrix<T>(){
            row = r;
        };
        Vector(size_t s, bool r) : Matrix<T>(r == 1 ? 1 : s,r == 0 ? 1 : s){
            row = r;
        };
        // special constructors
        Vector(std::initializer_list<T> arr) : Matrix<T>({arr}){
            row = 1;
        };
        Vector(std::vector<T> vec) : Matrix<T>(vectorize(vec)){
            row = 1;
        };
        // overload newSize function
        // take only one argument
        void newSize(size_t s)
        {
            if (row) {
                Matrix<T>::newSize(1, s);
            } else {
                Matrix<T>::newSize(s, 1);
            }
        }
        // overload () operator
        // take only one argument
        T& operator () (size_t i)
        {
            if (row) {
                if (i >= (*this).cols()) {
                    (*this).newSize(i+1);
                }
                return getMatrix()[0][i];
            } else {
                if (i >= (*this).rows()) {
                    (*this).newSize(i+1);
                }
                return getMatrix()[i][0];
            }
        }
        // return the vector size (maximum between rows and cols)
        size_t dim()
        {
            return std::max((*this).rows(), (*this).cols());
        }

        void operator = (Matrix<T>);
        Vector<T> operator + (T scl);
        Vector<T> operator - (T scl);
        Vector<T> operator * (T scl);

        // overload t function
        // change row parameter
        Vector<T> t()
        {
            Vector<T> out((*this).dim(), !row);

            auto it = (*this).begin();
            for (auto e=out.begin(); e != out.end(); e++) {
                *e = *(it++);
            }

            return out;
        }
        Vector<T> c()
        {
            Vector<T> out((*this).dim(), row);

            auto e = (*this).begin();
            for (auto it=out.begin(); it!=out.end(); it++) {
                *it = std::conj(*(e++));
            }

            return out;
        }

        size_t maxPos();
        size_t minPos();
        // implement products
        T dot(Vector<T>);
        Vector<T> cross(Vector<T>);
        Matrix<T> outer(Vector<T>);

        T norm(T);

        Vector<T> proj(Vector<T> op2)
        {
            Vector<T> op1 = *this;

            return op2 * (op1.dot(op2.t())/op2.dot(op2.t()));
        }
    };
}
