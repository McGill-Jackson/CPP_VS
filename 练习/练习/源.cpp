#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
//////////////////////////////////////ɾ�����������е��ظ���//////////////////////////////
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {//˼·�ǲ���ɾ��,ֻ������,����ֻ��len
//        size_t nums_size = nums.size();
//        if (nums_size == 0 || nums_size == 1)return nums_size;
//        size_t idex = 1;
//        for (int i = 0; i < nums_size - 1; ++i) {
//            if (nums[i] == nums[i + 1])continue;
//            nums[idex++] = nums[i + 1];
//        }
//        return idex;
//    }
//    //int removeDuplicates(vector<int>& nums) {//˼·������,���ǵ��˶��ַ����Լ�������,�ٶȼ�����
//    //    if (nums.empty())return 0;
//    //    vector<int>::iterator left = nums.begin();
//    //    vector<int>::iterator right = left + 1;
//    //    while (right != nums.end()) {
//    //        if (*left != *right) {
//    //            ++right;
//    //            left = right - 1;        //��ͬ�������,��ֵ����,��ֵ����
//    //        }
//    //        else {
//    //            right = nums.erase(right);//��ͬ�������,ɾ����ֵ,�ڽ����µĵ�����
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
//////////////////////////////////////////�������//////////////////////////////////////////
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> triangle;
//        vector<int> layer;
//        triangle.push_back(layer);//����һ��,���������һ��
//        triangle[0].push_back(1);//���ϳ�ʼ����һ
//        if (numRows != 1) {
//            for (int i = 1; i < numRows; i++) {
//                vector<int> layer;
//                triangle.push_back(layer);//�����²�
//                triangle[i].push_back(1);//ǰ��ֱ�Ӳ�1
//                vector<int>::iterator left = triangle[i - 1].begin();//��һ��������
//                vector<int>::iterator right = left + 1;
//                while (right != triangle[i - 1].end()) {
//                    triangle[i].push_back(*left+*right);//β���¼ӵ�����
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
//////////////////////////////////ֻ����һ�ε�����//////////////////////////////////////
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        //����ʱ�临�Ӷ�,�������¿ռ�
//        int num = 0;
//        for (const auto& e : nums)num = num ^ e;//���
//        return num;
//    }
//};
//int main() {
//    Solution s;
//    vector<int> nums = { 4,1,2,1,2 };
//    cout << s.singleNumber(nums) << endl;
//    return 0;
//}
//////////////////////////////vector������ʧЧ////////////////////////////////////////////
//int main() {
//	int a[] = { 1,2,3,4,5 };
//	int n = sizeof(a) / sizeof(int);
//	vector<int> iv(a, a + n);
//	vector<int>::iterator it = find(iv.begin(),iv.end(),4);
//	//iv.insert(it, 0);
//	it = iv.erase(it);//�����ϻ���ԭλ��,�߼��ϲ���ԭλ��
//	for (const auto e : iv)
//		cout << e << " ";
//	cout << endl;
//	cout << *it << endl;
//	return 0;
//}
////////////////////////////////��һ��Ψһ�ַ�//////////////////////////////////////
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
///////////////////////��ת�ַ����еĵ���////////////////////////////////////
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
/////////////////////////////////��ת�ַ���//////////////////////////////////////////
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        int _length = s.length();
//        int _pos = 0;
//        while ((_length - _pos)>=k) {                   //ʣ����ַ����ڵ���k
//            if ((_length - _pos) >= (2 * k)) {          //ʣ����ַ����ڵ���2k
//                size_t l = _pos;                        //�����ַ�
//                for (size_t r = (_pos + k - 1); l < r; l++, r--) {
//                    char temp = s[l];
//                    s[l] = s[r];
//                    s[r] = temp;
//                }
//            }
//            else {                                      //ʣ����ַ�С��2k
//                size_t l = _pos;
//                for (size_t r = (_pos + k - 1); l < r; l++, r--) {
//                    char temp = s[l];
//                    s[l] = s[r];
//                    s[r] = temp;
//                }
//            }
//            _pos += (2 * k);
//        }
//        if (_pos == (_length - 1))return s;             //ʣ���ַ�Ϊ��
//        size_t l = _pos;
//        for (size_t r = _length - 1; l < r; l++, r--) { //ʣ���ַ�С��k
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

/////////////////////////�ַ���ת��������////////////////////////////////////////////
//class Solution {
//public:
//    int StrToInt(string str) {
//        if (str.size() == 0)return 0;                           //�ַ���Ϊ�շ���
//        size_t index = str.find_first_not_of("+-1234567890");   //����"+-1234567890"֮����ַ�����
//        if (index != string::npos) return 0;
//        int number = 0;
//        size_t found = str.find_first_of("+-");     //�鿴�Ƿ���"+-"
//        if (found == string::npos) {                //��"+-"���
//            size_t multiple = 1;
//            for(int i = (str.size()-1);i>=0;i--){
//                number += (str[i] - 48) * multiple;
//                multiple *= 10;
//            }
//        }
//        else {                                      //��"+-"���
//            if (found != 0)return 0;                //"+-"δ���ַ����ײ�
//            size_t multiple = 1;
//            if (str[found] == '-')multiple *= -1;   //�ײ�Ϊ"-",���ֱ��
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

//////////////////////////�ַ������//////////////////////////////////////////////
//class Solution {
//public:
//	string add_string(string max, string min) {
//		int i = max.size() - 1;
//		int bit = 0;										//��λ���
//		for (int j = min.size() - 1; j >= 0; --i, --j) {	//�����ַ�����λ(β��)��ʼ���
//			max[i] = max[i] + min[j] - 48 + bit;
//			bit = 0;
//			if (max[i] > 57) {								//��λ����
//				max[i] -= 10;
//				++bit;
//			}
//		}
//		while (bit == 1) {									//�����н�λ,��������
//			if (i < 0) {
//				max.insert(0, "1");							//�Ѿ��������λ(ͷ��),�����н�λ,����ͷ��
//				break;
//			}
//			max[i] = max[i] + bit;
//			bit = 0;
//			if (max[i] > 57) {								//��λ����
//				max[i] -= 10;
//				++bit;
//			}
//			--i;
//		}
//		return max;
//	}
//public:
//	string addStrings(string num1, string num2) {			//��λ���ߵ�number����ǰ��
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