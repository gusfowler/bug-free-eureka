// Assignment #: Arizona State University CSE205 #8
//         Name: August Fowler
//    StudentID: 1214774210
//      Lecture: MW 6-715p
//  Description: The Assignment 8 class displays a menu of choices to a user
//               and performs the chosen task. It will keep asking a user to
//               enter the next choice until the choice of 'Q' (Quit) is
//               entered.

import java.io.Serializable;
import java.util.ArrayList;

public class GroceryStore implements Serializable {
	private static final long serialVersionUID = 5032628731504404707L;
	private ArrayList<Food> foodList;
	
	public GroceryStore() {
		foodList = new ArrayList<Food>();
	}
	
	public int idExists(int id) {
		for (int x = 0; x < foodList.size(); x++) {
			if (foodList.get(x).getId() ==  id) {
				return x;
			}
		}
		return -1;
	}
	
	public int categAndNameExists(String cat, String name) {
		for (int x = 0; x < foodList.size(); x++) {
			if (foodList.get(x).getCategory().equals(cat) && foodList.get(x).getName().equals(name)) {
				return x;
			}
		}
		return -1;
	}
	
	public boolean addFoodById(String cat, String name, int id) {
		for (int x = 0; x < foodList.size(); x++) {
			if (foodList.get(x).getId() == id) {
				return false;
			}
		}
		foodList.add(new Food(cat, name, id));
		return true;
	}
	
	public boolean removeById(int id) {
		for (int x = 0; x < foodList.size(); x++) {
			if (foodList.get(x).getId() == id) {
				foodList.remove(x);
				return true;
			}
		}
		return false;
	}
	
	public boolean removeByCategAndName(String cat, String name) {
		for (int x = 0; x < foodList.size(); x++) {
			if (foodList.get(x).getCategory().equals(cat) && foodList.get(x).getName().equals(name)) {
				foodList.remove(x);
				return true;
			}
		}
		return false;
	}
	
	public void sortByCategAndName() {
		Sorts.sort(foodList, new CategAndNameComparator());
	}
	
	public void sortById() {
		Sorts.sort(foodList, new IdComparator());
	}
	
	public String listFood() {
		if (foodList.size() > 0) {
			String working = "";
			for (int x = 0; x < foodList.size(); x++) {
				working += (Integer.toString(x + 1)+ ". " + foodList.get(x).toString() + "\n");
			}
			return working;
		}
		else {
			return "\nNo Food\n\n";
		}
	}
	
	public void closeGroceryStore() {
		foodList.clear();
	}
}
