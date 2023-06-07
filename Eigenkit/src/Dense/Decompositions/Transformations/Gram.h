namespace ek
{
    template <typename T>
    class Gram : public Transformation<T>
    {
    private:
        std::vector<std::vector<T>> gramize(Matrix<T> mtx)
        {
            std::vector<std::vector<T>> out;
            if (mtx.rows() == 0) {return out;}

            std::vector<std::vector<T>> arr = mtx.t().mtx();

            out.resize(mtx.cols());

            for (size_t i=0; i<mtx.cols(); i++) {
                out[i].resize(mtx.rows());

                Vector<T> a = arr[i];
                Vector<T> res = a;

                for (size_t j=0; j<i; j++) {
                    Vector<T> u = out[j];
                    Vector<T> e;
                    e = u/u.norm(2);
                    res = res - e*(a.dot(e));
                }

                out[i] = res.mtx()[0];
            }

            return out;
        }
    public:
        // special constructor
        Gram(Matrix<T> mtx) : Transformation<T>(gramize(mtx)){};
    };
}
