namespace ek
{
    // finds the inverse matrix with determinant and cofactors
    template <typename T>
    Matrix<T> Matrix<T>::inverse()
    {
        if ((*this).det() == 0) {
            throw std::invalid_argument("Invalid Argument");
        }

        return (1/(*this).det()) * (*this).cofactors().t();
    }
}
