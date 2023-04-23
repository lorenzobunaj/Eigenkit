namespace ek
{
    template <typename T>
    static Matrix<T> matrix (Squared<T> sq)
    {
        Matrix<T> mtx(sq.rows(), sq.cols());

        if (sq.rows() == 0) {return mtx;}

        auto it = sq.begin();
        for (auto e = mtx.begin(); e != mtx.end(); e++) {
            *e = *(it++);
        }

        return mtx;
    }

    template <typename T>
    static Matrix<T> matrix (Vector<T> vec)
    {
        Matrix<T> mtx(vec.rows(), vec.cols());

        if (vec.rows() == 0) {return mtx;}

        auto it = vec.begin();
        for (auto e = mtx.begin(); e != mtx.end(); e++) {
            *e = *(it++);
        }

        return mtx;
    }

    template <typename T>
    static Matrix<T> matrix (Binary<T> bn)
    {
        Matrix<T> mtx(bn.rows(), bn.cols());

        if (bn.rows() == 0) {return mtx;}

        auto it = bn.begin();
        for (auto e = mtx.begin(); e != mtx.end(); e++) {
            *e = *(it++);
        }

        return mtx;
    }
}
