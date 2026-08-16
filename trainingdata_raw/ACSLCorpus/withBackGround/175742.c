#include <stddef.h>

/*@ predicate is_valid_range(integer n) = 1 <= n <= 100; */
/*@ predicate is_valid_x(integer x) = 1 <= x <= 10000; */
/*@ predicate is_valid_number(integer val) = 1 <= val <= 100; */

/*@
  requires \valid_read(numbers + (0..n-2));
  requires is_valid_range(n);
  requires is_valid_x(x);
  requires \forall integer i; 0 <= i < n-1 ==> is_valid_number(numbers[i]);
  ensures \result >= 0;
*/
long func(long n, long x, const long numbers[]) {
    long count = 0;
    long current = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n-1;
      loop invariant 0 <= count <= (long)index;
      loop invariant 0 <= current <= (long)index * 100;
      loop invariant \forall integer i; 0 <= i < index ==> is_valid_number(numbers[i]);
      loop invariant is_valid_range(n);
      loop invariant is_valid_x(x);
      loop assigns count, current, index;
    */
    while (index < (size_t)(n - 1)) {
        long ai = numbers[index];
        current += ai;
        
        //@ assert current >= ai;
        
        if (current <= x) {
            count += 1;
            //@ assert count >= 1;
        } else {
            break;
        }
        index += 1;
    }
    
    //@ assert count >= 0;
    return count + 1;
}
