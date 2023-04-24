namespace ek
{
    template <typename T>
    struct Matrix<T>::Iterator
    {
        // iterator category
        using iterator_category = std::forward_iterator_tag;

    private:
        T* T_ptr;
        size_t r_pos = 0;
        size_t c_pos = 0;
        std::vector<std::vector<T>>* matrix;

    public:
        // constructor
        Iterator(T* ptr, std::vector<std::vector<T>>* mtx) : T_ptr(ptr) {matrix = mtx;}
        // access to rvalue and lvalue
        T* operator -> () {return T_ptr;}
        T& operator * () const {return *T_ptr;}
        // prefix increment
        Iterator& operator ++ ()
        {
            c_pos++;
            if (c_pos == (*matrix)[0].size() && r_pos+1 < (*matrix).size()) {
                c_pos = 0;
                r_pos++;
                T_ptr = &((*matrix)[r_pos][c_pos]);
            } else {
                T_ptr++;
            }

            return *this;
        }
        // postfix increment
        Iterator operator ++ (int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        // equality operators
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.T_ptr == b.T_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.T_ptr != b.T_ptr; };

    };
}
