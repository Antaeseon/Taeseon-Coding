#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	string a, b, c;
	map<string, int>m;
	m.insert({ "black",0 });
	m.insert({ "brown",1 });
	m.insert({ "red",2 });
	m.insert({ "orange",3 });
	m.insert({ "yellow",4 });
	m.insert({ "green",5 });
	m.insert({ "blue",6 });
	m.insert({ "violet",7 });
	m.insert({ "grey",8 });
	m.insert({ "white",9 });

	cin >> a >> b >> c;
	int temp = 1;
	for (int i = 0; i < m[c]; i++) temp *= 10;
	cout<<(m[a] * 10 + m[b])*temp<<"\n";

}