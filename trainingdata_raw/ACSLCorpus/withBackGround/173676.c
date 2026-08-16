#include <stdbool.h>

/*@ predicate valid_range(integer n) = 1 <= n <= 100; */
/*@ predicate valid_x(integer x, integer n) = 0 <= x <= n * 50; */
/*@ predicate valid_numbers(int *numbers, integer n) = 
      \forall integer i; 0 <= i < n ==> 0 <= numbers[i] <= 50; */

/*@ lemma ans_non_negative: 
      \forall integer ans, i; 0 <= ans <= i ==> ans >= 0; */

/*@ requires valid_range(n);
    requires valid_x(x, n);
    requires \valid(numbers + (0 .. n-1));
    requires valid_numbers(numbers, n);
    ensures \result >= 0;
    assigns \nothing;
 */
int func(int n, int x, int *numbers) {
    int ans = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant valid_numbers(numbers, n);
        loop invariant valid_range(n);
        loop invariant valid_x(x, n);
        loop assigns ans, i;
        loop variant n - i;
     */
    while (i < n) {
        int y = numbers[i];
        //@ assert 0 <= y <= 50;
        
        if (x >= y) {
            ans = ans + 1;
        }
        //@ assert 0 <= ans <= i+1;
        i = i + 1;
    }
    
    //@ assert ans >= 0;
    return ans;
}
