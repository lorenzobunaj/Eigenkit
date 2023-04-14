namespace ek
{
    template <typename T, bool D>
    static Matrix<T, D, D> matrix (Squared<T, D> sq)
    {
        Matrix<T,D,D> mtx(sq.rows(), sq.cols());

        auto it = sq.begin();
        for (auto e = mtx.begin(); e != mtx.end(); e++) {
            *e = *(it++);
        }

        return mtx;
    }
}

