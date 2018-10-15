// Sequence.cpp
// Implementation file for Sequence Class

// Name: Od Ganzorig
// Date: 01/30/2018

// The private instance variables of the Sequence class are:
//    value_type data[CAPACITY] -- an array for storing the items
//    size_type length          -- current number of items
//    size_type current_index   -- index of the current item
//       current_index implements the following idea: you can have your
//       index finger on a specific item in the sequence.
//
// CAPACITY is given a specific value in the header file at compile time.
//    Always refer to the capacity of the sequence by name `CAPACITY` in
//    your implementation; never use the actual number value of CAPACITY.
//
// CLASS INVARIANT: The current_index will always satisfy one of the
//    following two conditions:
//    1. 0 <= current_index < length.  In this case, there is a current
//       item, data[current_index].  is_item() returns true in this case.
//    2. current_index == length.  In this case, this is NO current item.
//       is_item() returns false in this case.
//

#include <cstdlib>
#include <iostream>
#include <cassert>
#include "Sequence.h"

using namespace std;

namespace main_savitch_3
{
/*************************** PART 1 IMPLEMENTATIONS ***********************/
// CONSTRUCTOR for the Sequence class
// Postcondition: The sequence has been initialized as an empty sequence.
Sequence::Sequence()
{
    length = 0;
    current_index = 0;
}

// CONSTANT MEMBER FUNCTIONS for the Sequence class:

// size
// Postcondition: The return value is the length of the sequence.
Sequence::size_type Sequence::size() const
{
    return length;
}

// is_item
// Postcondition: A `true` return value indicates that there is a valid
//    current item that may be retrieved by activating the `current`
//    member function (see below). A `false` return value indicates that
//    there is no valid current item.
bool Sequence::is_item() const
{
    return current_index != length;
    

}

// current
// Precondition: is_item() returns true (there is a current item).
// Postcondition: The item returned is the current item in the Sequence.
Sequence::value_type Sequence::current() const
{
    if (is_item())
    return data[current_index];
}

// MODIFICATION MEMBER FUNCTIONS

// start
// Postcondition: The sequence of items is not modified.
// Postcondition: If the sequence is not empty, the first item in the
//    sequence is the current item.
void Sequence::start()
{
    current_index = 0;
    

}

// advance
// Precondition: is_item() returns true (there is a current item).
// Postcondition: The sequence of items is not modified.
// Postcondition: If the current item was already the last item in the
//    sequence, then there is no longer a current item; otherwise, the new
//    current item is the item immediately after the original current item.
// Example: If the sequence is (p, i, g) with current item p, then after
//    a call to advance() the sequence is (p, i, g) with current item i.
void Sequence::advance()
{
    if (is_item())
    current_index++;
        
}

// append
// Precondition: size() < CAPACITY.
// Postcondition: The provided value, `entry`, has been placed at the end
//    of the sequence. The newly appended item is now the current item of
//    the sequence.
// Example: If the sequence is (p, i, g) with current item i, then after
//    a call to append('s') the sequence is (p, i, g, s) with current item s.
// Example: If the sequence is (c, a, t) with NO CURRENT ITEM, then after
//    a call to append('!') the sequence is (c, a, t, !) with current item !.
void Sequence::append(const value_type& entry)
{
    if (size() < CAPACITY)
    {
        data[length] = entry;
        length++;
        current_index = length-1;
    }

}

// insert
// Precondition: size() < CAPACITY.
// Postcondition: The provided value, `entry`, has been inserted into the
//    sequence BEFORE the current item. If there was no current item, then
//    the new entry has been inserted at the FRONT of the sequence. In either
//    case, the newly inserted item is now the current item of the sequence.
// Example: If the sequence is (c, a, t, !) with current item !, then after
//    a call to insert('Z') the sequence is (c, a, t, Z, !) with current item Z.
// Example: If the sequence is (X, Y) with NO CURRENT ITEM, then after
//    a call to insert('K') the sequence is (K, X, Y) with current item K.
void Sequence::insert(const value_type& entry)
{
    if (size() < CAPACITY)
    {
        for (int i = length; i > current_index; i--)
        {
            data[i] = data[i-1];
        }
        data[current_index] = entry;
        length++;

    if (!is_item())
    current_index = 0;
    }

}

// remove_current
// Precondition: is_item returns true (there is a current item).
// Postcondition: The current item has been removed from the sequence, and
//    the item that was immediately to the right of current (if there was one)
//    is now the new current item.
// Example: If the sequence is (K, X, Y) with current item X, then after
//    a call to remove_current() the sequence is (K, Y) with current item Y.
// Example: If the sequence is (i, n, d, i, a, n, A) with current item A,
//    then after a call to remove_current() the sequence is (i, n, d, i, a, n)
//    with no current item.
void Sequence::remove_current()
{
    if (is_item())
    for (int i = current_index; i < length; i++)
        {   
            data[i] = data[i+1];   
        }
        length--;

}

// OPERATOR OVERLOADS

// equivalence operator (==)
// seqA and seqB are "equal" iff they have:
//      - the same size
//      - the same items, and *in the same order*
// Example: Sequence (d, o, g) with current_index 1 and sequence (d, o, g)
//    with current_index 2 are equal.  (The current_index is irrelevant for
//    determining equality of sequences.)
bool operator==(const Sequence& seqA, const Sequence& seqB)
{
    if (seqA.size() != seqB.size())
    return false;
    for (int i = 0; i < seqA.size(); i++)
    {
        if (seqA.data[i] != seqB.data[i])
        return false;
    }
    return true;        
    
            
}

// inequivalence operator (!=)
// logical opposite of the == operator
bool operator!=(const Sequence& seqA, const Sequence& seqB)
{
    return !(seqA == seqB); 
}

// increment operator (+=)
// Precondition: this.length + otherSeq.length <= Sequence::CAPACITY
// Postcondition: This sequence is modified by appending the items of otherSeq.
// Postcondition: the index of the current item for this sequence is unchanged
// NOTE: += is a class member, not a friend.
void Sequence::operator+=(const Sequence& otherSeq)
{
    if (length + otherSeq.length <= Sequence::CAPACITY)
    copy (otherSeq.data, otherSeq.data + otherSeq.length, data + length);
    length += otherSeq.length;

}

// *** implementation provided ***
// stream output operator (<<)
// Example:  A sequence (c, o, w, s) with current item w would produce the
//    following output:
//      sequence: c o w s
// Example:  An empty sequence () would produce the following output:
//      sequence: <empty sequence>
// FOLLOWED BY A NEWLINE
// note: returns the `out` parameter to allow chaining of stream output
// note: get the spacing exactly right
ostream& operator<<(ostream& out, const Sequence& seq)
{
    out << "Sequence:";
    for (int i = 0; i < seq.size(); i++)
    {
        out << " " << seq.data[i];
    }
    if (seq.size() == 0)
    {
        out << " <empty sequence>\n";
    }

    return out;
}

// *** implementation provided ***
// friend istream& operator>>(istream& in, Sequence& seq)
// stream input operator, for modifying a sequence by reading an input stream
// Precondition:  `in` holds a string in the exact format produced by <<
//    (see above), FOLLOWED BY A NEWLINE CHARACTER '\n'
// Postcondition: s1 will hold the items listed in the input stream
// Postcondition: s1 will have its first item as the current item, unless
//    s1 is an empty sequence (in which case there is no current item)
// Example: if the input stream `in` holds the message,
//     "Sequence: c o w s\n"
//    then `in >> s1` will cause s1 to be modified: s1 will have length = 4,
//    items (c, o, w, s), and current item c.
// note: returns the `in` parameter to allow chaining of stream input
istream& operator>>(istream& in, Sequence& seq)
{
    // "empty out" the contents of seq
    seq.length = 0;
    seq.current_index = 0;

    // read from in with getline
    string line;
    getline(in, line, '\n');
    // cout << "The line i read is: " << line << endl;
    // cout << "The char at position 10 is: " << line[10] << endl;

    // append chars to seq, if any
    if (line[10] != '<')
    {
        for (int i = 10; i < line.size(); i += 2)
        {
            seq.append(line[i]);
        }
        seq.current_index = 0;
    }

    return in;
}

}  // namespace main_savitch_3