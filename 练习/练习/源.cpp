#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
//////////////////////////////////////删除有序数组中的重复项//////////////////////////////
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {//思路是不做删除,只做覆盖,反正只看len
//        size_t nums_size = nums.size();
//        if (nums_size == 0 || nums_size == 1)return nums_size;
//        size_t idex = 1;
//        for (int i = 0; i < nums_size - 1; ++i) {
//            if (nums[i] == nums[i + 1])continue;
//            nums[idex++] = nums[i + 1];
//        }
//        return idex;
//    }
//    //int removeDuplicates(vector<int>& nums) {//思路无问题,但是调了多种方法以及迭代器,速度极其慢
//    //    if (nums.empty())return 0;
//    //    vector<int>::iterator left = nums.begin();
//    //    vector<int>::iterator right = left + 1;
//    //    while (right != nums.end()) {
//    //        if (*left != *right) {
//    //            ++right;
//    //            left = right - 1;        //不同的情况下,右值右移,左值更新
//    //        }
//    //        else {
//    //            right = nums.erase(right);//相同的情况下,删除右值,在接收新的迭代器
//    //        }
//    //    }
//    //    return nums.size();
//    //}
//};
//int main() {
//    vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
//    Solution s;
//    size_t len = s.removeDuplicates(nums);
//
//    cout << len << " nums = ";
//    for (int i = 0; i < len;++i)cout << nums[i] << " ";
//    cout << endl;
//    return 0;
//}
//////////////////////////////////////////杨辉三角//////////////////////////////////////////
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> triangle;
//        vector<int> layer;
//        triangle.push_back(layer);//最少一层,所以先造出一层
//        triangle[0].push_back(1);//填上初始数字一
//        if (numRows != 1) {
//            for (int i = 1; i < numRows; i++) {
//                vector<int> layer;
//                triangle.push_back(layer);//构造新层
//                triangle[i].push_back(1);//前后直接插1
//                vector<int>::iterator left = triangle[i - 1].begin();//上一层的最左边
//                vector<int>::iterator right = left + 1;
//                while (right != triangle[i - 1].end()) {
//                    triangle[i].push_back(*left+*right);//尾插新加的数字
//                    ++left;
//                    ++right;
//                }
//                triangle[i].push_back(1);
//           }
//        }
//        return triangle;
//    }
//};
//int main() {
//    Solution s;
//    vector<vector<int>> triangle = s.generate(5);
//    cout << triangle[4][1] << endl;
//    return 0;
//}
//////////////////////////////////只出现一次的数字//////////////////////////////////////
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        //线性时间复杂度,不开辟新空间
//        int num = 0;
//        for (const auto& e : nums)num = num ^ e;//异或
//        return num;
//    }
//};
//int main() {
//    Solution s;
//    vector<int> nums = { 4,1,2,1,2 };
//    cout << s.singleNumber(nums) << endl;
//    return 0;
//}
//////////////////////////////vector迭代器失效////////////////////////////////////////////
//int main() {
//	int a[] = { 1,2,3,4,5 };
//	int n = sizeof(a) / sizeof(int);
//	vector<int> iv(a, a + n);
//	vector<int>::iterator it = find(iv.begin(),iv.end(),4);
//	//iv.insert(it, 0);
//	it = iv.erase(it);//物理上还在原位置,逻辑上不在原位置
//	for (const auto e : iv)
//		cout << e << " ";
//	cout << endl;
//	cout << *it << endl;
//	return 0;
//}
////////////////////////////////第一个唯一字符//////////////////////////////////////
//class Solution {
//public:
//    /*int firstUniqChar(string s) {
//        for (int i = 0; i < s.length(); i++) {
//            int pos = s.find(s[i], i + 1);
//            if (pos == string::npos)return i;
//        }
//        return -1;
//    }*/
//    int firstUniqChar(string s) {
//        int hash[30] = { 0 };
//        for (int i = 0; i < s.length(); i++) {
//            ++hash[s[i] - 'a'];
//        }
//        for (int i = 0; i < s.length(); i++) {
//            if (hash[s[i]-'a'] == 1)return i;
//        }
//        return -1;
//    }
//};
//int main() {
//    Solution S;
//    string s = "loveleetcode";
//    cout << S.firstUniqChar(s);
//    return 0;
//}
///////////////////////反转字符串中的单词////////////////////////////////////
//class Solution {
//public:
//    size_t _rever(string& s, size_t _start) {
//        size_t end = s.find(' ',_start);
//        if (end == string::npos)end = s.length();
//        size_t l = _start;
//        for (size_t r = end-1; l < r; l++, r--) {
//            char temp = s[l];
//            s[l] = s[r];
//            s[r] = temp;
//        }
//        return (end + 1);
//    }
//    string reverseWords(string s) {
//        size_t start = 0;
//        while (start <= s.length()) {
//            start = _rever(s, start);
//        }
//        return s;
//    }
//};
//int main() {
//    Solution S;
//    string s = "Let's take LeetCode contest";
//    cout << S.reverseWords(s);
//
//    return 0;
//}
/////////////////////////////////反转字符串//////////////////////////////////////////
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        int _length = s.length();
//        int _pos = 0;
//        while ((_length - _pos)>=k) {                   //剩余的字符大于等于k
//            if ((_length - _pos) >= (2 * k)) {          //剩余的字符大于等于2k
//                size_t l = _pos;                        //交换字符
//                for (size_t r = (_pos + k - 1); l < r; l++, r--) {
//                    char temp = s[l];
//                    s[l] = s[r];
//                    s[r] = temp;
//                }
//            }
//            else {                                      //剩余的字符小于2k
//                size_t l = _pos;
//                for (size_t r = (_pos + k - 1); l < r; l++, r--) {
//                    char temp = s[l];
//                    s[l] = s[r];
//                    s[r] = temp;
//                }
//            }
//            _pos += (2 * k);
//        }
//        if (_pos == (_length - 1))return s;             //剩余字符为零
//        size_t l = _pos;
//        for (size_t r = _length - 1; l < r; l++, r--) { //剩余字符小于k
//            char temp = s[l];
//            s[l] = s[r];
//            s[r] = temp;
//        }
//        return s;
//    }
//};
//int main() {
//    Solution s;
//    cout << s.reverseStr("abcdefgh", 3) << endl;
//	return 0;
//}

/////////////////////////字符串转整形数字////////////////////////////////////////////
//class Solution {
//public:
//    int StrToInt(string str) {
//        if (str.size() == 0)return 0;                           //字符串为空返回
//        size_t index = str.find_first_not_of("+-1234567890");   //出现"+-1234567890"之外的字符返回
//        if (index != string::npos) return 0;
//        int number = 0;
//        size_t found = str.find_first_of("+-");     //查看是否有"+-"
//        if (found == string::npos) {                //无"+-"情况
//            size_t multiple = 1;
//            for(int i = (str.size()-1);i>=0;i--){
//                number += (str[i] - 48) * multiple;
//                multiple *= 10;
//            }
//        }
//        else {                                      //有"+-"情况
//            if (found != 0)return 0;                //"+-"未在字符串首部
//            size_t multiple = 1;
//            if (str[found] == '-')multiple *= -1;   //首部为"-",数字变号
//            for (int i = (str.size() - 1); i > 0; i--) {
//                number += (str[i] - 48) * multiple;
//                multiple *= 10;
//            }
//        }
//        return number;
//    }
//};
//int main() {
//    string n("-133");
//    Solution s;
//    cout << s.StrToInt(n) << endl;
//	return 0;
//}

//////////////////////////字符串相加//////////////////////////////////////////////
//class Solution {
//public:
//	string add_string(string max, string min) {
//		int i = max.size() - 1;
//		int bit = 0;										//进位标记
//		for (int j = min.size() - 1; j >= 0; --i, --j) {	//从两字符串低位(尾部)开始相加
//			max[i] = max[i] + min[j] - 48 + bit;
//			bit = 0;
//			if (max[i] > 57) {								//进位操作
//				max[i] -= 10;
//				++bit;
//			}
//		}
//		while (bit == 1) {									//若还有进位,则继续相加
//			if (i < 0) {
//				max.insert(0, "1");							//已经到了最高位(头部),但还有进位,进行头插
//				break;
//			}
//			max[i] = max[i] + bit;
//			bit = 0;
//			if (max[i] > 57) {								//进位操作
//				max[i] -= 10;
//				++bit;
//			}
//			--i;
//		}
//		return max;
//	}
//public:
//	string addStrings(string num1, string num2) {			//将位数高的number放在前面
//		size_t size1 = num1.size();
//		size_t size2 = num2.size();
//		if (size1 >= size2) {
//			return add_string(num1, num2);
//		}
//		else {
//			return add_string(num2, num1);
//		}
//	}
//};
//
//int main() {
//	string num1("999");
//	string num2("1");
//	Solution n;
//	string m = n.addStrings(num1, num2);
//	cout << m << endl;
//	return 0;
//}