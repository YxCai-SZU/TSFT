#include <limits.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert 1 <= r && r <= 100;
    return 3 * r * r;
}

/*@
    requires (1 <= (p) <= 100) && (1 <= (q) <= 100) && (1 <= (r) <= 100);
    ensures \result <= p + q + r;
    ensures \result == p + q || \result == q + r || \result == r + p;
    assigns \nothing;
*/
int func_f(int p, int q, int r)
{
    int x;
    int result;
    
    if (p + q < q + r) {
        x = p + q;
    } else {
        x = q + r;
    }
    
    if (x < r + p) {
        result = x;
    } else {
        result = r + p;
    }
    
    //@ assert result <= p + q + r;
    return result;
}

/*@
    requires \valid(a) && \valid(b);
    ensures \result == (*a > *b ? *a : *b);
    assigns \nothing;
*/
int max_val(int *a, int *b)
{
    if (*a > *b) {
        return *a;
    } else {
        return *b;
    }
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= a + b + c;
    ensures \result == a + b || \result == b + c || \result == c + a;
    assigns \nothing;
*/
int func_s(int a, int b, int c)
{
    int x;
    int result;
    
    if (a + b < b + c) {
        x = a + b;
    } else {
        x = b + c;
    }
    
    if (x < c + a) {
        result = x;
    } else {
        result = c + a;
    }
    
    //@ assert result <= a + b + c;
    return result;
}
