#include <stdbool.h>

/*@ requires ((A0) == 0 &&
    (A1) >= 0 && (A2) >= 0 && (A3) >= 0 && (A4) >= 0 &&
    (A1) <= 123 && (A2) <= 123 && (A3) <= 123 && (A4) <= 123 &&
    (K) >= 0 && (K) <= 123);
    ensures \result == (A4 - A0 <= K);
*/
bool func(long A0, long A1, long A2, long A3, long A4, long K) {
    long array[5];
    int i;
    i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> array[j] == ((j) == 0 ? (A0) :
    (j) == 1 ? (A1) :
    (j) == 2 ? (A2) :
    (j) == 3 ? (A3) :
    (A4));
        loop invariant ((A0) == 0 &&
    (A1) >= 0 && (A2) >= 0 && (A3) >= 0 && (A4) >= 0 &&
    (A1) <= 123 && (A2) <= 123 && (A3) <= 123 && (A4) <= 123 &&
    (K) >= 0 && (K) <= 123);
        loop assigns i, array[0..4];
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert i >= 0 && i < 5;
        if (i == 0) array[i] = A0;
        else if (i == 1) array[i] = A1;
        else if (i == 2) array[i] = A2;
        else if (i == 3) array[i] = A3;
        else array[i] = A4;
        i++;
    }
    
    long first = array[0];
    long last = array[4];
    
    //@ assert first == A0;
    //@ assert last == A4;
    //@ assert ((A0) == 0 &&     (A1) >= 0 && (A2) >= 0 && (A3) >= 0 && (A4) >= 0 &&     (A1) <= 123 && (A2) <= 123 && (A3) <= 123 && (A4) <= 123 &&     (K) >= 0 && (K) <= 123);
    
    return last - first <= K;
}

int main() {
    return 0;
}
