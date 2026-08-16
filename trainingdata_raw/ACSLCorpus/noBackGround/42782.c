#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (h) <= 100 && (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
*/
int64_t func(int64_t a, int64_t b, int64_t h)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= h <= 100;
    //@ assert h % 2 == 0;
    
    int64_t sum;
    int64_t prod;
    int64_t half;
    int64_t ans;
    int64_t temp;
    
    sum = a + b;
    
    //@ assert 1 <= (a + b) * h <= 20000;
    prod = sum * h;
    half = 2;
    ans = 0;
    temp = prod;
    
    /*@
        loop invariant 0 <= temp <= prod;
        loop invariant 0 <= ans <= prod / 2;
        loop invariant temp == prod - 2 * ans;
        loop assigns temp, ans;
        loop variant temp;
    */
    while (temp >= half) {
        //@ assert temp >= 2;
        temp -= half;
        ans += 1;
        //@ assert temp == prod - 2 * ans;
    }
    
    //@ assert ans == (((a) + (b)) * (h) / 2);
    return ans;
}
