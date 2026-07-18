class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> index(26,0);
        for(int i=0;i<order.size();i++)
        {
            index[order[i]-'a'] = i;
        }

        int n = words.size();
        for(int i=0;i<n-1;i++)
        {
            string w1 = words[i], w2 = words[i+1];
            int m = w1.size(),n = w2.size();
            for(int j=0;j<m;j++)
            {
                if(j==n) return false;
                if(w1[j]!=w2[j])
                {
                    if(index[w1[j]-'a'] > index[w2[j]-'a'])
                    {
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};