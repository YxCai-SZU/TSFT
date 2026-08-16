#include <stdbool.h>
#include <limits.h>

/*@
    predicate is_valid_index(integer i, integer len) =
        0 <= i < len;

    logic integer vector_len(integer capacity) = capacity;

    lemma len_non_negative:
        \forall integer cap; cap >= 0 ==> vector_len(cap) >= 0;
*/

bool is_sorted_three(int *v, int cap) {
    int len = cap;
    int i = 0;

    while (i < len) {
        i += 1;
    }

    //@ assert len >= 3;
    
    if (len >= 3) {
        //@ assert is_valid_index(0, len) && is_valid_index(1, len) && is_valid_index(2, len);
        if (v[0] < v[1] && v[1] < v[2]) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

/*@
    predicate is_int32(integer x) = INT_MIN <= x <= INT_MAX;
*/

int maximum_of_three(int a, int b, int c) {
    int max_val = a;
    //@ assert max_val == a;
    if (b > max_val) {
        max_val = b;
        //@ assert max_val == b;
    }
    //@ assert max_val >= a && max_val >= b;
    if (c > max_val) {
        max_val = c;
        //@ assert max_val == c;
    }
    //@ assert max_val >= a && max_val >= b && max_val >= c;
    //@ assert max_val == a || max_val == b || max_val == c;
    return max_val;
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    logic integer count_matches(integer a, integer b, integer c) =
        (a == b ? 1 : 0) + (b == c ? 1 : 0) + (a == c ? 1 : 0);
*/

/*@
    lemma count_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            0 <= count_matches(a, b, c) <= 3;
*/

int count_equal_pairs(int a, int b, int c) {
    int cnt = 0;
    //@ assert cnt == 0;
    if (a == b) {
        cnt += 1;
        //@ assert cnt == 1;
    }
    //@ assert cnt == (a == b ? 1 : 0);
    if (b == c) {
        cnt += 1;
        //@ assert cnt == (a == b ? 1 : 0) + 1;
    }
    //@ assert cnt == (a == b ? 1 : 0) + (b == c ? 1 : 0);
    if (a == c) {
        cnt += 1;
        //@ assert cnt == (a == b ? 1 : 0) + (b == c ? 1 : 0) + 1;
    }
    //@ assert cnt == count_matches(a, b, c);
    //@ assert 0 <= cnt <= 3;
    return cnt;
}

/*@
    predicate valid_triplet(int a, int b, int c) =
        valid_range(a) && valid_range(b) && valid_range(c) &&
        is_int32(a) && is_int32(b) && is_int32(c);
*/

/*@
    logic integer max_of_three(int a, int b, int c) =
        (a >= b ? (a >= c ? a : c) : (b >= c ? b : c));
*/

int analyze_triplet(int *v, int cap) {
    bool sorted = is_sorted_three(v, cap);
    
    int a = v[0];
    int b = v[1];
    int c = v[2];
    
    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    //@ assert is_int32(a) && is_int32(b) && is_int32(c);
    
    int equal_count = count_equal_pairs(a, b, c);
    
    //@ assert 0 <= equal_count <= 3;
    
    int result;
    
    if (sorted) {
        result = c;
        //@ assert result == c;
    } else {
        result = maximum_of_three(a, b, c);
        //@ assert result == a || result == b || result == c;
        //@ assert result >= a && result >= b && result >= c;
    }
    
    //@ assert result >= a && result >= b && result >= c;
    
    int final_score = equal_count + result;
    
    //@ assert equal_count >= 0 && equal_count <= 3;
    //@ assert result >= 1 && result <= 100;
    //@ assert final_score >= 1 && final_score <= 103;
    
    return final_score;
}
