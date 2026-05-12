class DSU {
public:

    vector<int> parent;

    DSU(int n) {

        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {

        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {

        int pa = find(a);
        int pb = find(b);

        if(pa != pb) {
            parent[pa] = pb;
        }
    }
};

class Solution {
public:

    bool similar(string &a, string &b) {

        int diff = 0;

        for(int i = 0; i < a.size(); i++) {

            if(a[i] != b[i]) {
                diff++;
            }
        }

        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        DSU dsu(n);

        // Compare every pair
        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                if(similar(strs[i], strs[j])) {

                    dsu.unite(i,j);
                }
            }
        }

        unordered_set<int> groups;

        for(int i = 0; i < n; i++) {

            groups.insert(dsu.find(i));
        }

        return groups.size();
    }
};