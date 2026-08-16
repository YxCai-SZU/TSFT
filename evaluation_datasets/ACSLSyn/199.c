#include <stdbool.h>

/*@ predicate in_range(integer n, integer m) = 
      1 <= n <= 100 && 0 <= m <= n; */

/*@ predicate valid_k(integer k) = 1 <= k <= 200; */

/*@ lemma equality_lemma: 
      \forall integer n, m; in_range(n, m) ==> (n == m ==> n == m); */

/*@ lemma product_bound: \forall integer k; valid_k(k) ==> 
        (k / 2) * (k - k / 2) <= 200 * 200; */

/*@ logic integer half(integer k) = k / 2; */
/*@ logic integer remain(integer k) = k - half(k); */
/*@ logic integer expected_result(integer k) = half(k) * remain(k); */

bool func_bool(int n, int m) {
    //@ assert n == m ==> n == m;
    return n == m;
}

bool func2(int n, int m) {
    bool result;
    if (n == m) {
        result = true;
    } else {
        result = false;
    }
    //@ assert result == (n == m);
    return result;
}

bool func3(int n, int m) {
    bool result;
    result = (n == m) ? true : false;
    //@ assert result == (n == m);
    return result;
}

bool func4(int n, int m) {
    bool result;
    if (n == m) {
        result = true;
    } else {
        result = false;
    }
    //@ assert result == (n == m);
    return result;
}

int func_int(unsigned int k)
{
    unsigned int half_k;
    unsigned int remain_k;
    int result;

    half_k = k / 2;
    remain_k = k - half_k;

    //@ assert half_k == half(k);
    //@ assert remain_k == remain(k);
    //@ assert half_k * remain_k <= 200 * 200;
    //@ assert half_k * remain_k == expected_result(k);

    result = (int)(half_k * remain_k);
    return result;
}

int process_conditional_operation(int n, int m, unsigned int k) {
    bool condition;
    int value;
    
    condition = func_bool(n, m);
    
    if (condition) {
        value = func_int(k);
    } else {
        value = 0;
    }
    
    //@ assert (condition == (n == m)) && (value == (condition ? expected_result(k) : 0));
    //@ assert value == ((n == m) ? expected_result(k) : 0);
    
    return value;
}
