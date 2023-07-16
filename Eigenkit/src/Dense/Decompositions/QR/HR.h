namespace ek
{
    template <typename T>
    void QR<T>::HR()
    {
        // initialize class matrices
        // letter "i" near the matrix name means "i-th"
        // letter "t" near the matrix name means "temporary"
        Identity<T> idl(A.rows());
        Identity<T> idr(A.cols());
        P = idr;
        Q = idl;
        R = A;
        Matrix<T> Ri = A;
        Matrix<T> Ht;

        for (size_t i=0; i<range(); i++) {

            // perform Householder transformation with temporary matrix H on R
            Vector<T> v = refVector(Ri);
            Householder<T> H(v);
            Ri = H*Ri;

            // initialize R(i+1) (reduce Ri from nxm to (n-1)x(m-1))
            if (i<range()-1) {
                Ri = Ri.sub(1,1,Ri.rows()-1, Ri.cols()-1);
            }

            // save H's elements in larger matrix
            Ht = idl;
            for (size_t j=0; j<Ht.rows(); j++) {
                for (size_t s=0; s<Ht.cols(); s++) {
                    if ((j>=i) && (s>=i)) {
                        Ht(j,s) = H(j-i,s-i);
                    }
                }
            }

            // update the complete matrices' elements
            Q = Q*Ht;
            R = Ht*R;
        }
    }
}
