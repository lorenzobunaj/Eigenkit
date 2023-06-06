namespace ek
{
    template <typename T>
    class Householder : public Transformation<T>
    {
    private:
        Matrix<T> householderize(Vector<T> vec)
        {
            Identity<T> id(vec.dim());
            Matrix<T> out = id - ((vec*(vec.t()))/(vec.dot(vec))*2);

            return out;
        }
    public:
        // special constructor
        Householder(Vector<T> vec) : Transformation<T>(householderize(vec).mtx()){};
    };
}
