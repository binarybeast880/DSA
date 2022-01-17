/*  ----problem statement----   
A celebrity is a person who is known to all but does not know anyone at a party. 
If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an
element of row i and column j  is set to 1 it means ith person knows jth person. 
Here M[i][i] will always be 0.
*/

#include <bits/stdc++.h> 
using namespace std; 
#define N 8 
  
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}}; 
  
bool knows(int a, int b) 
{ 
    return MATRIX[a][b]; 
} 
  
int findCelebrity(int n) 
{ 
    stack<int> s; 
    int cel;
    for (int i = 0; i < n; i++) 
        s.push(i); 
    int A = s.top(); 
    s.pop(); 
    int B = s.top(); 
    s.pop(); 
    while (s.size() > 1) 
    { 
        if (knows(A, B)) 
        { 
            A = s.top(); 
            s.pop(); 
        } 
        else
        { 
            B = s.top(); 
            s.pop(); 
        } 
    } 
    cel = s.top(); 
    s.pop(); 
    if (knows(cel, B)) 
        cel = B; 
  
    if (knows(cel, A)) 
        cel = A; 
  
    for (int i = 0; i < n; i++) 
    { 
        if ( (i != cel) && 
                (knows(cel, i) ||  
                 !knows(i, cel)) ) 
            return -1; 
    } 
  
    return cel; 
} 
 main() 
{ 
    int n = 4; 
    int id = findCelebrity(n); 
    id == -1 ? cout << "No celebrity" : 
               cout << "Celebrity ID " << id; 
} 