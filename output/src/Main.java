import java.util.Arrays;
import java.util.Scanner;

/**
 * @author kanat
 */
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr = new int[in.nextInt()];
        for (int i = 0; i < arr.length; arr[i++] = in.nextInt());
        hybridSort(arr);
    }

    static int insertionSort(int[] arr, int left, int right) {
        int count = 0;
        for (int i = left + 1; i <= right; i++) {
            int val = arr[i];
            int j = i;
            while (j > left && val < arr[j - 1]) {
                arr[j--] = arr[j];
                count++;
            }
            arr[j] = val;
            count++;
        }
        return count;
    }

    static int quickSort(int[] arr, int left, int right, int count, int k) {
        if (left >= right) {
            return count;
        } else {
            if ((right - left) < k) {
                return count + insertionSort(arr, left, right);
            }
            int pivotValue = arr[right];
            int pivot = left;
            for (int i = left; i < right; i++) {
                if (arr[i] < pivotValue) {
                    int temp = arr[i];
                    arr[i] = arr[pivot];
                    arr[pivot++] = temp;
                    count += 2;
                }
            }
            int temp = arr[right];
            arr[right] = arr[pivot];
            arr[pivot] = temp;
            count += 2;

            return quickSort(arr, pivot + 1, right, quickSort(arr, left, pivot - 1, count, k), k);
        }
    }

    static void hybridSort(int[] arr) {
        int k = 0, min = Integer.MAX_VALUE;
        int[] copy = null;
        for (int i = 0; i <= arr.length; i++) {
            copy = Arrays.copyOf(arr, arr.length);
            int assignments = quickSort(copy, 0, copy.length - 1, 0, i);
            if (assignments < min) {
                min = assignments;
                k = i;
            }
        }
        System.out.printf("%d%n%d%n%s%n", k, min, Arrays.toString(copy).replaceAll("[\\[,\\]]", ""));
    }
}
