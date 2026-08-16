#include <stdbool.h>

/*@ predicate exists_min(int *a, integer len, integer min) =
      \exists integer i; 0 <= i < len && a[i] == min;
*/

/*@ predicate forall_min(int *a, integer len, integer min) =
      \forall integer j; 0 <= j < len ==> a[j] >= min;
*/

/*@ predicate exists_max(int *a, integer len, integer max) =
      \exists integer i; 0 <= i < len && a[i] == max;
*/

/*@ predicate forall_max(int *a, integer len, integer max) =
      \forall integer j; 0 <= j < len ==> a[j] <= max;
*/

/*@ lemma min_element_lemma:
      \forall int *a, integer len, integer min;
      len > 0 && exists_min(a, len, min) && forall_min(a, len, min) ==>
      \exists integer i; 0 <= i < len && a[i] == min;
*/

/*@ lemma max_element_lemma:
      \forall int *a, integer len, integer max;
      len > 0 && exists_max(a, len, max) && forall_max(a, len, max) ==>
      \exists integer i; 0 <= i < len && a[i] == max;
*/

/*@ logic integer func_result(integer n, integer a, integer b) =
      n * a < b ? n * a : b;
*/

/*@ predicate is_even_result(integer n, bool result) =
      result == (n % 2 == 0);
*/

/*@ lemma func_lemma:
      \forall integer n, integer a, integer b;
      1 <= n <= 20 && 1 <= a <= 50 && 1 <= b <= 50 ==>
      func_result(n, a, b) == n * a || func_result(n, a, b) == b;
*/

/*@ lemma func_bound_lemma:
      \forall integer n, integer a, integer b;
      1 <= n <= 20 && 1 <= a <= 50 && 1 <= b <= 50 ==>
      func_result(n, a, b) <= b;
*/

/*@ lemma product_bound:
      \forall integer n, integer a;
      1 <= n <= 20 && 1 <= a <= 50 ==> n * a <= 1000;
*/

/*@ requires 
      len > 0;
    ensures
      exists_min(a, len, \result);
    ensures
      forall_min(a, len, \result);
*/
int min_element(int *a, int len)
{
    int min;
    int i;
    
    min = a[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant exists_min(a, i, min);
        loop invariant forall_min(a, i, min);
        loop assigns min, i;
    */
    while (i < len) {
        if (a[i] < min) {
            min = a[i];
        }
        i++;
    }
    return min;
}

/*@ requires 
      len > 0;
    ensures
      exists_max(a, len, \result);
    ensures
      forall_max(a, len, \result);
*/
int max_element(int *a, int len)
{
    int max;
    int i;
    
    max = a[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant exists_max(a, i, max);
        loop invariant forall_max(a, i, max);
        loop assigns max, i;
    */
    while (i < len) {
        if (a[i] > max) {
            max = a[i];
        }
        i++;
    }
    return max;
}

/*@ requires
      1 <= n <= 20;
    requires
      1 <= a <= 50;
    requires
      1 <= b <= 50;
    ensures
      \result == n * a || \result == b;
    ensures
      \result <= b;
*/
int func(int n, int a, int b)
{
    int product;
    
    //@ assert n * a <= 1000;
    product = n * a;
    
    if (product < b) {
        return product;
    } else {
        return b;
    }
}

/*@ requires
      0 <= n;
    ensures
      is_even_result(n, \result);
*/
bool is_even(int n)
{
    int temp;
    
    temp = n;
    
    /*@ loop invariant 0 <= temp <= n;
        loop invariant n % 2 == temp % 2;
        loop assigns temp;
    */
    while (temp >= 2) {
        temp -= 2;
    }
    return temp == 0;
}
