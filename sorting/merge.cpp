/**
 *    author:  joshi8
 *    created:
**/

#include <bits/stdc++.h>

using namespace std;


vector<int> merge_sort(vector<int> arr)
{
    if(arr.size()!=1)
    {
        vector<int> left;
        vector<int> right;

        int i;
        for(i=0;i<arr.size()/2;i++)
        {
            left.push_back(arr[i]);
        }
        for(i;i<arr.size();i++)
        {
            right.push_back(arr[i]);
        }

        left = merge_sort(left);
        right = merge_sort(right);

        vector<int> merged;

        int j=0,k=0,l,m,n;
        while(j<left.size() && k<right.size())
        {
            if(left[j]<right[k])
            {
                merged.push_back(left[j]);
                j++;
            }
            else
            {
                merged.push_back(right[k]);
                k++;
            }
        }

        while(j<left.size())
        {
            merged.push_back(left[j]);
            j++;
        }

        while(k<right.size())
        {
            merged.push_back(right[k]);
            k++;
        }

        return merged;

    }
    else
    {
        return arr;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    vector<int> arr;
    int n;
    cin>>n;

    int inp;
    for(int i=0;i<n;i++)
    {
        cin>>inp;
        arr.push_back(inp);
    }


    vector<int> arr2 = merge_sort(arr);

    cout<<"\n\n";
    for(int i=0;i<arr2.size();i++)
    {
        cout<<arr2[i]<<"  ";
    }
    return 0;
}
