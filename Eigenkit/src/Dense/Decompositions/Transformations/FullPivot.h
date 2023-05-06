namespace ek
{
    template <typename T>
    class FullPivot
    {
    private:
        Matrix<T> indSwap (Matrix<T> mtx, size_t i, size_t j)
        {
            T temp = mtx(1,i);
            mtx(1,i) = mtx(1,j);
            mtx(1,j) = temp;

            return mtx;
        }

        std::vector<Matrix<T>> fullpivize(Matrix<T> U, size_t j, Matrix<T> indices)
        {
            std::vector<size_t> s = U.sub(j,j,U.rows()-1,U.cols()-1).absMaxPos();

            Permutation<T> P(indSwap(indices, j, s[0]+j));
            Permutation<T> Q(indSwap(indices, j, s[1]+j));

            std::vector<Matrix<T>> out = {P,Q};

            return out;
        }
    public:
        Matrix<T> P;
        Matrix<T> Q;

        // special constructor
        FullPivot(Matrix<T> mtx, size_t j, Matrix<T> indices)
        {
            std::vector<Matrix<T>> components = fullpivize(mtx, j, indices);

            P = components[0];
            Q = components[1];
        }
    };
}
