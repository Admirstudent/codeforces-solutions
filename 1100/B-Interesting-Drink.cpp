#include <bits/stdc++.h>

using namespace std;
ifstream fin("input.txt");

int DivideConquer(vector<int> &arr, int first, int last, int &coins, int &number_of_days)
{
    float length_of_array = (last - first) + 1;
    int middle = last - floor(length_of_array / 2);
    int middle_index = arr[middle - 1];
    
    if (coins >= middle_index)
    {
        number_of_days += (middle - first) + 1;
    }

    if (coins >= middle_index && coins < arr[middle])
    {
        return 0;
    }

    if (coins < middle_index)
    {
        DivideConquer(arr, first, middle - 1, coins, number_of_days);
    }

    else
    {
        DivideConquer(arr, middle + 1, last, coins, number_of_days);
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int days;
    cin >> days;

    for (int j = 0; j < days; j++)
    {
        int coins;
        cin >> coins;

        // less than lowest amount
        if (coins < arr[0])
        {
            cout << 0 << '\n';
            continue;
        }

        // more than max amount
        if (coins > arr[arr.size() - 1] || coins == arr[arr.size() - 1])
        {
            cout << arr.size() << '\n';
            continue;
        }
        
        int number_of_days = 0;

        DivideConquer(arr, 1, arr.size(), coins, number_of_days);

        cout << number_of_days << '\n';
    }
}