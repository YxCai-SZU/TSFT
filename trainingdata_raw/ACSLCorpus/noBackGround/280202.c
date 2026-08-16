#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= x && x <= 10000;
    requires \valid(numbers + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 1 && (numbers)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n + 1;
*/
int func(int n, int x, int *numbers) {
    int ans = 1;
    int sum = 0;
    int i = 0;
    
    /*@
        loop invariant ((i) >= 0 && (i) <= (n) &&
    (n) >= 1 && (n) <= 100 &&
    (x) >= 1 && (x) <= 10000 &&
    (sum) >= 0 &&
    (sum) <= (i) * 100 &&
    (ans) >= 1 &&
    (ans) <= (i) + 1);
        loop invariant 0 <= i && i <= n;
        loop invariant sum >= 0;
        loop invariant sum <= i * 100;
        loop invariant ans >= 1 && ans <= i + 1;
        loop assigns i, sum, ans;
        loop variant n - i;
    */
    while (i < n) {
        int num = numbers[i];
        sum += num;
        
        //@ assert sum >= 0 && sum <= (i + 1) * 100;
        
        if (sum <= x) {
            ans += 1;
        }
        
        i += 1;
        
        //@ assert i >= 1 && i <= n;
    }
    
    //@ assert ans >= 1 && ans <= n + 1;
    return ans;
}
