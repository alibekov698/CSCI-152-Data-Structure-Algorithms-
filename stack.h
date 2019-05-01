
#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#include <iostream>
#include <initializer_list>

class stack
{
   size_t current_size;
   size_t current_capacity;

   double* data;
      // INVARIANТ: has been allocated with size current_capacity.
      // 0 <= current_size <= current_capacity.

   void ensure_capacity( size_t c );
      // Ensure that stack has capacity of at least c.
      // This function is given, so you don't have to write it.

public:
    stack( )
        : current_size{0},
        current_capacity{10},
        data{ new double[current_capacity] }
        // Constructs empty stack.
    {
        std::cout << "Default\n";
    }

    stack( const stack& s )
        : current_size{ s. current_size },
        current_capacity{ s. current_capacity},
        data{ new double[current_capacity] }
    {
        for( size_t i = 0; i != current_size; i++ )
            data[i] = s.data[i];
    }

    ~stack( )
    {
        delete[] data;
    }

    const stack& operator = ( const stack& s )
    {
        this->ensure_capacity(s. current_size);
        current_size = s.current_size;
        for( size_t i = 0; i != current_size; ++i)
            data[i] = s.data[i];
        return *this;
    }

    stack( std::initializer_list<double> init )
    {
      // So that you can write s = { 1,2,3 };
      // You can use init. size( ) to see the size, and
      // for( double d : init ) to go through all
      // elements in the initializer_list.
        current_size = init. size( );
        current_capacity = current_size * 2;
        data = new double[current_capacity];
        size_t i = 0;
        for( double d : init ){
            data[ i++ ]=d;
        }
    }

    void push( double d )
    {
        current_size++;
        this->ensure_capacity( current_size);
        data[current_size] = d;
    }

    void pop( )
    {
        if(current_size != 0)
            current_size --;
    }

    void clear( )
    {
        current_size = 0;
    }

    void reset( size_t s )
    {
        while(s < current_size)
        {
            current_size -- ;
        }
    }

    double peek( ) const
    {
         if(current_size != 0)
            return data[current_size];
    }

    size_t size( ) const
    {
        return current_size;
    }

    bool empty( ) const
    {
        if(current_size > 0){
            return 0;
        }
        else if(current_size == 0){
            return 1;
        }
    }

    friend std::ostream& operator << ( std::ostream& out, const stack& s)
    {
        for( size_t i = 0; i != s.current_size; ++ i )
            out << s.data[i];
        return out; // so that printing can coninue.
    }
};


#endif


