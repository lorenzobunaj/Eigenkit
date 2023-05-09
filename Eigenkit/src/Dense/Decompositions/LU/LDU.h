namespace ek
{
    template <typename T>
    class LDU
    {
    private:
        std::vector<Matrix<T>> operators;

        std::vector<Matrix<T>> lduize(Matrix<T> DU)
        {
            Matrix<T> U = DU;
            Matrix<T> D(DU.rows(), DU.cols());

            for (size_t i=0; i<DU.cols(); i++) {
                D(i,i) = DU(i,i);
                for (size_t j=i; j<DU.rows(); j++) {
                    U(i,j) =DU(i,j)/D(i,i);
                }
            }

            return {D, U};
        }
    public:
        Matrix<T> D;
        Matrix<T> U;

        LDU(Matrix<T> DU)
        {
            operators = lduize(DU);
            D = operators[0];
            U = operators[1];
        };
    };
}
