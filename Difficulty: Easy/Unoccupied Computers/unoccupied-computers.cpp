class Solution {
  public:
    int solve(int n, string s) {
        // Track status of each character ('A'-'Z'):
        // 0 = Not seen / Departed
        // 1 = Occupying a computer
        // 2 = Turned away (unserviced)
        vector<int> status(26, 0);

        int occupied = 0;
        int unserviced_count = 0;

        for (char ch : s) {
            int idx = ch - 'A';

            // First time seeing this customer (Arrival)
            if (status[idx] == 0) {
                if (occupied < n) {
                    status[idx] = 1; // Assigned a computer
                    occupied++;
                } else {
                    status[idx] = 2; // Turned away
                    unserviced_count++;
                }
            } 
            // Second time seeing this customer (Departure)
            else {
                if (status[idx] == 1) {
                    occupied--; // Customer leaves and frees up a computer
                }
                // Reset status or leave as is since we won't see them again
            }
        }

        return unserviced_count;
    }
};