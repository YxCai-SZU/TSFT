#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= n && n <= 100;
  requires \valid(numbers + (0 .. n-1));
  requires \forall integer i; 0 <= i < n ==> 1 <= numbers[i] <= 1000;
  ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==>
        (numbers)[i] % 2 != 0 || (numbers)[i] % 6 == 0 || (numbers)[i] % 10 == 0);
  assigns \nothing;
*/
bool func(size_t n, int numbers[]) {
    size_t i = 0;
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer j; 0 <= j < i ==> 
        numbers[j] % 2 != 0 || numbers[j] % 6 == 0 || numbers[j] % 10 == 0;
      loop assigns i;
      loop variant n - i;
    */
    while (i < n) {
        int x = numbers[i];
        //@ assert 0 <= i < n;
        if (x % 2 == 0 && x % 6 != 0 && x % 10 != 0) {
            //@ assert !(x % 2 != 0 || x % 6 == 0 || x % 10 == 0);
            return false;
        }
        i += 1;
    }
    //@ assert i == n;
    //@ assert (\forall integer i; 0 <= i < (n) ==>         (numbers)[i] % 2 != 0 || (numbers)[i] % 6 == 0 || (numbers)[i] % 10 == 0);
    return true;
}
