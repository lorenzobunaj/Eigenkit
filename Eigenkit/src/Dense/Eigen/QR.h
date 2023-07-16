namespace ek
{
    template <typename T>
    std::vector<T> Eigen<T>::EQR(std::string dec, size_t n, T e)
    {
        // check if the chosen decomposition exists
        if (dec != "householder" && dec != "givens") {
            throw std::invalid_argument("Invalid Decomposition");
        }

        // initialize the eigenvalues container
        std::vector<T> ev;
        ev.resize(A.rows());

        // perform the QR algorithm
        size_t q=0;
        while (!jqrConv(A,e) && q<n) {
            // find the decomposition
            QR<T> d(A);
            if (dec == "householder") {d.HR();}
            else if (dec == "givens") {d.GR();}

            // A(n+1) = Q.h * A(n) * Q
            Matrix<T> Q = d.Q;
            A = Q.h() * A * Q;

            q++;
        }

        // insert the eigenvalues in the container
        for (size_t i=0; i<A.rows(); i++) {
            ev[i] = A(i,i);
        }

        return ev;
    }
}
