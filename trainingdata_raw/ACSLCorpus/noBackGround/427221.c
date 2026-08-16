/*@
    requires 1 <= k <= 100 && 1 <= x <= 100;
    ensures \result == (((k) % 2 == 0) ?
            (((x) % 2 == 0) ? (x) : 0)
        :
            (((x) % 2 != 0) ? 1 : 0));
*/
int func(int k, int x)
{
    //@ assert (((k) % 2 == 0)) || (((k) % 2 != 0));
    //@ assert (((x) % 2 == 0)) || (((x) % 2 != 0));
    
    if (k % 2 == 0) {
        if (x % 2 == 0) {
            //@ assert k % 2 == 0 && x % 2 == 0;
            return x;
        } else {
            //@ assert k % 2 == 0 && x % 2 != 0;
            return 0;
        }
    } else {
        if (x % 2 != 0) {
            //@ assert k % 2 != 0 && x % 2 != 0;
            return 1;
        } else {
            //@ assert k % 2 != 0 && x % 2 == 0;
            return 0;
        }
    }
}

int main() {
    return 0;
}
