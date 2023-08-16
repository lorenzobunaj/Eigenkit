#include "Eigenkit/Eigenkit.h"

int main()
{
    ek::Matrix<double> m1 =
    {
        {0.8595, 0.7176, 0.9781, 0.8116, 0.2164},
        {0.8886, 0.05399,   0.2921,    0.7058,    0.1801},
        {0.8149, 0.367,     0.04329,   0.5527,    0.7479},
        {0.7431,    0.9701,    0.9428,    0.5411,    0.0009715},
        {0.8033,    0.8404,    0.9647,    0.9118,    0.8811},
        {0.05875,   0.4113,    0.03543,   0.1149,    0.8648},
        {0.7246,    0.3075,    0.4898,    0.8406,    0.5857},
        {0.538,    0.5798,    0.4514,   0.6041,    0.01276},
        {0.7342,    0.001529,  0.2108,    0.426,     0.5745},
        {0.6983,    0.7891,    0.4445,    0.2376,    0.1985}
    };

    ek::Matrix<double> m2 = {
        {1,0,0,0,2},
        {0,0,3,0,0},
        {0,0,0,0,0},
        {0,4,0,0,0}
    };

    ek::Matrix<double> m3 = {
        {3, 2, 2},
        {2, 3, -2}
    };

    ek::Matrix<double> m4 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    ek::Matrix<double> m5 = {
        {1, 1, 1},
        {4, 3, -1},
        {3, 5, 3}
    };

    ek::Matrix<double> m6 = {
        {2, 1, -5},
        {1, 7, 4},
        {-5, 4, 19}
    };

    ek::Matrix<double> m7 = {
        {2, 1, 0, 1},
        {1, 3, 0, 1},
        {0, 0, 0, 0},
        {1, 1, 0, 1}
    };

    ek::Matrix<double> m8 = {
        {3, 2, 0},
        {-1, 0, 0},
        {0, 0, 1}
    };

    /*
    ek::Vector<double> v1 = {1, 6, 4};
    v1 = v1.t();

    ek::UBV<double> hs1(m4);
    hs1.Householder();

    std::cout << hs1.U << std::endl;
    std::cout << "..." << std::endl;
    std::cout << hs1.B << std::endl;
    std::cout << "..." << std::endl;
    std::cout << hs1.V << std::endl;
    std::cout << "..." << std::endl;
    std::cout << hs1.U*hs1.B*(hs1.V.t()) << std::endl;
    */

    bool check = ek::isPosDef(m8, "sylvester");

    std::cout << check << std::endl;


    return 0;
}
