// Ethan Deming
// 11/19/18
// COSC 2030 Fall 2018

#include "Lab7-edeming.h"
#include "RandomUtilities.h"
#include "WinTimer.h"
#include <iostream>
#include <algorithm>

using namespace std;

vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
}

vector <double> bubble(vector <double> input)
{
    bool hasChanged = true;
    int itemCount = input.size();

    while(hasChanged != false)
    {
        hasChanged = false;
        itemCount--;
        for(int i = 0; i < itemCount; i++)
        {
            if(input[i] > input[i+1])
            {
                swap(input[i], input[i+1]);
                hasChanged = true;
            }
        }
    }

    return input;
};

vector <double> insertion(vector <double> input)
{
    for(int i = 1; i < input.size()-1; i++)
    {
        double value = input[i];
        double index = i-1;

        while(index >= 0 && input[index] > value)
        {
            input[index+1] = input[index];
            index = index-1;
        }

        input[index+1] = value;
    }

    return input;
};

vector <double> selection(vector <double> input)
{
    for(int i = 0; i < input.size(); i++)
    {
        double min = i;

        for(int c = i+1; c < input.size(); c++)
        {
            if(input[c] < input[min])
            {
                min = c;
            }
        }

        if (min != i)
        {
            swap(input[i], input[min]);
        }
    }

    return input;
};

vector <double> mergeSort(vector <double> input)
{
    vector <double> left, right, result;

    if(input.size() <= 1)
    {
        return input;
    }
    else
    {
        int middle = input.size() / 2;

        for(int i = input.size()-1; i > middle-1; i--)
        {
            right.push_back(input[i]);
        }

        for(int i = middle-1; i > -1; i--)
        {
            left.push_back(input[i]);
        }

        left = mergeSort(left);

        right = mergeSort(right);

        if(left.back() <= right.front())
        {
            for(int i = right.size()-1; i > -1; i--)
            {
                left.push_back(right[i]);
            }

            return left;
        }

        while(left.size() > 0 && right.size() > 0)
        {
            if(left.front() <= right.front())
            {
                result.push_back(left.front());
                left.erase(left.begin());
            }
            else
            {
                result.push_back(right.front());
                right.erase(right.begin());
            }
        }

        if(left.size() > 0)
        {
            result.push_back(left.front());
        }
        if(right.size() > 0)
        {
            result.push_back(right.front());
        }

        return result;
    }
};

vector <double> quickSort(vector <double> input)
{
    vector <double> less, equal, greater, result;

    if(input.size() > 1)
    {
        double pivot = input[input.size()-1];

        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] == pivot)
            {
                equal.push_back(input[i]);
            }
            else if(input[i] < pivot)
            {
                less.push_back(input[i]);
            }
            else if(input[i] > pivot)
            {
                greater.push_back(input[i]);
            }

            less = quickSort(less);
            greater = quickSort(greater);

            for(int i = greater.size()-1; i > -1; i--)
            {
                result.push_back(greater[i]);
            }

            for(int i = equal.size()-1; i > -1; i--)
            {
                result.push_back(equal[i]);
            }

            for(int i = less.size()-1; i > -1; i--)
            {
                result.push_back(less[i]);
            }

            return result;
        }
    }
};

int main()
{
	cout << "Find the time to sort" << endl
		<< "-----------------------------" << endl << endl;

    cout << "Enter size for numbers: ";
    int n = 0;
    cin >> n;
    cout << "Enter seed for rand: ";
    unsigned int seed;
    cin >> seed;
    srand(seed);

    Timer get;
    get.start();
    vector<double> numbers = getNums(n, -n, n);
    get.stop();
    cout << "Constructed in " << get() << " seconds"
        << endl;

    Timer time;
    time.start();
    bubble(numbers);
    time.stop();
    cout << "Sorted in " << time() << " seconds" << endl << endl;

    cout << "Find the time to sort" << endl
		<< "-----------------------------" << endl << endl;

    cout << "Enter size for numbers: ";
    n = 0;
    cin >> n;
    cout << "Enter seed for rand: ";
    cin >> seed;
    srand(seed);

    // Construct a sorted list of numbers
    Timer get1;
    get1.start();
    numbers = getNums(n, -n, n);
    get1.stop();
    cout << "Constructed in " << get1() << " seconds"
        << endl;

    Timer time1;
    time1.start();
    insertion(numbers);
    time1.stop();
    cout << "Sorted in " << time1() << " seconds" << endl << endl;

    cout << "Find the time to sort" << endl
		<< "-----------------------------" << endl << endl;

    cout << "Enter size for numbers: ";
    n = 0;
    cin >> n;
    cout << "Enter seed for rand: ";
    cin >> seed;
    srand(seed);

    Timer get2;
    get2.start();
    numbers = getNums(n, -n, n);
    get2.stop();
    cout << "Constructed in " << get2() << " seconds"
        << endl;

    Timer time2;
    time2.start();
    selection(numbers);
    time2.stop();
    cout << "Sorted in " << time2() << " seconds" << endl << endl;

    cout << "Find the time to sort" << endl
		<< "-----------------------------" << endl << endl;

    cout << "Enter size for numbers: ";
    n = 0;
    cin >> n;
    cout << "Enter seed for rand: ";
    cin >> seed;
    srand(seed);

    Timer get3;
    get3.start();
    numbers = getNums(n, -n, n);
    get3.stop();
    cout << "Constructed in " << get3() << " seconds"
        << endl;

    Timer time3;
    time3.start();
    mergeSort(numbers);
    time3.stop();
    cout << "Sorted in " << time3() << " seconds" << endl << endl;

    cout << "Find the time to sort" << endl
		<< "-----------------------------" << endl << endl;

    cout << "Enter size for numbers: ";
    n = 0;
    cin >> n;
    cout << "Enter seed for rand: ";
    cin >> seed;
    srand(seed);

    Timer get4;
    get4.start();
    numbers = getNums(n, -n, n);
    get4.stop();
    cout << "Constructed in " << get4() << " seconds"
        << endl;

    Timer time4;
    time4.start();
    quickSort(numbers);
    time4.stop();
    cout << "Sorted in " << time4() << " seconds" << endl << endl;

     cout << "Find the time to sort" << endl
		<< "-----------------------------" << endl << endl;

    cout << "Enter size for numbers: ";
    n = 0;
    cin >> n;
    cout << "Enter seed for rand: ";
    cin >> seed;
    srand(seed);

    Timer get5;
    get5.start();
    numbers = getNums(n, -n, n);
    get5.stop();
    cout << "Constructed in " << get5() << " seconds"
        << endl;

    Timer time5;
    time5.start();
    sort(numbers.begin(), numbers.end());
    time5.stop();
    cout << "Sorted in " << time5() << " seconds" << endl << endl;

    return 0;
}
