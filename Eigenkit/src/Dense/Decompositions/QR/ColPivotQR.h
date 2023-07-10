namespace ek
{
    template <typename T>
    class ColPivotQR
    {
    private:
        std::vector<Matrix<T>> operators;
        // converts the constructor inputs to a vector of matrices
        std::vector<Matrix<T>> colpivotize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> Pc = id; // complete matrix P
            Matrix<T> temp;
            Matrix<T> Q = id;
            Matrix<T> Rc = A; // complete matrix R
            Matrix<T> R = Rc;
            Matrix<T> Hc; // complete matrix H
            // initialize matrix ind : ind(0,i) = ind(1,i) = i+1
            Matrix<T> ind(2, A.rows());
            for (size_t i=0; i<ind.cols(); i++) {
                ind(0,i) = i+1;
                ind(1,i) = i+1;
            }
            Vector<T> v(0);
            Vector<T> a(0);
            Vector<T> e(A.rows(), 0); // canonical basis element

            e(0) = 1;
            for (size_t i=0; i<std::min(A.rows(), A.cols()); i++) {
                // perform Column Pivoting on the i-th row with temporary matrix P on matrix R
                ColPivot<T> P(R, ind);
                R = R*P;
                // prepare the vector v for the Householder transformation
                a = R.col(0);
                e.newSize(R.rows());
                v = a + (a(0)/std::abs(a(0)))* a.norm(2)*e;
                // perform Householder transformation with temporary matrix H on R
                Householder<T> H(v);
                R = H*R;
                // reduce R from nxm to (n-1)x(m-1)
                if (i<std::min(A.rows(), A.cols())-1) {
                    R = R.sub(1,1,R.rows()-1, R.cols()-1);
                }
                // save P's and H's elements in larger matrices
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
                // update the complete matrices' elements
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

        // special constructor
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
