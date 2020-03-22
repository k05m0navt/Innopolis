/* Daniil Gubajdullin */

/* Class that implements quicksort algorithm */
public class QuickSort<T extends Comparable<? super T>>{

    /* Swap function that swap two values in array */
    void swap(T[] arr, int index1, int index2)
    {
        T tmp;

        tmp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = tmp;
    }

    /* Partion function take pivot(midle of the array) and put it to the right position */
    private int partion(T[] arr, int start, int end)
    {
        int index;
        T pivot;
        
        index = (start + end) / 2;
        pivot = arr[index];
        end += 1;
        start -= 1;
        while (true)
        {
            do
                start += 1;
            while (arr[start].compareTo(pivot) < 0); 

            do
                end -= 1;
            while (arr[end].compareTo(pivot) > 0);

            if (end <= start)
                return (end);
            swap(arr, start, end);
        }
    }
    
    /* Quicksort function works recursively while end variable greater than start variable */
    private void quickSort(T[] arr, int start, int end)
    {
        if (end > start)
        {
            int index;

            index = partion(arr, start, end);

            quickSort(arr, start, index);
            quickSort(arr, index + 1, end);
        }
    }

    /* Main function tested quicksort algorithm at double, integer, string types */
    public static void main(String[] args)
    {
        /* String testing */
        String[] arrayOfStrings = {"Cheese", "Pepperoni", "Black Olives"};
        QuickSort<String> StringSorter   = new QuickSort<>();
        StringSorter.quickSort(arrayOfStrings, 0, arrayOfStrings.length - 1);
        System.out.println(java.util.Arrays.toString(arrayOfStrings));

        /* Integer testing */
        Integer[] arrayOfIntegers = {10, 7, 8, 9, 1, 5};
        QuickSort<Integer> IntegerSorter   = new QuickSort<>();
        IntegerSorter.quickSort(arrayOfIntegers, 0, arrayOfIntegers.length - 1);
        System.out.println(java.util.Arrays.toString(arrayOfIntegers));

        /* Double testing */
        Double[] arrayOfDoubles = {0.35, 0.02, 0.36, 0.82, 0.27, 0.49, 0.41, 0.17, 0.30, 0.89, 0.37, 0.66, 0.82, 0.17, 0.20, 0.96, 0.18, 0.25, 0.37, 0.52};
        QuickSort<Double> doubleSorter   = new QuickSort<>();
        doubleSorter.quickSort(arrayOfDoubles, 0, arrayOfDoubles.length - 1);
        System.out.println(java.util.Arrays.toString(arrayOfDoubles));
    }
}

/* 
 *  Documentation
 *  
 *  1. What is the time complexity of the algorithm?
 *      In general case:
 *          T(n) = T(k) + T(n-k-1) + Theta(n)
 *  
 *          n - number of elements in array
 *          k - number of elements which are smaller than pivot
 *  
 *      In worst case:
 *          Partition process always picks greatest or smallest element as pivot, so the worst case would occur when the array is already sorted in increasing or decreasing order
 *          
 *          T(n) = T(n-1) + Theta(n) -> T(n) = Theta(n^2)
 *          
 *          n - number of elements in array
 *  
 *      In best case:
 *          The best case occurs when the partition process always picks the middle element as pivot
 *  
 *          T(n) = 2T(n/2) + Theta(n) -> T(n) = Theta(nLogn) (2nd case in Masters Theorem)
 *  
 *          n - number of elements in array
 *      In average case:
 *          We can get an idea of average case by considering the case when partition puts O(n/9) elements in one set and O(9n/10) elements in other set
 *          
 *          T(n) = T(n/9) + T(9n/10) + Theta(n) -> T(n) = Theta(nLogn)
 *  2. Is it in-place or out-of-place?
 *      it uses extra space only for storing recursive function calls but not for manipulating the input -> this algorithm is in-place
 *  3. Is it stable?
 *      No, it is not. But we can make this algorithm stable by considering indexes as comparison parameter
 *          
 *  4. References
 *      1) https://www.geeksforgeeks.org/quick-sort/
 *      2) https://en.wikipedia.org/wiki/Quicksort
 *      3) https://www.youtube.com/
 *  */