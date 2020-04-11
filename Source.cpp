#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int const n = 4, m = 3;
	int A[m][n], B[m], C[n][m], D[m], AT[n][m];
	ifstream file;
	file.open("massiva.txt");

	if (!file) {
		cout << "Файл не открыт\n\n";
		return -1;
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			file >> A[i][j];

	file.close(); 
	cout << "Вектор а:" << endl;

	for (int i = 0; i < m; i++)	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
	}

	file.open("vektorb.txt");

	if (!file)	{
		cout << "Файл не открыт\n\n";
		return -1;
	}

	for (int i = 0; i < m; i++)
		file >> B[i];

	file.close(); 

	file.open("massivc.txt");

	if (!file)	{
		cout << "Файл не открыт\n\n";
		return -1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			file >> C[i][j];

	file.close(); cout << endl;
	cout << "\nМассив с: " << endl;
	for (int i = 0; i < n; i++)	{

		cout << endl;
		for (int j = 0; j < m; j++)		{
			cout << C[i][j] << " ";
		}
	}

	file.open("vektord.txt");

	if (!file)	{
		cout << "Файл не открыт\n\n";
		return -1;
	}

	for (int i = 0; i < m; i++)
		file >> D[i];

	file.close(); cout << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			AT[i][j] = A[j][i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			AT[i][j] *= 10;

	for (int i = 0; i < n; i++)	{
		cout << endl;
		for (int j = 0; j < m; j++)	{
			cout << AT[i][j] << " ";
		}
	}

	cout << endl;

	int F[n];

	for (int i = 0; i < n; i++)
		F[i] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			F[i] += B[j] * AT[i][j];

	int G[n];

	for (int i = 0; i < n; i++)
		G[i] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			G[i] += D[j] * C[i][j];

	for (int i = 0; i < n; i++)
		F[i] -= G[i];
	cout << endl;
	cout << "Результат : " << endl;
	cout << endl;

	for (int i = 0; i < n; i++)
		cout << F[i] << " ";
	cout << endl;
}