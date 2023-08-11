namespace ek
{
    template <typename T>
    void LU<T>::DU()
    {
        // if LD or DU decompositions have been performed before, change them
        Identity<T> idl(A.rows());
        if (ld) {
            L = L*D;
            D = idl;
            ld = 0;
        } else if (du) {
            U = D*U;
            D = idl;
            du = 0;
            return;
        }

        for (size_t i=0; i<range(); i++) {
            // insert U's diagonal elements in D's diagonal
            D(i,i) = U(i,i);

            // divide U's elements by the diagonal ones
            for (size_t j=i; j<U.rows(); j++) {
                U(i,j) = U(i,j)/D(i,i);
            }
        }

        // mark DU decomposition as performed
        du = 1;
    }
}
