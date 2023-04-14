namespace ek
{
    template <typename T, bool DR, bool DC>
    std::ostream& operator << (std::ostream& os, Matrix<T, DR, DC> mtx)
    {
        for (size_t i=0; i<mtx.rows(); i++) {
            for (size_t j=0; j<mtx.cols(); j++) {
                os << mtx(i,j) << " ";
            }
            if(i != mtx.rows()-1) {os << std::endl;}
        }
        return os;
    };
}
