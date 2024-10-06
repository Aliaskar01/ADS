import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class a {
    TreeNode root;

    public class TreeNode {
        private TreeNode right;
        private TreeNode left;
        private int data;

        public TreeNode(int data) {
            this.data = data;
        }
    }

    public A() {
        root = null;
    }

    public void insert(int val) {
        root = insert(root, val);
    }
    public TreeNode insert(TreeNode root, int val) {
        if(root == null) {
            root = new TreeNode(val);
            return root;
        }

        if(val < root.data) {
            root.left = insert(root.left, val);
        } else {
            root.right = insert(root.right, val);
        }

        return root;
    }

    public String solve(String path) {
        TreeNode current = root;
        for(int i = 0; i < path.length(); i++) {
            if(path.charAt(i) == 'L') {
                if(current.left == null) {
                    return "NO";
                } else {
                    current = current.left;
                }
            } else {
                if(current.right == null) {
                    return "NO";
                } else {
                    current = current.right;
                }
            }
        }
        return "YES";
    }

    public static void main(String[] args) throws IOException  {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Scanner sc = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(br.readLine());
        A bst = new A();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            bst.insert(Integer.parseInt(st.nextToken()));
        }

        for(int i = 0; i < m; i++) {
            System.out.println(bst.solve(br.readLine()));
        }
        br.close();
    }
}
