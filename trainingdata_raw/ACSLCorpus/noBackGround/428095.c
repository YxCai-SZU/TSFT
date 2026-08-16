#include <stdint.h>

/*@
    requires 1 <= k <= n <= 50;
    ensures \result == n - k + 1;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int k)
{
    unsigned int res;
    //@ assert 1 <= k <= n <= 50;
    res = n - k + 1;
    //@ assert res == n - k + 1;
    return res;
}

/*@
    requires 1 <= a <= 10 && 1 <= b <= 10 && 1 <= c <= 10 && 1 <= d <= 10;
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func2(int a, int b, int c, int d)
{
    int max;
    int min;
    int res;
    
    //@ assert 1 <= a <= 10 && 1 <= b <= 10 && 1 <= c <= 10 && 1 <= d <= 10;
    
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    //@ assert max == (((a) > (b)) ? (a) : (b));
    
    if (c < d) {
        min = c;
    } else {
        min = d;
    }
    //@ assert min == (((c) < (d)) ? (c) : (d));
    
    if (max - min < 0) {
        res = 0;
    } else {
        res = max - min;
    }
    //@ assert res >= 0;
    //@ assert res <= a + b + c + d;
    
    return res;
}
