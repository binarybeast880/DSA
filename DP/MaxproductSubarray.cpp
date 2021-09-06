class Solution
{
public:
    int maxProduct(vector<int> &a)
    {
        int i, n = a.size();

        int mini[n];
        int maxi[n];

        mini[0] = a[0];
        maxi[0] = a[0];

        int maxpro = a[0];
        for (i = 1; i < n; i++)
        {
            if (a[i] > 0)
            {
                maxi[i] = max(maxi[i - 1] * a[i], a[i]);
                mini[i] = min(mini[i - 1] * a[i], a[i]);
            }
            else
            {
                maxi[i] = max(mini[i - 1] * a[i], a[i]);
                mini[i] = min(maxi[i - 1] * a[i], a[i]);
            }
            maxpro = max(maxpro, maxi[i]);
        }

        return maxpro;
    }
};