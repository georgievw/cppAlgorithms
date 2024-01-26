#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
private:
    vector<int> elements;
    int size;
public:
    MaxHeap()
    {
        size = 0;
    }
    void insert(int new_el)
    {
        elements.push_back(new_el);
        int index = size;
        size += 1;
        while (index != 0)
        {
            if (elements[index] > elements[(index-1)/2])
            {
                int buf = elements[index];
                elements[index] = elements[(index-1)/2];
                elements[(index-1)/2] = buf;
                index = (index-1)/2;
                continue;
            }
            break;
        }
    }
    int extract()
    {
        if (size == 0) return 0;
        int max_el = elements[0];
        elements[0] = elements.back();
        elements.pop_back();
        size -= 1;  
        int index = 0;
        while (true)
        {   
            int left_child_index = 2*index + 1, right_child_index = 2*index + 2;
            int left_child = left_child_index < size ? elements[left_child_index] : elements[index]-1;
            int right_child = right_child_index < size ? elements[right_child_index] : elements[index]-1;

            if (left_child > elements[index] & left_child >= right_child)
            {
                int buf = elements[index];
                elements[index] = elements[left_child_index];
                elements[left_child_index] = buf;
                index = left_child_index;
                continue;
            }
            if (right_child > elements[index] & left_child < right_child)
            {
                int buf = elements[index];
                elements[index] = elements[right_child_index];
                elements[right_child_index] = buf;
                index = right_child_index;
                continue;
            }
            break;
        }
        return max_el;
    }
    int getSize()
    {
        return size;
    }
    void print()
    {
        for (int el: elements)
        {
            cout << el << "  ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap heap;
    int n, command, new_el;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == 0)
        {
            cin >> new_el;
            heap.insert(new_el);
        }
        if (command == 1)
        {
            cout << heap.extract() << endl;
        }
    }
}