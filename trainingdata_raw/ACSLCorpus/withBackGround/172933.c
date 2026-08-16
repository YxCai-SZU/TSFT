#include <stdint.h>
#include <stdbool.h>

/*@ predicate valid_number(integer v) = 1 <= v <= 1000000000; */

/*@ predicate valid_array(int64_t* arr, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> valid_number(arr[i]); */

/*@
  requires \valid_read(numbers + (0 .. n-1));
  requires valid_array(numbers, n);
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result <= n;
*/
int32_t func(uint32_t n, int64_t* numbers) {
    int32_t ok_cnt = 0;
    uint32_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant ok_cnt >= 0;
      loop invariant ok_cnt <= (int32_t)index;
      loop invariant \forall integer i; 0 <= i < index ==> valid_number(numbers[i]);
      loop assigns index, ok_cnt;
    */
    while (index < n) {
        int64_t a = numbers[index];
        
        //@ assert valid_number(a);
        
        if (a % 2 == 0 && a % 3 == 0) {
            ok_cnt += 1;
        }
        
        index += 1;
    }
    
    if (ok_cnt == 0) {
        return -1;
    } else {
        return ok_cnt;
    }
}
