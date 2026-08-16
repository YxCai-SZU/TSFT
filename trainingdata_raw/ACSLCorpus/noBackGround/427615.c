/*@
    requires (-40 <= (x) && (x) <= 40);
    ensures (((\result) != 0) <==> (x) >= 30);
    assigns \nothing;
*/
int func(int x) {
    int result;
    
    if (x < 30) {
        result = 0;
    } else {
        result = 1;
    }
    
    return result;
}

/*@
    requires (1 <= (n) && (n) <= 10000 &&
        1 <= (k) && (k) <= 10000 &&
        1 <= (y) && (y) < (x) && (x) <= 10000);
    ensures ((\result) >= 0 &&
        ((\result) == (n) * (x) || (\result) == (k) * (x) + ((n) - (k)) * (y)));
    assigns \nothing;
*/
int func2(int n, int k, int x, int y) {
    int result;
    
    if (n < k) {
        //@ assert n * x >= 0;
        result = n * x;
    } else {
        //@ assert k * x + (n - k) * y >= 0;
        result = k * x + (n - k) * y;
    }
    
    return result;
}
