/*@
    requires (1 <= (input) && (input) <= 32);
    ensures ((\result) > 0 &&
        ((\result) == 1 || (\result) == 2 || (\result) == 5 || (\result) == 14 || (\result) == 15 || (\result) == 51 || (\result) == 4));
*/
long func(long input)
{
    long arr[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    long result;
    
    //@ assert (1 <= (input) && (input) <= 32);
    //@ assert ((input) == 1 ? 1 :         (input) == 2 ? 1 :         (input) == 3 ? 1 :         (input) == 4 ? 2 :         (input) == 5 ? 1 :         (input) == 6 ? 2 :         (input) == 7 ? 1 :         (input) == 8 ? 5 :         (input) == 9 ? 2 :         (input) == 10 ? 2 :         (input) == 11 ? 1 :         (input) == 12 ? 5 :         (input) == 13 ? 1 :         (input) == 14 ? 2 :         (input) == 15 ? 1 :         (input) == 16 ? 14 :         (input) == 17 ? 1 :         (input) == 18 ? 5 :         (input) == 19 ? 1 :         (input) == 20 ? 5 :         (input) == 21 ? 2 :         (input) == 22 ? 2 :         (input) == 23 ? 1 :         (input) == 24 ? 15 :         (input) == 25 ? 2 :         (input) == 26 ? 2 :         (input) == 27 ? 5 :         (input) == 28 ? 4 :         (input) == 29 ? 1 :         (input) == 30 ? 4 :         (input) == 31 ? 1 :         51) == arr[input-1];
    
    result = arr[input - 1];
    return result;
}
