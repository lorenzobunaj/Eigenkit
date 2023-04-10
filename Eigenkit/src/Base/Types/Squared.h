namespace ek {
    template <typename T, bool D=1>
    class Squared : public Matrix<T,D,D>
    {
    public:
        Squared() : Matrix<T,D,D>(){};
        Squared(size_t r, size_t c) : Matrix<T,D,D>(r, c)
        {
            squaredCheck(*this);
        };
        Squared(std::initializer_list<std::initializer_list<T>> arr) : Matrix<T,D,D>(arr)
        {
            squaredCheck(*this);
        };
        Squared(std::vector<std::vector<T>> arr) : Matrix<T,D,D>(arr)
        {
            squaredCheck(*this);
        };

        void newSize(size_t s)
        {
            Matrix<T,D,D>::newSize(s, s);
        }

        void squaredCheck(Matrix<T,D,D> mtx)
        {
            if (mtx.rows() != mtx.cols()) {
                throw std::invalid_argument("Invalid Argument");
            }
        }
    };
}
