#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	return a.size() < b.size();
}

int main(void)
{
	int N, copyN;
	cin >> N;
	cin.ignore(32767, '\n');

	vector<string> vec;

	int countRep(0);
	bool rep;
	string *RecordStr, tempStr;
	RecordStr = new string [N];
	for (int i = 0; i < N; i++)
	{
		rep = false;
		getline(cin, tempStr);
		for (int j = 0; j < i; j++)
		{	
			if (tempStr == RecordStr[j])
			{
				rep = true;
				countRep++;
				break;
			}
		}
		if (!rep)
			RecordStr[i] = tempStr;
	}
	
	vec.assign(RecordStr, RecordStr+N);

	stable_sort(vec.begin(), vec.end());
	stable_sort(vec.begin(), vec.end(), compare);

	for (int i = countRep; i < vec.size(); i++)
		cout << vec[i] << "\n";
	
	delete[] RecordStr;
	return 0;
}
