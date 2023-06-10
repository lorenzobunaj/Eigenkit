namespace ek
{
    template <typename T>
    class FullPivot
    {
    private:
        // swaps elements in the 2nd row of a matrix
        Matrix<T> indSwap (Matrix<T> A, size_t i, size_t j)
        {
            T temp = A(1,i);
            A(1,i) = A(1,j);
            A(1,j) = temp;

            return A;
        }
        // converts the constructor inputs to an array
        std::vector<Matrix<T>> fullpivize(Matrix<T> A, size_t j, Matrix<T> indices)
        {
            // find pmax : pmax = argmax(A(x,y))
            std::vector<size_t> pmax = A.sub(j,j,A.rows()-1,A.cols()-1).absMaxPos();
            // initialize permutation matrices M : MA swaps rows and AM swap columns
            Permutation<T> P(indSwap(indices, j, pmax[0]+j));
            Permutation<T> Q(indSwap(indices, j, pmax[1]+j));

            std::vector<Matrix<T>> out = {P,Q};
            return out;
        }
    public:
        Matrix<T> P;
        Matrix<T> Q;

        // special constructor
        FullPivot(Matrix<T> A, size_t j, Matrix<T> indices)
        {
            std::vector<Matrix<T>> components = fullpivize(A, j, indices);
            P = components[0];
            Q = components[1];
        }
    };
}
