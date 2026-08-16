#include <stdbool.h>
#include <stddef.h>

/*@ predicate sorted(int *arr, integer n) =
      \forall integer i; 0 <= i < n-1 ==> arr[i] < arr[i+1];
*/

/*@ predicate in_range(int *arr, integer n, integer k) =
      \forall integer i; 0 <= i < n ==> 0 <= arr[i] && arr[i] < k;
*/

/*@ lemma bounds_lemma:
      \forall int *arr, integer n, integer k;
      sorted(arr, n) && in_range(arr, n, k) && n >= 2 && k >= 2 ==>
      arr[0] >= 0 && arr[n-1] < k;
*/

/*@ requires 2 <= k <= 1000000;
    requires 2 <= n <= 200000;
    requires \valid(numbers + (0..n-1));
    requires in_range(numbers, n, k);
    requires sorted(numbers, n);
    ensures \result >= 0 && \result <= k;
*/
int func(int k, int n, int *numbers) {
    int a;
    int b;
    int m;
    size_t i;
    
    a = numbers[0];
    b = k - numbers[n-1] + numbers[0];
    m = 0;
    i = 0;
    
    /*@ loop invariant 0 <= i <= n-1;
        loop invariant a >= 0 && a <= k;
        loop invariant b >= 0;
        loop invariant m >= 0 && m <= k;
        loop invariant in_range(numbers, n, k);
        loop invariant sorted(numbers, n);
        loop assigns a, b, m, i;
    */
    while (i < (size_t)(n - 1)) {
        int l;
        
        l = numbers[i + 1] - numbers[i];
        
        //@ assert l > 0;
        
        if (a < l) {
            a = l;
        }
        
        if (b < l) {
            b = l;
        }
        
        if (m < l) {
            m = l;
        }
        
        i++;
    }
    
    //@ assert m >= 0 && m <= k;
    
    {
        int x;
        int y;
        int ans;
        
        x = k - m;
        y = (a < b) ? a : b;
        ans = (x < y) ? x : y;
        
        //@ assert ans >= 0;
        //@ assert ans <= k;
        
        return ans;
    }
}
