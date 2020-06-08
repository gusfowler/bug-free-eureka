import java.io.Serializable;

//Assignment #: Arizona State University CSE205 #8
//Name: August Fowler
//StudentID: 1214774210
//Lecture: MW 6-715p
//Description: The Assignment 8 class displays a menu of choices to a user
//    and performs the chosen task. It will keep asking a user to
//    enter the next choice until the choice of 'Q' (Quit) is
//    entered.

public class Food implements Serializable, Comparable<Food>
{
    private String category;
    private String name;
    private int id;

    //constructor
    public Food(String nCategory, String nName, int nId)
    {
		category = nCategory;
        name = nName;
        id = nId;
    }

    //accessors & mutators
    public String getCategory()
    {
        return category;
    }

    public void setCategory(String nCategory)
    {
		category = nCategory;
    }

    public String getName()
    {
		 return name;
    }

    public void setName(String nName)
    {
		name = nName;
    }

    public int getId()
    {
        return id;
    }

    public void setId(int nId)
    {
		id = nId;
    }

    public String toString()
    {
        return "Category: " + category + "\t\tName: " + name + "\t\tID: " + id + "\n";
    }

	@Override
	public int compareTo(Food o) {
		// TODO Auto-generated method stub
		int result = 0;
		if (category.equals(o.getCategory())) {
			result = name.compareTo(o.getName());
		}
		else {
			result = category.compareTo(o.getCategory());
		}
		return result;
	}
}