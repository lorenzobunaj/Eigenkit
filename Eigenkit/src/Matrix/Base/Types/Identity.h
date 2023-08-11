namespace ek
{
    template <typename T>
    class Identity : public Squared<T>
    {
    private:
        // input:= size
        // output:= 2xsize matrix where a(0,j) = a(1,j) = j+1
        std::vector<std::vector<T>> Id(size_t s)
        {
            /*
            Matrix<T> mtx(2,s);

            for (size_t i=0; i<s; i++) {
                mtx(0,i) = i+1;
                mtx(1,i) = i+1;
            }
            */

            Matrix<T> out(s,s);
            for (size_t i=0; i<s; i++) {out(i,i) = (T)1;}

            return out.mtx();
        }

    public:
        // special constructor
        Identity(size_t s) : Squared<T>(Id(s)){};
    };
}
