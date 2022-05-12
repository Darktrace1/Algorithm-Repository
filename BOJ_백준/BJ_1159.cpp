#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int i, index, i_name[26];
	string s_name;

	memset(i_name, 0, sizeof(i_name));

	for (i = 0; i< N; i++)
	{
		cin >> s_name;
		index = s_name.at(0) - 97;
		i_name[index]++;
	}

	int status(0);
	for (i = 0; i < 26; i++)
	{
		if (i_name[i] >= 5)
		{
			cout << (char)(i + 97);
			status = 1;
		}
	}
	if (!status)
		cout << "PREDAJA";

	return 0;
}
