namespace ek
{
    template <typename T>
    std::ostream& operator << (std::ostream& os, Matrix<T> mtx)
    {
        size_t i = 0;

        for (auto it : mtx) {
            os << it << " ";
            if((++i)%mtx.cols() == 0 && i/mtx.cols() != mtx.rows()) {os << std::endl;}
        }

        return os;
    };
}
