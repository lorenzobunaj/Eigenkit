namespace ek
{
    // find the Lp norm of a vector
    template <typename T>
    T Vector<T>::norm(T p)
    {
        T np=0;
        for (auto it=(*this).begin(); it!=(*this).end(); it++) {
            np += std::pow(*it,p);
        }

        return std::pow(np,1/p);
    }
}

