#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_range(int* arr, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < 3 ==> arr[i] >= 1 && arr[i] <= 13;

    predicate is_arithmetic_sequence(int a, int b, int c) =
        b - a == c - b;
*/

bool check_arithmetic_sequence(int* arr, size_t len) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert len >= 3;
    if (len < 3) {
        return false;
    }

    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert a >= 1 && a <= 13;
    //@ assert b >= 1 && b <= 13;
    //@ assert c >= 1 && c <= 13;

    result = (b - a == c - b);
    //@ assert result == true <==> is_arithmetic_sequence(a, b, c);
    return result;
}

/*@
    predicate valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer mul500(integer n) = 500 * n;

    predicate condition_holds(integer k, integer x) =
        mul500(k) >= x;
*/

bool check_budget(long k, long x)
{
    long r;
    bool result;

    //@ assert valid_params(k, x);

    if (500 * k >= x) {
        //@ assert mul500(k) >= x;
        return true;
    } else {
        r = 1;
        while (r < k) {
            //@ assert 500 * (r - 1) < x;
            if (500 * r >= x) {
                //@ assert mul500(k) >= x;
                return true;
            }
            r = r + 1;
        }
        //@ assert mul500(k) < x;
        return false;
    }
}

/*@
    predicate valid_deal(int* cards, integer len, integer k, integer x) =
        valid_range(cards, len) && valid_params(k, x) &&
        (is_arithmetic_sequence(cards[0], cards[1], cards[2]) || mul500(k) >= x);
*/

bool validate_deal_round(int* cards, size_t len, long k, long x) {
    bool is_sequence;
    bool has_budget;
    bool deal_valid;

    is_sequence = check_arithmetic_sequence(cards, len);
    
    has_budget = check_budget(k, x);
    
    deal_valid = is_sequence || has_budget;
    
    //@ assert deal_valid == true <==> (is_arithmetic_sequence(cards[0], cards[1], cards[2]) || mul500(k) >= x);
    //@ assert deal_valid == true <==> valid_deal(cards, len, k, x);
    return deal_valid;
}
