namespace ek
{
    template <typename T>
    void Bidiag<T>::GolubKahan(T e)
    {
        init();

        U.newSize(A.rows(),1);

        Vector<T> u(A.rows());
        Vector<T> v(A.cols());
        U(0,0) = 1;

        T a;
        T b;

        Vector<T> va;
        va = A.h() * U.col(0);
        a = va.norm(2);
        v = va/a;
        for (size_t i=0; i<A.cols(); i++)
        {
            V(i,0) = v(i);
        }
        L(0,0) = a;

        size_t j=1;
        do
        {
            Vector<T> bu;
            bu = A * V.col(j-1) - U.col(j-1)*a;
            b = bu.norm(2);
            u = bu/b;
            for (size_t i=0; i<A.rows(); i++)
            {
                U(i,j) = u(i);
            }

            Vector<T> va;
            va = A.h() * U.col(j);
            if (j>0) {va = va - V.col(j-1)*b;}
            a = va.norm(2);
            v = va/a;
            for (size_t i=0; i<A.cols(); i++)
            {
                V(i,j) = v(i);
            }

            L(j,j) = a;
            L(j,j-1) = b;

            j++;
        } while ((L(j-1,j-1) != 0) && (L(j-1,j-2) != 0) && (L(j-1,j-1) > 1/std::pow(10,e)) && (L(j-1,j-2) > 1/std::pow(10,e)));
    }
}
