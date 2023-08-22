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
            return sylvesterDef(M, "positive");
        }
        else if (method == "eigen")
        {
            return eigenDef(M, "positive");
        }

        throw std::invalid_argument("Invalid Method Name");
    }

    template<typename T>
    bool isNegDef(Matrix<T> M, std::string method)
    {
        if (method == "sylvester")
        {
            return sylvesterDef(M, "negative");
        }
        else if (method == "eigen")
        {
            return eigenDef(M, "negative");
        }

        throw std::invalid_argument("Invalid Method Name");
    }

    template<typename T>
    bool isSemiposDef(Matrix<T> M, std::string method)
    {
        if (method == "sylvester")
        {
            return sylvesterDef(M, "semipositive");
        }
        else if (method == "eigen")
        {
            return eigenDef(M, "semipositive");
        }

        throw std::invalid_argument("Invalid Method Name");
    }

    template<typename T>
    bool isSeminegDef(Matrix<T> M, std::string method)
    {
        if (method == "sylvester")
        {
            return sylvesterDef(M, "seminegative");
        }
        else if (method == "eigen")
        {
            return eigenDef(M, "seminegative");
        }

        throw std::invalid_argument("Invalid Method Name");
    }

    template<typename T>
    bool sylvesterDef(Matrix<T> M, std::string type)
    {
        if (type == "positive")
        {
            for (size_t i=1; i<M.rows()-1; i++)
            {
                if (M.sub(0,0,M.rows()-i,M.cols()-i).det() <= 0)
                {
                    return 0;
                }
            }
            return 1;
        }
        else if (type == "negative")
        {
            for (size_t i=1; i<M.rows()-1; i++)
            {
                if (std::pow(-1,i+1)*M.sub(0,0,M.rows()-i,M.cols()-i).det() <= 0)
                {
                    return 0;
                }
            }
            return 1;
        }
        else if (type == "semipositive")
        {
            for (size_t i=1; i<M.rows(); i++)
            {
                for (size_t j=i; j<M.rows(); j++)
                {
                    if (M.sub(j-i,j-i,j,j).det() <= 0)
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
        else if (type == "seminegative")
        {
            for (size_t i=1; i<M.rows(); i++)
            {
                for (size_t j=i; j<M.rows(); j++)
                {
                    if (std::pow(-1,i+1)*M.sub(j-i,j-i,j,j).det() <= 0)
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }

        throw std::invalid_argument("Invalid Type Name");
    }

    template<typename T>
    bool eigenDef(Matrix<T> M, std::string type)
    {
        return 1;
    }
}
