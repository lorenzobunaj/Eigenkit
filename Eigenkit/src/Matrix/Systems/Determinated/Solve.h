namespace ek
{
    template <typename T>
    Vector<T> autoDec(Matrix<T> A, Vector<T> a)
    {
        Vector<T> out;

        if ((A == A.h()))
        {
            Cholesky<T> clDec(A);
            clDec.LL();

            out = clDec.solve(a);
        }
        else if (A.rows() == A.cols())
        {
            LU<T> luDec(A);
            luDec.PP();

            out = luDec.solve(a);
        }
        else if (A.rows() != A.cols())
        {
            QR<T> qrDec(A);
            qrDec.CP();

            out = qrDec.solve(a);
        }

        return out;
    }

    template <typename T>
    Vector<T> solve(Matrix<T> A, Vector<T> a, std::string decName = "", std::string decType = "")
    {
        Vector<T> out;

        if ((decName=="") || (decType==""))
        {
            out = autoDec(A,a);
        }
        else if (decName == "lu")
        {
            LU<T> luDec(A);

            if (decType == "gauss")
            {
                luDec.Gauss();
            }
            else if (decType == "pp")
            {
                luDec.PP();
            }
            else if (decType == "fp")
            {
                luDec.FP();
            }
            else
            {
                throw std::invalid_argument("Invalid Decomposition Type");
            }
            out = luDec.solve(a);
        }
        else if (decName == "qr")
        {
            QR<T> qrDec(A);

            if (decType == "householder")
            {
                qrDec.Householder();
            }
            else if (decType == "cp")
            {
                qrDec.CP();
            }
            else if (decType == "givens")
            {
                qrDec.Givens();
            }
            else if (decType == "gram")
            {
                qrDec.Gram();
            }
            else
            {
                throw std::invalid_argument("Invalid Decomposition Type");
            }
            out = qrDec.solve(a);
        }
        else if (decName == "cholesky")
        {
            Cholesky<T> clDec(A);

            if (decType == "ll")
            {
                clDec.LL();
            }
            else if (decType == "ldl")
            {
                clDec.LDL();
            }
            else
            {
                throw std::invalid_argument("Invalid Decomposition Type");
            }
            out = clDec.solve(a);
        }
        else
        {
            throw std::invalid_argument("Invalid Decomposition Name");
        }

        return out;
    }
}
