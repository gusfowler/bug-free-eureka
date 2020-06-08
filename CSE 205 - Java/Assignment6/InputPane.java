// Assignment #: Arizona State University CSE205 #6
//         Name: August Fowler
//    StudentID: 1214774210
//      Lecture: MW6pm
//  Description: InputPane generates a pane where a user can enter
//  a laptop information and create a list of available laptops.

import java.util.ArrayList;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
//import all other necessary javafx classes here
//----

public class InputPane extends HBox
{
	//GUI components
   private ArrayList<Laptop> laptopList;

   //The relationship between InputPane and PurchasePane is Aggregation
   private PurchasePane purchasePane;
   //----
   private Label lblErrOutput, lblBrand, lblModel, lblCPU, lblRAM, lblPrice;
   private TextField txtBrand, txtModel, txtCPU, txtRAM, txtPrice;
   private Button btnEnterInfo;
   private TextArea areaOutput;

	//constructor
	public InputPane(ArrayList<Laptop> list, PurchasePane pPane)
	{
		this.laptopList = list;
		this.purchasePane = pPane;

		//Step #1: initialize each instance variable and set up the layout
		//----
		
		//Labels
		lblErrOutput = new Label("");
		//change lblErrOutput to red
		lblBrand = new Label("Brand");
		lblModel = new Label("Model");
		lblCPU = new Label("CPU(GHz)");
		lblRAM = new Label("RAM(GB)");
		lblPrice = new Label("Price($)");
				
		//Textboxes
		txtBrand = new TextField();
		txtModel = new TextField();
		txtCPU = new TextField();
		txtRAM = new TextField();
		txtPrice = new TextField();
				
		//Button
		btnEnterInfo = new Button("Enter Laptop Info.");
				
		//TextArea
		areaOutput = new TextArea();
		
		//create a GridPane hold those labels & text fields
		//consider using .setPadding() or setHgap(), setVgap()
		//to control the spacing and gap, etc.
		//----
		
		GridPane left = new GridPane();
		//left.setPadding(); //figure this out

		//You might need to create a sub pane to hold the button
   		//----
		GridPane btn = new GridPane();
		btn.addRow(0, btnEnterInfo);
		
   		//Set up the layout for the left half of the InputPane.
   		//----
		left.addRow(0,lblErrOutput);
		left.addRow(1, lblBrand, txtBrand);
		left.addRow(2, lblModel, txtModel);
		left.addRow(3, lblCPU, txtCPU);
		left.addRow(4, lblRAM, txtRAM);
		left.addRow(5, lblPrice, txtPrice);
		left.addRow(6, btn);

   		//the right half of the InputPane is simply a TextArea object
   		//Note: a ScrollPane will be added to it automatically when there are no
   		//enough space

   		//Add the left half and right half to the InputPane
   		//Note: InputPane extends from HBox
   		//----
		GridPane root = new GridPane();
		root.addColumn(0, left);
		root.addColumn(1, areaOutput);
		this.getChildren().add(root);
		
		//Step #3: register source object with event handler
		//----
		ButtonHandler btnHandler = new ButtonHandler();
		btnEnterInfo.setOnAction(btnHandler);


	} //end of constructor

  //Step #2: Create a ButtonHandler class
  //ButtonHandler listens to see if the buttont "Enter a Laptop Info." is pushed or not,
  //When the event occurs, it get a laptop's brand, model, CPU, RAM and price
  //information from the relevant text fields, then create a new Laptop object and add it inside
  //the laptopList. Meanwhile it will display the laptop's information inside the text area.
  //It also does error checking in case any of the textfields are empty or wrong data was entered.
    private class ButtonHandler implements EventHandler<ActionEvent>
   	 {
   	    //Override the abstact method handle()
   	    public void handle(ActionEvent e)
        {
			//declare any necessary local variables here
			//---
   	    	String b, m;
   	    	double cpu, ram, p;

			//when a text field is empty and the button is pushed
			if (txtBrand.getText().trim().isEmpty() || txtModel.getText().trim().isEmpty() || txtCPU.getText().trim().isEmpty() || txtRAM.getText().trim().isEmpty() || txtPrice.getText().trim().isEmpty())
			{
				String out = new String();
				if (txtBrand.getText().trim().isEmpty()) {
					out += "No Brand Entered\n";
				}
				
				if (txtModel.getText().trim().isEmpty()) {
					out += "No Model Entered\n";
				}
				
				if (txtCPU.getText().trim().isEmpty()) {
					out += "No CPU Entered\n";
				}
				
				if (txtRAM.getText().trim().isEmpty()) {
					out += "No RAM Entered\n";
				}

				if (txtPrice.getText().trim().isEmpty()) {
					out += "No Price Entered\n";
				}
				
				lblErrOutput.setText(out);
			}
			else	//for all other cases
         	{
				b = txtBrand.getText().trim();
				m = txtModel.getText().trim();
				try {
					cpu = Double.parseDouble(txtCPU.getText().trim());
					ram = Double.parseDouble(txtRAM.getText().trim());
					p = Double.parseDouble(txtPrice.getText().trim());
					Laptop l = new Laptop(b, m, cpu, ram, p);
					laptopList.add(l);
					//update purchasePane
				}
				catch (NumberFormatException n) {
					lblErrOutput.setText("Incorrect data format");
				}
				
				//----
				//at the end, don't forget to update the new arrayList
				//information on the ListView of the Purchase Pane
                //----

                //Also somewhere you will need to use try & catch block to catch
                //the NumberFormatException
            }
      } //end of handle() method
   } //end of ButtonHandler class

}