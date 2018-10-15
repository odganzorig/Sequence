// Sequence_tests.cpp
// Unit tests for Sequence class, CS 223 Lab 2

// Name: Od Ganzorig
// Date: 01/30/2018

#include <sstream>
#include <iostream>
#include <string>
#include "Sequence.h"
#include "gtest/gtest.h"  // declares the testing framework

using namespace std;
using namespace main_savitch_3;

namespace {

static const size_t CAPACITY = main_savitch_3::Sequence::CAPACITY;

// constructor, size, is_item (test provided)

TEST(TestConstructorAndGetters, DefaultConstructor)
{
    Sequence s1;
    EXPECT_EQ(0, s1.size());
    EXPECT_FALSE(s1.is_item());
}

// You are responsible for writing the tests listed below.

// Each test should be written one at a time as you go through
// the Test-Driven Development (TDD) process.

// USE THE PROVIDED NAMES for the Google test cases (e.g., "TestSequenceAppend")
// and individual tests (e.g., "Append_To_Empty").  Within this file, tests
// should be implemented in the given order.

// ** Do not rearrange the order of the testing code in this file. **

/*
TestSequenceAppend
  - Append_to_Empty
  - Append_to_Length_1 <<== PROVIDED
  - Append_to_Length_2
  - Append_until_Filled_to_Capacity
*/

TEST(TestSequenceAppend, Append_to_Empty)
{
    Sequence s1;
    s1.append('c');
    EXPECT_EQ(s1.size(), 1);
    EXPECT_TRUE(s1.is_item());
    EXPECT_EQ(s1.current(), 'c');
}

TEST(TestSequenceAppend, Append_To_Length_1)
{
    Sequence s1;
    s1.append('c');
    s1.append('a');
    EXPECT_EQ(s1.size(), 2);
    EXPECT_TRUE(s1.is_item());
    EXPECT_EQ(s1.current(), 'a');
}

TEST(TestSequenceAppend, Append_to_Length_2)
{
    Sequence s1;
    s1.append('c');
    s1.append('a');
    s1.append('b');
    EXPECT_EQ(s1.size(), 3);
    EXPECT_TRUE(s1.is_item());
    EXPECT_EQ(s1.current(), 'b');
}

TEST(TestSequenceAppend, Append_until_Filled_to_Capacity)
{
    Sequence s1;
    for (int i=0; i<CAPACITY-1; i++)
    {
        s1.append('c');
    }
    s1.append('z');
    EXPECT_EQ(s1.size(), CAPACITY);
    EXPECT_TRUE(s1.is_item());
    EXPECT_EQ(s1.current(), 'z');
}

/*
TestSequenceAdvanceANDStart
  - Advance_CurrentIndex_from_Start_to_End <<== PROVIDED
  - Advance_Some_then_Call_Start
*/

TEST(TestSequenceAdvanceANDStart, Advance_CurrentIndex_from_Start_to_End)
{
    Sequence s1;
    s1.append('c');
    s1.append('a');
    s1.append('t');
    s1.append('!');
    s1.start();
    EXPECT_EQ(s1.current(), 'c');
    s1.advance();
    EXPECT_EQ(s1.current(), 'a');
    s1.advance();
    EXPECT_EQ(s1.current(), 't');
    s1.advance();
    EXPECT_EQ(s1.current(), '!');
}

TEST(TestSequenceAdvanceANDStart, Advance_Some_then_Call_Start)
{
    Sequence s1;
    s1.append('c');
    s1.append('a');
    s1.append('t');
    s1.append('!');
    EXPECT_EQ(s1.current(), '!');
    s1.start();
    EXPECT_EQ(s1.current(), 'c');
    s1.advance();
    EXPECT_EQ(s1.current(), 'a');
    s1.advance();
    EXPECT_EQ(s1.current(), 't');
    s1.start();                      // call start again
    EXPECT_EQ(s1.current(), 'c');
}



/*
TestSequenceInsert
  - Insert_into_Empty
  - Insert_into_Length_1_CurrentIndex_0
  - Insert_into_Length_1_CurrentIndex_1
  - Insert_into_Length_5_CurrentIndex_0 <<== PROVIDED
  - Insert_into_Length_5_CurrentIndex_2
  - Insert_into_Length_5_CurrentIndex_4
  - Insert_into_Length_5_CurrentIndex_5
  - Insert_into_Length_CAPACITYminus1_CurrentIndex_CAPACITYminus2 <<== PROVIDED
  - Insert_into_Length_CAPACITYminus1_CurrentIndex_0 <<== PROVIDED
*/

TEST(TestSequenceInsert, Insert_into_Empty)
{
    Sequence s1;
    s1.insert('Z');
    EXPECT_EQ(s1.size(), 1);
    EXPECT_TRUE(s1.is_item());
    ASSERT_EQ(s1.current(), 'Z');
}


TEST(TestSequenceInsert, Insert_into_Length_1_CurrentIndex_0)
{
    Sequence s1;
    s1.append('c');
    s1.insert('Z');
    ASSERT_EQ(s1.current(), 'Z');
    ASSERT_EQ(s1.size(), 2);
    s1.advance();
    EXPECT_EQ(s1.current(), 'c');
    s1.start();
    EXPECT_EQ(s1.current(), 'Z');

}

TEST(TestSequenceInsert, Insert_into_Length_1_CurrentIndex_1)
{
    Sequence s1;
    s1.append('c');
    s1.insert('Z');
    ASSERT_EQ(s1.size(), 2);
    s1.advance();
    EXPECT_EQ(s1.current(), 'c'); // current index 1
    s1.insert('P');
    ASSERT_EQ(s1.size(), 3);
    ASSERT_EQ(s1.current(), 'P');
    s1.advance();
    EXPECT_EQ(s1.current(), 'c');
    s1.start();
    EXPECT_EQ(s1.current(), 'Z');

}


TEST(TestSequenceInsert, Insert_Into_Length_5_CurrentIndex_0)
{
    Sequence s1;
    s1.append('c');
    s1.append('h');
    s1.append('a');
    s1.append('i');
    s1.append('r');
    s1.start();
    s1.insert('Z');
    ASSERT_EQ(s1.current(), 'Z');
    ASSERT_EQ(s1.size(), 6);
    s1.advance();
    ASSERT_EQ(s1.current(), 'c');
    s1.advance();
    s1.advance();
    s1.advance();
    s1.advance();
    EXPECT_EQ(s1.current(), 'r');
}

TEST(TestSequenceInsert, Insert_into_Length_5_CurrentIndex_2)
{
    Sequence s1;
    s1.append('c');
    s1.append('h');
    s1.append('a');
    s1.append('i');
    s1.append('r');
    s1.start();
    s1.advance();
    s1.advance();
    s1.insert('Z');
    ASSERT_EQ(s1.current(), 'Z');
    ASSERT_EQ(s1.size(), 6);
    s1.advance();
    ASSERT_EQ(s1.current(), 'a');
    s1.advance();
    s1.advance();
    EXPECT_EQ(s1.current(), 'r');
}

TEST(TestSequenceInsert, Insert_into_Length_5_CurrentIndex_4)
{
    Sequence s1;
    s1.append('c');
    s1.append('h');
    s1.append('a');
    s1.append('i');
    s1.append('r');
    s1.start();
    s1.advance();
    s1.advance();
    s1.advance();
    s1.advance();
    s1.insert('Z');
    ASSERT_EQ(s1.current(), 'Z');
    ASSERT_EQ(s1.size(), 6);
    s1.advance();
    ASSERT_EQ(s1.current(), 'r');
    s1.start();
    s1.advance();
    s1.advance();
    s1.advance();
    s1.advance();
    EXPECT_EQ(s1.current(), 'Z');
}

TEST(TestSequenceInsert, Insert_into_Length_5_CurrentIndex_5)
{
    Sequence s1;
    s1.append('c');
    s1.append('h');
    s1.append('a');
    s1.append('i');
    s1.append('r');
    s1.insert('Z');
    s1.advance();
    ASSERT_EQ(s1.current(), 'r');
    ASSERT_EQ(s1.size(), 6);
    s1.insert('P');
    ASSERT_EQ(s1.current(), 'P');
    ASSERT_EQ(s1.size(), 7);
    s1.advance();
    EXPECT_EQ(s1.current(), 'r');
}


TEST(TestSequenceInsert,
    Insert_into_Length_CAPACITYminus1_CurrentIndex_CAPACITYminus2)
{
    Sequence s1;
    string chars_29 = "0123456789qwertyuiopasdfghjkl"; // length 29
    for (int i = 0; i < CAPACITY - 1; i++)
    {
        s1.append(chars_29[i]);
    }
    ASSERT_EQ(s1.current(), 'l'); // current_index 28, cap minus 2
    s1.insert('$');               // '$'' at index 28, 'l' at index 29
    EXPECT_EQ(s1.current(), '$');
    s1.advance();
    EXPECT_EQ(s1.current(), 'l');
    cout << s1 << endl;
}

TEST(TestSequenceInsert,
    Insert_into_Length_CAPACITYminus1_CurrentIndex_0)
{
    Sequence s1;
    string chars_29 = "0123456789qwertyuiopasdfghjkl"; // length 29
    for (int i = 0; i < CAPACITY - 1; i++)
    {
        s1.append(chars_29[i]);
    }
    s1.start(); // current index 0, length is CAP minus 1
    s1.insert('$');  // '$' at index 0, all others shifted one right
    cout << s1 << endl;
    EXPECT_EQ(s1.current(), '$');
    chars_29 = "$" + chars_29; // length 30, '$' at front
    for (int i = 1; i < CAPACITY; i++)
    {
        s1.advance();
        EXPECT_EQ(s1.current(), chars_29[i]);
    }
}

/*
TestSequenceRemoveCurrent
  - Remove_from_Length_1_CurrentIndex_0
  - Remove_from_Length_2_CurrentIndex_0
  - Remove_from_Length_2_CurrentIndex_1
  - Remove_from_Length_5_CurrentIndex_0
  - Remove_from_Length_5_CurrentIndex_2 <<== PROVIDED
  - Remove_from_Length_5_CurrentIndex_4
  - Remove_from_Length_CAPACITY_CurrentIndex_CAPACITYminus1 <<== PROVIDED
  - Remove_from_Length_CAPACITY_CurrentIndex_0 <<== PROVIDED
*/

TEST(TestSequenceRemoveCurrent,
    Remove_from_Length_1_CurrentIndex_0)
{
    Sequence s1;
    s1.append('a');
    s1.remove_current();
    EXPECT_FALSE(s1.is_item());
    EXPECT_EQ(s1.size(), 0);
}

TEST(TestSequenceRemoveCurrent,
    Remove_from_Length_2_CurrentIndex_0)
{
    Sequence s1;
    s1.append('a');
    s1.append('b');
    s1.start();
    s1.remove_current();
    EXPECT_EQ(s1.current(), 'b'); // 'a' was removed
    EXPECT_EQ(s1.size(), 1);
}

TEST(TestSequenceRemoveCurrent,
    Remove_from_Length_2_CurrentIndex_1)
{
    Sequence s1;
    s1.append('a');
    s1.append('b');
    s1.remove_current();
    EXPECT_FALSE(s1.is_item());
    EXPECT_EQ(s1.size(), 1);
}

TEST(TestSequenceRemoveCurrent,
    Remove_from_Length_5_CurrentIndex_0)
{
    Sequence s1;
    s1.append('a');
    s1.append('b');
    s1.append('c');
    s1.append('d');
    s1.append('e');
    s1.start();
    s1.remove_current();
    EXPECT_EQ(s1.current(), 'b'); // 'a' was removed
    EXPECT_EQ(s1.size(), 4);
}

TEST(TestSequenceRemoveCurrent,
    Remove_From_Length_5_CurrentIndex_2)
{
    Sequence s1;
    s1.append('a');
    s1.append('b');
    s1.append('c');
    s1.append('d');
    s1.append('e');
    s1.start();
    s1.advance();
    s1.advance();
    s1.remove_current();
    EXPECT_EQ(s1.current(), 'd'); // 'c' was removed
    EXPECT_EQ(s1.size(), 4);
}

TEST(TestSequenceRemoveCurrent,
    Remove_from_Length_5_CurrentIndex_4)
{
    Sequence s1;
    s1.append('a');
    s1.append('b');
    s1.append('c');
    s1.append('d');
    s1.append('e');
    s1.start();
    s1.advance();
    s1.advance();
    s1.advance();
    s1.advance();
    s1.remove_current();
    EXPECT_FALSE(s1.is_item());
    EXPECT_EQ(s1.size(), 4);
}

TEST(TestSequenceRemoveCurrent,
    Remove_from_Length_CAPACITY_CurrentIndex_CAPACITYminus1)
{
    Sequence s1;
    string chars_30 = "0123456789qwertyuiopasdfghjklx"; // length 30
    for (int i = 0; i < CAPACITY; i++)
    {
        s1.append(chars_30[i]);
    }
    ASSERT_EQ(s1.current(), 'x'); // current_index 29, cap minus 1
    s1.remove_current();
    cout << s1 << endl;
    EXPECT_FALSE(s1.is_item());
    EXPECT_EQ(s1.size(), CAPACITY - 1);
}

TEST(TestSequenceRemoveCurrent,
    Remove_from_Length_CAPACITY_CurrentIndex_0)
{
    Sequence s1;
    string chars_30 = "0123456789qwertyuiopasdfghjklx"; // length 30
    for (int i = 0; i < CAPACITY; i++)
    {
        s1.append(chars_30[i]);
    }
    ASSERT_EQ(s1.current(), 'x'); // current_index 29, cap minus 1
    s1.start();  // current_index 0
    s1.remove_current();
    cout << s1 << endl;
    EXPECT_EQ(s1.current(), '1');
    EXPECT_EQ(s1.size(), CAPACITY - 1);
}

/*
Test_Seq1_EqualNotEqual_Seq2,
  - Both_Empty_Equivalent
  - Both_Size_3_and_Equivalent_with_Same_Current_Index
  - Both_Size_3_and_Equivalent_with_Different_Current_Index
  - Seq1_Shorter_Not_Equivalent
  - Seq1_Longer_Not_Equivalent
  - Both_Size_5_Same_Except_First_Item_Not_Equivalent <<== PROVIDED
  - Both_Size_5_Same_Except_Middle_Item_Not_Equivalent
  - Both_Size_5_Same_Except_Last_Item_Not_Equivalent
*/

TEST(Test_Seq1_EqualNotEqual_Seq2,
    Both_Empty_Equivalent)
{
    Sequence s1, s2;
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 != s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    Both_Size_3_and_Equivalent_with_Same_Current_Index)
{
    Sequence s1, s2;
    s1.append('a');
    s1.append('b');
    s1.append('c');
    s2.append('a');
    s2.append('b');
    s2.append('c');
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 != s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    Both_Size_3_and_Equivalent_with_Different_Current_Index)
{
    Sequence s1, s2;
    s1.append('a');
    s1.append('b');
    s1.append('c');
    s2.append('a');
    s2.append('b');
    s2.append('c');
    s1.start();
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 != s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    Seq1_Shorter_Not_Equivalent)
{
    Sequence s1, s2;
    s1.append('a');
    s2.append('a');
    s2.append('b');
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    Seq1_Longer_Not_Equivalent)
{
    Sequence s1, s2;
    s2.append('a');
    s1.append('a');
    s1.append('b');
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    Both_Size_5_Same_Except_First_Item_Not_Equivalent)
{
    Sequence s1, s2;
    s1.append('a');
    s1.append('b');
    s1.append('c');
    s1.append('d');
    s1.append('e');
    s2.append('x');
    s2.append('b');
    s2.append('c');
    s2.append('d');
    s2.append('e');
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    Both_Size_5_Same_Except_Middle_Item_Not_Equivalent)
{
    Sequence s1, s2;
    s1.append('a');
    s1.append('b');
    s1.append('c');
    s1.append('d');
    s1.append('e');
    s2.append('a');
    s2.append('b');
    s2.append('x');
    s2.append('d');
    s2.append('e');
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

TEST(Test_Seq1_EqualNotEqual_Seq2,
    Both_Size_5_Same_Except_Last_Item_Not_Equivalent)
{
    Sequence s1, s2;
    s1.append('a');
    s1.append('b');
    s1.append('c');
    s1.append('d');
    s1.append('e');
    s2.append('a');
    s2.append('b');
    s2.append('c');
    s2.append('d');
    s2.append('x');
    EXPECT_TRUE(s1 != s2);
    EXPECT_FALSE(s1 == s2);
}

/*
Test_Seq1_PlusAssign_Seq2,
  - Both_Empty
  - Both_Typical <<== PROVIDED
  - Seq1_Empty_and_Seq2_Typical
  - Seq1_Typical_and_Seq2_Empty
  - Seq1_PlusAssign_Seq1
*/

TEST(Test_Seq1_PlusAssign_Seq2,
    Both_Empty)
{
    Sequence s1, s2, s3;
    s1 += s2;
    EXPECT_TRUE(s1 == s3);
    EXPECT_FALSE(s1.is_item());
    EXPECT_EQ(s1.size(), 0);
}

TEST(Test_Seq1_PlusAssign_Seq2,
    Both_Typical)
{
    Sequence s1, s2, s3;
    s1.append('a');
    s1.append('b');
    s1.append('c');
    s1.append('d');
    s1.start();
    s1.advance(); // current_index 1
    s2.append('x');
    s2.append('y');
    s2.start(); // current_index 0
    s3.append('a');
    s3.append('b');
    s3.append('c');
    s3.append('d');
    s3.append('x');
    s3.append('y');
    s1 += s2;

    EXPECT_TRUE(s1 == s3);
    EXPECT_EQ(s1.current(), 'b');
    EXPECT_EQ(s1.size(), 6);
}

TEST(Test_Seq1_PlusAssign_Seq2,
    Seq1_Empty_and_Seq2_Typical)
{
    Sequence s1, s2, s3;
    s2.append('x');
    s2.append('y');
    s2.append('a');
    s2.advance();
    s3.append('x');
    s3.append('y');
    s3.append('a');
    s1 += s2;
    EXPECT_TRUE(s1 == s3);
    EXPECT_EQ(s1.current(), 'x');
    EXPECT_EQ(s1.size(), 3);
}

TEST(Test_Seq1_PlusAssign_Seq2,
    Seq1_Typical_and_Seq2_Empty)
{
    Sequence s1, s2, s3;
    s1.append('x');
    s1.append('y');
    s1.append('a');
    s3.append('x');
    s3.append('y');
    s3.append('a');
    s1 += s2;
    EXPECT_TRUE(s1 == s3);
    EXPECT_EQ(s1.current(), 'a');
    EXPECT_EQ(s1.size(), 3);
}

TEST(Test_Seq1_PlusAssign_Seq2,
    Seq1_PlusAssign_Seq1)
{
    Sequence s1, s3;
    s1.append('x');
    s1.append('y');
    s1.append('a');
    s1.start();
    s1.advance(); 
    s1.advance();  // current_index 2
    s3.append('x');
    s3.append('y');
    s3.append('a');
    s3.append('x');
    s3.append('y');
    s3.append('a');
    s1 += s1;
    EXPECT_TRUE(s1 == s3);
    EXPECT_EQ(s1.current(), 'a');
    EXPECT_EQ(s1.size(), 6);
}

// operator<<, stream output of Sequence objects

TEST(TestSequenceStreamOutput, Empty)
{
    stringstream out;   // simulated output stream
    string correct;     // correct output

    // 1. Setup sequence and store correct output
    Sequence seq;
    correct = "Sequence: <empty sequence>\n";

    // 2. Execute (put sequence into output stream)
    out << seq;

    // 3. Assert (check that contents of output stream are correct)
    EXPECT_EQ(out.str(), correct);
}

TEST(TestSequenceStreamOutput, Typical)
{
    stringstream out;   // simulated output stream
    string correct;     // correct output

    // 1. Setup sequence and store correct output
    Sequence seq;
    seq.append('h');
    seq.append('i');
    seq.append('!');
    seq.start();

    correct = "Sequence: h i !";

    // 2. Execute (put sequence into output stream)
    out << seq;

    // 3. Assert (check that contents of output stream are correct)
    EXPECT_EQ(out.str(), correct);
}

TEST(TestSequenceStreamOutput, Chaining)
{
    stringstream out;   // simulated output stream
    string correct;     // correct output

    // 1. Setup sequence and store correct output
    Sequence seqA;      // empty sequence
    Sequence seqB;      // sequence (h i !)
    seqB.append('h');
    seqB.append('i');
    seqB.append('!');
    seqB.start();
    correct = "Sequence: <empty sequence>\nSequence: h i !";

    // 2. Execute (put sequence into output stream)
    out << seqA << seqB;

    // 3. Assert (check that contents of output stream are correct)
    EXPECT_EQ(out.str(), correct);
}

// operator>>, stream input for Sequence objects

TEST(TestSequenceStreamInput, Read_Longer_into_Shorter)
{
    stringstream in;    // simulated input stream

    // 1. Setup sequence and store the string representation of a new sequence
    Sequence seq;
    seq.append('h');
    seq.append('i');
    seq.append('!');

    in << "Sequence: b y e !\n";

    // 2. Execute (read in sequence from the input stream)
    in >> seq;

    // 3. Assert (check that seq has been correctly modified)
    EXPECT_EQ(seq.size(), 4);
    EXPECT_TRUE(seq.is_item());
    EXPECT_EQ(seq.current(), 'b');  // operator>> should move current to start
    seq.advance();
    EXPECT_EQ(seq.current(), 'y');
    seq.advance();
    EXPECT_EQ(seq.current(), 'e');
    seq.advance();
    EXPECT_EQ(seq.current(), '!');
}

TEST(TestSequenceStreamInput, Read_Shorter_into_Longer)
{
    stringstream in;    // simulated input stream

    // 1. Setup sequence and store the string representation of a new sequence
    Sequence seq;
    seq.append('t');
    seq.append('r');
    seq.append('u');
    seq.append('c');
    seq.append('k');

    in << "Sequence: c a r\n";

    // 2. Execute (read in sequence from the input stream)
    in >> seq;

    // 3. Assert (check that seq has been correctly modified)
    EXPECT_EQ(seq.size(), 3);
    EXPECT_TRUE(seq.is_item());
    EXPECT_EQ(seq.current(), 'c');  // operator>> should move current to start
    seq.advance();
    EXPECT_EQ(seq.current(), 'a');
    seq.advance();
    EXPECT_EQ(seq.current(), 'r');
}

TEST(TestSequenceStreamInput, Read_Empty_into_Nonempty)
{
    stringstream in;    // simulated input stream

    // 1. Setup sequence and store the string representation of a new sequence
    Sequence seq;
    seq.append('s');
    seq.append('t');
    seq.append('u');
    seq.append('f');
    seq.append('f');

    in << "Sequence: <empty sequence>\n";

    // 2. Execute (read in sequence from the input stream)
    in >> seq;

    // 3. Assert (check that seq has been correctly modified)
    EXPECT_EQ(seq.size(), 0);
    EXPECT_FALSE(seq.is_item());
}

TEST(TestSequenceStreamInput, Chaining)
{
    stringstream in;    // simulated input stream

    // 1. Setup sequences and store the string representations
    Sequence seqA;
   Sequence seqB;

    in << "Sequence: a b c\n";
    in << "Sequence: x y z\n";

    // 2. Execute (read in sequence from the input stream)
    in >> seqA >> seqB;

    // 3. Assert (check that both seqA & seqB have been correctly modified)
    EXPECT_EQ(seqA.size(), 3);
    EXPECT_EQ(seqA.current(), 'a');
    seqA.advance();
    EXPECT_EQ(seqA.current(), 'b');
    seqA.advance();
    EXPECT_EQ(seqA.current(), 'c');

    EXPECT_EQ(seqB.size(), 3);
    EXPECT_EQ(seqB.current(), 'x');
    seqB.advance();
    EXPECT_EQ(seqB.current(), 'y');
    seqB.advance();
    EXPECT_EQ(seqB.current(), 'z');
}

} // End namespace

// main() for testing -- boilerplate
int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}