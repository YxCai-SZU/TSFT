/*@
    requires 1 <= a && a <= 9;
    requires 1 <= b && b <= 9;
    requires 1 <= c && c <= 9;
    ensures \result == 1 <==> ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
    ensures \result == 0 <==> !((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;
    
    if ((a < b && b < c) || (a > b && b > c)) {
        result = 1;
        //@ assert ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
    } else {
        //@ assert !((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
        result = 0;
    }
    
    return result;
}
