namespace ek
{
    template <typename T>
    class Jacobi : public Transformation<T>
    {
    private:
        std::vector<std::vector<T>> jacobize(size_t s, size_t ir, size_t ic, T a)
        {
            std::vector<std::vector<T>> arr;

            arr.resize(s);
            size_t i=0;
            for (auto r = arr.begin(); r != arr.end(); r++) {
                (*r).resize(s);
                (*r)[i++] = 1;
            }
            arr[ir][ir] = std::cos(a);
            arr[ic][ic] = std::cos(a);
            arr[ir][ic] = std::sin(a);
            arr[ic][ir] = -std::sin(a);

            return arr;
        }
    public:
        // special constructor
        Jacobi(size_t s, size_t ir, size_t ic, T a) : Transformation<T>(jacobize(s,ir,ic,a)){};
    };
}
