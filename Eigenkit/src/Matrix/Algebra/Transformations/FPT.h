namespace ek
{
    template <typename T>
    class FPT
    {
    private:
        // swaps elements in the 2nd row of a matrix
        Matrix<T> indSwap(Matrix<T> A, size_t i, size_t j)
        {
            T temp = A(1, i);
            A(1, i) = A(1, j);
            A(1, j) = temp;

            return A;
        }
        // converts the constructor inputs to an array
        std::vector<Matrix<T>> fullpivize(Matrix<T> A, Matrix<T> indRow, Matrix<T> indCol, size_t j)
        {
            // find pmax : pmax = argmax(A(x,y))
            std::vector<size_t> pmax = A.sub(j, j, A.rows() - 1, A.cols() - 1).absMaxPos();
            // initialize permutation matrices M : MA swaps rows and AM swap columns
            Permutation<T> P(indSwap(indRow, j, pmax[0] + j));
            Permutation<T> Q(indSwap(indCol, j, pmax[1] + j));

            std::vector<Matrix<T>> out = {P, Q};
            return out;
        }

    public:
        Matrix<T> P;
        Matrix<T> Q;

        // special constructor
        FPT(Matrix<T> A, Matrix<T> indRow, Matrix<T> indCol, size_t j)
        {
            std::vector<Matrix<T>> components = fullpivize(A, indRow, indCol, j);
            P = components[0];
            Q = components[1];
        }
    };
}
