namespace ek
{
    /*
    template <typename T>
    T conj(T e)
    {
        if (!(isComplex<T>()))
        {
            return e;
        } else {
            return std::conj(e);
        }
    }
    */

    // finds the conjugate matrix
    template <typename T>
    Matrix<T> Matrix<T>::c()
    {
        Matrix<T> out((*this).rows(), (*this).cols());

        auto e = (*this).begin();
        for (auto it = out.begin(); it != out.end(); it++)
        {
            if (isComplex<T>())
            {
                *it = std::conj(*(e++));
            }
            else
            {
                *it = *(e++);
            }
        }

        return out;
    }
    // finds the transposed and conjugate matrix
    template <typename T>
    Matrix<T> Matrix<T>::h()
    {
        return ((*this).t()).c();
    }
}
