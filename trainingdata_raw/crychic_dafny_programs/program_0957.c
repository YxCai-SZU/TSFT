// Generated C + ACSL

typedef struct {
    int memberAccess;
} Place;

#define OH 0

/*@
    requires place != \null;
    assigns place->memberAccess;
*/
void AlterMemberAccess(Place* place, int newAccess)
{
  place->memberAccess = newAccess;
}

/*@
    requires places != \null;
    requires places_len >= 0;
    requires \valid(places + (0 .. places_len-1));
    assigns places[0 .. places_len-1].memberAccess;
*/
void MigratePlaces(Place* places, int places_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= places_len;
  loop invariant \forall integer k; 0 <= k < i ==> places[k].memberAccess == OH;
  loop assigns i, places[0..places_len-1].memberAccess;
  loop variant places_len - i;
*/
  while ((i < places_len))
    {
      places[i].memberAccess = OH;
      i = (i + 1);
    }
}