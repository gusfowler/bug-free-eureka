// Assignment #: Arizona State University CSE205 #7
//         Name: Gus Fowler
//    StudentID: 1214774210
//      Lecture: MW 6-715p (e.g., MWF 9:40am)
//  Description: The DrawPane class creates a canvas where we can use
//               mouse key to draw either a Rectangle or a Circle with different
//               colors. We can also use the the two buttons to erase the last
//				 drawn shape or clear them all.

//import any classes necessary here
//----
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.shape.Shape;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Circle;
import javafx.scene.paint.Color;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Orientation;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.RadioButton;
import javafx.scene.control.Toggle;
import javafx.scene.control.ToggleGroup;
import javafx.scene.input.MouseEvent;

import java.util.ArrayList;

public class DrawPane extends BorderPane
{
   private Button undoBtn, eraseBtn;
   private ComboBox<String> colorCombo;
   private RadioButton rbRect, rbCircle;
   private ArrayList<Shape> shapeList;
   private Pane canvas;
   private ObservableList<String> options;
   private ToggleGroup shapes;
   //declare any other necessary instance variables here
   //----

   //Constructor
   public DrawPane()
   {
      //Step #1: initialize each instance variable and set up layout
      undoBtn = new Button("Undo");
      eraseBtn = new Button("Erase");
      undoBtn.setMinWidth(80.0);
      eraseBtn.setMinWidth(80.0);
      rbRect = new RadioButton("Rectangle");
      rbCircle= new RadioButton("Circle");
      options = FXCollections.observableArrayList("Black", "Blue", "Green", "Red", "Yellow", "Orange", "Pink");
      
      //Create the color comboBox and intial its default color
      //----
      colorCombo = new ComboBox<String>(options);
      colorCombo.setValue("Black");

      //Create the two radio buttons and also a ToggleGroup
      //so that the two radio buttons can be selected
      //mutually exclusively. Otherwise they are indepedant of each other
      //----
      shapes = new ToggleGroup();
      rbRect.setToggleGroup(shapes);
      rbCircle.setToggleGroup(shapes);
      
      //initialize shapeList, it is a data structure we used
      //to track the shape we created
      //----
      shapeList = new ArrayList<Shape>();
      
      //canvas is a Pane where we will draw rectagles and circles on it
      canvas = new Pane();
      canvas.setStyle("-fx-background-color: beige;");

      //initialize the remaining instance variables and set up
      //the layout
      //----
      GridPane buttonPane = new GridPane();
      buttonPane.addColumn(0, undoBtn, eraseBtn);
      HBox buttonHBox = new HBox(8);
      buttonHBox.getChildren().add(buttonPane);
      
      VBox shapecolorVBox = new VBox(8);
      shapecolorVBox.getChildren().addAll(colorCombo, rbRect, rbCircle);
      
      StackPane stack = new StackPane();
      stack.getChildren().add(buttonHBox);
      stack.setAlignment(buttonHBox, Pos.BOTTOM_CENTER);
      stack.getChildren().add(canvas);
      stack.setAlignment(canvas, Pos.CENTER_RIGHT);
      stack.getChildren().add(shapecolorVBox);
      stack.setAlignment(shapecolorVBox, Pos.CENTER_LEFT);
      
      this.getChildren().add(stack);
      //----

      //Step #3: Register the source nodes with its handler objects
      //----
      canvas.setOnMousePressed(new MouseHandler());
      shapes.selectedToggleProperty().addListener((ChangeListener<? super Toggle>) new ShapeHandler());
      eraseBtn.setOnMouseClicked(new ButtonHandler());
      undoBtn.setOnMouseClicked(new ButtonHandler());
      shapes.selectedToggleProperty().addListener(new ShapeHandler());
      //----


    }

   //Step #2(A) - MouseHandler
   private class MouseHandler implements EventHandler<MouseEvent>
   {
      public void handle(MouseEvent event)
      {
		 //handle MouseEvent here
		 //Note: you can use if(event.getEventType()== MouseEvent.MOUSE_PRESSED)
		 //to check whether the mouse key is pressed, dragged or released
		 //write your own codes here
		 //----
    	 if (event.getEventType() == MouseEvent.MOUSE_PRESSED) {
    		 Shape working;
    		 if (rbRect.isSelected() == true) {
    			 working = new Rectangle(event.getX(), event.getY(), (event.getSceneX() - event.getX()), (event.getSceneY() - event.getY()));
    			 working.setFill(getColor());
    		 }
    		 if (rbCircle.isSelected() == true) {
    			 working = new Circle(event.getX(), event.getY(), findRadius(event));
    			 working.setFill(getColor());
    		 }
    		 else {
    			 working = new Rectangle();
    		 }
    		 shapeList.add(working);
    		 canvas.getChildren().addAll(shapeList);
    	 }
      }//end handle()
      
      public Color getColor() {
    	  String working = shapes.getSelectedToggle().toString();
    	  if (working.equals("Black")) {
    		  return Color.BLACK;
    	  }
    	  if (working.equals("Blue")) {
    		  return Color.BLUE;
    	  }
    	  if (working.equals("Green")) {
    		  return Color.GREEN;
    	  }
    	  if (working.equals("Red")) {
    		  return Color.RED;
    	  }
    	  if (working.equals("Yellow")) {
    		  return Color.YELLOW;
    	  }
    	  if (working.equals("Orange")) {
    		  return Color.ORANGE;
    	  }
    	  if (working.equals("Pink")) {
    		  return Color.PINK;
    	  }
    	  else {
    		  return Color.TRANSPARENT;
    	  }
      }
      
      public double findRadius(MouseEvent event) {
    	  double radius = -1;
    	  double a = (event.getSceneX() - event.getX());
    	  double b = (event.getSceneY() - event.getY());
    	  radius = Math.sqrt((a*a) + (b*b));
    	  
    	  return radius;
      }
   }//end MouseHandler

   //Step #2(B)- A handler class used to handle events from Undo & Erase buttons
   private class ButtonHandler implements EventHandler<MouseEvent>
   {
		@Override
		public void handle(MouseEvent arg0) {
			// TODO Auto-generated method stub
			if (undoBtn.isPressed()) {
				shapeList.remove(shapeList.size() - 1);
			}
			if (eraseBtn.isPressed()) {
				shapeList = new ArrayList<Shape>();
			}
		}
   }//end ButtonHandler

   //Step #2(C)- A handler class used to handle events from the two radio buttons
   private class ShapeHandler implements ChangeListener<Toggle>
   {
      public void handle(ActionEvent event)
      {
		  //write your own codes here
		  //----



      }

      @Override
      public void changed(ObservableValue<? extends Toggle> arg0, Toggle arg1, Toggle arg2) {
    	  // TODO Auto-generated method stub
		
	}
   }//end ShapeHandler

   //Step #2(D)- A handler class used to handle colors from the combo box
   private class ColorHandler implements EventHandler<ActionEvent>
   {
      public void handle(ActionEvent event)
      {
		  //write your own codes here
		  //----

      }
   }//end ColorHandler

}//end class DrawPane