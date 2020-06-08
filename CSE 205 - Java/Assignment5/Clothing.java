import java.text.NumberFormat;

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


public class Clothing extends Product{
	private String size;
	private String color;
	
	public Clothing(String pI, int q, double uP, String s, String c) {
		super(pI, q, uP);
		size = s;
		color = c;
	}
	
	public String toString() {
		return ("\nClothing:\n" + 
				"Product ID:\t\t" + this.productId + "\n" + 
				"Quantity:\t\t" + this.quantity + "\n" + 
				"Unit Price:\t\t$" + this.unitPrice + "\n" + 
				"Total Cost:\t\t$" + this.totalCost + "\n" + 
				"Size:\t\t" + size + "\n" + 
				"Color:\t\t" + color + "\n");
	}

	@Override
	public void computeTotalCost() {
		this.totalCost = (this.unitPrice * this.quantity);
	}
}
