namespace ek
{
    template <typename T>
    class Identity : public Permutation<T>
    {
    private:
        // input:= size
        // output:= 2xsize matrix where a(0,j) = a(1,j) = j+1
        Matrix<T> Id(size_t s)
        {
            Matrix<T> mtx(2,s);

            for (size_t i=0; i<s; i++) {
                mtx(0,i) = i+1;
                mtx(1,i) = i+1;
            }

            return mtx;
        }

    public:
        // special constructor
        Identity(size_t s) : Permutation<T>(Id(s)){};
    };
}
