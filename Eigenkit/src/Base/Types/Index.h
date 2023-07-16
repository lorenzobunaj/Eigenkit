namespace ek {
    template <typename T>
    class Index : public Matrix<T>
    {
    private:
        std::vector<std::vector<T>> index(T d)
        {
            std::vector<std::vector<T>> out;

            out.resize(2);
            out[0].resize(d);
            out[1].resize(d);

            for (size_t i=0; i<d; i++) {
                out[0][i] = i+1;
                out[1][i] = i+1;
            }

            return out;
        }

    public:
        Index(size_t d)
        : Matrix<T>(index(d)){}
    };
}
