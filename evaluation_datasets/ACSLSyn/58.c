#include <stdbool.h>

/*@ predicate is_in_range(integer a) = 1 <= a && a <= 10; */

/*@ predicate all_small_or_one_less(integer n, int *h, integer k) =
      \forall integer i; 0 <= i < n ==> (h[i] <= k || h[i] - 1 <= k);
*/

/*@ lemma bound_lemma:
      \forall integer n, integer k, int *h;
        0 < n <= 100000 &&
        (\forall integer i; 0 <= i < n ==> 1 <= h[i] <= 500) &&
        1 <= k <= 500 ==>
        (\forall integer i; 0 <= i < n ==> h[i] <= k || h[i] - 1 <= k) ||
        (\exists integer i; 0 <= i < n && h[i] > k && h[i] - 1 > k);
*/

bool func1(unsigned long long a)
{
    bool is_allowed = false;
    unsigned long long a_local = a;
    
    //@ assert is_in_range(a_local);
    a_local = a_local - 1;
    is_allowed = true;
    
    //@ assert 1 <= a_local + 1 && a_local + 1 <= 10;
    
    return is_allowed;
}

bool func2(int n, int *h, int k) {
    int index = 0;
    while (index < n) {
        int i = h[index];
        //@ assert 1 <= i <= 500;
        if (i > k && i - 1 > k) {
            return false;
        }
        index++;
    }
    return true;
}

bool process_sensor_data(unsigned long long a, int n, int *h, int k) {
    bool threshold_valid = func1(a);
    
    bool readings_valid = func2(n, h, k);
    
    return threshold_valid && readings_valid;
}
