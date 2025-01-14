//
//  main.cpp
//  Rotate Matrix
//
//  Created by daniel saghbine on 12/17/24.
//  CTCI 1.7 Rotate Matrix

#include <iostream>
#include <cstdlib>
using namespace std;

const int N=3;

void Rotate_Matrix(const int m[][N]);

int main()
{
    srand(int(time(0)));
    
    int matrix[N][N];
    
    cout<<"problem\n-------\n\tGiven an image represented by an N x N matrix, where each pixel in the image is represented by an integer, write a method to rotate the image by 90 degrees. Can you do this in place?\n\n";
    
    cout<<"input\n-----\n";
    
    for(int c=0; c < N; c++)
    {
        cout<<'\t';
        
        for(int r=0; r < N; r++)
        {
            matrix[r][c]=rand()%10;
            cout<<matrix[r][c]<<' ';
        }
        
        cout<<endl;
    }
    
    cout<<"\noutput\n------\n";
    
    Rotate_Matrix(matrix);
    Rotate_Matrix(matrix);
    Rotate_Matrix(matrix);
    Rotate_Matrix(matrix);
    
    cout<<"\nsolution\n--------\n\tAuxiliary space complexity: O(1); time complexity: O(n^2).\n\n";
    
    return 0;
}

bool outie(int c, int n1)
{
    switch(c)
    {
        case 1: return n1 < N;
        default: return n1 >= 0;
    }
}

void outer(int c, int &n1)
{
    switch(c)
    {
        case 1: n1++;
            break;
        default: n1--;
    }
}

int inn(int c)
{
    switch(c)
    {
        case 3: return 0;
        default: return N-1;
    }
}

bool innie(int c, int n2)
{
    switch(c)
    {
        case 3: return n2 < N;
        default: return n2 >= 0;
    }
}

void innermost(int c, int &n2)
{
    switch(c)
    {
        case 3: n2++;
            break;
        default: n2--;
    }
}

void print_matrix(const int m[][N])
{
    for(int c=0; c < N; c++)
    {
        cout<<"\t\t";
        
        for(int r=0; r < N; r++)
            cout<<m[r][c]<<' ';
        
        cout<<endl;
    }
}

void Rotate_Matrix(const int m[][N]) // m is input matrix
{
    static int counter=0; // rotation counter
    int val; // initializer for for loop
    
    counter++; // count rotation
    
    cout<<'\t'; // tab in output window
    
    switch(counter) // check counter
    {
        case 1: cout<<"First"; // if it is 1
            break;
        case 2: cout<<"Second"; // if it is 2
            break;
        case 3: cout<<"Third"; // if it is 3
            break;
        default: cout<<"Fourth"; // if it is 4
    }
    
    cout<<" 90 degrees clockwise rotation.\n"; // print in output window
    
    switch(counter) // check counter
    {
        case 1: val=0; // if it is 0, initialize val to beginning in m
            break;
        case 4: print_matrix(m); // if it is 4, print original matrix
            counter=0; // reset counter
            return;
        default: val=N-1; // if not above, initialize val to ending in m
    }
    
    /*
     for for loop
         First 90 degrees clockwise rotation
            [ ] [ ]  ... [ ]
            [ ] [ ]  ... [ ]
            ... ...  ... ...
            [ ] [ ]  ... [ ]
             0   1   ...  n
           ^beg          end^
                print column 0 bottom-to-top first, print column 1 bottom-to-top second, ... and print column n bottom-to-top last
         
         Second 90 degrees clockwise rotation
            [ ] [ ]  ... [ ]  0  <-- end here
            [ ] [ ]  ... [ ]  1
            ... ...  ... ... ...
            [ ] [ ]  ... [ ]  n  <-- begin here
                print row n right-to-left first, ..., print row 1 right-to-left second-to-last and print row 0 right-to-left last
            
         Third 90 degrees clockwise rotation
          \/end          beg\/
             0   1   ...  n
            [ ] [ ]  ... [ ]
            [ ] [ ]  ... [ ]
            ... ...  ... [ ]
            [ ] [ ]  ... [ ]
                print column n top-to-bottom first, ..., print column 1 top-to-bottom second-to-last and print column 0 top-to-bottom last
     */
    for(int n1=val; outie(counter, n1); outer(counter, n1))
    {
        cout<<"\t\t";
        
        for(int n2=inn(counter); innie(counter, n2); innermost(counter, n2))
        {
            switch(counter)
            {
                case 2: cout<<m[n2][n1];
                    break;
                default: cout<<m[n1][n2];
            }
            
            cout<<' ';
        }
        
        cout<<endl;
    }
    
    cout<<endl; // ends current line of output line to brand new line below it
}
