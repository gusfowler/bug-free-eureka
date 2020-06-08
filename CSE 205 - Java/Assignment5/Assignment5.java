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

import java.io.*;         //to use InputStreamReader and BufferedReader
import java.util.*;       //to use ArrayList

public class Assignment5
{
   public static void main (String[] args)
   {
      char input1;
      String inputInfo = new String();
      String line = new String();
      boolean found;

     // ArrayList object is used to store drink objects
      ArrayList<Product> productList = new ArrayList<Product>();

      try
      {
         printMenu();     // print out menu

       // create a BufferedReader object to read input from a keyboard
         InputStreamReader isr = new InputStreamReader (System.in);
         BufferedReader stdin = new BufferedReader (isr);

         do
         {
            System.out.print("What action would you like to perform?\n");
            line = stdin.readLine().trim();
            input1 = line.charAt(0);
            input1 = Character.toUpperCase(input1);

            if (line.length() == 1)
            {
               switch (input1)
               {
                  case 'A':   //Add Product
                     System.out.print("Please enter a product information to add:\n");
                     inputInfo = stdin.readLine().trim();
                     productList.add(new ProductParser().parseStringToProduct(inputInfo));
                     break;

                  case 'C':   //Compute Total Costs
                	  double tC = 0.0;
                	  for (int x = 0; x < productList.size(); x++) {
                		  productList.get(x).computeTotalCost();
                	  }
                	  System.out.println("total costs computed\n");

                     break;

                  case 'S':   //Search for a product
                     System.out.print("Please enter a productId to search:\n");
                     inputInfo = stdin.readLine().trim();
                     int index = 0;
                     found = false;
                     for (int x = 0; x < productList.size(); x++) {
                    	 if (productList.get(x).productId  == inputInfo) {
                    		 found = true;
                    		 index = x;
                    	 }
                     }
                     if (found) {
                    	 System.out.println(productList.get(index).toString());
                     }
                     else {
                    	 System.out.print("product not found\n");
                     }
                     break;

                  case 'L':   //List Products
                	  if (productList.size() > 0) {
                		  for (int x = 0; x < productList.size(); x++) {
                			  System.out.println(productList.get(x).toString());
                		  }
                	  }
                	  else {
                		  System.out.println("products not found\n");
                	  }
                     break;

                  case 'Q':   //Quit
                     break;
                  case '?':   //Display Menu
                     printMenu();
                     break;
                  default:
                     System.out.print("Unknown action\n");
                     break;
               }
            }
            else
            {
               System.out.print("Unknown action\n");
            }
         } while (input1 != 'Q'); // stop the loop when Q is read
      }
      catch (IOException exception)
      {
         System.out.println("IO Exception");
      }
   }

  /** The method printMenu displays the menu to a use **/
   public static void printMenu()
   {
      System.out.print("Choice\t\tAction\n" +
                      "------\t\t------\n" +
                      "A\t\tAdd Product\n" +
                      "C\t\tCompute Total Costs\n" +
                      "S\t\tSearch for Product\n" +
                      "L\t\tList Products\n" +
                      "Q\t\tQuit\n" +
                      "?\t\tDisplay Help\n\n");
   }
}

