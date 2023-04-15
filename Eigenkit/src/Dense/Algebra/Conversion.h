namespace ek
{
    template <typename T, bool D>
    static Matrix<T, D, D> matrix (Squared<T, D> sq)
    {
        Matrix<T,D,D> mtx(sq.dim(), sq.dim());

        if (sq.dim() == 0) {return mtx;}

        auto it = sq.begin();
        for (auto e = mtx.begin(); e != mtx.end(); e++) {
            *e = *(it++);
        }

        return mtx;
    }

    template <typename T, bool D>
    static Matrix<T, D, D> matrix (Vector<T, D> vec)
    {
        std::vector<size_t> dim;

        if (vec.rows() == 1) {
            dim = {1, vec.dim()};
        } else if (vec.cols() == 1) {
            dim = {vec.dim(), 1};
        } else {
            Matrix<T, D, D> mtx;
            return mtx;
        }

        Matrix<T, D, D> mtx(dim[0], dim[1]);

        auto it = vec.begin();
        for (auto e = mtx.begin(); e != mtx.end(); e++) {
            *e = *(it++);
        }

        return mtx;
    }

    template <bool DR, bool DC>
    static Matrix<int, DR, DC> matrix (Binary<DR, DC> bn)
    {
        Matrix<int, DR, DC> mtx(bn.rows(), bn.cols());

        if (bn.rows() == 0) {return mtx;}

        auto it = bn.begin();
        for (auto e = mtx.begin(); e != mtx.end(); e++) {
            *e = *(it++);
        }

        return mtx;
    }
}

