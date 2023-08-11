namespace ek
{
    template <typename T>
    void UBV<T>::Lanczos(Vector<T> vec, T e)
    {
        Vector<T> u;
        Vector<T> v;
        T a;
        T b;

        for (size_t i=0; i<A.rows(); i++)
        {
            U(i,0) = vec(i)/(vec.norm(2));
        }

        Vector<T> va;
        va = A.h() * U.col(0);
        a = va.norm(2);
        v = va/a;
        for (size_t i=0; i<A.cols(); i++)
        {
            V(i,0) = v(i);
        }
        B(0,0) = a;

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

            B(j,j) = a;
            B(j,j-1) = b;

            j++;
        }
        while
        (
            (B(j-1,j-1) > A.absMin()/std::pow(10,e)) &&
            (B(j-1,j-2) > A.absMin()/std::pow(10,e))
        );
    }
}
