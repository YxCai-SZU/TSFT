#include <stdbool.h>

/* ========== Provided function 1 (slightly adapted) ========== */

/*@ predicate is_greater_than(integer x, integer k) = k > x; */
/*@ predicate is_less_than_or_equal_to(integer x, integer k) = k <= x; */
/*@ predicate is_divisible_by(integer x, integer k) = k % x == 0; */

/*@ lemma test_is_greater_than: 
      \forall integer x, k; (k > x) ==> is_greater_than(x, k); */

/*@ lemma test_is_less_than_or_equal_to: 
      \forall integer x, k; (k <= x) ==> is_less_than_or_equal_to(x, k); */

/*@ lemma test_is_divisible_by: 
      \forall integer x, k; (k % x == 0) ==> is_divisible_by(x, k); */

bool greater_than_test(int k) {
    //@ assert k > 5 ==> is_greater_than(5, k);
    return k > 5;
}

bool less_than_or_equal_to_test(int k) {
    //@ assert k <= 5 ==> is_less_than_or_equal_to(5, k);
    return k <= 5;
}

bool divisible_by_test(int k) {
    //@ assert k % 5 == 0 ==> is_divisible_by(5, k);
    return (k % 5) == 0;
}

/* ========== Provided function 2 ========== */

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate x_in_range(integer x) = 1 <= x && x <= 200;
*/

bool func2(long a, long b, long x)
{
    bool result;

    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert x_in_range(x);

    result = (b <= x) && (a >= (x - b));
    return result;
}

/* ========== Provided function 3 ========== */

/*@ predicate all_odd_or_divisible_by_3_or_5(int *arr, integer n) =
      \forall integer i; 0 <= i < n ==> 
        (arr[i] % 2 != 0) || (arr[i] % 3 == 0) || (arr[i] % 5 == 0);
*/

/*@ predicate valid_range(int *arr, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 1000;
*/

/*@ lemma range_preservation:
      \forall int *arr, integer n, integer m;
        valid_range(arr, n) && 0 <= m <= n ==> valid_range(arr, m);
*/

bool func3(int n, int *numbers) {
    bool flag = true;
    int index = 0;
    
    while (index < n) {
        int a = numbers[index];
        
        if (a % 2 != 0) {
            index += 1;
            continue;
        }
        
        if (!(a % 3 == 0 || a % 5 == 0)) {
            flag = false;
        }
        
        index += 1;
    }
    
    return flag;
}

/* ========== Provided function 4 ========== */

/*@
    predicate is_valid_range(integer v) = 1 <= v <= 9;

    predicate condition_holds(integer a, integer b, integer c) =
        (a == b + 1 && c == 1) ||
        (a == b - 1 && c == 9) ||
        (b == c + 1 && a == 1) ||
        (b == c - 1 && a == 9) ||
        (c == a + 1 && b == 1) ||
        (c == a - 1 && b == 9);
*/

bool func4(int a, int b, int c)
{
    bool flag = false;

    //@ assert a >= 1 && a <= 9;
    //@ assert b >= 1 && b <= 9;
    //@ assert c >= 1 && c <= 9;

    if ((a == b + 1 && c == 1) || (a == b - 1 && c == 9)) {
        flag = true;
    }
    if ((b == c + 1 && a == 1) || (b == c - 1 && a == 9)) {
        flag = true;
    }
    if ((c == a + 1 && b == 1) || (c == a - 1 && b == 9)) {
        flag = true;
    }

    //@ assert flag == true <==> condition_holds(a, b, c);
    return flag;
}

/* ========== Synthesized complex function ========== */

/*@ 
    predicate valid_input(int n, int *arr, long a, long b, long x, int p, int q, int r) =
        n >= 1 && n <= 100 &&
        \valid(arr + (0 .. n-1)) &&
        valid_range(arr, n) &&
        a_in_range(a) && b_in_range(b) && x_in_range(x) &&
        is_valid_range(p) && is_valid_range(q) && is_valid_range(r);
*/

bool process_and_validate(int n, int *arr, long a, long b, long x, int p, int q, int r) {
    bool array_ok = func3(n, arr);
    
    bool relation_ok = func2(a, b, x);
    
    bool cyclic_ok = func4(p, q, r);
    
    int threshold = 5;
    bool greater = greater_than_test(threshold + 1);  // 6 > 5 -> true
    bool less_eq = less_than_or_equal_to_test(threshold);  // 5 <= 5 -> true
    bool divisible = divisible_by_test(threshold * 2);  // 10 % 5 == 0 -> true
    
    bool result = array_ok && relation_ok && cyclic_ok && greater && less_eq && divisible;
    
    //@ assert result == 1 <==> (all_odd_or_divisible_by_3_or_5(arr, n) && (b <= x && a >= (x - b)) && condition_holds(p, q, r));
    
    return result;
}
