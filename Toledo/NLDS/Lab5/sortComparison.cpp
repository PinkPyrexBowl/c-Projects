#include <vector>
#include <math.h>

using namespace std;
void insertionSort(vector<int>&numbers)
{
    //j is initiallized outside the loop to limit the amount of initializations to 1 rather than i
    int j = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        //j is set to the value of i, as we are making sure that each value to left of the current i is less than the current i
        j = i;
        //loop continues for each case where our current value is less than that of the next value to the left of it, and while j is a valid index
        while(j < 0 && numbers[j] < numbers[j - 1])
        {
            //our current value is swapped with that to the left and our next value, j is decremented
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            j--;
        }
    }
}

void bucketSort(vector<int>&numbers, int numBuckets)
{
    //makes sure that numbers has a valid quantity of indicies
    if(numbers.size() < 1)
        return;
    vector<int> buckets[numBuckets];
    int maxValue = numbers[0];
    for(int i = 1; i < numbers.size(); i++)
    {
       if(numbers[i] > maxValue)
           maxValue = numbers[i];
    }

    for(int number : numbers)
    {
        int index = floor(number * numBuckets / (maxValue + 1));
        buckets[index].push_back(number);
    }
    
    vector<int> result;
    for(vector<int> bucket: buckets)
    {
       insertionSort(bucket); 
       for(int i : bucket)
       {
            result.push_back(i);
       }
    }

    numbers = result;
}

int RadixGetLength(int value)
{
    if(value == 0)
        return 1;
    
    int digits = 0;
    while(value != 0)
    {
        digits++;
        value /= 10;
    }
    return digits;
}

int RadixGetMaxLength(vector<int> numbers, int numbersSize)
{
    int maxDigits = 0;
    for(int i = 0; i < numbersSize; i++)
    {
        int digitCount = RadixGetLength(numbers[i]);
        if(digitCount > maxDigits)
            maxDigits = digitCount;
    }
    return maxDigits;
}

void radixSort(vector<int>& numbers)
{
    vector<vector<int>> buckets(10);
    int digitIndex;
    int maxDigits = RadixGetMaxLength(numbers, numbers.size());

    int pow10 = 1;
    for(digitIndex = 0; digitIndex < maxDigits; digitIndex++)
    {
        for(int i = 0; i < numbers.size(); i++)
        {
            int bucketIndex = int(abs(numbers[i] / pow10) % 10);
            buckets[bucketIndex].push_back(numbers[i]);
        }
        int copyBackIndex = 0;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < buckets[i].size(); j++)
            {
                numbers[copyBackIndex] = buckets[i].at(j);
                copyBackIndex++;
            }
            buckets[i].clear();
        }
        pow10 *=10;
    }
}
int main()
{

}
