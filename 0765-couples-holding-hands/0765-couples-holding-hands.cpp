class Solution {
public:

    int minSwapsCouples(vector<int>& row) {

        int n = row.size();

        unordered_map<int,int> pos;

        // person -> index
        for(int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }

        int swaps = 0;

        for(int i = 0; i < n; i += 2) {

            int first = row[i];

            int partner = first ^ 1;

            // Already correct
            if(row[i+1] == partner)
                continue;

            swaps++;

            int partnerIndex = pos[partner];

            // Swap into correct place
            swap(row[i+1], row[partnerIndex]);

            // Update positions
            pos[row[partnerIndex]] = partnerIndex;
            pos[row[i+1]] = i + 1;
        }

        return swaps;
    }
};