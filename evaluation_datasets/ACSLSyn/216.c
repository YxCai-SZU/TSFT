#include <stdbool.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */
/*@ predicate vector_len_eq_two(int *v, integer len) = len == 2;
    predicate element_in_range(int *v, integer len) = 
        len == 2 ==> v[0] >= 0 && v[0] <= 100 && v[1] >= 0 && v[1] <= 100;
    logic integer leq_result(integer a, integer b) = a <= b ? 1 : 0;
*/

unsigned int func(unsigned int a, unsigned int b) {
    unsigned int ans;
    bool cond;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    cond = (a % 2 == 0) && (b % 2 != 0);
    
    if (cond) {
        ans = a;
    } else {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= a;
    
    return ans;
}

bool func2(int *v) {
    int a;
    int b;
    bool result;
    
    //@ assert vector_len_eq_two(v, 2);
    //@ assert element_in_range(v, 2);
    
    a = v[0];
    b = v[1];
    
    //@ assert a >= 0 && a <= 100;
    //@ assert b >= 0 && b <= 100;
    
    result = a <= b;
    
    //@ assert result == (bool)leq_result(a, b);
    return result;
}

unsigned int process_pair(int *v) {
    unsigned int a_val, b_val;
    unsigned int result_a;
    bool comparison;
    
    //@ assert \valid(v+(0..1));
    //@ assert vector_len_eq_two(v, 2);
    //@ assert element_in_range(v, 2);
    
    a_val = (unsigned int)v[0];
    b_val = (unsigned int)v[1];
    
    //@ assert 1 <= a_val <= 100;
    //@ assert 1 <= b_val <= 100;
    
    result_a = func(a_val, b_val);
    
    //@ assert result_a >= 0;
    //@ assert result_a <= a_val;
    
    comparison = func2(v);
    
    //@ assert comparison == (bool)(v[0] <= v[1]);
    
    //@ assert (comparison && result_a == a_val) ==> (v[0] <= v[1] && v[0] % 2 == 0 && v[1] % 2 != 0);
    //@ assert (!comparison && result_a == 0) ==> (v[0] > v[1] || !(v[0] % 2 == 0 && v[1] % 2 != 0));
    
    return result_a;
}
