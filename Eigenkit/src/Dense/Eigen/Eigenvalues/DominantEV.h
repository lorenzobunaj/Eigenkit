namespace ek
{
    // finds if the Power method converged
    template <typename T>
    bool domConv(Matrix<T> p, Matrix<T> s, T e)
    {
        // compare xn - x(n-1) to 10^(-k)
        for (size_t i=0; i<p.rows()-1; i++) {
            if (std::abs(p(i,0)-s(i,0)) > e) {
                return 0;
            }
        }

        return 1;
    }

    // performs the Power method
    template <typename T>
    T Eigen<T>::DominantEV(size_t n, T e)
    {
        // initialize the container of the latest two results
        std::vector<T> vn;
        vn.resize(2);

        // initialize x(0), x(n-1), x(n)
        Matrix<T> x(A.cols(),1);
        for (size_t i = 0; i<x.rows(); i++) {
            x(i,0) = 1;
        }
        Matrix<T> p;
        Matrix<T> s;

        // perform Power algorithm
        size_t i=0;
        do {
            // initialize x(n-1) and x(n)
            p = x;
            s = A*x;

            // find the 2 new values
            s = s/s(s.rows()-1,0);
            x = s;

            i++;
        } while (!domConv(p,s,e) && i<n);

        return Rayleigh(A,x);
    }
}
