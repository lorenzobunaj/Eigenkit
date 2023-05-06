namespace ek
{
    template <typename T>
    T Matrix<T>::max()
    {
        T M=*((*this).begin());
        for (auto it=(*this).begin(); it!=(*this).end(); it++) {
            M = std::max(M, *it);
        }

        return M;
    }
    template <typename T>
    T Matrix<T>::absMax()
    {
        T M=*((*this).begin());
        for (auto it=(*this).begin(); it!=(*this).end(); it++) {
            M = std::max(std::abs(M), std::abs(*it));
        }

        return M;
    }
    template <typename T>
    T Matrix<T>::min()
    {
        T m=*((*this).begin());
        for (auto it=(*this).begin(); it!=(*this).end(); it++) {
            m = std::min(m, *it);
        }

        return m;
    }
    template <typename T>
    std::vector<size_t> Matrix<T>::maxPos(std::vector<T> na)
    {
        std::vector<size_t> null;
        if ((*this).rows() == 0) {return null;}

        size_t Mr=0;
        size_t Mc=0;

        for (size_t i=0; i<(*this).rows();i++) {
            for (size_t j=0; j<(*this).cols();j++) {
                if ((*this)(i,j) > (*this)(Mr,Mc)) {
                    if (!(std::find(na.begin(), na.end(), (*this)(i,j)) != na.end())) {
                        Mr = i;
                        Mc = j;
                    }
                }
            }
        }

        return {Mr,Mc};
    }
    template <typename T>
    std::vector<size_t> Matrix<T>::absMaxPos(std::vector<T> na)
    {
        std::vector<size_t> null;
        if ((*this).rows() == 0) {return null;}

        size_t Mr=0;
        size_t Mc=0;

        for (size_t i=0; i<(*this).rows();i++) {
            for (size_t j=0; j<(*this).cols();j++) {
                if (std::abs((*this)(i,j)) > std::abs((*this)(Mr,Mc))) {
                    if (!(std::find(na.begin(), na.end(), (*this)(i,j)) != na.end())) {
                        Mr = i;
                        Mc = j;
                    }
                }
            }
        }

        return {Mr,Mc};
    }
    template <typename T>
    std::vector<size_t> Matrix<T>::minPos()
    {
        std::vector<size_t> null;
        if ((*this).rows() == 0) {return null;}

        size_t mr=0;
        size_t mc=0;

        for (size_t i=0; i<(*this).rows();i++) {
            for (size_t j=0; j<(*this).cols();j++) {
                if ((*this)(i,j) < (*this)(mr,mc)) {
                    mr = i;
                    mc = j;
                }
            }
        }

        return {mr,mc};
    }
    template <typename T>
    size_t Vector<T>::maxPos()
    {
        size_t null;
        if ((*this).dim() == 0) {return null;}

        size_t Mp=0;
        for (size_t i=0; i<(*this).dim(); i++) {
            if ((*this)(i) > (*this)(Mp)) {
                Mp = i;
            }
        }

        return Mp;
    }
    template <typename T>
    size_t Vector<T>::minPos()
    {
        size_t null;
        if ((*this).dim() == 0) {return null;}

        size_t mp=0;
        for (size_t i=0; i<(*this).dim(); i++) {
            if ((*this)(i) > (*this)(mp)) {
                mp = i;
            }
        }

        return mp;
    }
}
