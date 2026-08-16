/*@
    requires (1 <= (n) && (n) <= 100000 &&
        1 <= (k) && (k) <= 100000);
    ensures ((\result) >= 1 && (\result) <= (n) + (k) - 1);
    assigns \nothing;
*/
unsigned long func(unsigned long n, unsigned long k) {
    unsigned long f;
    unsigned long ans;
    unsigned long result;
    
    if (k == 1) {
        result = 1;
        //@ assert ((result) >= 1 && (result) <= (n) + (k) - 1);
        return result;
    } else {
        if (n <= k) {
            result = 1;
            //@ assert ((result) >= 1 && (result) <= (n) + (k) - 1);
            return result;
        } else {
            f = k - 1;
            ans = n - f;
            //@ assert ans >= 1;
            result = ans;
            //@ assert ((result) >= 1 && (result) <= (n) + (k) - 1);
            return result;
        }
    }
}

int main() {
    return 0;
}
