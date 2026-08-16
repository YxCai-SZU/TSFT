#include <stdbool.h>
#include <limits.h>

/*@
    requires ((n) >= 2 && (n) <= 50 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer k; 0 <= k < (n) ==> 0 <= (numbers)[k] && (numbers)[k] <= 100);
    ensures \result >= 0;
    ensures \result <= 100000;
    assigns \nothing;
*/
long func(long n, const int *numbers) {
    long ans = 100000;
    long i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((n) >= 2 && (n) <= 50 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer k; 0 <= k < (n) ==> 0 <= (numbers)[k] && (numbers)[k] <= 100);
        loop invariant ((ans) >= 0 && (ans) <= 100000);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        long num1 = numbers[i];
        long j = i + 1;
        
        /*@
            loop invariant i < n;
            loop invariant i + 1 <= j <= n;
            loop invariant ((n) >= 2 && (n) <= 50 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer k; 0 <= k < (n) ==> 0 <= (numbers)[k] && (numbers)[k] <= 100);
            loop invariant ((ans) >= 0 && (ans) <= 100000);
            loop invariant num1 >= 0 && num1 <= 100;
            loop assigns ans, j;
            loop variant n - j;
        */
        while (j < n) {
            long num2 = numbers[j];
            long sum = num1 + num2;
            long x = sum < 0 ? -sum : sum;
            
            //@ assert x >= 0;
            
            if (x < ans) {
                ans = x;
            }
            
            //@ assert ((ans) >= 0 && (ans) <= 100000);
            j++;
        }
        i++;
    }
    return ans;
}
