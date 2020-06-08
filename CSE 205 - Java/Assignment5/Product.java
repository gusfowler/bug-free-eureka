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


public abstract class Product {
	protected String productId;
	protected int quantity;
	protected double unitPrice;
	protected double totalCost;
	
	public Product() {
		productId = "?";
		quantity = 0;
		unitPrice = 0.0;
	}
	
	public Product(String pI, int q, double uP) {
		productId = pI;
		quantity = q;
		unitPrice = uP;
	}
	
	public String getProductId() {
		return productId;
	}
	
	public String toString() {
		return ("\nProduct ID\t\t" + productId + "\n" + "Quantity:\t\t" + quantity + "\n" + "Unit Price:\t\t$" + unitPrice + "\n" + "Total Cost:\t\t$" + totalCost + "\n");
	}
	
	public abstract void computeTotalCost();
}