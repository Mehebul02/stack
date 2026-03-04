#include <stdio.h>
#define Max 5

void display_array(int datarr[])
{
	int i; //looping variable
	printf("\nARRAY: ");
	for(i=0; i<MAX; i++)
	{
		printf("%d ", datarr[i]);
	}
}

int insert_element_by_position (int datarr[], int value, int position)
{

    int index = position-1;
    int i;

    if ( position <1 || position > Max)
    {
        printf("\nThe position selection of the outside the array.")
        return -1;
    }

    if(Max ==1)
    {
        datarr[Max-1] = value;
        printf("\nElement was added in a position", value, position);
        return 0;
    }

    for (i=Max-2; i>=index; i--)
    {
        datarr[i+1] = datarr[i]
    }
    datarr[index]= value;
    printf("\nElement was added the position", value,position);
    return 0;
}

int delete_element_value(int datarr[], int rem_value )
int i;
int rem_index;
int found=0;

for (i =0; i<Max; i++)
{
    if(datarr[i]== rem_value)
    {
        rem_index=i;
        found = 1;
        break
    }
}

if( found ==0)
{

    prindf("\Given value to be removed watched not found", rem_value);
    return -1;

}
for (i=rem_index; i<=Max-2;i++)
{
    datarr[i]= datarr[i+1];

}
datarr[Max-1]= -1;
printf("\n Element was removed", rem_value);
return 0;
}

int delete_element_by_position(int datarr[], int position)
{
    int index = position-1;
    int i;

    if ( position <1 || position > Max)
    {
        printf("\n The position selected deleted of the outside array",)
        return -1;

    }

    if( Max ==1)
    {
        datarr[Max-1] =-1;
        printf("\n The position was deleted", position);
        return 0;

    }
    for (i = index; i<Max-1 ;i++)
    {
        datarr[i]= datarr[i+1];
    }
    datarr[Max-1] = -1;
    printf("\nElement in position %d was deleted.", position);

	return 0;
}

int main ()
{
    int arr []={44,5,6,7,3};
    display_array(arr);

    insert_element_by_position(arr,4,5);
    display_array(arr);

    delete_element_by_value(arr,3);
    display_array(arr);

    delete_element_by_position(arr,4);
    display_array(arr);
    return 0;
}
