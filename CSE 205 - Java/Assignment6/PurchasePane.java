// Assignment #: Arizona State University CSE205 #6
//         Name: August Fowler
//    StudentID: 1214774210
//      Lecture: MW6pm
//  Description: PurchasePane displays a list of available laptops
//  from which a user can select to buy. It also shows how many
//  laptops are selected and what is the total amount.


import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.event.ActionEvent;	//**Need to import to handle event
import javafx.event.EventHandler;	//**Need to import to handle event

import java.util.ArrayList;
import java.text.DecimalFormat;

//import all other necessary javafx classes
//----

public class PurchasePane extends VBox
{
   //GUI components
   private ArrayList<Laptop> laptopList, selectedList;

   //laptopLV for top ListView; selectedLV for bottom ListView
   private ListView<Laptop> laptopLV, selectedLV;

   //declare all other necessary GUI variables here
   //----
   private Label lblAvailHeader, lblSelectedHeader, lblQtySelect, lblTotalAmt;
   private Button btnPickLaptop, btnRemoveLaptop;
   

 //constructor
   public PurchasePane(ArrayList<Laptop> list)
   {
   	  //initialize instance variables
      this.laptopList = list;
      selectedList = new ArrayList<Laptop>();
      
      //Labels
      lblAvailHeader = new Label("Available Laptops");
      lblSelectedHeader = new Label("Selected Laptops");
      lblQtySelect = new Label("Qty Selected: 0");
      lblTotalAmt = new Label("Total Amt: 0.00");
      
      //Buttons
      btnPickLaptop = new Button("Pick a Laptop");
      btnRemoveLaptop = new Button("Remove a Laptop");
      
      //Lists
      laptopLV = new ListView<Laptop>();
      selectedLV =  new ListView<Laptop>();

      //set up the layout
      //----
      GridPane root = new GridPane();
      root.addRow(0, lblAvailHeader);
      root.addRow(1, laptopLV);
      root.addRow(2, btnPickLaptop, btnRemoveLaptop);
      root.addRow(3, lblSelectedHeader);
      root.addRow(4, selectedLV);
      root.addRow(5, lblQtySelect, lblTotalAmt);
      

   	 //PurchasePane is a VBox - add the components here
   	 //----
      this.getChildren().add(root);

	  //Step #3: Register the button with its handler class
	  //----
      

   } //end of constructor

 //This method refresh the ListView whenever there's new laptop added in InputPane
 //you will need to update the underline ObservableList object in order for ListView
 //object to show the updated laptop list
 public void updateLaptopList(Laptop newLaptop)
 {
     laptopList.add(newLaptop);
     
 }

//Step #2: Create a ButtonHandler class
 private class ButtonHandler2 implements EventHandler<ActionEvent>
 {
  	//Override the abstact method handle()
    public void handle(ActionEvent e)
    {
		//When "Pick a Laptop" button is pressed and a laptop is selected from
		//the top list
        if (//----)
        {
			//----

        }
        //when "Remove a Laptop" button is pushed and a laptop is selected from
        //the bottom list
        else if (//----)
         {

         }
         else //for all other cases
		 {
		 	 //All invalid action, do nothing here;
	     }
      	 //update the QtySelect and AmtSelect labels
      	 //----
       }
   } //end of ButtonHandler class
} //end of PurchasePane class