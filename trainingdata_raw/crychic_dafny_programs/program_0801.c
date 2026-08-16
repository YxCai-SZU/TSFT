// Generated C + ACSL

/*@
  predicate Valid(integer currentSize, integer size, integer currentPtr,
                  integer nTransitionsStored, integer sizeInTransitions,
                  integer timeHorizon) =
    currentSize <= size && currentPtr <= size &&
    nTransitionsStored <= sizeInTransitions &&
    size * timeHorizon == sizeInTransitions &&
    timeHorizon > 0 && size > 0;
*/

/*@
    requires sizeIncrement > 0;
    requires sizeIncrement <= size;
    requires \valid(currentSize);
    requires \valid(currentPtr);
    requires *currentSize >= 0 && *currentSize <= size;
    requires *currentPtr >= 0 && *currentPtr <= size;
    assigns *currentSize, *currentPtr;
    ensures \result == \null || \valid(\result);
*/
int* GetStorageIdx(int sizeIncrement, int* currentSize, int size, int* currentPtr)
{
  int* result = 0;
  if (((*currentSize + sizeIncrement) <= size))
  {
    int i = *currentSize;
/*@
  loop invariant *currentSize <= i <= *currentSize + sizeIncrement;
  loop invariant \at(*currentSize, LoopEntry) == *currentSize;
  loop invariant \at(sizeIncrement, LoopEntry) == sizeIncrement;
  loop assigns i;
  loop variant (*currentSize + sizeIncrement) - i;
*/
    while ((i < (*currentSize + sizeIncrement)))
      {
        i = (i + 1);
      }
    *currentSize = (*currentSize + sizeIncrement);
    /*@ assert *currentSize >= 0 && *currentSize <= size; */
  }
  else
  if ((*currentSize < size))
  {
    int remainingSpace = (size - *currentSize);
    int overflow = (sizeIncrement - remainingSpace);
    /*@ assert overflow <= sizeIncrement && sizeIncrement <= size; */
    int i = *currentSize;
/*@
  loop invariant *currentSize <= i <= size;
  loop invariant \at(*currentSize, LoopEntry) <= i <= \at(*currentSize, LoopEntry) + sizeIncrement;
  loop invariant i - \at(*currentSize, LoopEntry) >= 0;
  loop assigns i;
  loop variant size - i;
*/
    while ((i < size))
      {
        i = (i + 1);
      }
    i = 0;
/*@
  loop invariant 0 <= i <= overflow;
  loop invariant overflow <= size;
  loop assigns i;
  loop variant overflow - i;
*/
    while ((i < overflow))
      {
        i = (i + 1);
      }
    *currentSize = size;
    *currentPtr = overflow;
    /*@ assert *currentPtr >= 0 && *currentPtr <= size; */
  }
  else
  {
    if (((*currentPtr + sizeIncrement) <= size))
    {
      int i = *currentPtr;
/*@
  loop invariant *currentPtr <= i <= *currentPtr + sizeIncrement;
  loop invariant \at(i, LoopEntry) <= i;
  loop invariant *currentPtr + sizeIncrement <= size;
  loop assigns i;
  loop variant (*currentPtr + sizeIncrement) - i;
*/
      while ((i < (*currentPtr + sizeIncrement)))
        {
          i = (i + 1);
        }
      *currentPtr = (*currentPtr + sizeIncrement);
    }
    else
    {
      int remainingSpace = (size - *currentPtr);
      int overflow = (sizeIncrement - remainingSpace);
      /*@ assert overflow <= sizeIncrement && sizeIncrement <= size; */
      int i = *currentPtr;
/*@
  loop invariant *currentPtr <= i <= size;
  loop assigns i;
  loop variant size - i;
*/
      while ((i < size))
        {
          i = (i + 1);
        }
      i = 0;
/*@
  loop invariant 0 <= i <= overflow;
  loop invariant overflow <= size;
  loop assigns i;
  loop variant overflow - i;
*/
      while ((i < overflow))
        {
          i = (i + 1);
        }
      *currentPtr = overflow;
    }
  }
  int* idx = result;
  return idx;
}

/*@
  predicate IsFull(integer currentSize, integer size) =
    currentSize == size;
*/