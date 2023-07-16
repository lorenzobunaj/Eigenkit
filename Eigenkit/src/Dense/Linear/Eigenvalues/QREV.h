namespace ek
{
    template <typename T>
    std::vector<T> QREV(std::string dec, Matrix<T> A, size_t n, T e)
    {
        if (dec != "householder" && dec != "givens") {
            throw std::invalid_argument("Invalid Decomposition");
        }

        std::vector<T> out;
        out.resize(A.rows());

        size_t q=0;
        while (!conv(A,e) && q<n) {
            QR<T> QR(A);

            if (dec == "householder") {QR.HR();}
            else if (dec == "givens") {QR.GR();}

            Matrix<T> Q = QR.Q;

            A = Q.h() * A * Q;

            q++;
        }

        for (size_t i=0; i<A.rows(); i++) {
            out[i] = A(i,i);
        }

        return out;
    }
}
