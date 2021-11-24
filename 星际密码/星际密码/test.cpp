//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main(int argc, char const* argv[]) {
//    const int max = 10010;
//    int fb[max] = { 0 }; fb[1] = 1; fb[2] = 1; fb[3] = 2;
//    for (int i = 4; i <= max; i++) {
//        fb[i] = (fb[i - 1] + fb[i - 2])%10000;
//    }
//    int n = 0;
//    while (cin >> n) {
//        for (int i = n; i > 0; i--) {
//            int num = 0;
//            cin >> num;
//            cout << setw(4) << setfill('0')<< fb[num+1];
//        }
//        cout << endl;
//    }
//    
//    return 0;
//}
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (cin >> str) {
		int num = 0;
		for (int i = 0; i < str.size(); i++) {
			num += str[i] - '0';
		}
		while (num > 9) {
			num = num % 10 + num / 10;
		}
		cout << num << endl;
	}
	return 0;
}