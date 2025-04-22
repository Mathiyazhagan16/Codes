import java.util.Scanner;
public class TowersOfHanoi {
    static void displayTower(int[] stack, int top, int nod) 
    {
        if (top == nod) // empty
            System.out.println("-1");
        else {
            for (int ind = nod - 1; ind >= top; ind -= 1)
                System.out.print(stack[ind] + " ");
            System.out.println();
        }
    }
    static void tohDisplay(int[] src, int[] des, int[] aux, int srcTop, int desTop, int auxTop, int nod, int choice) {
        if (choice == 1)
            displayTower(src, srcTop, nod);
        else if (choice == 2)
            displayTower(des, desTop, nod);
        else if (choice == 3)
            displayTower(aux, auxTop, nod);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int no_of_disks = scanner.nextInt();
        int choice = scanner.nextInt();
        int srcTop = 0;
        int desTop = no_of_disks;
        int auxTop = no_of_disks;
        int[] src = new int[no_of_disks + 1];
        int[] des = new int[no_of_disks + 1];
        int[] aux = new int[no_of_disks + 1];

        for (int ctr = 0; ctr < no_of_disks; ctr++) {
            src[ctr] = ctr + 1;
            aux[ctr] = des[ctr] = -1;
        }
        src[no_of_disks] = des[no_of_disks] = aux[no_of_disks] = Integer.MAX_VALUE;
        tohDisplay(src, des, aux, srcTop, desTop, auxTop, no_of_disks, choice);

        while (true) { // endless loop
            if (src[srcTop] < des[desTop]) { // src is sender, des is receiver
                desTop--; // alter the receiver
                des[desTop] = src[srcTop]; // using the space
                src[srcTop] = -1; // reinitialize sender
                srcTop++; // alter the sender
            } else { // des is sender, src is receiver
                srcTop--;
                src[srcTop] = des[desTop];
                des[desTop] = -1;
                desTop++;
            }
            tohDisplay(src, des, aux, srcTop, desTop, auxTop, no_of_disks, choice);

            if (desTop == 0) break; // base case

            if (src[srcTop] < aux[auxTop]) { // src is sender, aux is receiver
                auxTop--;
                aux[auxTop] = src[srcTop];
                src[srcTop] = -1;
                srcTop++;
            } else { // aux is sender, src is receiver
                srcTop--;
                src[srcTop] = aux[auxTop];
                aux[auxTop] = -1;
                auxTop++;
            }
            tohDisplay(src, des, aux, srcTop, desTop, auxTop, no_of_disks, choice);
            if (auxTop == 0) break;

            if (aux[auxTop] < des[desTop]) { // aux is sender, des is receiver
                desTop--;
                des[desTop] = aux[auxTop];
                aux[auxTop] = -1;
                auxTop++;
            } else { // des is sender, aux is receiver
                auxTop--;
                aux[auxTop] = des[desTop];
                des[desTop] = -1;
                desTop++;
            }
            tohDisplay(src, des, aux, srcTop, desTop, auxTop, no_of_disks, choice);
            if (desTop == 0 || auxTop == 0) break; // base case
        }
    }
}
