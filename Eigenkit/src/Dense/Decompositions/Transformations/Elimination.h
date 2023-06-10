namespace ek
{
    template <typename T>
    class Elimination : public Transformation<T>
    {
    private:
        // converts the constructor inputs to an array
        std::vector<std::vector<T>> eliminize(Matrix<T> A, size_t j)
        {
            // initialize array out : out(i,j) = i==j ? 1 : 0
            Identity<T> id(A.rows());
            Matrix<T> out = id;
            // assign out(i,j) values : out*A performs Gaussian Elimination to A
            for (size_t i=j+1; i<A.rows(); i++) {
                out(i,j) = -A(i,j) * 1/A(j,j);
            }

            return out.mtx();
        }
    public:
        // special constructor
        Elimination(Matrix<T> A, size_t j) : Transformation<T>(eliminize(A, j)){};
    };
}
