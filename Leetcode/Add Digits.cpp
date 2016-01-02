class Solution {
public:
	int addDigits(int num) {
		if (num < 10)
			return num;
		int sum = 0;
		while (num)
		{
			sum += num % 10;
			num /= 10;
		}
		addDigits(sum);
	}
};

/*O(1)���㷨 ��֤�����Եõ�����
class Solution {
public:
int addDigits(int num) {
if(num == 0)    return 0;
else if(num % 9)      return num % 9;
else    return 9;
}
};
*/