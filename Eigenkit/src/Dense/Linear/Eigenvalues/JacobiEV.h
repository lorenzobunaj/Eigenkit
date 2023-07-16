namespace ek
{
    template <typename T>
    bool conv(Matrix<T> A, T e)
    {
        T frobNorm = 0;
        T diagNorm = 0;

        for (size_t i=0; i<A.rows(); i++) {
            for (size_t j=0; j<A.cols(); j++) {
                frobNorm += std::pow(A(i,j),2);
                diagNorm += i==j ? A(i,j) : 0;
            }
        }

        return (std::abs(frobNorm-diagNorm)/A.rows() <= e);
    }

    template <typename T>
    T Error(Matrix<T> A /*, size_t k*/)
    {
        T out = 0;

        for (size_t i=0; i<A.rows(); i++) {
            for (size_t j=0; j<A.cols(); j++) {
                if (i!=j) {out += std::pow(A(i,j),2);}
            }
        }

        return out/(A.rows()*(A.rows()-1));
        //return out/(A.rows()*(A.rows()-1))/std::pow(10,k);
    }

    template <typename T>
    std::vector<T> JacobiEV(Matrix<T> A, size_t n, T e)
    {
        std::vector<T> out;
        out.resize(A.rows());

        size_t q=0;
        T r;
        T c;
        T s;
        /* bool f=0 */
        /* T it = 0 */
        while (!conv(A,e) && q<n) {
            for (size_t j=0; j<A.cols(); j++) {
                for (size_t i=0; i<j; i++) {
                    // check if the element is 0
                    if (A(i,j) == 0) {continue;}

                    if (std::pow(A(i,j),2) >= Error(A/*, it*/)) {
                        // check if the element is 0
                        if (A(i,j) == 0) {continue;}

                        // initialize r : r^2 = R(j,j)^2 + R(i,j)^2
                        r = std::sqrt(std::pow(A(j,j),2)+std::pow(A(i,j),2));

                        // initialize c, s : c = cos(t), s = sin(t) for a given rotation angle t
                        c = A(j,j)/r;
                        s = -A(i,j)/r;
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

        for (size_t i=0; i<A.rows(); i++) {
            out[i] = A(i,i);
        }

        return out;
    }
}
