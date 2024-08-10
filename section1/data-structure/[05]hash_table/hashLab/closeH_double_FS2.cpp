// fold shift hashing  open or close
// key=student id 13 digit
// close double hashing
// cutting 6 in left
#include <iostream>
#include <sstream>

using namespace std;
#define ARRAYSIZE 20
#define STUDENT_ID_SIZE 14

unsigned long long hashFunction(char *key)
{
	key += 1;
	int i = 0, sum = 0;
	string s;
	while (*(key) != '\0')
	{
		if (i == 4)
		{
			stringstream geek;
			geek << s;
			int x = 0;
			geek >> x;
			sum += x;
			i = 0;
			s.clear();
		}
		else
		{
			s += *(key);
			key += 1;
			i++;
		}
	}
	stringstream geek;
	geek << s;
	int a = 0;
	geek >> a;
	sum += a;
	return (sum) % ARRAYSIZE;
}

long long int stoi(char *key)
{
	stringstream geek;
	geek << key;
	long long int a = 0;
	geek >> a;
	return a;
}

long long int DouHashFunc1(char *key)
{
	return STUDENT_ID_SIZE - (stoi(key) % STUDENT_ID_SIZE);
}

long long int DouHashFunc2(int i, char *key)
{
	int a = stoi(key);

	return (stoi(key) + i * DouHashFunc1(key)) % ARRAYSIZE;
}

int main()
{
	cout << "Enter your Student ID : ";
	char key[STUDENT_ID_SIZE];
	long long int arraylist[ARRAYSIZE];
	cin >> key;
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		arraylist[i] = -1;
	}

	int a = 0;
	int pos;
	arraylist[0] = 6504062650251;
	arraylist[1] = 6504062650251;
	arraylist[2] = 6504062650251;
	arraylist[3] = 6504062650251;
	arraylist[4] = 6504062650251;
	arraylist[5] = 6504062650251;
	arraylist[6] = 6504062650251;
	arraylist[7] = 6504062650251;
	arraylist[8] = 6504062650251;
	arraylist[9] = 6504062650251;
	arraylist[10] = 6504062650251;
	arraylist[14] = 6504062650251;
	arraylist[15] = 6504062650251;
	if (arraylist[hashFunction(key)] == -1)
	{
		arraylist[hashFunction(key)] = stoi(key);
		// cout<<"ABT";
	}
	else
	{
		// Double hashing
		int i = 1;
		while (i != -1)
		{
			int position = hashFunction(key) + (DouHashFunc2(i, key));
			cout << "Collusion Pos" << position << "//";
			cout << "Double Func2 :" << DouHashFunc2 << " | "
					 << "i=" << i << endl;

			if (arraylist[position] != -1)
			{
				i++;
				// cout<<" "<<"|"<<hashFunction(key)<<"end";
			}
			else
			{
				arraylist[position] = stoi(key);
				pos = position;
				i = -1;
			}
		}
		a = 1;
	}
	// loop print
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		cout << "Array " << i << " : " << arraylist[i] << endl;
	}
	cout << "You position is : " << pos;
}
//	cout<<hashFunction(key)<<endl;
