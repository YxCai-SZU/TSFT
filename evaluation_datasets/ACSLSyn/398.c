#include <stdbool.h>
#include <stddef.h>


/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a && a <= 100 && 1 <= b && b <= 100;

    logic integer compute_expr(integer a, integer b) =
        (a - (a / 2)) * 2 > b ? 1 : 0;
*/

bool func1(unsigned int a, unsigned int b)
{
    unsigned int a_mod_2;
    bool result;

    //@ assert is_valid_range(a, b);
    
    a_mod_2 = a % 2;
    result = ((a - (a / 2)) * 2 > b);

    //@ assert result == (compute_expr(a, b) == 1);
    
    return result;
}


enum Dessert {
    Cake,
    Pie,
    Icecream
};

struct DessertData {
    enum Dessert tag;
    union {
        unsigned int pieces;
        unsigned int scoop_number;
    } data;
};

/*@
    predicate check_dessert(struct DessertData d) =
        d.tag == Icecream && d.data.scoop_number > 5;
*/

struct DessertData make_float(struct DessertData d) {
    struct DessertData new_dessert;
    //@ assert d.tag == Icecream;
    new_dessert.tag = Icecream;
    new_dessert.data.scoop_number = 0;
    return new_dessert;
}


/*@
    predicate is_in_range(integer n) =
        1 <= n <= 10000;

    logic integer compute_result(integer n) =
        (n - 1) / 100 * 100 + 100;

    lemma result_correctness:
        \forall integer n;
            is_in_range(n) ==>
            compute_result(n) == (n - 1) / 100 * 100 + 100;
*/

size_t func3(size_t n)
{
    size_t ans;
    size_t temp;

    if (n % 100 == 0)
    {
        ans = n;
        //@ assert ans == n;
    }
    else
    {
        temp = n / 100;
        temp += 1;
        ans = temp * 100;
        //@ assert ans == (n - 1) / 100 * 100 + 100;
    }

    //@ assert ans == compute_result(n);
    return ans;
}


/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        (a - c * d > 0 && b - d < 0) ||
        (a - c * d < 0 && b - d > 0) ||
        (a - c * d == 0 && b - d == 0) ||
        (a - c * d == 0 && b - d > 0) ||
        (a - c * d > 0 && b - d == 0);
*/

/*@
    lemma product_bounds:
        \forall integer c, d;
        1 <= c <= 100 && 1 <= d <= 100 ==> c * d <= 10000;
*/

bool func4(int a, int b, int c, int d)
{
    bool condition;
    int tmp1;
    int tmp2;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;
    
    //@ assert c * d <= 10000;

    tmp1 = a - c * d;
    tmp2 = b - d;

    if (tmp1 > 0 && tmp2 < 0) {
        condition = true;
    } else if (tmp1 < 0 && tmp2 > 0) {
        condition = true;
    } else if (tmp1 == 0 && tmp2 == 0) {
        condition = true;
    } else if (tmp1 == 0 && tmp2 > 0) {
        condition = true;
    } else if (tmp1 > 0 && tmp2 == 0) {
        condition = true;
    } else {
        condition = false;
    }

    //@ assert condition == true <==> condition_holds(a, b, c, d);

    return condition;
}


bool inventory_management(unsigned int a, unsigned int b, size_t n, 
                          int c, int d, struct DessertData icecream)
{
    bool result;
    size_t rounded_n;
    struct DessertData processed_dessert;

    processed_dessert = make_float(icecream);
    //@ assert processed_dessert.tag == Icecream;
    //@ assert processed_dessert.data.scoop_number == 0;

    bool expr_result = func1(a, b);
    //@ assert expr_result == (compute_expr(a, b) == 1);

    rounded_n = func3(n);
    //@ assert rounded_n == compute_result(n);

    bool cond_result = func4(a, b, c, d);
    //@ assert cond_result == true <==> condition_holds(a, b, c, d);

    result = cond_result && (rounded_n >= 100) && expr_result;

    //@ assert result == true <==> (condition_holds(a, b, c, d) && compute_result(n) >= 100 && compute_expr(a, b) == 1);

    return result;
}
