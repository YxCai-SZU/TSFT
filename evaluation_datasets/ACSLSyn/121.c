#include <stdbool.h>

/*@ predicate vector_len_5(long long *v) =
      \valid(v + (0 .. 4));
*/

/*@ predicate has_zero(long long *v) =
      v[0] == 0 || v[1] == 0 || v[2] == 0 || v[3] == 0 || v[4] == 0;
*/

/*@ predicate all_nonzero_before(long long *v, integer i) =
      \forall integer j; 0 <= j < i ==> v[j] != 0;
*/

/*@ lemma precondition_implies_zero_exists:
      \forall long long *v;
        vector_len_5(v) && has_zero(v) ==>
        \exists integer k; 0 <= k < 5 && v[k] == 0;
*/

long long find_first_zero(long long *v) {
    int i = 0;
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            return (long long)(i + 1);
        }
        //@ assert v[i] != 0;
        i++;
    }
    //@ assert i == 5;
    //@ assert \forall integer j; 0 <= j < 5 ==> v[j] != 0;
    //@ assert false;
    return -1;
}

/*@
    predicate is_in_range(integer n) = 1 <= n && n <= 100;
    predicate is_in_range_x(integer x) = 1 <= x && x <= 100000;
    logic integer compute_en(integer n) = n * 500;
*/

bool check_threshold(int n, int x)
{
    int en;
    en = n * 500;
    //@ assert en == compute_en(n);
    return x >= en - 1 && x <= en;
}

/* Scenario: Energy consumption threshold detection system.
   Given a 5-element vector of energy readings (long long), the system finds 
   the first zero reading index (position). Then, based on a threshold index (n) 
   and a consumption value (x), it checks whether x falls within a computed 
   energy window (en-1 to en). The final assertion ensures that when the 
   zero position is found, the threshold check is consistent: the window 
   endpoint en is proportional to n, and x is within range.
*/

bool synthesized_func(long long *v, int n, int x) {
    long long pos;
    bool result;
    
    pos = find_first_zero(v);
    //@ assert 1 <= pos <= 5;
    //@ assert v[pos - 1] == 0;
    
    result = check_threshold(n, x);
    
    //@ assert (result == 1) ==> (x >= n * 500 - 1 && x <= n * 500);
    //@ assert (result == 0) ==> (x < n * 500 - 1 || x > n * 500);
    
    return result;
}
