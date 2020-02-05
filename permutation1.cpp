#include<bits/stdc++.h>
using namespace std;


vector<string> permute(vector<string> arr, vector<char> vec2){
	int n = arr.size();
	string a;
	
	for(int j = 0 ; j<n ; j++){
		a.append(arr[j]);
		for(int k = 0 ; k<vec2.size() ; k++){
			a.append(1,vec2[k]);
			arr.push_back(a);
			a.erase(a.end() - 1);
		}
		a.erase(0);
	}
	arr.erase(arr.begin() , arr.begin() + n);
	return arr;
}

int main(){
	//vector<vector<char>> data{{'a','b','c'},{'i','j'} , {'x','y'}};  Dummy Data
	
	vector < vector<char>> data;
	string line;
	ifstream file("input.csv");
	
	while (getline(file, line))
	{
        vector<char> row;
        stringstream iss(line);
        string val;
        int c = 0 ;
        while (getline(iss, val, ','))
        {            
            row.push_back(val[1]);
        }
        data.push_back(row);
	}
	
	vector<string> vec1;
	
	for(int i = 0 ; i<data[0].size() ; i++){
		string s(1,data[0][i]);
		vec1.push_back(s);
	}
	
	for(int i  = 1 ; i <data.size() ; i++){
		vec1 = permute(vec1, data[i]);
	}
	
	for(int i = 0 ; i<vec1.size() ; i++){
		cout<<vec1[i]<<endl;
	}
	
}
