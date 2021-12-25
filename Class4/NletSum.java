package Class4;

import java.util.Arrays;

/**
 * NletSum
 */
public class NletSum {

    private static boolean nletSum(int[] arr , int nlet, int sum) {

        int n = arr.length;

        if(n==0) {
            return false;
        }
      
        if(nlet == 1) {
            for(int i = 0; i<n; i++) {
                if (arr[i] == sum) {
                    return true;
                }
            }
            return false;
        }

        if(nlet == 2) {

            return checkSumTwoPointer(arr, 0, n-1, sum);
        }

        if (nlet >= 3) {
            
            for(int i = 0; i < n-2; i++) {
                
                int lSum = arraySum(arr, i, nlet-2);
            
                if(lSum == -1) {
                    continue;
                }

                int RSum = sum -lSum;
                if (checkSumTwoPointer(arr, i+1 , n-1, RSum)) {
                    return true;
                }
            }
        }




        return false;

    }

    private static boolean checkSumTwoPointer(int arr[], int p1, int p2, int sum) {

        while(p1 < p2) {
            if(arr[p1] + arr[p2] == sum) {
                return true;
            }
            else if( arr[p1] + arr[p2] > sum) {
                p2--;
            } else {
                p1++;
            }
        }
        return false;
    }



    private static int arraySum(int arr[], int begIndex, int numberOfElements) {
        int sum = 0;
        for(int i =0; i< numberOfElements; i++) {
            if(begIndex > arr.length -1){
                return -1;
            }        
            sum += arr[begIndex++];
        }
        return sum;
    }


    private static String checkNletSum(int arr[], int nlet, int sum) {

          //sort the array
          Arrays.sort(arr);

          boolean flag = nletSum(arr, nlet, sum);

          return "For  " + nlet + " let sum on " +Arrays.toString(arr) + " sum = " + sum  + " is " + (flag ? " feasible " : " not feasible");
    }

    public static void main(String[] args) {
    
        System.out.println(checkNletSum(new int[]{1, 2, 45, 6, 10, 8}, 3, 13));
        System.out.println(checkNletSum(new int[]{1, 2, 45, 6, 10, 8}, 3, 30));
        System.out.println(checkNletSum(new int[]{1, 2, 45, 6, 10, 8}, 3, 9));
        System.out.println(checkNletSum(new int[]{1, 2, 45, 6, 10, 8}, 3, 24));
        System.out.println(checkNletSum(new int[]{1, 2, 45, 6, 10, 8}, 3, 48));
        System.out.println(checkNletSum(new int[]{1, 2, 45, 6, 10, 8}, 2, 13));
        System.out.println(checkNletSum(new int[]{1, 2, 45, 6, 10, 8}, 4, 21));
        System.out.println(checkNletSum(new int[]{1, 2, 45, 6, 10, 8}, 4, 20));
        System.out.println(checkNletSum(new int[]{1, 2, 45, 6, 10, 8, 15,18}, 5, 27));
    }

}
