namespace ek
{
    template <typename T>
    class GivensQR
    {
    private:
        std::vector<Matrix<T>> operators;
        // converts the constructor inputs to a vector of matrices
        std::vector<Matrix<T>> givensize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> Qt = id; // transposed matrix Q
            Matrix<T> R = A;

            for (size_t j=0; j<A.cols(); j++) {
                for (size_t i=j+1; i<A.rows(); i++) {
                    if (A(i,j) == 0) {continue;}
                    // initialize r : r^2 = R(j,j)^2 + R(i,j)^2
                    T r = std::sqrt(std::pow(R(j,j),2)+std::pow(R(i,j),2));
                    // initialize c, s : c = cos(t), s = sin(t) for a given rotation angle t
                    T c = R(j,j)/r;
                    T s = -R(i,j)/r;
                    // perform Givens rotation
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

        // special constructor
        GivensQR(Matrix<T> mtx)
        {
            operators = givensize(mtx);
            A = mtx;
            Q = operators[0];
            R = operators[1];
        };
    };
}
