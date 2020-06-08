// Assignment : Arizona State U. CSE205 #4
// Name: Gus Fowler
// StudentID: 1214774210
// Lecture: Your section
// Description: Assignment 4 class displays a menu of choices to a user
//        and performs the chosen task. It will keep asking a user to
//        enter the next choice until the choice of 'Q' (Quit) is entered.
// Time spent:

import java.text.DecimalFormat;

public class Laptop {
	private DecimalFormat d = new DecimalFormat("'$'0.00");
	private String brandName;
	private Model model;
	private double price;
	
	//constructor
	public Laptop() {
		brandName = "?";
		model = new Model();
		price = 0.0;
	}
	
	// getters
	public String getBrand() {
		return brandName;
	}
	
	public Model getModel() {
		return model;
	}
	
	public double getPrice() {
		return price;
	}
	
	// setters
	public void setBrand(String newBrand) {
		brandName = newBrand;
	}
	
	public void setModel(String newModel, double newCPU, int newRAM) {
		model = new Model(newModel, newCPU, newRAM);
	}
	
	public void setPrice(double newPrice) {
		price = newPrice;
	}
	
	// convert Laptop to a String
	public String toString() {
		return ("\nBrand:\t" + brandName + "\n" + model.toString() + "Price:\t" + d.format(price) + "\n\n");
	}
}
