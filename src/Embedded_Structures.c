/*
 ============================================================================
 Name        : Embedded_Structures.c
 Author      : mohammed nabil
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 10
#define STUDENT_NUMBER 2

/*
 =================================================================================

  			  				Structures

 ================================================================================
 */
typedef struct Student
{
	char name[10];
	float degree;
	int counter;
}student;
/*
 =================================================================================

  								Variable

 ================================================================================
 */
student students[5];

/*
 =================================================================================

  								Prototyping

 ================================================================================
 */
void Print_arry (char *arr , int size);
void Scan_arry_char (char *arr , int size ,int *counter);
void Scan_float (float *arr );
char* degree_marks(float value);


/*
 =================================================================================

 									main

 ================================================================================
 */
int main(void) {


	printf("Please note that name-size {%d} , sudent-number %d and degree range (0-100)\r\n" , NAME_SIZE,STUDENT_NUMBER);

	for(int index = 0 ; index < STUDENT_NUMBER ; index++)
	{
		printf("Enter Name [%d] : " , index);

		Scan_arry_char(students[index].name , NAME_SIZE , &students[index].counter);


		while(1)
		{
			printf("Enter degree of %s : " , students[index].name);
			Scan_float(&students[index].degree);
			if(students[index].degree < 101 && students[index].degree > -1)
			{
				break;
			}
			printf("%s's degree range (0 - 100) .. please try again \n" , students[index].name);
		}


	}

	for(int index = 0 ; index < STUDENT_NUMBER ; index++)
	{
		printf("Degree of %s : %f , %s \n" , students[index].name , students[index].degree , degree_marks(students[index].degree));
	}

	return EXIT_SUCCESS;
}
/*
 * ===================================================================================
 *
 *								Print-Arrays
 *
 * ==================================================================================
 */
void Print_arry (char *arr , int size)
{

	for(int index = 0 ; index <= size ; index++)
	{
		printf("%c" ,arr[index]);
	}
	printf("\n");

}
/*
 * ===================================================================================
 *
 *								Scan-Arrays
 *
 * ==================================================================================
 */
void Scan_arry_char ( char *arr , int size ,int *counter)
{
	(*counter) = -1;
	char backup = 0;

	for(int index = 0 ; index < size ; index ++)
	{
		backup = arr[index];
		scanf("%c" , &arr[index]);
		if(arr[index] == '\n')
		{
			arr[index] = backup;

			break;
		}
		(*counter)++;
	}
}
void Scan_float (float *arr )
{

	char enter_press = 0;
	scanf("%f" , arr);
	scanf("%c" , &enter_press);

}

/*
 * ===================================================================================
 *
 *									Degrees
 *
 * ==================================================================================
 */
char* degree_marks(float value)
{
	if(value >= 90)
	{
		return "Excellent";
	}
	else if (value < 90 && value >= 80)
	{
		return "Very-Good";
	}
	else if (value < 80 && value >= 70)
	{
		return "Good";
	}
	else if (value < 70 && value >= 50)
	{
		return "Passed";
	}
	else
	{
		return "Failed";
	}


}
