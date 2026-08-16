#include <stdbool.h>

/* ========== Function 1: is_strictly_decreasing ========== */

/*@
    predicate strictly_decreasing{L}(int *v, integer len) =
        len >= 2 &&
        \forall integer i; 0 <= i < len - 1 ==> v[i] > v[i + 1];

    lemma decreasing_implies_len_two:
        \forall int *v, integer len; strictly_decreasing(v, len) ==> len >= 2;
*/

int is_strictly_decreasing(int *v, unsigned int len) {
    unsigned int i;
    int result;

    i = 1;
    result = 1;

    while (i < len) {
        //@ assert 0 <= i - 1 < i < len;
        if (v[i] >= v[i - 1]) {
            result = 0;
            break;
        }
        i++;
    }

    return result;
}

/* ========== Function 2: func ========== */

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;
    
    predicate func_pre(integer a, integer b, integer c) =
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    
    predicate func_post(integer a, integer b, integer c, bool result) =
        result <==> ((a < c && b > c) || (a > c && b < c));
*/

bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert is_valid_range(c);
    
    result = (a < c && b > c) || (a > c && b < c);
    return result;
}

/* ========== Synthesized function: protocol_state_validator ========== */

/*@
    predicate protocol_state_valid(int *seq, unsigned int len,
                                   unsigned int min_w, unsigned int max_w, unsigned int thresh) =
        strictly_decreasing(seq, len) &&
        ((min_w < thresh && max_w > thresh) || (min_w > thresh && max_w < thresh));
*/

int protocol_state_validator(int *seq, unsigned int len,
                             unsigned int min_window, unsigned int max_window, unsigned int threshold)
{
    int decreasing_ok;
    bool crossing_ok;

    decreasing_ok = is_strictly_decreasing(seq, len);
    //@ assert decreasing_ok == 1 <==> strictly_decreasing(seq, len);

    crossing_ok = func(min_window, max_window, threshold);
    //@ assert func_post(min_window, max_window, threshold, crossing_ok);

    int result = (decreasing_ok == 1 && crossing_ok) ? 1 : 0;

    //@ assert (result == 1) ==> (strictly_decreasing(seq, len) && ((min_window < threshold && max_window > threshold) || (min_window > threshold && max_window < threshold)));

    return result;
}

int main(void)
{
    return 0;
}
