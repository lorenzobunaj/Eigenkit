namespace ek
{
    template <typename T>
    class Householder : public Squared<T>
    {
    private:
        Matrix<T> householderize(Vector<T> vec)
        {
            Identity<T> id(vec.dim());
            Matrix<T> out = id - (T)2*vec.outer(vec.c());

            return out;
        }
    protected:
        // get original matrix
        std::vector<std::vector<T>>& getMatrix()
        {
            return Squared<T>::matrix;
        }
    public:
        // special constructor
        Householder(Vector<T> vec) : Squared<T>(householderize(vec).mtx()){};
        // overload newSize function
        // break the inheritance
        void newSize(size_t s)
        {
            throw std::invalid_argument("Invalid Method");
        };
        // overload () operator
        // can't modify elements
        T operator () (size_t ir, size_t ic)
        {
            if (ir >= (*this).rows() || ic >= (*this).cols()) {
                throw std::invalid_argument("Invalid Index");
            }

            return getMatrix()[ir][ic];
        }
    };
}
