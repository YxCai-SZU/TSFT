#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/*@
    predicate a_le_n_minus_b_plus_1(integer n, integer a, integer b) =
        a <= n - b + 1;
*/

bool func1(int n, int a, int b) {
    int min;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a < b <= n;
    
    if (a < n - b + 1) {
        min = a;
        //@ assert min == a;
    } else {
        min = n - b + 1;
        //@ assert min == n - b + 1;
    }
    
    //@ assert min == a <==> a <= n - b + 1;
    return min == a;
}

/*@
    predicate has_nine(integer n) =
        (n / 100) % 10 == 9 ||
        (n / 10) % 10 == 9 ||
        n % 10 == 9;
*/

bool func2(int n)
{
    unsigned int n_unsigned;
    bool result;

    //@ assert 1000 <= n <= 9999;
    
    if (n < 0) {
        n_unsigned = (unsigned int)(-(long long)n);
    } else {
        n_unsigned = (unsigned int)n;
    }
    
    //@ assert n_unsigned == (unsigned int)(n < 0 ? -(long long)n : n);
    
    if ((n_unsigned / 100) % 10 == 9 ||
        (n_unsigned / 10) % 10 == 9 ||
        n_unsigned % 10 == 9) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> has_nine(n);
    return result;
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer compute_ans(integer x) = (x + 100) / 100 * 100 + 100;
    
    lemma ans_bounds: \forall integer x; valid_range(x) ==> 1 <= compute_ans(x) <= 1000;
    lemma ans_formula: \forall integer x; valid_range(x) ==> compute_ans(x) == (x + 100) / 100 * 100 + 100;
*/

uint32_t func3(uint32_t x)
{
    uint32_t ans;
    
    //@ assert x + 100 <= 200;
    //@ assert (x + 100) / 100 <= 2;
    //@ assert (x + 100) / 100 * 100 <= 200;
    //@ assert (x + 100) / 100 * 100 + 100 <= 300;
    
    ans = (x + 100) / 100 * 100 + 100;
    return ans;
}

typedef struct {
    char* name;
    unsigned int cost;
    unsigned int quantity;
} Ingredient;

/*@ predicate is_inexpensive(Ingredient* i) = i->cost < 5; */

Ingredient func4(Ingredient* i, unsigned int amount) {
    Ingredient ret;
    
    //@ assert i->quantity >= amount;
    //@ assert i->quantity - amount <= i->quantity;
    
    ret.name = i->name;
    ret.cost = i->cost;
    ret.quantity = i->quantity - amount;
    
    return ret;
}


bool check_discount_eligibility(int n, int a, int b, int cost, Ingredient* i, unsigned int amount) {
    bool position_ok;
    bool no_nine;
    uint32_t tier;
    Ingredient remaining;
    
    position_ok = func1(n, a, b);
    
    no_nine = !func2(cost);
    
    tier = func3(i->quantity);
    
    remaining = func4(i, amount);
    
    //@ assert (position_ok && no_nine) ==> (a <= n - b + 1 && !((cost / 100) % 10 == 9 || (cost / 10) % 10 == 9 || cost % 10 == 9));
    
    return position_ok && no_nine;
}

int main() {
    Ingredient sugar = {"sugar", 10, 50};
    check_discount_eligibility(10, 2, 5, 1234, &sugar, 5);
    return 0;
}
