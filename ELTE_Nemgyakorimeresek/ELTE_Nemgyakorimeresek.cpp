
#include <iostream>
#include <unordered_map>

using namespace std;



struct Input 
{
	static const int n_MAX = 100000;
	static const int ei_MAX = 1000000000;
	int n;
	int k;
	int T[n_MAX];
};

struct Output
{
	int n;
	int* T;

	Output(int N)
	{
		n = N;
		T = new int[N];
	}
};


Input Beolvas();
Output Feldolgoz(Input);
void Kiir(Output);

int main()
{
//	Beolvas();
//	Feldolgoz(Beolvas());
	Kiir(Feldolgoz(Beolvas()));
}

Input Beolvas()
{
	Input be;
	cerr << "A meresi eredmenyek szama: \n";
	cin >> be.n;
	cerr << "A gyakorisagi korlat erteke: \n";
	cin >> be.k;
	cerr << "A meresi eredmenyek enterrel elvalasztva:\n";
	for (int i = 0; i < be.n; i++)
	{
		cin >> be.T[i];
	}
	return be;
}

Output Feldolgoz(Input be)
{
	unordered_map<int, int> nyilvantartas;
	int j;
	Output ki(be.n);

	for (int i = 0; i < be.n; i++)
	{
		if (nyilvantartas.find(be.T[i]) == nyilvantartas.end())
		{
			nyilvantartas[be.T[i]] = 1;
		}
		else
		{
			nyilvantartas[be.T[i]] += 1;
		}
	}


	cerr << "------------------\na nyilvantartas:\n------------------\n";
	j = 0;

	for(auto p : nyilvantartas)
	{
		cerr << "[" << p.first << "] = " << p.second << endl;
		if (p.second <= be.k)
		{
			ki.T[j++] = p.first;
		}
	}

	ki.n = j;
	cerr << "------------------\n";

	return ki;
}

void Kiir(Output ki)
{
	cout << ki.n;
	cerr << " db nem gyakori meresi eredmeny van, megpedig a kovetkezok:";
	cout << endl;
	for (int i = 0; i < ki.n; i++)
	{
		cout << ki.T[i] << endl;
	}
}
