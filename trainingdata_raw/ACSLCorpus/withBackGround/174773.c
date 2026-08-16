#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 1 <= n <= 100; */
/*@ predicate valid_numbers(integer n, int *numbers) =
      \forall integer i; 0 <= i < n ==> 1 <= numbers[i] <= 1000; */
/*@ predicate is_special(integer x) = 
      x % 2 != 0 && x % 3 != 0 && x % 5 != 0; */

/*@ lemma count_bound: 
      \forall integer n, int *numbers, integer count, integer i;
      valid_range(n) && valid_numbers(n, numbers) && 0 <= i <= n && 
      0 <= count <= i ==> count <= n; */

/*@ requires valid_range(n);
    requires \valid(numbers + (0 .. n-1));
    requires valid_numbers(n, numbers);
    assigns \nothing;
    ensures \result <= n;
    ensures \forall integer i; 0 <= i < n ==> 
             is_special(numbers[i]) ==> \result > 0;
*/
size_t func(int n, int *numbers) {
    size_t count = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 
                       is_special(numbers[j]) ==> count > 0;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int a = numbers[i];
        
        //@ assert 1 <= a <= 1000;
        
        if (a % 2 != 0 && a % 3 != 0 && a % 5 != 0) {
            count++;
        }
        
        i++;
        
        //@ assert count <= i;
    }
    
    return count;
}

/*@ assigns \nothing; */
int main() {
    return 0;
}
