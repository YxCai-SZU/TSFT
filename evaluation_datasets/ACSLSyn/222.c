#include <stdbool.h>

/* Original functions with their specifications */

/*@
    predicate condition(integer x, integer y, integer z) =
        (x == 5 && (y == 5 || z == 5 || (y == 4 && z == 4))) ||
        (y == 5 && (x == 5 || z == 5 || (x == 4 && z == 4))) ||
        (z == 5 && (x == 5 || y == 5 || (x == 4 && y == 4)));
*/

bool func1(unsigned int x, unsigned int y, unsigned int z)
{
    bool r = false;

    //@ assert 1 <= x <= 5 && 1 <= y <= 5 && 1 <= z <= 5;

    if (x == 5) {
        if (y == 5 || z == 5) {
            r = true;
        } else if (y == 4 && z == 4) {
            r = true;
        }
    } else if (y == 5) {
        if (x == 5 || z == 5) {
            r = true;
        } else if (x == 4 && z == 4) {
            r = true;
        }
    } else if (z == 5) {
        if (x == 5 || y == 5) {
            r = true;
        } else if (x == 4 && y == 4) {
            r = true;
        }
    }

    //@ assert r == 1 <==> condition(x, y, z);

    return r;
}

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

bool func2(int x, int y, int z)
{
    bool result;

    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    //@ assert 1 <= z <= 100;
    //@ assert y - x >= -99 && y - x <= 99;
    //@ assert z - y >= -99 && z - y <= 99;

    if ((y - x == z - y) && y != z) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

/* 
 * Scenario: Dice game scoring system
 * In a dice game, three dice are rolled with values 1-5.
 * The first function checks for special combinations (triples, pairs).
 * The second function checks if the values form an arithmetic progression (but not all equal).
 * The synthesized function determines if a player gets a bonus round.
 * A bonus round is awarded when the dice form a special combination AND an arithmetic progression,
 * or when no special combination exists but the values form a valid arithmetic progression.
 */

/*@
    predicate bonus_condition(integer x, integer y, integer z) =
        (condition(x, y, z) && (y - x == z - y) && y != z) ||
        (!condition(x, y, z) && (y - x == z - y) && y != z);
*/

bool bonus_round(unsigned int x, unsigned int y, unsigned int z)
{
    bool special = false;
    bool arithmetic = false;

    special = func1(x, y, z);
    //@ assert special == 1 <==> condition(x, y, z);

    arithmetic = func2((int)x, (int)y, (int)z);
    //@ assert arithmetic == 1 <==> ((y - x == z - y) && y != z);

    bool bonus = false;
    if (special && arithmetic) {
        bonus = true;
    } else if (!special && arithmetic) {
        bonus = true;
    }

    //@ assert (bonus == 1) <==> bonus_condition(x, y, z);

    return bonus;
}
