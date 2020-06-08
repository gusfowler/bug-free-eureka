// Assignment #: Arizona State University CSE205 #11
//         Name: Your name
//    StudentID: Your id
//      Lecture: Your lecture
//  Description: This is a utility class that provide a static method that
//				 takes an infix string, checked and determine if parentheses
//				 are matching, if matching, returns a postfix string.

import java.util.Stack;

public class InfixToPostfixConverter {
	// **********************************************************************
	// The precedence method determines the precedence between two operators.
	// If the first operator is of higher or equal precedence than the second
	// operator, it returns true, otherwise it returns false.
	// ***********************************************************************
	public static boolean precedence(char first, char second) {
		// PEMDAS
		switch (first) {
			case '+':
				switch (second) {
					case '+': 	return true;
					case '-': 	return true;
					case '*': 	return false;
					case '/': 	return true;
					//case '(':	return false;
				}
			case '-':
				switch (second) {
					case '+':	return true;
					case '-':	return true;
					case '*':	return false;
					case '/':	return false;
					//case '(':	return false;
				}
			case '*':
				switch (second) {
					case '+':	return true;
					case '-':	return true;
					case '*':	return true;
					case '/':	return true;
					//case '(':	return false;
				}
			case '/':
				switch (second) {
					case '+':	return true;
					case '-':	return true;
					case '*':	return true;
					case '/':	return true;
					//case '(':	return false;
				}
			case '(':
				return false;
				//switch (second) {
				//	case '+':	return true;
				//	case '-':	return true;
				//	case '*':	return true;
				//	case '/':	return true;
				//	case '(':	return false; //??
				//}
		}
		return false;
	}

	// *************************************************************************
	// The static convertToPostfix method will convert the infixString
	// into the corresponding postfix string. Check the algorithm on
	// assignment #11's description page. Mark each case clearly inside the code
	// *************************************************************************
	public static String convertToPostfix(String infixString) {
		// initialize the resulting postfix string
		String postfixString = "";

		// initialize the stack
		Stack<Character> stack1 = new Stack<Character>();

		// Obtain the character at index i in the string
		for (int i = 0; i < infixString.length(); i++) {
			char currentChar = infixString.charAt(i);
			switch (currentChar) {
				//Case A: operands
				case 'a':
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
				case 'g':
				case 'h':
				case 'i':
				case 'j':
				case 'k':
				case 'l':
				case 'm':
				case 'n':
				case 'o':
				case 'p':
				case 'q':
				case 'r':
				case 's':
				case 't':
				case 'u':
				case 'v':
				case 'w':
				case 'x':
				case 'y':
				case 'z':
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
				case 'G':
				case 'H':
				case 'I':
				case 'J':
				case 'K':
				case 'L':
				case 'M':
				case 'N':
				case 'O':
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
				case 'T':
				case 'U':
				case 'V':
				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
					postfixString += currentChar;
					break;
				//Case B: (
				case '(':
					stack1.push(currentChar);
					break;
				//Case C / D: operator
				case '+':
				case '-':
				case '*':
				case '/':
					//Case C: if stack empty add as first operator
					if (stack1.empty()) {
						stack1.push(currentChar);
						break;
					}
					//Case D: evaluate presidence to see if stack needs to be moved to string or not
						//if stack has higher precedence pop stack and append to poststring
					else if (!stack1.empty()) {
						//move stack
						while (precedence(stack1.peek(), currentChar) && !stack1.empty()) {
							postfixString += stack1.pop();
							if (stack1.empty()) break;
						}
						stack1.push(currentChar);
						break;
					}
				//Case E: Right Parenthesis push to string
				case ')':
					boolean found = false;
					//if stack is not empty
					while (!stack1.empty()) {	
						if (stack1.peek().equals('(')) {
							stack1.pop(); //discard left parenthes
							found = true;
							break;
						}
						postfixString += stack1.pop();
					}
					if (!found) return "No matching open parenthesis error";
			}
		} // end of for loop
		
		// Case F:
		if (stack1.empty() == false) {
			while (!stack1.empty()) {
				if (stack1.peek() == '(') {
					return "No matching open parenthesis error";
				}
				if (!stack1.empty()) postfixString += stack1.pop();
			}
		}
		
		return "The Postfix Expression is: " + postfixString;
	}// end of convertToPostfix method

}// end of the InfixToPostfixConverter class