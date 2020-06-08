// Assignment #: 2
// Name        : Gus (August) Fowler
// StudentID   : 1214774210
// Lecture     : MW 6-715p
// Description : 

import java.util.Scanner;
public class Assignment2 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);    		// init scanner
		
		int input = -1;									// init input var
		
		int minimum =0, sumPositiveEven = 0, totalNegative = 0, sumDivideThree = 0;		// init computed vars
		while (input != 0) {
			input = scan.nextInt();		// take integer input from user
			
			if (minimum > input || minimum == 0) {
				minimum = input;			// determine if minimum and store
			}
			
			if (input % 2 == 0) {
				sumPositiveEven += input;	// compute sum of positive even numbers
			}
			
			if (input < 0) {
				totalNegative += 1;			// count negative numbers
			}
			
			if (input % 3 == 0) {
				sumDivideThree += input;		// compute sum of inputs that are divisible by 3
			}
			
		}
		
		System.out.print("The minimum integer is " + minimum + "\nThe sum of positive even integers is " + sumPositiveEven + "\nThe count of negative integers is " + totalNegative + "\nthe sum of numbers divisible by 3 is " + sumDivideThree);
	}
}
