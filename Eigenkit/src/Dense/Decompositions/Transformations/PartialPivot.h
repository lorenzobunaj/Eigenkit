namespace ek
{
    template <typename T>
    class PartialPivot : public Transformation<T>
    {
    private:
        Matrix<T> indSwap (Matrix<T> mtx, size_t i, size_t j)
        {
            T temp = mtx(1,i);
            mtx(1,i) = mtx(1,j);
            mtx(1,j) = temp;

            return mtx;
        }

        std::vector<std::vector<T>> partialpivize(Matrix<T> U, size_t ind, Matrix<T> indices)
        {
            std::vector<std::vector<T>> out;

            Vector<T> c = U.sub(ind, ind, U.rows()-1, U.cols()-1).t().mtx()[0];
            for (size_t i=ind; i<U.rows(); i++) {
                if (U(i,ind) == c.max()) {
                    Permutation<T> P(indSwap(indices,i,ind));
                    out = P.mtx();
                }
            }

            return out;
        }
    public:
        // special constructor
        PartialPivot(Matrix<T> mtx, size_t ind, Matrix<T> indices) : Transformation<T>(partialpivize(mtx, ind, indices)){};
    };
}
