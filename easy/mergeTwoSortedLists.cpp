#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // struct ListNode* mid = malloc(sizeof(struct ListNode)); // impossible in C++ but allowable in C
        if(list2 == nullptr)
            return list1;
        
        struct ListNode* list1next,*list2next,*list2prev;
        int list2val;
        struct ListNode* start = list2;
        
        while(list1 != nullptr){
            if(list1->val <= list2->val){
                //save pointers and values for swapping
                list1next = list1->next;
                list2val = list2->val;
                list2next = list2->next;
                
                //list2 now gets list1's smaller value and point to list1 node which will contain the larger value
                list2->val = list1->val;
                list2->next = list1;

                //list1 now gets list2's larger value, point to the next list2 node
                list1->val = list2val;
                list1->next = list2next;

                //the next list1 node is examined
                list1 = list1next;
            }
            else if(list1->val > list2->val){
                list2prev = list2;
                list2 = list2->next;
                if(list2 == nullptr){
                    list2prev->next = list1;
                    return start;
                }
            }
        }
        return start;
    }
};

ListNode* convertToListNode(int arr[], int size){
    ListNode * list, *start, *next;

    start = nullptr; // start = list; // can not do this yet since otherwise, new ListNode will change the address
    if(arr){
        list = new ListNode(arr[0],nullptr);
        start = list;
        for(int i = 1;i < size;i++){
            list->next = new ListNode(arr[i],nullptr);
            list = list->next;
        }
    }
    return start;
}

void printList(ListNode* list){
    while(list != nullptr){
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,4};
    int arr2[] = {1,3,4};
    // Edge case 1 will not work * I need to fix later
    // int arr[] = {1};
    // int arr2[] = {};
    // Edge case 2 will not work
    // int arr[] = {};
    // int arr2[] = {1};

    //printList(convertToListNode(arr,sizeof(arr)/sizeof(arr[0]))); //test
    struct ListNode * list1,*list2;
    list1 = convertToListNode(arr,sizeof(arr)/sizeof(arr[0]));
    list2 = convertToListNode(arr2,sizeof(arr2)/sizeof(arr2[0]));
    Solution s;
    printList(s.mergeTwoLists(list1,list2));

    return 0;
}