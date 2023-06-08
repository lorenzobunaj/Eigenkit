namespace ek
{
    template <typename T>
    class GivensQR
    {
    private:
        std::vector<Matrix<T>> operators;

        std::vector<Matrix<T>> givensize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> Qt = id;
            Matrix<T> R = A;

            for (size_t j=0; j<A.cols(); j++) {
                for (size_t i=j+1; i<A.rows(); i++) {
                    if (A(i,j) == 0) {continue;}

                    T r = std::sqrt(std::pow(R(j,j),2)+std::pow(R(i,j),2));
                    T c = R(j,j)/r;
                    T s = -R(i,j)/r;

                    Givens<T> G(A.rows(),j,i,c,s);

                    Qt = G*Qt;
                    R = G*R;
                }
            }

            return {Qt.t(), R};
        }
    public:
        Matrix<T> A;
        Matrix<T> Q;
        Matrix<T> R;

        GivensQR(Matrix<T> mtx)
        {
            operators = givensize(mtx);
            A = mtx;
            Q = operators[0];
            R = operators[1];
        };
    };
}
