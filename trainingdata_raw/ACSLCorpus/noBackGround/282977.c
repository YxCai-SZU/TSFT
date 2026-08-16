/*@ requires a > b || b > a;
    ensures \result == a || \result == b;
    ensures (((a) > (b) ==> (\result) == (a)) && ((a) <= (b) ==> (\result) == (b)));
*/
int max_ints(int a, int b)
{
    int result;
    
    if (a > b) {
        result = a;
        //@ assert result == a;
    } else {
        result = b;
        //@ assert result == b;
    }
    
    //@ assert result == a || result == b;
    return result;
}

int main() {
    return 0;
}
