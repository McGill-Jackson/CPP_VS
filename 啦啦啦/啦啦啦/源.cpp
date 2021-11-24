
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//using namespace std;
//class solution {
//public:
//	vector<string> topkfrequent(vector<string>& words, int k) {
//		map<string,int> m;
//		for (size_t i = 0; i < words.size(); i++) {
//			m.insert(make_pair(words[i], 0));
//			m.at(words[i])++;
//		}
//		multimap<int, string> n;
//		std::map<string, int>::reverse_iterator rit;
//		for (rit = m.rbegin(); rit != m.rend(); ++rit) {
//			n.insert(make_pair(rit->second, rit->first));
//		}
//		vector<string> word;
//		int i = 0;
//		std::map<int,string>::reverse_iterator rpt;
//		for (rpt = n.rbegin(); rpt != n.rend() && i < k; ++rpt,++i) {
//			word.push_back(rpt->second);
//		}
//		return word;
//	}
//};
//
//int main() {
//	vector<string> words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
//	solution so;
//	so.topkfrequent(words, 4);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	cout << a + b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//    int m, n, num1, num2, temp; 
//    cin >> num1 >> num2;
//    m = num1; 
//    n = num2;
//    while (num2 != 0)
//    {
//        temp = num1 % num2;
//        num1 = num2;
//        num2 = temp;
//    }
//    cout << num1 << endl;
//    cout << m * n / num1 << endl;
//}

#include<iostream>
using namespace std;
double fac(int);
double fac(int x) {
	static double f = 1;
	f *= x;
	return f;
}
int main(){
	int i;
	double count = 0;
	for (i = 1; i <= 30; i++){
		count += fac(i);
	}
	printf("%.2e\n", count);
	return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string num;
//	cin >> num;
//	int count = 0;
//	for (int i = 0; i < num.size(); i++) {
//		if (num[i] == '1')count++;
//	}
//	cout << count << endl;
//	return 0;
//}
//#include<stdio.h> 
//using namespace std;
//int main() {
//    double jc(int x);
//
//    double sum = 0;
//    for (int i = 1; i <= 30; i++) {
//        sum += jc(i);
//    }
//    printf("%.2E", sum);
//}
//double jc(int x) {
//    double result;
//    if (x == 1)
//    {
//        return 1.0;
//    }
//    else {
//        result = (double)x * jc(x - 1);
//
//        return result;
//    }
//}

