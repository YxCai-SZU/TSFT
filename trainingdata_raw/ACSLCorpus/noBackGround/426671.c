#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 1000000);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int count = 0;
    int i = 0;
    /*@ loop invariant (0 <= (i) && (i) <= (n) &&
      0 <= (count) && (count) <= (i) &&
      (((n)) >= 1 && ((n)) <= 200000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer k; 0 <= k < ((n)) ==> ((a))[k] >= 1 && ((a))[k] <= 1000000));
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int num = a[i];
        bool divisible = false;
        int j = 0;
        /*@ loop invariant (0 <= (j) && (j) <= (i) &&
      (((n)) >= 1 && ((n)) <= 200000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer k; 0 <= k < ((n)) ==> ((a))[k] >= 1 && ((a))[k] <= 1000000));
            loop assigns j, divisible;
            loop variant i - j;
        */
        while (j < i) {
            int divisor = a[j];
            if (divisor != num) {
                int remainder = num;
                /*@ loop invariant ((remainder) >= 0 &&
      (remainder) <= (num) &&
      (((n)) >= 1 && ((n)) <= 200000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer k; 0 <= k < ((n)) ==> ((a))[k] >= 1 && ((a))[k] <= 1000000));
                    loop assigns remainder;
                    loop variant remainder;
                */
                while (remainder >= divisor) {
                    remainder -= divisor;
                }
                if (remainder == 0) {
                    divisible = true;
                }
            }
            j++;
        }
        if (!divisible) {
            count++;
        }
        i++;
    }
    //@ assert count <= n;
    return count;
}
