#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= a <= 10000;
  requires 1 <= b <= 10000;
  ensures \result == (a % 2 != 0 && b % 2 != 0);
*/
bool func(unsigned long a, unsigned long b) {
    bool a_is_odd;
    bool b_is_odd;
    bool result;

    a_is_odd = (a % 2) != 0;
    b_is_odd = (b % 2) != 0;
    result = a_is_odd && b_is_odd;

    //@ assert result == (a % 2 != 0 && b % 2 != 0);
    return result;
}

/*@
  requires size <= 100;
  requires \forall integer i; 0 <= i < size ==> list[i] <= 10000;
  ensures \result <= size;
  ensures \forall integer i; 0 <= i < size && (list[i] % 2 != 0) ==> \result > 0;
*/
size_t odd_count(unsigned long *list, size_t size) {
    size_t count;
    size_t i;

    count = 0;
    i = 0;

    /*@
      loop invariant i <= size;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < i && (list[j] % 2 != 0) ==> count > 0;
      loop invariant size <= 100;
      loop assigns i, count;
      loop variant size - i;
    */
    while (i < size) {
        unsigned long x;
        x = list[i];
        if ((x % 2) != 0) {
            count = count + 1;
        }
        i = i + 1;
    }

    //@ assert count <= size;
    //@ assert \forall integer i; 0 <= i < size && (list[i] % 2 != 0) ==> count > 0;
    return count;
}
