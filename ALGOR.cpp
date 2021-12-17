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

#include "ALGOR.hpp"

template<typename type_array> void swap(type_array &firstNumber, type_array &secondNumber)
{
    type_array *temp = new type_array(firstNumber);
    firstNumber = secondNumber;
    secondNumber = *temp;
    delete (temp);
}

template<typename type_array> type_array minimum(const type_array *Array, const int &array_size)
{
    type_array point_min = Array[0];
    for (int i = 1; i < array_size; i++)
    {
        if (point_min > Array[i])
        {
            point_min = Array[i];
        }
    }
    return point_min;
}

template<typename type_array> type_array maximum(const type_array *Array, const int &array_size)
{
    type_array point_max = Array[0];
    for (int i = 1; i < array_size; i++)
    {
        if (point_max < Array[i])
        {
            point_max = Array[i];
        }
    }
    return point_max;
}

template<typename type_array> void addElement(type_array *&Array, int &array_size, const type_array &value)
{
    if (array_size == 0)
    {
        array_size++;
        Array = new type_array[array_size]{value};
    }
    else
    {
        type_array *temp_Array = new type_array[array_size];
        copy<type_array>(temp_Array, Array, array_size);
        delete[] Array;
        int limit = array_size;
        array_size++;
        Array = new type_array[array_size];
        copy<type_array>(Array, temp_Array, limit);
        Array[limit] = value;
        delete[] temp_Array;
    }
}

template<typename type_array> void copy(type_array *new_array, const type_array *old_array, const int &size_of_copied, int position_in_new_array, int position_in_old_array)
{
    for (int i = 0; i < size_of_copied; i++)
    {
        new_array[i + position_in_new_array] = old_array[i + position_in_old_array];
    }
}

template<typename type_array> Array<type_array> *create_struct(const int &SIZE)
{
    Array<type_array> *ARRAY = new Array<type_array>;
    ARRAY->array_size = SIZE;
    ARRAY->array = new type_array[SIZE];
    return ARRAY;
}

template<typename type_array> void remove_struct(Array<type_array> *&Array)
{
    delete[] Array->array;
    delete(Array);
}

template<typename type_array> void ARRAYDATA<type_array>::generatedData(const int &min_limit, const int &max_limit)
{
    srand(time(NULL));
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        this->ARRAY->array[i] = min_limit + rand() % (max_limit - min_limit);
    }
}

//setData();

template<typename type_array> void ARRAYDATA<type_array>::getData(Array<type_array> *&DATA)
{
    DATA = this->ARRAY;
}

template<typename type_array> Array<type_array> *ARRAYDATA<type_array>::getData()
{
    return this->ARRAY;
}

//reset();

template<typename type_array> void ARRAYDATA<type_array>::resize(const int &NEW_SIZE, const type_array &setElement)
{
    Array<type_array> *OLD_ARRAY = this->ARRAY, *NEW_ARRAY = new Array<type_array>;
    NEW_ARRAY->array_size = NEW_SIZE;
    NEW_ARRAY->array = new type_array[NEW_SIZE];
    if (OLD_ARRAY->array_size < NEW_ARRAY->array_size)
    {
        copy<type_array>(NEW_ARRAY->array, OLD_ARRAY->array, OLD_ARRAY->array_size);
        for(int i = OLD_ARRAY->array_size; i < NEW_ARRAY->array_size; i++)
        {
            NEW_ARRAY->array[i] = setElement;
        }
    }
    else
    {
        copy<type_array>(NEW_ARRAY->array, OLD_ARRAY->array, NEW_ARRAY->array_size);
    }
    this->ARRAY = NEW_ARRAY;
    delete[] OLD_ARRAY->array;
    delete(OLD_ARRAY);
}

template<typename type_array> void ARRAYDATA<type_array>::reverse()
{
    int left_limit = 0, right_limit = this->ARRAY->array_size - 1;
    for (int i = 0; i < this->ARRAY->array_size / 2; i++)
    {
        swap<type_array>(this->ARRAY->array[left_limit], this->ARRAY->array[right_limit]);
        left_limit++;
        right_limit--;
    }
}

template<typename type_array> void ARRAYDATA<type_array>::remove()
{
    delete[] this->ARRAY->array;
    delete this->ARRAY;
}

template<typename type_array> type_array ARRAYDATA<type_array>::getMin(ArrayStatus ArrStat)
{
    switch (ArrStat)
    {
    case UNSORTED:
        return minimum<type_array>(this->ARRAY->array, this->ARRAY->array_size);
    case SORTED:
        return this->ARRAY->array[0];
    }
    throw -1;
}

template<typename type_array> type_array ARRAYDATA<type_array>::getMax(ArrayStatus ArrStat)
{
    switch (ArrStat)
    {
    case UNSORTED:
        return maximum<type_array>(this->ARRAY->array, this->ARRAY->array_size);
    case SORTED:
        return this->ARRAY->array[this->ARRAY->array_size - 1];
    }
    throw -1;
}

template<typename type_array> Array<int> *ARRAYDATA<type_array>::lenear_searcher(const type_array &required_element)
{
    Array<int> *NumberPoints = new Array<int>;
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        if (required_element == this->ARRAY->array[i])
        {
            addElement<int>(NumberPoints->array, NumberPoints->array_size, i);
        }
    }
    if (NumberPoints->array_size == 0)
    {
        throw -1;
    }
    return NumberPoints;
}

template<typename type_array> int ARRAYDATA<type_array>::binary_searcher(const type_array &required_element)
{
    int position = 0;
    binary_searcher(required_element, position, 0, this->ARRAY->array_size - 1);
    return position;
}

template<typename type_array> void ARRAYDATA<type_array>::binary_searcher(const type_array &required_element, int &number_point, int left_limit, int right_limit)
{
    if (left_limit > right_limit)
    {
        throw -1;
    }
    int middle = left_limit + (right_limit - left_limit) / 2;
    if (this->ARRAY->array[middle] == required_element)
    {
        number_point = middle;
    }
    if (this->ARRAY->array[middle] > required_element)
    {
        binary_searcher(required_element, number_point, left_limit, middle - 1);
    }
    if (this->ARRAY->array[middle] < required_element)
    {
        binary_searcher(required_element, number_point, middle + 1, right_limit);
    }
}

template<typename type_array> Array<int> *ARRAYDATA<type_array>::searcherOccurrencesOfSubstring(Array<type_array> *&SUBARRAY, ArrayType ArrType)
{
    Array<int> *Occurrences = new Array<int>;
    for (int i = 0; i <= this->ARRAY->array_size - SUBARRAY->array_size; i++)
    {
        for (int j = 0; j < SUBARRAY->array_size; j++)
        {
            if (this->ARRAY->array[i + j] == SUBARRAY->array[j])
            {
                switch (ArrType)
                {
                case NUMBER:
                    if (SUBARRAY->array_size - j == 1)
                    {
                        addElement<int>(Occurrences->array, Occurrences->array_size, i);
                    }
                    break;
                case STRING:
                    if (SUBARRAY->array_size - j == 2)
                    {
                        addElement<int>(Occurrences->array, Occurrences->array_size, i);
                    }
                    break;
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
    return Occurrences;
}

template<typename type_array> type_array ARRAYDATA<type_array>::average()
{
    type_array average = 0;
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        average += this->ARRAY->array[i];
    }
    return average / this->ARRAY->array_size;
}

template<typename type_array> type_array ARRAYDATA<type_array>::mediana()
{
    return this->ARRAY->array_size % 2 == 0 ? (this->ARRAY->array[this->ARRAY->array_size / 2] + this->ARRAY->array[(this->ARRAY->array_size / 2) - 1]) / 2 : (this->ARRAY->array[this->ARRAY->array_size / 2]);
}

template<typename type_array> type_array ARRAYDATA<type_array>::moda(int &highest_frequency)
{
    type_array most_frequent = 0;
    highest_frequency = 0;
    int current_frequency = 0;
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        current_frequency++;
        if (i == this->ARRAY->array_size - 1 || this->ARRAY->array[i] != this->ARRAY->array[i + 1])
        {
            if (current_frequency > highest_frequency)
            {
                highest_frequency = current_frequency;
                most_frequent = this->ARRAY->array[i];
            }
            current_frequency = 0;
        }
    }
    return most_frequent;
}

template<typename type_array> Array<type_array> *ARRAYDATA<type_array>::modas(int &highest_frequency)
{
    Array<type_array> *MostFrequents = new Array<type_array>;
    highest_frequency = 0;
    int current_frequency = 0;
    type_array most_frequent = moda(highest_frequency);
    addElement<type_array>(MostFrequents->array, MostFrequents->array_size, most_frequent);
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        if (most_frequent == this->ARRAY->array[i])
        {
            for (int j = i + highest_frequency; j < this->ARRAY->array_size; j++)
            {
                current_frequency++;
                if (j == this->ARRAY->array_size - 1 || this->ARRAY->array[j] != this->ARRAY->array[j + 1])
                {
                    if (current_frequency == highest_frequency)
                    {
                        addElement<type_array>(MostFrequents->array, MostFrequents->array_size, this->ARRAY->array[j]);
                    }
                    current_frequency = 0;
                }
            }
            break;
        }
    }
    return MostFrequents;
}

template<typename type_array> void Exchange_Sorts::BubbleSort<type_array>::start_sort()
{
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        for (int j = 0; j < this->ARRAY->array_size - 1; j++)
        {
            if (this->ARRAY->array[j] > this->ARRAY->array[j + 1])
            {
                swap<type_array>(this->ARRAY->array[j], this->ARRAY->array[j + 1]);
            }
        }
    }
}

template<typename type_array> void Exchange_Sorts::CocktailShakerSort<type_array>::start_sort()
{
    int leftMark = 1, rightMark = this->ARRAY->array_size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
        {
            if (this->ARRAY->array[i - 1] > this->ARRAY->array[i])
            {
                swap<type_array>(this->ARRAY->array[i], this->ARRAY->array[i - 1]);
            }
        }
        leftMark++;
        for (int i = leftMark; i <= rightMark; i++)
        {
            if (this->ARRAY->array[i - 1] > this->ARRAY->array[i])
            {
                swap<type_array>(this->ARRAY->array[i], this->ARRAY->array[i - 1]);
            }
        }
        rightMark--;
    }
}

template<typename type_array> void Exchange_Sorts::QuickSort<type_array>::start_sort()
{
    quick_sort(0, this->ARRAY->array_size - 1);
}

template<typename type_array> void Exchange_Sorts::QuickSort<type_array>::quick_sort(const int &left_limit, const int &right_limit)
{
    type_array middle = this->ARRAY->array[(left_limit + right_limit) / 2];
    int start = left_limit, finish = right_limit;
    do
    {
        while (this->ARRAY->array[start] < middle)
        {
            start++;
        }
        while (this->ARRAY->array[finish] > middle)
        {
            finish--;
        }
        if (start <= finish)
        {
            swap<type_array>(this->ARRAY->array[start], this->ARRAY->array[finish]);
            start++;
            finish--;
        }
    } while (start < finish);
    if (left_limit < finish)
    {
        quick_sort(left_limit, finish);
    }
    if (start < right_limit)
    {
        quick_sort(start, right_limit);
    }
}

template<typename type_array> void Selection_Sorts::HeapSort<type_array>::start_sort()
{
    for (int right = this->ARRAY->array_size / 2 - 1; right >= 0; right--)
    {
        heapify(this->ARRAY->array, right, this->ARRAY->array_size);
    }
    for (int i = this->ARRAY->array_size - 1; i >= 0; i--)
    {
        swap<type_array>(this->ARRAY->array[0], this->ARRAY->array[i]);
        heapify(this->ARRAY->array, 0, i);
    }
}

template<typename type_array> void Selection_Sorts::HeapSort<type_array>::heapify(type_array *Array, const int &count, const int &array_size)
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
        swap<type_array>(Array[count], Array[large]);
        heapify(Array, large, array_size);
    }
}

template<typename type_array> void Insertion_Sorts::InsertSort<type_array>::start_sort()
{
    for (int i = 0; i < this->ARRAY->array_size; i++)
    {
        for (int j = i; j > 0 && this->ARRAY->array[j - 1] > this->ARRAY->array[j]; j--)
        {
            swap<type_array>(this->ARRAY->array[j - 1], this->ARRAY->array[j]);
        }
    }
}

template<typename type_array> void Merge_Sorts::MergeSort<type_array>::start_sort()
{
    merge_sort(this->ARRAY->array, 0, this->ARRAY->array_size - 1);
}

template<typename type_array> void Merge_Sorts::MergeSort<type_array>::merge_sort(type_array *Array, const int &left_limit, const int &right_limit)
{
    if (left_limit < right_limit)
    {
        int middle = left_limit + (right_limit - left_limit) / 2;
        merge_sort(Array, left_limit, middle);
        merge_sort(Array, middle + 1, right_limit);
        merge(Array, left_limit, middle, right_limit);
    }
}

template<typename type_array> void Merge_Sorts::MergeSort<type_array>::merge(type_array *Array, const int &left_limit, const int &middle_limit, const int &right_limit)
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

void Noncomparison_Sort::CountingSort::start_sort()
{
    int min = minimum<int>(ARRAY->array, ARRAY->array_size),
        max = maximum<int>(ARRAY->array, ARRAY->array_size);
    int *tempArray = new int[max - min + 1];
    for (int i = 0; i < max - min + 1; i++)
    {
        tempArray[i] = 0;
    }
    for (int i = 0; i < ARRAY->array_size; i++)
    {
        tempArray[ARRAY->array[i] - min] = tempArray[ARRAY->array[i] - min] + 1;
    }
    for (int i = 0, j = min; j < max + 1; j++)
    {
        while (tempArray[j - min] != 0)
        {
            ARRAY->array[i] = j;
            tempArray[j - min]--;
            i++;
        }
    }
    delete[] tempArray;
}

void Noncomparison_Sort::RadixSort::start_sort()
{
    int exp = 1, bit = 10, max = maximum<int>(ARRAY->array, ARRAY->array_size);
    int *tempArray = new int[ARRAY->array_size], *bucket = new int[bit];
    while (max / exp > 0)
    {
        for (int i = 0; i < bit; i++)
        {
            bucket[i] = 0;
        }
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            bucket[(ARRAY->array[i] / exp) % bit]++;
        }
        for (int i = 1; i < bit; i++)
        {
            bucket[i] += bucket[i - 1];
        }
        for (int i = ARRAY->array_size - 1; i >= 0; i--)
        {
            int current = (ARRAY->array[i] % (exp * bit)) / exp;
            bucket[current]--;
            tempArray[bucket[current]] = ARRAY->array[i];
        }
        for (int i = 0; i < ARRAY->array_size; i++)
        {
            ARRAY->array[i] = tempArray[i];
        }
        exp *= bit;
    }
    delete[] bucket;
    delete[] tempArray;
}

template void swap<int>(int &, int &);
template void swap<float>(float &, float &);
template void swap<char>(char &, char &);

template int minimum<int>(const int *, const int &);
template float minimum<float>(const float *, const int &);
template char minimum<char>(const char *, const int &);

template int maximum<int>(const int *, const int &);
template float maximum<float>(const float *, const int &);
template char maximum<char>(const char *, const int &);

template void addElement<int>(int *&, int &, const int &);
template void addElement<float>(float *&, int &, const float &);
template void addElement<char>(char *&, int &, const char &);

template void copy<int>(int *, const int *, const int &, int, int);
template void copy<float>(float *, const float *, const int &, int, int);
template void copy<char>(char *, const char *, const int &, int, int);

template Array<int> *create_struct<int>(const int &);
template Array<float> *create_struct<float>(const int &);
template Array<char> *create_struct<char>(const int &);

template void remove_struct<int>(Array<int> *&);
template void remove_struct<float>(Array<float> *&);
template void remove_struct<char>(Array<char> *&);

template void ARRAYDATA<int>::generatedData(const int &, const int &);
template void ARRAYDATA<float>::generatedData(const int &, const int &);
template void ARRAYDATA<char>::generatedData(const int &, const int &);

//setData();

template void ARRAYDATA<int>::getData(Array<int> *&);
template void ARRAYDATA<float>::getData(Array<float> *&);
template void ARRAYDATA<char>::getData(Array<char> *&);

template Array<int> *ARRAYDATA<int>::getData();
template Array<float> *ARRAYDATA<float>::getData();
template Array<char> *ARRAYDATA<char>::getData();

//reset();

template void ARRAYDATA<int>::resize(const int &, const int &);
template void ARRAYDATA<float>::resize(const int &, const float &);
template void ARRAYDATA<char>::resize(const int &, const char &);

template void ARRAYDATA<int>::reverse();
template void ARRAYDATA<float>::reverse();
template void ARRAYDATA<char>::reverse();

template void ARRAYDATA<int>::remove();
template void ARRAYDATA<float>::remove();
template void ARRAYDATA<char>::remove();

template int ARRAYDATA<int>::getMin(ArrayStatus);
template float ARRAYDATA<float>::getMin(ArrayStatus);
template char ARRAYDATA<char>::getMin(ArrayStatus);

template int ARRAYDATA<int>::getMax(ArrayStatus);
template float ARRAYDATA<float>::getMax(ArrayStatus);
template char ARRAYDATA<char>::getMax(ArrayStatus);

template Array<int> *ARRAYDATA<int>::lenear_searcher(const int &);
template Array<int> *ARRAYDATA<float>::lenear_searcher(const float &);
template Array<int> *ARRAYDATA<char>::lenear_searcher(const char &);

template int ARRAYDATA<int>::binary_searcher(const int &);
template int ARRAYDATA<float>::binary_searcher(const float &);
template int ARRAYDATA<char>::binary_searcher(const char &);

template void ARRAYDATA<int>::binary_searcher(const int &, int &, int, int);
template void ARRAYDATA<float>::binary_searcher(const float &, int &, int, int);
template void ARRAYDATA<char>::binary_searcher(const char &, int &, int, int);

template Array<int> *ARRAYDATA<int>::searcherOccurrencesOfSubstring(Array<int> *&, ArrayType);
template Array<int> *ARRAYDATA<float>::searcherOccurrencesOfSubstring(Array<float> *&, ArrayType);
template Array<int> *ARRAYDATA<char>::searcherOccurrencesOfSubstring(Array<char> *&, ArrayType);

template int ARRAYDATA<int>::average();
template float ARRAYDATA<float>::average();
template char ARRAYDATA<char>::average();

template int ARRAYDATA<int>::mediana();
template float ARRAYDATA<float>::mediana();
template char ARRAYDATA<char>::mediana();

template int ARRAYDATA<int>::moda(int &);
template float ARRAYDATA<float>::moda(int &);
template char ARRAYDATA<char>::moda(int &);

template Array<int> *ARRAYDATA<int>::modas(int &);
template Array<float> *ARRAYDATA<float>::modas(int &);
template Array<char> *ARRAYDATA<char>::modas(int &);

template void Exchange_Sorts::BubbleSort<int>::start_sort();
template void Exchange_Sorts::BubbleSort<float>::start_sort();
template void Exchange_Sorts::BubbleSort<char>::start_sort();

template void Exchange_Sorts::CocktailShakerSort<int>::start_sort();
template void Exchange_Sorts::CocktailShakerSort<float>::start_sort();
template void Exchange_Sorts::CocktailShakerSort<char>::start_sort();

template void Exchange_Sorts::QuickSort<int>::start_sort();
template void Exchange_Sorts::QuickSort<float>::start_sort();
template void Exchange_Sorts::QuickSort<char>::start_sort();

template void Exchange_Sorts::QuickSort<int>::quick_sort(const int &, const int &);
template void Exchange_Sorts::QuickSort<float>::quick_sort(const int &, const int &);
template void Exchange_Sorts::QuickSort<char>::quick_sort(const int &, const int &);

template void Selection_Sorts::HeapSort<int>::start_sort();
template void Selection_Sorts::HeapSort<float>::start_sort();
template void Selection_Sorts::HeapSort<char>::start_sort();

template void Selection_Sorts::HeapSort<int>::heapify(int *, const int &, const int &);
template void Selection_Sorts::HeapSort<float>::heapify(float *, const int &, const int &);
template void Selection_Sorts::HeapSort<char>::heapify(char *, const int &, const int &);

template void Insertion_Sorts::InsertSort<int>::start_sort();
template void Insertion_Sorts::InsertSort<float>::start_sort();
template void Insertion_Sorts::InsertSort<char>::start_sort();

template void Merge_Sorts::MergeSort<int>::start_sort();
template void Merge_Sorts::MergeSort<float>::start_sort();
template void Merge_Sorts::MergeSort<char>::start_sort();

template void Merge_Sorts::MergeSort<int>::merge_sort(int *, const int &, const int &);
template void Merge_Sorts::MergeSort<float>::merge_sort(float *, const int &, const int &);
template void Merge_Sorts::MergeSort<char>::merge_sort(char *, const int &, const int &);

template void Merge_Sorts::MergeSort<int>::merge(int *, const int &, const int &, const int &);
template void Merge_Sorts::MergeSort<float>::merge(float *, const int &, const int &, const int &);
template void Merge_Sorts::MergeSort<char>::merge(char *, const int &, const int &, const int &);
