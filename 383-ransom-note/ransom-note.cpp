class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> need;
        unordered_map<char, int> have;

        for(char c : ransomNote)
        {
            need[c]++;
        }

        for(char c : magazine)
        {
            have[c]++;
        }

        return helper(have, need);
    }

    bool helper(unordered_map<char, int> have, unordered_map<char, int> need)
    {
        for(auto i : need)
        {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            if(fhave < fneed)
            {
                return false;
            }
        }
        return true;
    }
};