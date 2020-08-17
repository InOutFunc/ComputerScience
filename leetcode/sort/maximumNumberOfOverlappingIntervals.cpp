// Program to find maximum guest at any time in a party
#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;
 
void findMaxGuests(vector<int> arrl, vector<int> exit)
{
   int n = arrl.size();
   // Sort arrival and exit arrays
   sort(arrl.begin(), arrl.end());
   sort(exit.begin(), exit.end());
 
   // guests_in indicates number of guests at a time
   int guests_in = 1, max_guests = 1, time = arrl[0];
   int i = 1, j = 0;
 
   // Similar to merge in merge sort to process
   // all events in sorted order
   while (i < n && j < n)
   {
      // If next event in sorted order is arrival,
      // increment count of guests
      if (arrl[i] <= exit[j])
      {
          guests_in++;
 
          // Update max_guests if needed
          if (guests_in > max_guests)
          {
              max_guests = guests_in;
              time = arrl[i];
          }
          i++;  //increment index of arrival array
      }
      else // If event is exit, decrement count
      {    // of guests.
          guests_in--;
          j++;
      }
   }
 
   cout << "Maximum Number of Guests = " << max_guests
        << " at time " << time;
}
 
// Driver program to test above function
int main()
{
    vector<int> arrl = {1, 2, 10, 5, 5};
    vector<int> exit = {4, 5, 12, 9, 12};
    findMaxGuests(arrl, exit);
    return 0;
}
