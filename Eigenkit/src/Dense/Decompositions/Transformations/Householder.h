namespace ek
{
    template <typename T>
    class Householder : public Transformation<T>
    {
    private:
        std::vector<std::vector<T>> householderize(Vector<T> v)
        {
            // let out = id - v*v.t/(2*v.dot(v))
            Identity<T> id(v.dim());
            Matrix<T> out = id - (v*(v.t())/(v.dot(v))*2);

            return out.mtx();
        }
    public:
        // special constructor
        Householder(Vector<T> v) : Transformation<T>(householderize(v)){};
    };
}
