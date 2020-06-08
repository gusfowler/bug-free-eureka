// Assignment : Arizona State U. CSE205 #4
// Name: Gus Fowler
// StudentID: 1214774210
// Lecture: Your section
// Description: Assignment 4 class displays a menu of choices to a user
//        and performs the chosen task. It will keep asking a user to
//        enter the next choice until the choice of 'Q' (Quit) is entered.
// Time spent:

import java.text.DecimalFormat;

public class Model {
	private DecimalFormat d = new DecimalFormat("0.00");
	private String modelName;
	private double cpuSpeed;
	private int ramSize;
	
	//constructor
	public Model() {
		modelName = "?";
		cpuSpeed = 0.0;
		ramSize = 0;
	}
	
	// overloaded constructor
	public Model(String mN, double cS, int rS) {
		modelName = mN;
		cpuSpeed = cS;
		ramSize = rS;
	}
	
	// getters
	public String getModel() {
		return modelName;
	}
	
	public double getCPU() {
		return cpuSpeed;
	}
	
	public int getRAM() {
		return ramSize;
	}
	
	// setters
	public void setModel(String newModel) {
		modelName = newModel;
	}
	
	public void setCPU(double newCPU) {
		cpuSpeed = newCPU;
	}
	
	public void setRAM(int newRam) {
		ramSize = newRam;
	}
	
	// output Model as a String
	public String toString() {
		return ("Model:\t" + modelName + "\nCPU:\t" + d.format(cpuSpeed) + "GHz\nRAM:\t" + ramSize +"GB\n");
	}
}
