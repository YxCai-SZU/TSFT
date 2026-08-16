/*@
predicate non_negative(integer v) = v >= 0;
predicate within_100(integer v) = v >= 0 && v <= 100;
predicate sum_within_100(integer a, integer b, integer c) = a + b + c <= 100;
predicate bounded_by_10(integer a, integer b) = a <= b && b <= a + 10;
predicate triple_bounded(integer a, integer b, integer c) = a <= b && b <= c && c <= a + 10;
predicate pair_sum_within_100(integer a, integer b) = a + b <= 100;
*/

/*@
lemma calc_example_3: \forall integer x, y, z, w; x <= y && y <= z && z <= w ==> x <= w;
lemma calc_example_4: \forall integer a, b, c; a <= b && b <= c ==> a <= c;
lemma calc_example_5: \forall integer n; 0 <= n && n <= 100 ==> 0 <= n && n <= 100;
lemma calc_example_6: \forall integer x; x >= 0 && x <= 100 ==> x >= 0 && x <= 100;
lemma calc_example_7: \forall integer a, b, c; a >= 0 && b >= 0 && c >= 0 && a + b + c <= 100 ==> a >= 0 && b >= 0 && c >= 0 && a + b + c <= 100;
lemma calc_example_8: \forall integer a, b; a <= b && b <= a + 10 ==> a <= b && b <= a + 10;
lemma calc_example_9: \forall integer a, b, c; a <= b && b <= c && c <= a + 10 ==> a <= b && b <= c && c <= a + 10;
lemma calc_example_10: \forall integer a, b; a >= 0 && b >= 0 && a + b <= 100 ==> a >= 0 && b >= 0 && a + b <= 100;
*/

/*@ requires x <= y && y <= z && z <= w;
    ensures x <= w;
*/
void calc_example_3(int x, int y, int z, int w)
{
    //@ assert x <= y;
    //@ assert y <= z;
    //@ assert z <= w;
    //@ assert x <= w;
}

/*@ requires a <= b && b <= c;
    ensures a <= c;
*/
void calc_example_4(int a, int b, int c)
{
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
}

/*@ requires 0 <= n && n <= 100;
    ensures 0 <= n && n <= 100;
*/
void calc_example_5(int n)
{
    //@ assert 0 <= n;
    //@ assert n <= 100;
}

/*@ requires x >= 0 && x <= 100;
    ensures x >= 0 && x <= 100;
*/
void calc_example_6(int x)
{
    //@ assert x >= 0;
    //@ assert x <= 100;
}

/*@ requires a >= 0 && b >= 0 && c >= 0 && a + b + c <= 100;
    ensures a >= 0 && b >= 0 && c >= 0 && a + b + c <= 100;
*/
void calc_example_7(int a, int b, int c)
{
    //@ assert a >= 0;
    //@ assert b >= 0;
    //@ assert c >= 0;
    //@ assert a + b + c <= 100;
}

/*@ requires a <= b && b <= a + 10;
    ensures a <= b && b <= a + 10;
*/
void calc_example_8(int a, int b)
{
    //@ assert a <= b;
    //@ assert b <= a + 10;
}

/*@ requires a <= b && b <= c && c <= a + 10;
    ensures a <= b && b <= c && c <= a + 10;
*/
void calc_example_9(int a, int b, int c)
{
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert c <= a + 10;
}

/*@ requires a >= 0 && b >= 0 && a + b <= 100;
    ensures a >= 0 && b >= 0 && a + b <= 100;
*/
void calc_example_10(int a, int b)
{
    //@ assert a >= 0;
    //@ assert b >= 0;
    //@ assert a + b <= 100;
}

int main() {
    return 0;
}
