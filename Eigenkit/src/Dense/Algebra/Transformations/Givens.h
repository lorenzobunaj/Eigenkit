namespace ek
{
    template <typename T>
    class Givens : public Squared<T>
    {
    private:
        std::vector<std::vector<T>> givensize(size_t s, size_t ir, size_t ic, T a)
        {
            std::vector<std::vector<T>> arr;

            arr.resize(s);
            size_t i=0;
            for (auto r = arr.begin(); r != arr.end(); r++) {
                (*r).resize(s);
                (*r)[i++] = 1;
            }
            arr[ir][ir] = std::cos(a);
            arr[ic][ic] = std::cos(a);
            arr[ir][ic] = -std::sin(a);
            arr[ic][ir] = std::sin(a);

            return arr;
        }
    protected:
        // get original matrix
        std::vector<std::vector<T>>& getMatrix()
        {
            return Squared<T>::matrix;
        }
    public:
        // special constructor
        Givens(size_t s, size_t ir, size_t ic, T a) : Squared<T>(givensize(s,ir,ic,a)){};
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
