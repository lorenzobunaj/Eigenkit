namespace ek
{
    template <typename T>
    void QR<T>::GR()
    {
        // initialize class matrices
        // letter "t" near the matrix name means "transposed"
        Identity<T> idl(A.rows());
        Identity<T> idr(A.cols());
        P = idr;
        Matrix<T> Qt = idl;
        R = A;

        for (size_t j=0; j<A.cols(); j++) {
            for (size_t i=j+1; i<A.rows(); i++) {
                // check if the element is 0
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

        Q = Qt.t();
    }
}
