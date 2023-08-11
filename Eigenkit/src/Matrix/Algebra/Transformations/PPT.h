namespace ek
{
    template <typename T>
    class PPT : public Transformation<T>
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
        std::vector<std::vector<T>> partialpivize(Matrix<T> A, Matrix<T> indices, size_t j)
        {
            std::vector<std::vector<T>> out;
            // find imax : imax = argmax(A(i,j))
            size_t imax = j + A.col(0).absMaxPos()[0];
            // initialize permutation matrix P : PA swaps rows and AP swap columns
            Permutation<T> P(indSwap(indices, imax, j));

            out = P.mtx();
            return out;
        }

    public:
        // special constructor
        PPT(Matrix<T> A, Matrix<T> indices, size_t j) : Transformation<T>(partialpivize(A, indices, j)){};
    };
}
