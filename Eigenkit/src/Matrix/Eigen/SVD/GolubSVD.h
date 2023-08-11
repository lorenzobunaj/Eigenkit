namespace ek
{
    template <typename T>
    void SVD<T>::Golub()
    {
        UBV<T> UBV(A);
        UBV.GolubKahan();
        U = UBV.U;
        S = UBV.B;
        V = UBV.V.h();

        QR<T> QR(S);
        QR.Givens();
        U = U * QR.Q.t();
        S = QR.Q * S * QR.Q.t();
        V = QR.Q * V;
    }
}
