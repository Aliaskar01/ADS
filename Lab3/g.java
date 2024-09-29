import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class g {

    public static boolean check(int[] arr, long f, int capacity) {
        int count = 0;
        for (int i : arr) {
            count += i / capacity;
            if (i % capacity > 0) count++;
        }
        return count <= f;
    }

    public static int BinarySearchCapacity(int[] arr, int n, long f) {
        int low = 1;
        int high = arr[n - 1];

        int res = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(arr, f, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        long f = Long.parseLong(st.nextToken());

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        System.out.println(BinarySearchCapacity(arr, n, f));

        br.close();
    }
}

