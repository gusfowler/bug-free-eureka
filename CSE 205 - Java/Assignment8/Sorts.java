// Assignment #: Arizona State University CSE205 #8
//         Name: August Fowler
//    StudentID: 1214774210
//      Lecture: MW 6-715p
//  Description: The Assignment 8 class displays a menu of choices to a user
//               and performs the chosen task. It will keep asking a user to
//               enter the next choice until the choice of 'Q' (Quit) is
//               entered.

import java.util.ArrayList;
import java.util.Comparator;

public class Sorts {
	public static void sort(ArrayList<Food> foodList, Comparator<Food> foodComparator) {
		foodList.sort(foodComparator);
	}
}
