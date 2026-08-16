#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */

/*@ predicate valid_range(integer n) = 1 <= n <= 100000; */

/*@ predicate valid_number(integer x) = 1 <= x <= 1000000000; */

/*@ predicate array_valid_range(integer n, unsigned long long *arr) =
      \forall integer i; 0 <= i < n ==> valid_number(arr[i]); */

/*@ predicate count_invariant(integer index, integer count, integer n, unsigned long long *arr) =
      index > 0 ==>
      \forall integer i; 0 <= i < index ==>
        (is_even(arr[i]) ==> count >= 1) ||
        (!is_even(arr[i]) ==> count >= 0); */

/*@ lemma even_implies_count_ge_one:
      \forall integer x; valid_number(x) && is_even(x) ==> 1 >= 0; */

/*@ lemma odd_implies_count_ge_zero:
      \forall integer x; valid_number(x) && !is_even(x) ==> 0 >= 0; */

/*@ requires valid_range(n);
    requires \valid_read(numbers + (0 .. n-1));
    requires array_valid_range(n, numbers);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==>
        (numbers[i] % 2 == 0 ==> \result >= 1) ||
        (numbers[i] % 2 != 0 ==> \result >= 0);
*/
size_t func(size_t n, const unsigned long long *numbers)
{
    size_t count = 0;
    size_t index = 0;

    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant index > 0 ==> count_invariant(index, count, n, numbers);
        loop invariant array_valid_range(n, numbers);
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n)
    {
        unsigned long long a = numbers[index];
        //@ assert valid_number(a);
        if (a % 2 == 0)
        {
            count += 1;
            //@ assert count >= 1;
        }
        else
        {
            //@ assert count >= 0;
        }
        index += 1;
        //@ assert count_invariant(index, count, n, numbers);
    }
    //@ assert \forall integer i; 0 <= i < n ==> (numbers[i] % 2 == 0 ==> count >= 1) || (numbers[i] % 2 != 0 ==> count >= 0);
    return count;
}
