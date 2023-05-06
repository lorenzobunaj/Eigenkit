namespace ek
{
    template <typename T>
    class Elimination : public Transformation<T>
    {
    private:
        std::vector<std::vector<T>> eliminize(Matrix<T> A, size_t j)
        {
            Identity<T> id(A.rows());
            Matrix<T> out = id;

            for (size_t i=j+1; i<A.rows(); i++) {
                out(i,j) = -A(i,j) * 1/A(j,j);
            }


            //std::cout << out << std::endl;
            //std::cout << "..." << std::endl;
            return out.mtx();
        }
    public:
        // special constructor
        Elimination(Matrix<T> mtx, size_t j) : Transformation<T>(eliminize(mtx, j)){};
    };
}
