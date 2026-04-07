class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> need = {
            {'b', 1},
            {'a', 1},
            {'l', 2},
            {'o', 2},
            {'n', 1}
        };
        unordered_map<char, int> have;

        for(int i=0;i<text.size();i++)
        {
            have[text[i]] ++;
        }

        int res = INT_MAX;

        for(auto it : need)
        {
            char c = it.first;
            int fneed = it.second;
            int fhave = have[c];
            int times = fhave / fneed;
            res = min(res, times);
        }
        return res;
    }
};