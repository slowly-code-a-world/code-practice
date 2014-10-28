#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

string get_sub_palindrome(string s){
	int n = s.size();
	vector<int> vec;
	for(int i=0;i<n;++i){
		int t1 = s[i]-'0';
		int t2 = s[i]-'a';
		int t3 = s[i]-'A';
		if(t1>=0&&t1<10) vec.push_back(i);
		else if(t2>=0&&t2<26) vec.push_back(i);
		else if(t3>=0&&t3<26) vec.push_back(i);
	}
	int dis = abs('a'-'A');
	int m = vec.size();
	vector<int> mark(m,1);
	vector<vector<bool> > pal_status(m,vector<bool>(m,false));
	int max_len = 0;
	int max_index = -1;
	for(int i=m-1;i>=0;--i){
		for(int j=m-1;j>=i;--j){
			if((s[vec[i]]==s[vec[j]]||abs(int(s[vec[i]])-int(s[vec[j]]))==dis)&&(j-i<=2||pal_status[i+1][j-1])){
				pal_status[i][j] = true;
				if(i!=m-1) mark[i] = mark[i+1]+2;
				if(mark[i]>max_len){
					max_len = mark[i];
					max_index = i;
				}
			}
		}
	}
	if(max_index==-1) return s;
	return s.substr(vec[max_index],vec[max_index+max_len-1]-vec[max_index]+1);
}

string GetSubPal(string s){
	string res="";
	int max_len=0,max_index=-1;
	int n = s.size();
	int dis = abs(int('a')-int('A'));
	if(n<=1) return s;
	for(int i=0;i<n;++i){
		int l=i-1,r=i+1;
		while(l>=0&&r<n){
			int t1 = s[l]-'0';
			int t2 = s[l]-'a';
			int t3 = s[l]-'A';
			if(t1<0&&t1>=10&&t2<0&&t2>=26&&t3<0&&t3>=26){
				l--;
				continue;
			}
			t1 = s[r]-'0';
			t2 = s[r]-'a';
			t3 = s[r]-'A';
			if(t1<0&&t1>=10&&t2<0&&t2>=26&&t3<0&&t3>=26){
				r++;
				continue;
			}
			if(s[l]==s[r]||abs((int(s[l])-int(s[r]))==dis)){
				l--;r++;
			}else break;
		}
		if(l<0&&r>=n) return s;
		if(l<0){
			int t1 = s[r]-'0';
			int t2 = s[r]-'a';
			int t3 = s[r]-'A';
			if(t1<0&&t1>=10&&t2<0&&t2>=26&&t3<0&&t3>=26){
				max_index = 0;
				max_len = r;
			}
		}else if(r>=n){
			int t1 = s[l]-'0';
			int t2 = s[l]-'a';
			int t3 = s[l]-'A';
			if(t1<0&&t1>=10&&t2<0&&t2>=26&&t3<0&&t3>=26){
				if(n-l>max_len){
					max_index = l+1;
					max_len = n-l;
				}	
			}
		}else{
			int t1 = s[l]-'0';
			int t2 = s[l]-'a';
			int t3 = s[l]-'A';
			if(t1<0&&t1>=10&&t2<0&&t2>=26&&t3<0&&t3>=26){
		
		}
	}
}

int main(int argc,char*argv[]){
	string line;
	while(cin>>line){
		cout << get_sub_palindrome(string s) << endl;		
	}
}
