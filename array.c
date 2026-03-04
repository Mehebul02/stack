/*
CSE2111 Data Structures.
Array insertion, deletion and printing.
In this program we have created an array of size 5.
We can insert any element by position.
We can delete any element by position.
We can print the entire array.
*/

#include <stdio.h>
#define MAX 5

//--------------------------------------------
//This function displays contents of the array
//--------------------------------------------
void display_array(int datarr[])
{
	int i; //looping variable
	printf("\nARRAY: ");
	for(i=0; i<MAX; i++)
	{
		printf("%d ", datarr[i]);
	}
}


//-----------------------------------------
//This function inserts element by position
//-----------------------------------------
int insert_element_by_position(int datarr[], int value, int position)
{
	int index = position - 1;	//index is always 1 less than element position
	int i;						//looping variable

	//checking if given position is out of array limit
	if(position < 1 || position > MAX)
	{
		printf("\nThe position selected for insertion is outside the array.");
		return -1; //returning -1 to indicate
	}

	//The arraysize is 1, so simply replace that with given value. No loop is required.
	if(MAX == 1)
	{
		datarr[MAX-1] = value;
		printf("\nElement %d was added in position %d.", value, position);
		return 0;
	}

	//If array size is greater than 1, we shift all elements
	//by 1 position to create space for the new element to be inserted.
	//The last element will be removed from the array.
	//We start from the index of second last element i.e. MAX-2
	for(i = MAX-2; i>=index; i--)
	{
		datarr[i+1] = datarr[i];
	}
	datarr[index] = value; //insert element in the given index
	printf("\nElement %d was added in position %d.", value, position);

	return 0;
}

//-----------------------------------------
//This function deletes element by value
//-----------------------------------------
int delete_element_by_value(int datarr[], int rem_value)
{
	int i;			//looping variable
	int rem_index;	//this will hold the index of value to be removed, if found.
	int found = 0;	//found 0 means rem_value has not been found.
					//found 1 means rem_value has been found.

	//We are looping the array to see if the rem_value can be found in array
	for(i = 0; i<MAX; i++)
	{
		if(datarr[i]==rem_value)
		{
			rem_index = i;		//storing the index of the rem_value to be removed
			found = 1;	//rem_value has been found so set found = 1.
			break;
		}
	}

	//if rem_value is not found
	if(found == 0)
	{
		printf("\nGiven value %d to be removed was not found.", rem_value);
		return -1;
	}

	//removing element by shifting all the next elements by 1 position
	for(i=rem_index;i<=MAX-2;i++)
	{
		datarr[i] = datarr[i+1];
	}

	datarr[MAX-1]=-1; //setting the last item as -1

	printf("\nElement %d was removed.", rem_value);

	return 0;

}


//-----------------------------------------
//This function deletes element by position
//-----------------------------------------
int delete_element_by_position(int datarr[], int position)
{
	int index = position - 1;	//index is always 1 less than element position
	int i;						//looping variable

	//checking if given position is out of array limit
	if(position < 1 || position > MAX)
	{
		printf("\nThe position selected for deletion is outside the array.");
		return -1; //returning -1 to indicate
	}

	//The arraysize is 1, so simple delete that position. No loop is required.
	if(MAX == 1)
	{
		datarr[MAX-1] = -1;
		printf("\nElement in position %d was deleted.", position);
		return 0;
	}

	//If array size is greater than 1, then we shift all elements by 1 position.
	//The last element will be replaced by -1.
	//We start from the index of item and then loop till last element i.e. MAX-1
	for(i = index; i<MAX-1; i++)
	{
		datarr[i] = datarr[i+1];
	}
	datarr[MAX-1] = -1; //Set last element to -1
	printf("\nElement in position %d was deleted.", position);

	return 0;


}


int main()
{
	int arr[] = {23,77,24,65,55};				//Creating an array with 5 elements
	display_array(arr);							//display array

	//BELOW ARE SOME TESTS ON OUT CODE
	insert_element_by_position(arr, 89, 3);		//pass the array as argument, insert 89 in position 3
	display_array(arr);							//pass the array as argument,display array

	delete_element_by_position(arr, 4);			//pass the array as argument,delete element of position 4
	display_array(arr);							//pass the array as argument,display array

	delete_element_by_position(arr, 4);			//pass the array as argument,delete element of position 4
	display_array(arr);							//pass the array as argument,display array

	insert_element_by_position(arr, 122, 0);	//INVALID insertion attempt because 0 is not a position
	display_array(arr);							//pass the array as argument, display array

	delete_element_by_position(arr, 1);			//delete element of position 1
	display_array(arr);							//display array

	insert_element_by_position(arr, 211, 4);	//insert 211 in position 4
	display_array(arr);							//display array

	delete_element_by_position(arr, 7);			//INVALID deletion attempt because 7 is not position
	display_array(arr);							//display array

	delete_element_by_value(arr, 99);			//INVALID value deletion attempt
	display_array(arr);							//display array

	delete_element_by_value(arr, 89);			//delete element of value 89
	display_array(arr);							//display array

	return 0;
}
