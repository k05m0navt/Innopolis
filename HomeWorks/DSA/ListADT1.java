import java.util.Arrays;

public class ListADT1<T>{
    private Object[] store;
    private int capacity = 10;
    private int size = 0;
    private String right = "right";
    private String left = "left";

    private ListADT1(){
        store = new Object[capacity];
    }

    public int size(){
        return size;
    }

    public Boolean isEmpty(){
        if(size() == 0)
            return true;
        else
            return false;
    }

    private void doubleCapacity(){
        store = Arrays.copyOf(store, store.length*2);
        capacity *= 2;
    }

    public void add(int i, T e){
        if (i <= 0)
            throw new ArrayIndexOutOfBoundsException("index:"+i);
        if (i >= capacity)
            doubleCapacity();
        store[i] = e;
        size++;
    }

    private void moveAllElements(String str){
        if (str == right){
            int i = size;
            while (i > 0)
                store[i] = store[--i];
        } else if (str == left){
            int i = 0;
            while (i < size-1)
                store[i] = store[++i];
        }
    }

    public void addFirst(T e){
        checkSize();
        moveAllElements(right);
        store[0] = e;
        size++;
    }

    private void checkSize(){
        if (size + 1 > capacity)
            doubleCapacity();
    }

    public void addLast(T e){
        checkSize();
        store[size] = e;
        size++;
    }

    public void deleteFirst(){
        moveAllElements(left);
        size--;
    }

    public  void deleteLast(){
        store[size - 1] = null;
        size--;
    }

    public void set(int i, T e){
        store[i] = e;
    }

    public Object get(int i){
        return store[i];
    }
}