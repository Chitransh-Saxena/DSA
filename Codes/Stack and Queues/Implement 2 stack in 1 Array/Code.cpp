/*
    In this question, we are given 1 array of some certain size (example 100)
    Now, first half of the array is treated as 1 stack (0-49)
    Second half of the array is treated as another stack (50-99)

    So, we have to implement the same basic pop and push operations for these stacks implemented in 1 array.

    So, the solution is simple, we implement the same functions but with few boundary checks.
*/

/*The structure of the class is
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};
*/


/* The method push to push element into the stack 2 */
void twoStacks :: push1(int x)
{   
    if(top1 - (top2-1)) {       // make sure the item is placed in correct part of the array
        top1++;
        arr[top1] = x;
    }
}
   
/* The method push to push element into the stack 2*/
void twoStacks ::push2(int x)
{
    if(top1 - (top2-1)) {
        top2--;
        arr[top2] = x;
    }
}
   
/* The method pop to pop element from the stack 1 */
//Return the popped element
int twoStacks ::pop1()
{
    if(top1 >= 0) {
        int item = arr[top1];
        top1--;
        return item;
    }
    else {
        return -1;
    }
}

/* The method pop to pop element from the stack 2 */
//Return the popped element
int twoStacks :: pop2()
{
    if(top2<size) {
        int item = arr[top2];
        top2++;
        return item;
    }
    else {
        return -1;
    }
}
