package ASS2.ASS2;

public class QuickSort<T extends Comparable<? super T>>{
    void swap(T[] arr, int index1, int index2)
    {
        T tmp;

        tmp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = tmp;
    }

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

    public static void main(String[] args)
    {
        Double[]                     arrayOfDoubles = {0.35, 0.02, 0.36, 0.82, 0.27, 0.49, 0.41, 0.17, 0.30, 0.89, 0.37, 0.66, 0.82, 0.17, 0.20, 0.96, 0.18, 0.25, 0.37, 0.52};
        QuickSort<Double> doubleSorter   = new QuickSort<>();
        doubleSorter.quickSort(arrayOfDoubles, 0, arrayOfDoubles.length - 1);
        System.out.println(java.util.Arrays.toString(arrayOfDoubles));
    }
}