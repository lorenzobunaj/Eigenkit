 namespace ek
{
    template <typename T>
    class Gram : public Matrix<T> //: public Transformation<T>
    {
    private:
        // converts the constructor inputs to an array
        std::vector<std::vector<T>> gramize(Matrix<T> A)
        {
            std::vector<std::vector<T>> out;
            out.resize(A.cols());
            // find the A.t() associated array
            std::vector<std::vector<T>> arr = A.t().mtx();

            for (size_t i=0; i<A.cols(); i++) {
                out[i].resize(A.rows());
                // let a = i-th A's column
                Vector<T> a = arr[i];
                Vector<T> r = a;
                // scroll through the previous r out(j);
                for (size_t j=0; j<i; j++) {
                    // let u = out(j) and e = u/||u||
                    Vector<T> u = out[j];
                    Vector<T> e;
                    e = u/(u.norm(2));
                    // r = a - e(0)*(a.dot(e(0))) - ... - e(i-1)*(a.dot(e(i-1)))
                    r = r - e*(a.dot(e));
                }
                // out(i) = r
                out[i] = r.mtx()[0];
            }

            return out;
        }
    public:
        // special constructor
        Gram(Matrix<T> mtx) : Matrix<T>(gramize(mtx)){};
    };
}
