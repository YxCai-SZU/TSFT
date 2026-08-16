#include <stdbool.h>

/*@
  requires 1 <= a && a <= 100;
  requires 1 <= b && b <= 100;
  requires 1 <= c && c <= 100;
  ensures \result == true <==> (((a + b + c) % 2) == 0);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long sum;
    unsigned long long half;
    bool result;

    sum = a + b + c;
    
    //@ assert sum >= 3 && sum <= 300;
    
    half = sum / 2;
    
    //@ assert sum - 2 * half == 0 <==> (((sum) % 2) == 0);
    
    result = (sum - 2 * half) == 0;
    return result;
}
