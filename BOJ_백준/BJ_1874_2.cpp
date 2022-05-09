#include <cstdint>
#include <string>
#include <iostream>
#include <stack>
using namespace std;


int main(void)
{
	int N;
	cin >> N;
	cin.ignore();

	int i, j;
	int *RecordNum = new int[N+1];
	string RecordStr;
	for (i = 1; i <= N; i++)
		cin >> RecordNum[i];

	stack<int> s;
	bool status(true);
	int InputData(0), inNum(0), size;
	for (i = 1; i <= N; i++)
	{
		InputData = RecordNum[i];
		if (s.empty() || s.top() < InputData)
		{
			size = InputData - inNum;
			for (j = 0; j < size; j++)
			{
				s.push(++inNum);
				RecordStr += "+";
			}
		} 
		else if (s.top() > InputData) 
		{
			status = false;
			break;
		}

		if (s.top() == InputData)
		{
			s.pop();
			RecordStr += "-";
		}
	}
	
	if (!status)
		cout << "NO\n";

	else
		for (auto &elm : RecordStr)
			cout << elm << "\n";

	delete[] RecordNum;
	return 0;
}
