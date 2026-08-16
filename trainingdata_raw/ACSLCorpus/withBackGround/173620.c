/*@
    predicate valid_range(integer x) = 1 <= x && x <= 100;
    lemma mul3_bound: \forall integer x; valid_range(x) ==> x * 3 <= 300;
    lemma mul5_bound: \forall integer x; valid_range(x) ==> x * 5 <= 500;
    lemma mul7_bound: \forall integer x; valid_range(x) ==> x * 7 <= 700;
    lemma mul9_bound: \forall integer x; valid_range(x) ==> x * 9 <= 900;
    lemma mul11_bound: \forall integer x; valid_range(x) ==> x * 11 <= 1100;
    lemma mul13_bound: \forall integer x; valid_range(x) ==> x * 13 <= 1300;
    lemma mul15_bound: \forall integer x; valid_range(x) ==> x * 15 <= 1500;
    lemma mul17_bound: \forall integer x; valid_range(x) ==> x * 17 <= 1700;
    lemma mul19_bound: \forall integer x; valid_range(x) ==> x * 19 <= 1900;
    lemma mul21_bound: \forall integer x; valid_range(x) ==> x * 21 <= 2100;
*/

/*@
    requires valid_range(x);
    ensures \result == x * 3;
    assigns \nothing;
*/
int func(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 3 <= 300;
    int result = x * 3;
    return result;
}

/*@
    requires valid_range(x);
    ensures \result == x * 5;
    assigns \nothing;
*/
int func2(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 5 <= 500;
    int result = x * 5;
    return result;
}

/*@
    requires valid_range(x);
    ensures \result == x * 7;
    assigns \nothing;
*/
int func3(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 7 <= 700;
    int result = x * 7;
    return result;
}

/*@
    requires valid_range(x);
    ensures \result == x * 9;
    assigns \nothing;
*/
int func4(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 9 <= 900;
    int result = x * 9;
    return result;
}

/*@
    requires valid_range(x);
    ensures \result == x * 11;
    assigns \nothing;
*/
int func5(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 11 <= 1100;
    int result = x * 11;
    return result;
}

/*@
    requires valid_range(x);
    ensures \result == x * 13;
    assigns \nothing;
*/
int func6(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 13 <= 1300;
    int result = x * 13;
    return result;
}

/*@
    requires valid_range(x);
    ensures \result == x * 15;
    assigns \nothing;
*/
int func7(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 15 <= 1500;
    int result = x * 15;
    return result;
}

/*@
    requires valid_range(x);
    ensures \result == x * 17;
    assigns \nothing;
*/
int func8(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 17 <= 1700;
    int result = x * 17;
    return result;
}

/*@
    requires valid_range(x);
    ensures \result == x * 19;
    assigns \nothing;
*/
int func9(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 19 <= 1900;
    int result = x * 19;
    return result;
}

/*@
    requires valid_range(x);
    ensures \result == x * 21;
    assigns \nothing;
*/
int func10(int x)
{
    //@ assert valid_range(x);
    //@ assert x * 21 <= 2100;
    int result = x * 21;
    return result;
}
