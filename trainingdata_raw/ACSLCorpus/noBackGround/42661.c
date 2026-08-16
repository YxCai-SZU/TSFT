/*@
    requires (1 <= (X) && (X) <= 100000) && (1 <= (Y) && (Y) <= 100000);
    ensures ((\result) >= (X)) && ((\result) >= (Y) / 2) && ((\result) == (X) + (Y) / 2);
*/
unsigned int func(unsigned int X, unsigned int Y) {
    unsigned int cost;
    unsigned int YMut;
    unsigned int count;

    cost = X;
    YMut = Y;
    count = 0;

    /*@
        loop invariant 1 <= X && X <= 100000;
        loop invariant 1 <= Y && Y <= 100000;
        loop invariant YMut >= 0;
        loop invariant count >= 0;
        loop invariant YMut + 2 * count == Y;
        loop assigns YMut, count;
        loop variant YMut;
    */
    while (YMut >= 2) {
        //@ assert YMut >= 2;
        YMut -= 2;
        count += 1;
    }

    cost += count;
    //@ assert cost == X + Y / 2;
    return cost;
}
