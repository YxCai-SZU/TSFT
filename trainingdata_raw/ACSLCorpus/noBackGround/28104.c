/*@
    requires (((a) == 1 && (b) == 2) || ((a) == 1 && (b) == 3) || ((a) == 2 && (b) == 1) ||
        ((a) == 2 && (b) == 3) || ((a) == 3 && (b) == 1) || ((a) == 3 && (b) == 2));
    ensures (((\result) == 1 && (a) != 1 && (b) != 1) ||
        ((\result) == 2 && (a) != 2 && (b) != 2) ||
        ((\result) == 3 && (a) != 3 && (b) != 3));
    assigns \nothing;
*/
int func(int a, int b)
{
    int res = 6;
    
    //@ assert res == 6;
    
    if (a == 1) {
        res = res - 1;
    }
    if (a == 2) {
        res = res - 2;
    }
    if (a == 3) {
        res = res - 3;
    }
    if (b == 1) {
        res = res - 1;
    }
    if (b == 2) {
        res = res - 2;
    }
    if (b == 3) {
        res = res - 3;
    }
    
    //@ assert res == 6 - a - b;
    //@ assert (((res) == 1 && (a) != 1 && (b) != 1) ||         ((res) == 2 && (a) != 2 && (b) != 2) ||         ((res) == 3 && (a) != 3 && (b) != 3));
    
    return res;
}
