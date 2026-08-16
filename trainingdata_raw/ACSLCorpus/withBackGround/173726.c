#include <stdbool.h>

/*@ predicate is_sum(integer a, integer b, integer c) =
      a == b + c || b == c + a || c == a + b;
*/

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == (a == b + c || b == c + a || c == a + b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int min;
    int mid;
    int max;
    int temp;

    if (a == b + c || b == c + a || c == a + b) {
        return true;
    } else {
        min = a;
        mid = b;
        max = c;

        // Sorting the three variables
        if (min > mid) {
            temp = min;
            min = mid;
            mid = temp;
        }
        //@ assert min <= mid;
        
        if (mid > max) {
            temp = mid;
            mid = max;
            max = temp;
        }
        //@ assert mid <= max;
        
        if (min > mid) {
            temp = min;
            min = mid;
            mid = temp;
        }
        //@ assert min <= mid && mid <= max;

        // Ensuring no overflow/underflow occurs in the addition
        //@ assert min >= 1 && mid >= 1 && max >= 1;
        //@ assert min <= 100 && mid <= 100 && max <= 100;

        if (max == min + mid) {
            return true;
        } else {
            return false;
        }
    }
}
