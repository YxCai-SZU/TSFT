// Generated C + ACSL

// Structure definitions for pitbog and flamechick
struct Pokemon {
  int hp;
  int speed;
  int attack;
  int defence;
  int special_defence;
  int special_attack;
};

/*@
  predicate Valid(struct Pokemon *p) =
    \valid(p) &&
    p->hp >= 0 && p->speed >= 0 && p->attack >= 0 && 
    p->defence >= 0 && p->special_defence >= 0 && p->special_attack >= 0;
*/

/*@
    assigns \nothing;
*/
void Main(void)
{
  struct Pokemon pitbog = {50, 0, 70, 0, 0, 0};
  struct Pokemon flamechick = {45, 0, 0, 0, 0, 70};
  
  /*@ assert (pitbog.hp == 50); */
  /*@ assert (pitbog.attack == 70); */
  /*@ assert (flamechick.hp == 45); */
  /*@ assert (flamechick.special_attack == 70); */
  /*@ assert Valid(&pitbog); */
  /*@ assert Valid(&flamechick); */
}