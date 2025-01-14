//
//  main.cpp
//  String Rotation
//
//  Created by daniel saghbine on 1/9/25.
//
//  CTCI 1.9 String Rotation: Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
//  Auxiliary space complexity: O(1). Time complexity: O(n).

#include <iostream>
using namespace std;

bool String_Rotation(const string &s1, const string &s2);

int main()
{
    string str1, str2;
    
    cout<<"input\n-----\n";
    cout<<"\tType a string to serve as the rotation base: ";
    cin>>str1;
    cout<<"\tType another string to check if it's a rotation of the base: ";
    cin>>str2;
    
    cout<<"\noutput\n------\n";
    cout<<"\t\""<<str2<<"\" is"<<(String_Rotation(str1, str2) ? "" : "n't")<<" a rotation of \""<<str1<<"\".\n\n";
    
    return 0;
}

bool String_Rotation(const string &s1, const string &s2) // s1 is the first C++ string and s2 is the second
{
    if(s1.size() != s2.size()) // check if s1 and s2 don't have the same size
        return false; // s2 isn't a rotation of s1
    
    int i1, i2; // i1 is the index tracker of s1 and i2 is the index tracker of s2
    
    for(i2=0; i2 < s2.size() && s2[i2] != s1[0]; i2++); // move i2 to the index where it contains the same char as index 0 of s1 if it does
    
    if(s2[i2++] == s1[0]) // this is if it does
    {
        for(i1=1; i1 < s1.size() && i2 < s2.size() && s1[i1] == s2[i2]; i1++, i2++); // move i1 to the first index where there is a char mismatch between it and i2 as it moves too
        
        if(s2.find(s1.substr(i1, s1.size()-i1+1)) == -1) // if the final portion of s1 isn't the same as the beginning portion of s2
            return false; // s2 isn't a rotation of s1
    }
    
    return true; // s2 is a rotation of s1
}
