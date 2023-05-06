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

        std::vector<std::vector<T>> partialpivize(Matrix<T> U, size_t j, Matrix<T> indices)
        {
            std::vector<std::vector<T>> out;

            size_t sr = j + U.sub(j,j,U.rows()-1,j).absMaxPos()[0];
            Permutation<T> P(indSwap(indices,sr,j));
            out = P.mtx();

            return out;
        }
    public:
        // special constructor
        PartialPivot(Matrix<T> mtx, size_t j, Matrix<T> indices) : Transformation<T>(partialpivize(mtx, j, indices)){};
    };
}
