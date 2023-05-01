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

            std::vector<std::vector<T>> arr = mtx.mtx();

            out.resize(mtx.rows());

            for (size_t i=0; i<mtx.rows(); i++) {
                out.resize(mtx.cols());
                Vector<T> op1 = arr[i];
                Vector<T> res = op1;

                for (size_t j=0; j<i; j++) {
                    Vector<T> temp = arr[j];
                    res = res - op1.proj(temp);
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
