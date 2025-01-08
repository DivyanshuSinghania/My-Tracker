#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {

    int content_child = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int n = g.size();
    int m = s.size();
    // cout << m << " " << n << endl;
    int i = 0;
    int j = 0;

    int temp = 0;
    while (i<n && j<m)
    {
        if (g[i] <= s[j])
        {
            content_child++;
            i++;
        }
        j++;
    }

    return content_child;        
}



int main() {

    vector<int> g[3];
    g->push_back(1);
    g->push_back(2);
    g->push_back(3);

    vector<int> s[2];
    s->push_back(1);
    s->push_back(4);


    cout << findContentChildren(*g, *s) << endl;
    return 0;
}




