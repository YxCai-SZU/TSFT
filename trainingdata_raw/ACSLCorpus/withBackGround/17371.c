/*@
    predicate is_even(integer n) = n % 2 == 0;
    logic integer half(integer n) = n / 2;
    
    lemma half_even: \forall integer n; is_even(n) ==> half(n) * 2 == n;
*/

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures (x < a ==> \result == 0) && (x >= a ==> \result == 10);
*/
unsigned long func(unsigned long x, unsigned long a)
{
    //@ assert 0 <= x <= 9;
    //@ assert 0 <= a <= 9;
    
    if (x < a) {
        //@ assert x < a;
        return 0;
    } else {
        //@ assert x >= a;
        return 10;
    }
}

/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    requires y % 2 == 0;
    ensures \result == x + y / 2;
*/
int func2(int x, int y)
{
    int half_y = 0;
    int i = 0;
    
    //@ assert is_even(y);
    //@ assert 0 <= x <= 100;
    //@ assert 0 <= y <= 100;
    
    /*@
        loop invariant 0 <= i <= y;
        loop invariant half_y * 2 == i;
        loop invariant 0 <= x <= 100;
        loop invariant 0 <= y <= 100;
        loop invariant is_even(y);
        loop assigns half_y, i;
    */
    while (i < y) {
        //@ assert i < y;
        half_y += 1;
        i += 2;
        //@ assert half_y * 2 == i;
    }
    
    //@ assert i == y;
    //@ assert half_y == half(y);
    return x + half_y;
}

int main() {
    return 0;
}
