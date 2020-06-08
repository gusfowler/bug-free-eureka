import java.io.IOException;
import java.util.Scanner;

// Assignment #: ASU CSE205 Assignment #9
//         Name: August Fowler
//    StudentID: 1214774210
//      Lecture: MW 6-715p
//  Description: this program reads in a sequence of numbers from standard
//  input until 0 is read and stores the numbers in an array, it then
//  compute the largest number, the count of even numbers (includes both postive and negative),
//  the number of -1 inside the array, and also compute the sum of numbers at
//  odd indexes (i.e. 0, 2, 4, ...), using recursion.


public class Assignment9
{
	private static int[] arrayInt = new int[100];
	private static int index = 0;
	
	/******************************************************************************
	  ***Complete the main() method. See above program description for details.
	******************************************************************************/	
	public static void main (String[] args) throws IOException
	{
		  try {
			  Scanner scan = new Scanner(System.in);
			  int next = scan.nextInt();
			  if (next != 0) {
				  arrayInt[index] = next;
				  index += 1;
				  main(args);
			  }
			  if (next == 0) {
				  System.out.println("The largest number is " + findMax(arrayInt, 0, index));
				  System.out.println("The total number of even integers is " + countEven(arrayInt,0,index));
				  System.out.println("The total number of -1 is " + countNegativeOne(arrayInt, index));
				  System.out.println("The sum of numbers at odd indexes is " + computeSumAtOddIndexes(arrayInt, index));
			  }
		  }
		  catch (Exception e) {
			  System.out.println("Exception");
			  e.printStackTrace();
		  }
		  
		  
	}
	
	/*************************************************************************************
	***(1)Complete the method. The method finds the largest number in the partial array
	***range from startIndex to endIndex
	*************************************************************************************/
	public static int findMax(int[ ] numbers, int startIndex, int endIndex)
	{
		if (endIndex - startIndex <= 1) 
		{
		     return Math.max(numbers[startIndex], numbers[endIndex]);
		} 
		else 
		{
		     int middle = (startIndex + endIndex) /2; //split into two parts to fix StackOverFlowException
		     int leftMax =  findMax(numbers, startIndex, middle);
		     int rightMax = findMax(numbers, middle + 1, endIndex);
		     return Math.max(leftMax, rightMax);
		}
	}
	
	/**************************************************************************************
	***(2)Complete the method. The method counts the number of even integers in the partial
	***arrya range from startIndex to endIndex
	*************************************************************************************/
	public static int countEven(int[ ] numbers, int startIndex, int endIndex)
	{
		int count = 0;
		if (startIndex < endIndex) {
			int working = numbers[startIndex];
			if (working % 2 == 0) {
				count += 1;
			}
			count += countEven(numbers, startIndex + 1, endIndex);
		}
		return count;
	}
	
	/*************************************************************************************
	***(3)Complete the method. The method counts the number of -1 inside an array with
	***   "count" numbers, index ranges from 0 to count-1
	*************************************************************************************/
	public static int countNegativeOne(int[ ] numbers, int count)
	{
		int count1 = 0;
		if (count >= 0) {
			if (numbers[count] == -1) {
				count1 += 1;
			}
			count1 += countNegativeOne(numbers, count - 1);
		}
		return count1;
	}
	
	/**************************************************************************************
	***(4)Complete the method. The method computes the sum of numbers at index 1, 3, 5, ...
	***  inside a partial array with "count" numbers inside, index ranges from 0 to count-1
	***************************************************************************************/
	public static int computeSumAtOddIndexes(int[ ] numbers, int count)
	{
		int sum = 0;
		if (count >= 0) {
			if (count % 2 == 1) {
				sum += numbers[count];
			}
			sum += computeSumAtOddIndexes(numbers, count - 1);
		}
		return sum;
	}
}// end of class Assignment9