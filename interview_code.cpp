#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <ctime>
#define MAXN 5000
#define xx first 
#define yy second 
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define INF (1<<30)
#define prime 37
#define eps 0.0000001

using namespace std;
class A {
	
	vector<string> names;
	public :
	void init(vector<string> names) {
		this->names = names; 
	}

	string find() {
		srand (time(NULL));
		int sz = names.size();
		int index = rand() % sz;
		string res = names[index];	
		for (int i = index; i < sz - 1; i ++ ) {
			names[i] = names[i + 1];
		}
		names.pop_back();
		return res;
	}
	
	vector< vector<string> > solve() {
		
		
		int n = names.size();
		int group = n / 3;
		int rem = n % 3;
		vector< int > g;
		vector<vector< string > > res;
		if (n <= 3 ) {
			res.push_back (names);
			return res;
		}
		
		
		for (int i = 0; i < group; i  ++ ) {
			g.push_back(3);
		}		
			
		if ( g.size() < rem ) {
			g[0] += rem;
		} else {
			for (int i = 0; i < g.size() && rem > 0; i ++ ){
				g[i] = g[i] + 1;
				rem --;
			}
		}
		
		for (int i = 0; i <  g.size(); i ++ ) {
			vector<string> tempnames;
			for (int j = 0; j < g[i]; j ++ ) {
				tempnames.push_back( find() );
			}
			res.push_back(tempnames);
		}
		return res;
	}

}; 

int main() {
	
	string arr[] = { "a1" , "a2" , "a3" ,"a4","a5","a6","a7","a8","a9","a10","a11" , "a12"  };
	// must populate the ar with arr
	vector< string >  ar;
	for (int i = 0; i < 12; i ++ )
		ar.push_back(arr[i]);
		
	A a;
	a.init(ar);
	
	// main function 
	vector<vector<string> > groups = a.solve();	
	
	
	for (int i = 0; i < groups.size(); i ++ ) {
		
		for(int j = 0; j < groups[i].size(); j ++ ) {
			cout << groups[i][j] << ",";
		}
		cout << endl; 
	}
	
	
	return 0;
}
