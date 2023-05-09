namespace ek
{
    template <typename T>
    class HouseholderQR
    {
    private:
        std::vector<Matrix<T>> operators;

        Vector<T> colonize(Matrix<T> A, T j)
        {
            std::vector<T> el;
            el.resize(A.rows());
            for (size_t i=0; i<A.rows(); i++) {
                el[i] = A(i,j);
            }

            Vector<T> out(el);
            return out;
        }

        std::vector<Matrix<T>> houseize(Matrix<T> A)
        {
            Identity<T> id(A.rows());
            Matrix<T> Q = id;
            Matrix<T> R = A;
            Matrix<T> Aj = A;
            Vector<T> v;

            for (size_t j=0; j<A.cols(); j++) {
                Vector<T> a = colonize(Aj,0);
                Vector<T> e(Aj.rows(),1);
                e(0) = 1;

                v = a + std::sqrt(std::pow(a(0),2))/a(0) * a.norm(2) * e;

                Householder<T> H(v);

                Matrix<T> Ht = id;
                if (H.rows() < A.rows()) {

                    for (size_t k=0; k<A.rows(); k++) {
                        for (size_t s=0; s<A.rows(); s++) {
                            if ((k >= j) && (s >= j)) {
                                Ht(k,s) = H(k-j,s-j);
                            }
                        }
                    }
                }

                Q = j==0? Q*H : Q*Ht;
                R = j==0? H*R : Ht*R;

                if (j<A.cols()-1) {
                    Aj = (H*Aj).sub(1,1,Aj.rows()-1,Aj.cols()-1);
                }
            }

            return {Q,R};
        }
    public:
        Matrix<T> A;
        Matrix<T> Q;
        Matrix<T> R;

        HouseholderQR(Matrix<T> mtx)
        {
            operators = houseize(mtx);
            A = mtx;
            Q = operators[0];
            R = operators[1];
        };
    };
}
