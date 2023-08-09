namespace ek
{
    template <typename T>
    void Bidiag<T>::Lanczos(Vector<T> vec, T e)
    {
        init();
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
        }
        while
        (
            (L(j-1,j-1) > A.absMin()/std::pow(10,e)) &&
            (L(j-1,j-2) > A.absMin()/std::pow(10,e))
        );
    }
}

/*
namespace ek
{
    template <typename T>
    void Bidiag<T>::Lanczos(Vector<T> vec, T e)
    {
        init();
        Identity<T> idr(A.rows());
        Identity<T> idl(A.cols());
        std::vector<T> a;
        std::vector<T> b;
        Vector<T> gl;
        Vector<T> gr;

        // 0
        b.resize(1);
        b[0] = vec.norm(2);
        for (size_t i=0; i<vec.dim(); i++)
        {
            U(i,0) = vec(i)/b[0];
        }

        // 1.1
        gl = A.t()*(U.col(0));
        // 1.2
        a.resize(1);
        a[0] = gl.norm(2);
        for (size_t i=0; i<gl.dim(); i++)
        {
            V(i,0) = gl(i)/a[0];
        }
        B(0,0) = a[0];

        // 2.1
        gr = A*V.col(0);
        // 2.2
        //b.resize(2);
        //b[1] = gr.norm(2);
        //for (size_t i=0; i<gr.dim(); i++)
        //{
        //    U(i,1) = gr(i)/b[1];
        //}
        //B(1,0) = b[1];


        // 3
        size_t j=1;
        while
        (
            B(j-1,j-2) > 1/std::pow(10,e) &&
            B(j-1,j-1) > 1/std::pow(10,e)
        )
        {
            b.resize(j+1);
            b[j] = gr.norm(2);
            for (size_t i=0; i<gr.dim(); i++)
            {
                U(i,j) = gr(i)/b[j];
            }
            B(j,j-1) = b[j];

            // 3.1
            gl = A.t()*U.col(j) - V.col(j-1)*b[j];
            a.resize(j+1);
            a[j] = gl.norm(2);
            for (size_t i=0; i<gl.dim(); i++)
            {
                V(i,j) = gl(i)/a[j];
            }
            B(j,j) = a[j];

            // 3.2
            gr = A*V.col(j) - U.col(j)*a[j];

            j++;
        }
    }
}
*/


