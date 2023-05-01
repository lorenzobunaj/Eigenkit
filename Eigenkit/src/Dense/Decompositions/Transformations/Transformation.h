namespace ek
{
    template <typename T>
    class Transformation : public Squared<T>
    {
    public:
        // special constructor
        Transformation(std::vector<std::vector<T>> arr) : Squared<T>(arr){};
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

            return (*this).mtx()[ir][ic];
        }
    };
}
