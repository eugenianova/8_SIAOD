//Простого обмена (пузырек) 
//Шейкерная
//Простое слияние

#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector <int>& arr, int n);
void shaker_sort(vector <int>& arr, int n);
void merge(vector <int>& arr, int l, int r, int m);
void merge_sort(vector <int>& arr, int l, int r);

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> temp(n);

	for (int i = 0; i < n; i++) a[i] = rand() % 201 - 100;
	temp = a;
	unsigned int start_time = clock();
	bubble_sort(temp, n);
	unsigned int end_time = clock();
	cout << "bubble_sort, time: " << (end_time - start_time) / 1000.0 << endl;

	temp = a;
	start_time = clock();
	shaker_sort(temp, n);
	end_time = clock();
	cout << "shaker_sort, time: " << (end_time - start_time) / 1000.0 << endl;

	temp = a;
	start_time = clock();
	merge_sort(temp, 0, n - 1);
	end_time = clock();
	cout << "merge sort, time: " << (end_time - start_time) / 1000.0 << endl;
	//for (int i = 0; i < temp.size(); i++)
		//{
		//	cout << temp[i] << " ";
		//}
}

// Сортировка пузырьком
void bubble_sort(vector <int>& arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}
// Шейкерная сортировка
void shaker_sort(vector <int>& arr, int n)
{
	int left_el = 1;
	int right_el = n - 1;
	while (left_el <= right_el)
	{
		for (int i = right_el; i >= left_el; i--)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i - 1], arr[i]);
			}
		}
		left_el++;
		for (int j = left_el; j <= right_el; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
		right_el--;
	}
}
// Сортировка слиянием
void merge_sort(vector <int>& arr, int l, int r)
{
	if (l >= r) return;
	int m = l + (r - l) / 2;
	merge_sort(arr, l, m);
	merge_sort(arr, m + 1, r);
	merge(arr, l, r, m);
}
// Слияние
void merge(vector <int>& arr, int l, int r, int m)
{
	int n1 = m - l + 1; // Размер первого подмассива
	int n2 = r - m;
	vector <int> L(n1);
	vector <int> R(n2);
	// Создаем копии подмассивов
	for (int i = 0; i < n1; i++) L[i] = arr[l + i];
	for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

	int i, j, k;
	i = j = 0; k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	// Собираем оставшиеся элементы, если один из подмассивов закончился раньше:
	while (i < n1)
	{
		arr[k] = L[i];
		i++; k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++; k++;
	}
}