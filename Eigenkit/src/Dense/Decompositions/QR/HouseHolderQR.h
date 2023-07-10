namespace ek
{
    template <typename T>
    class HouseholderQR
    {
    private:
        std::vector<Matrix<T>> operators;
        // converts the constructor inputs to a vector of matrices
        std::vector<Matrix<T>> householderize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> Q = id;
            Matrix<T> Rc = A; // complete matrix R
            Matrix<T> R = Rc;
            Matrix<T> Hc; // complete matrix H
            Vector<T> v(0);
            Vector<T> a(0);
            Vector<T> e(A.rows(), 0);; // canonical basis element

            e(0) = 1;
            for (size_t i=0; i<std::min(A.rows(), A.cols()); i++) {
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
                // save H's elements in larger matrix
                Hc = id;
                for (size_t j=0; j<Rc.rows(); j++) {
                    for (size_t s=0; s<Rc.cols(); s++) {
                        if ((j>=i) && (s>=i)) {
                            Hc(j,s) = H(j-i,s-i);
                        }
                    }
                }
                // update the complete matrices' elements
                Q = Q*Hc;
                Rc = Hc*Rc;
            }

            return {Q, Rc};
        }
    public:
        Matrix<T> A;
        Matrix<T> Q;
        Matrix<T> R;

        // special constructor
        HouseholderQR(Matrix<T> mtx)
        {
            operators = householderize(mtx);
            A = mtx;
            Q = operators[0];
            R = operators[1];
        };
    };
}
