#include <stdint.h>

/*@ requires (-1000 <= (x) <= 1000);
    ensures \result == ((x) * (x));
    assigns \nothing;
 */
int32_t square(int32_t x)
{
    //@ assert (-1000 <= (x) <= 1000);
    //@ assert -1000000 <= ((x) * (x)) <= 1000000;
    return x * x;
}

/*@ requires sum == ((a) * (a)) + ((b) * (b));
    requires (-1000 <= (a) <= 1000);
    requires (-1000 <= (b) <= 1000);
    assigns \nothing;
 */
void print_sum_of_squares(int32_t a, int32_t b, int32_t sum)
{
    //@ assert -2000000 <= sum <= 2000000;
}

/*@ assigns \nothing;
 */
int main()
{
    int32_t a;
    int32_t b;
    int32_t sum;
    int32_t tmp1;
    int32_t tmp2;
    
    a = 20;
    b = 30;
    //@ assert (-1000 <= (a) <= 1000);
    //@ assert (-1000 <= (b) <= 1000);
    
    tmp1 = square(a);
    //@ assert tmp1 == ((a) * (a));
    
    tmp2 = square(b);
    //@ assert tmp2 == ((b) * (b));
    
    sum = tmp1 + tmp2;
    //@ assert sum == ((a) * (a)) + ((b) * (b));
    
    print_sum_of_squares(a, b, sum);
    return 0;
}
