///*
//дано к отсортированных массивов по n элементов. Создать отсортированный массив из них
//*/
//
//#include <iostream>
//#include <fstream>
//
//using std::cin;
//using std::cout;
//
//int** memory_alloc(int k, int n)
//{
//	int** arr = new int* [k];
//	for (size_t i = 0; i < k; i++)
//	{
//		arr[i] = new int[n];
//	}
//	return arr;
//}
//
//void fill_by_stream(std::istream& stream, int** arr, int k, int n)
//{
//	for (size_t i = 0; i < k; i++)
//	{
//		for (size_t j = 0; j < n; j++)
//		{
//			stream >> arr[i][j];
//		}
//	}
//}
//
//void print_arr(std::istream& stream, int** arr, int k, int n)
//{
//	for (size_t i = 0; i < k; i++)
//	{
//		for (size_t j = 0; j < n; j++)
//		{
//			cout << arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
//
//void min(int** arr, int k, int* ind, int& min_num, int& ind_nim_num)
//{
//	for (size_t i = 1; i < k; i++)
//	{
//		if (arr[i][ind[i]] < min_num)
//		{
//			min_num = arr[i][ind[i]];
//			ind_nim_num = i;
//		}
//	}
//}
//
////int mergeSortedArrs[] (int[] firstArr, int[] secondArr) {
////	int firstArrLen = firstArr.length, secondArrLen = secondArr.length;
////	int[] mergedArr = new int[firstArrLen + secondArrLen];
////	int firstArrIdx = 0, secondArrIdx = 0, mergedArrIdx = 0;
////
////	while (firstArrIdx < firstArrLen && secondArrIdx < secondArrLen) {
////		if (firstArr[firstArrIdx] < secondArr[secondArrIdx]) {
////			mergedArr[mergedArrIdx++] = firstArr[firstArrIdx++];
////		}
////		else {
////			mergedArr[mergedArrIdx++] = secondArr[secondArrIdx++];
////		}
////	}
////
////	while (firstArrIdx < firstArrLen) {
////		mergedArr[mergedArrIdx++] = firstArr[firstArrIdx++];
////	}
////	while (secondArrIdx < secondArrLen) {
////		mergedArr[mergedArrIdx++] = secondArr[secondArrIdx++];
////	}
////
////	return mergedArr;
////}
////
////int* mergeKSortedArr(int** kSortedArrs, int firstArrIdx, int lastArrIdx) 
////{
////	if (firstArrIdx == lastArrIdx) {
////		return kSortedArrs[firstArrIdx];
////	}
////	if (lastArrIdx - firstArrIdx == 1) {
////		return mergeSortedArrs(kSortedArrs[firstArrIdx], kSortedArrs[lastArrIdx]);
////	}
////
////	int midIdx = (lastArrIdx - firstArrIdx) / 2 + firstArrIdx;
////	int[] mergedFirstGroup = mergeKSortedArr(kSortedArrs, firstArrIdx, midIdx);
////	int[] mergedSecondGroup = mergeKSortedArr(kSortedArrs, midIdx + 1, lastArrIdx);
////
////	return mergeSortedArrs(mergedFirstGroup, mergedSecondGroup);
////}
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	std::fstream file("data.txt");
//	if (file)
//	{
//		int k, n;
//		file >> k >> n;
//		int** arr = memory_alloc(k, n);
//		fill_by_stream(file, arr, k, n);
//		print_arr(file, arr, k, n);
//
//		int* new_arr = new int[k * n];
//		int* ind = new int[k] {0};
//
//	}
//	else
//		cout << "Файл не найден\n";
//	
//
//
//}
//
///*
//int *mergeKArrays(int arr[][N], int k)
//{
//int* res = new int[k*k];
//for(int i=0;i<k;i++){ res[i]="0;" }="" vector<int=""> index(k,0);
//int in=0;
//for(int i=0;i<k*k;i++,in++){ int="" minvalue="INT_MAX;" int="" minindex="INT_MAX;" for(int="" j="0;j&lt;k;j++){" if(index[j]<k="" &&="" minvalue=""> arr[j][index[j]]){
//minvalue = arr[j][index[j]];
//minIndex=j;
//}
//}
//index[minIndex]+=1;
//res[i] = (minvalue);
//}
//return res;
//}
//*/


#include <vector> 
#include<iostream>
using namespace std;
vector<int> mergeTwoArrays(vector<int> l, vector<int> r)
{
    vector<int> ret;
    int l_in = 0, r_in = 0;
    while (l_in + r_in < l.size() + r.size())
    {
        if (l_in != l.size() && (r_in == r.size() || l[l_in] < r[r_in]))
        {
            ret.push_back(l[l_in]);
            l_in++;
        }
        else
        {
            ret.push_back(r[r_in]);
            r_in++;
        }
    }
    return ret;
}
vector<int> mergeArrays(vector<vector<int> > arr)
{
    vector<vector<int> > arr_s;
    while (arr.size() != 1)
    {
        arr_s.clear();
        for (int i = 0; i < arr.size(); i += 2)
        {
            if (i == arr.size() - 1)
                arr_s.push_back(arr[i]);
            else
                arr_s.push_back(mergeTwoArrays(arr[i], arr[i + 1]));
        }
        arr = arr_s;
    }
    return arr[0];
}
int main()
{
    int n;
    std::cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        vector<int> temp;
        for (int j = 0; j < x; j++)
        {
            int p;
            cin >> p;
            temp.push_back(p);
        }
        v.push_back(temp);
    }
    vector<int>output = mergeArrays(v);
    for (auto u : output)
    {
        cout << u << " ";
    }
    cout << endl;
    return 0;
}