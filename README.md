# Eigenkit C++ Library

Eigenkit is a Numerical Linear Algebra library for C++ programming language.
It offers a variety of methods for dense matrices, linear systems, eigenvalues and quaternions.
<div align="center">
  <img src="https://github.com/lorenzobunaj/eigenkit/blob/main/eigenkit-logo.svg" width="200"/>
</div>
</br>

This library it's still under development, but it's already possible to observe how the structure of the first completed version will be.
Many other important features, such as methods for sparse matrices, will be added with subsequent releases.

## Features

- Supports many [C++ Standard Numerics Library](https://en.cppreference.com/w/cpp/numeric) functions and types, like [complex](https://en.cppreference.com/w/cpp/numeric/complex).
- Compatible with any compiler
- Easily Extensible
- Open Source

## Requirements and Download

Eigenkit is compatible with any compiler and doesn't have any dependencies other than the [C++ Standard Library](https://en.cppreference.com/w/cpp/standard_library).  
So, if you want to use it, you can [download](https://eigenkit.org/docs/getting-started/download.html) the Eigenkit source's latest version and extract it. Once you've done that, you'll simply add the source code containing the header files to your project.

## Documentation

- [Getting Started](https://eigenkit.org/docs/getting-started/)
- [Matrix Class](https://eigenkit.org/docs/matrix-class/)
- [Dense Algebra](https://eigenkit.org/docs/dense-algebra/)
- [Dense Decompositions](https://eigenkit.org/docs/dense-decompositions/)
- [Dense Linear Algebra](https://eigenkit.org/docs/dense-linear-algebra/)
- [Quaternion Class](https://eigenkit.org/docs/quaternion-class/)

## Example of Usage

```cpp
#include <iostream>
#include <Eigenkit/Eigenkit.h>
                        
int main()
{
    ek::Matrix<int> mtx(2,2);
    mtx(0,0) = 1;
    std::cout << mtx(0,0);

    return 0;
}
```

Terminal:

```cpp
1
```

The basic class provided by Eigenkit library is the Matrix class, whose instances retain the properties of dense matrices.  
In the code above, we are initializing a 2x2 matrix whose elements are integers, assigning the value 1 to the element in position (0,0) and showing on terminal the matrix element in position (0,0), which we expect to be 1. 

## Contribute

To contribute, just do as follows:
1. Fork the Project
2. Create a new Feature Branch: `git checkout -b feature/YourFeature`
3. Commit the Changes: `git commit -m 'YourFeature main points'`
4. Push to the Branch `git push origin feature/YourFeature`
5. Open a Pull Request (discuss it)

## Authors and Contributors

This project is being developed by Lorenzo Bunaj
