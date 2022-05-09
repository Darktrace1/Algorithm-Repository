#include <cstdint>
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int RecordChar_Count(0);

void PUSH(int Data, char *RecordChar)
{
	s.push(Data);
	//cout << "+" << endl;
	RecordChar[RecordChar_Count++] = '+';
}

void POP(char *RecordChar)
{
	//cout << "-" << endl;
	RecordChar[RecordChar_Count++] = '-';
	s.pop();
}

int main(void)
{
	int N;
	cin >> N;
	cin.ignore();

	int i, j;
	int *RecordNum = new int[N+1];
	char *RecordChar = new char[3*N];
	for (i = 1; i <= N; i++)
		cin >> RecordNum[i];

	bool status(true);
	int InputData(0), inNum(0), size;
	for (i = 1; i <= N; i++)
	{
		InputData = RecordNum[i];
	
		if (s.empty() || s.top() < InputData)
		{
			size = InputData - inNum;
			for (j = 0; j < size; j++)
				PUSH(++inNum, RecordChar);
		} 
		else if (s.top() > InputData) 
		{
			status = false;
			break;
		}

		if (s.top() == InputData)
			POP(RecordChar);
	}
	
	if (!status)
		cout << "NO\n";
	else
		for (i = 0; i < RecordChar_Count; i++)
			cout << RecordChar[i] << "\n";

	delete[] RecordNum;
	return 0;
}
