/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        1 <= (x) <= (n) - 1);
    requires m >= 0;
    requires \valid(numbers + (0 .. m-1));
    requires (\forall integer i; 0 <= i < (m) ==> (((numbers)[i]) >= 1 && ((numbers)[i]) <= ((n)) && ((numbers)[i]) != ((x))));
    ensures \result >= 0;
    ensures \result <= m;
*/
int func(int n, int m, int x, int* numbers) {
    int l = 0;
    int r = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= l <= i;
        loop invariant (\forall integer i; 0 <= i < (m) ==> (((numbers)[i]) >= 1 && ((numbers)[i]) <= ((n)) && ((numbers)[i]) != ((x))));
        loop invariant (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        1 <= (x) <= (n) - 1);
        loop invariant \forall integer j; 0 <= j < i ==> numbers[j] < x;
        loop assigns i, l;
        loop variant m - i;
    */
    while (i < m && numbers[i] < x) {
        //@ assert numbers[i] >= 1 && numbers[i] <= n && numbers[i] != x;
        l += 1;
        i += 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= r <= i;
        loop invariant (\forall integer i; 0 <= i < (m) ==> (((numbers)[i]) >= 1 && ((numbers)[i]) <= ((n)) && ((numbers)[i]) != ((x))));
        loop invariant (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        1 <= (x) <= (n) - 1);
        loop invariant \forall integer j; 0 <= j < i ==> numbers[j] > x;
        loop assigns i, r;
        loop variant m - i;
    */
    while (i < m && numbers[i] > x) {
        //@ assert numbers[i] >= 1 && numbers[i] <= n && numbers[i] != x;
        r += 1;
        i += 1;
    }

    int min_val = (l < r) ? l : r;
    //@ assert min_val >= 0 && min_val <= m;
    return min_val;
}
