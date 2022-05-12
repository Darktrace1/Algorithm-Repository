#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{	
	int N;
	cin >> N;

	int i, index, name[26];
	string s;

	memset(name, 0, sizeof(name));

	for (i = 0; i< N; i++)
	{
		cin >> s;
		index = s.at(0) - 97;
		name[index]++;
	}

	int status(0);
	for (i = 0; i < 26; i++)
	{
		if (name[i] >= 5)
		{
			cout << (char)(i + 97);
			status = 1;
		}
	}
	
	if (!status)
		cout << "PREDAJA";

	return 0;
}
