namespace ek
{
    template<typename T>
    std::string sylvesterDef(Matrix<T>);

    template<typename T>
    std::string eigenDef(Matrix<T>);

    template<typename T>
    bool isPosDef(Matrix<T> M, std::string method)
    {
        if (method == "sylvester")
        {
            return (sylvesterDef(M) == "positive");
        }
        else if (method == "eigen")
        {
            return (eigenDef(M) == "positive");
        }

        throw std::invalid_argument("Invalid Method Name");
    }
    template<typename T>
    bool isSemiposDef(Matrix<T> M, std::string method)
    {
        if (method == "sylvester")
        {
            return (sylvesterDef(M) == "semipositive");
        }
        else if (method == "eigen")
        {
            return (eigenDef(M) == "semipositive");
        }

        throw std::invalid_argument("Invalid Method Name");
    }

    template<typename T>
    std::string sylvesterDef(Matrix<T> M)
    {
        bool semi = 0;
        std::string car = "";

        T minor = M.det();
        if (minor > 0)
        {
            car = "positive";
        }
        else if (minor < 0)
        {
            car = "negative";
        }

        T prod;

        for (size_t i=1; i<M.rows()-1; i++)
        {
            prod = minor * M.sub(0,0,M.rows()-i-1,M.cols()-i-1).det();
            if (prod < 0)
            {
                return "indefinite";
            }
            else if (prod == 0 )
            {
                if (minor == 0) {minor = M.sub(0,0,M.rows()-i-1,M.cols()-i-1).det();}
                semi = 1;
            }
            else if (prod > 0)
            {
                minor = M.sub(0,0,M.rows()-i-1,M.cols()-i-1).det();
                if (minor > 0) {car = "positive";}
                else if (minor < 0) {car = "negative";}
            }
        }

        if (car == "")
        {
            return "indefinite";
        }

        if (semi)
        {
            car = "semi"+car;
            return car;
        }
        else
        {
            return car;
        }
    }

    template<typename T>
    std::string eigenDef(Matrix<T> M)
    {
        return "";
    }
}
