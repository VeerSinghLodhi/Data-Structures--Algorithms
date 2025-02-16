#include<iostream>
using namespace std;
template<class t1,class t2>
class SumTwoNumber{
    t1 num1;
    t2 num2;
public:
    void setSum(t1 num1,t2 num2)
    {
        this->num1=num1;
        this->num2=num2;
    }
    void getSum()
    {
        t2 sum;
        sum=num1+num2;
        cout<<"\nSum is "<<sum;
    }
};
int main()
{
    // Sum of Integer and Integer
    SumTwoNumber<int,int>s1;
    s1.setSum(20,30);
    s1.getSum();

    //Sum of Integer and float with the same methods setSum and getSum
    SumTwoNumber<int,float>s2;
    s2.setSum(20,30.5);
    s2.getSum();

    //Sum of float and float with the same methods setSum and getSum
    SumTwoNumber<float,float>s3;
    s3.setSum(20.2,30.5);
    s3.getSum();

    //Sum of double and double with the same methods setSum and getSum
    SumTwoNumber<float,float>s4;
    s4.setSum(20.012,30.05);
    s4.getSum();

    return 0;
}
