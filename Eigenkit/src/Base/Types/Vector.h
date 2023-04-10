namespace ek {
    template <typename T, bool D=1>
    class Vector : public Matrix<T,0,D>
    {
    protected:
        std::vector<std::vector<T>>& getMatrix() {return Matrix<T,0,D>::getMatrix();}
        bool row = 1;

    public:
        Vector() : Matrix<T,0,D>(){};
        Vector(std::initializer_list<T> arr) : Matrix<T,0,D>({arr}){};

        void newSize(size_t s)
        {
            if (this->row) {
                Matrix<T,0,D>::newSize(1, s);
            } else {
                Matrix<T,0,D>::newSize(s, 1);
            }
        }

        T& operator () (size_t i)
        {
            if (this->row) {
                return Matrix<T,0,D>(0,i);
            } else {
                return Matrix<T,0,D>(i,0);
            }
        }
    };
}
