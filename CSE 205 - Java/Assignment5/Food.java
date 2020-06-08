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
import java.text.NumberFormat;

public class Food extends Product{
	private String name = "?";
	private double damageRate = 0.0;
	private String expirationDate = "08.20.2015";
	
	public Food(String pI, int q, double uP, String n, double dR, String eD) {
		super(pI, q, uP);
		name = n;
		damageRate = dR;
		expirationDate = eD;
	}
	
	public String toString() {
		NumberFormat percentF = NumberFormat.getPercentInstance();
		percentF.setMinimumFractionDigits(2);
		return ("\nFood:\n" + 
				"Product ID:\t\t" + this.productId + "\n" + 
				"Quantity:\t\t" + this.quantity + "\n" + 
				"Unit Price:\t\t$" + this.unitPrice + "\n" + 
				"Total Cost:\t\t$" + this.totalCost + "\n" + 
				"Food Name:\t\t" + this.name + "\n" + 
				"Damage Rate:\t\t" + percentF.format(this.damageRate) + "\n" + 
				"Expiration Date:\t" + this.expirationDate + "\n");
	}

	@Override
	public void computeTotalCost() {
		this.totalCost = (unitPrice * quantity) * (1 + damageRate);
		
	}
}
