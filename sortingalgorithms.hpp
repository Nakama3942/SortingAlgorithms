/* **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                                                                              *
 * Copyright © 2021 Kalynovsky Valentin. All rights reserved.                   *
 *                                                                              *
 * Licensed under the Apache License, Version 2.0 (the "License");              *
 * you may not use this file except in compliance with the License.             *
 * You may obtain a copy of the License at                                      *
 *                                                                              *
 *     http://www.apache.org/licenses/LICENSE-2.0                               *
 *                                                                              *
 * Unless required by applicable law or agreed to in writing, software          *
 * distributed under the License is distributed on an "AS IS" BASIS,            *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.     *
 * See the License for the specific language governing permissions and          *
 * limitations under the License.                                               *
 *                                                                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

/* **************************************************************************** *
 * ---------------------------------------------------------------------------- *
 *                              Version: 1.1.0-dev                              *
 * ---------------------------------------------------------------------------- *
 * **************************************************************************** */

#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <iostream>
#include <ctime>
#include <random>
using namespace std;

template <typename type_array>
struct Array
{
    type_array *array;
    int array_size;
};

//class generator
//{
//public:
//};

class ArrayProcessing
{
public:
    enum ArrayStatus
    {
        SORTED,
        UNSORTED
    };
    template <typename type_array>
    static void generatedStruct(Array<type_array> *&ARRAY, const int &SIZE)
    {
        ARRAY->array_size = SIZE;
        ARRAY->array = new type_array[SIZE];
    }
    template <typename type_array>
    static void generatedArray(Array<type_array> *&ARRAY, const int &left_limit, const int &right_limit)
    {
        srand(time(NULL));
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            ARRAY->array[i] = left_limit + rand() % right_limit;
        }
    }
    template <typename type_array>
    static void swap(type_array &firstNumber, type_array &secondNumber)
    {
        type_array *temp = new type_array(firstNumber);
        firstNumber = secondNumber;
        secondNumber = *temp;
        delete (temp);
    }
    template <typename type_array>
    static void getMin(const type_array *Array, const int &array_size, type_array &point_min, ArrayStatus ArrStat = UNSORTED)
    {
        switch (ArrStat)
        {
        case UNSORTED:
            point_min = Array[0];
            for (int i = 1; i < array_size; i++)
            {
                if (point_min > Array[i])
                {
                    point_min = Array[i];
                }
            }
            break;
        case SORTED:
            point_min = Array[0];
            break;
        }
    }
    template <typename type_array>
    static void getMax(const type_array *Array, const int &array_size, type_array &point_max, ArrayStatus ArrStat = UNSORTED)
    {
        switch (ArrStat)
        {
        case UNSORTED:
            point_max = Array[0];
            for (int i = 1; i < array_size; i++)
            {
                if (point_max < Array[i])
                {
                    point_max = Array[i];
                }
            }
            break;
        case SORTED:
            point_max = Array[array_size - 1];
            break;
        }
    }
    template <typename type_array>
    static void getElementsNumber_lenear(Array<type_array> *&ARRAY, const type_array &required_element, Array<type_array> *&NumberPoints)
    {
        NumberPoints->array_size = 0;
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            if (required_element == ARRAY->array[i])
            {
                addElement<int>(NumberPoints, i);
            }
        }
        if (NumberPoints->array_size == 0)
        {
            throw -1;
        }
    }
    template <typename type_array>
    static void getElementNumber_binary(const type_array *Array, const int &left_limit, const int &right_limit, const type_array &required_element, int &number_point)
    {
        if (left_limit > right_limit)
        {
            throw -1;
        }
        int middle = left_limit + (right_limit - left_limit) / 2;
        if (Array[middle] == required_element)
        {
            number_point = middle;
        }
        if (Array[middle] > required_element)
        {
            getElementNumber_binary(Array, left_limit, middle - 1, required_element, number_point);
        }
        if (Array[middle] < required_element)
        {
            getElementNumber_binary(Array, middle + 1, right_limit, required_element, number_point);
        }
    }
    template <typename type_array>
    static void getOccurrencesOfSubstring(Array<type_array> *&ARRAY, Array<type_array> *&SUBARRAY, Array<type_array> *&Occurrences)
    {
        Occurrences->array_size = 0;
        for (int i = 0; i <= ARRAY->array_size - SUBARRAY->array_size; i++)
        {
            for (int j = 0; j < SUBARRAY->array_size; j++)
            {
                if (ARRAY->array[i + j] == SUBARRAY->array[j])
                {
                    if (SUBARRAY->array_size - j == 1)
                    {
                        addElement<int>(Occurrences, i);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if (Occurrences->array_size == 0)
        {
            throw -1;
        }
    }
    template <typename type_array>
    static void addElement(Array<type_array> *&ARRAY, const type_array &value)
    {
        if (ARRAY->array_size == 0)
        {
            ARRAY->array_size++;
            ARRAY->array = new int[ARRAY->array_size]{value};
        }
        else
        {
            type_array *temp_Array = new type_array[ARRAY->array_size];
            copy(temp_Array, ARRAY->array, ARRAY->array_size);
            delete[] ARRAY->array;
            int *limit = new int(ARRAY->array_size);
            ARRAY->array_size++;
            ARRAY->array = new type_array[ARRAY->array_size];
            copy(ARRAY->array, temp_Array, *limit);
            ARRAY->array[*limit] = value;
            delete (limit);
            delete[] temp_Array;
        }
    }
    template <typename type_array>
    static void reverse(Array<type_array> *&ARRAY)
    {
        int left_limit = 0, right_limit = ARRAY->array_size - 1;
        for (int i = 0; i < ARRAY->array_size / 2; i++)
        {
            swap(ARRAY->array[left_limit], ARRAY->array[right_limit]);
            left_limit++;
            right_limit--;
        }
    }
    template <typename type_array>
    static void copy(type_array *new_array, const type_array *old_array, const int &size_of_copied, int position_in_new_array = 0, int position_in_old_array = 0)
    {
        for (int i = 0; i < size_of_copied; i++)
        {
            new_array[i + position_in_new_array] = old_array[i + position_in_old_array];
        }
    }
    template <typename type_array>
    static void average(Array<type_array> *&ARRAY, type_array &average)
    {
        average = 0;
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            average += ARRAY->array[i];
        }
        average = average / ARRAY->array_size;
    }
    template <typename type_array>
    static void mediana(Array<type_array> *&ARRAY, type_array &mediana)
    {
        ARRAY->array_size % 2 == 0 ? mediana = (ARRAY->array[ARRAY->array_size / 2] + ARRAY->array[(ARRAY->array_size / 2) - 1]) / 2 : mediana = (ARRAY->array[ARRAY->array_size / 2]);
    }
    template <typename type_array>
    static void moda(Array<type_array> *&ARRAY, type_array &most_frequent, int &highest_frequency)
    {
        highest_frequency = 0;
        int current_frequency = 0;
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            current_frequency++;
            if (i == ARRAY->array_size - 1 || ARRAY->array[i] != ARRAY->array[i + 1])
            {
                if (current_frequency > highest_frequency)
                {
                    highest_frequency = current_frequency;
                    most_frequent = ARRAY->array[i];
                }
                current_frequency = 0;
            }
        }
    }
    template <typename type_array>
    static void modas(Array<type_array> *&ARRAY, Array<type_array> *&MostFrequents, int &highest_frequency)
    {
        type_array most_frequent;
        MostFrequents->array_size = 0, highest_frequency = 0;
        int current_frequency = 0;
        moda(ARRAY, most_frequent, highest_frequency);
        addElement<type_array>(MostFrequents, most_frequent);
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            if (most_frequent == ARRAY->array[i])
            {
                for (int j = i + highest_frequency; j < ARRAY->array_size; j++)
                {
                    current_frequency++;
                    if (j == ARRAY->array_size - 1 || ARRAY->array[j] != ARRAY->array[j + 1])
                    {
                        if (current_frequency == highest_frequency)
                        {
                            addElement<type_array>(MostFrequents, ARRAY->array[j]);
                        }
                        current_frequency = 0;
                    }
                }
                break;
            }
        }
    }
};

namespace Exchange_Sorts
{
    template <typename type_array>
    class BubbleSort
    {
    public:
        static void bubble_sort(type_array *Array, const int &array_size)
        {
            for (int i = 0; i < array_size; i++)
            {
                for (int j = 0; j < array_size - 1; j++)
                {
                    if (Array[j] > Array[j + 1])
                    {
                        ArrayProcessing::swap<type_array>(Array[j], Array[j + 1]);
                    }
                }
            }
        }
    };

    template <typename type_array>
    class CocktailShakerSort
    {
    public:
        static void cocktail_shaker_sort(type_array *Array, const int &array_size)
        {
            int leftMark = 1, rightMark = array_size - 1;
            while (leftMark <= rightMark)
            {
                for (int i = rightMark; i >= leftMark; i--)
                {
                    if (Array[i - 1] > Array[i])
                    {
                        ArrayProcessing::swap<type_array>(Array[i], Array[i - 1]);
                    }
                }
                leftMark++;
                for (int i = leftMark; i <= rightMark; i++)
                {
                    if (Array[i - 1] > Array[i])
                    {
                        ArrayProcessing::swap<type_array>(Array[i], Array[i - 1]);
                    }
                }
                rightMark--;
            }
        }
    };

    //class OddevenSort{};

    //class CombSort{};

    //class GnomeSort{};

    template <typename type_array>
    class QuickSort
    {
    public:
        static void quick_sort(type_array *Array, const int &left_limit, const int &right_limit)
        {
            type_array middle = Array[(left_limit + right_limit) / 2];
            int start = left_limit, finish = right_limit;
            do
            {
                while (Array[start] < middle)
                {
                    start++;
                }
                while (Array[finish] > middle)
                {
                    finish--;
                }
                if (start <= finish)
                {
                    ArrayProcessing::swap<type_array>(Array[start], Array[finish]);
                    start++;
                    finish--;
                }
            } while (start < finish);
            if (left_limit < finish)
            {
                quick_sort(Array, left_limit, finish);
            }
            if (start < right_limit)
            {
                quick_sort(Array, start, right_limit);
            }
        }
    };

    namespace Ineffective_Sorts
    {
        //class StoogeSort{};

        //class BogoSort{};
    }
}

namespace Selection_Sorts
{
    //class SelectionSort{};

    template <typename type_array>
    class HeapSort
    {
    public:
        static void heapify(type_array *Array, const int &count, const int &array_size)
        {
            int left = 2 * count + 1, large = count, right = 2 * count + 2;
            if (left < array_size && Array[left] > Array[large])
            {
                large = left;
            }
            if (right < array_size && Array[right] > Array[large])
            {
                large = right;
            }
            if (large != count)
            {
                ArrayProcessing::swap<type_array>(Array[count], Array[large]);
                heapify(Array, large, array_size);
            }
        }
        static void heap_sort(type_array *Array, const int &array_size)
        {
            for (int right = array_size / 2 - 1; right >= 0; right--)
            {
                heapify(Array, right, array_size);
            }
            for (int i = array_size - 1; i >= 0; i--)
            {
                ArrayProcessing::swap<type_array>(Array[0], Array[i]);
                heapify(Array, 0, i);
            }
        }
    };

    //class SmoothSort{};
}

namespace Insertion_Sorts
{
    template <typename type_array>
    class InsertSort
    {
    public:
        static void insert_sort(type_array *Array, const int &array_size)
        {
            for (int i = 0; i < array_size; i++)
            {
                for (int j = i; j > 0 && Array[j - 1] > Array[j]; j--)
                {
                    ArrayProcessing::swap<type_array>(Array[j - 1], Array[j]);
                }
            }
        }
    };

    //class ShellSort{};

    //class LibrarySort{};

    //class PatienceSort{};

    //class TreeSort{};

    //class CycleSort{};
}

namespace Merge_Sorts
{
    template <typename type_array>
    class MergeSort
    {
    public:
        static void merge(type_array *Array, const int &left_limit, const int &middle_limit, const int &right_limit)
        {
            int start = left_limit, finish = middle_limit + 1;
            type_array *tempArray = new type_array[right_limit - left_limit + 1];
            for (int i = left_limit; i <= right_limit; i++)
            {
                if ((start <= middle_limit) && ((finish > right_limit) || (Array[start] < Array[finish])))
                {
                    tempArray[i - left_limit] = Array[start];
                    start++;
                }
                else
                {
                    tempArray[i - left_limit] = Array[finish];
                    finish++;
                }
            }
            for (int i = left_limit; i <= right_limit; i++)
            {
                Array[i] = tempArray[i - left_limit];
            }
            delete[] tempArray;
        }
        static void merge_sort(type_array *Array, const int &left_limit, const int &right_limit)
        {
            if (left_limit < right_limit)
            {
                int middle = left_limit + (right_limit - left_limit) / 2;
                merge_sort(Array, left_limit, middle);
                merge_sort(Array, middle + 1, right_limit);
                merge(Array, left_limit, middle, right_limit);
            }
        }
    };

    //class SlowSort{};

    //class StrandSort{};
}

namespace Noncomparison_Sort
{
    class CountingSort
    {
    public:
        static void counting_sort(int *Array, const int &array_size)
        {
            int min, max;
            ArrayProcessing::getMin<int>(Array, array_size, min);
            ArrayProcessing::getMax<int>(Array, array_size, max);
            int *tempArray = new int[max - min + 1];
            for (int i = 0; i < max - min + 1; i++)
            {
                tempArray[i] = 0;
            }
            for (int i = 0; i < array_size; i++)
            {
                tempArray[Array[i] - min] = tempArray[Array[i] - min] + 1;
            }
            for (int i = 0, j = min; j < max + 1; j++)
            {
                while (tempArray[j - min] != 0)
                {
                    Array[i] = j;
                    tempArray[j - min]--;
                    i++;
                }
            }
            delete[] tempArray;
        }
    };

    //class BucketSort{};

    class RadixSort
    {
    public:
        static void radix_sort(int *Array, const int &array_size)
        {
            int exp = 1, bit = 10, max;
            ArrayProcessing::getMax<int>(Array, array_size, max);
            int *tempArray = new int[array_size], *bucket = new int[bit];
            while (max / exp > 0)
            {
                for (int i = 0; i < bit; i++)
                {
                    bucket[i] = 0;
                }
                for (int i = 0; i < array_size; i++)
                {
                    bucket[(Array[i] / exp) % bit]++;
                }
                for (int i = 1; i < bit; i++)
                {
                    bucket[i] += bucket[i - 1];
                }
                for (int i = array_size - 1; i >= 0; i--)
                {
                    int current = (Array[i] % (exp * bit)) / exp;
                    bucket[current]--;
                    tempArray[bucket[current]] = Array[i];
                }
                for (int i = 0; i < array_size; i++)
                {
                    Array[i] = tempArray[i];
                }
                exp *= bit;
            }
            delete[] bucket;
            delete[] tempArray;
        }
    };

    //class PigeonholeSort{};

    //class BurstSort{};

    //class BeadSort{};

    //class PostmanSort{};
}

namespace Hybrid_Sorts
{
    //class TimSort{};

    //class BlockSort{};

    //class IntroSort{};

    //class SpreadSort{};
}

namespace Other_Sorts
{
    //class TopologicalSort{};

    //class BitonicSorter{};

    //class FlashSort{};

    //class PancakeSort{};

    //class SpaghettiSort{};
}

namespace Unknown_Sorts
{
    //class SampleSort{};
}

#endif // SORTINGALGORITHMS_H
