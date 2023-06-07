namespace ek
{
    template <typename T>
    class ColPivot : public Transformation<T>
    {
    private:
        Matrix<T> indSwap (Matrix<T> mtx, size_t i, size_t j)
        {
            T temp = mtx(1,i);
            mtx(1,i) = mtx(1,j);
            mtx(1,j) = temp;

            return mtx;
        }

        std::vector<std::vector<T>> colpivize(Matrix<T> A, Matrix<T> indices)
        {
            std::vector<std::vector<T>> out;
            std::vector<std::vector<T>> error = {{-1}};

            size_t sc=0;
            T norm=0;
            for (size_t j=1;j<A.cols();j++) {
                Vector<T> v;
                v = A.col(j);
                if (v.norm(2) == 0) {
                    throw std::invalid_argument("Invalid Arguments");
                }
                else if (v.norm(2) > norm) {
                    norm = v.norm(2);
                    sc = j;
                }
            }

            Permutation<T> P(indSwap(indices,sc,0));
            out = P.mtx();

            return out;
        }
    public:
        // special constructor
        ColPivot(Matrix<T> mtx, Matrix<T> indices) : Transformation<T>(colpivize(mtx, indices)){};
    };
}
