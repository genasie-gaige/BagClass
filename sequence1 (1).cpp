
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "sequence1.h"  // With value_type defined as double
using namespace std;
using namespace main_savitch_3;


//Post-condition: sequence.used is set to zero in order to initialize as empty
sequence::sequence( )
{
    used = 0;
    current_index = -1; //set current_index out of bounds until it is initialized
}

//if sequence is not empty then set current_index to first item
void sequence::start( ) 
{
    if(used != 0)
        current_index = 0; //initialized current_index within bounds
}

//precondition: assert that is_item() = true
//postcondition: if current_index is less than used then advance 
//               current_index one place else set current_index out of bounds;
void sequence::advance( )
{
    assert(is_item() == true);
    if(current_index < used - 1)
        current_index++;
    else
        current_index = -1;
        
}

//precondidtion: assert size() < cpacity
//postcondition: create new entry before current_index or at beginning of list
void sequence::insert(const value_type& entry)
{
    assert(size() < CAPACITY);
    size_type new_spot;
    
    if(is_item() == false){
        data[used] = entry;
        current_index = used;
    } else {
        
        if(current_index == 0){
            new_spot = 0;
        }else{
            new_spot = current_index--;
        }
        
        current_index = used;  //sets current_index to next available spot
        while(current_index > new_spot){   
            data[current_index] = data[current_index - 1];  //moves every entry over one space
            current_index--;
        }
        
        data[new_spot] = entry; 
        current_index = new_spot;
    }
    used++;
}

//precondidtion: assert size() < cpacity
//postcondition: create new entry after current_index or at end of list
void sequence::attach(const value_type& entry)
{
    assert(size() < CAPACITY);
    size_type new_spot;
    
    if(is_item() == false || current_index == used - 1){
        data[used] = entry;
        current_index = used;
        
    } else {
        new_spot = current_index + 1;
        current_index = used;  //sets current_index to next available spot
        while(current_index > new_spot){   
            data[current_index] = data[current_index - 1];  //moves every entry over one space
            current_index--;
            }
            
        data[new_spot] = entry; 
        current_index = new_spot;
    }
    used++;
}

//precondition: is_item() == true
//postcondition: remove current_index and replace with next entry
void sequence::remove_current( )
{
    assert(is_item() == true);
    while(current_index < used - 1){
        data[current_index] = data[current_index + 1];
        current_index++;
    }
    used--;
}

//Postcondition: returns number of items in bag
sequence::size_type sequence::size( ) const
{
    return used;
}

//postcondition: asserts that current_index is within bounds
bool sequence::is_item( ) const
{
    if(current_index != -1)
        return true;
    else 
        return false;
}

//precondition: is_item() is true
//postcondition: return value at current_index
sequence::value_type sequence::current( ) const
{
    assert(is_item() == true);
    return data[current_index];
}