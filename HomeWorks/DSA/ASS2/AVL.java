/* Daniil Gubajdullin */

public class AVL<T extends Comparable<? super T>>{
    class Node
    {
        T key;
        int height;
        Node left;
        Node right;

        Node(T k)
        {
            key = k;
            height = 1;
        }
    }

    Node root;

    int     maxValue(int a, int b)
    {
        if (a >= b)
            return (a);
        else
            return (b);
    }

    int     height(Node N)
    {
        if (N == null)
            return (0);
        return (N.height);
    }

    void    updateHeight(Node P)
    {
        P.height = maxValue(height(P.right), height(P.left)) + 1;
    }

    Node    rightRotate(Node P)
    { 
        Node Q;
        Node R;

        Q = P.left;
        R = Q.right; 

        Q.right = P; 
        P.left = R; 

        updateHeight(P);
        updateHeight(Q);
        
        return (Q); 
    }

    Node    leftRotate(Node Q)
    { 
        Node P;
        Node R;

        P = Q.right; 
        R = P.left; 

        P.left = Q; 
        Q.right = R; 

        updateHeight(Q);
        updateHeight(P);

        return (P); 
    }

    int     bfactor(Node N)
    {
        if (N == null)
            return (0);
        return (height(N.left) - height(N.right));
    }

    Node    insert(Node N, T key)
    {
        int balance;

        if (N == null)
            return (new Node(key));
        if (key.compareTo(N.key) < 0)
            N.left = insert(N.left, key);
        else if (key.compareTo(N.key) > 0)
            N.right = insert(N.right, key);
        else
            return (N);

        updateHeight(N);
        
        balance = bfactor(N);

        // Right Right Case 
        if (balance < -1 && key.compareTo(N.right.key) > 0) 
            return leftRotate(N); 
    
        // Right Left Case 
        if (balance < -1 && key.compareTo(N.right.key) < 0) { 
            N.right = rightRotate(N.right); 
            return leftRotate(N); 
        }

        // Left Left Case 
        if (balance > 1 && key.compareTo(N.left.key) < 0) 
            return rightRotate(N); 

        // Left Right Case 
        if (balance > 1 && key.compareTo(N.left.key) > 0) { 
            N.left = leftRotate(N.left); 
            return rightRotate(N); 
        } 

        return (N);
    }

    Node    minNode(Node N)
    {
        Node that;
        
        that = N;
        while (that.left != null)
            that = that.left;
        return (that);
    }

    Node    delete(Node N, T key)
    {
        int balance;

        if (N == null)
            return (N);
        if (key.compareTo(N.key) < 0)
            N.left = delete(N.left, key);
        else if (key.compareTo(N.key) > 0)
            N.right = delete(N.right, key);
        else
        {
            if ((N.right == null) || (N.left == null))
            {
                Node tmp;

                tmp = null;
                if (tmp == N.right)
                    tmp = N.left;
                else
                    tmp = N.right;
                if (tmp == null)
                {
                    tmp = N;
                    N = null;
                }
                else
                    N = tmp;

            }
            else
            {
                Node tmp;

                tmp = minNode(N.right);
                N.key = tmp.key;
                N.right = delete(N.right, tmp.key);
            }
        }

        if (N == null)
            return (N);

        updateHeight(N);

        balance = bfactor(N);

        // Right Right Case  
        if (balance < -1 && bfactor(N.right) <= 0)  
            return (leftRotate(N));  
        // Right Left Case  
        if (balance < -1 && bfactor(N.right) > 0)  
        {  
            N.right = rightRotate(N.right);  
                return (leftRotate(N));  
        } 
        // Left Left Case  
        if (balance > 1 && bfactor(N.left) >= 0)  
            return (rightRotate(N));  

        // Left Right Case  
        if (balance > 1 && bfactor(N.left) < 0)  
        {  
            N.left = leftRotate(N.left);  
            return (rightRotate(N));  
        }   

        return (N);
    }
}
/* 
 *  Documentation
 *  
 *  1. Time Complexity
 *      All rotations in AVL tree takes constant time. Because of insertion depends on height of the tree and height = BigO(log(n)) -> Insert operation time complexity = BigO(log(n))
 *      Searching in AVL tree is equal to searching in BST -> searching time complexity = BigO(log(n))
 *      Delete operation also equal to BST deletion -> deletion time complexity = BigO(log(n))
 *  
 *  2. Results(Time Complexity)
 *      maxValue, height, updateHeight, rightRotate, leftRotate, bfactor time complexity = BigO(1)
 *      insert, minNode, delete time complexity = BigO(log(n))
 *  3. References
 *      https://www.geeksforgeeks.org/
 *      https://habr.com/
 *      https://www.cs.odu.edu/
 * 
 */