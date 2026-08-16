#include <stdint.h>

/*@
  requires (1 <= (r) <= 100);
  ensures \result == ((2 * 31415 * (r)) / 10000);
  assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t circumference;
    int64_t temp;
    int64_t divisor;
    
    pi_approx = 31415;
    circumference = 0;
    temp = 2 * pi_approx * r;
    divisor = 10000;
    
    /*@
      loop invariant 1 <= r <= 100;
      loop invariant pi_approx == 31415;
      loop invariant divisor == 10000;
      loop invariant temp >= 0;
      loop invariant circumference * 10000 + temp == 2 * pi_approx * r;
      loop assigns temp, circumference;
      loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference == ((2 * 31415 * (r)) / 10000);
    return circumference;
}

/*@ assigns \nothing; */
int main()
{
    return 0;
}
