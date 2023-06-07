namespace ek
{
    template <typename T>
    class ColPivotQR
    {
    private:
        std::vector<Matrix<T>> operators;

        std::vector<Matrix<T>> colpivotize(Matrix<T> A)
        {
            Matrix<T> ind(2, A.rows());
            for (size_t i=0; i<ind.cols(); i++) {
                ind(0,i) = i+1;
                ind(1,i) = i+1;
            }

            Identity<T> id(A.rows());
            Matrix<T> Pc = id;
            Matrix<T> temp;
            Matrix<T> Q = id;
            Matrix<T> Rc = A;
            Matrix<T> R = Rc;
            Matrix<T> Hc;

            Vector<T> v(0);
            Vector<T> a(0);
            Vector<T> e(A.rows(), 0);
            e(0) = 1;

            for (size_t i=0; i<std::min(A.rows(), A.cols()); i++) {
                ColPivot<T> P(R, ind);
                R = R*P;

                a = R.col(0);
                e.newSize(R.rows());
                v = a + (a(0)/std::abs(a(0)))* a.norm(2)*e;

                Householder<T> H(v);

                R = H*R;
                if (i<std::min(A.rows(), A.cols())-1) {
                    R = R.sub(1,1,R.rows()-1, R.cols()-1);
                }

                Hc = id;
                temp = id;
                for (size_t j=0; j<Rc.rows(); j++) {
                    for (size_t s=0; s<Rc.cols(); s++) {
                        if ((j>=i) && (s>=i)) {
                            Hc(j,s) = H(j-i,s-i);
                            temp(j,s) = P(j-i,s-i);
                        }
                    }
                }

                Pc = Pc*temp;
                Q = Q*Hc;
                Rc = Hc*Rc;
            }

            return {Pc, Q, Rc};
        }
    public:
        Matrix<T> A;
        Matrix<T> P;
        Matrix<T> Q;
        Matrix<T> R;

        ColPivotQR(Matrix<T> mtx)
        {
            operators = colpivotize(mtx);
            A = mtx;
            P = operators[0];
            Q = operators[1];
            R = operators[2];
        };
    };
}
