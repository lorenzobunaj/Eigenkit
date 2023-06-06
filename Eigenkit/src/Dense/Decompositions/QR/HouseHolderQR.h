namespace ek
{
    template <typename T>
    class HouseholderQR
    {
    private:
        std::vector<Matrix<T>> operators;

        std::vector<Matrix<T>> householderize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> Q = id;
            Matrix<T> Rc = A;
            Matrix<T> R = Rc;
            Matrix<T> Hc;

            Vector<T> v(0);
            Vector<T> a(0);
            Vector<T> e(A.rows(), 0);
            e(0) = 1;

            for (size_t i=0; i<std::min(A.rows(), A.cols()); i++) {
                a = R.col(0);
                e.newSize(R.rows());
                v = a + (a(0)/std::abs(a(0)))* a.norm(2)*e;

                Householder<T> H(v);

                R = H*R;
                if (i<std::min(A.rows(), A.cols())-1) {
                    R = R.sub(1,1,R.rows()-1, R.cols()-1);
                }

                Hc = id;
                for (size_t j=0; j<Rc.rows(); j++) {
                    for (size_t s=0; s<Rc.cols(); s++) {
                        if ((j>=i) && (s>=i)) {
                            Hc(j,s) = H(j-i,s-i);
                        }
                    }
                }

                Q = Q*Hc;
                Rc = Hc*Rc;
            }

            return {Q, Rc};
        }
    public:
        Matrix<T> A;
        Matrix<T> Q;
        Matrix<T> R;

        HouseholderQR(Matrix<T> mtx)
        {
            operators = householderize(mtx);
            A = mtx;
            Q = operators[0];
            R = operators[1];
        };
    };
}
