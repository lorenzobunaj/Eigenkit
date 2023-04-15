namespace ek
{
    template <typename T, bool DR, bool DC>
    std::ostream& operator << (std::ostream& os, Matrix<T, DR, DC> mtx)
    {
        size_t i = 0;

        for (auto it : mtx) {
            os << it << " ";
            if((++i)%mtx.cols() == 0 && i/mtx.cols() != mtx.rows()) {os << std::endl;}
        }

        return os;
    };
}
