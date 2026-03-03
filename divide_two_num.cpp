 #include<iostream>
 #include<climits>
 using namespace std;
 int divide(int dividend, int divisor) {
    //     if(dividend==INT_MIN && divisor<1)
    //     {
    //         return INT_MAX;
    //     }
    //     long long a=llabs((long long)dividend);
    //     long long b=llabs((long long)divisor);
    //     int result=0;
    //     while(a>=b)
    //     {
    //       long long temp=b;
    //       int multiple=1;
    //       while((temp<<1)<=a)
    //       {
    //         temp<<=1;
    //         multiple<<=1;
    //       }
    //       a-=temp;
    //       result+=multiple;
    //     }

    //     if ((dividend < 0) ^ (divisor < 0))
    //      result = -result;

    // return result;

    // Handle division by zero
    if (divisor == 0)
        return INT_MAX;

    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine sign of result
    bool negative = (dividend < 0) ^ (divisor < 0);

    // Convert to long long BEFORE taking absolute value
    long long a = (long long)dividend;
    long long b = (long long)divisor;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    long long result = 0;

    while (a >= b) {

        long long temp = b;
        long long multiple = 1;

        // Shift divisor until it exceeds dividend
        while ((temp << 1) <= a) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        result += multiple;
    }

    if (negative)
        result = -result;

    return (int)result;
    }
int main()
{
    int dividend=10,divisor=2;
    cout<<divide(dividend,divisor);
}