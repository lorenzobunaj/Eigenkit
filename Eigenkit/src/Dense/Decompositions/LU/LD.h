namespace ek
{
    template <typename T>
    void LU<T>::LD()
    {
        // if LD or DU decompositions have been performed before, change them
        Identity<T> idl(A.rows());
        if (ld) {
            L = L*D;
            D = idl;
            ld = 0;
            return;
        } else if (du) {
            U = D*U;
            D = idl;
            du = 0;
        }

        for (size_t i=0; i<range(); i++) {
            // insert U's diagonal elements in D's diagonal
            D(i,i) = L(i,i);

            // divide U's elements by the diagonal ones
            for (size_t j=0; j<i+1; j++) {
                L(i,j) = L(i,j)/D(i,i);
            }
        }

        // mark LD decomposition as performed
        ld = 1;
    }
}
