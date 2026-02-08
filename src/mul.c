#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *head_AR=NULL;                             //creating another list for temporary storage of elements
    node *tail_AR=NULL;
    node *tailR2=NULL;
    node *headR2=NULL;
    int carry=0,count=0;                        //initial carry and count =0;
    node *temp1=tail1;                          // for moving from tail to head temp1 variable for list1
    node *temp2=tail2;                          // for moving from tail to head temp2 variable for list2
    while(temp2){                               //until list2 becomes null.
        carry=0;                                // everytime carry is zero.
        for(int i=0;i<count;i++){               //for adding zeros in the R2 count var is required.
            insert_first(&headR2,&tailR2,0);    //inserting zeros
        }
        count++;                                //incrementing count.
        while(temp1){                           //UNTIL TEMP1 reaches null
            int num1=temp1->data;               //num1 is data from list1
            int num2=temp2->data;               //num2 is data from list2
            int mul=num1 * num2 +carry;         //multiplying both
            int data=mul%10;                    //if suppose 9*2 =18 we needd to store 8 only for that 18%10;
            carry=mul/10;                       
            if(count==1)
                insert_first(headR,tailR,data);
            else
                insert_first(&headR2,&tailR2,data);
            temp1=temp1->prev;
        }
        if(carry){
            if(count==1)
                insert_first(headR,tailR,carry);
            else
                insert_first(&headR2,&tailR2,carry);
        }
        addition(*tailR,tailR2,&head_AR,&tail_AR);
        delete_list(headR,tailR);
        delete_list(&headR2,&tailR2);
        *headR=head_AR;
        *tailR=tail_AR;
        head_AR=NULL;
        tail_AR=NULL;
        temp2=temp2->prev;
        temp1=tail1;
    }
    remove_pre_zeros(headR);
}
