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

            size_t idx = ind + U.sub(ind,ind,U.rows()-1,ind).maxPos()[0];
            Permutation<T> P(indSwap(indices,idx,ind));
            out = P.mtx();

            return out;
        }
    public:
        // special constructor
        PartialPivot(Matrix<T> mtx, size_t ind, Matrix<T> indices) : Transformation<T>(partialpivize(mtx, ind, indices)){};
    };
}
