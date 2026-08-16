/*@
    predicate non_negative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;
    
    predicate k_in_range(integer a, integer b, integer c, integer k) =
        1 <= k && k <= a + b + c;
    
    predicate sum_bounded(integer a, integer b, integer c) =
        a + b + c <= 2000000000;
    
    logic integer compute_na(integer a, integer cnt) =
        cnt < a ? cnt : a;
    
    logic integer compute_nb(integer b, integer cnt) =
        cnt < b ? cnt : b;
    
    logic integer compute_nc(integer c, integer cnt) =
        cnt < c ? cnt : c;
    
    lemma result_bounds:
        \forall integer a, b, c, k, na, nb, nc, cnt1, cnt2, cnt3;
        non_negative(a, b, c) && k_in_range(a, b, c, k) && sum_bounded(a, b, c) &&
        na == compute_na(a, k) && cnt1 == k - a &&
        nb == compute_nb(b, cnt1) && cnt2 == cnt1 - b &&
        nc == compute_nc(c, cnt2) && cnt3 == cnt2 - c ==>
        na - nc <= a + b + c && na - nc >= -a - c;
*/

/*@
    requires 0 <= a && 0 <= b && 0 <= c;
    requires 1 <= k && k <= a + b + c;
    requires a + b + c <= 2000000000;
    ensures \result <= a + b + c;
    ensures \result >= -a - c;
*/
int func(int a, int b, int c, int k)
{
    int cnt;
    int na;
    int nb;
    int nc;
    
    cnt = k;
    
    //@ assert cnt == k;
    
    if (cnt < a) {
        na = cnt;
    } else {
        na = a;
    }
    //@ assert na == (cnt < a ? cnt : a);
    
    cnt = cnt - a;
    //@ assert cnt == k - a;
    
    if (cnt < b) {
        nb = cnt;
    } else {
        nb = b;
    }
    //@ assert nb == (cnt < b ? cnt : b);
    
    cnt = cnt - b;
    //@ assert cnt == k - a - b;
    
    if (cnt < c) {
        nc = cnt;
    } else {
        nc = c;
    }
    //@ assert nc == (cnt < c ? cnt : c);
    
    cnt = cnt - c;
    //@ assert cnt == k - a - b - c;
    
    //@ assert na - nc <= a + b + c;
    //@ assert na - nc >= -a - c;
    
    return na - nc;
}
