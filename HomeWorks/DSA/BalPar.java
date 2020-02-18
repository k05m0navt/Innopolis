import java.util.Arrays;
import java.util.Scanner;

public class BalPar { 
	static class stack { 
        int top=-1;
        int capacity = 100;
		String items[] = new String[capacity]; 

		void push(String exp) {
            if (top == capacity-1)
                doubleCapacity();
            items[++top] = exp; 
		} 

		String pop() { 
			if (top == -1) { 
				System.out.println("Underflow error"); 
				return "\0"; 
            }
            else { 
				String element = items[top]; 
				top--; 
				return element; 
			} 
        } 
        
        private void doubleCapacity(){
            items = Arrays.copyOf(items, items.length*2);
            capacity *= 2;
        }

		boolean isEmpty() {
            return (top == -1) ? true : false;
        }
	} 
	
	/* Returns true if character1 and character2 
	are matching left and right Parenthesis */
	static boolean isMatchingPair(String character1, String character2) { 
        if (character1.equals("(") && character2.equals(")")) 
            return true; 
        else if (character1.equals("{") && character2.equals("}")) 
            return true; 
        else if (character1.equals("[") && character2.equals("]")) 
            return true; 
        else
            return false; 
	} 
	
	/* Return true if expression has balanced 
	Parenthesis */
	static boolean areParenthesisBalanced(String[] exp) {
        /* Declare an empty stack */
        stack st = new stack();

        /*
         * Traverse the given expression to check matching parenthesis
         */
        for (int i = 0; i < exp.length; i++) {

            /*
             * If the exp[i] is a starting parenthesis then push it
             */
            if (exp[i].equals("{") || exp[i].equals("(") || exp[i].equals("["))
                st.push(exp[i]);

            /*
             * If exp[i] is an ending parenthesis then pop from stack and check if the
             * popped parenthesis is a matching pair
             */
            if (exp[i].equals("}") || exp[i].equals(")") || exp[i].equals("]")) {

                /*
                 * If we see an ending parenthesis without a pair then return false
                 */
                if (st.isEmpty()) {
                    return false;
                }

                /*
                 * Pop the top element from stack, if it is not a pair parenthesis of character
                 * then there is a mismatch. This happens for expressions like {(})
                 */
                else if (!isMatchingPair(st.pop(), exp[i]))
				    return false;  
		    } 
        } 
		
        /* If there is something left in expression 
            then there is a starting parenthesis without 
            a closing parenthesis */
            
        if (st.isEmpty()) 
            return true; /*balanced*/
        else 
            return false;/*not balanced*/
	} 
	
	public static void main(String[] args) 
	{ 
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        for (int i = 0; i < n; i++) {
            String string = in.nextLine();
            String exp[] = string.split("");
            if (areParenthesisBalanced(exp)) 
                System.out.println("Input is properly balanced"); 
            else
                System.out.println("Not Balanced"); 
        }
	} 

} 
