namespace ek
{
    template <typename T>
    T Matrix<T>::det()
    {
        if (((*this).rows() != (*this).cols()) || ((*this).rows() == 0)) {
            throw std::invalid_argument("Invalid Argument");
        } else if ((*this).rows() == 1) {
            return (*this)(0,0);
        } else {
            T complementSum = 0;
            for (size_t i=0; i<(*this).rows(); i++) {
                complementSum += std::pow(-1,i)*(*this)(i,0)*((*this).complement(i,0)).det();
            }
            return complementSum;
        }


    }
}
