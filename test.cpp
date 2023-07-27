#include "Eigenkit/Eigenkit.h"

int main()
{
    ek::Matrix<double> m1 =
    {
      {4,10,8},
      {10,26,26},
      {8,26,61}
    };
    ek::Vector<double> b1 = {44,128,214};

    ek::Cholesky<double> d1(m1);
    d1.LL();
    ek::Vector<double> x1 = d1.solve(b1);

    std::cout << x1 << std::endl;

    return 0;
}
