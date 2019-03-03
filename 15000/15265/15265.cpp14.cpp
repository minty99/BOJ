#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <bitset>
#include <random>
#include <array>
using namespace std;

unordered_map<string, int> um;

class Folder {
public:
    string name;
    set<string> v;
    int size;

    Folder(string _s, int _size) {
        name = _s;
        size = _size;
    }
};

int t;
vector<Folder> tree;

bitset<100000> bs;

void print(int curr)
{
    if(bs[curr] == true) return;
    bs[curr] = true;
    if(tree[curr].size >= t) {
        bool flag = false;
        for(auto it = tree[curr].v.begin(); it != tree[curr].v.end(); ++it)
        {
            if(tree[um[*it]].size >= t) { flag = true; break; }
        }

        if(tree[curr].v.size() > 0 and flag) {
            printf("- %s %d\n", tree[curr].name.c_str(), tree[curr].size);
            for(auto it = tree[curr].v.begin(); it != tree[curr].v.end(); ++it)
            {
                print(um[*it]);
            }
        }
        else if(tree[curr].v.size() > 0) printf("+ %s %d\n", tree[curr].name.c_str(), tree[curr].size);
        else printf("  %s %d\n", tree[curr].name.c_str(), tree[curr].size);
    }
    else {
        if(tree[curr].v.size() == 0) printf("  %s %d\n", tree[curr].name.c_str(), tree[curr].size);
        else printf("+ %s %d\n", tree[curr].name.c_str(), tree[curr].size);
    }

}

int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    tree.emplace_back("/", 0);
    char _s[200];
    um.insert(make_pair("/", 0));
    for(int i = 1; i <= n; i++)
    {
        int sz = 0;
        scanf("%s %d", _s, &sz);
        string s(_s);

        int pos = 0;
        int par_idx = -1;
        while(true) {
            int np = s.find("/", pos);
            if(np == string::npos) break;
            string str = np > 0 ? s.substr(0, np) + "/" : "/";
            if(par_idx >= 0) tree[par_idx].v.insert(str);
            if(um.find(str) != um.end()) { tree[um[str]].size += sz; par_idx = um[str]; }
            else { tree.emplace_back(str, sz); par_idx = tree.size()-1; um.insert(make_pair(str, tree.size()-1)); }
            pos = np+1;
        }
    }

    scanf("%d", &t);
    print(0);
}
