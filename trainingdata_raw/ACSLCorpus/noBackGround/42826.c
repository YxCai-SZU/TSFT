/*@
    requires (1 <= (N) <= 10000 && 1 <= (H) <= 10000);
    ensures \result >= 0 && \result <= N + H;
*/
int func(int N, int H)
{
    int result = 0;
    int remaining_height = H;
    int remaining_blocks = N;

    /*@
        loop invariant (0 <= (result) <= (N) + (H) &&
        0 <= (remaining_height) <= (H) &&
        0 <= (remaining_blocks) <= (N) &&
        (result) <= (N) + (H) - (remaining_height) - (remaining_blocks) &&
        (N) + (H) - (remaining_height) - (remaining_blocks) >= 0);
        loop assigns result, remaining_height, remaining_blocks;
        loop variant remaining_height + remaining_blocks;
    */
    while (remaining_height > 0 && remaining_blocks > 0)
    {
        //@ assert remaining_height > 0 && remaining_blocks > 0;
        remaining_height -= 1;
        
        //@ assert remaining_blocks > 0;
        result += 1;
        remaining_blocks -= 1;
    }

    //@ assert result >= 0 && result <= N + H;
    return result;
}
