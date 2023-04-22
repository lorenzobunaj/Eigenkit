namespace ek
{
    template <typename T, bool DR, bool DC>
    Matrix<T, DR, DC> Matrix<T, DR, DC>::operator + (Matrix<T, DR, DC> mtx)
    {
        auto it = (*this).begin();
        for (auto e = mtx.begin(); e != mtx.end(); e++) {
            *e += *(it++);
        }

        return mtx;
    }
}
