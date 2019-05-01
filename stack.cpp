
#include "stack.h"

// Use this method for all your reallocations:

void stack::ensure_capacity( size_t c )
{
   if( current_capacity < c )
   {
      // New capacity will be the greater of c and
      // 2 * current_capacity.

      if( c < 2 * current_capacity )
         c = 2 * current_capacity;

      double* newdata = new double[ c ];
      for( size_t i = 0; i < current_size; ++ i )
         newdata[i] = data[i];

      current_capacity = c;
      delete[] data;
      data = newdata;
   }
}



