import java.util.*;
public class Hamiltonian_Cycle 
{
    public static boolean check(int v, int graph[][], int path[], int pos) 
    {
        for (int i = 0; i < pos; i++)
            if (path[i] == v || graph[path[pos - 1]][v] == 0)
                return false;
        return true;
    }
    public static boolean hamiltonianUtil(int graph[][], int path[], int pos, int N) 
    {
        if (pos == N) 
        {
            for (int i = 0; i < N; i++)
                System.out.print(path[i]+" ");
            System.out.println(path[0]);
            return true;
        }
        for (int v = 1; v < N; v++) 
            if (check(v, graph, path, pos)) 
            {
                path[pos] = v;
                if (hamiltonianUtil(graph, path, pos + 1, N) == true) return true;
                path[pos] = -1;
            }
        return false;
    }
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        int N = 5;
        int[][] graph = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
        int[] path = new int[N];
        path[0] = 0;
        System.out.printf("%s",(hamiltonianUtil(graph, path, 1,N) == true)?"":"Hamiltonian Cycle does not exist");
    }
}