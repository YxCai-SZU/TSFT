#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(integer n) = 1 <= n && n <= 1000000; */
/*@ predicate is_valid_m_range(integer m) = 1 <= m && m <= 10000; */
/*@ predicate is_valid_number(integer x) = 1 <= x && x <= 10000; */
/*@ predicate array_valid(int *arr, integer m) = 
      \forall integer i; 0 <= i < m ==> is_valid_number(arr[i]); */

/*@ logic integer min_val(integer a, integer b) = a < b ? a : b; */

/*@ lemma min_properties: 
      \forall integer a, b; 
      a >= -2147483648 && b >= -2147483648 ==> 
      (min_val(a, b) == a || min_val(a, b) == b) && 
      min_val(a, b) <= a && 
      min_val(a, b) <= b; */

/*@ assigns \nothing;
    ensures \result == min_val(a, b);
 */
int min(int a, int b)
{
    //@ assert a >= -2147483648;
    int result;
    if (a < b) {
        result = a;
        //@ assert result == min_val(a, b);
    } else {
        result = b;
        //@ assert result == min_val(a, b);
    }
    return result;
}

/*@ requires is_valid_range(n);
    requires is_valid_m_range(m);
    requires \valid(numbers + (0 .. m-1));
    requires array_valid(numbers, m);
    assigns \nothing;
    ensures \result >= -1;
    ensures \result <= n;
 */
int func(int n, int m, int *numbers)
{
    int v = 0;
    size_t index = 0;
    int result;
    
    //@ assert is_valid_range(n);
    //@ assert is_valid_m_range(m);
    //@ assert array_valid(numbers, m);
    
    /*@ loop invariant 0 <= index <= m;
        loop invariant v >= 0;
        loop invariant v <= index * 10000;
        loop invariant \forall integer i; 0 <= i < index ==> v >= numbers[i];
        loop assigns v, index;
        loop variant m - index;
    */
    while (index < (size_t)m) {
        //@ assert numbers[index] >= 1 && numbers[index] <= 10000;
        v += numbers[index];
        //@ assert v >= 0;
        index++;
    }
    
    //@ assert v >= 0 && v <= m * 10000;
    if (n - v >= 0) {
        result = n - v;
        //@ assert result >= 0 && result <= n;
    } else {
        result = -1;
        //@ assert result == -1;
    }
    return result;
}
