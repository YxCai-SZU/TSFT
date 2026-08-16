#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
*/
int64_t func(int64_t a, int64_t b, int64_t h)
{
    // Variable declarations at scope top
    int64_t sum;
    int64_t product;
    int64_t ans;
    int64_t count;
    int64_t temp;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (h) <= 100 &&         (h) % 2 == 0);
    
    sum = a + b;
    //@ assert 1 <= a + b <= 200;
    
    product = sum * h;
    //@ assert 1 <= product <= 20000;
    
    ans = 0;
    count = 0;
    temp = product;

    /*@ loop invariant
            0 <= count <= product / 2 &&
            temp + 2 * count == product;
        loop assigns
            temp, count;
        loop variant
            temp;
    */
    while (temp >= 2) {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
        //@ assert temp + 2 * count == product;
    }

    ans = count;
    //@ assert ans == (a + b) * h / 2;
    
    return ans;
}
