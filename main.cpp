#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    vector<int> x;

    int a, n;

    while(fin >> a) {
        x.push_back(a);
    }

    for (int i = 0; i < x.size(); i++) {
        fout << x[i] << " ";
    }
   
    n = x.size();
    
    vector<vector<int> > d( n + 1 , vector<int> (n + 1, 0));
    vector<vector<int> > p( n + 1 , vector<int> (n + 1, 0));;

    for (int i = 0; i <= n; i++)
    {
        p[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(d[i][j-1] > d[i-1][j-1]+x[j-1])
            {
                d[i][j] = d[i][j-1];
                p[i][j] = p[i][j-1];
            }
            else if(d[i][j-1] < d[i-1][j-1]+x[j-1])
            {
                d[i][j] = d[i-1][j-1]+x[j-1];
                p[i][j] = p[i-1][j-1];
            }
            else 
            {
                d[i][j] = d[i][j-1];
                p[i][j] = p[i][j-1]+p[i-1][j-1];
            }
            cout<<d[i][j]<<"("<<p[i][j]<<")";
        }
        cout<<"\n";
    }

    


    return 0;
}