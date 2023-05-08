namespace ek
{
    template <typename T>
    class CholeskySRF
    {
    private:
        std::vector<Matrix<T>> components;

        std::vector<Matrix<T>> sfrcholeskize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> L = id;
            Matrix<T> D = A;

            for (size_t j=0; j<A.cols()-1; j++) {
                for (size_t i=j+1; i<D.rows(); i++) {
                    L(i,j) = D(i,j) / D(j,j);
                }

                Elimination<T> M(D,j);
                D = M * D;
                D = D * M.t();
            }

            return {L,D};
        }
    public:
        Matrix<T> A;
        Matrix<T> L;
        Matrix<T> D;

        CholeskySRF(Matrix<T> mtx)
        {
            components = sfrcholeskize(mtx);
            A = mtx;
            L = components[0];
            D = components[1];
        };
    };
}
