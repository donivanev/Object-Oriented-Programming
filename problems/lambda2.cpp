#include <iostream>
#include <functional>
#include <vector>
using namespace std;

template <typename T, typename K>
vector<K> map(const vector<T>& target, const function<K (T)>& mapFunction)
{
    vector<K> result;
    //vector<K> result = new vector<K>(target.size());

    for(T element : target)
    {
        result.push_back(mapFunction(element));
    }

    return result;
}

template <typename T>
vector<T> filter(const vector<T>& target, const function <bool (T)>& predicate)
{
    vector<T> result;

    for(T element : target)
    {
        if (predicate(element))
        {
            result.push_back(element);
        }
    }

    return result;
}

template <typename T, typename K>
K reduce(const vector<T> &target, const function<K (T, K)> reducer, const K &initialValue)
{
    K result = initialValue;

    for(T element : target)
    {
        result = reducer(element, result);
    }

    return result;
}

int main()
{

    vector<int> integers {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> squares = map<int, int>(integers, [](int x) { return x * x; });
    // map ot int kum int
    for (int element : squares)
    {
        cout << element;
    }

    vector<int> result = filter<int>(squares, [](int x) { return x % 2 == 0; });

    for (int element : result)
    {
        cout << element;
    }

    int sum = reduce<int, int>(result, [](int element, int res) { return element + res;}, 0);

    cout << sum;

    int sumOfSquaresOfEvens = 
    reduce<int, int>
    (
        map<int, int>
        (
            filter<int>
            (
                integers, [](int x) { return x % 2 == 0; }
            ), [](int x) { return x * x; }
        ),[](int element, int res) { return element + res; },
    0);

    return 0;
}