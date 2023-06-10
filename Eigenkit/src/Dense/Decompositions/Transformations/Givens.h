namespace ek
{
    template <typename T>
    class Givens : public Transformation<T>
    {
    private:
        // converts the constructor inputs to an array
        std::vector<std::vector<T>> givensize(size_t d, size_t p1, size_t p2, T c, T s)
        {
            // initialize array out : out(i,j) = i==j ? 1 : 0
            Identity<T> id(d);
            std::vector<std::vector<T>> out = id.mtx();
            // insert cos and sin values
            out[p1][p1] = c;
            out[p2][p2] = c;
            out[p1][p2] = -s;
            out[p2][p1] = s;

            return out;
        }
    public:
        // special constructor
        Givens(size_t d, size_t p1, size_t p2, T c, T s) : Transformation<T>(givensize(d,p1,p2,c,s)){};
    };
}
