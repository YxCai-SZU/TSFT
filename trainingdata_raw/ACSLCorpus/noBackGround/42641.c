#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n && n <= 100;
    requires 1 <= x && x <= 10000;
    requires \valid(numbers + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    ensures \result >= 0 && \result <= n + 1;
    assigns \nothing;
*/
long func(long n, long x, long *numbers) {
    long ans = 0;
    long sum = 0;
    size_t index = 0;

    /*@ loop invariant ((index) >= 0 && (index) <= (size_t)(n) &&
      (sum) >= 0 && (sum) <= (x) + 100 &&
      (ans) >= 0 && (ans) <= (long)(index) && (long)(index) <= (n) + 1 &&
      ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100) &&
      (((n)) >= 1 && ((n)) <= 100 &&
      \forall integer i; 0 <= i < ((n)) ==> ((numbers))[i] >= 1 && ((numbers))[i] <= 100));
        loop assigns ans, sum, index;
        loop variant n - (long)index;
    */
    while (index < (size_t)n && sum <= x) {
        //@ assert index >= 0 && index < (size_t)n;
        sum += numbers[index];
        ans += 1;
        index += 1;
        //@ assert ans >= 0 && ans <= (long)index && (long)index <= n + 1;
    }

    //@ assert ans >= 0 && ans <= n + 1;
    return ans;
}
