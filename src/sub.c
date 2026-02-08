#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow=0;
    while(tail1){
        int sub=0;
        if(borrow==1){
            (tail1->data)--;
            borrow=0;
        }
        int num=0;
        if(tail2){
            num=tail2->data;
            tail2=tail2->prev;
        }
        if(tail1->data >= num){
            sub=tail1->data - num;
        }
        else{
            sub=((tail1->data)+10) - num;
            borrow=1;
        }

        insert_first(headR,tailR,sub);
        tail1=tail1->prev;
    }
    remove_pre_zeros(headR);
}
