
import java.util.*;

public class heapprac {
    
     
    public static void sort(int[] arr,int size){
        for(int i=size/2-1;i>=0;i--){
            hepify(arr,size,i);

        }
        for(int i=size-1;i>=0;i--){
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            hepify(arr,i,0);

        }


    }
    public static void hepify(int[] arr,int size,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<size&&arr[left]>arr[largest]){
            largest=left;

        }
        if(right<size&&arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            int temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            hepify(arr,size,largest);
        }
    }

    public static void main(String[]args){
        int n;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter no of elements : ");
        n=in.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            System.out.println("Enter element : ");
            arr[i]=in.nextInt();

        }
        sort(arr,n);
        System.out.println("Sorted array is : ");
        for (int i = 0; i < n; i++)
        System.out.println(arr[i]+" ");           
    System.out.println();   

        

    }
}
