#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * (3141592)) / (1000000));
*/
int64_t func(int64_t r) {
    int64_t pi;
    int64_t ans;
    int64_t temp;
    int64_t count;
    int64_t divisor;
    
    pi = 3141592;
    ans = 0;
    temp = 2 * r * pi;
    count = 0;
    divisor = 1000000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == (3141592);
        loop invariant (1000000)== 1000000;
        loop invariant temp >= 0;
        loop invariant count * (1000000)+ temp == 2 * r * pi;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        count += 1;
    }
    ans = count;
    
    //@ assert ans == ((2 * (r) * (3141592)) / (1000000));
    return ans;
}

int main() {
    return 0;
}
