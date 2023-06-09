namespace ek
{
    // standard constructor
    template <typename T>
    Matrix<T>::Matrix()
    {
        nr = 0;
        nc = 0;
    }
    // given rows and cols number
    template <typename T>
    Matrix<T>::Matrix(size_t r, size_t c)
    {
        matrix.resize(r);
        for (auto r = matrix.begin(); r != matrix.end(); r++) {
            (*r).resize(c);
        }

        nr = r;
        nc = c;
    }
    // given an std::initializer_list array
    template <typename T>
    Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> arr)
    {
        for (auto r = arr.begin(); r != arr.end(); r++) {
            if ((*r).size() != (*(arr.begin())).size()) {
                throw std::invalid_argument("Invalid Array");
            }
        }

        matrix.reserve(arr.size());
        for (auto r = arr.begin(); r != arr.end(); r++) {
            matrix.insert(matrix.cend(), *r);
        }

        nr = arr.size();
        nc = (*(arr.begin())).size();
    }
    // given an std::vector array
    template <typename T>
    Matrix<T>::Matrix(std::vector<std::vector<T>> arr)
    {
        for (auto r=arr.begin(); r != arr.end(); r++) {
            if ((*r).size() != (*(arr.begin())).size()) {
                throw std::invalid_argument("Invalid Array");
            }
        }

        matrix = arr;

        nr = arr.size();
        nc = (*(arr.begin())).size();
    }
}
