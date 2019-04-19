#include <iostream> 
#include <string.h> 
#include <vector> 
// defining total number of process 
#define Pr 5 
// definining total number of resources 
#define Re 3 
  
// intializing total number of safe-sequences 
int t = 0; 
  
using namespace std; 
  
// function to check if process can be allocated or not 
bool p_available(int p_id, int allocated[][Re], 
                  int max[][Re], int need[][Re], int available[]) 
{ 
  //intializing boolean flag 
    bool fg = true; 
  
    // check if all the available resources  are less greater than need of process 
    for (int x = 0; x < Re; x++) { 
  
        if (need[p_id][x] > available[x]) 
            fg = false; 
    } 
  
    return fg; 
} 
  
// Print all the safe-sequences 
void sf_sequence(bool m[], int allocated[][Re], int max[][Re], 
                   int need[][Re], int available[], vector<int> safe) 
{ 
  
    for (int x = 0; x < Pr; x++) { 
  
        // check if it is not marked already and can be allocated 
        if (!m[x] && p_available(x, allocated, max, need, available )){ 
  
            // mark the process 
            m[x] = true; 
  
            // increasing the available by deallocating from process x 
            for (int j = 0; j < Re; j++) 
                available[j] += allocated[x][j]; 
  
            safe.push_back(x); 
            // finding safe sequence by taking process x 
            sf_sequence(m, allocated, max, need, available, safe); 
            safe.pop_back(); 
  
            // unmark the process 
            m[x] = false; 
  
            // decrement the available resources 
            for (int j = 0; j < Re; j++) 
                available[j] -= allocated[x][j]; 
        } 
    } 
  
    // To display all the safe sequences 
    if (safe.size() == Pr) { 
  
        t++; 
        for (int x = 0; x< Pr; x++)
		 { 
  
            cout << "P" << safe[x]; 
            if (x != (Pr - 1)) 
                cout << "->- "; 
        } 
  
        cout << endl; 
    } 
} 
  
// main function 
int main() 
{ 
  
    // allocated matrix of size Pr*Re 
    int allocated[Pr][Re] = { { 0, 1, 0 }, { 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 },{ 0, 0, 2} }; 
  
    // max matrix of size Pr*Re 
    int max[Pr][Re] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 }, { 4, 3, 3} }; 
  
    // Initial total resources 
    int Resources[Re] = { 10, 5, 7 }; 
  
    // available vector of size Re 
    int available[Re] = { 3, 3, 2 };
  
    // safe vector for displaying a safe-sequence 
    vector<int> s; 
  
    // marked of size Pr for marking allocated process 
    bool m[Pr]; 
  
    // need matrix of size Pr*R 
    int need[Pr][Re]; 
    for (int x = 0; x < Pr; x++) 
  {
	for (int y = 0; y < Re; y++) 
	{
	need[x][y] = max[x][y] - allocated[x][y];
    }
}
    
  cout<<"System is in safe state"<<endl;
  cout<<"\n";
    cout << "All possible Safe sequences are:" << endl; 
    sf_sequence(m, allocated, max, need, available, s); 
  
    cout << "\nThere are total " << t << " safe-sequences" << endl; 
    return 0; 
} 

