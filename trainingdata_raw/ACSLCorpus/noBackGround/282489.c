/*@
    requires l >= 0 && w >= 0 && h >= 0;
    ensures \result >= 0;
    ensures \result == ((l) <= 0 ? 0 : ((w) <= 0 ? 0 : ((h) <= 0 ? 0 : (l) * (w) * (h))));
*/
int compute_volume(int l, int w, int h) {
    int result;
    //@ assert l >= 0 && w >= 0 && h >= 0;
    if (l <= 0) {
        result = 0;
    } else if (w <= 0) {
        result = 0;
    } else if (h <= 0) {
        result = 0;
    } else {
        result = l * w * h;
    }
    //@ assert result == ((l) <= 0 ? 0 : ((w) <= 0 ? 0 : ((h) <= 0 ? 0 : (l) * (w) * (h))));
    //@ assert result >= 0;
    return result;
}

int main() {
    int vol;
    //@ assert ((4) <= 0 ? 0 : ((5) <= 0 ? 0 : ((6) <= 0 ? 0 : (4) * (5) * (6)))) >= 0;
    vol = compute_volume(4, 5, 6);
    //@ assert vol >= 0;
    return 0;
}
