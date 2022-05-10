#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	int i, N, M, *RecordNum = new int[2*T];
	for (i = 0; i < 2*T; i += 2)
	{
		cin >> N >> M;
		RecordNum[i] = N;
		RecordNum[i+1] = M;
	}

	int inN, inM, *count = new int[T];
	string Num;
	for (i = 0; i < 2*T; i+=2)
	{
		inN = RecordNum[i];
		inM = RecordNum[i+1];
		for (int j = inN; j <= inM; j++)
		{
			Num = to_string(j);
			for (int k = 0; k < Num.length(); k++)
			{			
				if(Num.find("0") == string::npos)
					break;
				else if (Num.find("0", k) <= k)
					count[i/2]++;
			}
		}
	}

	for (i = 0; i < T; i++)
		cout << count[i] << "\n";

	delete[] count;
	delete[] RecordNum;
	return 0;	
}
