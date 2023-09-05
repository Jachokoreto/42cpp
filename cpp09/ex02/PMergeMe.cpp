#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::~PMergeMe()
{
}
void printList(std::list<int> &list)
{
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl
              << std::endl;
}
const int INSERTION_SORT_THRESHOLD = 10; // Threshold for using insertion sort

// Insertion sort algorithm
void PMergeMe::insertionSortDeque(std::deque<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

// Merge phase of merge-insertion sort
void PMergeMe::mergeDeque(std::deque<int> &arr, int left, int mid, int right)
{
    std::deque<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    std::copy(temp.begin(), temp.end(), arr.begin() + left);
}

// Merge-insertion sort algorithm
void PMergeMe::mergeInsertionSortDeque(std::deque<int> &arr, int left, int right)
{
    if (left < right)
    {
        if (right - left <= INSERTION_SORT_THRESHOLD)
        {
            insertionSortDeque(arr, left, right);
        }
        else
        {
            int mid = left + (right - left) / 2;
            mergeInsertionSortDeque(arr, left, mid);
            mergeInsertionSortDeque(arr, mid + 1, right);
            mergeDeque(arr, left, mid, right);
        }
    }
}

double PMergeMe::sortInDeque(std::string expression)
{
    std::stringstream ss(expression);
    std::string token;
    clock_t start, end;

    while (std::getline(ss, token, ' '))
    {
        _deque.push_back(stoi(token));
    }

    start = clock();
    mergeInsertionSortDeque(_deque, 0, _deque.size() - 1);
    end = clock();

    double timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    // for (int i = 0; i < _deque.size(); ++i)
    // {
    //     std::cout << _deque[i] << " ";
    // }

    return timeTaken;
}

// void PMergeMe::insertionSortList(std::list<int> &arr, int left, int right)
// {
//     std::list<int>::iterator i = arr.begin();
//     std::advance(i, left);
//     std::list<int>::iterator j = i;
//     std::advance(j, 1);

//     while (i != arr.end())
//     {
//         std::list<int>::iterator key = i;
//         std::advance(key, 1);
//         std::list<int>::iterator k = i;
//         std::advance(k, -1);

//         while (k != arr.begin() && *k > *key)
//         {
//             std::advance(k, -1);
//         }

//         if (*k > *key)
//         {
//             arr.insert(k, *key);
//             j = arr.erase(key);
//         }
//         else
//         {
//             ++j;
//         }
//     }
// }

// do insertion sort with std::list
void PMergeMe::insertionSortList(std::list<int> &arr)
{
    std::list<int>::iterator key = ++(arr.begin());

    while (key != arr.end())
    {
        // std::list<int>::iterator key = it;
        // std::advance(key, 1);
        std::list<int>::iterator i = key;
        // std::advance(k, -1);

        while (--i != --(arr.begin()) && *i > *key)
            ;
        arr.insert(++i, *key);
        std::list<int>::iterator j = key;
        ++key;
        arr.erase(j);
    }
}

void PMergeMe::mergeList(std::list<int> &arr, std::list<int> &left, std::list<int> &right)
{
    std::list<int> temp;
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end())
    {
        if (*leftIt <= *rightIt)
        {
            temp.push_back(*leftIt);
            ++leftIt;
        }
        else
        {
            temp.push_back(*rightIt);
            ++rightIt;
        }
    }
    temp.insert(temp.end(), leftIt, left.end());
    temp.insert(temp.end(), rightIt, right.end());

    arr = temp;
}

void PMergeMe::mergeInsertionSortList(std::list<int> &arr)
{

    if (arr.size() <= INSERTION_SORT_THRESHOLD)
    {
        insertionSortList(arr);
    }
    else
    {
        std::list<int> left, right;
        std::list<int>::iterator mid = arr.begin();
        std::advance(mid, arr.size() / 2);

        left.splice(left.begin(), arr, arr.begin(), mid);
        right.splice(right.begin(), arr, mid, arr.end());

        // Recursively sort the two halves
        // left = mergeInsertionSort(left);
        // right = mergeInsertionSort(right);
        mergeInsertionSortList(left);
        mergeInsertionSortList(right);

        // Merge the sorted halves
        // arr = merge(left, right);
        mergeList(arr, left, right);
    }
}

double PMergeMe::sortInList(std::string expression)
{
    std::stringstream ss(expression);
    std::string token;
    clock_t start, end;

    while (std::getline(ss, token, ' '))
    {
        _list.push_back(stoi(token));
    }

    start = clock();
    mergeInsertionSortList(_list);
    end = clock();

    double timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    return timeTaken;
}

int PMergeMe::stoi(std::string str)
{
    std::stringstream ss(str);
    int val;
    ss >> val;
    return val;
}

void PMergeMe::run(char **argv)
{
    double timeDeque, timeList;

    std::string toSort = joinString(argv);

    timeDeque = sortInDeque(toSort);
    timeList = sortInList(toSort);

    try
    {
        checkSorting();
        std::cout << "Before: " << toSort << std::endl;
        std::cout << "After: ";
        for (std::deque<int>::iterator i = _deque.begin(); i != _deque.end(); ++i)
        {
            std::cout << *i << " ";
        }
        std::cout << std::endl;

        std::cout.precision(6);
        std::cout.width(10);
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque\t: " << timeDeque << "s" << std::endl;
        std::cout << "Time to process a range of " << _list.size() << " elements with std::list\t: " << timeList << "s" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        for (std::deque<int>::iterator i = _deque.begin(); i != _deque.end(); ++i)
        {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
        for (std::list<int>::iterator i = _list.begin(); i != _list.end(); ++i)
        {
            std::cout << *i << " ";
        }
    }
}

int PMergeMe::checkSorting()
{
    for (std::deque<int>::iterator i = _deque.begin(); i != _deque.end() - 1; ++i)
    {
        if (*i > *(i + 1))
        {
            throw std::runtime_error("Error: deque sequence not sorted");
        }
    }

    for (std::list<int>::iterator i = _list.begin(); i != --(_list.end()); ++i)
    {
        std::list<int>::iterator j = i;
        if (*i > *++j)
        {
            throw std::runtime_error("Error: list sequence not sorted");
        }
    }

    return 0;
}

std::string PMergeMe::joinString(char **argv)
{
    std::string str = "";
    for (int i = 0; argv[i] != NULL; ++i)
    {
        str += argv[i];
        str += " ";
    }
    return str;
}