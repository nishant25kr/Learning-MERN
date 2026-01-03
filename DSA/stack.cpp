#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    /**
     * stack operates in LIFO(last in first out)
     * operations in stack are push, top, pop, size
     */
    // stack using array
    class Stack
    {
    private:
        int topIndex;
        int arr[5];

    public:
        Stack()
        {
            topIndex = -1;
        }

        void push(int x)
        {
            if (topIndex == 4)
            {
                cout << "Stack Overflow\n";
                return;
            }
            arr[++topIndex] = x;
        }

        int top()
        {
            if (topIndex == -1)
            {
                cout << "Stack is empty\n";
                return -1;
            }
            return arr[topIndex];
        }

        void pop()
        {
            if (topIndex == -1)
            {
                cout << "Stack Underflow\n";
                return;
            }
            topIndex--;
        }

        int size()
        {
            return topIndex + 1;
        }

        bool isEmpty()
        {
            return topIndex == -1;
        }
    };

    vector<int> nums = {1, 2, 3, 4, 5};
    stack<int> st;
    

}