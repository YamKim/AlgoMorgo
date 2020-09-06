#include <iostream>
#include <vector>

using namespace std;

string code;

string reverse(string::iterator &it) {
	char head = *it;
	++it;
	// 만약, 시작이 'b' 혹은 'w'이면 바로 리턴.
	if (head == 'w' || head == 'b')
		return (string(1, head));
	// x부터 시작이면 part를 나누어 리턴
	string upperLeft	= reverse(it); 
	string upperRight	= reverse(it); 
	string lowerLeft	= reverse(it);  
	string lowerRight	= reverse(it);
	
	return ("x" + lowerLeft + lowerRight + upperLeft + upperRight);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> code;

	string::iterator beg = code.begin();
	cout << reverse(beg) << "\n";
	
	return (0);
}
