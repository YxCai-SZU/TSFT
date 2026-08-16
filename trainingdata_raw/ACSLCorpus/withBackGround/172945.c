#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 2 <= n <= 1000000; */
/*@ predicate valid_x(integer x) = 0 <= x <= 1000000000; */
/*@ predicate valid_array(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> 0 <= arr[i] <= 1000000000; */

/*@ lemma loop_invariant_maintained:
      \forall int *numbers, integer n, integer x, integer index, integer cnt, integer y;
        valid_range(n) && valid_x(x) && valid_array(numbers, n) &&
        0 <= index <= n && 0 <= cnt <= index && y <= x && y <= index * 1000000000 ==>
        (index < n && y + numbers[index] <= x ==> 
         0 <= index+1 <= n && 0 <= cnt+1 <= index+1 && 
         y+numbers[index] <= x && y+numbers[index] <= (index+1)*1000000000); */

/*@ requires valid_range(n);
    requires valid_x(x);
    requires valid_array(numbers, n);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int x, int numbers[]) {
    int cnt;
    int y;
    int index;
    
    cnt = 0;
    y = 0;
    index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= cnt <= index;
        loop invariant y <= index * 1000000000;
        loop invariant y <= x;
        loop assigns cnt, y, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= numbers[index] <= 1000000000;
        y = y + numbers[index];
        cnt = cnt + 1;
        
        if (y > x) {
            break;
        }
        
        index = index + 1;
    }
    
    //@ assert 0 <= cnt <= n;
    return cnt;
}
