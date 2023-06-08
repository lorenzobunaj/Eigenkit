namespace ek
{
    template <typename T>
    class Givens : public Transformation<T>
    {
    private:
        std::vector<std::vector<T>> givensize(size_t d, size_t p1, size_t p2, T c, T s)
        {
            Identity<T> id(d);
            std::vector<std::vector<T>> arr = id.mtx();

            /*arr.resize(r);
            size_t i=0;
            for (auto r = arr.begin(); r != arr.end(); r++) {
                (*r).resize(c);
                (*r)[i++] = 1;
            }*/
            arr[p1][p1] = c;
            arr[p2][p2] = c;
            arr[p1][p2] = -s;
            arr[p2][p1] = s;

            return arr;
        }
    public:
        // special constructor
        Givens(size_t d, size_t p1, size_t p2, T c, T s) : Transformation<T>(givensize(d,p1,p2,c,s)){};
    };
}
