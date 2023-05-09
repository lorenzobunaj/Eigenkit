namespace ek
{
    template <typename T>
    class Householder : public Transformation<T>
    {
    private:
        Matrix<T> householderize(Vector<T> vec)
        {
            Identity<T> id(vec.dim());
            Matrix<T> out = id - (T)2*(vec.t()*vec)/(vec*vec.t())(0,0);

            return out;
        }
    public:
        // special constructor
        Householder(Vector<T> vec) : Transformation<T>(householderize(vec).mtx()){};
    };
}
