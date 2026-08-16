#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
    (x) >= 1 && (x) <= 10000 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n + 1;
*/
long func(long n, long x, long *numbers) {
    long ans = 1;
    long sum = 0;
    long index = 0;
    
    /*@ loop invariant ((index) >= 0 && (index) <= (n) &&
    (n) >= 1 && (n) <= 100 &&
    (x) >= 1 && (x) <= 10000 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100 &&
    (sum) >= 0 &&
    (ans) >= 1 &&
    (ans) <= (index) + 1 &&
    (index) <= (n));
        loop assigns ans, sum, index;
        loop variant n - index;
    */
    while (sum <= x && index < n) {
        //@ assert index >= 0 && index < n;
        sum += numbers[index];
        index++;
        if (sum <= x) {
            ans++;
        }
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n + 1;
    return ans;
}
