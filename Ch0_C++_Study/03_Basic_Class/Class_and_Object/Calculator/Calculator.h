class Calculator
{
    private:
        int add_num;
        int min_num;
        int mul_num;
        int div_num;
    public:
        inline void Init() {
            add_num = 0;
            min_num = 0;
            mul_num = 0;
            div_num = 0;
        }

        double Add(double d1, double d2);
        double Min(double d1, double d2);
        double Mul(double d1, double d2);
        double Div(double d1, double d2);

        void ShowOpCount();
};