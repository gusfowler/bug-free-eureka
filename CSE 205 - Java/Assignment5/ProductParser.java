// Assignment #: Arizona State University Assignment #5
//         Name: August Fowler
//    StudentID: 121-477-4210
//      Lecture: 1
//      Section: A
//  Description: The Assignment 5 class displays a menu of choices
//               (add a product, compute the total cost, search a product, list product,
//               quit, display menu) to a user.
//               Then it performs the chosen task. It will keep asking a user to
//               enter the next choice until the choice of 'Q' (Quit) is
//               entered.

import java.util.Scanner;

public class ProductParser {
	public Product parseStringToProduct(String lineToParse) {
		Scanner scan = new Scanner(lineToParse);
		scan.useDelimiter("/");
		
		Product prod;
		
		String type = scan.next();
		//System.out.println(type);
		
		if (type.equals("Clothing")) {
			prod = new Clothing(scan.next(), scan.nextInt(), scan.nextDouble(), scan.next(), scan.next());
		}
		else if (type.equals("Food")) {
			prod = new Food(scan.next(), scan.nextInt(), scan.nextDouble(), scan.next(), scan.nextDouble(), scan.next());
		}
		else {
			prod = null;
			//System.out.println("error in parsing");
		}
		
		return prod;
	}
}
