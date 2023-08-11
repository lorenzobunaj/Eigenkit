namespace ek
{
    template <typename T>
    void UBV<T>::Householder()
    {
        Identity<T> idl(A.rows());
        Identity<T> idr(A.cols());
        Matrix<T> temp(A.rows(),A.cols());

        U = idl;
        B = temp;
        V = idr;
        Matrix<T> Ai = A;

        Vector<T> v(0);

        for (size_t i=0; i<range()-1; i++)
        {

            Vector<T> c;
            c = Ai.col(0);
            T b = c.norm(2);
            B(i,i) = b;

            Ai = Ai.sub(0,1,Ai.rows()-1,Ai.cols()-1);

            Vector<T> e1(c.dim(),0);
            e1(0) = 1;
            v = c - e1*b;

            HouseholderT<T> H(v);
            Ai = H*Ai;

            Matrix<T> Ht = idl;
            for (size_t j=0; j<Ht.rows(); j++)
            {
                for (size_t s=0; s<Ht.cols(); s++)
                {
                    if ((j >= i) && (s >= i))
                    {
                        Ht(j,s) = H(j-i,s-i);
                    }
                }
            }
            U = U*Ht;


            Vector<T> r;
            r = Ai.row(0).t();
            T a = r.norm(2);
            B(i,i+1) = a;

            Ai = Ai.sub(1,0,Ai.rows()-1,Ai.cols()-1);

            Vector<T> e2(r.dim(),0);
            e2(0) = 1;
            v = r - e2*a;

            HouseholderT<T> Q(v);
            Ai = Ai*Q;

            Matrix<T> Qt = idr;
            for (size_t j=0; j<Qt.rows()-1; j++)
            {
                for (size_t s=0; s<Qt.cols()-1; s++)
                {
                    if ((j >= i) && (s >= i))
                    {
                        Qt(j,s) = Q(j-i,s-i);
                    }
                }
            }
            V = V*Qt;

        }
    }
}
