namespace ek
{
    // estimates if the algorithm has to be computed
    template <typename T>
    T jError(Matrix<T> A /*, size_t k*/)
    {
        // initialize the Frobenius norm and A's size sqrtared
        T frobNorm = 0;
        size_t n = A.rows();

        // find the value of the Frobenius norm
        for (size_t i=0; i<n; i++) {
            for (size_t j=0; j<n; j++) {
                if (i!=j) {frobNorm += std::pow(A(i,j),2);}
            }
        }

        return frobNorm/(n*(n-1));
        //return out/(A.rows()*(A.rows()-1))/std::pow(10,k);
    }

    // performs the Jacobi algorithm
    template <typename T>
    std::vector<T> Eigen<T>::Jacobi(size_t n, T e)
    {
        // initialize the eigenvalues container
        std::vector<T> ev;
        ev.resize(A.rows());

        /* bool f=0 */
        /* T it = 0 */
        size_t q=0;
        while (!jqrConv(A,e) && q<n) {
            for (size_t j=0; j<A.cols(); j++) {
                for (size_t i=0; i<j; i++) {
                    // check if the element is 0
                    if (A(i,j) == 0) {continue;}

                    // compare A(i,j) to the error
                    if (std::pow(A(i,j),2) >= jError(A/*, it*/)) {
                        // check if the element is 0
                        if (A(i,j) == 0) {continue;}

                        // initialize r : r^2 = R(j,j)^2 + R(i,j)^2
                        T r = std::sqrt(std::pow(A(j,j),2)+std::pow(A(i,j),2));

                        // initialize c, s : c = cos(t), s = sin(t) for a given rotation angle t
                        T c = A(j,j)/r;
                        T s = -A(i,j)/r;
                        Givens<T> G(A.rows(), i, j, c, s);

                        A =   G.t() * A * G;
                        /*f=1*/
                    }
                }
            }

            /* if (f==0) {it++;}*/
            /*f=0*/
            q++;
        }

        // insert the eigenvalues in the container
        for (size_t i=0; i<A.rows(); i++) {
            ev[i] = A(i,i);
        }

        return ev;
    }
}
