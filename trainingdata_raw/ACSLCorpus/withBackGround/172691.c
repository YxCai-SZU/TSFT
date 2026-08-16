#include <stdbool.h>
/*@
    predicate valid_array(integer n, int *arr) =
        n >= 1 && n <= 1000000 &&
        \valid(arr + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 10;

    logic integer remainder(integer num) =
        num >= 2 ? num % 2 : num;

    lemma remainder_range:
        \forall integer num; num >= 1 && num <= 10 ==> remainder(num) >= 0 && remainder(num) <= 1;
*/

/*@
    requires valid_array(n, arr);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *arr) {
    int cnt = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant cnt >= 0;
        loop invariant cnt <= i;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= 1 && arr[k] <= 10;
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n) {
        int num = arr[i];
        int rem;
        if (num >= 2) {
            int temp = num;
            /*@
                loop invariant temp >= 0 && temp <= num;
                loop invariant temp % 2 == num % 2;
                loop assigns temp;
                loop variant temp;
            */
            while (temp >= 2) {
                temp -= 2;
            }
            rem = temp;
        } else {
            rem = num;
        }
        //@ assert rem == remainder(num);
        if (rem == 0) {
            cnt += 1;
        }
        i += 1;
    }
    return cnt;
}
