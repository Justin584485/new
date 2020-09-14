#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(){
	ifstream infile("lth.txt");
	string temp;
	while(getline(infile,temp)){
		cout<<temp;
	}
	infile.close();
}
