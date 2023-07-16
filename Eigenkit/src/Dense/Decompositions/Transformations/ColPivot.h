namespace ek
{
    template <typename T>
    class ColPivot : public Transformation<T>
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
        std::vector<std::vector<T>> colpivize(Matrix<T> A, Matrix<T> indices)
        {
            std::vector<std::vector<T>> out;

            size_t jmax=0;
            T norm =0;

            for (size_t j=0;j<A.cols();j++) {
                // initialize vector v : v = j-th A's column
                Vector<T> v;
                v = A.col(j);
                /*// raise error if v is made of zeros
                if (v.norm(2) == 0) {
                    throw std::invalid_argument("Invalid Arguments");
                }*/
                // find jmax : jmax = argmax(A.col(j).norm(2))
                if (v.norm(2) > norm) {
                    norm = v.norm(2);
                    jmax = j;
                }
            }
            // initialize permutation matrix P : PA swaps rows and AP swap columns
            Permutation<T> P(indSwap(indices,jmax,0));
            out = P.mtx();

            return out;
        }
    public:
        // special constructor
        ColPivot(Matrix<T> A, Matrix<T> indices) : Transformation<T>(colpivize(A, indices)){};
    };
}
